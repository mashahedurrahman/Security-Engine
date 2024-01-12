//`timescale 1ns / 1ps
module Data_reg 
    #(parameter width = 8) (
    input wire clk,
    input wire rst,
    input wire en,
    input wire [width-1:0] in,
    output reg [width-1:0] out
    );
    
    always @(posedge rst, posedge clk) begin
        if (rst) begin
            out <= 0;
        end
        else if (en) begin
            out <= in;
        end
    end
endmodule

