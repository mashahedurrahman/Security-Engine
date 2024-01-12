//`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: FICS, University of Florida
// Engineer: Jungmin Park
// 
// Create Date: 02/08/2022 12:45:32 AM
// Design Name: 
// Module Name: sha256_ip
// Project Name: 
// Target Devices: 
// Tool Versions: 
// Description: 
// 
// Dependencies: 
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
//////////////////////////////////////////////////////////////////////////////////


module sha256_ip(
    input wire clk,
	input wire rst,
	input wire go,
	input wire [511:0] data_in,
	output wire [255:0] data_out,
	output wire done
    );
    
    wire [31:0] data;
    wire [31:0] text_o0, text_o1, text_o2, text_o3, text_o4, text_o5, text_o6, text_o7;
    wire done_SHA;
    wire [2:0] cmd_i;
    wire [3:0] cmd_o;
    wire cmd_w_i;
    wire [446:0] zeros;
    wire [63:0] length_sha;
    wire [1023:0] padded_data;
    
    assign zeros = 447'd0;
    assign length_sha = 64'b0000000000000000000000000000000000000000000000000000001000000000; 
    assign padded_data = (go)? {data_in, 1'b1,  zeros, length_sha}: 1024'd0;
    assign data_out = {text_o7, text_o6, text_o5, text_o4, text_o3, text_o2, text_o1, text_o0};
      
    sha256 u_sha256(
        .clk_i(clk), 
        .rst_i(rst), 
        .text_i(data), 
        .text_o( ), 
        .text_o0(text_o0), 
        .text_o1(text_o1), 
        .text_o2(text_o2), 
        .text_o3(text_o3), 
        .text_o4(text_o4), 
        .text_o5(text_o5), 
        .text_o6(text_o6), 
        .text_o7(text_o7), 
        .done(done_SHA), 
        .cmd_i(cmd_i), 
        .cmd_w_i(cmd_w_i), 
        .cmd_o(cmd_o)
    );
    
    controller256 u_controller256 (
        .clk(clk),
        .rst(rst),
        .go(go),
        .data_in(padded_data),
        .data(data),    
        .done_SHA(done_SHA),
        .cmd_i(cmd_i),
        .cmd_w_i(cmd_w_i),
        .cmd_o(cmd_o),
        .done(done)        
    );                 
endmodule
