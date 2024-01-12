
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: Md Sami Ul Islam
// 
// Create Date: 08/22/2021 12:54:56 AM
// Design Name: 
// Module Name: parameter_poca
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

parameter address_bus_size = 32;
parameter data_bus_size = 32;
parameter total_number_byte_size = 8;
parameter enable_data_out_size = 32;
parameter ecc_mult_input_size = 32;
parameter ECC_input_size = 128;
parameter test_response_size = 32;
parameter KS_value_size = 4;
parameter P_value_size = 4;
parameter capture_count_size = 16;
//parameter output_response_size = 1024;
parameter TRNG_output_size = 128;
parameter Private_key_chip_size = 128;
parameter hash_output_size = 256;
parameter ecc_output_size = 256;
parameter TRNG_write_base_addr = 32'h60000000;
parameter TRNG_read_base_addr = 32'h60000000;
parameter ECC_write_base_addr = 32'h46000000;
parameter ECC_read_base_addr = 32'h46000000;
parameter Hash_write_base_addr = 32'h43000000;
parameter Hash_read_base_addr = 32'h43000000;
