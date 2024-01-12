//Developed by Jennifer Sheldon, Andrew Whigham, Daniel Volya, and Dr. Prabhat Mishra at the University of Florida.
//Use naive method bc don't want to make guarantees about inputs.
//Replace with multicycle division and done signal?
module eeageneric #(parameter integer_size = 64)(output reg[integer_size-1:0] x_inv, input wire[integer_size-1:0] x, p, output reg done, failure, input wire reset, clk, go);
	localparam WAIT = 4'b0111, CHECKMOD = 4'b0000, DONEOUT = 4'b1001;
	reg [3:0] state;
	reg [integer_size-1:0] x_reg, p_reg, checkedVal, outputVal;
	//All synchronous go will not start without rising clock.
	always @ (posedge clk)
	begin : STATE_FUNCTIONS
		done <= 1'b0;
		failure <= failure;
		state <= state;
		checkedVal <= checkedVal;
		outputVal <= outputVal;
		x_inv <= x_inv;
		case(state)
			WAIT: begin
				done <= 1'b0;
				failure <= 1'b0;
				x_inv <= 0;
				outputVal <= 0;
				if (go == 1'b1) begin
					state <= CHECKMOD;
					x_reg <= x;
					checkedVal <= 1;
					p_reg <= p;
				end
			end
			CHECKMOD: begin
				if((((x_reg%p_reg * checkedVal%p_reg) % p_reg) == 1)) begin
					outputVal <= checkedVal;
					x_inv <= checkedVal;
					state <= DONEOUT;
				end
				else if(checkedVal == p_reg) begin
					x_inv <= 0;
					state <= DONEOUT;
				end
				else begin
				checkedVal <= checkedVal + 1;
			end
			end
			DONEOUT: begin
				done <= 1'b1;
				//$display("finished eeageneric ", p_reg , " " , x_reg, " ", checkedVal, " ",x_reg%p_reg , " " , checkedVal%p_reg, " " , (x_reg%p_reg * checkedVal%p_reg) % p_reg );
				if(outputVal == 0) begin
					failure <= 1'b1;
					//$display("Failure");
				end
				if(go == 1'b0) begin
					state <= WAIT;
				end
			end
		endcase
		if(reset == 1'b1) begin
			state <= WAIT;
		end
	end
endmodule