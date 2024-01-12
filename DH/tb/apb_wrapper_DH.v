`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company:
// Engineer:
//
// Create Date: 02/03/2022 02:01:16 AM
// Design Name:
// Module Name: apb_wrapper_DH
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


module apb_wrapper_DH#(
    parameter BUS_WIDTH = 32,
    parameter ADDR_OFFSET= 'h00000000
    )
    (
    input clk,
    input rst,
    // Interface to APB bridge
    input S_PSEL,
    input S_PENABLE,
    input [BUS_WIDTH-1:0] S_PADDR,
    input S_PWRITE,
    input [BUS_WIDTH-1:0] S_PWDATA,
    output reg  S_PREADY,
    output reg  S_PSLVERR,
    output reg [BUS_WIDTH-1:0] S_PRDATA
    );

    wire apb_write;
    wire apb_read;
    wire [7:0] addr_index;

    reg [282:0] cx_reg;
    reg   done_reg;
    // Interface to SHA module
    wire  done;
    wire [282:0] cx;
    reg  [282:0] ax;
    reg  [282:0] bx;
    reg go;
    reg   reset;

    assign apb_write = S_PSEL & S_PENABLE & S_PWRITE;
    assign apb_read = S_PSEL & ~S_PWRITE;
    assign addr_index = S_PADDR[7:0];

    //---serial_multiplier_283 instantiation-------
    serial_multiplier_283 U0_serial_multiplier_283(
        .ax(ax),
        .bx(bx),
        .cx(cx),
        .go(go),
	    .reset(reset),
	    .clk(clk),
	    .done(done)
    );

    always @( posedge clk )
	begin
	  if ( !rst )
	    begin
	      cx_reg <= 0;
	      done_reg <= 0;
	    end
	  else
	    begin
	      cx_reg <=cx;
	      done_reg <= done;
	    end
	end

	always@(posedge clk)
    begin
        if (!rst) begin
            S_PREADY    <= 1;
            S_PSLVERR   <= 0;
            S_PRDATA    <= 0;
            ax          <= 0;
            bx          <= 0;
            reset       <= 1;
        end
        else begin
        S_PREADY  <= 1;
        S_PSLVERR <= 0;
        reset     <= 0;
            if (apb_write) begin
            case (addr_index)
                8'h00: ax[31:0]     <= S_PWDATA;
                8'h04: ax[63:32]    <= S_PWDATA;
                8'h08: ax[95:64]    <= S_PWDATA;
                8'h0C: ax[127:96]   <= S_PWDATA;
                8'h10: ax[159:128]  <= S_PWDATA;
                8'h14: ax[191:160]  <= S_PWDATA;
                8'h18: ax[223:192]  <= S_PWDATA;
                8'h1C: ax[255:224]  <= S_PWDATA;
                8'h20: ax[282:256]  <= S_PWDATA[26:0];
                8'h24: bx[31:0]     <= S_PWDATA;
                8'h28: bx[63:32]    <= S_PWDATA;
                8'h2C: bx[95:64]    <= S_PWDATA;
                8'h30: bx[127:96]   <= S_PWDATA;
                8'h34: bx[159:128]  <= S_PWDATA;
                8'h38: bx[191:160]  <= S_PWDATA;
                8'h3C: bx[223:192]  <= S_PWDATA;
                8'h40: bx[255:224]  <= S_PWDATA;
                8'h44: bx[282:256]  <= S_PWDATA[26:0];
                8'h54: go        <= S_PWDATA[0:0];
            endcase
            end
            else if (apb_read) begin
            case (addr_index)
                8'h00: S_PRDATA <= ax[31:0];
                8'h04: S_PRDATA <= ax[63:32];
                8'h08: S_PRDATA <= ax[95:64];
                8'h0C: S_PRDATA <= ax[127:96];
                8'h10: S_PRDATA <= ax[159:128];
                8'h14: S_PRDATA <= ax[191:160];
                8'h18: S_PRDATA <= ax[223:192];
                8'h1C: S_PRDATA <= ax[255:224];
                8'h20: S_PRDATA <= {5'h0, ax[282:256]};
                8'h24: S_PRDATA <= bx[31:0];
                8'h28: S_PRDATA <= bx[63:32];
                8'h2C: S_PRDATA <= bx[95:64];
                8'h30: S_PRDATA <= bx[127:96];
                8'h34: S_PRDATA <= bx[159:128];
                8'h38: S_PRDATA <= bx[191:160];
                8'h3C: S_PRDATA <= bx[223:192];
                8'h40: S_PRDATA <= bx[255:224];
                8'h44: S_PRDATA <= {5'h0, bx[282:256]};
                8'h54: S_PRDATA <= {31'h0, go};
                8'h60: S_PRDATA <= {31'h0, done_reg};
                8'h64: S_PRDATA <= cx_reg[31:0];
                8'h68: S_PRDATA <= cx_reg[63:32];
                8'h6C: S_PRDATA <= cx_reg[95:64];
                8'h70: S_PRDATA <= cx_reg[127:96];
                8'h74: S_PRDATA <= cx_reg[159:128];
                8'h78: S_PRDATA <= cx_reg[191:160];
                8'h7C: S_PRDATA <= cx_reg[223:192];
                8'h80: S_PRDATA <= cx_reg[255:224];
                8'h84: S_PRDATA <= {5'h0, cx_reg[282:256]};
            endcase
            end else
                S_PRDATA  <= 0;
        end
    end
endmodule
