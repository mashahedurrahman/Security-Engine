`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
//// Company: University of Florida
//// Engineer: Sujan Kumar Saha
//// 
//// Create Date: 10/10/2023 01:30:37 PM
//// Design Name: 
//// Module Name: montgomeryLadder_tb
//// Project Name: AISS
//// Target Devices: 
//// Tool Versions: 
//// Description: 
//// 
//// Dependencies: 
//// 
//// Revision:
//// Revision 0.01 - File Created
//// Additional Comments:
//// 
////////////////////////////////////////////////////////////////////////////////////


module montgomeryLadder_tb;
    parameter key_size = 256;
    parameter integer_size = 64;
    parameter period = 5; // Clock period
    //---Inputs----
    reg         clk;
    reg         rst;
    reg		go;
    reg [key_size-1:0]	m;
    reg [integer_size-1:0]	prime;
    reg [integer_size-1:0]	A;
    reg [integer_size-1:0]	B;
    reg [integer_size-1:0]	Px;
    reg [integer_size-1:0]	Py;
    reg [integer_size-1:0]	Ox;
    reg [integer_size-1:0]	Oy;
    
    //---Outputs---
    wire        done;
    wire        infinityP;
    wire [key_size-1:0] mGx;
    wire [key_size-1:0] mGy;


    //module instantiation
    montgomeryLadder UUT(
	.m(m),
	.clk(clk), 
	.rst(rst), 
	.go(go), 
	.done(done), 
	.infinityP(infinityP), 
	.prime(prime), 
	.A(A), 
	.B(B), 
	.Px(Px), 
	.Py(Py), 
	.Ox(Ox), 
	.Oy(Oy), 
	.mGx(mGx), 
	.mGy(mGy)
    );

    always #(period) clk = !clk;

    initial begin
	clk	<=0;
	#period;
        rst	<= 1;
        #(period*4);
        rst	<= 0;
        #period;
	m	<= 217457;
	prime	<= 11;
	A	<= 2;
	B	<= 3;
	Px	<= 2;
	Py	<= 7;
	Ox	<= 9;
	Oy	<= 17;
	go	<= 1;
	//#(period*4);
	//go	<= 0;
	#period;
	wait(done == 1);
	$display("infinityP = %b", infinityP);
	$display("mGx = %h", mGx);
	$display("mGy = %h", mGy);
    end

endmodule
