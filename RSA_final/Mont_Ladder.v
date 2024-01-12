//`timescale 1ns/1ps

module mont_lad(
        clk,
        rst,
        go,
        X,
        E,
        N,
        O,
        done
    );
	
	

    parameter [31:0] width  = 4096;
    input clk;
    input rst;
    input go;
    input [( width - 1 ):0] X;
    input [( width - 1 ):0] E;
    input [( width - 1 ):0] N;
    output reg [( width - 1 ):0] O;
    output reg done;
    
	localparam [2:0] WAIT_FOR_GO = 3'b000, 
                     S_READ = 3'b001, 
                     S_ZERO_R1 = 3'b010,
					 S_ZERO_R0 = 3'b011,					
                     S_ONE_R0 = 3'b100,
					 S_ONE_R1 = 3'b101,
                     S_MOD = 3'b110, 
                     S_DONE = 3'b111;
	reg [2:0] state;
    reg condition0;
    reg condition1;

    reg signed [11:0] i = width - 1;
    reg [( width - 1 ):0] R1=  0;
    reg [( width - 1 ):0] R0 = 0;
    reg [( width - 1 ):0] sub = 0;
	
	reg start = 0;
	wire ready_mult;
	reg [(width - 1) : 0] X_data_temp, Y_data_temp;
	wire [(2*width -1): 0] out_mult;
	
	
    BoothMultiplier #(4, 11) mult_1( .clock(clk), .clear(rst), .start(start), 
		.X_data(X_data_temp), .Y_data(Y_data_temp), .ready(ready_mult), .Result(out_mult));
	
	
	
    always @ (  posedge clk, posedge rst)
    begin
        if ( rst) 
        begin
            O <= 0;
            condition0 <= 0;
            condition1 <= 0;
            done <= 0;
			start <= 0;
			state <= WAIT_FOR_GO;
        end
        else
        begin 
            
                done <= 0;
                case ( state ) 
                WAIT_FOR_GO : 
                begin
                    i <= 10;
                    R1 <= X;
                    R0 <= 1;
                    sub <= N;
                    if ( go ) 
                    begin
                        state <= S_READ;
                    end
                    else
                    begin 
                        state <= WAIT_FOR_GO;
                    end
                end
                S_READ:
                begin
                    condition0 <= 1'b0;
                    condition1 <= 1'b0;
                    if ( i >= 0 ) 
                    begin
                        if ( E[i] == 1'b0 ) 
                        begin
                            state <= S_ZERO_R1;
                        end
                        else
                        begin 
                            state <= S_ONE_R0;
                        end
                    end
                    else
                    begin 
                        state <= S_DONE;
                    end
                end
				
                S_ZERO_R1:
				
                begin
				
					X_data_temp <= R1;
					Y_data_temp <= R0;
					start <= 1;
					
					if ( ready_mult == 1)
					begin
						R1 <= out_mult[(width - 1) : 0];
						state <= S_ZERO_R0;
						start <= 0;
					end
				end
				
                S_ZERO_R0:
				
                begin
				
					X_data_temp <= R0;
					Y_data_temp <= R0;
					start <= 1;
					
					if ( ready_mult == 1)
					begin
						R0 <= out_mult[(width - 1) : 0];
						state <= S_MOD;
						start <= 0;
					end
				end
								
				
				
 //                   R1 <= R1*R0;
 //                  R0 <= R0*R0;
 //                  state <= S_MOD;
 //             end
 
                S_ONE_R0:
                begin
				
					X_data_temp <= R1;
					Y_data_temp <= R0;
					start <= 1;
					
					if ( ready_mult == 1)
					begin
						R0 <= out_mult[(width - 1) : 0];
						state <= S_ONE_R1;
						start <= 0;
					end
				end
				
                S_ONE_R1:
                begin
				
					X_data_temp <= R1;
					Y_data_temp <= R1;
					start <= 1;
					
					if ( ready_mult == 1)
					begin
						R1 <= out_mult[(width - 1) : 0];
						state <= S_MOD;
						start <= 0;
					end
				end
								
				
//                    R0 <= R0*R1;
//                    R1 <= R1*R1;
//                    state <= S_MOD;
//                end

                S_MOD:
                begin
                    if ( R0 > sub ) 
                    begin
                        R0 <= ( R0 - sub );
                    end
                    else
                    begin 
                        R0 <= R0;
                        condition0 <= 1'b1;
                    end
                    if ( R1 > sub ) 
                    begin
                        R1 <= ( R1 - sub );
                    end
                    else
                    begin 
                        R1 <= R1;
                        condition1 <= 1'b1;
                    end
                    if ( ( condition1 == 1'b1 ) & ( condition0 == 1'b1 ) ) 
                    begin
                        i <= ( i - 1 );
                        state <= S_READ;
                    end
                    else
                    begin 
                        state <= S_MOD;
                    end
                end
                S_DONE:
                begin
                    O <= R0;
                    done <= 1'b1;
                    if ( go == 1'b0 ) 
                    begin
                        state <= WAIT_FOR_GO;
                    end
                    else
                    begin 
                        state <= S_DONE;
                    end
                end
                default :
                begin
				state <= WAIT_FOR_GO;
				
                end
                endcase
            end
        end
    
endmodule 
