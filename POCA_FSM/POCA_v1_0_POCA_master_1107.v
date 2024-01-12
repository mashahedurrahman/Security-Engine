

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

		// The master will start generating data from the C_M_START_DATA_VALUE value
		parameter  C_M_START_DATA_VALUE	= 32'hAA000000,
		// The master requires a target slave base address.
    // The master will initiate read and write transactions on the slave with base address specified here as a parameter.
		//parameter  C_M_TARGET_SLAVE_BASE_ADDR	= 32'h40000000,
		// Width of M_AXI address bus. 
    // The master generates the read and write addresses of width specified as C_M_AXI_ADDR_WIDTH.
		parameter integer C_M_AXI_ADDR_WIDTH	= 32,
		// Width of M_AXI data bus. 
    // The master issues write data and accept read data where the width of the data bus is C_M_AXI_DATA_WIDTH
		parameter integer C_M_AXI_DATA_WIDTH	= 32
		// Transaction number is the number of write 
    // and read transactions the master will perform as a part of this example memory test.
		//parameter integer C_M_TRANSACTIONS_NUM	= 4
	)
	(
		// Users to add ports here

		// User ports ends
		// Do not modify the ports beyond this line

		// Initiate AXI transactions
		input wire  INIT_AXI_TXN,
		// Asserts when ERROR is detected
		output reg  ERROR,
		// Asserts when AXI transactions is complete
		output wire  TXN_DONE,
		// AXI clock signal
		input wire  M_AXI_ACLK,
		// AXI active low reset signal
		input wire  M_AXI_ARESETN,
		// Master Interface Write Address Channel ports. Write address (issued by master)
		output wire [C_M_AXI_ADDR_WIDTH-1 : 0] M_AXI_AWADDR,
		// Write channel Protection type.
    // This signal indicates the privilege and security level of the transaction,
    // and whether the transaction is a data access or an instruction access.
		output wire [2 : 0] M_AXI_AWPROT,
		// Write address valid. 
    // This signal indicates that the master signaling valid write address and control information.
		output wire  M_AXI_AWVALID,
		// Write address ready. 
    // This signal indicates that the slave is ready to accept an address and associated control signals.
		input wire  M_AXI_AWREADY,
		// Master Interface Write Data Channel ports. Write data (issued by master)
		output wire [C_M_AXI_DATA_WIDTH-1 : 0] M_AXI_WDATA,
		// Write strobes. 
    // This signal indicates which byte lanes hold valid data.
    // There is one write strobe bit for each eight bits of the write data bus.
		output wire [C_M_AXI_DATA_WIDTH/8-1 : 0] M_AXI_WSTRB,
		// Write valid. This signal indicates that valid write data and strobes are available.
		output wire  M_AXI_WVALID,
		// Write ready. This signal indicates that the slave can accept the write data.
		input wire  M_AXI_WREADY,
		// Master Interface Write Response Channel ports. 
    // This signal indicates the status of the write transaction.
		input wire [1 : 0] M_AXI_BRESP,
		// Write response valid. 
    // This signal indicates that the channel is signaling a valid write response
		input wire  M_AXI_BVALID,
		// Response ready. This signal indicates that the master can accept a write response.
		output wire  M_AXI_BREADY,
		// Master Interface Read Address Channel ports. Read address (issued by master)
		output wire [C_M_AXI_ADDR_WIDTH-1 : 0] M_AXI_ARADDR,
		// Protection type. 
    // This signal indicates the privilege and security level of the transaction, 
    // and whether the transaction is a data access or an instruction access.
		output wire [2 : 0] M_AXI_ARPROT,
		// Read address valid. 
    // This signal indicates that the channel is signaling valid read address and control information.
		output wire  M_AXI_ARVALID,
		// Read address ready. 
    // This signal indicates that the slave is ready to accept an address and associated control signals.
		input wire  M_AXI_ARREADY,
		// Master Interface Read Data Channel ports. Read data (issued by slave)
		input wire [C_M_AXI_DATA_WIDTH-1 : 0] M_AXI_RDATA,
		// Read response. This signal indicates the status of the read transfer.
		input wire [1 : 0] M_AXI_RRESP,
		// Read valid. This signal indicates that the channel is signaling the required read data.
		input wire  M_AXI_RVALID,
		// Read ready. This signal indicates that the master can accept the read data and response information.
		output wire  M_AXI_RREADY
	);

	// function called clogb2 that returns an integer which has the
	// value of the ceiling of the log base 2
     //`include "parameter_poca.v" 
     
     //Commented by Sujan
	 //function integer clogb2 (input integer bit_depth);
	 //function integer clogb2 ( input reg bit_depth);
	 //	 begin
	 //	 for(clogb2=0; bit_depth>0; clogb2=clogb2+1)
	 //		 bit_depth = bit_depth >> 1;
	 //	 end
	 //endfunction
	 
    integer C_M_TRANSACTIONS_NUM;
    //reg [31:0] C_M_TRANSACTIONS_NUM;
	// TRANS_NUM_BITS is the width of the index counter for 
	// number of write or read transaction.
	//localparam integer TRANS_NUM_BITS = clogb2(C_M_TRANSACTIONS_NUM-1); //Commented by Sujan
	
	// Example State machine to initialize counter, initialize write transactions, 
	// initialize read transactions and comparison of read data with the 
	// written data words.
	//parameter [1:0] IDLE = 2'b00, // This state initiates AXI4Lite transaction 
	parameter [4:0] IDLE = 5'b00000, // This state initiates AXI4Lite transaction 
		    // after the state machine changes state to INIT_GEN_MULT_READ  
			// when there is 0 to 1 transition on INIT_AXI_TXN
			// In this state, the POCA reads the generator_mult value from the BRAM
		INIT_GEN_MULT_READ   = 5'b00001, // This state initializes a read transaction,
			// In this state, the POCA reads the test_response value from the BRAM
		INIT_TEST_RES_READ   = 5'b00010, // This state initializes a read transaction,
		    // In this state, the POCA reads the KS value from the BRAM
		INIT_KS_READ   = 5'b00011, // This state initializes a read transaction,
		    // In this state, the POCA reads the HSM_public_key from the BRAM
		INIT_HSM_PUBLIC_KEY_READ   = 5'b00100, // This state initializes a read transaction,
			// after the state machine changes state to INIT_WRITE   
			// when there is 0 to 1 transition on INIT_AXI_TXN
		INIT_WRITE   = 5'b00101, // This state initializes write transaction,
			// once writes are done, the state machine 
			// changes state to INIT_READ 
		INIT_READ = 5'b00110, // This state initializes read transaction
			// once reads are done, the state machine 
			// changes state to INIT_COMPARE 
		INIT_WAIT = 5'b00111,
		//INIT_COMPARE = 4'b0111; // This state issues the status of comparison 
			// of the written data with the read data	
        INIT_POCA_RES_WRITE = 5'b01000,
        
        INIT_DONE = 5'b01001;
        
	 reg [1:0] mst_exec_state;

	// AXI4LITE signals
	//write address valid
	reg  	axi_awvalid;
	//write data valid
	reg  	axi_wvalid;
	//read address valid
	reg  	axi_arvalid;
	//read data acceptance
	reg  	axi_rready;
	//write response acceptance
	reg  	axi_bready;
	//write address
	reg [C_M_AXI_ADDR_WIDTH-1 : 0] 	axi_awaddr;
	//write data
	reg [C_M_AXI_DATA_WIDTH-1 : 0] 	axi_wdata;
	//read addresss
	reg [C_M_AXI_ADDR_WIDTH-1 : 0] 	axi_araddr;
	//Asserts when there is a write response error
	wire  	write_resp_error;
	//Asserts when there is a read response error
	wire  	read_resp_error;
	//A pulse to initiate a write transaction
	reg  	start_single_write;
	//A pulse to initiate a read transaction
	reg  	start_single_read;
	//Asserts when a single beat write transaction is issued and remains asserted till the completion of write trasaction.
	reg  	write_issued;
	//Asserts when a single beat read transaction is issued and remains asserted till the completion of read trasaction.
	reg  	read_issued;
	//flag that marks the completion of write trasactions. The number of write transaction is user selected by the parameter C_M_TRANSACTIONS_NUM.
	reg  	writes_done;
	//flag that marks the completion of read trasactions. The number of read transaction is user selected by the parameter C_M_TRANSACTIONS_NUM
	reg  	reads_done;
	//The error register is asserted when any of the write response error, read response error or the data mismatch flags are asserted.
	reg  	error_reg;
	//index counter to track the number of write transaction issued
	//reg [TRANS_NUM_BITS : 0] 	write_index;
	reg [7 : 0] 	write_index;    //modified by Sujan to avaiod the use of TRANS_NUM_BITS
	//index counter to track the number of read transaction issued
	//reg [TRANS_NUM_BITS : 0] 	read_index;
	reg [7 : 0] 	read_index;
	//Expected read data used to compare with the read data.
	reg [C_M_AXI_DATA_WIDTH-1 : 0] 	expected_rdata;
	//Flag marks the completion of comparison of the read data with the expected read data
	reg  	compare_done;
	//This flag is asserted when there is a mismatch of the read data with the expected read data.
	reg  	read_mismatch;
	//Flag is asserted when the write index reaches the last write transction number
	reg  	last_write;
	//Flag is asserted when the read index reaches the last read transction number
	reg  	last_read;
	reg  	init_txn_ff;
	reg  	init_txn_ff2;
	reg  	init_txn_edge;
	wire  	init_txn_pulse;
	
	// register and wire variables required for POCA 
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
    reg [ecc_mult_input_size+P_value_size+ecc_output_size+test_response_size-1:0] hash_input_g_p_qa_r_reg;
    wire shared_secret_key_ready;
    wire poca_output_ready;


    reg [address_bus_size-1:0] slave_base_address;
    wire [7:0] write_addr_index;
    reg slave_IP_done;
	// I/O Connections assignments

	//Adding the offset address to the base addr of the slave
	//assign M_AXI_AWADDR	= C_M_TARGET_SLAVE_BASE_ADDR + axi_awaddr;
	assign M_AXI_AWADDR	= slave_base_address + axi_awaddr;
	//AXI 4 write data
	assign M_AXI_WDATA	= axi_wdata;
	assign M_AXI_AWPROT	= 3'b000;
	assign M_AXI_AWVALID	= axi_awvalid;
	//Write Data(W)
	assign M_AXI_WVALID	= axi_wvalid;
	//Set all byte strobes in this example
	assign M_AXI_WSTRB	= 4'b1111;
	//Write Response (B)
	assign M_AXI_BREADY	= axi_bready;
	//Read Address (AR)
	//assign M_AXI_ARADDR	= C_M_TARGET_SLAVE_BASE_ADDR + axi_araddr;
	assign M_AXI_ARADDR	= slave_base_address + axi_araddr;
	assign M_AXI_ARVALID	= axi_arvalid;
	assign M_AXI_ARPROT	= 3'b001;
	//Read and Read Response (R)
	assign M_AXI_RREADY	= axi_rready;
	//Example design I/O
	assign TXN_DONE	= compare_done;
	assign init_txn_pulse	= (!init_txn_ff2) && init_txn_ff;
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
        .data_in(data_in),     //input data which will come from TRNG, DH and SHA sequencially 32 bit by 32 bit
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
        .poca_output_ready(poca_output_ready)
    );

	//Generate a pulse to initiate AXI transaction.
	always @(posedge M_AXI_ACLK)										      
	  begin                                                                        
	    // Initiates AXI transaction delay    
	    if (M_AXI_ARESETN == 0 )                                                   
	      begin                                                                    
	        init_txn_ff <= 1'b0;                                                   
	        init_txn_ff2 <= 1'b0;                                                   
	      end                                                                               
	    else                                                                       
	      begin  
	        init_txn_ff <= INIT_AXI_TXN;
	        init_txn_ff2 <= init_txn_ff;                                                                 
	      end                                                                      
	  end     


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
	        hash_input_g_p_qa_r_reg <= 0;                                       
	      end                                                                               
	    else                                                                       
	      begin  
	        poca_output_response_reg <= poca_output_response;
	        addr_out_reg <= addr_out;    
	        enable_data_out_reg <= enable_data_out; 
	        ecc_input_1_reg <= ecc_input_1;
	        ecc_input_2_reg <= ecc_input_2;  
	        if(hash_input_g_p_qa_r > 0) begin
	           hash_input_r_reg <=  {700'b0, hash_input_g_p_qa_r};
	        end
	        else hash_input_r_reg  <= {992'b0, hash_input_r};
	        //hash_input_g_p_qa_r_reg <= hash_input_g_p_qa_r;                                                       
	      end                                                                      
	  end     

	//--------------------
	//Write Address Channel
	//--------------------

	// The purpose of the write address channel is to request the address and 
	// command information for the entire transaction.  It is a single beat
	// of information.

	// Note for this example the axi_awvalid/axi_wvalid are asserted at the same
	// time, and then each is deasserted independent from each other.
	// This is a lower-performance, but simplier control scheme.

	// AXI VALID signals must be held active until accepted by the partner.

	// A data transfer is accepted by the slave when a master has
	// VALID data and the slave acknoledges it is also READY. While the master
	// is allowed to generated multiple, back-to-back requests by not 
	// deasserting VALID, this design will add rest cycle for
	// simplicity.

	// Since only one outstanding transaction is issued by the user design,
	// there will not be a collision between a new request and an accepted
	// request on the same clock cycle. 

	  always @(posedge M_AXI_ACLK)										      
	  begin                                                                        
	    //Only VALID signals must be deasserted during reset per AXI spec          
	    //Consider inverting then registering active-low reset for higher fmax     
	    if (M_AXI_ARESETN == 0 || init_txn_pulse == 1'b1)                                                   
	      begin                                                                    
	        axi_awvalid <= 1'b0;                                                   
	      end                                                                      
	      //Signal a new address/data command is available by user logic           
	    else                                                                       
	      begin                                                                    
	        if (start_single_write)                                                
	          begin                                                                
	            axi_awvalid <= 1'b1;                                               
	          end                                                                  
	     //Address accepted by interconnect/slave (issue of M_AXI_AWREADY by slave)
	        else if (M_AXI_AWREADY && axi_awvalid)                                 
	          begin                                                                
	            axi_awvalid <= 1'b0;                                               
	          end                                                                  
	      end                                                                      
	  end                                                                          
	                                                                               
	                                                                               
	  // start_single_write triggers a new write                                   
	  // transaction. write_index is a counter to                                  
	  // keep track with number of write transaction                               
	  // issued/initiated                                                          
	  always @(posedge M_AXI_ACLK)                                                 
	  begin                                                                        
	    if (M_AXI_ARESETN == 0 || init_txn_pulse == 1'b1)                                                   
	      begin                                                                    
	        write_index <= 0;                                                      
	      end                                                                      
	      // Signals a new write address/ write data is                            
	      // available by user logic                                               
	    else if (start_single_write)                                               
	      begin                                                                    
	        write_index <= write_index + 1;                                        
	      end                                                                      
	  end                                                                          


	//--------------------
	//Write Data Channel
	//--------------------

	//The write data channel is for transfering the actual data.
	//The data generation is speific to the example design, and 
	//so only the WVALID/WREADY handshake is shown here

	   always @(posedge M_AXI_ACLK)                                        
	   begin                                                                         
	     if (M_AXI_ARESETN == 0  || init_txn_pulse == 1'b1)                                                    
	       begin                                                                     
	         axi_wvalid <= 1'b0;                                                     
	       end                                                                       
	     //Signal a new address/data command is available by user logic              
	     else if (start_single_write)                                                
	       begin                                                                     
	         axi_wvalid <= 1'b1;                                                     
	       end                                                                       
	     //Data accepted by interconnect/slave (issue of M_AXI_WREADY by slave)      
	     else if (M_AXI_WREADY && axi_wvalid)                                        
	       begin                                                                     
	        axi_wvalid <= 1'b0;                                                      
	       end                                                                       
	   end                                                                           


	//----------------------------
	//Write Response (B) Channel
	//----------------------------

	//The write response channel provides feedback that the write has committed
	//to memory. BREADY will occur after both the data and the write address
	//has arrived and been accepted by the slave, and can guarantee that no
	//other accesses launched afterwards will be able to be reordered before it.

	//The BRESP bit [1] is used indicate any errors from the interconnect or
	//slave for the entire write burst. This example will capture the error.

	//While not necessary per spec, it is advisable to reset READY signals in
	//case of differing reset latencies between master/slave.

	  always @(posedge M_AXI_ACLK)                                    
	  begin                                                                
	    if (M_AXI_ARESETN == 0 || init_txn_pulse == 1'b1)                                           
	      begin                                                            
	        axi_bready <= 1'b0;                                            
	      end                                                              
	    // accept/acknowledge bresp with axi_bready by the master          
	    // when M_AXI_BVALID is asserted by slave                          
	    else if (M_AXI_BVALID && ~axi_bready)                              
	      begin                                                            
	        axi_bready <= 1'b1;                                            
	      end                                                              
	    // deassert after one clock cycle                                  
	    else if (axi_bready)                                               
	      begin                                                            
	        axi_bready <= 1'b0;                                            
	      end                                                              
	    // retain the previous value                                       
	    else                                                               
	      axi_bready <= axi_bready;                                        
	  end                                                                  
	                                                                       
	//Flag write errors                                                    
	assign write_resp_error = (axi_bready & M_AXI_BVALID & M_AXI_BRESP[1]);


	//----------------------------
	//Read Address Channel
	//----------------------------

	//start_single_read triggers a new read transaction. read_index is a counter to
	//keep track with number of read transaction issued/initiated

	  always @(posedge M_AXI_ACLK)                                                     
	  begin                                                                            
	    if (M_AXI_ARESETN == 0 || init_txn_pulse == 1'b1)                                                       
	      begin                                                                        
	        read_index <= 0;                                                           
	      end                                                                          
	    // Signals a new read address is                                               
	    // available by user logic                                                     
	    else if (start_single_read)                                                    
	      begin                                                                        
	        read_index <= read_index + 1;                                              
	      end                                                                          
	  end                                                                              
	                                                                                   
	  // A new axi_arvalid is asserted when there is a valid read address              
	  // available by the master. start_single_read triggers a new read                
	  // transaction                                                                   
	  always @(posedge M_AXI_ACLK)                                                     
	  begin                                                                            
	    if (M_AXI_ARESETN == 0 || init_txn_pulse == 1'b1)                                                       
	      begin                                                                        
	        axi_arvalid <= 1'b0;                                                       
	      end                                                                          
	    //Signal a new read address command is available by user logic                 
	    else if (start_single_read)                                                    
	      begin                                                                        
	        axi_arvalid <= 1'b1;                                                       
	      end                                                                          
	    //RAddress accepted by interconnect/slave (issue of M_AXI_ARREADY by slave)    
	    else if (M_AXI_ARREADY && axi_arvalid)                                         
	      begin                                                                        
	        axi_arvalid <= 1'b0;                                                       
	      end                                                                          
	    // retain the previous value                                                   
	  end                                                                              


	//--------------------------------
	//Read Data (and Response) Channel
	//--------------------------------

	//The Read Data channel returns the results of the read request 
	//The master will accept the read data by asserting axi_rready
	//when there is a valid read data available.
	//While not necessary per spec, it is advisable to reset READY signals in
	//case of differing reset latencies between master/slave.

	  always @(posedge M_AXI_ACLK)                                    
	  begin                                                                 
	    if (M_AXI_ARESETN == 0 || init_txn_pulse == 1'b1)                                            
	      begin                                                             
	        axi_rready <= 1'b0;                                             
	      end                                                               
	    // accept/acknowledge rdata/rresp with axi_rready by the master     
	    // when M_AXI_RVALID is asserted by slave                           
	    else if (M_AXI_RVALID && ~axi_rready)                               
	      begin                                                             
	        axi_rready <= 1'b1;                                             
	      end                                                               
	    // deassert after one clock cycle                                   
	    else if (axi_rready)                                                
	      begin                                                             
	        axi_rready <= 1'b0;                                             
	      end                                                               
	    // retain the previous value                                        
	  end                                                                   
	                                                                        
	//Flag write errors                                                     
	assign read_resp_error = (axi_rready & M_AXI_RVALID & M_AXI_RRESP[1]);  


	//--------------------------------
	//User Logic
	//--------------------------------

	//Address/Data Stimulus

	//Address/data pairs for this example. The read and write values should
	//match.
	//Modify these as desired for different address patterns.

	  //Write Addresses                                        
	  always @(posedge M_AXI_ACLK)                                  
	      begin                                                     
	        if (M_AXI_ARESETN == 0  || init_txn_pulse == 1'b1)                                
	          begin                                                 
	            axi_awaddr <= 0;                                    
	          end                                                   
	          // Signals a new write address/ write data is         
	          // available by user logic                            
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
	            //axi_wdata <= C_M_START_DATA_VALUE;   
	            axi_wdata <= 0;               
	          end                                                   
	        // Signals a new write address/ write data is           
	        // available by user logic                              
	        else if (M_AXI_WREADY && axi_wvalid)                    
	          begin 
	            if(slave_base_address == TRNG_write_base_addr)  begin                                              
	            //axi_wdata <= C_M_START_DATA_VALUE + write_index;    
	               axi_wdata <= enable_data_out_reg;
	            end
	            else if(slave_base_address == ECC_write_base_addr)  begin 
	               case(write_addr_index)
	                    8'h00: axi_wdata <= ecc_input_1_reg[31:0];
                        8'h04: axi_wdata <= ecc_input_1_reg[63:32];
                        8'h08: axi_wdata <= ecc_input_1_reg[95:64];
                        8'h0C: axi_wdata <= ecc_input_1_reg[127:96];
                        8'h10: axi_wdata <= 0;
                        8'h14: axi_wdata <= 0;
                        8'h18: axi_wdata <= 0;
                        8'h1C: axi_wdata <= 0;
                        8'h20: axi_wdata <= 0;
                        8'h24: axi_wdata <= ecc_input_2_reg[31:0];
                        8'h28: axi_wdata <= ecc_input_2_reg[63:32];
                        8'h2C: axi_wdata <= ecc_input_2_reg[95:64];
                        8'h30: axi_wdata <= ecc_input_2_reg[127:96];
                        8'h34: axi_wdata <= 0;
                        8'h38: axi_wdata <= 0;
                        8'h3C: axi_wdata <= 0;
                        8'h40: axi_wdata <= 0;
                        8'h44: axi_wdata <= 0;
	               endcase
	            end
	            else if(slave_base_address == Hash_write_base_addr)  begin 
	               case(write_addr_index)
	                    8'h00: axi_wdata <= hash_input_r_reg[31:0];
                        8'h04: axi_wdata <= hash_input_r_reg[63:32];
                        8'h08: axi_wdata <= hash_input_r_reg[95:64];
                        8'h0C: axi_wdata <= hash_input_r_reg[127:96];
                        8'h10: axi_wdata <= hash_input_r_reg[159:128];
                        8'h14: axi_wdata <= hash_input_r_reg[191:160];
                        8'h18: axi_wdata <= hash_input_r_reg[223:192];
                        8'h1C: axi_wdata <= hash_input_r_reg[255:224];
                        8'h20: axi_wdata <= hash_input_r_reg[287:256];
                        8'h24: axi_wdata <= hash_input_r_reg[319:288];
                        8'h28: axi_wdata <= hash_input_r_reg[351:320];
                        8'h2C: axi_wdata <= hash_input_r_reg[383:352];
                        8'h30: axi_wdata <= hash_input_r_reg[415:384];
                        8'h34: axi_wdata <= hash_input_r_reg[447:416];
                        8'h38: axi_wdata <= hash_input_r_reg[479:448];
                        8'h3C: axi_wdata <= hash_input_r_reg[511:480];
                        8'h40: axi_wdata <= hash_input_r_reg[543:512];
                        8'h44: axi_wdata <= hash_input_r_reg[575:544];
                        8'h48: axi_wdata <= hash_input_r_reg[607:576];
                        8'h4C: axi_wdata <= hash_input_r_reg[639:608];
                        8'h50: axi_wdata <= hash_input_r_reg[671:640];
                        8'h54: axi_wdata <= hash_input_r_reg[703:672];
                        8'h58: axi_wdata <= hash_input_r_reg[735:704];
                        8'h5C: axi_wdata <= hash_input_r_reg[767:736];
                        8'h60: axi_wdata <= hash_input_r_reg[799:768];
                        8'h64: axi_wdata <= hash_input_r_reg[831:800];
                        8'h68: axi_wdata <= hash_input_r_reg[863:832];
                        8'h6C: axi_wdata <= hash_input_r_reg[895:864];
                        8'h70: axi_wdata <= hash_input_r_reg[927:896];
                        8'h74: axi_wdata <= hash_input_r_reg[959:928];
                        8'h78: axi_wdata <= hash_input_r_reg[991:960];
                        8'h7C: axi_wdata <= hash_input_r_reg[1023:992];
                        8'h80: axi_wdata <= enable_data_out_reg;
	               endcase
	            end
	            else if(slave_base_address == GPIO_base_addr) begin
	                   axi_wdata <= 32'h0000000F;
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
	          // Signals a new write address/ write data is         
	          // available by user logic                            
	        else if (M_AXI_ARREADY && axi_arvalid)                  
	          begin                                                 
	            axi_araddr <= axi_araddr + 32'h00000004;            
	          end                                                   
	      end                                                       
	  
	  //Saving bus data while reading from the bus and sending to POCA                                                              
	  always @(posedge M_AXI_ACLK)                                  
	      begin                                                     
	        if (M_AXI_ARESETN == 0  || init_txn_pulse == 1'b1)                                
	          begin                                                 
	            data_in <= 0; 
	            slave_IP_done <= 0;            
	          end                                                   
	          // Signals a new write address/ write data is         
	          // available by user logic                            
	        else if (M_AXI_RVALID && axi_rready)                    
	          begin                                                 
	            data_in <= M_AXI_RDATA;
	            if ((M_AXI_ARADDR == ECC_read_base_addr) || (M_AXI_ARADDR == Hash_read_base_addr)) begin
	               slave_IP_done <= M_AXI_RDATA[0:0];
	            end  
	          end                                                   
	      end   
	  
	                                                                
	  always @(posedge M_AXI_ACLK)                                  
	      begin                                                     
	        if (M_AXI_ARESETN == 0  || init_txn_pulse == 1'b1)                                
	          begin                                                 
	            generator_mult <= 0;             
	          end                                                   
	          // Signals a new write address/ write data is         
	          // available by user logic                            
	        else if (M_AXI_RVALID && axi_rready && (M_AXI_ARADDR == BRAM_base_addr))                    
	          begin                                                 
	            generator_mult <= M_AXI_RDATA;
	          end                                                   
	      end
	       
	  always @(posedge M_AXI_ACLK)                                  
	      begin                                                     
	        if (M_AXI_ARESETN == 0  || init_txn_pulse == 1'b1)                                
	          begin                                                 
	            test_response <= 0;             
	          end                                                   
	          // Signals a new write address/ write data is         
	          // available by user logic                            
	        else if (M_AXI_RVALID && axi_rready && (M_AXI_ARADDR == (BRAM_base_addr + 32'h00000004)))                    
	          begin                                                 
	            test_response <= M_AXI_RDATA;
	          end                                                   
	      end    
	      
	   always @(posedge M_AXI_ACLK)                                  
	      begin                                                     
	        if (M_AXI_ARESETN == 0  || init_txn_pulse == 1'b1)                                
	          begin                                                 
	            KS_value <= 0;             
	          end                                                   
	          // Signals a new write address/ write data is         
	          // available by user logic                            
	        else if (M_AXI_RVALID && axi_rready && (M_AXI_ARADDR == (BRAM_base_addr + 32'h00000008)))                    
	          begin                                                 
	            KS_value <= M_AXI_RDATA[KS_value_size-1:0];
	          end                                                   
	      end   
	      
	    always @(posedge M_AXI_ACLK)                                  
	      begin                                                     
	        if (M_AXI_ARESETN == 0  || init_txn_pulse == 1'b1)                                
	          begin                                                 
	            hsm_public_key <= 0;             
	          end                                                   
	          // Signals a new write address/ write data is         
	          // available by user logic                            
	        else if (M_AXI_RVALID && axi_rready && (M_AXI_ARADDR >= (BRAM_base_addr + 32'h00000010)) || (M_AXI_ARADDR <= (BRAM_base_addr + 32'h0000002C)))                    
	          begin                                                 
	            hsm_public_key <= {M_AXI_RDATA, hsm_public_key[ecc_output_size-1:data_bus_size]};
	          end                                                   
	      end                                                                  
//	  always @(posedge M_AXI_ACLK)          //comment this always block. It will not be required.                        
//	      begin                                                     
//	        if (M_AXI_ARESETN == 0  || init_txn_pulse == 1'b1)                                
//	          begin                                                 
//	            expected_rdata <= C_M_START_DATA_VALUE;             
//	          end                                                   
//	          // Signals a new write address/ write data is         
//	          // available by user logic                            
//	        else if (M_AXI_RVALID && axi_rready)                    
//	          begin                                                 
//	            expected_rdata <= C_M_START_DATA_VALUE + read_index;
//	          end                                                   
//	      end                                                       
	  //implement master command interface state machine                         
	  always @ ( posedge M_AXI_ACLK)                                                    
	  begin                                                                             
	    if (M_AXI_ARESETN == 1'b0)                                                     
	      begin                                                                         
	      // reset condition                                                            
	      // All the signals are assigned default values under reset condition          
	        mst_exec_state  <= IDLE;                                            
	        start_single_write <= 1'b0;                                                 
	        write_issued  <= 1'b0;                                                      
	        start_single_read  <= 1'b0;                                                 
	        read_issued   <= 1'b0;                                                      
	        compare_done  <= 1'b0;                                                      
	        ERROR <= 1'b0;
	        // Assigning the generic slave base address
	        slave_base_address <= 0;   // Added by Sujan 
	        C_M_TRANSACTIONS_NUM <= 0;
	        go <= 0;
	        write_complete <= 0;
	      end                                                                           
	    else                                                                            
	      begin                                                                         
	       // state transition                                                          
	        case (mst_exec_state)                                                       
	                                                                                    
	          IDLE:                                                             
	          // This state is responsible to initiate 
	          // AXI transaction when init_txn_pulse is asserted 
	            if ( init_txn_pulse == 1'b1 )                                     
	              begin                                                                 
	                //mst_exec_state  <= INIT_WRITE;  
	                mst_exec_state  <= INIT_GEN_MULT_READ;                                    
	                ERROR <= 1'b0;
	                compare_done <= 1'b0;
	              end                                                                   
	            else                                                                    
	              begin                                                                 
	                mst_exec_state  <= IDLE;                                    
	              end                                                                   
	          
	          INIT_GEN_MULT_READ:
	            // This state is responsible to issue start_single_read pulse to        
	            // initiate a read transaction. Read transactions will be               
	            // issued until last_read signal is asserted.                           
	             // read controller                                                     
	             if (reads_done)                                                        
	               begin                                                                
	                 mst_exec_state <= INIT_TEST_RES_READ;                                    
	               end                                                                  
	             else                                                                   
	               begin                                                                
	                 mst_exec_state  <= INIT_GEN_MULT_READ;                                      
	                                                                                    
	                 if (~axi_arvalid && ~M_AXI_RVALID && ~last_read && ~start_single_read && ~read_issued)
	                   begin                                                            
	                     start_single_read <= 1'b1;                                     
	                     read_issued  <= 1'b1; 
	                     // Added by Sujan
	                     // Assigning the generic slave base address and the number of transaction
	                     slave_base_address <= BRAM_base_addr; 
	                     C_M_TRANSACTIONS_NUM <= 1;                                     
	                   end                                                              
	                 else if (axi_rready)                                               
	                   begin                                                            
	                     read_issued  <= 1'b0;                                          
	                   end                                                              
	                 else                                                               
	                   begin                                                            
	                     start_single_read <= 1'b0; //Negate to generate a pulse        
	                   end                                                              
	               end     
	          
	          INIT_TEST_RES_READ:
	            // This state is responsible to issue start_single_read pulse to        
	            // initiate a read transaction. Read transactions will be               
	            // issued until last_read signal is asserted.                           
	             // read controller                                                     
	             if (reads_done)                                                        
	               begin                                                                
	                 mst_exec_state <= INIT_KS_READ;                                    
	               end                                                                  
	             else                                                                   
	               begin                                                                
	                 mst_exec_state  <= INIT_TEST_RES_READ;                                      
	                                                                                    
	                 if (~axi_arvalid && ~M_AXI_RVALID && ~last_read && ~start_single_read && ~read_issued)
	                   begin                                                            
	                     start_single_read <= 1'b1;                                     
	                     read_issued  <= 1'b1; 
	                     // Added by Sujan
	                     // Assigning the generic slave base address and the number of transaction
	                     slave_base_address <= BRAM_base_addr + 32'h00000004; 
	                     C_M_TRANSACTIONS_NUM <= 1;                                     
	                   end                                                              
	                 else if (axi_rready)                                               
	                   begin                                                            
	                     read_issued  <= 1'b0;                                          
	                   end                                                              
	                 else                                                               
	                   begin                                                            
	                     start_single_read <= 1'b0; //Negate to generate a pulse        
	                   end                                                              
	               end   
	          
	          INIT_KS_READ:
	            // This state is responsible to issue start_single_read pulse to        
	            // initiate a read transaction. Read transactions will be               
	            // issued until last_read signal is asserted.                           
	             // read controller                                                     
	             if (reads_done)                                                        
	               begin                                                                
	                 mst_exec_state <= INIT_HSM_PUBLIC_KEY_READ;                                    
	               end                                                                  
	             else                                                                   
	               begin                                                                
	                 mst_exec_state  <= INIT_KS_READ;                                      
	                                                                                    
	                 if (~axi_arvalid && ~M_AXI_RVALID && ~last_read && ~start_single_read && ~read_issued)
	                   begin                                                            
	                     start_single_read <= 1'b1;                                     
	                     read_issued  <= 1'b1; 
	                     // Added by Sujan
	                     // Assigning the generic slave base address and the number of transaction
	                     slave_base_address <= BRAM_base_addr + 32'h00000008; 
	                     C_M_TRANSACTIONS_NUM <= 1;                                     
	                   end                                                              
	                 else if (axi_rready)                                               
	                   begin                                                            
	                     read_issued  <= 1'b0;                                          
	                   end                                                              
	                 else                                                               
	                   begin                                                            
	                     start_single_read <= 1'b0; //Negate to generate a pulse        
	                   end                                                              
	               end 
	          
	          INIT_HSM_PUBLIC_KEY_READ:
	            // This state is responsible to issue start_single_read pulse to        
	            // initiate a read transaction. Read transactions will be               
	            // issued until last_read signal is asserted.                           
	             // read controller                                                     
	             if (reads_done)                                                        
	               begin 
	                 go <= 1;
	                 mst_exec_state <= INIT_WAIT;                                 
	               end                                                                  
	             else                                                                   
	               begin                                                                
	                 mst_exec_state  <= INIT_HSM_PUBLIC_KEY_READ;                                      
	                                                                                    
	                 if (~axi_arvalid && ~M_AXI_RVALID && ~last_read && ~start_single_read && ~read_issued)
	                   begin                                                            
	                     start_single_read <= 1'b1;                                     
	                     read_issued  <= 1'b1; 
	                     // Added by Sujan
	                     // Assigning the generic slave base address and the number of transaction
	                     slave_base_address <= BRAM_base_addr + 32'h00000010; 
	                     C_M_TRANSACTIONS_NUM <= 8;                                     
	                   end                                                              
	                 else if (axi_rready)                                               
	                   begin                                                            
	                     read_issued  <= 1'b0;                                          
	                   end                                                              
	                 else                                                               
	                   begin                                                            
	                     start_single_read <= 1'b0; //Negate to generate a pulse        
	                   end                                                              
	               end 
	                                                                                       
	          INIT_WRITE:                                                               
	            // This state is responsible to issue start_single_write pulse to       
	            // initiate a write transaction. Write transactions will be             
	            // issued until last_write signal is asserted.                          
	            // write controller                                                     
	            if (writes_done)                                                        
	              begin  
	                write_complete <= 1;                                                               
	                mst_exec_state <= INIT_WAIT;//                                      
	              end                                                                   
	            else                                                                    
	              begin                                                                 
	                mst_exec_state  <= INIT_WRITE;                                      
	                                                                                    
	                  if (~axi_awvalid && ~axi_wvalid && ~M_AXI_BVALID && ~last_write && ~start_single_write && ~write_issued)
	                    begin                                                           
	                      start_single_write <= 1'b1;                                   
	                      write_issued  <= 1'b1;  
	                      slave_base_address <= addr_out_reg;
	                      if(addr_out_reg == TRNG_write_base_addr) begin
	                           C_M_TRANSACTIONS_NUM  <= 1;   // 1 write transaction is needed while writing at TRNG
	                      end 
	                      else if(addr_out_reg == ECC_write_base_addr) begin
	                           C_M_TRANSACTIONS_NUM  <= 16;   // 16 write transaction is needed while writing to ECC 
	                      end  
	                      else if(addr_out_reg == Hash_write_base_addr) begin
	                           C_M_TRANSACTIONS_NUM  <= 33;   // 16 write transaction is needed while writing to ECC 
	                      end                                  
	                    end                                                             
	                  else if (axi_bready)                                              
	                    begin                                                           
	                      write_issued  <= 1'b0;                                        
	                    end                                                             
	                  else                                                              
	                    begin                                                           
	                      start_single_write <= 1'b0; //Negate to generate a pulse      
	                    end                                                             
	              end                                                                   
	                                                                                    
	          INIT_READ:                                                                
	            // This state is responsible to issue start_single_read pulse to        
	            // initiate a read transaction. Read transactions will be               
	            // issued until last_read signal is asserted.                           
	             // read controller                                                     
	             if (reads_done)                                                        
	               begin    
	                 input_data_transfer_complete <= 1'b1;                                                            
	                 mst_exec_state <= INIT_WAIT;                                    
	               end                                                                  
	             else                                                                   
	               begin                                                                
	                 //mst_exec_state  <= INIT_READ;                                      
	                                                                                    
	                 if (~axi_arvalid && ~M_AXI_RVALID && ~last_read && ~start_single_read && ~read_issued)
	                   begin                                                            
	                     start_single_read <= 1'b1;                                     
	                     read_issued  <= 1'b1; 
	                     slave_base_address <= addr_out_reg; 
	                     if(addr_out_reg == TRNG_read_base_addr) begin
	                           C_M_TRANSACTIONS_NUM  <= 4;   // 1 read transaction is needed while reading from TRNG
	                           data_input_ready <= 1'b1; 
	                           mst_exec_state  <= INIT_READ;
	                     end 
	                     else if(addr_out_reg == ECC_read_base_addr) begin
	                           C_M_TRANSACTIONS_NUM  <= 8;   // 8 read transaction is needed while reading from ECC 
	                           if(slave_IP_done == 1'b1) begin
	                               mst_exec_state  <= INIT_READ; 
	                           end
	                           else begin
	                               mst_exec_state  <= INIT_WAIT; 
	                           end
	                     end                                        
	                   end                                                              
	                 else if (axi_rready)                                               
	                   begin                                                            
	                     read_issued  <= 1'b0;                                          
	                   end                                                              
	                 else                                                               
	                   begin                                                            
	                     start_single_read <= 1'b0; //Negate to generate a pulse        
	                   end                                                              
	               end                                                                  
	                                                                                    
//	           INIT_COMPARE:                                                            
//	             begin
//	                 // This state is responsible to issue the state of comparison          
//	                 // of written data with the read data. If no error flags are set,      
//	                 // compare_done signal will be asseted to indicate success.            
//	                 ERROR <= error_reg; 
//	                 mst_exec_state <= IDLE;                                    
//	                 compare_done <= 1'b1;                                              
//	             end
	             
	           INIT_WAIT:                                                            
	             begin
	                 if(poca_output_ready == 1) begin
	                   mst_exec_state <= INIT_POCA_RES_WRITE;
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
	                //write_complete <= 1;                                                               
	                mst_exec_state <= INIT_DONE;//                                      
	               end                                                                   
	              else                                                                    
	              begin                                                                 
	                mst_exec_state  <= INIT_POCA_RES_WRITE;                                      
	                                                                                    
	                  if (~axi_awvalid && ~axi_wvalid && ~M_AXI_BVALID && ~last_write && ~start_single_write && ~write_issued)
	                    begin                                                           
	                      start_single_write <= 1'b1;                                   
	                      write_issued  <= 1'b1;  
	                      slave_base_address <= BRAM_base_addr + 32'h00000040;
	                      C_M_TRANSACTIONS_NUM <= 24;                                  
	                    end                                                             
	                  else if (axi_bready)                                              
	                    begin                                                           
	                      write_issued  <= 1'b0;                                        
	                    end                                                             
	                  else                                                              
	                    begin                                                           
	                      start_single_write <= 1'b0; //Negate to generate a pulse      
	                    end                                                            
	              end 
	           
	           INIT_DONE:
	                if (writes_done)                                                        
	               begin  
	                //write_complete <= 1;                                                               
	                mst_exec_state <= IDLE;//                                      
	               end                                                                   
	              else                                                                    
	              begin                                                                 
	                mst_exec_state  <= INIT_DONE;                                      
	                                                                                    
	                  if (~axi_awvalid && ~axi_wvalid && ~M_AXI_BVALID && ~last_write && ~start_single_write && ~write_issued)
	                    begin                                                           
	                      start_single_write <= 1'b1;                                   
	                      write_issued  <= 1'b1;  
	                      slave_base_address <= GPIO_base_addr;
	                      C_M_TRANSACTIONS_NUM <= 1;                                  
	                    end                                                             
	                  else if (axi_bready)                                              
	                    begin                                                           
	                      write_issued  <= 1'b0;                                        
	                    end                                                             
	                  else                                                              
	                    begin                                                           
	                      start_single_write <= 1'b0; //Negate to generate a pulse      
	                    end                                                            
	              end                                                                              
	           default :                                                                
	             begin                                                                  
	               mst_exec_state  <= IDLE;                                     
	             end                                                                    
	        endcase                                                                     
	    end                                                                             
	  end //MASTER_EXECUTION_PROC                                                       
	                                                                                    
	  //Terminal write count                                                            
	                                                                                    
	  always @(posedge M_AXI_ACLK)                                                      
	  begin                                                                             
	    if (M_AXI_ARESETN == 0 || init_txn_pulse == 1'b1)                                                         
	      last_write <= 1'b0;                                                           
	                                                                                    
	    //The last write should be associated with a write address ready response       
	    else if ((write_index == C_M_TRANSACTIONS_NUM) && M_AXI_AWREADY)                
	      last_write <= 1'b1;                                                           
	    else                                                                            
	      last_write <= last_write;                                                     
	  end                                                                               
	                                                                                    
	  //Check for last write completion.                                                
	                                                                                    
	  //This logic is to qualify the last write count with the final write              
	  //response. This demonstrates how to confirm that a write has been                
	  //committed.                                                                      
	                                                                                    
	  always @(posedge M_AXI_ACLK)                                                      
	  begin                                                                             
	    if (M_AXI_ARESETN == 0 || init_txn_pulse == 1'b1)                                                         
	      writes_done <= 1'b0;                                                          
	                                                                                    
	      //The writes_done should be associated with a bready response                 
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
	                                                                                    
	    //The last read should be associated with a read address ready response         
	    else if ((read_index == C_M_TRANSACTIONS_NUM) && (M_AXI_ARREADY) )              
	      last_read <= 1'b1;   
            else if (reads_done == 1'b1)    // mash
              last_read <= 1'b0;            // mash                                             
	    else                                                                            
	      last_read <= last_read;                                                       
	      //last_read <= 1'b0;                                                       
	  end                                                                               
	                                                                                    
	/*                                                                                  
	 Check for last read completion.                                                    
	                                                                                    
	 This logic is to qualify the last read count with the final read                   
	 response/data.                                                                     
	 */                                                                                 
	  always @(posedge M_AXI_ACLK)                                                      
	  begin                                                                             
	    if (M_AXI_ARESETN == 0 || init_txn_pulse == 1'b1)                                                         
	      reads_done <= 1'b0;                                                           
	                                                                                    
	    //The reads_done should be associated with a read ready response                
	    else if (last_read && M_AXI_RVALID && axi_rready)                               
	      reads_done <= 1'b1;                                                           
	    else                                                                            
	      //reads_done <= reads_done;      // mash                                           
	      reads_done <= 1'b0;                                                     
	    end                                                                             
	                                                                                    
	//-----------------------------                                                     
	//Example design error register                                                     
	//-----------------------------                                                     
	                                                                                    
	//Data Comparison                                                                   
	  always @(posedge M_AXI_ACLK)                                                      
	  begin                                                                             
	    if (M_AXI_ARESETN == 0  || init_txn_pulse == 1'b1)                                                         
	    read_mismatch <= 1'b0;                                                          
	                                                                                    
	    //The read data when available (on axi_rready) is compared with the expected data
	    else if ((M_AXI_RVALID && axi_rready) && (M_AXI_RDATA != expected_rdata))         
	      read_mismatch <= 1'b1;                                                        
	    else                                                                            
	      read_mismatch <= read_mismatch;                                               
	  end                                                                               
	                                                                                    
	// Register and hold any data mismatches, or read/write interface errors            
	  always @(posedge M_AXI_ACLK)                                                      
	  begin                                                                             
	    if (M_AXI_ARESETN == 0  || init_txn_pulse == 1'b1)                                                         
	      error_reg <= 1'b0;                                                            
	                                                                                    
	    //Capture any error types                                                       
	    else if (read_mismatch || write_resp_error || read_resp_error)                  
	      error_reg <= 1'b1;                                                            
	    else                                                                            
	      error_reg <= error_reg;                                                       
	  end                                                                               
	// Add user logic here

	// User logic ends

	endmodule
