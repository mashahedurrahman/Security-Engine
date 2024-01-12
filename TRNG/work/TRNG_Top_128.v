

`timescale	1ns/10ps

`define		INIT	2'h0
`define		COND_1	2'h1
`define		COND_2 	2'h2
`define		COND_3 	2'h3

module TRNG_Top_128 #(
	parameter P_ADDR_WIDTH = 12,
	parameter P_DATA_WIDTH = 32 ) (
	input	wire			TRNG_Go			,
	input	wire	[1:0]	Op_Type			,
	input  	wire			clk				,
    input	wire			Resetn			,
	output	wire			TRNG_Done,
	
	input wire [511:0] data_in,
	output wire [127:0]data_out
	
	   	
);

	wire mux1_sel;
	wire mux2_sel;
	//SHA Control
	wire Hash_Go;
	wire Hash_done; 
	//Reg Control
	wire rst_reg_1;
	wire en_reg_1;
	wire rst_reg_2;
	wire en_reg_2;


	TRNG_Controller controller(
	.TRNG_Go(TRNG_Go),
	.Op_Type(Op_Type),
	.clk(clk),
	.Resetn(Resetn),
	.TRNG_Done(TRNG_Done),
	.mux1_sel(mux1_sel),
	.mux2_sel(mux2_sel),
	.Hash_Go(Hash_Go),
	.Hash_done(Hash_done),
	.rst_reg_1(rst_reg_1),
	.en_reg_1(en_reg_1),
	.rst_reg_2(rst_reg_2),
	.en_reg_2(en_reg_2)


);


Data_Path_128 datapath (

	.clk(clk),
	.Resetn(Resetn),
	.data_in(data_in),
	.data_out(data_out),
	.mux1_sel(mux1_sel),
	//.mux2_sel(mux2_sel),
	.Hash_Go(Hash_Go),
	.Hash_done(Hash_done),
	.rst_reg_1(rst_reg_1),
	.en_reg_1(en_reg_1),
	.rst_reg_2(rst_reg_2),
	.en_reg_2(en_reg_2)


);

endmodule


