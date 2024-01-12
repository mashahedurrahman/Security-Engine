`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 02/03/2022 04:37:36 PM
// Design Name: 
// Module Name: apb_wrapper_DH_tb
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


module apb_wrapper_DH_tb;
    parameter period = 5; // Clock period
    //parameter KEYSIZE = 256;
    //---Inputs----
    reg         clk;
    reg         rst;
    reg         S_PSEL;
    reg         S_PENABLE;
    reg [31:0]  S_PADDR;
    reg         S_PWRITE;
    reg [31:0]  S_PWDATA;
   
    //---Outputs---
    wire        S_PREADY;
    wire        S_PSLVERR;
    wire [31:0] S_PRDATA;
    
    //module instantiation
    apb_wrapper_DH UUT(
        .clk(clk),
        .rst(rst),
        .S_PSEL(S_PSEL),
        .S_PENABLE(S_PENABLE),
        .S_PADDR(S_PADDR),
        .S_PWRITE(S_PWRITE),
        .S_PWDATA(S_PWDATA),
        .S_PREADY(S_PREADY),
        .S_PSLVERR(S_PSLVERR),
        .S_PRDATA(S_PRDATA)
    );

    always #(period) clk = !clk;
    
    initial begin
        clk             <= 0;
        S_PSEL          <= 0;
        S_PENABLE       <= 0;
        S_PADDR         <= 0;
        S_PWRITE        <= 0;
        S_PWDATA        <= 0;
        #period;
        rst <= 0;
        #(period*4);
        rst <= 1;
        #period;
        
        //---sending ax-------
        S_PSEL          <= 1;
        S_PENABLE       <= 1;
        S_PADDR         <= 32'h00000000;
        S_PWRITE        <= 1;
        S_PWDATA        <= 32'h00000002;
        #(period*2);
        S_PADDR         <= 32'h00000004;
        S_PWRITE        <= 1;
        S_PWDATA        <= 32'h00000004;
        #(period*2);
        S_PADDR         <= 32'h00000008;
        S_PWRITE        <= 1;
        S_PWDATA        <= 32'h00000006;
        #(period*2);
        S_PADDR         <= 32'h0000000C;
        S_PWRITE        <= 1;
        S_PWDATA        <= 32'h00000008;
        #(period*2);
        S_PADDR         <= 32'h00000010;
        S_PWRITE        <= 1;
        S_PWDATA        <= 32'h0000000A;
        #(period*2);
        S_PADDR         <= 32'h00000014;
        S_PWRITE        <= 1;
        S_PWDATA        <= 32'h0000000C;
        #(period*2);
        S_PADDR         <= 32'h00000018;
        S_PWRITE        <= 1;
        S_PWDATA        <= 32'h0000000E;
        #(period*2);
        S_PADDR         <= 32'h0000001C;
        S_PWRITE        <= 1;
        S_PWDATA        <= 32'h00000012;
        #(period*2);
        S_PADDR         <= 32'h00000020;
        S_PWRITE        <= 1;
        S_PWDATA        <= 32'h00000014;
        #(period*2);
        //---sending bx-------
        S_PADDR         <= 32'h00000024;
        S_PWRITE        <= 1;
        S_PWDATA        <= 32'h00000012;
        #(period*2);
        S_PADDR         <= 32'h00000028;
        S_PWRITE        <= 1;
        S_PWDATA        <= 32'h00000014;
        #(period*2);
        S_PADDR         <= 32'h0000002C;
        S_PWRITE        <= 1;
        S_PWDATA        <= 32'h00000016;
        #(period*2);
        S_PADDR         <= 32'h00000030;
        S_PWRITE        <= 1;
        S_PWDATA        <= 32'h00000018;
        #(period*2);
        S_PADDR         <= 32'h00000034;
        S_PWRITE        <= 1;
        S_PWDATA        <= 32'h0000001A;
        #(period*2);
        S_PADDR         <= 32'h00000038;
        S_PWRITE        <= 1;
        S_PWDATA        <= 32'h0000001C;
        #(period*2);
        S_PADDR         <= 32'h0000003C;
        S_PWRITE        <= 1;
        S_PWDATA        <= 32'h0000001E;
        #(period*2);
        S_PADDR         <= 32'h00000040;
        S_PWRITE        <= 1;
        S_PWDATA        <= 32'h00000022;
        #(period*2);
        S_PADDR         <= 32'h00000044;
        S_PWRITE        <= 1;
        S_PWDATA        <= 32'h00000024;
        #(period*2);
        //---sending go signal from the application----
        S_PADDR         <= 32'h00000054;
        S_PWRITE        <= 1;
        S_PWDATA        <= 32'h00000001;
        #(period*2);
        S_PADDR         <= 32'h00000054;
        S_PWRITE        <= 1;
        S_PWDATA        <= 32'h00000000;
        #(period*2);
        //---sending address to read done=1 signal----
        S_PADDR         <= 32'h00000060;
        S_PWRITE        <= 0;
        wait(S_PRDATA[0]==1);
        //---sending address to read the cx value---
        S_PADDR         <= 32'h00000064;
        S_PWRITE        <= 0;
        #(period*2);
        S_PADDR         <= 32'h00000068;
        S_PWRITE        <= 0;
        #(period*2);
        S_PADDR         <= 32'h0000006C;
        S_PWRITE        <= 0;
        #(period*2);
        S_PADDR         <= 32'h00000070;
        S_PWRITE        <= 0;
        #(period*2);
        S_PADDR         <= 32'h00000074;
        S_PWRITE        <= 0;
        #(period*2);
        S_PADDR         <= 32'h00000078;
        S_PWRITE        <= 0;
        #(period*2);
        S_PADDR         <= 32'h0000007C;
        S_PWRITE        <= 0;
        #(period*2);
        S_PADDR         <= 32'h00000080;
        S_PWRITE        <= 0;
        #(period*2);
        S_PADDR         <= 32'h00000084;
        S_PWRITE        <= 0;
        #(period*2);
    end
endmodule
