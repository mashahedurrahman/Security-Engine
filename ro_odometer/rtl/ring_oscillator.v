//`timescale 1ns/1ps

module ring_oscillator #(
                        parameter NO_STAGES=21,      // No of inverter stage
                        parameter INV_DELAY= 20       // Delay of single inverter in 0.01*ns

                        )(
                            input wire en_ro,
                            output wire ro_out
                        );    
    
    (* DONT_TOUCH = "TRUE" *) wire [NO_STAGES:0] wi;
  
    assign wi[0] = en_ro ? wi[NO_STAGES] : 0;
    assign ro_out = en_ro ? wi[NO_STAGES] : 0;
    
    genvar i;
    generate
        for(i = 0; i < NO_STAGES; i = i+1) begin : ro
            (* DONT_TOUCH = "TRUE" *) not #(INV_DELAY*0.01) (wi[i+1], wi[i]);
        end
    endgenerate 
    
endmodule  
