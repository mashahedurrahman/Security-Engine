`timescale	1ns/10ps


module Mux_N #(
	parameter WIDTH = 12)(sel,a,b,z);
input [WIDTH-1:0] a,b;
output [WIDTH-1:0]z;
input sel;

assign z = (sel==0) ? a : b;
endmodule
