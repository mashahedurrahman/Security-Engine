
//`timescale 1 ns / 1 ps

	module POCA_v1_0_POCA_master #
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
        parameter TRNG_output_size = 128,
        parameter Private_key_chip_size = 128,
        parameter hash_output_size = 256,
        parameter ecc_output_size = 256,
        parameter DRAM_base_addr = 32'hB2000000,
        parameter TRNG_base_addr = 32'h60000000,
        parameter DH_base_addr = 32'h46000000,     //base address of Diffe-Hellman
        parameter HASH_base_addr = 32'h43000000,    // base address of SHA
        parameter GPIO_base_addr = 32'h41200000,
	parameter  C_M_START_DATA_VALUE	= 32'hAA000000,
	parameter integer C_M_AXI_ADDR_WIDTH	= 32,
	parameter integer C_M_AXI_DATA_WIDTH	= 32
	)
	(
		input wire  M_AXI_ACLK,
		input wire  M_AXI_ARESETN,
		output wire [C_M_AXI_ADDR_WIDTH-1 : 0] M_AXI_AWADDR,
                output wire [3:0] M_AXI_AWID,
                output wire [7:0] M_AXI_AWLEN,
                output wire [2:0] M_AXI_AWSIZE,
		output wire [2 : 0] M_AXI_AWPROT,
		output wire  M_AXI_AWVALID,
		input wire  M_AXI_AWREADY,
		output wire [C_M_AXI_DATA_WIDTH-1 : 0] M_AXI_WDATA,
		output wire [C_M_AXI_DATA_WIDTH/8-1 : 0] M_AXI_WSTRB,
		output wire  M_AXI_WVALID,
		output wire  M_AXI_WLAST,
		input wire  M_AXI_WREADY,
		input wire [1 : 0] M_AXI_BRESP,
		input wire  M_AXI_BVALID,
		output wire  M_AXI_BREADY,
		output wire [C_M_AXI_ADDR_WIDTH-1 : 0] M_AXI_ARADDR,
                output wire [3:0] M_AXI_ARID,
                output wire [7:0] M_AXI_ARLEN,
                output wire [2:0] M_AXI_ARSIZE,
		output wire [2 : 0] M_AXI_ARPROT,
		output wire  M_AXI_ARVALID,
		input wire  M_AXI_ARREADY,
		input wire [C_M_AXI_DATA_WIDTH-1 : 0] M_AXI_RDATA,
		input wire [1 : 0] M_AXI_RRESP,
		input wire  M_AXI_RVALID,
		output wire  M_AXI_RREADY
	);

    integer C_M_TRANSACTIONS_NUM;
	parameter [4:0] IDLE = 5'b00000, 
	INIT_GEN_MULT_READ   = 5'b00001, 
	INIT_TEST_RES_READ   = 5'b00010, 
	INIT_KS_READ   = 5'b00011, 
	INIT_HSM_PUBLIC_KEY_READ   = 5'b00100, 
	INIT_WRITE   = 5'b00101, 
	INIT_READ = 5'b00110, 
	INIT_WAIT = 5'b00111,
        INIT_POCA_RES_WRITE = 5'b01000,
        
        INIT_DONE = 5'b01001,
       
        WAIT_ONE_CYCLE = 5'b01010,

        TRNG_WRITE = 5'b01011,

        TRNG_WRITE_1_0 = 5'b01100,

        WAIT_FOR_DONE = 5'b01101,

        READ_OUTPUT = 5'b01110,

        SEND_TO_POCA = 5'b01111,

        DH_WRITE = 5'b10000,

        WAIT_STATE = 5'b10001,

        WAIT_FOR_CAPTURE = 5'b10010,

        HASH_WRITE = 5'b10011,

        WAIT_FOR_START = 5'b10100;
 
	 reg [4:0] mst_exec_state;

	reg  	axi_awvalid;
        reg [2:0] axi_awsize;
	reg  	axi_wvalid;
	reg  	axi_wlast;
	reg  	axi_arvalid;
        reg [2:0] axi_arsize;
	reg  	axi_rready;
	reg  	axi_bready;
	reg [C_M_AXI_ADDR_WIDTH-1 : 0] 	axi_awaddr;
	reg [C_M_AXI_DATA_WIDTH-1 : 0] 	axi_wdata;
	reg [C_M_AXI_ADDR_WIDTH-1 : 0] 	axi_araddr, axi_araddr_temp;
	wire  	write_resp_error;
	wire  	read_resp_error;
	reg  	start_single_write;
	reg  	start_single_read;
	reg  	write_issued;
	reg  	read_issued;
	reg  	writes_done;
	reg  	reads_done;
	reg [7 : 0] 	write_index;   
	reg [7 : 0] 	read_index;
	reg  	last_write;
	reg  	last_read;
	reg  	init_txn_pulse;
	reg [ecc_mult_input_size-1:0] generator_mult;
	reg [test_response_size-1:0] test_response;
	reg go;
	reg [KS_value_size-1:0] KS_value;
	reg write_complete;
	reg [data_bus_size-1:0] data_in;
	reg data_input_ready;
    reg hsm_key_received;
    reg [ecc_output_size-1:0] hsm_public_key;
    reg input_data_transfer_complete;
    
    wire capture_cntl;
    wire [hash_output_size+hash_output_size+ecc_output_size-1:0] poca_output_response;
    reg [hash_output_size+hash_output_size+ecc_output_size-1:0] poca_output_response_reg;
    wire [address_bus_size-1:0] addr_out;
    reg [address_bus_size-1:0] addr_out_reg;
    wire is_write;
    wire [enable_data_out_size-1:0] enable_data_out;
    reg [enable_data_out_size-1:0] enable_data_out_reg;
    wire [ECC_input_size-1:0] ecc_input_1;
    reg [ECC_input_size-1:0] ecc_input_1_reg;
    wire [ECC_input_size-1:0] ecc_input_2;
    reg [ECC_input_size-1:0] ecc_input_2_reg;
    wire [test_response_size-1:0] hash_input_r;
    reg [1023:0] hash_input_r_reg;
    wire [ecc_mult_input_size+P_value_size+ecc_output_size+test_response_size-1:0] hash_input_g_p_qa_r;
    wire shared_secret_key_ready;
    wire poca_output_ready;
    wire test_response_ready; 

    reg  INIT_AXI_TXN;
    // TRNG signals
    reg [1:0] TRNG_Op_Type;
    reg [31:0] TRNG_SRAM_val0;
    reg [1:0] TRNG_write_steps;
    reg TRNG_write_access;

    // HASH signals
    reg [1:0] HASH_write_steps;
    reg HASH_write_access;

    // DH signals
    reg [1:0] DH_write_steps;

    reg [127:0] TRNG_output;
    reg [511:0] HASH_output;
    reg [287:0] DH_output;
    reg [7:0] word_count;
    reg [7:0] wait_count;

    reg [address_bus_size-1:0] slave_base_address;
    wire [7:0] write_addr_index;
    reg slave_IP_done;

    // I/O Connections assignments
    assign M_AXI_AWADDR	= slave_base_address + axi_awaddr;
    assign M_AXI_AWID   = 0;
    assign M_AXI_AWLEN   = 0;
    assign M_AXI_AWSIZE   = axi_awsize;
    assign M_AXI_WDATA	= axi_wdata;
    assign M_AXI_WLAST	= axi_wlast;
    assign M_AXI_AWPROT	= 3'b000;
    assign M_AXI_AWVALID	= axi_awvalid;
    assign M_AXI_WVALID	= axi_wvalid;
    assign M_AXI_WSTRB	= 4'b1111;
    assign M_AXI_BREADY	= axi_bready;
    assign M_AXI_ARADDR	= slave_base_address + axi_araddr;
    assign M_AXI_ARID   = 0;
    assign M_AXI_ARLEN   = 0;
    assign M_AXI_ARSIZE   = axi_arsize;
    assign M_AXI_ARVALID	= axi_arvalid;
    assign M_AXI_ARPROT	= 3'b001;
    assign M_AXI_RREADY	= axi_rready;
    assign write_addr_index = M_AXI_AWADDR[7:0];


    //POCA FSM instantiation
    poca_master U0_poca_master(
        .generator_mult(generator_mult),
        .test_response(test_response),
        .clk(M_AXI_ACLK), 
        .go(go), 
        .rstn(M_AXI_ARESETN),
        .KS_value(KS_value),
        .write_complete(write_complete),
        .data_in(data_in),     
        .data_input_ready(data_input_ready),
        .hsm_key_received(hsm_key_received),
        .hsm_public_key(hsm_public_key),
        .input_data_transfer_complete(input_data_transfer_complete),
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
        .poca_output_ready(poca_output_ready),
        .test_response_ready(test_response_ready)
    );



    //Saving the output data of POCA to corresponding registers
	always @(posedge M_AXI_ACLK)										      
	  begin                                                                           
	    if (M_AXI_ARESETN == 0 )                                                   
	      begin                                                                    
	        poca_output_response_reg <= 0;                                                   
	        addr_out_reg <= 0; 
	        enable_data_out_reg <= 0;    
	        ecc_input_1_reg <= 0;  
	        ecc_input_2_reg <= 0;   
	        hash_input_r_reg <= 0;   
	        //hash_input_g_p_qa_r_reg <= 0;                                       
	      end                                                                               
	    else                                                                       
	      begin  
	        poca_output_response_reg <= poca_output_response;
	        addr_out_reg <= addr_out;    
	        enable_data_out_reg <= enable_data_out; 
	        ecc_input_1_reg <= ecc_input_1;
	        ecc_input_2_reg <= ecc_input_2;  
	        if(HASH_write_access == 0) begin
                   hash_input_r_reg  <= {992'b0, hash_input_r};
	        end
	        else begin 
	           hash_input_r_reg <=  {700'b0, hash_input_g_p_qa_r};
                end
	      end                                                                      
	  end     

	//--------------------
	//Write Address Channel
	//--------------------
	  always @(posedge M_AXI_ACLK)										      
	  begin                                                                        
	    if (M_AXI_ARESETN == 0 || init_txn_pulse == 1'b1)                                                   
	      begin                                                                    
	        axi_awvalid <= 1'b0;                                                   
	        axi_awsize <= 3'b0;                                                       
	      end                                                                      
	    else                                                                       
	      begin                                                                    
	        if (start_single_write)                                                
	          begin                                                                
	            axi_awvalid <= 1'b1;                                               
	            axi_awsize <= 3'b10;                                                       
	          end                                                                  
	        else if (M_AXI_AWREADY && axi_awvalid)                                 
	          begin                                                                
	            axi_awvalid <= 1'b0;                                               
	            axi_awsize <= 3'b0;                                                       
	          end                                                                  
	      end                                                                      
	  end                                                                          
	                                                                               
	                                                                               
	  always @(posedge M_AXI_ACLK)                                                 
	  begin                                                                        
	    if (M_AXI_ARESETN == 0 || init_txn_pulse == 1'b1)                                                   
	      begin                                                                    
	        write_index <= 0;                                                      
	      end                                                                      
	    else if (start_single_write)                                               
	      begin                                                                    
	        write_index <= write_index + 1;                                        
	      end                                                                      
	  end                                                                          


	//--------------------
	//Write Data Channel
	//--------------------
	   always @(posedge M_AXI_ACLK)                                        
	   begin                                                                         
	     if (M_AXI_ARESETN == 0  || init_txn_pulse == 1'b1)                                                    
	       begin                                                                     
	         axi_wvalid <= 1'b0;                                                     
	         axi_wlast <= 1'b0;                                                   
	       end                                                                       
	     //else if (start_single_write)      // mash                                          
	     else if (M_AXI_AWREADY && axi_awvalid)                                                
	       begin                                                                     
	         axi_wvalid <= 1'b1;                                                     
	         axi_wlast <= 1'b1;                                                   
	       end                                                                       
	     else if (M_AXI_WREADY && axi_wvalid)                                        
	       begin                                                                     
	        axi_wvalid <= 1'b0;                                                      
	        axi_wlast <= 1'b0;                                                   
	       end                                                                       
	   end                                                                           


	//----------------------------
	//Write Response (B) Channel
	//----------------------------
	  always @(posedge M_AXI_ACLK)                                    
	  begin                                                                
	    if (M_AXI_ARESETN == 0 || init_txn_pulse == 1'b1)                                           
	      begin                                                            
	        axi_bready <= 1'b0;                                            
	      end                                                              
	    else if (M_AXI_BVALID && ~axi_bready)                              
	      begin                                                            
	        axi_bready <= 1'b1;                                            
	      end                                                              
	    else if (axi_bready)                                               
	      begin                                                            
	        axi_bready <= 1'b0;                                            
	      end                                                              
	    else                                                               
	      axi_bready <= axi_bready;                                        
	  end                                                                  
	                                                                       
	assign write_resp_error = (axi_bready & M_AXI_BVALID & M_AXI_BRESP[1]);


	//----------------------------
	//Read Address Channel
	//----------------------------
	  always @(posedge M_AXI_ACLK)                                                     
	  begin                                                                            
	    if (M_AXI_ARESETN == 0 || init_txn_pulse == 1'b1)                                                       
	      begin                                                                        
	        read_index <= 0;                                                           
	      end                                                                          
	    else if (start_single_read)                                                    
	      begin                                                                        
	        read_index <= read_index + 1;                                              
	      end                                                                          
	  end                                                                              
	                                                                                   
	  always @(posedge M_AXI_ACLK)                                                     
	  begin                                                                            
	    if (M_AXI_ARESETN == 0 || init_txn_pulse == 1'b1)                                                       
	      begin                                                                        
	        axi_arvalid <= 1'b0;                                                       
	        axi_arsize <= 3'b0;                                                       
	      end                                                                          
	    else if (start_single_read)                                                    
	      begin                                                                        
	        axi_arvalid <= 1'b1;                                                       
	        axi_arsize <= 3'b10;                                                       
	      end                                                                          
	    else if (M_AXI_ARREADY && axi_arvalid)                                         
	      begin                                                                        
	        axi_arvalid <= 1'b0;                                                       
	        axi_arsize <= 3'b0;                                                       
	      end                                                                          
	  end                                                                              


	//--------------------------------
	//Read Data (and Response) Channel
	//--------------------------------
	  always @(posedge M_AXI_ACLK)                                    
	  begin                                                                 
	    if (M_AXI_ARESETN == 0 || init_txn_pulse == 1'b1)                                            
	      begin                                                             
	        axi_rready <= 1'b0;                                             
	      end                                                               
	    else if (M_AXI_RVALID && ~axi_rready)                               
	      begin                                                             
	        axi_rready <= 1'b1;                                             
	      end                                                               
	    else if (axi_rready)                                                
	      begin                                                             
	        axi_rready <= 1'b0;                                             
	      end                                                               
	  end                                                                   
	                                                                        
	assign read_resp_error = (axi_rready & M_AXI_RVALID & M_AXI_RRESP[1]);  


	//--------------------------------
	//User Logic
	//--------------------------------

	  //Write Addresses                                        
	  always @(posedge M_AXI_ACLK)                                  
	      begin                                                     
	        if (M_AXI_ARESETN == 0  || init_txn_pulse == 1'b1)                                
	          begin                                                 
	            axi_awaddr <= 0;                                    
	          end                                                   
	        else if (M_AXI_AWREADY && axi_awvalid)                  
	          begin                                                 
	            axi_awaddr <= axi_awaddr + 32'h00000004;            
	                                                                
	          end                                                   
	      end                                                       
	                                                                
	  // Write data generation                                      
	  always @(posedge M_AXI_ACLK)                                  
	      begin                                                     
	        if (M_AXI_ARESETN == 0 || init_txn_pulse == 1'b1 )                                
	          begin                                                 
	            axi_wdata <= 0;               
	          end                                                   
	        else if (start_single_write)                    
	          begin 
	            if(slave_base_address == TRNG_base_addr)  begin
                       if (TRNG_write_steps == 0) begin                                              
	                 case(write_addr_index)
	                  8'h00: axi_wdata <= 0;
                          8'h04: axi_wdata <= TRNG_Op_Type;
                          8'h08: axi_wdata <= TRNG_SRAM_val0;
                          8'h0C: axi_wdata <= 0;
                          8'h10: axi_wdata <= 0;
                          8'h14: axi_wdata <= 0;
                          8'h18: axi_wdata <= 0;
                          8'h1C: axi_wdata <= 0;
                          8'h20: axi_wdata <= 0;
                          8'h24: axi_wdata <= 0;
                          8'h28: axi_wdata <= 0;
                          8'h2C: axi_wdata <= 0;
                          8'h30: axi_wdata <= 0;
                          8'h34: axi_wdata <= 0;
                          8'h38: axi_wdata <= 0;
                          8'h3C: axi_wdata <= 0;
                          8'h40: axi_wdata <= 0;
                          8'h44: axi_wdata <= 0;
	                 endcase
                       end else if (TRNG_write_steps == 1) begin
                         axi_wdata <= 1;   // TRNG go = 1
                       end else if (TRNG_write_steps == 2) begin
                         axi_wdata <= 0;   // TRNG go = 0
                       end
	            end
	            else if(slave_base_address == DH_base_addr)  begin 
                       if (DH_write_steps == 0) begin                                              
	                 case(write_addr_index)
                          8'h00: axi_wdata <= 0;
	                  8'h04: axi_wdata <= ecc_input_1_reg[31:0];
                          8'h08: axi_wdata <= ecc_input_1_reg[63:32];
                          8'h0C: axi_wdata <= ecc_input_1_reg[95:64];
                          8'h10: axi_wdata <= ecc_input_1_reg[127:96];
                          8'h14: axi_wdata <= 0;
                          8'h18: axi_wdata <= 0;
                          8'h1C: axi_wdata <= 0;
                          8'h20: axi_wdata <= 0;
                          8'h24: axi_wdata <= 0;
                          8'h28: axi_wdata <= ecc_input_2_reg[31:0];
                          8'h2C: axi_wdata <= ecc_input_2_reg[63:32];
                          8'h30: axi_wdata <= ecc_input_2_reg[95:64];
                          8'h34: axi_wdata <= ecc_input_2_reg[127:96];
                          8'h38: axi_wdata <= 0;
                          8'h3C: axi_wdata <= 0;
                          8'h40: axi_wdata <= 0;
                          8'h44: axi_wdata <= 0;
                          8'h48: axi_wdata <= 0;
	                 endcase
                       end else if (DH_write_steps == 1) begin
                         axi_wdata <= 1;   // DH go = 1
                       end else if (DH_write_steps == 2) begin
                         axi_wdata <= 0;   // DH go = 0
                       end
	            end
	            else if(slave_base_address == HASH_base_addr)  begin 
                       if (HASH_write_steps == 0) begin                                              
	                 case(write_addr_index)
	                  8'h00: axi_wdata <= 0;
	                  8'h04: axi_wdata <= 0;
                          8'h08: axi_wdata <= hash_input_r_reg[31:0];
                          8'h0C: axi_wdata <= hash_input_r_reg[63:32];
                          8'h10: axi_wdata <= hash_input_r_reg[95:64];
                          8'h14: axi_wdata <= hash_input_r_reg[127:96];
                          8'h18: axi_wdata <= hash_input_r_reg[159:128];
                          8'h1C: axi_wdata <= hash_input_r_reg[191:160];
                          8'h20: axi_wdata <= hash_input_r_reg[223:192];
                          8'h24: axi_wdata <= hash_input_r_reg[255:224];
                          8'h28: axi_wdata <= hash_input_r_reg[287:256];
                          8'h2C: axi_wdata <= hash_input_r_reg[319:288];
                          8'h30: axi_wdata <= hash_input_r_reg[351:320];
                          8'h34: axi_wdata <= hash_input_r_reg[383:352];
                          8'h38: axi_wdata <= hash_input_r_reg[415:384];
                          8'h3C: axi_wdata <= hash_input_r_reg[447:416];
                          8'h40: axi_wdata <= hash_input_r_reg[479:448];
                          8'h44: axi_wdata <= hash_input_r_reg[511:480];
                          8'h48: axi_wdata <= hash_input_r_reg[543:512];
                          8'h4C: axi_wdata <= hash_input_r_reg[575:544];
                          8'h50: axi_wdata <= hash_input_r_reg[607:576];
                          8'h54: axi_wdata <= hash_input_r_reg[639:608];
                          8'h58: axi_wdata <= hash_input_r_reg[671:640];
                          8'h5C: axi_wdata <= hash_input_r_reg[703:672];
                          8'h60: axi_wdata <= hash_input_r_reg[735:704];
                          8'h64: axi_wdata <= hash_input_r_reg[767:736];
                          8'h68: axi_wdata <= hash_input_r_reg[799:768];
                          8'h6C: axi_wdata <= hash_input_r_reg[831:800];
                          8'h70: axi_wdata <= hash_input_r_reg[863:832];
                          8'h74: axi_wdata <= hash_input_r_reg[895:864];
                          8'h78: axi_wdata <= hash_input_r_reg[927:896];
                          8'h7C: axi_wdata <= hash_input_r_reg[959:928];
                          8'h80: axi_wdata <= hash_input_r_reg[991:960];
                          8'h84: axi_wdata <= hash_input_r_reg[1023:992];
	                 endcase
                       end else if (HASH_write_steps == 1) begin
                         axi_wdata <= 1;   // HASH go = 1
                       end else if (HASH_write_steps == 2) begin
                         axi_wdata <= 0;   // HASH go = 0
                       end
	            end
	            else if(slave_base_address == DRAM_base_addr + 32'h00000040)  begin 
	               case(write_addr_index)
                        8'h40: axi_wdata <= poca_output_response_reg[31:0];
	                8'h44: axi_wdata <= poca_output_response_reg[63:32];
                        8'h48: axi_wdata <= poca_output_response_reg[95:64];
                        8'h4C: axi_wdata <= poca_output_response_reg[127:96];
                        8'h50: axi_wdata <= poca_output_response_reg[159:128];
                        8'h54: axi_wdata <= poca_output_response_reg[191:160];
                        8'h58: axi_wdata <= poca_output_response_reg[223:192];
                        8'h5C: axi_wdata <= poca_output_response_reg[255:224];
                        8'h60: axi_wdata <= poca_output_response_reg[287:256];
                        8'h64: axi_wdata <= poca_output_response_reg[319:288];
                        8'h68: axi_wdata <= poca_output_response_reg[351:320];
                        8'h6C: axi_wdata <= poca_output_response_reg[383:352];
                        8'h70: axi_wdata <= poca_output_response_reg[415:384];
                        8'h74: axi_wdata <= poca_output_response_reg[447:416];
                        8'h78: axi_wdata <= poca_output_response_reg[479:448];
                        8'h7C: axi_wdata <= poca_output_response_reg[511:480];
                        8'h80: axi_wdata <= poca_output_response_reg[543:512];
                        8'h84: axi_wdata <= poca_output_response_reg[575:544];
                        8'h88: axi_wdata <= poca_output_response_reg[607:576];
                        8'h8C: axi_wdata <= poca_output_response_reg[639:608];
                        8'h90: axi_wdata <= poca_output_response_reg[671:640];
                        8'h94: axi_wdata <= poca_output_response_reg[703:672];
                        8'h98: axi_wdata <= poca_output_response_reg[735:704];
                        8'h9C: axi_wdata <= poca_output_response_reg[767:736];
	               endcase
	            end
	            else if(slave_base_address == DRAM_base_addr + 32'h00000100) begin
	                axi_wdata <= 32'h00000001;
	            end
	          end                                                   
	        end          	                                       
	                                                                
	  //Read Addresses                                              
	  always @(posedge M_AXI_ACLK)                                  
	      begin                                                     
	        if (M_AXI_ARESETN == 0  || init_txn_pulse == 1'b1)                                
	          begin                                                 
	            axi_araddr <= 0;                                    
	          end                                                   
	        else if (M_AXI_ARREADY && axi_arvalid)                  
	          begin                                                 
	            axi_araddr_temp <= axi_araddr + 32'h00000004;            
	          end              
                else if (M_AXI_RVALID && axi_rready)    
                  begin
                    axi_araddr <= axi_araddr_temp;
                  end                                     
	      end                                                       
	  

          // Read for the done signal                                                       
	  always @(posedge M_AXI_ACLK)                                  
	      begin                                                     
	        if (M_AXI_ARESETN == 0  || init_txn_pulse == 1'b1)                                
	          begin                                                 
	            slave_IP_done <= 0;            
	          end                                                   
	        else if (M_AXI_RVALID && axi_rready)                    
	          begin                                                 
	            if ((M_AXI_ARADDR == TRNG_base_addr+32'h58) ||(M_AXI_ARADDR == DH_base_addr+32'h70) || (M_AXI_ARADDR == HASH_base_addr+32'hD0)) begin
	               slave_IP_done <= M_AXI_RDATA[0:0];
	            end  
	          end                                                   
	      end   
	  
          // Read outputs                                                       
	  always @(posedge M_AXI_ACLK)                                  
	      begin                                                     
	        if (M_AXI_ARESETN == 0)                                
	          begin                                                 
	            TRNG_output <= 0; 
	            HASH_output <= 0; 
	            DH_output <= 0; 
	          end                                                   
	        else if (M_AXI_RVALID && axi_rready)                    
	          begin                                                 
                    case (M_AXI_ARADDR)
                        TRNG_base_addr+32'h48 : TRNG_output[31:0] <= M_AXI_RDATA;
                        TRNG_base_addr+32'h4C : TRNG_output[63:32] <= M_AXI_RDATA;
                        TRNG_base_addr+32'h50 : TRNG_output[95:64] <= M_AXI_RDATA;
                        TRNG_base_addr+32'h54 : TRNG_output[127:96] <= M_AXI_RDATA;

                        HASH_base_addr+32'h88 : HASH_output[31:0] <= M_AXI_RDATA;
                        HASH_base_addr+32'h8C : HASH_output[63:32] <= M_AXI_RDATA;
                        HASH_base_addr+32'h90 : HASH_output[95:64] <= M_AXI_RDATA;
                        HASH_base_addr+32'h94 : HASH_output[127:96] <= M_AXI_RDATA;
                        HASH_base_addr+32'h98 : HASH_output[159:128] <= M_AXI_RDATA;
                        HASH_base_addr+32'h9C : HASH_output[191:160] <= M_AXI_RDATA;
                        HASH_base_addr+32'hA0 : HASH_output[223:192] <= M_AXI_RDATA;
                        HASH_base_addr+32'hA4 : HASH_output[255:224] <= M_AXI_RDATA;
                        HASH_base_addr+32'hA8 : HASH_output[287:256] <= M_AXI_RDATA;
                        HASH_base_addr+32'hAC : HASH_output[319:288] <= M_AXI_RDATA;
                        HASH_base_addr+32'hB0 : HASH_output[351:320] <= M_AXI_RDATA;
                        HASH_base_addr+32'hB4 : HASH_output[383:352] <= M_AXI_RDATA;
                        HASH_base_addr+32'hB8 : HASH_output[415:384] <= M_AXI_RDATA;
                        HASH_base_addr+32'hBC : HASH_output[447:416] <= M_AXI_RDATA;
                        HASH_base_addr+32'hC0 : HASH_output[479:448] <= M_AXI_RDATA;
                        HASH_base_addr+32'hC4 : HASH_output[511:480] <= M_AXI_RDATA;

                        DH_base_addr+32'h4C : DH_output[31:0] <= M_AXI_RDATA;
                        DH_base_addr+32'h50 : DH_output[63:32] <= M_AXI_RDATA;
                        DH_base_addr+32'h54 : DH_output[95:64] <= M_AXI_RDATA;
                        DH_base_addr+32'h58 : DH_output[127:96] <= M_AXI_RDATA;
                        DH_base_addr+32'h5C : DH_output[159:128] <= M_AXI_RDATA;
                        DH_base_addr+32'h60 : DH_output[191:160] <= M_AXI_RDATA;
                        DH_base_addr+32'h64 : DH_output[223:192] <= M_AXI_RDATA;
                        DH_base_addr+32'h68 : DH_output[255:224] <= M_AXI_RDATA;
                        DH_base_addr+32'h6C : DH_output[287:256] <= M_AXI_RDATA;
                    endcase 
	          end                                                   
	      end   
	  
	                                                                
	                                                                
	  always @(posedge M_AXI_ACLK)                                  
	      begin                                                     
	        if (M_AXI_ARESETN == 0)                                
	          begin                                                 
	            INIT_AXI_TXN <= 0;             
	          end                                                   
	        else if (M_AXI_RVALID && axi_rready && (M_AXI_ARADDR == DRAM_base_addr + 32'h00000200))                    
	          begin                                                 
	            INIT_AXI_TXN <= M_AXI_RDATA[0];
	          end                                                   
	      end
	       
	  always @(posedge M_AXI_ACLK)                                  
	      begin                                                     
	        if (M_AXI_ARESETN == 0)                                
	          begin                                                 
	            generator_mult <= 0;             
	          end                                                   
	        else if (M_AXI_RVALID && axi_rready && (M_AXI_ARADDR == DRAM_base_addr))                    
	          begin                                                 
	            generator_mult <= M_AXI_RDATA;
	          end                                                   
	      end
	       
	  always @(posedge M_AXI_ACLK)                                  
	      begin                                                     
	        if (M_AXI_ARESETN == 0)                                
	          begin                                                 
	            test_response <= 0;             
	          end                                                   
	        else if (M_AXI_RVALID && axi_rready && (M_AXI_ARADDR == (DRAM_base_addr + 32'h00000004)))                    
	          begin                                                 
	            test_response <= M_AXI_RDATA;
	          end                                                   
	      end    
	      
	   always @(posedge M_AXI_ACLK)                                  
	      begin                                                     
	        if (M_AXI_ARESETN == 0)                                
	          begin                                                 
	            KS_value <= 0;             
	          end                                                   
	        else if (M_AXI_RVALID && axi_rready && (M_AXI_ARADDR == (DRAM_base_addr + 32'h00000008)))                    
	          begin                                                 
	            KS_value <= M_AXI_RDATA[KS_value_size-1:0];
	          end                                                   
	      end   
	      
	    always @(posedge M_AXI_ACLK)                                  
	      begin                                                     
	        if (M_AXI_ARESETN == 0)                                
	          begin                                                 
	            hsm_public_key <= 0;             
	          end                                                   
	        else if (M_AXI_RVALID && axi_rready && (M_AXI_ARADDR >= (DRAM_base_addr + 32'h00000010)) && (M_AXI_ARADDR <= (DRAM_base_addr + 32'h0000002C)))                    
	          begin                                                 
	            hsm_public_key <= {M_AXI_RDATA, hsm_public_key[ecc_output_size-1:data_bus_size]};
	          end                                                   
	      end                                                                  

          always @(posedge M_AXI_ACLK)   
            begin
              if (M_AXI_ARESETN == 0  || init_txn_pulse == 1'b1)
                init_txn_pulse <= 1'b0;
            end

               
	  //implement master command interface state machine                         
	  always @ ( posedge M_AXI_ACLK)                                                    
	  begin                                                                             
	    if (M_AXI_ARESETN == 1'b0)                                                     
	      begin                                                                         
	        mst_exec_state  <= WAIT_FOR_START;                                            
	        start_single_write <= 1'b0;                                                 
	        write_issued  <= 1'b0;                                                      
	        start_single_read  <= 1'b0;                                                 
	        read_issued   <= 1'b0;                                                      
	        slave_base_address <= 0;   // Added by Sujan 
	        C_M_TRANSACTIONS_NUM <= 0;
	        go <= 0;
	        write_complete <= 0;
                data_in <= 0;

                // TRNG signals
                TRNG_Op_Type <= 0;
                TRNG_SRAM_val0 <= 0;
                TRNG_write_steps <= 0;
                TRNG_write_access <= 0;

                // HASH signals
                HASH_write_steps <= 0;
                HASH_write_access <= 0;

                // DH signals
                DH_write_steps <= 0;

                word_count <= 0;
                wait_count <= 0;
                data_input_ready <= 0;
                input_data_transfer_complete <= 0;
                hsm_key_received <= 0;
	      end                                                                           
	    else                                                                            
	      begin                                                                         
	        case (mst_exec_state)                                                       
	                                                                                    
                  WAIT_FOR_START:
	              if (shared_secret_key_ready == 0) begin   
	                  if (reads_done) begin   
                              if (INIT_AXI_TXN) begin                                                            
                                  init_txn_pulse <= 1;  
                                  if (init_txn_pulse == 1'b1) begin                              
	                            mst_exec_state <= IDLE;  
                                  end
                              end else begin
                                  init_txn_pulse <= 1;  
                                  if (init_txn_pulse == 1'b1) begin                              
	                            mst_exec_state <= WAIT_FOR_START;  
                                  end
                              end
	                  end                                                                  
	                  else begin                                                                
	                      mst_exec_state  <= WAIT_FOR_START;                                      
	                                                                                         
	                      if (~axi_arvalid && ~M_AXI_RVALID && ~last_read && ~start_single_read && ~read_issued)
	                        begin                                                            
	                          start_single_read <= 1'b1;                                     
	                          read_issued  <= 1'b1; 
	                          slave_base_address <= DRAM_base_addr + 32'h200; 
	                          C_M_TRANSACTIONS_NUM <= 1;                                     
	                        end                                                              
	                      else if (axi_rready)                                               
	                        begin                                                            
	                          read_issued  <= 1'b0;                                          
	                        end                                                              
	                      else                                                               
	                        begin                                                            
	                          start_single_read <= 1'b0;         
	                        end                                                              
	                  end 
                      end
                                  
	          IDLE:                                                             
	            if ( INIT_AXI_TXN == 1'b1 )                                     
	              begin                                                                 
                        init_txn_pulse <= 1;  
                        if (init_txn_pulse == 1'b1) begin                              
	                  mst_exec_state  <= INIT_GEN_MULT_READ;                                    
                        end
	              end                                                                   
	            else                                                                    
	              begin                                                                 
	                mst_exec_state  <= IDLE;                                    
	              end                                                                   
	          
	          INIT_GEN_MULT_READ:
	             if (reads_done)                                                        
	               begin                                                                
                         init_txn_pulse <= 1;  
                         if (init_txn_pulse == 1'b1) begin                              
	                   mst_exec_state <= INIT_TEST_RES_READ;   
                         end                                
	               end                                                                  
	             else                                                                   
	               begin                                                                
	                 mst_exec_state  <= INIT_GEN_MULT_READ;                                      
	                                                                                    
	                 if (~axi_arvalid && ~M_AXI_RVALID && ~last_read && ~start_single_read && ~read_issued)
	                   begin                                                            
	                       start_single_read <= 1'b1;                                     
	                       read_issued  <= 1'b1; 
	                       slave_base_address <= DRAM_base_addr; 
	                       C_M_TRANSACTIONS_NUM <= 1;      
	                   end                                                              
	                 else if (axi_rready)                                               
	                   begin                                                            
	                     read_issued  <= 1'b0;                                          
	                   end                                                              
	                 else                                                               
	                   begin                                                            
	                     start_single_read <= 1'b0; 
	                   end                                                              
	               end     
	          
	          INIT_TEST_RES_READ:
	             if (reads_done)                                                        
	               begin                                                                
                         init_txn_pulse <= 1;  
                         if (init_txn_pulse == 1'b1) begin                              
	                   mst_exec_state <= INIT_KS_READ;                                    
                         end
	               end                                                                  
	             else                                                                   
	               begin                                                                
	                 mst_exec_state  <= INIT_TEST_RES_READ;                                      
	                                                                                    
	                 if (~axi_arvalid && ~M_AXI_RVALID && ~last_read && ~start_single_read && ~read_issued)
	                   begin                                                            
	                       start_single_read <= 1'b1;                                     
	                       read_issued  <= 1'b1; 
	                       slave_base_address <= DRAM_base_addr + 32'h00000004; 
	                       C_M_TRANSACTIONS_NUM <= 1;      
	                   end                                                              
	                 else if (axi_rready)                                               
	                   begin                                                            
	                     read_issued  <= 1'b0;                                          
	                   end                                                              
	                 else                                                               
	                   begin                                                            
	                     start_single_read <= 1'b0;         
	                   end                                                              
	               end   
	          
	          INIT_KS_READ:
	             if (reads_done)                                                        
	               begin                                                                
                         init_txn_pulse <= 1;  
                         if (init_txn_pulse == 1'b1) begin                              
	                   go <= 1;
	                   mst_exec_state <= WAIT_ONE_CYCLE;  
                         end
	               end                                                                  
	             else                                                                   
	               begin                                                                
	                 mst_exec_state  <= INIT_KS_READ;                                      
	                                                                                    
	                 if (~axi_arvalid && ~M_AXI_RVALID && ~last_read && ~start_single_read && ~read_issued)
	                   begin                                                            
	                     start_single_read <= 1'b1;                                     
	                     read_issued  <= 1'b1; 
	                     slave_base_address <= DRAM_base_addr + 32'h00000008; 
	                     C_M_TRANSACTIONS_NUM <= 1;                                     
	                   end                                                              
	                 else if (axi_rready)                                               
	                   begin                                                            
	                     read_issued  <= 1'b0;                                          
	                   end                                                              
	                 else                                                               
	                   begin                                                            
	                     start_single_read <= 1'b0;         
	                   end                                                              
	               end 
	          
	          INIT_WRITE:                                                               
	            if(addr_out_reg == TRNG_base_addr) begin
                         if (TRNG_write_access == 0) begin
                             TRNG_Op_Type <= 0;
                             TRNG_SRAM_val0 <= 32'd1452664;
                             mst_exec_state  <= TRNG_WRITE;
                         end else if (TRNG_write_access == 1) begin
                             TRNG_Op_Type <= 2;
                             TRNG_SRAM_val0 <= 32'd323464;
                             mst_exec_state  <= TRNG_WRITE;
                         end
	            end 
	            else if(addr_out_reg == DH_base_addr) begin
                         mst_exec_state  <= DH_WRITE;
	            end  
	            else if(addr_out_reg == HASH_base_addr) begin
                         mst_exec_state  <= HASH_WRITE;
	            end                                  
	          
	          TRNG_WRITE:                                                               
	            if (writes_done)                                                        
	              begin  
                         init_txn_pulse <= 1;  
                         if (init_txn_pulse == 1'b1) begin                              
	                   if(TRNG_write_steps == 0) begin
                             TRNG_write_steps <= 1;
                           end
	                   else if(TRNG_write_steps == 1) begin
                             TRNG_write_steps <= 2;
                           end
	                   else if(TRNG_write_steps == 2) begin
                             TRNG_write_steps <= 0;
                             if (TRNG_write_access == 0) TRNG_write_access <= 1;
	                     write_complete <= 1;                                                               
	                     mst_exec_state <= WAIT_ONE_CYCLE;//     
                           end
                         end                                
	              end                                                                   
	            else                                                                    
	              begin                                                                 
	                mst_exec_state  <= TRNG_WRITE;                                      
	                                                                                    
	                  if (~axi_awvalid && ~axi_wvalid && ~M_AXI_BVALID && ~last_write && ~start_single_write && ~write_issued)
	                    begin                                                           
	                      start_single_write <= 1'b1;                                   
	                      write_issued  <= 1'b1;  
	                      slave_base_address <= TRNG_base_addr;
	                      if(TRNG_write_steps == 0) begin
	                           C_M_TRANSACTIONS_NUM  <= 18;   
	                      end 
	                      else if(TRNG_write_steps == 1) begin
	                           C_M_TRANSACTIONS_NUM  <= 1;    
	                      end  
	                      else if(TRNG_write_steps == 2) begin
	                           C_M_TRANSACTIONS_NUM  <= 1;    
	                      end                                  
	                    end                                                             
	                  else if (axi_bready)                                              
	                    begin                                                           
	                      write_issued  <= 1'b0;                                        
	                    end                                                             
	                  else                                                              
	                    begin                                                           
	                      start_single_write <= 1'b0;       
	                    end                                                             
	              end                                                                   
                                                                          
	          DH_WRITE:                                                               
	            if (writes_done)                                                        
	              begin  
                         init_txn_pulse <= 1;  
                         if (init_txn_pulse == 1'b1) begin                              
	                   if(DH_write_steps == 0) begin
                             DH_write_steps <= 1;
                           end
	                   else if(DH_write_steps == 1) begin
                             DH_write_steps <= 2;
                           end
	                   else if(DH_write_steps == 2) begin
                             DH_write_steps <= 0;
	                     write_complete <= 1;  
                             wait_count <= 0;
	                     mst_exec_state <= WAIT_STATE;//     
                           end
                         end                                
	              end                                                                   
	            else                                                                    
	              begin                                                                 
	                mst_exec_state  <= DH_WRITE;                                      
	                                                                                    
	                  if (~axi_awvalid && ~axi_wvalid && ~M_AXI_BVALID && ~last_write && ~start_single_write && ~write_issued)
	                    begin                                                           
	                      start_single_write <= 1'b1;                                   
	                      write_issued  <= 1'b1;  
	                      slave_base_address <= DH_base_addr;
	                      if(DH_write_steps == 0) begin
	                           C_M_TRANSACTIONS_NUM  <= 19;   
	                      end 
	                      else if(DH_write_steps == 1) begin
	                           C_M_TRANSACTIONS_NUM  <= 1;    
	                      end  
	                      else if(DH_write_steps == 2) begin
	                           C_M_TRANSACTIONS_NUM  <= 1;    
	                      end                                  
	                    end                                                             
	                  else if (axi_bready)                                              
	                    begin                                                           
	                      write_issued  <= 1'b0;                                        
	                    end                                                             
	                  else                                                              
	                    begin                                                           
	                      start_single_write <= 1'b0;       
	                    end                                                             
	              end                                                                   
                                                                          
	          HASH_WRITE:                                                               
	            if (writes_done)                                                        
	              begin  
                         init_txn_pulse <= 1;  
                         if (init_txn_pulse == 1'b1) begin                              
	                   if(HASH_write_steps == 0) begin
                             HASH_write_steps <= 1;
                           end
	                   else if(HASH_write_steps == 1) begin
                             HASH_write_steps <= 2;
                           end
	                   else if(HASH_write_steps == 2) begin
                             HASH_write_steps <= 0;
                             if (HASH_write_access == 0) HASH_write_access <= 1;
	                     write_complete <= 1;                                                               
	                     mst_exec_state <= WAIT_ONE_CYCLE;//     
                           end
                         end                                
	              end                                                                   
	            else                                                                    
	              begin                                                                 
	                mst_exec_state  <= HASH_WRITE;                                      
	                                                                                    
	                  if (~axi_awvalid && ~axi_wvalid && ~M_AXI_BVALID && ~last_write && ~start_single_write && ~write_issued)
	                    begin                                                           
	                      start_single_write <= 1'b1;                                   
	                      write_issued  <= 1'b1;  
	                      slave_base_address <= HASH_base_addr;
	                      if(HASH_write_steps == 0) begin
	                           C_M_TRANSACTIONS_NUM  <= 34;   
	                      end 
	                      else if(HASH_write_steps == 1) begin
	                           C_M_TRANSACTIONS_NUM  <= 1;    
	                      end  
	                      else if(HASH_write_steps == 2) begin
	                           C_M_TRANSACTIONS_NUM  <= 1;    
	                      end                                  
	                    end                                                             
	                  else if (axi_bready)                                              
	                    begin                                                           
	                      write_issued  <= 1'b0;                                        
	                    end                                                             
	                  else                                                              
	                    begin                                                           
	                      start_single_write <= 1'b0;       
	                    end                                                             
	              end                                                                   
                                                                          
	          INIT_READ:
                      begin                                                                
                          mst_exec_state  <= WAIT_FOR_DONE;
	              end    

                  WAIT_FOR_DONE:
	              if (reads_done) begin   
                          if (slave_IP_done) begin                                                            
                              init_txn_pulse <= 1;  
                              if (init_txn_pulse == 1'b1) begin                              
	                        mst_exec_state <= READ_OUTPUT;  
                              end
                          end else begin
                              init_txn_pulse <= 1;  
                              if (init_txn_pulse == 1'b1) begin                              
	                        mst_exec_state <= WAIT_FOR_DONE;  
                              end
                          end
	              end                                                                  
	              else begin                                                                
	                  mst_exec_state  <= WAIT_FOR_DONE;                                      
	                                                                                     
	                  if (~axi_arvalid && ~M_AXI_RVALID && ~last_read && ~start_single_read && ~read_issued)
	                    begin                                                            
                              if(addr_out_reg == TRNG_base_addr) begin
	                        start_single_read <= 1'b1;                                     
	                        read_issued  <= 1'b1; 
	                        slave_base_address <= TRNG_base_addr + 32'h58; 
                              end else if(addr_out_reg == HASH_base_addr) begin
	                        start_single_read <= 1'b1;                                     
	                        read_issued  <= 1'b1; 
	                        slave_base_address <= HASH_base_addr + 32'hD0; 
                              end else if(addr_out_reg == DH_base_addr) begin
	                        start_single_read <= 1'b1;                                     
	                        read_issued  <= 1'b1; 
	                        slave_base_address <= DH_base_addr + 32'h70; 
                              end
	                      C_M_TRANSACTIONS_NUM <= 1;                                     
	                    end                                                              
	                  else if (axi_rready)                                               
	                    begin                                                            
	                      read_issued  <= 1'b0;                                          
	                    end                                                              
	                  else                                                               
	                    begin                                                            
	                      start_single_read <= 1'b0;         
	                    end                                                              
	              end 
                                  
                  READ_OUTPUT:
	             if (reads_done)                                                        
	               begin                                                                
                         init_txn_pulse <= 1;  
                         if (init_txn_pulse == 1'b1) begin                              
	                   mst_exec_state <= SEND_TO_POCA;  
                           word_count <= 1;
                         end
	               end                                                                  
	             else                                                                   
	               begin                                                                
	                 mst_exec_state  <= READ_OUTPUT;                                      
	                                                                                    
	                 if (~axi_arvalid && ~M_AXI_RVALID && ~last_read && ~start_single_read && ~read_issued)
	                   begin                                                            
                             if(addr_out_reg == TRNG_base_addr) begin
	                       start_single_read <= 1'b1;                                     
	                       read_issued  <= 1'b1; 
	                       slave_base_address <= TRNG_base_addr + 32'h48; 
	                       C_M_TRANSACTIONS_NUM <= 4;
                             end else if(addr_out_reg == HASH_base_addr) begin                                    
	                       start_single_read <= 1'b1;                                     
	                       read_issued  <= 1'b1; 
	                       slave_base_address <= HASH_base_addr + 32'h88; 
	                       C_M_TRANSACTIONS_NUM <= 16;
                             end else if(addr_out_reg == DH_base_addr) begin                                    
	                       start_single_read <= 1'b1;                                     
	                       read_issued  <= 1'b1; 
	                       slave_base_address <= DH_base_addr + 32'h4C; 
	                       C_M_TRANSACTIONS_NUM <= 9;
                             end
	                   end                                                              
	                 else if (axi_rready)                                               
	                   begin                                                            
	                     read_issued  <= 1'b0;                                          
	                   end                                                              
	                 else                                                               
	                   begin                                                            
	                     start_single_read <= 1'b0;         
	                   end                                                              
	               end 
                          
                  SEND_TO_POCA:
                       if(addr_out_reg == TRNG_base_addr) begin
                           data_input_ready <= 1'b1;
                           data_in <= TRNG_output[(word_count-1)*32 +: 32];
                           if(word_count == 4) begin
                               input_data_transfer_complete <= 1'b1;
                               wait_count <= 0;
	                       mst_exec_state <= WAIT_STATE;//     
                           end else begin
                               word_count <= word_count+1;
                           end
                       end else if(addr_out_reg == HASH_base_addr) begin
                           data_input_ready <= 1'b1;
                           data_in <= HASH_output[(word_count-1)*32 +: 32];
                           if(word_count == 8) begin
                               input_data_transfer_complete <= 1'b1;
                               wait_count <= 0;
	                       mst_exec_state <= WAIT_STATE;//     
                           end else begin
                               word_count <= word_count+1;
                           end
                       end else if(addr_out_reg == DH_base_addr) begin
                           data_input_ready <= 1'b1;
                           data_in <= DH_output[(word_count-1)*32 +: 32];
                           if(word_count == 8) begin
                               input_data_transfer_complete <= 1'b1;
                               wait_count <= 0;
	                       mst_exec_state <= WAIT_STATE;//     
                           end else begin
                               word_count <= word_count+1;
                           end
                       end 
 
	             
	           WAIT_STATE: 
                     begin
                         if(wait_count == 2) begin
                           mst_exec_state <= INIT_WAIT;
                         end else begin
                           wait_count <= wait_count + 1;
                         end     
                         if(data_input_ready == 1) data_input_ready <= 0;
                         if(input_data_transfer_complete == 1) input_data_transfer_complete <= 0;
                         if(write_complete == 1) write_complete <= 0;
                     end  
                                                     
	           WAIT_ONE_CYCLE: 
                     begin
                         mst_exec_state <= INIT_WAIT;   
                         if(data_input_ready == 1) data_input_ready <= 0;
                         if(input_data_transfer_complete == 1) input_data_transfer_complete <= 0;
                         if(write_complete == 1) write_complete <= 0;
                     end

                   WAIT_FOR_CAPTURE: 
                     begin
                         if(test_response_ready == 1) begin
                           mst_exec_state <= WAIT_ONE_CYCLE;
                         end else begin
                           mst_exec_state <= WAIT_FOR_CAPTURE;
                         end
                     end

	           INIT_WAIT:                                                            
	             begin
	                 if(shared_secret_key_ready == 1) begin
	                   mst_exec_state <= INIT_DONE;
	                 end
	                 else if(poca_output_ready == 1) begin
	                   mst_exec_state <= INIT_POCA_RES_WRITE;
	                 end
	                 else if (capture_cntl == 1) begin    
                           mst_exec_state <= WAIT_FOR_CAPTURE;
	                 end
	                 else if (is_write == 1) begin                                                              
	                   mst_exec_state <= INIT_WRITE;
	                 end
	                 else begin
	                   mst_exec_state <= INIT_READ;                                            
	                 end 
	             end 
	             
	           INIT_POCA_RES_WRITE:
	            if (writes_done)                                                        
	              begin  
                         init_txn_pulse <= 1;  
                         if (init_txn_pulse == 1'b1) begin                              
	                   mst_exec_state <= INIT_HSM_PUBLIC_KEY_READ;//                                      
                         end                                
	              end                                                                   
	            else                                                                    
	              begin                                                                 
	                mst_exec_state  <= INIT_POCA_RES_WRITE;                                      
	                                                                                    
	                  if (~axi_awvalid && ~axi_wvalid && ~M_AXI_BVALID && ~last_write && ~start_single_write && ~write_issued)
	                    begin                                                           
	                      start_single_write <= 1'b1;                                   
	                      write_issued  <= 1'b1;  
	                      slave_base_address <= DRAM_base_addr + 32'h00000040;
	                      C_M_TRANSACTIONS_NUM <= 24;                                  
	                    end                                                             
	                  else if (axi_bready)                                              
	                    begin                                                           
	                      write_issued  <= 1'b0;                                        
	                    end                                                             
	                  else                                                              
	                    begin                                                           
	                      start_single_write <= 1'b0;       
	                    end                                                            
	              end 
	           
	          INIT_HSM_PUBLIC_KEY_READ:
	             if (reads_done)                                                        
	               begin 
                         init_txn_pulse <= 1;  
                         if (init_txn_pulse == 1'b1) begin     
                           hsm_key_received <= 1'b1;
	                   mst_exec_state <= WAIT_ONE_CYCLE;                              
                         end                               
	               end                                                                  
	             else                                                                   
	               begin                                                                
	                 mst_exec_state  <= INIT_HSM_PUBLIC_KEY_READ;                                      
	                                                                                    
	                 if (~axi_arvalid && ~M_AXI_RVALID && ~last_read && ~start_single_read && ~read_issued)
	                   begin                                                            
	                     start_single_read <= 1'b1;                                     
	                     read_issued  <= 1'b1; 
	                     slave_base_address <= DRAM_base_addr + 32'h00000010; 
	                     C_M_TRANSACTIONS_NUM <= 8;                                     
	                   end                                                              
	                 else if (axi_rready)                                               
	                   begin                                                            
	                     read_issued  <= 1'b0;                                          
	                   end                                                              
	                 else                                                               
	                   begin                                                            
	                     start_single_read <= 1'b0;         
	                   end                                                              
	               end 
	                                                                                       
	           INIT_DONE:
	              if (writes_done)                                                        
	               begin  
                         init_txn_pulse <= 1;  
                         if (init_txn_pulse == 1'b1) begin     
	                   mst_exec_state <= WAIT_FOR_START;
                           //go <= 0;
                         end
	               end                                                                   
	              else                                                                    
	              begin                                                                 
	                mst_exec_state  <= INIT_DONE;                                      
	                                                                                    
	                  if (~axi_awvalid && ~axi_wvalid && ~M_AXI_BVALID && ~last_write && ~start_single_write && ~write_issued)
	                    begin                                                           
	                      start_single_write <= 1'b1;                                   
	                      write_issued  <= 1'b1;  
	                      slave_base_address <= DRAM_base_addr + 32'h00000100;
	                      C_M_TRANSACTIONS_NUM <= 1;                                  
	                    end                                                             
	                  else if (axi_bready)                                              
	                    begin                                                           
	                      write_issued  <= 1'b0;                                        
	                    end                                                             
	                  else                                                              
	                    begin                                                           
	                      start_single_write <= 1'b0;       
	                    end                                                            
	              end                                                                              
	           default :                                                                
	             begin                                                                  
	               mst_exec_state  <= WAIT_FOR_START;                                     
	             end                                                                    
	        endcase                                                                     
	    end                                                                             
	  end //MASTER_EXECUTION_PROC                                                       
	                                                                                    
	  //Terminal write count                                                            
	  always @(posedge M_AXI_ACLK)                                                      
	  begin                                                                             
	    if (M_AXI_ARESETN == 0 || init_txn_pulse == 1'b1)                                                         
	      last_write <= 1'b0;                                                           
	    else if ((write_index == C_M_TRANSACTIONS_NUM) && M_AXI_AWREADY)                
	      last_write <= 1'b1;                                                           
	    else                                                                            
	      last_write <= last_write;                                                     
	  end                                                                               
	                                                                                    
	  always @(posedge M_AXI_ACLK)                                                      
	  begin                                                                             
	    if (M_AXI_ARESETN == 0 || init_txn_pulse == 1'b1)                                                         
	      writes_done <= 1'b0;                                                          
	    else if (last_write && M_AXI_BVALID && axi_bready)                              
	      writes_done <= 1'b1;                                                          
	    else                                                                            
	      writes_done <= writes_done;                                                   
	  end                                                                               
	                                                                                    
	//------------------                                                                
	//Read example                                                                      
	//------------------                                                                
	//Terminal Read Count                                                               
	  always @(posedge M_AXI_ACLK)                                                      
	  begin                                                                             
	    if (M_AXI_ARESETN == 0 || init_txn_pulse == 1'b1)                                                         
	      last_read <= 1'b0;                                                            
	    else if ((read_index == C_M_TRANSACTIONS_NUM) && (M_AXI_ARREADY) )              
	      last_read <= 1'b1;                                                            
	    else                                                                            
	      last_read <= last_read;                                                       
	  end                                                                               
	                                                                                    
	  always @(posedge M_AXI_ACLK)                                                      
	  begin                                                                             
	    if (M_AXI_ARESETN == 0 || init_txn_pulse == 1'b1)                                                         
	      reads_done <= 1'b0;                                                           
	    else if (last_read && M_AXI_RVALID && axi_rready)                               
	      reads_done <= 1'b1;                                                           
	    else                                                                            
	      reads_done <= reads_done;                                                     
	    end                                                                             
	                                                                                    
	endmodule
