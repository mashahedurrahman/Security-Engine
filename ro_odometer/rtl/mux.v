//`timescale 1ns / 1ps

module mux_ro #(
            parameter NO_MUX_IN=8,      // No of MUX inputs
            parameter MUX_SEL_SIZE=3       // MUX Select size

            )
            ( d, select, q );

input wire [NO_MUX_IN-1:0] d;
input wire [MUX_SEL_SIZE-1:0] select;
output wire q;

assign q = d[select];

endmodule
