//`timescale 1ns / 1ps
module Data_Path 
    #(parameter Output = 256) (
    input wire clk,
    input wire Resetn,
   
	input wire [511:0] data_in,
	output wire [255:0]data_out,
	
	//Mux Select
	input wire mux1_sel,
	input wire mux2_sel,
	//SHA Control
	input Hash_Go,
	output Hash_done, 
	//Reg Control
	input rst_reg_1,
	input en_reg_1,
	input rst_reg_2,
	input en_reg_2
    
    );
	
	//internal wires
	wire [511:0] mux1_out;
	wire [255:0] Hash_Out;
	wire [255:0] reg_1_out;
	wire [255:0] reg_2_out;
	wire [127:0] xor_out;
	wire [255:0] mux2_in;
	
	
	
	
	sha256_ip HashBlock(.clk(clk),.rst(~Resetn),.go(Hash_Go),.data_in(mux1_out),.data_out(Hash_Out),.done(Hash_done));
	
	Data_reg #(256) reg_1 (.clk(clk),.rst(rst_reg_1),.en(en_reg_1),.in(Hash_Out),.out(reg_1_out));
	Data_reg #(256) reg_2 (.clk(clk),.rst(rst_reg_2),.en(en_reg_2),.in(reg_1_out),.out(reg_2_out));
	mux #(512) mux1 (.sel(mux1_sel),.a(data_in),.b({reg_1_out,reg_2_out}),.z(mux1_out));
	mux #(256) mux2 (.sel(mux2_sel),.a(reg_1_out),.b(mux2_in),.z(data_out));
	
	
	
	assign xor_out=reg_1_out[255:128] ^ reg_1_out[127:0];
	assign mux2_in={xor_out,128'h0};
    
    
endmodule
