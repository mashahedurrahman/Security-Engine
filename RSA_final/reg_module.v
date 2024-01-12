//`timescale 1ns/1ps


module reg_module(
        clk,
        rst,
        en,
        inp,
        outp
    );
    parameter [31:0]width  = 4096;
    input clk;
    input rst;
    input en;
    input [( width - 1 ):0] inp;
    output reg [( width - 1 ):0] outp;

    always @ (  posedge clk,  posedge rst)
    begin
        if ( rst) 
        begin
            outp <= 0;
        end
        else
        begin 
  
                if ( en == 1'b1 ) 
                begin
                    outp <= inp;
                end
          
        end
    end
endmodule 
