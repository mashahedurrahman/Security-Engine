//Developed by Jennifer Sheldon, Andrew Whigham, Daniel Volya, and Dr. Prabhat Mishra at the University of Florida.
//Not pipelined questionable timing.
//Once EEA calculator is done, rest should be ready.
module get_2P #(parameter integer_size = 64) (input wire infiniteP, output reg infiniteDoubleP, input wire[integer_size-1:0] prime, A, B, Px, Py, output reg [integer_size-1:0] doublePx, doublePy, input wire clk, rst, go, output wire done);
	wire [integer_size-1:0] lam, nu, eeaout, doubleYin;
	reg [integer_size-1:0] Px_reg, Py_reg, A_reg, B_reg, prime_reg;
	assign doubleYin = 2*Py_reg;
	assign lam = $signed((((3*Px_reg*Px_reg) + A_reg) * eeaout)) >= 0 ? ((((3*Px_reg*Px_reg) + A_reg) * eeaout)) % prime_reg : prime_reg - ((-1*(((3*Px_reg*Px_reg) + A_reg) * eeaout)) % prime_reg);
	assign nu = $signed(((-1*Px_reg*Px_reg*Px_reg) + A_reg*Px_reg + 2*B_reg) * eeaout) >= 0 ? (((-1*Px_reg*Px_reg*Px_reg) + A_reg*Px_reg + 2*B_reg)* eeaout) % prime_reg : prime_reg - ((-1*(((-1*Px_reg*Px_reg*Px_reg) + A_reg*Px_reg + 2*B_reg) * eeaout))%prime_reg);
	eeageneric #(.integer_size(integer_size)) eeaCalculator(.clk(clk), .reset(rst), .go(go), .done(done), .x(doubleYin), .p(prime), .x_inv(eeaout));
	always @(go, done) begin
			Px_reg <= Px_reg;
			Py_reg <= Py_reg;
			prime_reg <= prime_reg;
			A_reg <= A_reg;
			B_reg <= B_reg;
			infiniteDoubleP <= 1'b0;
		if(go == 1'b1) begin
			//$display("Go double is ", Px, " ", Py);
			Px_reg <= Px;
			Py_reg <= Py;
			prime_reg <= prime;
			A_reg <= A;
			B_reg <= B;
		end
		if($signed(lam*lam - 2*Px_reg) >= 0) begin
			doublePx <= (lam*lam - 2*Px_reg) % prime_reg;
			//$display("P2 Positive X",);
		end
		else begin
			doublePx <= prime_reg - ((-1*(lam*lam - 2*Px_reg)) % prime_reg);
			//$display("P2 Negative X",);
		end
		if($signed(-1*lam*lam*lam + 2*lam*Px_reg - nu) >= 0) begin
			//$display("P2 Positive Y",);
			doublePy <= (-1*lam*lam*lam + 2*lam*Px_reg - nu)% prime_reg;
		end
		else begin
			//$display("P2 Negative Y",);
			doublePy <= prime_reg - ((-1*((-1*lam*lam*lam + 2*lam*Px_reg - nu))) % prime_reg);
		end
		if(infiniteP == 1'b1 || (Py_reg == 0)) begin
			//$display("P2 Infinity",);
			infiniteDoubleP <= 1'b1;
			doublePx <= Px_reg;
			doublePy <= Py_reg;
		end
		if(done == 1'b1) begin
			//$display("Done output double", doublePx, " ", doublePy);
		end

	end 
endmodule
