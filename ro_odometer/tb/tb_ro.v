`timescale 1ns/1ps
`define INVERTER_DELAY_REF 20
//`include "ring_oscillator.v"

module tb_ro ();
    reg en_ro, en_trans, nmos_g, ro_sleep;
    wire ro_out;
    supply0 GND;
    supply1 PWR;
    
    parameter NO_INV_STAGE=21;                       
                
    ring_oscillator #(
            .NO_STAGES(NO_INV_STAGE),      // No of inverter stage
            .INV_DELAY(`INVERTER_DELAY_REF)       // Delay of single inverter in 0.01*ns

    ) test_ro(
                .en_ro(en_ro),
                .ro_out(ro_out),
                .nmos_g(nmos_g),
                .en_trans(en_trans),
                .ro_sleep(ro_sleep)
            );                      
    initial begin
        $dumpfile("tb_ro.vcd");
        $dumpvars(0, tb_ro);
        
        // Initialize the initial
        ro_sleep=1; en_ro =0; en_trans =1; nmos_g=0;
        #200
        
        // Enable regular RO output
        ro_sleep=1; en_ro =1; en_trans =1; nmos_g=0;
        #200
        
        // Reference RO Sleep mode
        ro_sleep=0; en_ro =0; en_trans =0; nmos_g=0;
        #200
        
        // Stressed RO active mode
        ro_sleep=1; en_ro =0; en_trans =0; nmos_g=1;
        #200
        
        // Initialize the initial
        ro_sleep=1; en_ro =0; en_trans =1; nmos_g=0;
        #200
        // Enable regular RO output
        ro_sleep=1; en_ro =1; en_trans =1; nmos_g=0;
        #200     
                

        $monitor("@:%t ro_out:%0b", $time, ro_out);
        
        #200;
        $finish();
    end


endmodule 