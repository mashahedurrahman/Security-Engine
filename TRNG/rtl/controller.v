//`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 02/07/2022 11:46:26 PM
// Design Name: 
// Module Name: controller
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


module controller256(
    input wire clk,
    input wire rst,
    input wire go,
    input wire [1023:0] data_in,
    output reg [31:0] data,
    input wire done_SHA,
    output reg [2:0] cmd_i,
    output reg cmd_w_i,
    input wire [3:0] cmd_o,
    output reg done
);

    localparam [3:0] WAIT_FOR_GO = 4'b0000, 
                     SHA_1 = 4'b0001, 
                     SHA_READ_1 = 4'b0010, 
                     SHA_WAIT1 = 4'b0011, 
                     SHA_SET1 = 4'b0100, 
                     SHA_READ_2 = 4'b0101, 
                     SHA_WAIT2 = 4'b0110, 
                     SHA_SET2 = 4'b0111, 
                     S_DONE = 4'b1000;
                     
    reg [4:0] count;
    reg [3:0] state;
    reg [31:0] arr [0:31];
    integer i;
    
    
    always @(posedge rst, posedge clk) begin
        if (rst) begin
            state <= WAIT_FOR_GO;
            cmd_w_i <= 1'b0;
            done <= 1'b0;
            cmd_i <= 3'd0;
            data <= 32'd0;    
            count <= 5'd0;
        end
        else begin
            cmd_w_i <= 1'b0;
            done <= 1'b0;
            case (state) 
                WAIT_FOR_GO : begin   
                    count <= 5'd0;
                    if (go) begin
                        state <= SHA_1;
                        arr[0] <= data_in[31:0];
                        arr[1] <= data_in[63:32];
                        arr[2] <= data_in[95:64];
                        arr[3] <= data_in[127:96];
                        arr[4] <= data_in[159:128];
                        arr[5] <= data_in[191:160];
                        arr[6] <= data_in[223:192];
                        arr[7] <= data_in[255:224];
                        arr[8] <= data_in[287:256];
                        arr[9] <= data_in[319:288];
                        arr[10] <= data_in[351:320];
                        arr[11] <= data_in[383:352];
                        arr[12] <= data_in[415:384];
                        arr[13] <= data_in[447:416];
                        arr[14] <= data_in[479:448];
                        arr[15] <= data_in[511:480];
                        arr[16] <= data_in[543:512];
                        arr[17] <= data_in[575:544];
                        arr[18] <= data_in[607:576];
                        arr[19] <= data_in[639:608];
                        arr[20] <= data_in[671:640];
                        arr[21] <= data_in[703:672];
                        arr[22] <= data_in[735:704];
                        arr[23] <= data_in[767:736];
                        arr[24] <= data_in[799:768];
                        arr[25] <= data_in[831:800];
                        arr[26] <= data_in[863:832];
                        arr[27] <= data_in[895:864];
                        arr[28] <= data_in[927:896];
                        arr[29] <= data_in[959:928];
                        arr[30] <= data_in[991:960];
                        arr[31] <= data_in[1023:992];
                    end
                    else begin
                        state <= WAIT_FOR_GO;
                    end                
                end
                SHA_1 : begin
                    cmd_w_i <= 1'b1;
                    cmd_i <= 3'b010;
                    state <= SHA_READ_1;            
                end
                SHA_READ_1 : begin
                    data <= arr[31];
                    for (i = 1; i < 32; i = i+1) begin
                        arr[i] <= arr[i-1];
                    end
                    arr[0] <= 32'd0;
                    count <= count + 1'b1;
                    if (count == 5'd15) 
                        state <= SHA_WAIT1;
                    else 
                        state <= SHA_READ_1;            
                end
                SHA_WAIT1 : begin
                    if (cmd_o[3] == 1'b1) 
                        state <= SHA_WAIT1;
                    else
                        state <= SHA_SET1;
                end
                SHA_SET1 : begin
                    cmd_i <= 3'b110;
                    cmd_w_i <= 1'b1;
                    state <= SHA_READ_2;            
                end
                SHA_READ_2 : begin
                    data <= arr[31];
                    for (i = 1; i < 32; i = i + 1) begin
                        arr[i] <= arr[i-1];
                    end            
                    arr[0] <= 32'd0; 
                    count <= count + 1'b1;
                    if (count == 5'd31) 
                        state <= SHA_WAIT2;
                    else
                        state <= SHA_READ_2;           
                end
                SHA_WAIT2 : begin
                    if (cmd_o[3] == 1'b1) 
                        state <= SHA_WAIT2;
                    else 
                        state <= SHA_SET2;            
                end
                SHA_SET2 : begin
                    cmd_i <= 3'b001;
                    cmd_w_i <= 1'b1;
                    if (done_SHA == 1'b1) 
                        state <= S_DONE;
                    else
                        state <= SHA_SET2;            
                end
                S_DONE : begin
                    done <= 1'b1;
                    if (go == 1'b0) 
                        state <= WAIT_FOR_GO;
                    else
                        state <= S_DONE;
                end
                default : begin
                    state <= WAIT_FOR_GO;
                    cmd_w_i <= 1'b0;
                    done <= 1'b0;
                    cmd_i <= 3'b000;
                    data <= 32'd0;
                end
            endcase
        end
    end
endmodule

