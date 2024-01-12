//`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
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
// 
//////////////////////////////////////////////////////////////////////////////////


module ro_odometer_top #(
    parameter NO_INV_STAGE=21, 	// No. of inverter stages in each ring oscillator
    parameter TIMER=100,	// Timer (clock cycle) for ring oscillator frequency measurement
    parameter NO_CDIR=8,	// No. of RO blocks / combating die and recycling (CDIR) sensors
    parameter MUX_SEL_SIZE= $clog2(NO_CDIR) //3 	// Mux select size = log2(NO_CDIR)
    )(
    input clk,
    input rst,
    input go,
    input en_out,
    input [MUX_SEL_SIZE-1:0] r_mux_sel,
    input [MUX_SEL_SIZE-1:0] s_mux_sel,
    output [31:0] r_freq,
    output [31:0] s_freq,
    output valid_out
    );
    

// Internal constants
parameter SIZE = 4;
parameter IDLE = 4'b0001, ACTIVE = 4'b0010, AUTH1 = 4'b0100, AUTH2 = 4'b1000; // modes of operations / FSM states
// Internal variables
reg [SIZE-1:0] state, next_state;

// Controller FSM
reg [1:0] mode;
always @(posedge clk, posedge rst) begin
    if (rst) state <= IDLE;
        else state <= next_state;
end

always @(state, go, en_out, valid_out) begin
    case(state)
        IDLE: begin
            mode=2'b00;
            if (go) next_state = ACTIVE;
            else if (en_out) next_state = AUTH1;
            else next_state = IDLE;
        end
        
        ACTIVE: begin
            mode=2'b01;
            if (en_out) next_state = AUTH1;
            else next_state = ACTIVE;
        end
        
        AUTH1: begin
            mode=2'b00;
            next_state = AUTH2;            
        end 

        AUTH2: begin
            mode=2'b10;
            if (valid_out && go) next_state = ACTIVE;
            else next_state = AUTH2;            
        end 
    endcase     
end

sn_cdir_decoder #(
    .NO_INV_STAGE(NO_INV_STAGE), 	// No. of inverter stages in each ring oscillator
    .TIMER(TIMER),	// Timer (clock cycle) for ring oscillator frequency measurement
    .NO_CDIR(NO_CDIR),	// No. of RO blocks / combating die and recycling (CDIR) sensors
    .MUX_SEL_SIZE(MUX_SEL_SIZE) 	// Mux select size = log2(NO_CDIR)
    )
    ro_odometer(
    .clk(clk),
    .mode(mode), 		// mode = 00 (reset), 01 (normal operation - ref RO sleep, stressed RO active), 10 (authentication - both RO active, counter active)
    .r_mux_sel(r_mux_sel),
    .s_mux_sel(s_mux_sel),	// select RO outputs - for reference and stressed RO
    .r_freq(r_freq),
    .s_freq(s_freq),
    .valid_out(valid_out)	// frequency outputs - ref RO and stressed RO
    );

endmodule

