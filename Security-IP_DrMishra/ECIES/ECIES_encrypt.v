//MAY HAVE POINT AT INFINITY ISSUES.
//Don't need to convert to octet string bc already getting binary vector(???)
module ECIES_encrypt #(parameter message_width = 32, parameter hashed_width = 512,  parameter key_size = 128, parameter mac_key_length = 256, parameter enc_key_len = 128, parameter integer_size = 64) 
	(
		input wire clk, rst, go, hash_done, enc_done, kdf_hashDone, KDF_done, hash_ready,
		input wire[message_width-1 : 0] message, encryptedMessage,
		input wire [hashed_width-1:0] kdf_hashOut, hashedMessage,
		output reg [message_width-1 : 0] messageToProcess,
		input wire [key_size-1:0] privateKey, counter, nonce,publicKeyX, publicKeyY,
		output reg [message_width + 2*integer_size + hashed_width -1:0] full_cipher, // ephemeral key || encrypted message || hashed message
		output wire [integer_size+16-1:0] kdf_hashedVal,
		output wire [mac_key_length - 1: 0] mac_key,
		output wire [enc_key_len-1: 0] enc_key,
		output reg ready, hash_go, enc_go,
		output reg done, key_done, valid, 
		output wire kdf_hashGo,
		input wire [integer_size-1:0] prime, A, B, Gx, Gy, n
		);
	localparam WAIT = 0, ECC = 1, MAKEKDF = 2, ENC= 3, HASH = 4, DONEOUT = 5;
	reg [3:0] state;
	reg hash_start,ecc_go, KDF_go, secret_go;
	wire ecc_done, secret_done, hash_digest_valid, KDF_valid;
	wire [(message_width)/2-1:0] hash_digest;
	//Signing value and key value are different for kxG and mxG.
	reg [enc_key_len-1:0] encrypt_key_reg;
	reg [key_size-1:0] k_reg;
	reg [mac_key_length - 1:0] MAC_key_reg;
	wire [integer_size-1:0] kGx, kGy, secret_X;
	reg [message_width + 2*integer_size + hashed_width -1:0] full_cipher_reg;
	reg [integer_size-1:0] prime_reg, A_reg, B_reg, Gx_reg, Gy_reg, secret_reg, Rx, Ry;
	reg [message_width-1 : 0] message_reg;
	wire [mac_key_length + enc_key_len - 1 : 0] Z_out;
	reg [mac_key_length + enc_key_len - 1 : 0] z_reg;
	montgomeryLadder #(
		.key_size(key_size),
		.integer_size(integer_size)
		) kGGen (
		.m(k_reg), 
		.clk(clk), 
		.rst(rst), 
		.go(ecc_go),
    //.infinityP(0), //Why pass point at infinity here? 
    .done(ecc_done),
    .prime(prime_reg), 
    .A(A_reg), 
    .B(B_reg), 
    .Px(Gx_reg), 
    .Py(Gy_reg), 
    .mGx(kGx),
    .mGy(kGy)
    );

		montgomeryLadder #(
			.key_size(mac_key_length + enc_key_len),
			.integer_size(integer_size)
			) sharedSecretGen (
			.m(z_reg), 
			.clk(clk), 
			.rst(rst), 
			.go(secret_go),
    //.infinityP(0), //Why pass point at infinity here? 
    .done(secret_done),
    .prime(prime_reg), 
    .A(A_reg), 
    .B(B_reg), 
    .Px(publicKeyX), 
    .Py(publicKeyY), 
    .mGx(secret_X) //Leave out y bc not included in secret, so doesn't matter.
    );

			ANSIX963KDF #(.zSize(integer_size), .key_byte_number(mac_key_length/8 + enc_key_len/8), .hash_size(hashed_width)) KDFGen (
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
assign mac_key = MAC_key_reg;
assign enc_key = encrypt_key_reg;
//Controller to get order right.
always @ (posedge clk)
begin : STATE_FUNCTIONS
	done <= 1'b0;
	ecc_go <= 1'b0;
	state <= state;
	prime_reg <= prime_reg;
	A_reg <= A_reg;
	B_reg <= B_reg;
	z_reg <= z_reg;
	k_reg <= k_reg;
	ready <= 1'b0;
	key_done <= 1'b1;
	KDF_go <= 1'b0;
	Gx_reg <= Gx_reg;
	Gy_reg <= Gy_reg;
	Rx <= Rx;
	Ry <= Ry;
	encrypt_key_reg <= encrypt_key_reg;
	MAC_key_reg <= MAC_key_reg;
	full_cipher_reg <= full_cipher_reg;
	secret_reg <= secret_reg;
	message_reg <= message_reg;
	case(state)
		WAIT: begin
			full_cipher_reg <= 0;
			encrypt_key_reg <= 0;
			MAC_key_reg <= 0;
			done <= 1'b0;
			ready <= 1'b1;
			z_reg <= 0;
			k_reg <= 0;
			full_cipher <= 0;
			if(go == 1'b1) begin
				prime_reg <= prime;
				k_reg <= privateKey;
				A_reg <= A;
				B_reg <= B;
				Gx_reg <= Gx;
				Gy_reg <= Gy;
				message_reg <= message;
				state <= ECC;

			end
		end
		ECC: begin
			ecc_go <= 1'b1;
			secret_go <= 1'b1;
			if(ecc_done == 1'b1 && secret_done == 1'b1)
			begin
				secret_go <= 1'b0;
				ecc_go <= 1'b0;
				secret_reg <= secret_X;
				Rx <= kGx;
				Ry <= kGy;
				state <= MAKEKDF;
			end
		end
		MAKEKDF: begin
			KDF_go <= 1'b1;
			if(KDF_done == 1'b1) begin
				KDF_go <= 1'b0;
				encrypt_key_reg <= Z_out[mac_key_length + enc_key_len - 1 : mac_key_length + enc_key_len - 1 - enc_key_len];
				MAC_key_reg <= Z_out[mac_key_length-1:0];
				state <= ENC;
			end
		end
		ENC: begin
			enc_go <= 1'b1;
			messageToProcess <= message_reg;
			if(enc_done == 1'b1)
			begin
				enc_go <= 1'b0;
				message_reg <= encryptedMessage;
				state <= HASH;
			end 
		end
		HASH: begin
			hash_go <= 1'b1;
			messageToProcess <= message_reg;
			if(hash_done == 1'b1)
			begin
				hash_go <= 1'b0;
				full_cipher_reg <= {Rx, Ry, message_reg, hashedMessage};
				valid <= 1'b1;
				state <= DONEOUT;
			end 
		end
		DONEOUT:
		begin
			done <= 1'b1;
			full_cipher <= full_cipher_reg;
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
