
//`timescale	1ns/10ps

`define		INIT	2'h0
`define		COND_1	2'h1
`define		COND_2 	2'h2
`define		COND_3 	2'h3

module TRNG_Controller #(
	parameter P_ADDR_WIDTH = 12,
	parameter P_DATA_WIDTH = 32 ) (
	input	wire			TRNG_Go			,
	input	wire	[1:0]	Op_Type			,
	input  	wire			clk				,
    input	wire			Resetn			,
	output	reg			TRNG_Done,
	
	//Control Signals
	output	reg				mux1_sel		,
	output 	reg				mux2_sel		,
	output 	reg				Hash_Go			,
	input	wire			Hash_done		, 
	output	reg				rst_reg_1		,
	output	reg				rst_reg_2		,
	output	reg				en_reg_1		,
	output 	reg				en_reg_2		
	
	   	
);


reg		[1:0]				ctrl_state		;
reg		[1:0]				Op_Type_reg;

//assign TRNG_Done=(ctrl_state==`COND_3);

always @ (negedge Resetn or posedge clk) 
begin
	if (!Resetn) begin
		ctrl_state		<= `INIT			;
		rst_reg_1<=1'b1;
		rst_reg_2<=1'b1;
	end
	else begin
			case (ctrl_state) 
				`INIT	: begin
				
				
					if (TRNG_Go) begin
						
						ctrl_state	<= `COND_1				;
						Op_Type_reg<=Op_Type;
						TRNG_Done<=0;
					end
					else
					begin
					TRNG_Done<=1;
					end
					
					mux1_sel=1'b0;
					rst_reg_1<=1'b0;
					rst_reg_2<=1'b0;
					en_reg_1<=1'b0;
					en_reg_2<=1'b0;
					Hash_Go<=1'b0;
					
					
				end
				`COND_1	: begin
				
					if (Op_Type_reg[0]==0) begin
						mux1_sel=1'b0;
					end
					else begin
					
						mux1_sel=1'b1;
					end
					rst_reg_1<=1'b0;
					rst_reg_2<=1'b0;
					en_reg_1<=1'b0;
					en_reg_2<=1'b0;
					Hash_Go<=1'b1;
					
					ctrl_state<=`COND_2;
					
				end
				`COND_2	: begin
				
					rst_reg_1<=1'b0;
					rst_reg_2<=1'b0;
					
					
					Hash_Go<=1'b0;
					
					if (Hash_done==1) begin
						
						ctrl_state	<= `COND_3				;
						en_reg_2<=1'b1;
					end
					
					
					
				end
				`COND_3	: begin
				
					rst_reg_1<=1'b0;
					rst_reg_2<=1'b0;
					en_reg_1<=1'b1;
					en_reg_2<=1'b0;
					Hash_Go<=1'b0;
					TRNG_Done<=1'b1;
					
					mux2_sel<=Op_Type_reg[1];
					
						
					ctrl_state<=`INIT;
					
				end
				default : begin
					ctrl_state		<= `INIT				;
				end
			endcase
		
	end
end

endmodule

