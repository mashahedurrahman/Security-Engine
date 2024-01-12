//Developed by Jennifer Sheldon, Andrew Whigham, Daniel Volya, and Dr. Prabhat Mishra at the University of Florida.
//MAY HAVE POINT AT INFINITY ISSUES.
module ECDSA_sign #(		
		parameter message_width = 512,
		parameter key_size = 256,
		parameter integer_size = 64
	)
	(
		input wire clk, rst, go,
		input wire [message_width-1 : 0] message, hash, trng_value,
		output reg ready, failure,
		output reg done,
		input wire [key_size - 1:0] privateKey,
		input wire [integer_size-1:0] prime, A, B, Gx, Gy, n, Ox, Oy,
		output reg [key_size-1:0] r, s
	);
	localparam WAIT = 0, LOAD = 1, HASH = 2, TRNG = 3, ECC = 4, LOADSIGN = 5, DONEOUT = 6;

	reg [3:0] state;
	reg hash_start, ecc_go, k_go;
	wire ecc_done, k_done, hash_ready, hash_digest_valid, infinityP;

	reg [message_width-1 : 0] trng_reg, hash_reg;

	//Signing value and key value are different for kxG and mxG.
	reg [key_size-1:0] key_reg;
	wire [key_size-1:0] kGx, kGy;
	wire [integer_size-1:0] k_inv;
	reg [integer_size-1:0] prime_reg, A_reg, B_reg, Gx_reg, Gy_reg, mask, r_reg, s_reg, z_reg, e_reg, k_reg, n_reg, Ox_reg, Oy_reg;
	reg [message_width-1 : 0] message_reg;

	montgomeryLadder #(
		.key_size(integer_size),
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
	    .Ox(Ox_reg),
    	.Oy(Oy_reg),
	    .mGx(kGx),
	    .mGy(kGy)
    );


  	//Get generic k^-1.
  	eeageneric #(.integer_size(integer_size)) kinverter(
  		.clk(clk),
  		.reset(rst),
  		.x(k_reg),
  		.p(n_reg),
  		.go(k_go),
  		.done(k_done),
  		.x_inv(k_inv)
  	);
//Controller to get order right.
always @ (posedge clk)
begin : STATE_FUNCTIONS
	done <= 1'b0;
	state <= state;
	prime_reg <= prime_reg;
	A_reg <= A_reg;
	B_reg <= B_reg;
	k_reg <= k_reg;
	key_reg <= key_reg;
	Gx_reg <= Gx_reg;
	Gy_reg <= Gy_reg;
	e_reg <= e_reg;
	r_reg <= r_reg;
	s_reg <= s_reg;
	z_reg <= z_reg;
	n_reg <= n_reg;
	Ox_reg <= Ox_reg;
	Oy_reg <= Oy_reg;
	s <= s_reg;
	r <= r_reg;
	trng_reg <= trng_reg;
	hash_reg <= hash_reg;
	ready <= 1'b0;
	failure <= 1'b0;
	case(state)
		WAIT: begin
			done <= 1'b0;
			r_reg <= 0;
			s_reg <= 0;
			z_reg <= 0;
			k_reg <= 0;
			ready <= 1'b1;
			e_reg <= 0;
			trng_reg <= 0;
			n_reg <= 0;
			ecc_go <= 1'b0;
			k_go <= 1'b0;
			if(go == 1'b1) begin
				state <= LOAD;
			end
		end
		LOAD: begin
			prime_reg <= prime;
			n_reg <= prime;
			A_reg <= A;
			ecc_go <= 1'b0;
			B_reg <= B;
			Ox_reg <= Ox;
			Oy_reg <= Oy;
			trng_reg <= trng_value;
			e_reg <= hash;
			key_reg <= privateKey;
			Gx_reg <= Gx;
			Gy_reg <= Gy;
			message_reg <= message;
			state <= HASH;
		end
		HASH: begin
			ecc_go <= 1'b0;
			mask <= {key_size{1'b1}} << (key_size - prime_reg + 1);
			state <= TRNG;
		end
		TRNG: begin
			k_reg <= trng_reg;
			z_reg <= e_reg & 7;
			ecc_go <= 1'b0;
			//$display("***SIGN ECDSA TRNG***");
			if (trng_reg < n_reg && trng_reg + 1 > 0)
			begin
				state <= ECC;
			end
		end
		ECC: begin
			ecc_go = 1'b1;
			k_go = 1'b1;
			if(ecc_done == 1'b1 && k_done == 1'b1)
			begin
				ecc_go <= 1'b0;
				k_go <= 1'b0;
				//Load R here to get S in next step for fewer states.
				r_reg <= kGx % prime_reg;
				state <= LOADSIGN;
			end
		end
		LOADSIGN: begin
			s_reg <= k_inv*(e_reg + (r_reg * privateKey)) % n_reg;
			done <= 1'b1;
			state <= DONEOUT;	
		end
		DONEOUT:
		begin
			ecc_go <= 1'b0;
			if(r_reg == 0 || s_reg == 0)
			begin
				failure <= 1'b1;
				done <= 1'b1;
			end 
			else begin
			done <= 1'b1;
			r <= r_reg;
			s <= s_reg;
			if(go == 1'b0) begin
				state <= WAIT;
			end
		end
		end
	endcase
	if(rst == 1'b1) begin
		state <= WAIT;
	end
end

endmodule
