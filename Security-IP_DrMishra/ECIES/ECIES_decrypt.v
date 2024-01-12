//MAY HAVE POINT AT INFINITY ISSUES.
//Does not use input parse from https://www.secg.org/sec1-v2.pdf, just bit slicing.
module ECIES_decrypt #(parameter message_width = 32, parameter hashed_width = 512, parameter key_size = 128, parameter mac_key_length = 256, parameter dec_key_len = 128, parameter integer_size = 64) 
	(
		input wire clk, rst, go, hash_done, dec_done, kdf_hashDone, KDF_done, hash_ready,
		input wire[message_width-1 : 0] messageReturn,
		input wire [hashed_width-1:0] hashedMessage, kdf_hashOut, encryptedMessage,
		output reg [message_width-1 : 0] messageToProcess, messageOutput,
		input wire [key_size-1:0] privateKey, counter, nonce,publicKeyX, publicKeyY,
		input wire [message_width + 2*integer_size + hashed_width -1:0] full_cipher, // ephemeral key || encrypted message || hashed message
		output wire [integer_size+16-1:0] kdf_hashedVal,
		input wire [mac_key_length - 1: 0] mac_key,
		output wire [dec_key_len-1: 0] dec_key,
		output wire ready,
		output reg hash_go, dec_go,
		output reg done, valid, 
		output wire kdf_hashGo,
		input wire [integer_size-1:0] prime, A, B, Gx, Gy, n
		);
	localparam WAIT = 0, CHECKNOTINFINITY = 1, CHECKNQ = 2, GENERATEKDF = 3, DECODE = 4, HASH = 5, DONEOUT = 6;
	reg [3:0] state;
	reg hash_start,ecc_go, KDF_go, secret_go, valid_reg;
	wire ecc_done, secret_done, hash_digest_valid, KDF_valid, infinityP;
	wire [(message_width)/2-1:0] hash_digest;
	reg [key_size-1:0] k_reg;
	//Signing value and key value are different for kxG and mxG.
	reg [dec_key_len-1:0] decrypt_key_reg;
	reg [mac_key_length - 1:0] MAC_key_reg;
	wire [integer_size-1:0] kGx, kGy, secret_X;
	reg [message_width + 2*integer_size + hashed_width -1:0] full_cipher_reg;
	reg [integer_size-1:0] prime_reg, A_reg, B_reg, Gx_reg, Gy_reg, secret_reg, Rx, Ry, n_reg;
	reg [message_width-1 : 0] enc_message_reg, hash_reg;
	wire [mac_key_length + dec_key_len - 1 : 0] Z_out;
	reg [mac_key_length + dec_key_len - 1 : 0] z_reg;

	montgomeryLadder #(
		.key_size(key_size),
		.integer_size(integer_size)
		) kGGen (
		.m(k_reg), 
		.clk(clk), 
		.rst(rst), 
		.go(ecc_go),
    .infinityP(infinityP), //Why pass point at infinity here? 
    .done(ecc_done),
    .prime(prime_reg), 
    .A(A_reg), 
    .B(B_reg), 
    .Px(Gx_reg), 
    .Py(Gy_reg), 
    .mGx(kGx),
    .mGy(kGy)
    );

		ANSIX963KDF #(.zSize(integer_size), .key_byte_number(mac_key_length/8 + dec_key_len/8), .hash_size(hashed_width)) KDFGen (
				.clk(clk),
				.rst(rst),
				.go(KDF_go),
				.hashReady(hash_ready),
				.hashedOut(kdf_hashOut),
				.hashedVal(kdf_hashedVal),
				.hashDone(kdf_hashDone),
				.hashGo(kdf_hashGo),
				.done(KDF_done),
				.valid(KDF_valid),
				.z(secret_reg),
				.outputValue(Z_out)
				);
