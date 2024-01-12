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

//`timescale 1ns / 1ps
`define INVERTER_DELAY_REF 2
`define INVERTER_DELAY_STR 2.4

module sn_cdir_decoder  #(
    parameter NO_INV_STAGE=21, 	// No. of inverter stages in each ring oscillator
    parameter TIMER=100,	// Timer (clock cycle) for ring oscillator frequency measurement
    parameter NO_CDIR=8,	// No. of RO blocks / combating die and recycling (CDIR) sensors
    parameter MUX_SEL_SIZE= $clog2(NO_CDIR) //3 	// Mux select size = log2(NO_CDIR)
    )(
    clk, mode, 		// mode = 00 (reset), 01 (normal operation - ref RO sleep, stressed RO active), 10 (authentication - both RO active, counter active)
    r_mux_sel, s_mux_sel,	// select RO outputs - for reference and stressed RO
    r_freq, s_freq, valid_out	// frequency outputs - ref RO and stressed RO
    );

    
    input wire clk;
    input wire [1:0] mode;
    input wire [MUX_SEL_SIZE-1:0] r_mux_sel, s_mux_sel;
    
    output reg [31:0] r_freq, s_freq;
    output reg valid_out;
    
    reg r_en, s_en;
    wire [NO_CDIR-1:0] r_clk_o, s_clk_o;
    wire r_mux_o, s_mux_o;

    
    reg [31:0] time_cc=0;
    reg [31:0] temp_count1= 0;
    reg[31:0] temp_count2 = 0; 
    
    reg [31:0] count1, count2 = 0;
    
    genvar i;
    generate 
        for (i=0; i<NO_CDIR; i=i+1) begin: CDIR

            ring_oscillator #(
                    .NO_STAGES(NO_INV_STAGE),      // No of inverter stage
                    .INV_DELAY(`INVERTER_DELAY_REF)       // Delay of single inverter in 0.01*ns

                    ) ref_ro(
                        .en_ro(r_en),
                        .ro_out(r_clk_o[i])
                    ); 
            
            ring_oscillator #(
                    .NO_STAGES(NO_INV_STAGE),      // No of inverter stage
                    .INV_DELAY(`INVERTER_DELAY_STR)       // Delay of single inverter in 0.01*ns

                    ) str_ro(
                        .en_ro(s_en),
                        .ro_out(s_clk_o[i])
                    ); 
            end
    endgenerate                   
    
 mux_ro #(
        .NO_MUX_IN(NO_CDIR),
        .MUX_SEL_SIZE(MUX_SEL_SIZE))
    mux_ref_ro (         
        .d(r_clk_o),
        .select(r_mux_sel),
        .q(r_mux_o)        
    );
mux_ro #(
        .NO_MUX_IN(NO_CDIR),
        .MUX_SEL_SIZE(MUX_SEL_SIZE))
    mux_str_ro (         
        .d(s_clk_o),
        .select(s_mux_sel),
        .q(s_mux_o)        
    );
  

always @(posedge clk)
begin
    case (mode)
        0: begin    // Reset/Initialize
            r_en = 0;
            s_en = 0;
            time_cc <= 0;
            valid_out <= 0; 
            end
            
        1: begin   // Ref RO in Sleep, Stressed RO active
            r_en = 0;
            s_en = 1;
            time_cc <= 0;
            valid_out <= 0; 
            end
            
        2: begin    // Regular RO operation, measure both ref RO and stressed RO count for TIMER clock cycles 
            r_en = 1;
            s_en = 1;
            
            if (time_cc <= TIMER) begin
                time_cc <= time_cc +1;
            end else if (time_cc > TIMER) begin
                valid_out <= 1;
            end
            end      
        
        default: begin  // Ref RO in Sleep, Stressed RO active
            r_en = 0;
            s_en = 1;
            time_cc <= 0;
            valid_out <= 0; 
            end
    endcase
end



always @(negedge r_mux_o) begin
    case (mode)
        2: begin
             if (time_cc < TIMER) begin   
                    temp_count1 <=temp_count1 + 1;
             end                
        end
        default: begin
            temp_count1 <= 0;
        end
    endcase
    r_freq <= temp_count1;
end

always @(negedge s_mux_o) begin
    case (mode)
        2: begin
             if (time_cc < TIMER) begin   
                    temp_count2 <=temp_count2 + 1;
             end                
        end
        default: begin
            temp_count2 <= 0;
        end
    endcase
    s_freq <= temp_count2;      
end


endmodule

