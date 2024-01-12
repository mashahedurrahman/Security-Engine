//Developed by Jennifer Sheldon, Andrew Whigham, Daniel Volya, and Dr. Prabhat Mishra at the University of Florida.
//Not pipelined questionable timing.
module get_PQ #(parameter integer_size = 64)(input wire infiniteP, infiniteQ, output reg infinitePQ, input wire [integer_size-1:0] prime, A, B, Px, Py, Qx, Qy, output reg [integer_size-1:0] PQx, PQy, input wire clk, rst, go, output wire done);
	wire [integer_size-1:0] lam, nu, eeaout, subtractX;
	reg [integer_size-1:0] Px_reg, Py_reg, Qx_reg, Qy_reg, A_reg, B_reg, prime_reg;
	assign subtractX = ((Qx_reg - Px_reg)) >= 0 ? (((Qx_reg - Px_reg)) % prime_reg): prime_reg - ((-1*(Qx_reg - Px_reg)) % prime_reg);
	assign lam = $signed((Qy_reg - Py_reg)* eeaout) >= 0 ? (((Qy_reg - Py_reg)* eeaout) % prime_reg) : prime_reg - ((-1*((Qy_reg - Py_reg)* eeaout)) % prime_reg);
	assign nu = $signed((Py_reg * Qx_reg - Qy_reg*Px_reg) * eeaout) >= 0 ? (((Py_reg * Qx_reg - Qy_reg*Px_reg) * eeaout) % prime_reg): prime_reg - ((-1*((Py_reg * Qx_reg - Qy_reg*Px_reg) * eeaout)) % prime_reg);
	eeageneric #(.integer_size(integer_size)) eeaCalculator(.clk(clk), .reset(rst), .go(go), .done(done), .x(subtractX), .p(prime), .x_inv(eeaout));
	always @(go, done) begin
			Px_reg <= Px_reg;
			Py_reg <= Py_reg;
			Qx_reg <= Qx_reg;
			Qy_reg <= Qy_reg;
			prime_reg <= prime_reg;
			A_reg <= A_reg;
			B_reg <= B_reg;
			infinitePQ <= 1'b0;
		if(go == 1'b1) begin
			//$display("Go add is ", Px, " ", Py, " Q is ", Qx, " ", Qy);
			Px_reg <= Px;
			Py_reg <= Py;
			Qx_reg <= Qx;
			Qy_reg <= Qy;
			prime_reg <= prime;
			A_reg <= A;
			B_reg <= B;
		end
		if($signed(lam*lam - Px_reg - Qx_reg) >= 0) begin
			//$display("PQ Positive X",);
			PQx <= ((lam*lam - Px_reg - Qx_reg) % prime_reg);
		end
		else begin
			//$display("PQ Negative X",);
			PQx <= prime_reg - ((-1*((lam*lam - Px_reg - Qx_reg))) % prime_reg);
		end
		if($signed(-1*lam*lam*lam + lam* (Px_reg + Qx_reg) - nu) >= 0) begin
			//$display("PQ Positive Y",);
			PQy <= (-1*lam*lam*lam + lam* (Px_reg + Qx_reg) - nu) % prime_reg;
		end
		else begin
			//$display("PQ Negative Y",);
			PQy <= prime_reg - ((-1*((-1*lam*lam*lam + lam* (Px_reg + Qx_reg) - nu))) % prime_reg);
		end
		if((infiniteP == 1'b1 && infiniteQ == 1'b1) || (Px_reg == Qx_reg)) begin
			infinitePQ <= 1'b1;
			//$display("PQ Infinity",$time);
			PQx <= 0;
			PQy <= 0;
		end
		else if(infiniteP == 1'b1) begin
			//$display("PQ set Q Infinity",);
			PQx <= Qx;
			PQy <= Qy;
		end
		else if(infiniteQ == 1'b1) begin
			//$display("PQ set P Infinity",);
			PQx <= Px;
			PQy <= Py;
		end
		if(done == 1'b1) begin
			//$display("Done output add ", PQx, " ", PQy);
		end
	end
endmodule
