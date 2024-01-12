/////////////////////////////////////////////////////////////////////////////////////////
// Company: Florida Institute of Cybersecurity (FICS) Research at University of Florida 
// Engineer: Md Kawser Bepary
//
// Create Date: 05/22/2021 05:15:38 AM 
// Design Name: Ring Oscillator based Lifecycle Odometer 
// Module Name: sn_cdir_decoder 
// Project Name: AISS TA1.2.4 - Hardware Security IP 
// Target Devices: 
// Tool Versions : 
// Description: Lifecycle odometer is designed based on a pair of negativce bias temperature instability (NBTI) - aware ring oscillators (ROS). The reference RO remains quiet during the normal operation and stressed RO gets aged at an accelerated pace. This IP provides the frequency difference number of oscillations in a given number of cycles) as an output which is used to detect the usage time of the device.
//
// Dependencies:
// Revision: 
// Revision 0.01 - File Created 
// Additional Comments: 
////////////////////////////////////////////////////////////////////////////////////////

`timescale 1ns / 1ps

module tb_sn_cdir();
    parameter NO_INV_STAGE=21;      // No. of inverter stages in each ring oscillator
    parameter TIMER=100;       // Timer (clock cycle) for ring oscillator frequency measurement
    parameter NO_CDIR=8;        // No. of RO blocks / combating die and recycling (CDIR) sensors
    parameter MUX_SEL_SIZE=3;       // Mux select size = log2(NO_CDIR)

reg clk;
reg [1:0] mode;     // mode = 00 (reset), 01 (normal operation - ref RO sleep, stressed RO active), 10 (authentication - both RO active, counter active)
reg [MUX_SEL_SIZE-1:0] r_mux_sel, s_mux_sel;    // select RO outputs - for reference and stressed RO

wire [31:0] r_freq, s_freq;     // frequency outputs - ref RO and stressed RO
wire valid_out;

sn_cdir_decoder #(
    .NO_INV_STAGE(NO_INV_STAGE),
    .TIMER(TIMER),
    .NO_CDIR(NO_CDIR),
    .MUX_SEL_SIZE(MUX_SEL_SIZE) //log2(NO_CDIR)

) dut(
    .clk(clk), 
    .mode(mode), 
    .r_mux_sel(r_mux_sel),
    .s_mux_sel(s_mux_sel),
    .r_freq(r_freq),
    .s_freq(s_freq),
    .valid_out(valid_out)
    );
    
always #5 clk=~clk;

//testbench code
initial begin 
    $dumpfile("tb_sn_cdir.vcd");
    $dumpvars(0, sn_cdir_decoder);
	//$monitor ("@%0dns valid_out=%b r_freq=%b s_freq=%b ", $time, valid_out,r_freq,s_freq);
    
    clk =0;
    r_mux_sel = 3'b010;
    s_mux_sel = 3'b110;

 // mode = 00 (reset), 01 (normal operation - ref RO sleep, stressed RO active), 10 (authentication - both RO active, counter active)
    #200 
    mode = 2'b00;  // Reset/Initialize
    #500 
    $display ("\nFor mode= %b, valid_out= %b, r_freq= %h, s_freq= %h", mode, valid_out, r_freq, s_freq);
    mode =2'b01;   // Ref RO in sleep, stressed RO in active
    #500 
    $display ("For mode= %b, valid_out= %b, r_freq= %h, s_freq= %h", mode, valid_out, r_freq, s_freq);
    mode =2'b10;   // Regular RO operation, measure both ref RO and stressed RO count for TIMER clock cycles
    #1100 
    $display ("For mode= %b, valid_out= %b, r_freq= %h, s_freq= %h", mode, valid_out, r_freq, s_freq);
    mode =2'b11;  // Idle / Default: ref RO in sleep, stressed RO active
    #500
    $display ("For mode= %b, valid_out= %b, r_freq= %h, s_freq= %h", mode, valid_out, r_freq, s_freq);

    #200 
    mode = 2'b00;  // Reset/Initialize
    #500 
    $display ("\nFor mode= %b, valid_out= %b, r_freq= %h, s_freq= %h", mode, valid_out, r_freq, s_freq);
    mode =2'b01;   // Ref RO in sleep, stressed RO in active
    #500 
    $display ("For mode= %b, valid_out= %b, r_freq= %h, s_freq= %h", mode, valid_out, r_freq, s_freq);
    mode =2'b10;   // Regular RO operation, measure both ref RO and stressed RO count for TIMER clock cycles
    #1100 
    $display ("For mode= %b, valid_out= %b, r_freq= %h, s_freq= %h", mode, valid_out, r_freq, s_freq);
    mode =2'b11;  // Idle / Default: ref RO in sleep, stressed RO active
    #500
    $display ("For mode= %b, valid_out= %b, r_freq= %h, s_freq= %h \n", mode, valid_out, r_freq, s_freq);
    #200 $finish;
end

endmodule
