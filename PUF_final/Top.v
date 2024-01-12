


`timescale	1ns/10ps

`define		INIT	2'h0
`define		COND_1	2'h1
`define		COND_2 	2'h2
`define		COND_3 	2'h3

module PUF_Top (
	input	wire			PUF_Go			,
	input	wire	[1:0]	Op_Type			,
	input  	wire			clk				,
    input	wire			Resetn			,
	output	wire			PUF_Done		,
	input wire [0:7] 		Challenge_Seed	,
	input wire [255:0] 		data_in			,
	input wire [0:95]		i_helper		,
	
	output wire [255:0]data_out
	
	   	
);

	
	



	wire mux1_sel;
	
	//Scrambler Control
	wire En_Scrambler;
	wire Reset_Scrambler;
	wire [7:0] Seed_Data_LFSR;
	wire done_Scrambler;
	//ECC Decoder
	wire En_ECC_Dec;
	wire Reset_ECC_Dec;
	wire done_ECC_Dec;


	PUF_Controller controller(
	.PUF_Go(PUF_Go),
	.Op_Type(Op_Type),
	.Challenge_Seed(Challenge_Seed),
	.clk(clk),
	.Resetn(Resetn),
	.PUF_Done(PUF_Done),
	.mux1_sel(mux1_sel),
	.En_Scrambler(En_Scrambler),
	.Reset_Scrambler(Reset_Scrambler),
	.Seed_Data_LFSR(Seed_Data_LFSR),
	.done_Scrambler(done_Scrambler),
	.En_ECC_Dec(En_ECC_Dec),
	.Reset_ECC_Dec(Reset_ECC_Dec),
	.done_ECC_Dec(done_ECC_Dec)


);

	
	PUF_Data_Path datapath(

	.clk(clk),
	.data_out(data_out),
	.data_in(data_in),
	.En_Scrambler(En_Scrambler),
	.Reset_Scrambler(Reset_Scrambler),
	.Seed_Scrambler(Seed_Data_LFSR),
	.done_Scrambler(done_Scrambler),
	.En_ECC_Dec(En_ECC_Dec),
	.Reset_ECC_Dec(Reset_ECC_Dec),
	.done_ECC_Dec(done_ECC_Dec),
	.i_helper(i_helper),
	.mux1_sel(mux1_sel)
	

);




endmodule

