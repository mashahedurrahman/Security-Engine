`timescale	1ns/10ps
module PUF_Data_Path 
    #(parameter Output = 256) (
    input wire clk,
    
	output wire [0:255]data_out,
	
	//Scrambler
   
	input wire [0:255] data_in,
	input wire En_Scrambler,
	input wire Reset_Scrambler,
	input wire [7:0] Seed_Scrambler,
	output wire done_Scrambler,
	
	//ECC Decoder
	input wire En_ECC_Dec,
	input wire Reset_ECC_Dec,
	output wire done_ECC_Dec,
	input wire [0:95] i_helper,
	
	//Mux Select
	input wire mux1_sel
	//input wire mux2_sel
	
    
    );
	
	//internal wires
	wire [0:255] Scrambler_out;
	wire [0:255] ECC_Dec_out;
	wire [0:7] dummy_dec;
	
	
		LFSR #(.NUM_BITS(8),.OUTPUT_SIZE(256)) scrambler (
	
	.i_Clk(clk),
	.i_Enable(En_Scrambler),
	.i_Reset(Reset_Scrambler),
	.i_Seed_Data(Seed_Scrambler),
	.i_data_in(data_in),
	.o_LFSR_Data(Scrambler_out),
	.o_LFSR_Done(done_Scrambler)



);


	decoder_top ECC_Decode (
	
	.i_Data({8'b00000000,Scrambler_out}),
	.i_helper(i_helper),
	.clk(clk),
	.enable(En_ECC_Dec),
	.reset(Reset_ECC_Dec),
	.done(done_ECC_Dec),
	.o_Data({dummy_dec,ECC_Dec_out})



);
	
	Mux_N #(256) mux1 (.sel(mux1_sel),.a(Scrambler_out),.b(ECC_Dec_out),.z(data_out));
	
	
	
	
	
    
    
endmodule