//Controller to get order right.
always @ (posedge clk)
begin : STATE_FUNCTIONS
	done <= 1'b0;
	ecc_go <= 1'b0;
	valid <= 1'b0;
	state <= state;
	prime_reg <= prime_reg;
	A_reg <= A_reg;
	B_reg <= B_reg;
	z_reg <= z_reg;
	k_reg <= k_reg;
	KDF_go <= 1'b0;
	Gx_reg <= Gx_reg;
	Gy_reg <= Gy_reg;
	n_reg <= n_reg;
	valid_reg <= valid_reg;
	decrypt_key_reg <= decrypt_key_reg;
	MAC_key_reg <= MAC_key_reg;
	full_cipher_reg <= full_cipher_reg;
	enc_message_reg <= enc_message_reg;
	hash_reg <= hash_reg;
	secret_reg <= secret_reg;
	Rx <= Rx;
	Ry <= Ry;
	case(state)
		WAIT: begin
			full_cipher_reg <= 0;
			decrypt_key_reg <= 0;
			valid_reg <= 1'b0;
			MAC_key_reg <= 0;
			done <= 1'b0;
			z_reg <= 0;
			if(go == 1'b1) begin
				prime_reg <= prime;
				A_reg <= A;
				B_reg <= B;
				Gx_reg <= Gx;
				Gy_reg <= Gy;
				n_reg <= n;
				secret_reg <= publicKeyX;
				Rx <= full_cipher[message_width + 2*integer_size + hashed_width -1 : message_width + 2*integer_size + hashed_width -1 - integer_size];
				Ry <= full_cipher[message_width + 2*integer_size + hashed_width -1 - integer_size - 1: message_width + 2*integer_size + hashed_width -1 - 2*integer_size - 1];
				enc_message_reg <= full_cipher[hashed_width + message_width-1:hashed_width];
				hash_reg <= full_cipher[hashed_width - 1:0];
				state <= CHECKNOTINFINITY;
			end
		end
		CHECKNOTINFINITY: begin
			ecc_go <= 1'b1;
			k_reg <= 1;
			if(ecc_done == 1'b1 && ecc_go == 1'b1)
			begin
				ecc_go <= 1'b0;
				if(infinityP) begin
					//Don't set valid, go to done state.
					state <= DONEOUT;
				end
				else begin
					state <= CHECKNQ;
				end
			end
		end
		CHECKNQ: begin
			//Wait for inner FSM to reset.
			if(ecc_done == 1'b0) begin
			ecc_go <= 1'b1;
			k_reg <= n_reg;
		end
			if(ecc_done == 1'b1 && ecc_go == 1'b1)
			begin
				ecc_go <= 1'b0;
				if(infinityP) begin
					state <= GENERATEKDF;
				end
				else begin
					//Don't set valid, go to done state. Point is invalid.
					state <= DONEOUT;
				end
			end
		end
		GENERATEKDF: begin
			KDF_go <= 1'b1;
			if(KDF_done == 1'b1)
			begin
				KDF_go <= 1'b0;
				decrypt_key_reg <= Z_out[mac_key_length + dec_key_len - 1 : mac_key_length + dec_key_len - 1 - dec_key_len];
				MAC_key_reg <= Z_out[mac_key_length-1:0];
				state <= HASH;
			end
		end
		HASH:
		begin
			hash_go <= 1'b1;
			messageToProcess <= enc_message_reg;
			if(hash_done == 1'b1) begin
				hash_go <= 1'b0;
				if(hash_reg == encryptedMessage) begin
					state <= DECODE;
				end
				else
				begin
					state <= DONEOUT;
				end
			end
		end
		DECODE:
		begin
			messageToProcess <= enc_message_reg;
			dec_go <= 1'b1;
			if(dec_done == 1'b1) begin
				dec_go <= 1'b0;
				messageOutput <= messageReturn;
				valid_reg <= 1'b1;
				state <= DONEOUT;
			end
		end
		DONEOUT:
		begin
			valid <= valid_reg;
			done <= 1'b1;
			if(go == 1'b0) begin
				state <= WAIT;
			end
		end
	endcase
	if(rst == 1'b1) begin
		state <= WAIT;
	end
end
endmodule
