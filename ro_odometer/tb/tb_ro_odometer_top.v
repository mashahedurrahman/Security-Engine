`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 09/19/2022 02:40:30 PM
// Design Name: 
// Module Name: tb_ro_odometer_top
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


module tb_ro_odometer_top();
    parameter NO_INV_STAGE=21;      // No. of inverter stages in each ring oscillator
    parameter TIMER=100;       // Timer (clock cycle) for ring oscillator frequency measurement
    parameter NO_CDIR=8;        // No. of RO blocks / combating die and recycling (CDIR) sensors
    parameter MUX_SEL_SIZE=$clog2(NO_CDIR); //3;       // Mux select size = log2(NO_CDIR)

    
    reg clk;
    reg rst, go, en_out;
    reg [MUX_SEL_SIZE-1:0] r_mux_sel, s_mux_sel;
        
    wire [31:0] r_freq, s_freq;
    wire valid_out; 
    
    ro_odometer_top ro_odometer_top (
    .clk(clk),
    .rst(rst),
    .go(go),
    .en_out(en_out),
    .r_mux_sel(r_mux_sel),
    .s_mux_sel(s_mux_sel),	// select RO outputs - for reference and stressed RO
    .r_freq(r_freq),
    .s_freq(s_freq),
    .valid_out(valid_out)	// frequency outputs - ref RO and stressed RO
    );
    
    
always #5 clk=~clk;

//testbench code
initial begin 
    $dumpfile("tb_ro_odometer_top.vcd");
    $dumpvars(0, tb_ro_odometer_top);
	//$monitor ("@%0dns valid_out=%b r_freq=%b s_freq=%b ", $time, valid_out,r_freq,s_freq);
    
    clk =0;
    r_mux_sel = 3'b010;
    s_mux_sel = 3'b110;

    #200 
    rst = 1'b1;  // Reset/Initialize
    #50 
    rst = 1'b0;
    #50
    $display ("\nFor IDLE state, valid_out= %b, r_freq= %h, s_freq= %h", valid_out, r_freq, s_freq);
    
    go =1'b1;  // Ref RO in sleep, stressed RO in active
    #50 
    go =1'b0;
    #500
    $display ("For ACTIVE state, valid_out= %b, r_freq= %h, s_freq= %h", valid_out, r_freq, s_freq);
    en_out =1'b1;   // Regular RO operation, measure both ref RO and stressed RO count for TIMER clock cycles
    
    #50 
    en_out =1'b0; 
    wait (valid_out==1);
    $display ("For AUTH state, valid_out= %b, r_freq= %h, s_freq= %h",  valid_out, r_freq, s_freq);
      // Idle / Default: ref RO in sleep, stressed RO active
    #500
    $display ("For IDLE, valid_out= %b, r_freq= %h, s_freq= %h", valid_out, r_freq, s_freq);

 $finish;
end
endmodule
