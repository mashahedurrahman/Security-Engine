//Developed by Jennifer Sheldon, Andrew Whigham, Daniel Volya, and Dr. Prabhat Mishra at the University of Florida.
module ECDSA_verify #(
	parameter message_width = 512, 
	parameter key_size = 256,
	parameter integer_size = 64
	) 
	(
		input wire clk, rst, go, 
		input wire[message_width-1 : 0] message, hashedMessage, trng_value, 
		output reg ready, 
		output reg done, verified, 
		input wire [integer_size-1:0] prime, A, B, Qx, Qy, Gx, Gy, n, Ox,Oy,
		input wire [key_size-1:0] r, s, private_key
		);
	localparam WAIT = 0, LOAD = 1, CHECKVALUES = 2, HASH = 3, MODULOS = 4,CURVEPOINT = 5, CHECKR = 6, DONEOUT = 7;
	reg [3:0] state;
	reg hash_start, nq_go,u1G_go,u2Q_go, u1u2_go;
	wire nq_done, u2Q_done, u1G_done, hash_ready, hash_digest_valid, infinityPNQ, infinityPU1, infinityPU2, infinityPU1U2, u1u2_done;
	wire [(message_width)/2-1:0] hash_digest;
	//Signing value and key value are different for kxG and mxG.
	reg [key_size-1:0] key_reg, k_reg, r_reg, s_reg, z_reg, e_reg, u1_reg, u2_reg;
	wire [key_size-1:0] nQx, nQy, u1Gx, u1Gy, u2Qx, u2Qy, U1U2x, U1U2y;
	reg [integer_size-1:0] prime_reg, A_reg, B_reg, Gx_reg, Gy_reg, Qx_reg, Qy_reg, mask,x1_reg, y1_reg, Ox_reg, Oy_reg;
	reg [message_width-1 : 0] message_reg;

	get_PQ #(.integer_size(key_size)) U1U2version(.prime(prime_reg), .A(A_reg), .B(B_reg), .Px(u1Gx), .Py(u1Gy), .Qx(u2Qx), .Qy(u2Qy), .PQx(U1U2x), .PQy(U1U2y), .clk(clk), .rst(rst), .go(u1u2_go), .done(u1u2_done), .infiniteQ(infinityPU1), .infiniteP(infinityPU2), .infinitePQ(infinityPU1U2));

	montgomeryLadder #(
		.key_size(key_size),
		.integer_size(key_size)
		) nQgen (
		.m(1), 
		.clk(clk), 
		.rst(rst), 
		.go(nq_go),
    .infinityP(infinityPNQ), //Why pass point at infinity here? 
    .done(nq_done),
    .prime(prime_reg), 
    .A(A_reg), 
    .B(B_reg), 
    .Px(Qx_reg), 
    .Py(Qy_reg),
    .Ox(Ox_reg),
    .Oy(Oy_reg),
    .mGx(nQx),
    .mGy(nQy)
    );

		montgomeryLadder #(
			.key_size(key_size),
			.integer_size(key_size)
			) u1Ggen (
			.m(u1_reg), 
			.clk(clk), 
			.rst(rst), 
			.go(u1G_go),
    .infinityP(infinityPU1), //Why pass point at infinity here? 
    .done(u1G_done),
    .prime(prime_reg), 
    .A(A_reg), 
    .B(B_reg), 
    .Px(Gx_reg), 
    .Py(Gy_reg), 
    .Ox(Ox_reg),
    .Oy(Oy_reg),
    .mGx(u1Gx),
    .mGy(u1Gy)
    );
			montgomeryLadder #(
				.key_size(key_size),
				.integer_size(key_size)
				) u2Ggen (
				.m(u2_reg), 
				.clk(clk), 
				.rst(rst), 
				.go(u2Q_go),
    .infinityP(infinityPU2), //Why pass point at infinity here? 
    .done(u2Q_done),
    .prime(prime_reg), 
    .A(A_reg), 
    .B(B_reg), 
    .Ox(Ox_reg),
    .Oy(Oy_reg),
    .Px(Qx_reg), 
    .Py(Qy_reg), 
    .mGx(u2Qx),
    .mGy(u2Qy)
    );

