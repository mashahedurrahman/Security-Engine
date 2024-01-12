
`timescale 1 ns / 1 ps

	module POCA_v1_0 #
	(
		// Users to add parameters here
        parameter address_bus_size = 32,
        parameter data_bus_size = 32,
        parameter total_number_byte_size = 8,
        parameter enable_data_out_size = 32,
        parameter ecc_mult_input_size = 32,
        parameter ECC_input_size = 128,
        parameter test_response_size = 32,
        parameter KS_value_size = 4,
        parameter P_value_size = 4,
        parameter capture_count_size = 16,
        //parameter output_response_size = 1024;
        parameter TRNG_output_size = 128,
        parameter Private_key_chip_size = 128,
        parameter hash_output_size = 256,
        parameter ecc_output_size = 256,
        //parameter TRNG_reset_base_addr = 32'h40004004;
        parameter BRAM_base_addr = 32'h40000000,
        parameter TRNG_write_base_addr = 32'h40004000,
        parameter TRNG_read_base_addr = 32'h40004010,
        parameter ECC_write_base_addr = 32'h40002000,     //base address of Diffe-Hellman
        parameter ECC_read_base_addr = 32'h40002060,
        parameter Hash_write_base_addr = 32'h40003000,    // base address of SHA
        parameter Hash_read_base_addr = 32'h40003090,
        parameter GPIO_base_addr = 32'h41200000,
		// User parameters ends
		// Do not modify the parameters beyond this line


		// Parameters of Axi Master Bus Interface POCA_master
		parameter  C_POCA_master_START_DATA_VALUE	= 32'hAA000000,
		//parameter  C_POCA_master_TARGET_SLAVE_BASE_ADDR	= 32'h40000000,
		parameter integer C_POCA_master_ADDR_WIDTH	= 32,
		parameter integer C_POCA_master_DATA_WIDTH	= 32
		//parameter integer C_POCA_master_TRANSACTIONS_NUM	= 4
	)
	(
		// Users to add ports here

		// User ports ends
		// Do not modify the ports beyond this line


		// Ports of Axi Master Bus Interface POCA_master
		input wire  poca_master_init_axi_txn,
		output wire  poca_master_error,
		output wire  poca_master_txn_done,
		input wire  poca_master_aclk,
		input wire  poca_master_aresetn,
		output wire [C_POCA_master_ADDR_WIDTH-1 : 0] poca_master_awaddr,
		output wire [2 : 0] poca_master_awprot,
		output wire  poca_master_awvalid,
		input wire  poca_master_awready,
		output wire [C_POCA_master_DATA_WIDTH-1 : 0] poca_master_wdata,
		output wire [C_POCA_master_DATA_WIDTH/8-1 : 0] poca_master_wstrb,
		output wire  poca_master_wvalid,
		input wire  poca_master_wready,
		input wire [1 : 0] poca_master_bresp,
		input wire  poca_master_bvalid,
		output wire  poca_master_bready,
		output wire [C_POCA_master_ADDR_WIDTH-1 : 0] poca_master_araddr,
		output wire [2 : 0] poca_master_arprot,
		output wire  poca_master_arvalid,
		input wire  poca_master_arready,
		input wire [C_POCA_master_DATA_WIDTH-1 : 0] poca_master_rdata,
		input wire [1 : 0] poca_master_rresp,
		input wire  poca_master_rvalid,
		output wire  poca_master_rready
	);
// Instantiation of Axi Bus Interface POCA_master
	POCA_v1_0_POCA_master # ( 
	    .address_bus_size(address_bus_size),
        .data_bus_size(data_bus_size),
        .total_number_byte_size(total_number_byte_size),
        .enable_data_out_size(enable_data_out_size),
        .ecc_mult_input_size(ecc_mult_input_size),
        .ECC_input_size(ECC_input_size),
        .test_response_size(test_response_size),
        .KS_value_size(KS_value_size),
        .P_value_size(P_value_size),
        .capture_count_size(capture_count_size),
        //parameter output_response_size = 1024;
        .TRNG_output_size(TRNG_output_size),
        .Private_key_chip_size(Private_key_chip_size),
        .hash_output_size(hash_output_size),
        .ecc_output_size(ecc_output_size),
        //parameter TRNG_reset_base_addr = 32'h40004004;
        .BRAM_base_addr(BRAM_base_addr),
        .TRNG_write_base_addr(TRNG_write_base_addr),
        .TRNG_read_base_addr(TRNG_read_base_addr),
        .ECC_write_base_addr(ECC_write_base_addr),     //base address of Diffe-Hellman
        .ECC_read_base_addr(ECC_read_base_addr),
        .Hash_write_base_addr(Hash_write_base_addr),    // base address of SHA
        .Hash_read_base_addr(Hash_read_base_addr),
        .GPIO_base_addr(GPIO_base_addr),
		.C_M_START_DATA_VALUE(C_POCA_master_START_DATA_VALUE),
		//.C_M_TARGET_SLAVE_BASE_ADDR(C_POCA_master_TARGET_SLAVE_BASE_ADDR),
		.C_M_AXI_ADDR_WIDTH(C_POCA_master_ADDR_WIDTH),
		.C_M_AXI_DATA_WIDTH(C_POCA_master_DATA_WIDTH)
		//.C_M_TRANSACTIONS_NUM(C_POCA_master_TRANSACTIONS_NUM)
	) POCA_v1_0_POCA_master_inst (
		.INIT_AXI_TXN(poca_master_init_axi_txn),
		.ERROR(poca_master_error),
		.TXN_DONE(poca_master_txn_done),
		.M_AXI_ACLK(poca_master_aclk),
		.M_AXI_ARESETN(poca_master_aresetn),
		.M_AXI_AWADDR(poca_master_awaddr),
		.M_AXI_AWPROT(poca_master_awprot),
		.M_AXI_AWVALID(poca_master_awvalid),
		.M_AXI_AWREADY(poca_master_awready),
		.M_AXI_WDATA(poca_master_wdata),
		.M_AXI_WSTRB(poca_master_wstrb),
		.M_AXI_WVALID(poca_master_wvalid),
		.M_AXI_WREADY(poca_master_wready),
		.M_AXI_BRESP(poca_master_bresp),
		.M_AXI_BVALID(poca_master_bvalid),
		.M_AXI_BREADY(poca_master_bready),
		.M_AXI_ARADDR(poca_master_araddr),
		.M_AXI_ARPROT(poca_master_arprot),
		.M_AXI_ARVALID(poca_master_arvalid),
		.M_AXI_ARREADY(poca_master_arready),
		.M_AXI_RDATA(poca_master_rdata),
		.M_AXI_RRESP(poca_master_rresp),
		.M_AXI_RVALID(poca_master_rvalid),
		.M_AXI_RREADY(poca_master_rready)
	);

	// Add user logic here

	// User logic ends

	endmodule
