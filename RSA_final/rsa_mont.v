//`timescale 1ns/1ps


module rsa_mont(
        clk,
        rst,
        go,
   //     function_bits,
		message_in,
    //    decrypted,
        exponent,
        modulus,
        cypher,
        done
    );
	
	parameter [31:0] width  = 2048;
    input clk;
    input rst;
    input go;
  //  input function_bits;
    input [( width - 1 ):0] message_in;
   // input [( width - 1 ):0] decrypted;
    input [( width - 1 ):0] exponent;
    input [( width - 1 ):0] modulus;
    output [( width - 1 ):0] cypher;
    output reg done;
	
    wire encrypt_done;
  //  wire decrypt_done;
    wire done_en;
    wire [( width - 1 ):0] en_cypher;
//    wire [( width - 1 ):0] de_cypher;
 //   wire [( width - 1 ):0] reg_decrypted;
    wire [( width - 1 ):0] reg_exponent;
    wire [( width - 1 ):0] reg_message_in;
    wire [( width - 1 ):0] reg_modulus;
 
    reg [( width - 1 ):0] reg_cypher;
    reg encrypt_go;
  //  reg decrypt_go;
    reg reg_en;
 
    reg [2:0]state;
	
	localparam [1:0] WAIT_FOR_GO = 3'b00, 
                     S_START = 3'b01, 
                     POLL_DONE = 3'b10, 
                     S_DONE = 3'b11;

	
    assign done_en = encrypt_done; //( encrypt_done | decrypt_done );
	
    mont_lad #(
            .width(width)
        ) u_encrypt (
            .clk(clk),
            .go(encrypt_go),
            .rst(rst),
            .done(encrypt_done),
            .E(reg_exponent),
            .N(reg_modulus),
            .O(en_cypher),
            .X(reg_message_in)
        );
  /*  decrypt_mont #(
            .width(width)
        ) u_decrypt (
            .clk(clk),
            .go(decrypt_go),
            .rst(rst),
            .done(decrypt_done),
            .E(reg_exponent),
            .message(reg_decrypted),
            .N(reg_modulus),
            .O(de_cypher),
            .X(reg_message_in)
        );

*/
    always @ ( en_cypher )
    begin

            reg_cypher <= en_cypher;
        end
       

	
	
    always @ (  posedge clk , posedge rst)
    begin
        if ( rst == 1'b1 ) 
        begin
            encrypt_go <= 1'b0;
    //        decrypt_go <= 1'b0;
            reg_en <= 1'b0;
	    state <= WAIT_FOR_GO;
        end
        else
        begin 
     //       if ( clk == 1'b1 ) 
     //       begin
                encrypt_go <= 1'b0;

                reg_en <= 1'b0;
                done <= 1'b0;
                case ( state ) 
                WAIT_FOR_GO:
                begin
                    reg_en <= 1'b1;
                    if ( go == 1'b1 ) 
                    begin
                        state <= S_START;
                    end
                    else
                    begin 
                        state <= WAIT_FOR_GO;
                    end
                end
                S_START:
                begin
                //    if ( function_bits == 1'b0 ) 
                  //  begin
                        encrypt_go <= 1'b1;
                  //  end
                 //   else
                 //   begin 
                 //       if ( function_bits == 1'b1 ) 
                 //       begin
                 //           decrypt_go <= 1'b1;
                  //      end
                  //  end
                    state <= POLL_DONE;
                end
                POLL_DONE:
                begin
                    if (  encrypt_done == 1'b1 ) 
                    begin
                        state <= S_DONE;
                    end
                    else
                    begin 
                        state <= POLL_DONE;
                    end
                end
               S_DONE:
                begin
                    done <= 1'b1;
                    if ( go <= 1'b0 ) 
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
                end
                endcase
     //       end
        end
    end
    reg_module #(
            .width(width)
        ) u_exp_reg (
            .clk(clk),
            .en(reg_en),
            .inp(exponent),
            .rst(rst),
            .outp(reg_exponent)
        );
    reg_module #(
            .width(width)
        ) u_data_reg (
            .clk(clk),
            .en(reg_en),
            .inp(message_in),
            .rst(rst),
            .outp(reg_message_in)
        );
    reg_module #(
            .width(width)
        ) u_mod_reg (
            .clk(clk),
            .en(reg_en),
            .inp(modulus),
            .rst(rst),
            .outp(reg_modulus)
        );
    /*reg_module #(
            .width(width)
        ) u_dec_reg (
            .clk(clk),
            .en(reg_en),
            .inp(decrypted),
            .rst(rst),
            .outp(reg_decrypted)
        ); */
    reg_module #(
            .width(width)
        ) u_output_reg (
            .clk(clk),
            .en(done_en),
            .inp(reg_cypher),
            .rst(rst),
            .outp(cypher)
        );
endmodule 