//Controller to get order right.
always @ (posedge clk)
begin : STATE_FUNCTIONS
	done <= 1'b0;
	verified <= verified;
	{nq_go, u1G_go, u2Q_go} <= 1'b0;
	state <= state;
	prime_reg <= prime_reg;
	A_reg <= A_reg;
	B_reg <= B_reg;
	k_reg <= 0;
	ready <= 1'b0;
	//$display("***VERIFY***");
	e_reg <= e_reg;
	u1_reg <= u1_reg;
	u2_reg <= u2_reg;
	Ox_reg <= Ox_reg;
	Oy_reg <= Oy_reg;
	r_reg <= r_reg;
	s_reg <= s_reg;
	z_reg <= z_reg;
	case(state)
		WAIT: begin
			done <= 1'b0;
			ready <= 1'b1;
			verified <= 1'b0;
			r_reg <= 0;
			s_reg <= 0;
			z_reg <= 0;
			if(go == 1'b1) begin
				state <= LOAD;
			end
		end
		LOAD: begin
			prime_reg <= prime;
			A_reg <= A;
			B_reg <= B;
			Gx_reg <= Gx;
			Gy_reg <= Gy;
			Qx_reg <= Qx;
			Qy_reg <= Qy;
			Ox_reg <= Ox;
			Oy_reg <= Oy;
			e_reg <= hashedMessage;
			r_reg <= r;
			s_reg <= s;
			message_reg <= message_reg;
			state <= CHECKVALUES;
		end
		CHECKVALUES: begin
			nq_go <= 1'b1;
			if(nq_done == 1'b1) begin
				nq_go <= 1'b0;
				//Check nQa = O?
				if(infinityPNQ == 1'b0) begin
					state <= HASH;
				end else begin
						$display("nQx issue");
						verified <= 1'b0;
					state <= DONEOUT;
				end
			end
			//Not on curve or point at infinity?
			if(infinityPNQ == 1'b1 || ((Qy_reg*Qy_reg) % prime_reg) != ((Qx_reg*Qx_reg*Qx_reg) + (A_reg*Qx_reg) + B_reg) % prime_reg) begin
				$display("Not on curve ", Qx_reg, " ", Qy_reg, " ", Ox_reg, " ", Oy_reg, " ", (Qy_reg*Qy_reg) % prime_reg, " ", ((Qx_reg*Qx_reg*Qx_reg) + (A_reg*Qx_reg) + B_reg) % prime_reg);
				verified <= 1'b0;
				state <= DONEOUT;
			end
			
		end
		HASH: begin
			//if(hash_digest_valid == 1'b1)
			//begin
				mask <= {key_size{1'b1}} << (key_size - prime_reg + 1);
				state <= MODULOS;
			//end
		end
		MODULOS: begin
			z_reg <= e_reg & 7;
			u1_reg <= ((e_reg & 7)/s_reg) % prime_reg;
			u2_reg <= (r_reg/s_reg) % prime_reg;
			state <= CURVEPOINT;
		end
		CURVEPOINT: begin
			u1G_go <= 1'b1;
			u2Q_go <= 1'b1;
			if(u1G_done == 1'b1 && u2Q_done == 1'b1)
			begin
				u1G_go <= 1'b0;
				u2Q_go <= 1'b0;
				u1u2_go <= 1'b1;
			end
			if(u1u2_done == 1'b1) begin
				u1u2_go <= 1'b0;
				if(infinityPU1U2 == 1'b1) begin
					$display("got point at infinityU1U2");
					verified <= 1'b0;
					state <= DONEOUT;
				end	else begin
					x1_reg <= U1U2x;
					y1_reg <= U1U2y;
					state <= CHECKR;
				end
			end
		end
		CHECKR: begin
			$display("Made it to R-check reg is ", x1_reg, " r is ", r_reg);
			if(r_reg == (x1_reg%prime_reg)) begin
				verified <= 1'b1;
			end else begin
					verified <= 1'b0;
			end
			state <= DONEOUT;
		end
		DONEOUT: begin
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