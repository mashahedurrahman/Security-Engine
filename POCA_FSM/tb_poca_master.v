`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: Md Sami Ul Islam
// 
// Create Date: 09/11/2021 04:47:50 PM
// Design Name: 
// Module Name: tb_poca_master
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



module tb_poca_master();
`include "parameter_poca.v"


    reg [ecc_mult_input_size-1:0] generator_mult;
    reg [test_response_size-1:0] test_response;
    reg clk, go, rstn;
    reg [KS_value_size-1:0] KS_value;
    reg write_complete;
    reg [data_bus_size-1:0] data_in;
    reg data_input_ready;
    reg hsm_key_received;
    reg [ecc_output_size-1:0] hsm_public_key;
    reg input_data_transfer_complete;
   //output ports 
    wire capture_cntl;
    wire [hash_output_size+hash_output_size+ecc_output_size-1:0] poca_output_response;
    wire [address_bus_size-1:0] addr_out;
    wire is_write;
//    output reg [total_number_byte_size-1:0] total_number_byte;
    wire [enable_data_out_size-1:0] enable_data_out;
    wire [ECC_input_size-1:0] ecc_input_1, ecc_input_2;
    wire [test_response_size-1:0] hash_input_r;
    wire [ecc_mult_input_size+P_value_size+ecc_output_size+test_response_size-1:0] hash_input_g_p_qa_r;
    wire shared_secret_key_ready;
    wire poca_output_ready;
    
always #10 clk = !clk;

poca_master UUT (
    .generator_mult(generator_mult),
    .test_response(test_response),
    .clk(clk),
    .go(go),
    .rstn(rstn),
    .KS_value(KS_value),
    .write_complete(write_complete),
    .data_in(data_in),
    .data_input_ready(data_input_ready),
    .hsm_key_received(hsm_key_received),
    .hsm_public_key(hsm_public_key),
    .capture_cntl(capture_cntl),
    .poca_output_response(poca_output_response),
    .addr_out(addr_out),
    .is_write(is_write),
    .enable_data_out(enable_data_out),
    .ecc_input_1(ecc_input_1),
    .ecc_input_2(ecc_input_2),
    .hash_input_r(hash_input_r),
    .hash_input_g_p_qa_r(hash_input_g_p_qa_r),
    .shared_secret_key_ready(shared_secret_key_ready),
    .input_data_transfer_complete(input_data_transfer_complete),
    .poca_output_ready(poca_output_ready)
);


initial begin
clk = 1;
rstn = 0;
go = 0;
input_data_transfer_complete = 0;
data_input_ready = 0;
hsm_key_received = 0;
write_complete = 0;
hsm_public_key = 0;
data_in = 0;
generator_mult = 'h12345678;
KS_value = 'h5;
test_response = 'h12345678;
#40;
rstn = 1;
#40;

// state = IDLE
go = 1;
#100;

// state = TRNG_write
write_complete = 1;
#20;
write_complete = 0;
#100;

//TRNG for private key of the chip
// state = TRNG_read
data_input_ready = 1;
data_in = 32'b00000000000000000000000000010101;
#20;
data_in = 32'b00000000000000000000000000000000;
#20;
data_in = 32'b00000000000000000000000000010101;
#20;
data_in = 32'b00000000000000000000000000000001;
#20;
input_data_transfer_complete = 1;
data_input_ready = 0;
#20;
input_data_transfer_complete = 0;
#80;

// state = ECC_write
write_complete = 1;
#20;
write_complete = 0;
#100;

// state = TRNG_write_p
write_complete = 1;
#20;
write_complete = 0;
#100;

//TRNG for P value
// state = TRNG_read_p
data_input_ready = 1;
data_in = 32'b00000000000000000000000000010101;
#20;
data_in = 32'b00000000000000000000000000000000;
#20;
data_in = 32'b00000000000000000000000000010101;
#20;
data_in = 32'b00000000000000000000000000000001;
#20;
data_input_ready = 0;
input_data_transfer_complete = 1;
#20;
input_data_transfer_complete = 0;
#2340

#100;
// state = Hash_write
write_complete = 1; 
#20;
write_complete = 0;
#100;

//Hash of R 
// state = Hash_read
data_input_ready = 1;
data_in = 32'b00000000000000000000000000011111;
#20;
data_in = 32'b00000000000000000000000000000001;
#20;
data_in = 32'b00000000000000000000000000010101;
#20;
data_in = 32'b00000000000000000000000000000101;
#20;
data_in = 32'b00000000000000000000000000000101;
#20;
data_in = 32'b00000000000000000000000000000101;
#20;
data_in = 32'b00000000000000000000000000000101;
#20;
data_in = 32'b00000000000000000000000000000101;
#20;
data_input_ready = 0;
input_data_transfer_complete = 1;
#20;
input_data_transfer_complete = 0;


//ECC read
// state = ECC_read
#100; 
data_input_ready = 1;
data_in = 32'b00000000000000000000000000011111;
#20;
data_in = 32'b00000000000000000000000000000001;
#20;
data_in = 32'b00000000000000000000000000010101;
#20;
data_in = 32'b00000000000000000000000000000101;
#20;
data_in = 32'b00000000000000000000000000000101;
#20;
data_in = 32'b00000000000000000000000000000101;
#20;
data_in = 32'b00000000000000000000000000000101;
#20;
data_in = 32'b00000000000000000000000000000111;
#20;
data_input_ready = 0;
input_data_transfer_complete = 1;
#20;
input_data_transfer_complete = 0;


#100;
// state = Hash_write_1
write_complete = 1; 
#20;
write_complete = 0;
#100;

//Hash of combined data
// state = Hash_read_1 
data_input_ready = 1;
data_in = 32'b00000000000000000000000000011111;
#20;
data_in = 32'b00000000000000000000000000000001;
#20;
data_in = 32'b00000000000000001000000000010101;
#20;
data_in = 32'b00000000000000000000000000000101;
#20;
data_in = 32'b00000000000000000000000000000101;
#20;
data_in = 32'b00000000000001000000000000000101;
#20;
data_in = 32'b00000000000000000000000000000101;
#20;
data_in = 32'b00000000000000000000000001000101;
#20;
data_input_ready = 0;
input_data_transfer_complete = 1;
#20;
input_data_transfer_complete = 0;

//HSM public key
// state = Output_poca
#300;
hsm_key_received = 1;
hsm_public_key = 'h12345678;

//ECC write Hsm public key
// state = ECC_write_secret_key
#100;
write_complete = 1; 
#20;
write_complete = 0;
#100;

//ECC read
// state = ECC_read_secret_key
data_input_ready = 1;
data_in = 32'b00000000000000000001000000011111;
#20;
data_in = 32'b00000000000000000000000000000001;
#20;
data_in = 32'b00000000000000000000000000010101;
#20;
data_in = 32'b00000000000000000000000010000101;
#20;
data_in = 32'b00000000000000000001000000000101;
#20;
data_in = 32'b00000000000000000000000000000101;
#20;
data_in = 32'b00000000000000000100000000000101;
#20;
data_in = 32'b00000000000000000000000100000111;
#20;
data_input_ready = 0;
input_data_transfer_complete = 1;
#20;
input_data_transfer_complete = 0;
#100;
$finish;
end

initial begin
  $dumpfile("dump.vcd");
  $dumpvars;
end

endmodule
