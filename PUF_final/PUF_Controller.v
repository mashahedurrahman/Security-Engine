

`timescale	1ns/10ps

`define		INIT	3'h0
`define		COND_1	3'h1
`define		COND_2 	3'h2
`define		COND_3 	3'h3
`define		COND_4	3'h4
`define		COND_5	3'h5

module PUF_Controller #(
	parameter P_ADDR_WIDTH = 12,
	parameter P_DATA_WIDTH = 32 ) (
	input	wire			PUF_Go			,
	input	wire	[1:0]	Op_Type			,
	input	wire	[7:0]	Challenge_Seed,
	input  	wire			clk				,
    input	wire			Resetn			,
	output	reg			PUF_Done,
	
	//Control Signals mux
	output	reg				mux1_sel		,
	//output 	reg				mux2_sel		,
	//Control Signals Scrambler
	output 	reg				En_Scrambler	,
	output	reg				Reset_Scrambler	, 
	output	reg		[7:0]	Seed_Data_LFSR	,
	input	wire			done_Scrambler	,
	//Control Signals ECC Decoder
	output 	reg				En_ECC_Dec	,
	output	reg				Reset_ECC_Dec	, 
	input	wire			done_ECC_Dec	
	
	   	
);


reg		[2:0]				ctrl_state		;
reg		[1:0]				Op_Type_reg;

//assign TRNG_Done=(ctrl_state==`COND_3);

always @ (negedge Resetn or posedge clk) 
begin
	if (!Resetn) begin
		ctrl_state		<= `INIT			;
		En_ECC_Dec=1;
		En_Scrambler=1;
		Reset_ECC_Dec=1;
		Reset_Scrambler=1;
					
		
	end
	else begin
			case (ctrl_state) 
				`INIT	: begin
					En_ECC_Dec=0;
					En_Scrambler=0;
					Reset_ECC_Dec=0;
					Reset_Scrambler=0;
					PUF_Done=1;
				
					if (PUF_Go) begin
						
						ctrl_state	<= `COND_1				;
						Op_Type_reg<=Op_Type;
					end
					
					
					
					
				end
				`COND_1	: begin
				
					if (Op_Type_reg[0]==0) begin // determining which mode to execute
						mux1_sel=1'b0;
					end
					else begin
					
						mux1_sel=1'b1;
					end
					
					Seed_Data_LFSR=Challenge_Seed;
					En_ECC_Dec=0;
					En_Scrambler=1;
					Reset_ECC_Dec=0;
					Reset_Scrambler=1;
					PUF_Done=0;
					
				
					ctrl_state<=`COND_2;
					
				end
				`COND_2	: begin
				
					En_ECC_Dec=0;
					En_Scrambler=1;
					Reset_ECC_Dec=0;
					Reset_Scrambler=0;
					
					if (done_Scrambler==1) begin
						
						ctrl_state	<= `COND_3				;
						
					end
					
					
					
				end
				`COND_3	: begin
				
					En_ECC_Dec=1;
					En_Scrambler=0;
					Reset_ECC_Dec=1;
					Reset_Scrambler=0;
					
					
					if (Op_Type_reg[0]==0) begin // determining which mode to execute
						mux1_sel=1'b0;
						ctrl_state	<= `INIT				;
					end
					else begin
					
						mux1_sel=1'b1;
						ctrl_state<=`COND_4;
					end
					
									
						
					
					
				end
				`COND_4	: begin
				
					En_ECC_Dec=1;
					En_Scrambler=0;
					Reset_ECC_Dec=0;
					Reset_Scrambler=0;
					
					if (done_ECC_Dec==1) begin
						
						ctrl_state	<= `INIT				;
						
					end
					
					
					
				end
				
				default : begin
					ctrl_state		<= `INIT				;
				end
			endcase
		
	end
end

endmodule

