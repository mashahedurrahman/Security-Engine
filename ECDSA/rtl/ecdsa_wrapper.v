module ecdsa_wrapper #
(
	// Users to add parameters here
	parameter integer message_width = 32,
	parameter integer key_size = 64,
	parameter integer integer_size = 64,
	// User parameters ends
	// Do not modify the parameters beyond this line

	// Width of S_AXI data bus
	parameter integer C_S_AXI_DATA_WIDTH	= 32,
	// Width of S_AXI address bus
	parameter integer C_S_AXI_ADDR_WIDTH	= 9
)
(
	// Users to add ports here

	// User ports ends
	// Do not modify the ports beyond this line

	// Global Clock Signal
	input wire  S_AXI_ACLK,
	// Global Reset Signal. This Signal is Active LOW
	input wire  S_AXI_ARESETN,
	// Write address (issued by master, acceped by Slave)
	input wire [C_S_AXI_ADDR_WIDTH-1 : 0] S_AXI_AWADDR,
	// Write channel Protection type. This signal indicates the
	// privilege and security level of the transaction, and whether
	// the transaction is a data access or an instruction access.
	input wire [2 : 0] S_AXI_AWPROT,
	// Write address valid. This signal indicates that the master signaling
	// valid write address and control information.
	input wire  S_AXI_AWVALID,
	// Write address ready. This signal indicates that the slave is ready
	// to accept an address and associated control signals.
	output wire  S_AXI_AWREADY,
	// Write data (issued by master, acceped by Slave) 
	input wire [C_S_AXI_DATA_WIDTH-1 : 0] S_AXI_WDATA,
	// Write strobes. This signal indicates which byte lanes hold
	// valid data. There is one write strobe bit for each eight
	// bits of the write data bus.    
	input wire [(C_S_AXI_DATA_WIDTH/8)-1 : 0] S_AXI_WSTRB,
	// Write valid. This signal indicates that valid write
	// data and strobes are available.
	input wire  S_AXI_WVALID,
	// Write ready. This signal indicates that the slave
	// can accept the write data.
	output wire  S_AXI_WREADY,
	// Write response. This signal indicates the status
	// of the write transaction.
	output wire [1 : 0] S_AXI_BRESP,
	// Write response valid. This signal indicates that the channel
	// is signaling a valid write response.
	output wire  S_AXI_BVALID,
	// Response ready. This signal indicates that the master
	// can accept a write response.
	input wire  S_AXI_BREADY,
	// Read address (issued by master, acceped by Slave)
	input wire [C_S_AXI_ADDR_WIDTH-1 : 0] S_AXI_ARADDR,
	// Protection type. This signal indicates the privilege
	// and security level of the transaction, and whether the
	// transaction is a data access or an instruction access.
	input wire [2 : 0] S_AXI_ARPROT,
	// Read address valid. This signal indicates that the channel
	// is signaling valid read address and control information.
	input wire  S_AXI_ARVALID,
	// Read address ready. This signal indicates that the slave is
	// ready to accept an address and associated control signals.
	output wire  S_AXI_ARREADY,
	// Read data (issued by slave)
	output wire [C_S_AXI_DATA_WIDTH-1 : 0] S_AXI_RDATA,
	// Read response. This signal indicates the status of the
	// read transfer.
	output wire [1 : 0] S_AXI_RRESP,
	// Read valid. This signal indicates that the channel is
	// signaling the required read data.
	output wire  S_AXI_RVALID,
	// Read ready. This signal indicates that the master can
	// accept the read data and response information.
	input wire  S_AXI_RREADY
);

wire ecc_go, sign_go, verify_go;
wire[message_width-1 : 0] message, hashedMessage, trng; 
wire sign_ready, verify_ready, verified, failure, infiityPPubKey;
wire ecc_done, sign_done, verify_done; 
wire [integer_size-1:0] prime, A, B, Gx, Gy, n, Ox,Oy;
wire [key_size-1:0] r_sign, s_sign, verifying_r, verifying_s, privateKey;

// AXI4LITE signals
reg [C_S_AXI_ADDR_WIDTH-1 : 0] 	axi_awaddr;
reg  	axi_awready;
reg  	axi_wready;
reg [1 : 0] 	axi_bresp;
reg  	axi_bvalid;
reg [C_S_AXI_ADDR_WIDTH-1 : 0] 	axi_araddr;
reg  	axi_arready;
reg [C_S_AXI_DATA_WIDTH-1 : 0] 	axi_rdata;
reg [1 : 0] 	axi_rresp;
reg  	axi_rvalid;

// Example-specific design signals
// local parameter for addressing 32 bit / 64 bit C_S_AXI_DATA_WIDTH
// ADDR_LSB is used for addressing 32/64 bit registers/memories
// ADDR_LSB = 2 for 32 bits (n downto 2)
// ADDR_LSB = 3 for 64 bits (n downto 3)
localparam integer ADDR_LSB = (C_S_AXI_DATA_WIDTH/32) + 1;
localparam integer OPT_MEM_ADDR_BITS = 6;
//----------------------------------------------
//-- Signals for user logic register space example
//------------------------------------------------
//-- Number of Slave Registers 115
reg [C_S_AXI_DATA_WIDTH-1:0]	slv_reg0;
reg [C_S_AXI_DATA_WIDTH-1:0]	slv_reg1;
reg [C_S_AXI_DATA_WIDTH-1:0]	slv_reg2;
reg [C_S_AXI_DATA_WIDTH-1:0]	slv_reg3;
reg [C_S_AXI_DATA_WIDTH-1:0]	slv_reg4;
reg [C_S_AXI_DATA_WIDTH-1:0]	slv_reg5;
reg [C_S_AXI_DATA_WIDTH-1:0]	slv_reg6;
reg [C_S_AXI_DATA_WIDTH-1:0]	slv_reg7;
reg [C_S_AXI_DATA_WIDTH-1:0]	slv_reg8;
reg [C_S_AXI_DATA_WIDTH-1:0]	slv_reg9;
reg [C_S_AXI_DATA_WIDTH-1:0]	slv_reg10;
reg [C_S_AXI_DATA_WIDTH-1:0]	slv_reg11;
reg [C_S_AXI_DATA_WIDTH-1:0]	slv_reg12;
reg [C_S_AXI_DATA_WIDTH-1:0]	slv_reg13;
reg [C_S_AXI_DATA_WIDTH-1:0]	slv_reg14;
reg [C_S_AXI_DATA_WIDTH-1:0]	slv_reg15;
reg [C_S_AXI_DATA_WIDTH-1:0]	slv_reg16;
reg [C_S_AXI_DATA_WIDTH-1:0]	slv_reg17;
reg [C_S_AXI_DATA_WIDTH-1:0]	slv_reg18;
reg [C_S_AXI_DATA_WIDTH-1:0]	slv_reg19;
reg [C_S_AXI_DATA_WIDTH-1:0]	slv_reg20;
reg [C_S_AXI_DATA_WIDTH-1:0]	slv_reg21;
reg [C_S_AXI_DATA_WIDTH-1:0]	slv_reg22;
reg [C_S_AXI_DATA_WIDTH-1:0]	slv_reg23;
reg [C_S_AXI_DATA_WIDTH-1:0]	slv_reg24;
reg [C_S_AXI_DATA_WIDTH-1:0]	slv_reg25;
reg [C_S_AXI_DATA_WIDTH-1:0]	slv_reg26;
reg [C_S_AXI_DATA_WIDTH-1:0]	slv_reg27;
reg [C_S_AXI_DATA_WIDTH-1:0]	slv_reg28;
reg [C_S_AXI_DATA_WIDTH-1:0]	slv_reg29;
reg [C_S_AXI_DATA_WIDTH-1:0]	slv_reg30;
reg [C_S_AXI_DATA_WIDTH-1:0]	slv_reg31;
reg [C_S_AXI_DATA_WIDTH-1:0]	slv_reg32;
reg [C_S_AXI_DATA_WIDTH-1:0]	slv_reg33;
reg [C_S_AXI_DATA_WIDTH-1:0]	slv_reg34;
reg [C_S_AXI_DATA_WIDTH-1:0]	slv_reg35;
reg [C_S_AXI_DATA_WIDTH-1:0]	slv_reg36;
reg [C_S_AXI_DATA_WIDTH-1:0]	slv_reg37;
reg [C_S_AXI_DATA_WIDTH-1:0]	slv_reg38;
reg [C_S_AXI_DATA_WIDTH-1:0]	slv_reg39;
reg [C_S_AXI_DATA_WIDTH-1:0]	slv_reg40;
reg [C_S_AXI_DATA_WIDTH-1:0]	slv_reg41;
reg [C_S_AXI_DATA_WIDTH-1:0]	slv_reg42;
reg [C_S_AXI_DATA_WIDTH-1:0]	slv_reg43;
reg [C_S_AXI_DATA_WIDTH-1:0]	slv_reg44;
reg [C_S_AXI_DATA_WIDTH-1:0]	slv_reg45;
reg [C_S_AXI_DATA_WIDTH-1:0]	slv_reg46;
reg [C_S_AXI_DATA_WIDTH-1:0]	slv_reg47;
reg [C_S_AXI_DATA_WIDTH-1:0]	slv_reg48;
reg [C_S_AXI_DATA_WIDTH-1:0]	slv_reg49;
reg [C_S_AXI_DATA_WIDTH-1:0]	slv_reg50;
reg [C_S_AXI_DATA_WIDTH-1:0]	slv_reg51;
reg [C_S_AXI_DATA_WIDTH-1:0]	slv_reg52;
reg [C_S_AXI_DATA_WIDTH-1:0]	slv_reg53;
reg [C_S_AXI_DATA_WIDTH-1:0]	slv_reg54;
reg [C_S_AXI_DATA_WIDTH-1:0]	slv_reg55;
reg [C_S_AXI_DATA_WIDTH-1:0]	slv_reg56;
reg [C_S_AXI_DATA_WIDTH-1:0]	slv_reg57;
reg [C_S_AXI_DATA_WIDTH-1:0]	slv_reg58;
reg [C_S_AXI_DATA_WIDTH-1:0]	slv_reg59;
reg [C_S_AXI_DATA_WIDTH-1:0]	slv_reg60;
reg [C_S_AXI_DATA_WIDTH-1:0]	slv_reg61;
reg [C_S_AXI_DATA_WIDTH-1:0]	slv_reg62;
reg [C_S_AXI_DATA_WIDTH-1:0]	slv_reg63;
reg [C_S_AXI_DATA_WIDTH-1:0]	slv_reg64;
reg [C_S_AXI_DATA_WIDTH-1:0]	slv_reg65;
reg [C_S_AXI_DATA_WIDTH-1:0]	slv_reg66;
reg [C_S_AXI_DATA_WIDTH-1:0]	slv_reg67;
reg [C_S_AXI_DATA_WIDTH-1:0]	slv_reg68;
reg [C_S_AXI_DATA_WIDTH-1:0]	slv_reg69;
reg [C_S_AXI_DATA_WIDTH-1:0]	slv_reg70;
reg [C_S_AXI_DATA_WIDTH-1:0]	slv_reg71;
reg [C_S_AXI_DATA_WIDTH-1:0]	slv_reg72;
reg [C_S_AXI_DATA_WIDTH-1:0]	slv_reg73;
reg [C_S_AXI_DATA_WIDTH-1:0]	slv_reg74;
reg [C_S_AXI_DATA_WIDTH-1:0]	slv_reg75;
reg [C_S_AXI_DATA_WIDTH-1:0]	slv_reg76;
reg [C_S_AXI_DATA_WIDTH-1:0]	slv_reg77;
reg [C_S_AXI_DATA_WIDTH-1:0]	slv_reg78;
reg [C_S_AXI_DATA_WIDTH-1:0]	slv_reg79;
reg [C_S_AXI_DATA_WIDTH-1:0]	slv_reg80;
reg [C_S_AXI_DATA_WIDTH-1:0]	slv_reg81;
reg [C_S_AXI_DATA_WIDTH-1:0]	slv_reg82;
reg [C_S_AXI_DATA_WIDTH-1:0]	slv_reg83;
reg [C_S_AXI_DATA_WIDTH-1:0]	slv_reg84;
reg [C_S_AXI_DATA_WIDTH-1:0]	slv_reg85;
reg [C_S_AXI_DATA_WIDTH-1:0]	slv_reg86;
reg [C_S_AXI_DATA_WIDTH-1:0]	slv_reg87;
reg [C_S_AXI_DATA_WIDTH-1:0]	slv_reg88;
reg [C_S_AXI_DATA_WIDTH-1:0]	slv_reg89;
reg [C_S_AXI_DATA_WIDTH-1:0]	slv_reg90;
reg [C_S_AXI_DATA_WIDTH-1:0]	slv_reg91;
reg [C_S_AXI_DATA_WIDTH-1:0]	slv_reg92;
reg [C_S_AXI_DATA_WIDTH-1:0]	slv_reg93;
reg [C_S_AXI_DATA_WIDTH-1:0]	slv_reg94;
reg [C_S_AXI_DATA_WIDTH-1:0]	slv_reg95;
reg [C_S_AXI_DATA_WIDTH-1:0]	slv_reg96;
reg [C_S_AXI_DATA_WIDTH-1:0]	slv_reg97;
reg [C_S_AXI_DATA_WIDTH-1:0]	slv_reg98;
reg [C_S_AXI_DATA_WIDTH-1:0]	slv_reg99;
reg [C_S_AXI_DATA_WIDTH-1:0]	slv_reg100;
reg [C_S_AXI_DATA_WIDTH-1:0]	slv_reg101;
reg [C_S_AXI_DATA_WIDTH-1:0]	slv_reg102;
reg [C_S_AXI_DATA_WIDTH-1:0]	slv_reg103;
reg [C_S_AXI_DATA_WIDTH-1:0]	slv_reg104;
reg [C_S_AXI_DATA_WIDTH-1:0]	slv_reg105;
reg [C_S_AXI_DATA_WIDTH-1:0]	slv_reg106;
reg [C_S_AXI_DATA_WIDTH-1:0]	slv_reg107;
reg [C_S_AXI_DATA_WIDTH-1:0]	slv_reg108;
reg [C_S_AXI_DATA_WIDTH-1:0]	slv_reg109;
reg [C_S_AXI_DATA_WIDTH-1:0]	slv_reg110;
reg [C_S_AXI_DATA_WIDTH-1:0]	slv_reg111;
reg [C_S_AXI_DATA_WIDTH-1:0]	slv_reg112;
reg [C_S_AXI_DATA_WIDTH-1:0]	slv_reg113;
reg [C_S_AXI_DATA_WIDTH-1:0]	slv_reg114;
wire	 slv_reg_rden;
wire	 slv_reg_wren;
reg [C_S_AXI_DATA_WIDTH-1:0]	 reg_data_out;
integer	 byte_index;
reg	 aw_en;

// I/O Connections assignments

assign S_AXI_AWREADY	= axi_awready;
assign S_AXI_WREADY	= axi_wready;
assign S_AXI_BRESP	= axi_bresp;
assign S_AXI_BVALID	= axi_bvalid;
assign S_AXI_ARREADY	= axi_arready;
assign S_AXI_RDATA	= axi_rdata;
assign S_AXI_RRESP	= axi_rresp;
assign S_AXI_RVALID	= axi_rvalid;
// Implement axi_awready generation
// axi_awready is asserted for one S_AXI_ACLK clock cycle when both
// S_AXI_AWVALID and S_AXI_WVALID are asserted. axi_awready is
// de-asserted when reset is low.

always @( posedge S_AXI_ACLK )
begin
  if ( S_AXI_ARESETN == 1'b0 )
    begin
      axi_awready <= 1'b0;
      aw_en <= 1'b1;
    end 
  else
    begin    
      //if (~axi_awready && S_AXI_AWVALID && S_AXI_WVALID && aw_en) // mash
      if (~axi_awready && S_AXI_AWVALID && aw_en)
        begin
          // slave is ready to accept write address when 
          // there is a valid write address and write data
          // on the write address and data bus. This design 
          // expects no outstanding transactions. 
          axi_awready <= 1'b1;
          aw_en <= 1'b0;
        end
        else if (S_AXI_BREADY && axi_bvalid)
            begin
              aw_en <= 1'b1;
              axi_awready <= 1'b0;
            end
      else           
        begin
          axi_awready <= 1'b0;
        end
    end 
end       

// Implement axi_awaddr latching
// This process is used to latch the address when both 
// S_AXI_AWVALID and S_AXI_WVALID are valid. 

always @( posedge S_AXI_ACLK )
begin
  if ( S_AXI_ARESETN == 1'b0 )
    begin
      axi_awaddr <= 0;
    end 
  else
    begin    
      //if (~axi_awready && S_AXI_AWVALID && S_AXI_WVALID && aw_en) // mash
      if (~axi_awready && S_AXI_AWVALID && aw_en)
        begin
          // Write Address latching 
          axi_awaddr <= S_AXI_AWADDR;
        end
    end 
end       

// Implement axi_wready generation
// axi_wready is asserted for one S_AXI_ACLK clock cycle when both
// S_AXI_AWVALID and S_AXI_WVALID are asserted. axi_wready is 
// de-asserted when reset is low. 

always @( posedge S_AXI_ACLK )
begin
  if ( S_AXI_ARESETN == 1'b0 )
    begin
      axi_wready <= 1'b0;
    end 
  else
    begin    
      //if (~axi_wready && S_AXI_WVALID && S_AXI_AWVALID && aw_en ) // mash
      if (~axi_wready && S_AXI_WVALID )
        begin
          // slave is ready to accept write data when 
          // there is a valid write address and write data
          // on the write address and data bus. This design 
          // expects no outstanding transactions. 
          axi_wready <= 1'b1;
        end
      else
        begin
          axi_wready <= 1'b0;
        end
    end 
end       

// Implement memory mapped register select and write logic generation
// The write data is accepted and written to memory mapped registers when
// axi_awready, S_AXI_WVALID, axi_wready and S_AXI_WVALID are asserted. Write strobes are used to
// select byte enables of slave registers while writing.
// These registers are cleared when reset (active low) is applied.
// Slave register write enable is asserted when valid address and data are available
// and the slave is ready to accept the write address and write data.
//assign slv_reg_wren = axi_wready && S_AXI_WVALID && axi_awready && S_AXI_AWVALID;  // mash
assign slv_reg_wren = axi_wready && S_AXI_WVALID; 

always @( posedge S_AXI_ACLK )
begin
  if ( S_AXI_ARESETN == 1'b0 )
    begin
      slv_reg0 <= 0;
      slv_reg1 <= 0;
      slv_reg2 <= 0;
      slv_reg3 <= 0;
      slv_reg4 <= 0;
      slv_reg5 <= 0;
      slv_reg6 <= 0;
      slv_reg7 <= 0;
      slv_reg8 <= 0;
      slv_reg9 <= 0;
      slv_reg10 <= 0;
      slv_reg11 <= 0;
      slv_reg12 <= 0;
      slv_reg13 <= 0;
      slv_reg14 <= 0;
      slv_reg15 <= 0;
      slv_reg16 <= 0;
      slv_reg17 <= 0;
      slv_reg18 <= 0;
      slv_reg19 <= 0;
      slv_reg20 <= 0;
      slv_reg21 <= 0;
      slv_reg22 <= 0;
      slv_reg23 <= 0;
      slv_reg24 <= 0;
      slv_reg25 <= 0;
      slv_reg26 <= 0;
      slv_reg27 <= 0;
      slv_reg28 <= 0;
      slv_reg29 <= 0;
      slv_reg30 <= 0;
      slv_reg31 <= 0;
      slv_reg32 <= 0;
      slv_reg33 <= 0;
      slv_reg34 <= 0;
      slv_reg35 <= 0;
      slv_reg36 <= 0;
      slv_reg37 <= 0;
      slv_reg38 <= 0;
      slv_reg39 <= 0;
      slv_reg40 <= 0;
      slv_reg41 <= 0;
      slv_reg42 <= 0;
      slv_reg43 <= 0;
      slv_reg44 <= 0;
      slv_reg45 <= 0;
      slv_reg46 <= 0;
      slv_reg47 <= 0;
      slv_reg48 <= 0;
      slv_reg49 <= 0;
      slv_reg50 <= 0;
      slv_reg51 <= 0;
      slv_reg52 <= 0;
      slv_reg53 <= 0;
      slv_reg54 <= 0;
      slv_reg55 <= 0;
      slv_reg56 <= 0;
      slv_reg57 <= 0;
      slv_reg58 <= 0;
      slv_reg59 <= 0;
      slv_reg60 <= 0;
      slv_reg61 <= 0;
      slv_reg62 <= 0;
      slv_reg63 <= 0;
      slv_reg64 <= 0;
      slv_reg65 <= 0;
      slv_reg66 <= 0;
      slv_reg67 <= 0;
      slv_reg68 <= 0;
      slv_reg69 <= 0;
      slv_reg70 <= 0;
      slv_reg71 <= 0;
      slv_reg72 <= 0;
      slv_reg73 <= 0;
      slv_reg74 <= 0;
      slv_reg75 <= 0;
      slv_reg76 <= 0;
      slv_reg77 <= 0;
      slv_reg78 <= 0;
      slv_reg79 <= 0;
      slv_reg80 <= 0;
      slv_reg81 <= 0;
      slv_reg82 <= 0;
      slv_reg83 <= 0;
      slv_reg84 <= 0;
      slv_reg85 <= 0;
      slv_reg86 <= 0;
      slv_reg87 <= 0;
      slv_reg88 <= 0;
      slv_reg89 <= 0;
      slv_reg90 <= 0;
      slv_reg91 <= 0;
      slv_reg92 <= 0;
      slv_reg93 <= 0;
      slv_reg94 <= 0;
      slv_reg95 <= 0;
      slv_reg96 <= 0;
      slv_reg97 <= 0;
      slv_reg98 <= 0;
      slv_reg99 <= 0;
      slv_reg100 <= 0;
      slv_reg101 <= 0;
      slv_reg102 <= 0;
      slv_reg103 <= 0;
      slv_reg104 <= 0;
      slv_reg105 <= 0;
      slv_reg106 <= 0;
      slv_reg107 <= 0;
      slv_reg108 <= 0;
      slv_reg109 <= 0;
      slv_reg110 <= 0;
      slv_reg111 <= 0;
      slv_reg112 <= 0;
      slv_reg113 <= 0;
      slv_reg114 <= 0;
    end 
  else begin
    if (slv_reg_wren)
      begin
        case ( axi_awaddr[ADDR_LSB+OPT_MEM_ADDR_BITS:ADDR_LSB] )
          7'h00:
            for ( byte_index = 0; byte_index <= (C_S_AXI_DATA_WIDTH/8)-1; byte_index = byte_index+1 )
              if ( S_AXI_WSTRB[byte_index] == 1 ) begin
                // Respective byte enables are asserted as per write strobes 
                // Slave register 0
                slv_reg0[(byte_index*8) +: 8] <= S_AXI_WDATA[(byte_index*8) +: 8];
              end  
          7'h01:
            for ( byte_index = 0; byte_index <= (C_S_AXI_DATA_WIDTH/8)-1; byte_index = byte_index+1 )
              if ( S_AXI_WSTRB[byte_index] == 1 ) begin
                // Respective byte enables are asserted as per write strobes 
                // Slave register 1
                slv_reg1[(byte_index*8) +: 8] <= S_AXI_WDATA[(byte_index*8) +: 8];
              end  
          7'h02:
            for ( byte_index = 0; byte_index <= (C_S_AXI_DATA_WIDTH/8)-1; byte_index = byte_index+1 )
              if ( S_AXI_WSTRB[byte_index] == 1 ) begin
                // Respective byte enables are asserted as per write strobes 
                // Slave register 2
                slv_reg2[(byte_index*8) +: 8] <= S_AXI_WDATA[(byte_index*8) +: 8];
              end  
          7'h03:
            for ( byte_index = 0; byte_index <= (C_S_AXI_DATA_WIDTH/8)-1; byte_index = byte_index+1 )
              if ( S_AXI_WSTRB[byte_index] == 1 ) begin
                // Respective byte enables are asserted as per write strobes 
                // Slave register 3
                slv_reg3[(byte_index*8) +: 8] <= S_AXI_WDATA[(byte_index*8) +: 8];
              end  
          7'h04:
            for ( byte_index = 0; byte_index <= (C_S_AXI_DATA_WIDTH/8)-1; byte_index = byte_index+1 )
              if ( S_AXI_WSTRB[byte_index] == 1 ) begin
                // Respective byte enables are asserted as per write strobes 
                // Slave register 4
                slv_reg4[(byte_index*8) +: 8] <= S_AXI_WDATA[(byte_index*8) +: 8];
              end  
          7'h05:
            for ( byte_index = 0; byte_index <= (C_S_AXI_DATA_WIDTH/8)-1; byte_index = byte_index+1 )
              if ( S_AXI_WSTRB[byte_index] == 1 ) begin
                // Respective byte enables are asserted as per write strobes 
                // Slave register 5
                slv_reg5[(byte_index*8) +: 8] <= S_AXI_WDATA[(byte_index*8) +: 8];
              end  
          7'h06:
            for ( byte_index = 0; byte_index <= (C_S_AXI_DATA_WIDTH/8)-1; byte_index = byte_index+1 )
              if ( S_AXI_WSTRB[byte_index] == 1 ) begin
                // Respective byte enables are asserted as per write strobes 
                // Slave register 6
                slv_reg6[(byte_index*8) +: 8] <= S_AXI_WDATA[(byte_index*8) +: 8];
              end  
          7'h07:
            for ( byte_index = 0; byte_index <= (C_S_AXI_DATA_WIDTH/8)-1; byte_index = byte_index+1 )
              if ( S_AXI_WSTRB[byte_index] == 1 ) begin
                // Respective byte enables are asserted as per write strobes 
                // Slave register 7
                slv_reg7[(byte_index*8) +: 8] <= S_AXI_WDATA[(byte_index*8) +: 8];
              end  
          7'h08:
            for ( byte_index = 0; byte_index <= (C_S_AXI_DATA_WIDTH/8)-1; byte_index = byte_index+1 )
              if ( S_AXI_WSTRB[byte_index] == 1 ) begin
                // Respective byte enables are asserted as per write strobes 
                // Slave register 8
                slv_reg8[(byte_index*8) +: 8] <= S_AXI_WDATA[(byte_index*8) +: 8];
              end  
          7'h09:
            for ( byte_index = 0; byte_index <= (C_S_AXI_DATA_WIDTH/8)-1; byte_index = byte_index+1 )
              if ( S_AXI_WSTRB[byte_index] == 1 ) begin
                // Respective byte enables are asserted as per write strobes 
                // Slave register 9
                slv_reg9[(byte_index*8) +: 8] <= S_AXI_WDATA[(byte_index*8) +: 8];
              end  
          7'h0A:
            for ( byte_index = 0; byte_index <= (C_S_AXI_DATA_WIDTH/8)-1; byte_index = byte_index+1 )
              if ( S_AXI_WSTRB[byte_index] == 1 ) begin
                // Respective byte enables are asserted as per write strobes 
                // Slave register 10
                slv_reg10[(byte_index*8) +: 8] <= S_AXI_WDATA[(byte_index*8) +: 8];
              end  
          7'h0B:
            for ( byte_index = 0; byte_index <= (C_S_AXI_DATA_WIDTH/8)-1; byte_index = byte_index+1 )
              if ( S_AXI_WSTRB[byte_index] == 1 ) begin
                // Respective byte enables are asserted as per write strobes 
                // Slave register 11
                slv_reg11[(byte_index*8) +: 8] <= S_AXI_WDATA[(byte_index*8) +: 8];
              end  
          7'h0C:
            for ( byte_index = 0; byte_index <= (C_S_AXI_DATA_WIDTH/8)-1; byte_index = byte_index+1 )
              if ( S_AXI_WSTRB[byte_index] == 1 ) begin
                // Respective byte enables are asserted as per write strobes 
                // Slave register 12
                slv_reg12[(byte_index*8) +: 8] <= S_AXI_WDATA[(byte_index*8) +: 8];
              end  
          7'h0D:
            for ( byte_index = 0; byte_index <= (C_S_AXI_DATA_WIDTH/8)-1; byte_index = byte_index+1 )
              if ( S_AXI_WSTRB[byte_index] == 1 ) begin
                // Respective byte enables are asserted as per write strobes 
                // Slave register 13
                slv_reg13[(byte_index*8) +: 8] <= S_AXI_WDATA[(byte_index*8) +: 8];
              end  
          7'h0E:
            for ( byte_index = 0; byte_index <= (C_S_AXI_DATA_WIDTH/8)-1; byte_index = byte_index+1 )
              if ( S_AXI_WSTRB[byte_index] == 1 ) begin
                // Respective byte enables are asserted as per write strobes 
                // Slave register 14
                slv_reg14[(byte_index*8) +: 8] <= S_AXI_WDATA[(byte_index*8) +: 8];
              end  
          7'h0F:
            for ( byte_index = 0; byte_index <= (C_S_AXI_DATA_WIDTH/8)-1; byte_index = byte_index+1 )
              if ( S_AXI_WSTRB[byte_index] == 1 ) begin
                // Respective byte enables are asserted as per write strobes 
                // Slave register 15
                slv_reg15[(byte_index*8) +: 8] <= S_AXI_WDATA[(byte_index*8) +: 8];
              end  
          7'h10:
            for ( byte_index = 0; byte_index <= (C_S_AXI_DATA_WIDTH/8)-1; byte_index = byte_index+1 )
              if ( S_AXI_WSTRB[byte_index] == 1 ) begin
                // Respective byte enables are asserted as per write strobes 
                // Slave register 16
                slv_reg16[(byte_index*8) +: 8] <= S_AXI_WDATA[(byte_index*8) +: 8];
              end  
          7'h11:
            for ( byte_index = 0; byte_index <= (C_S_AXI_DATA_WIDTH/8)-1; byte_index = byte_index+1 )
              if ( S_AXI_WSTRB[byte_index] == 1 ) begin
                // Respective byte enables are asserted as per write strobes 
                // Slave register 17
                slv_reg17[(byte_index*8) +: 8] <= S_AXI_WDATA[(byte_index*8) +: 8];
              end  
          7'h12:
            for ( byte_index = 0; byte_index <= (C_S_AXI_DATA_WIDTH/8)-1; byte_index = byte_index+1 )
              if ( S_AXI_WSTRB[byte_index] == 1 ) begin
                // Respective byte enables are asserted as per write strobes 
                // Slave register 18
                slv_reg18[(byte_index*8) +: 8] <= S_AXI_WDATA[(byte_index*8) +: 8];
              end  
          7'h13:
            for ( byte_index = 0; byte_index <= (C_S_AXI_DATA_WIDTH/8)-1; byte_index = byte_index+1 )
              if ( S_AXI_WSTRB[byte_index] == 1 ) begin
                // Respective byte enables are asserted as per write strobes 
                // Slave register 19
                slv_reg19[(byte_index*8) +: 8] <= S_AXI_WDATA[(byte_index*8) +: 8];
              end  
          7'h14:
            for ( byte_index = 0; byte_index <= (C_S_AXI_DATA_WIDTH/8)-1; byte_index = byte_index+1 )
              if ( S_AXI_WSTRB[byte_index] == 1 ) begin
                // Respective byte enables are asserted as per write strobes 
                // Slave register 20
                slv_reg20[(byte_index*8) +: 8] <= S_AXI_WDATA[(byte_index*8) +: 8];
              end  
          7'h15:
            for ( byte_index = 0; byte_index <= (C_S_AXI_DATA_WIDTH/8)-1; byte_index = byte_index+1 )
              if ( S_AXI_WSTRB[byte_index] == 1 ) begin
                // Respective byte enables are asserted as per write strobes 
                // Slave register 21
                slv_reg21[(byte_index*8) +: 8] <= S_AXI_WDATA[(byte_index*8) +: 8];
              end  
          7'h16:
            for ( byte_index = 0; byte_index <= (C_S_AXI_DATA_WIDTH/8)-1; byte_index = byte_index+1 )
              if ( S_AXI_WSTRB[byte_index] == 1 ) begin
                // Respective byte enables are asserted as per write strobes 
                // Slave register 22
                slv_reg22[(byte_index*8) +: 8] <= S_AXI_WDATA[(byte_index*8) +: 8];
              end  
          7'h17:
            for ( byte_index = 0; byte_index <= (C_S_AXI_DATA_WIDTH/8)-1; byte_index = byte_index+1 )
              if ( S_AXI_WSTRB[byte_index] == 1 ) begin
                // Respective byte enables are asserted as per write strobes 
                // Slave register 23
                slv_reg23[(byte_index*8) +: 8] <= S_AXI_WDATA[(byte_index*8) +: 8];
              end  
          7'h18:
            for ( byte_index = 0; byte_index <= (C_S_AXI_DATA_WIDTH/8)-1; byte_index = byte_index+1 )
              if ( S_AXI_WSTRB[byte_index] == 1 ) begin
                // Respective byte enables are asserted as per write strobes 
                // Slave register 24
                slv_reg24[(byte_index*8) +: 8] <= S_AXI_WDATA[(byte_index*8) +: 8];
              end  
          7'h19:
            for ( byte_index = 0; byte_index <= (C_S_AXI_DATA_WIDTH/8)-1; byte_index = byte_index+1 )
              if ( S_AXI_WSTRB[byte_index] == 1 ) begin
                // Respective byte enables are asserted as per write strobes 
                // Slave register 25
                slv_reg25[(byte_index*8) +: 8] <= S_AXI_WDATA[(byte_index*8) +: 8];
              end  
          7'h1A:
            for ( byte_index = 0; byte_index <= (C_S_AXI_DATA_WIDTH/8)-1; byte_index = byte_index+1 )
              if ( S_AXI_WSTRB[byte_index] == 1 ) begin
                // Respective byte enables are asserted as per write strobes 
                // Slave register 26
                slv_reg26[(byte_index*8) +: 8] <= S_AXI_WDATA[(byte_index*8) +: 8];
              end  
          7'h1B:
            for ( byte_index = 0; byte_index <= (C_S_AXI_DATA_WIDTH/8)-1; byte_index = byte_index+1 )
              if ( S_AXI_WSTRB[byte_index] == 1 ) begin
                // Respective byte enables are asserted as per write strobes 
                // Slave register 27
                slv_reg27[(byte_index*8) +: 8] <= S_AXI_WDATA[(byte_index*8) +: 8];
              end  
          7'h1C:
            for ( byte_index = 0; byte_index <= (C_S_AXI_DATA_WIDTH/8)-1; byte_index = byte_index+1 )
              if ( S_AXI_WSTRB[byte_index] == 1 ) begin
                // Respective byte enables are asserted as per write strobes 
                // Slave register 28
                slv_reg28[(byte_index*8) +: 8] <= S_AXI_WDATA[(byte_index*8) +: 8];
              end  
          7'h1D:
            for ( byte_index = 0; byte_index <= (C_S_AXI_DATA_WIDTH/8)-1; byte_index = byte_index+1 )
              if ( S_AXI_WSTRB[byte_index] == 1 ) begin
                // Respective byte enables are asserted as per write strobes 
                // Slave register 29
                slv_reg29[(byte_index*8) +: 8] <= S_AXI_WDATA[(byte_index*8) +: 8];
              end  
          7'h1E:
            for ( byte_index = 0; byte_index <= (C_S_AXI_DATA_WIDTH/8)-1; byte_index = byte_index+1 )
              if ( S_AXI_WSTRB[byte_index] == 1 ) begin
                // Respective byte enables are asserted as per write strobes 
                // Slave register 30
                slv_reg30[(byte_index*8) +: 8] <= S_AXI_WDATA[(byte_index*8) +: 8];
              end  
          7'h1F:
            for ( byte_index = 0; byte_index <= (C_S_AXI_DATA_WIDTH/8)-1; byte_index = byte_index+1 )
              if ( S_AXI_WSTRB[byte_index] == 1 ) begin
                // Respective byte enables are asserted as per write strobes 
                // Slave register 31
                slv_reg31[(byte_index*8) +: 8] <= S_AXI_WDATA[(byte_index*8) +: 8];
              end  
          7'h20:
            for ( byte_index = 0; byte_index <= (C_S_AXI_DATA_WIDTH/8)-1; byte_index = byte_index+1 )
              if ( S_AXI_WSTRB[byte_index] == 1 ) begin
                // Respective byte enables are asserted as per write strobes 
                // Slave register 32
                slv_reg32[(byte_index*8) +: 8] <= S_AXI_WDATA[(byte_index*8) +: 8];
              end  
          7'h21:
            for ( byte_index = 0; byte_index <= (C_S_AXI_DATA_WIDTH/8)-1; byte_index = byte_index+1 )
              if ( S_AXI_WSTRB[byte_index] == 1 ) begin
                // Respective byte enables are asserted as per write strobes 
                // Slave register 33
                slv_reg33[(byte_index*8) +: 8] <= S_AXI_WDATA[(byte_index*8) +: 8];
              end  
          7'h22:
            for ( byte_index = 0; byte_index <= (C_S_AXI_DATA_WIDTH/8)-1; byte_index = byte_index+1 )
              if ( S_AXI_WSTRB[byte_index] == 1 ) begin
                // Respective byte enables are asserted as per write strobes 
                // Slave register 34
                slv_reg34[(byte_index*8) +: 8] <= S_AXI_WDATA[(byte_index*8) +: 8];
              end  
          7'h23:
            for ( byte_index = 0; byte_index <= (C_S_AXI_DATA_WIDTH/8)-1; byte_index = byte_index+1 )
              if ( S_AXI_WSTRB[byte_index] == 1 ) begin
                // Respective byte enables are asserted as per write strobes 
                // Slave register 35
                slv_reg35[(byte_index*8) +: 8] <= S_AXI_WDATA[(byte_index*8) +: 8];
              end  
          7'h24:
            for ( byte_index = 0; byte_index <= (C_S_AXI_DATA_WIDTH/8)-1; byte_index = byte_index+1 )
              if ( S_AXI_WSTRB[byte_index] == 1 ) begin
                // Respective byte enables are asserted as per write strobes 
                // Slave register 36
                slv_reg36[(byte_index*8) +: 8] <= S_AXI_WDATA[(byte_index*8) +: 8];
              end  
          7'h25:
            for ( byte_index = 0; byte_index <= (C_S_AXI_DATA_WIDTH/8)-1; byte_index = byte_index+1 )
              if ( S_AXI_WSTRB[byte_index] == 1 ) begin
                // Respective byte enables are asserted as per write strobes 
                // Slave register 37
                slv_reg37[(byte_index*8) +: 8] <= S_AXI_WDATA[(byte_index*8) +: 8];
              end  
          7'h26:
            for ( byte_index = 0; byte_index <= (C_S_AXI_DATA_WIDTH/8)-1; byte_index = byte_index+1 )
              if ( S_AXI_WSTRB[byte_index] == 1 ) begin
                // Respective byte enables are asserted as per write strobes 
                // Slave register 38
                slv_reg38[(byte_index*8) +: 8] <= S_AXI_WDATA[(byte_index*8) +: 8];
              end  
          7'h27:
            for ( byte_index = 0; byte_index <= (C_S_AXI_DATA_WIDTH/8)-1; byte_index = byte_index+1 )
              if ( S_AXI_WSTRB[byte_index] == 1 ) begin
                // Respective byte enables are asserted as per write strobes 
                // Slave register 39
                slv_reg39[(byte_index*8) +: 8] <= S_AXI_WDATA[(byte_index*8) +: 8];
              end  
          7'h28:
            for ( byte_index = 0; byte_index <= (C_S_AXI_DATA_WIDTH/8)-1; byte_index = byte_index+1 )
              if ( S_AXI_WSTRB[byte_index] == 1 ) begin
                // Respective byte enables are asserted as per write strobes 
                // Slave register 40
                slv_reg40[(byte_index*8) +: 8] <= S_AXI_WDATA[(byte_index*8) +: 8];
              end  
          7'h29:
            for ( byte_index = 0; byte_index <= (C_S_AXI_DATA_WIDTH/8)-1; byte_index = byte_index+1 )
              if ( S_AXI_WSTRB[byte_index] == 1 ) begin
                // Respective byte enables are asserted as per write strobes 
                // Slave register 41
                slv_reg41[(byte_index*8) +: 8] <= S_AXI_WDATA[(byte_index*8) +: 8];
              end  
          7'h2A:
            for ( byte_index = 0; byte_index <= (C_S_AXI_DATA_WIDTH/8)-1; byte_index = byte_index+1 )
              if ( S_AXI_WSTRB[byte_index] == 1 ) begin
                // Respective byte enables are asserted as per write strobes 
                // Slave register 42
                slv_reg42[(byte_index*8) +: 8] <= S_AXI_WDATA[(byte_index*8) +: 8];
              end  
          7'h2B:
            for ( byte_index = 0; byte_index <= (C_S_AXI_DATA_WIDTH/8)-1; byte_index = byte_index+1 )
              if ( S_AXI_WSTRB[byte_index] == 1 ) begin
                // Respective byte enables are asserted as per write strobes 
                // Slave register 43
                slv_reg43[(byte_index*8) +: 8] <= S_AXI_WDATA[(byte_index*8) +: 8];
              end  
          7'h2C:
            for ( byte_index = 0; byte_index <= (C_S_AXI_DATA_WIDTH/8)-1; byte_index = byte_index+1 )
              if ( S_AXI_WSTRB[byte_index] == 1 ) begin
                // Respective byte enables are asserted as per write strobes 
                // Slave register 44
                slv_reg44[(byte_index*8) +: 8] <= S_AXI_WDATA[(byte_index*8) +: 8];
              end  
          7'h2D:
            for ( byte_index = 0; byte_index <= (C_S_AXI_DATA_WIDTH/8)-1; byte_index = byte_index+1 )
              if ( S_AXI_WSTRB[byte_index] == 1 ) begin
                // Respective byte enables are asserted as per write strobes 
                // Slave register 45
                slv_reg45[(byte_index*8) +: 8] <= S_AXI_WDATA[(byte_index*8) +: 8];
              end  
          7'h2E:
            for ( byte_index = 0; byte_index <= (C_S_AXI_DATA_WIDTH/8)-1; byte_index = byte_index+1 )
              if ( S_AXI_WSTRB[byte_index] == 1 ) begin
                // Respective byte enables are asserted as per write strobes 
                // Slave register 46
                slv_reg46[(byte_index*8) +: 8] <= S_AXI_WDATA[(byte_index*8) +: 8];
              end  
          7'h2F:
            for ( byte_index = 0; byte_index <= (C_S_AXI_DATA_WIDTH/8)-1; byte_index = byte_index+1 )
              if ( S_AXI_WSTRB[byte_index] == 1 ) begin
                // Respective byte enables are asserted as per write strobes 
                // Slave register 47
                slv_reg47[(byte_index*8) +: 8] <= S_AXI_WDATA[(byte_index*8) +: 8];
              end  
          7'h30:
            for ( byte_index = 0; byte_index <= (C_S_AXI_DATA_WIDTH/8)-1; byte_index = byte_index+1 )
              if ( S_AXI_WSTRB[byte_index] == 1 ) begin
                // Respective byte enables are asserted as per write strobes 
                // Slave register 48
                slv_reg48[(byte_index*8) +: 8] <= S_AXI_WDATA[(byte_index*8) +: 8];
              end  
          7'h31:
            for ( byte_index = 0; byte_index <= (C_S_AXI_DATA_WIDTH/8)-1; byte_index = byte_index+1 )
              if ( S_AXI_WSTRB[byte_index] == 1 ) begin
                // Respective byte enables are asserted as per write strobes 
                // Slave register 49
                slv_reg49[(byte_index*8) +: 8] <= S_AXI_WDATA[(byte_index*8) +: 8];
              end  
          7'h32:
            for ( byte_index = 0; byte_index <= (C_S_AXI_DATA_WIDTH/8)-1; byte_index = byte_index+1 )
              if ( S_AXI_WSTRB[byte_index] == 1 ) begin
                // Respective byte enables are asserted as per write strobes 
                // Slave register 50
                slv_reg50[(byte_index*8) +: 8] <= S_AXI_WDATA[(byte_index*8) +: 8];
              end  
          7'h33:
            for ( byte_index = 0; byte_index <= (C_S_AXI_DATA_WIDTH/8)-1; byte_index = byte_index+1 )
              if ( S_AXI_WSTRB[byte_index] == 1 ) begin
                // Respective byte enables are asserted as per write strobes 
                // Slave register 51
                slv_reg51[(byte_index*8) +: 8] <= S_AXI_WDATA[(byte_index*8) +: 8];
              end  
          7'h34:
            for ( byte_index = 0; byte_index <= (C_S_AXI_DATA_WIDTH/8)-1; byte_index = byte_index+1 )
              if ( S_AXI_WSTRB[byte_index] == 1 ) begin
                // Respective byte enables are asserted as per write strobes 
                // Slave register 52
                slv_reg52[(byte_index*8) +: 8] <= S_AXI_WDATA[(byte_index*8) +: 8];
              end  
          7'h35:
            for ( byte_index = 0; byte_index <= (C_S_AXI_DATA_WIDTH/8)-1; byte_index = byte_index+1 )
              if ( S_AXI_WSTRB[byte_index] == 1 ) begin
                // Respective byte enables are asserted as per write strobes 
                // Slave register 53
                slv_reg53[(byte_index*8) +: 8] <= S_AXI_WDATA[(byte_index*8) +: 8];
              end  
          7'h36:
            for ( byte_index = 0; byte_index <= (C_S_AXI_DATA_WIDTH/8)-1; byte_index = byte_index+1 )
              if ( S_AXI_WSTRB[byte_index] == 1 ) begin
                // Respective byte enables are asserted as per write strobes 
                // Slave register 54
                slv_reg54[(byte_index*8) +: 8] <= S_AXI_WDATA[(byte_index*8) +: 8];
              end  
          7'h37:
            for ( byte_index = 0; byte_index <= (C_S_AXI_DATA_WIDTH/8)-1; byte_index = byte_index+1 )
              if ( S_AXI_WSTRB[byte_index] == 1 ) begin
                // Respective byte enables are asserted as per write strobes 
                // Slave register 55
                slv_reg55[(byte_index*8) +: 8] <= S_AXI_WDATA[(byte_index*8) +: 8];
              end  
          7'h38:
            for ( byte_index = 0; byte_index <= (C_S_AXI_DATA_WIDTH/8)-1; byte_index = byte_index+1 )
              if ( S_AXI_WSTRB[byte_index] == 1 ) begin
                // Respective byte enables are asserted as per write strobes 
                // Slave register 56
                slv_reg56[(byte_index*8) +: 8] <= S_AXI_WDATA[(byte_index*8) +: 8];
              end  
          7'h39:
            for ( byte_index = 0; byte_index <= (C_S_AXI_DATA_WIDTH/8)-1; byte_index = byte_index+1 )
              if ( S_AXI_WSTRB[byte_index] == 1 ) begin
                // Respective byte enables are asserted as per write strobes 
                // Slave register 57
                slv_reg57[(byte_index*8) +: 8] <= S_AXI_WDATA[(byte_index*8) +: 8];
              end  
          7'h3A:
            for ( byte_index = 0; byte_index <= (C_S_AXI_DATA_WIDTH/8)-1; byte_index = byte_index+1 )
              if ( S_AXI_WSTRB[byte_index] == 1 ) begin
                // Respective byte enables are asserted as per write strobes 
                // Slave register 58
                slv_reg58[(byte_index*8) +: 8] <= S_AXI_WDATA[(byte_index*8) +: 8];
              end  
          7'h3B:
            for ( byte_index = 0; byte_index <= (C_S_AXI_DATA_WIDTH/8)-1; byte_index = byte_index+1 )
              if ( S_AXI_WSTRB[byte_index] == 1 ) begin
                // Respective byte enables are asserted as per write strobes 
                // Slave register 59
                slv_reg59[(byte_index*8) +: 8] <= S_AXI_WDATA[(byte_index*8) +: 8];
              end  
          7'h3C:
            for ( byte_index = 0; byte_index <= (C_S_AXI_DATA_WIDTH/8)-1; byte_index = byte_index+1 )
              if ( S_AXI_WSTRB[byte_index] == 1 ) begin
                // Respective byte enables are asserted as per write strobes 
                // Slave register 60
                slv_reg60[(byte_index*8) +: 8] <= S_AXI_WDATA[(byte_index*8) +: 8];
              end  
          7'h3D:
            for ( byte_index = 0; byte_index <= (C_S_AXI_DATA_WIDTH/8)-1; byte_index = byte_index+1 )
              if ( S_AXI_WSTRB[byte_index] == 1 ) begin
                // Respective byte enables are asserted as per write strobes 
                // Slave register 61
                slv_reg61[(byte_index*8) +: 8] <= S_AXI_WDATA[(byte_index*8) +: 8];
              end  
          7'h3E:
            for ( byte_index = 0; byte_index <= (C_S_AXI_DATA_WIDTH/8)-1; byte_index = byte_index+1 )
              if ( S_AXI_WSTRB[byte_index] == 1 ) begin
                // Respective byte enables are asserted as per write strobes 
                // Slave register 62
                slv_reg62[(byte_index*8) +: 8] <= S_AXI_WDATA[(byte_index*8) +: 8];
              end  
          7'h3F:
            for ( byte_index = 0; byte_index <= (C_S_AXI_DATA_WIDTH/8)-1; byte_index = byte_index+1 )
              if ( S_AXI_WSTRB[byte_index] == 1 ) begin
                // Respective byte enables are asserted as per write strobes 
                // Slave register 63
                slv_reg63[(byte_index*8) +: 8] <= S_AXI_WDATA[(byte_index*8) +: 8];
              end  
          7'h40:
            for ( byte_index = 0; byte_index <= (C_S_AXI_DATA_WIDTH/8)-1; byte_index = byte_index+1 )
              if ( S_AXI_WSTRB[byte_index] == 1 ) begin
                // Respective byte enables are asserted as per write strobes 
                // Slave register 64
                slv_reg64[(byte_index*8) +: 8] <= S_AXI_WDATA[(byte_index*8) +: 8];
              end  
          7'h41:
            for ( byte_index = 0; byte_index <= (C_S_AXI_DATA_WIDTH/8)-1; byte_index = byte_index+1 )
              if ( S_AXI_WSTRB[byte_index] == 1 ) begin
                // Respective byte enables are asserted as per write strobes 
                // Slave register 65
                slv_reg65[(byte_index*8) +: 8] <= S_AXI_WDATA[(byte_index*8) +: 8];
              end  
          7'h42:
            for ( byte_index = 0; byte_index <= (C_S_AXI_DATA_WIDTH/8)-1; byte_index = byte_index+1 )
              if ( S_AXI_WSTRB[byte_index] == 1 ) begin
                // Respective byte enables are asserted as per write strobes 
                // Slave register 66
                slv_reg66[(byte_index*8) +: 8] <= S_AXI_WDATA[(byte_index*8) +: 8];
              end  
          7'h43:
            for ( byte_index = 0; byte_index <= (C_S_AXI_DATA_WIDTH/8)-1; byte_index = byte_index+1 )
              if ( S_AXI_WSTRB[byte_index] == 1 ) begin
                // Respective byte enables are asserted as per write strobes 
                // Slave register 67
                slv_reg67[(byte_index*8) +: 8] <= S_AXI_WDATA[(byte_index*8) +: 8];
              end  
          7'h44:
            for ( byte_index = 0; byte_index <= (C_S_AXI_DATA_WIDTH/8)-1; byte_index = byte_index+1 )
              if ( S_AXI_WSTRB[byte_index] == 1 ) begin
                // Respective byte enables are asserted as per write strobes 
                // Slave register 68
                slv_reg68[(byte_index*8) +: 8] <= S_AXI_WDATA[(byte_index*8) +: 8];
              end  
          7'h45:
            for ( byte_index = 0; byte_index <= (C_S_AXI_DATA_WIDTH/8)-1; byte_index = byte_index+1 )
              if ( S_AXI_WSTRB[byte_index] == 1 ) begin
                // Respective byte enables are asserted as per write strobes 
                // Slave register 69
                slv_reg69[(byte_index*8) +: 8] <= S_AXI_WDATA[(byte_index*8) +: 8];
              end  
          7'h46:
            for ( byte_index = 0; byte_index <= (C_S_AXI_DATA_WIDTH/8)-1; byte_index = byte_index+1 )
              if ( S_AXI_WSTRB[byte_index] == 1 ) begin
                // Respective byte enables are asserted as per write strobes 
                // Slave register 70
                slv_reg70[(byte_index*8) +: 8] <= S_AXI_WDATA[(byte_index*8) +: 8];
              end  
          7'h47:
            for ( byte_index = 0; byte_index <= (C_S_AXI_DATA_WIDTH/8)-1; byte_index = byte_index+1 )
              if ( S_AXI_WSTRB[byte_index] == 1 ) begin
                // Respective byte enables are asserted as per write strobes 
                // Slave register 71
                slv_reg71[(byte_index*8) +: 8] <= S_AXI_WDATA[(byte_index*8) +: 8];
              end  
          7'h48:
            for ( byte_index = 0; byte_index <= (C_S_AXI_DATA_WIDTH/8)-1; byte_index = byte_index+1 )
              if ( S_AXI_WSTRB[byte_index] == 1 ) begin
                // Respective byte enables are asserted as per write strobes 
                // Slave register 72
                slv_reg72[(byte_index*8) +: 8] <= S_AXI_WDATA[(byte_index*8) +: 8];
              end  
          7'h49:
            for ( byte_index = 0; byte_index <= (C_S_AXI_DATA_WIDTH/8)-1; byte_index = byte_index+1 )
              if ( S_AXI_WSTRB[byte_index] == 1 ) begin
                // Respective byte enables are asserted as per write strobes 
                // Slave register 73
                slv_reg73[(byte_index*8) +: 8] <= S_AXI_WDATA[(byte_index*8) +: 8];
              end  
          7'h4A:
            for ( byte_index = 0; byte_index <= (C_S_AXI_DATA_WIDTH/8)-1; byte_index = byte_index+1 )
              if ( S_AXI_WSTRB[byte_index] == 1 ) begin
                // Respective byte enables are asserted as per write strobes 
                // Slave register 74
                slv_reg74[(byte_index*8) +: 8] <= S_AXI_WDATA[(byte_index*8) +: 8];
              end  
          7'h4B:
            for ( byte_index = 0; byte_index <= (C_S_AXI_DATA_WIDTH/8)-1; byte_index = byte_index+1 )
              if ( S_AXI_WSTRB[byte_index] == 1 ) begin
                // Respective byte enables are asserted as per write strobes 
                // Slave register 75
                slv_reg75[(byte_index*8) +: 8] <= S_AXI_WDATA[(byte_index*8) +: 8];
              end  
          7'h4C:
            for ( byte_index = 0; byte_index <= (C_S_AXI_DATA_WIDTH/8)-1; byte_index = byte_index+1 )
              if ( S_AXI_WSTRB[byte_index] == 1 ) begin
                // Respective byte enables are asserted as per write strobes 
                // Slave register 76
                slv_reg76[(byte_index*8) +: 8] <= S_AXI_WDATA[(byte_index*8) +: 8];
              end  
          7'h4D:
            for ( byte_index = 0; byte_index <= (C_S_AXI_DATA_WIDTH/8)-1; byte_index = byte_index+1 )
              if ( S_AXI_WSTRB[byte_index] == 1 ) begin
                // Respective byte enables are asserted as per write strobes 
                // Slave register 77
                slv_reg77[(byte_index*8) +: 8] <= S_AXI_WDATA[(byte_index*8) +: 8];
              end  
          7'h4E:
            for ( byte_index = 0; byte_index <= (C_S_AXI_DATA_WIDTH/8)-1; byte_index = byte_index+1 )
              if ( S_AXI_WSTRB[byte_index] == 1 ) begin
                // Respective byte enables are asserted as per write strobes 
                // Slave register 78
                slv_reg78[(byte_index*8) +: 8] <= S_AXI_WDATA[(byte_index*8) +: 8];
              end  
          7'h4F:
            for ( byte_index = 0; byte_index <= (C_S_AXI_DATA_WIDTH/8)-1; byte_index = byte_index+1 )
              if ( S_AXI_WSTRB[byte_index] == 1 ) begin
                // Respective byte enables are asserted as per write strobes 
                // Slave register 79
                slv_reg79[(byte_index*8) +: 8] <= S_AXI_WDATA[(byte_index*8) +: 8];
              end  
          7'h50:
            for ( byte_index = 0; byte_index <= (C_S_AXI_DATA_WIDTH/8)-1; byte_index = byte_index+1 )
              if ( S_AXI_WSTRB[byte_index] == 1 ) begin
                // Respective byte enables are asserted as per write strobes 
                // Slave register 80
                slv_reg80[(byte_index*8) +: 8] <= S_AXI_WDATA[(byte_index*8) +: 8];
              end  
          7'h51:
            for ( byte_index = 0; byte_index <= (C_S_AXI_DATA_WIDTH/8)-1; byte_index = byte_index+1 )
              if ( S_AXI_WSTRB[byte_index] == 1 ) begin
                // Respective byte enables are asserted as per write strobes 
                // Slave register 81
                slv_reg81[(byte_index*8) +: 8] <= S_AXI_WDATA[(byte_index*8) +: 8];
              end  
          7'h52:
            for ( byte_index = 0; byte_index <= (C_S_AXI_DATA_WIDTH/8)-1; byte_index = byte_index+1 )
              if ( S_AXI_WSTRB[byte_index] == 1 ) begin
                // Respective byte enables are asserted as per write strobes 
                // Slave register 82
                slv_reg82[(byte_index*8) +: 8] <= S_AXI_WDATA[(byte_index*8) +: 8];
              end  
          7'h53:
            for ( byte_index = 0; byte_index <= (C_S_AXI_DATA_WIDTH/8)-1; byte_index = byte_index+1 )
              if ( S_AXI_WSTRB[byte_index] == 1 ) begin
                // Respective byte enables are asserted as per write strobes 
                // Slave register 83
                slv_reg83[(byte_index*8) +: 8] <= S_AXI_WDATA[(byte_index*8) +: 8];
              end  
          7'h54:
            for ( byte_index = 0; byte_index <= (C_S_AXI_DATA_WIDTH/8)-1; byte_index = byte_index+1 )
              if ( S_AXI_WSTRB[byte_index] == 1 ) begin
                // Respective byte enables are asserted as per write strobes 
                // Slave register 84
                slv_reg84[(byte_index*8) +: 8] <= S_AXI_WDATA[(byte_index*8) +: 8];
              end  
          7'h55:
            for ( byte_index = 0; byte_index <= (C_S_AXI_DATA_WIDTH/8)-1; byte_index = byte_index+1 )
              if ( S_AXI_WSTRB[byte_index] == 1 ) begin
                // Respective byte enables are asserted as per write strobes 
                // Slave register 85
                slv_reg85[(byte_index*8) +: 8] <= S_AXI_WDATA[(byte_index*8) +: 8];
              end  
          7'h56:
            for ( byte_index = 0; byte_index <= (C_S_AXI_DATA_WIDTH/8)-1; byte_index = byte_index+1 )
              if ( S_AXI_WSTRB[byte_index] == 1 ) begin
                // Respective byte enables are asserted as per write strobes 
                // Slave register 86
                slv_reg86[(byte_index*8) +: 8] <= S_AXI_WDATA[(byte_index*8) +: 8];
              end  
          7'h57:
            for ( byte_index = 0; byte_index <= (C_S_AXI_DATA_WIDTH/8)-1; byte_index = byte_index+1 )
              if ( S_AXI_WSTRB[byte_index] == 1 ) begin
                // Respective byte enables are asserted as per write strobes 
                // Slave register 87
                slv_reg87[(byte_index*8) +: 8] <= S_AXI_WDATA[(byte_index*8) +: 8];
              end  
          7'h58:
            for ( byte_index = 0; byte_index <= (C_S_AXI_DATA_WIDTH/8)-1; byte_index = byte_index+1 )
              if ( S_AXI_WSTRB[byte_index] == 1 ) begin
                // Respective byte enables are asserted as per write strobes 
                // Slave register 88
                slv_reg88[(byte_index*8) +: 8] <= S_AXI_WDATA[(byte_index*8) +: 8];
              end  
          7'h59:
            for ( byte_index = 0; byte_index <= (C_S_AXI_DATA_WIDTH/8)-1; byte_index = byte_index+1 )
              if ( S_AXI_WSTRB[byte_index] == 1 ) begin
                // Respective byte enables are asserted as per write strobes 
                // Slave register 89
                slv_reg89[(byte_index*8) +: 8] <= S_AXI_WDATA[(byte_index*8) +: 8];
              end  
          7'h5A:
            for ( byte_index = 0; byte_index <= (C_S_AXI_DATA_WIDTH/8)-1; byte_index = byte_index+1 )
              if ( S_AXI_WSTRB[byte_index] == 1 ) begin
                // Respective byte enables are asserted as per write strobes 
                // Slave register 90
                slv_reg90[(byte_index*8) +: 8] <= S_AXI_WDATA[(byte_index*8) +: 8];
              end  
          7'h5B:
            for ( byte_index = 0; byte_index <= (C_S_AXI_DATA_WIDTH/8)-1; byte_index = byte_index+1 )
              if ( S_AXI_WSTRB[byte_index] == 1 ) begin
                // Respective byte enables are asserted as per write strobes 
                // Slave register 91
                slv_reg91[(byte_index*8) +: 8] <= S_AXI_WDATA[(byte_index*8) +: 8];
              end  
          7'h5C:
            for ( byte_index = 0; byte_index <= (C_S_AXI_DATA_WIDTH/8)-1; byte_index = byte_index+1 )
              if ( S_AXI_WSTRB[byte_index] == 1 ) begin
                // Respective byte enables are asserted as per write strobes 
                // Slave register 92
                slv_reg92[(byte_index*8) +: 8] <= S_AXI_WDATA[(byte_index*8) +: 8];
              end  
          7'h5D:
            for ( byte_index = 0; byte_index <= (C_S_AXI_DATA_WIDTH/8)-1; byte_index = byte_index+1 )
              if ( S_AXI_WSTRB[byte_index] == 1 ) begin
                // Respective byte enables are asserted as per write strobes 
                // Slave register 93
                slv_reg93[(byte_index*8) +: 8] <= S_AXI_WDATA[(byte_index*8) +: 8];
              end  
          7'h5E:
            for ( byte_index = 0; byte_index <= (C_S_AXI_DATA_WIDTH/8)-1; byte_index = byte_index+1 )
              if ( S_AXI_WSTRB[byte_index] == 1 ) begin
                // Respective byte enables are asserted as per write strobes 
                // Slave register 94
                slv_reg94[(byte_index*8) +: 8] <= S_AXI_WDATA[(byte_index*8) +: 8];
              end  
          7'h5F:
            for ( byte_index = 0; byte_index <= (C_S_AXI_DATA_WIDTH/8)-1; byte_index = byte_index+1 )
              if ( S_AXI_WSTRB[byte_index] == 1 ) begin
                // Respective byte enables are asserted as per write strobes 
                // Slave register 95
                slv_reg95[(byte_index*8) +: 8] <= S_AXI_WDATA[(byte_index*8) +: 8];
              end  
          7'h60:
            for ( byte_index = 0; byte_index <= (C_S_AXI_DATA_WIDTH/8)-1; byte_index = byte_index+1 )
              if ( S_AXI_WSTRB[byte_index] == 1 ) begin
                // Respective byte enables are asserted as per write strobes 
                // Slave register 96
                slv_reg96[(byte_index*8) +: 8] <= S_AXI_WDATA[(byte_index*8) +: 8];
              end  
          7'h61:
            for ( byte_index = 0; byte_index <= (C_S_AXI_DATA_WIDTH/8)-1; byte_index = byte_index+1 )
              if ( S_AXI_WSTRB[byte_index] == 1 ) begin
                // Respective byte enables are asserted as per write strobes 
                // Slave register 97
                slv_reg97[(byte_index*8) +: 8] <= S_AXI_WDATA[(byte_index*8) +: 8];
              end  
          7'h62:
            for ( byte_index = 0; byte_index <= (C_S_AXI_DATA_WIDTH/8)-1; byte_index = byte_index+1 )
              if ( S_AXI_WSTRB[byte_index] == 1 ) begin
                // Respective byte enables are asserted as per write strobes 
                // Slave register 98
                slv_reg98[(byte_index*8) +: 8] <= S_AXI_WDATA[(byte_index*8) +: 8];
              end  
          7'h63:
            for ( byte_index = 0; byte_index <= (C_S_AXI_DATA_WIDTH/8)-1; byte_index = byte_index+1 )
              if ( S_AXI_WSTRB[byte_index] == 1 ) begin
                // Respective byte enables are asserted as per write strobes 
                // Slave register 99
                slv_reg99[(byte_index*8) +: 8] <= S_AXI_WDATA[(byte_index*8) +: 8];
              end  
          7'h64:
            for ( byte_index = 0; byte_index <= (C_S_AXI_DATA_WIDTH/8)-1; byte_index = byte_index+1 )
              if ( S_AXI_WSTRB[byte_index] == 1 ) begin
                // Respective byte enables are asserted as per write strobes 
                // Slave register 100
                slv_reg100[(byte_index*8) +: 8] <= S_AXI_WDATA[(byte_index*8) +: 8];
              end  
          7'h65:
            for ( byte_index = 0; byte_index <= (C_S_AXI_DATA_WIDTH/8)-1; byte_index = byte_index+1 )
              if ( S_AXI_WSTRB[byte_index] == 1 ) begin
                // Respective byte enables are asserted as per write strobes 
                // Slave register 101
                slv_reg101[(byte_index*8) +: 8] <= S_AXI_WDATA[(byte_index*8) +: 8];
              end  
          7'h66:
            for ( byte_index = 0; byte_index <= (C_S_AXI_DATA_WIDTH/8)-1; byte_index = byte_index+1 )
              if ( S_AXI_WSTRB[byte_index] == 1 ) begin
                // Respective byte enables are asserted as per write strobes 
                // Slave register 102
                slv_reg102[(byte_index*8) +: 8] <= S_AXI_WDATA[(byte_index*8) +: 8];
              end  
          7'h67:
            for ( byte_index = 0; byte_index <= (C_S_AXI_DATA_WIDTH/8)-1; byte_index = byte_index+1 )
              if ( S_AXI_WSTRB[byte_index] == 1 ) begin
                // Respective byte enables are asserted as per write strobes 
                // Slave register 103
                slv_reg103[(byte_index*8) +: 8] <= S_AXI_WDATA[(byte_index*8) +: 8];
              end  
          7'h68:
            for ( byte_index = 0; byte_index <= (C_S_AXI_DATA_WIDTH/8)-1; byte_index = byte_index+1 )
              if ( S_AXI_WSTRB[byte_index] == 1 ) begin
                // Respective byte enables are asserted as per write strobes 
                // Slave register 104
                slv_reg104[(byte_index*8) +: 8] <= S_AXI_WDATA[(byte_index*8) +: 8];
              end  
          7'h69:
            for ( byte_index = 0; byte_index <= (C_S_AXI_DATA_WIDTH/8)-1; byte_index = byte_index+1 )
              if ( S_AXI_WSTRB[byte_index] == 1 ) begin
                // Respective byte enables are asserted as per write strobes 
                // Slave register 105
                slv_reg105[(byte_index*8) +: 8] <= S_AXI_WDATA[(byte_index*8) +: 8];
              end  
          7'h6A:
            for ( byte_index = 0; byte_index <= (C_S_AXI_DATA_WIDTH/8)-1; byte_index = byte_index+1 )
              if ( S_AXI_WSTRB[byte_index] == 1 ) begin
                // Respective byte enables are asserted as per write strobes 
                // Slave register 106
                slv_reg106[(byte_index*8) +: 8] <= S_AXI_WDATA[(byte_index*8) +: 8];
              end  
          7'h6B:
            for ( byte_index = 0; byte_index <= (C_S_AXI_DATA_WIDTH/8)-1; byte_index = byte_index+1 )
              if ( S_AXI_WSTRB[byte_index] == 1 ) begin
                // Respective byte enables are asserted as per write strobes 
                // Slave register 107
                slv_reg107[(byte_index*8) +: 8] <= S_AXI_WDATA[(byte_index*8) +: 8];
              end  
          7'h6C:
            for ( byte_index = 0; byte_index <= (C_S_AXI_DATA_WIDTH/8)-1; byte_index = byte_index+1 )
              if ( S_AXI_WSTRB[byte_index] == 1 ) begin
                // Respective byte enables are asserted as per write strobes 
                // Slave register 108
                slv_reg108[(byte_index*8) +: 8] <= S_AXI_WDATA[(byte_index*8) +: 8];
              end  
          7'h6D:
            for ( byte_index = 0; byte_index <= (C_S_AXI_DATA_WIDTH/8)-1; byte_index = byte_index+1 )
              if ( S_AXI_WSTRB[byte_index] == 1 ) begin
                // Respective byte enables are asserted as per write strobes 
                // Slave register 109
                slv_reg109[(byte_index*8) +: 8] <= S_AXI_WDATA[(byte_index*8) +: 8];
              end  
          7'h6E:
            for ( byte_index = 0; byte_index <= (C_S_AXI_DATA_WIDTH/8)-1; byte_index = byte_index+1 )
              if ( S_AXI_WSTRB[byte_index] == 1 ) begin
                // Respective byte enables are asserted as per write strobes 
                // Slave register 110
                slv_reg110[(byte_index*8) +: 8] <= S_AXI_WDATA[(byte_index*8) +: 8];
              end  
          7'h6F:
            for ( byte_index = 0; byte_index <= (C_S_AXI_DATA_WIDTH/8)-1; byte_index = byte_index+1 )
              if ( S_AXI_WSTRB[byte_index] == 1 ) begin
                // Respective byte enables are asserted as per write strobes 
                // Slave register 111
                slv_reg111[(byte_index*8) +: 8] <= S_AXI_WDATA[(byte_index*8) +: 8];
              end  
          7'h70:
            for ( byte_index = 0; byte_index <= (C_S_AXI_DATA_WIDTH/8)-1; byte_index = byte_index+1 )
              if ( S_AXI_WSTRB[byte_index] == 1 ) begin
                // Respective byte enables are asserted as per write strobes 
                // Slave register 112
                slv_reg112[(byte_index*8) +: 8] <= S_AXI_WDATA[(byte_index*8) +: 8];
              end  
          7'h71:
            for ( byte_index = 0; byte_index <= (C_S_AXI_DATA_WIDTH/8)-1; byte_index = byte_index+1 )
              if ( S_AXI_WSTRB[byte_index] == 1 ) begin
                // Respective byte enables are asserted as per write strobes 
                // Slave register 113
                slv_reg113[(byte_index*8) +: 8] <= S_AXI_WDATA[(byte_index*8) +: 8];
              end  
          7'h72:
            for ( byte_index = 0; byte_index <= (C_S_AXI_DATA_WIDTH/8)-1; byte_index = byte_index+1 )
              if ( S_AXI_WSTRB[byte_index] == 1 ) begin
                // Respective byte enables are asserted as per write strobes 
                // Slave register 114
                slv_reg114[(byte_index*8) +: 8] <= S_AXI_WDATA[(byte_index*8) +: 8];
              end  
          default : begin
                      slv_reg0 <= slv_reg0;
                      slv_reg1 <= slv_reg1;
                      slv_reg2 <= slv_reg2;
                      slv_reg3 <= slv_reg3;
                      slv_reg4 <= slv_reg4;
                      slv_reg5 <= slv_reg5;
                      slv_reg6 <= slv_reg6;
                      slv_reg7 <= slv_reg7;
                      slv_reg8 <= slv_reg8;
                      slv_reg9 <= slv_reg9;
                      slv_reg10 <= slv_reg10;
                      slv_reg11 <= slv_reg11;
                      slv_reg12 <= slv_reg12;
                      slv_reg13 <= slv_reg13;
                      slv_reg14 <= slv_reg14;
                      slv_reg15 <= slv_reg15;
                      slv_reg16 <= slv_reg16;
                      slv_reg17 <= slv_reg17;
                      slv_reg18 <= slv_reg18;
                      slv_reg19 <= slv_reg19;
                      slv_reg20 <= slv_reg20;
                      slv_reg21 <= slv_reg21;
                      slv_reg22 <= slv_reg22;
                      slv_reg23 <= slv_reg23;
                      slv_reg24 <= slv_reg24;
                      slv_reg25 <= slv_reg25;
                      slv_reg26 <= slv_reg26;
                      slv_reg27 <= slv_reg27;
                      slv_reg28 <= slv_reg28;
                      slv_reg29 <= slv_reg29;
                      slv_reg30 <= slv_reg30;
                      slv_reg31 <= slv_reg31;
                      slv_reg32 <= slv_reg32;
                      slv_reg33 <= slv_reg33;
                      slv_reg34 <= slv_reg34;
                      slv_reg35 <= slv_reg35;
                      slv_reg36 <= slv_reg36;
                      slv_reg37 <= slv_reg37;
                      slv_reg38 <= slv_reg38;
                      slv_reg39 <= slv_reg39;
                      slv_reg40 <= slv_reg40;
                      slv_reg41 <= slv_reg41;
                      slv_reg42 <= slv_reg42;
                      slv_reg43 <= slv_reg43;
                      slv_reg44 <= slv_reg44;
                      slv_reg45 <= slv_reg45;
                      slv_reg46 <= slv_reg46;
                      slv_reg47 <= slv_reg47;
                      slv_reg48 <= slv_reg48;
                      slv_reg49 <= slv_reg49;
                      slv_reg50 <= slv_reg50;
                      slv_reg51 <= slv_reg51;
                      slv_reg52 <= slv_reg52;
                      slv_reg53 <= slv_reg53;
                      slv_reg54 <= slv_reg54;
                      slv_reg55 <= slv_reg55;
                      slv_reg56 <= slv_reg56;
                      slv_reg57 <= slv_reg57;
                      slv_reg58 <= slv_reg58;
                      slv_reg59 <= slv_reg59;
                      slv_reg60 <= slv_reg60;
                      slv_reg61 <= slv_reg61;
                      slv_reg62 <= slv_reg62;
                      slv_reg63 <= slv_reg63;
                      slv_reg64 <= slv_reg64;
                      slv_reg65 <= slv_reg65;
                      slv_reg66 <= slv_reg66;
                      slv_reg67 <= slv_reg67;
                      slv_reg68 <= slv_reg68;
                      slv_reg69 <= slv_reg69;
                      slv_reg70 <= slv_reg70;
                      slv_reg71 <= slv_reg71;
                      slv_reg72 <= slv_reg72;
                      slv_reg73 <= slv_reg73;
                      slv_reg74 <= slv_reg74;
                      slv_reg75 <= slv_reg75;
                      slv_reg76 <= slv_reg76;
                      slv_reg77 <= slv_reg77;
                      slv_reg78 <= slv_reg78;
                      slv_reg79 <= slv_reg79;
                      slv_reg80 <= slv_reg80;
                      slv_reg81 <= slv_reg81;
                      slv_reg82 <= slv_reg82;
                      slv_reg83 <= slv_reg83;
                      slv_reg84 <= slv_reg84;
                      slv_reg85 <= slv_reg85;
                      slv_reg86 <= slv_reg86;
                      slv_reg87 <= slv_reg87;
                      slv_reg88 <= slv_reg88;
                      slv_reg89 <= slv_reg89;
                      slv_reg90 <= slv_reg90;
                      slv_reg91 <= slv_reg91;
                      slv_reg92 <= slv_reg92;
                      slv_reg93 <= slv_reg93;
                      slv_reg94 <= slv_reg94;
                      slv_reg95 <= slv_reg95;
                      slv_reg96 <= slv_reg96;
                      slv_reg97 <= slv_reg97;
                      slv_reg98 <= slv_reg98;
                      slv_reg99 <= slv_reg99;
                      slv_reg100 <= slv_reg100;
                      slv_reg101 <= slv_reg101;
                      slv_reg102 <= slv_reg102;
                      slv_reg103 <= slv_reg103;
                      slv_reg104 <= slv_reg104;
                      slv_reg105 <= slv_reg105;
                      slv_reg106 <= slv_reg106;
                      slv_reg107 <= slv_reg107;
                      slv_reg108 <= slv_reg108;
                      slv_reg109 <= slv_reg109;
                      slv_reg110 <= slv_reg110;
                      slv_reg111 <= slv_reg111;
                      slv_reg112 <= slv_reg112;
                      slv_reg113 <= slv_reg113;
                      slv_reg114 <= slv_reg114;
                    end
        endcase
      end
  end
end    

// Implement write response logic generation
// The write response and response valid signals are asserted by the slave 
// when axi_wready, S_AXI_WVALID, axi_wready and S_AXI_WVALID are asserted.  
// This marks the acceptance of address and indicates the status of 
// write transaction.

always @( posedge S_AXI_ACLK )
begin
  if ( S_AXI_ARESETN == 1'b0 )
    begin
      axi_bvalid  <= 0;
      axi_bresp   <= 2'b0;
    end 
  else
    begin    
      //if (axi_awready && S_AXI_AWVALID && ~axi_bvalid && axi_wready && S_AXI_WVALID) // mash
      if (~axi_bvalid && axi_wready && S_AXI_WVALID)
        begin
          // indicates a valid write response is available
          axi_bvalid <= 1'b1;
          axi_bresp  <= 2'b0; // 'OKAY' response 
        end                   // work error responses in future
      else
        begin
          if (S_AXI_BREADY && axi_bvalid) 
            //check if bready is asserted while bvalid is high) 
            //(there is a possibility that bready is always asserted high)   
            begin
              axi_bvalid <= 1'b0; 
            end  
        end
    end
end   

// Implement axi_arready generation
// axi_arready is asserted for one S_AXI_ACLK clock cycle when
// S_AXI_ARVALID is asserted. axi_awready is 
// de-asserted when reset (active low) is asserted. 
// The read address is also latched when S_AXI_ARVALID is 
// asserted. axi_araddr is reset to zero on reset assertion.

always @( posedge S_AXI_ACLK )
begin
  if ( S_AXI_ARESETN == 1'b0 )
    begin
      axi_arready <= 1'b0;
      axi_araddr  <= 32'b0;
    end 
  else
    begin    
      if (~axi_arready && S_AXI_ARVALID)
        begin
          // indicates that the slave has acceped the valid read address
          axi_arready <= 1'b1;
          // Read address latching
          axi_araddr  <= S_AXI_ARADDR;
        end
      else
        begin
          axi_arready <= 1'b0;
        end
    end 
end       

// Implement axi_arvalid generation
// axi_rvalid is asserted for one S_AXI_ACLK clock cycle when both 
// S_AXI_ARVALID and axi_arready are asserted. The slave registers 
// data are available on the axi_rdata bus at this instance. The 
// assertion of axi_rvalid marks the validity of read data on the 
// bus and axi_rresp indicates the status of read transaction.axi_rvalid 
// is deasserted on reset (active low). axi_rresp and axi_rdata are 
// cleared to zero on reset (active low).  
always @( posedge S_AXI_ACLK )
begin
  if ( S_AXI_ARESETN == 1'b0 )
    begin
      axi_rvalid <= 0;
      axi_rresp  <= 0;
    end 
  else
    begin    
      if (axi_arready && S_AXI_ARVALID && ~axi_rvalid)
        begin
          // Valid read data is available at the read data bus
          axi_rvalid <= 1'b1;
          axi_rresp  <= 2'b0; // 'OKAY' response
        end   
      else if (axi_rvalid && S_AXI_RREADY)
        begin
          // Read data is accepted by the master
          axi_rvalid <= 1'b0;
        end                
    end
end    

// Implement memory mapped register select and read logic generation
// Slave register read enable is asserted when valid address is available
// and the slave is ready to accept the read address.
assign slv_reg_rden = axi_arready & S_AXI_ARVALID & ~axi_rvalid;
always @(*)
begin
      // Address decoding for reading registers
      case ( axi_araddr[ADDR_LSB+OPT_MEM_ADDR_BITS:ADDR_LSB] )
        7'h00   : reg_data_out <= {31'b0000000000000000000000000000000,ecc_go};
        7'h01   : reg_data_out <= {31'b0000000000000000000000000000000,sign_go};
        7'h02   : reg_data_out <= {31'b0000000000000000000000000000000,verify_go};
        7'h03   : reg_data_out <= message[31:0];
        //7'h04   : reg_data_out <= message[63:32];
        //7'h05   : reg_data_out <= message[95:64];
        //7'h06   : reg_data_out <= message[127:96];
        //7'h07   : reg_data_out <= message[159:128];
        //7'h08   : reg_data_out <= message[191:160];
        //7'h09   : reg_data_out <= message[223:192];
        //7'h0A   : reg_data_out <= message[255:224];
        //7'h0B   : reg_data_out <= message[287:256];
        //7'h0C   : reg_data_out <= message[319:288];
        //7'h0D   : reg_data_out <= message[351:320];
        //7'h0E   : reg_data_out <= message[383:352];
        //7'h0F   : reg_data_out <= message[415:384];
        //7'h10   : reg_data_out <= message[447:416];
        //7'h11   : reg_data_out <= message[479:448];
        //7'h12   : reg_data_out <= message[511:480];
        7'h13   : reg_data_out <= hashedMessage[31:0];
        //7'h14   : reg_data_out <= hashedMessage[63:32];
        //7'h15   : reg_data_out <= hashedMessage[95:64];
        //7'h16   : reg_data_out <= hashedMessage[127:96];
        //7'h17   : reg_data_out <= hashedMessage[159:128];
        //7'h18   : reg_data_out <= hashedMessage[191:160];
        //7'h19   : reg_data_out <= hashedMessage[223:192];
        //7'h1A   : reg_data_out <= hashedMessage[255:224];
        //7'h1B   : reg_data_out <= hashedMessage[287:256];
        //7'h1C   : reg_data_out <= hashedMessage[319:288];
        //7'h1D   : reg_data_out <= hashedMessage[351:320];
        //7'h1E   : reg_data_out <= hashedMessage[383:352];
        //7'h1F   : reg_data_out <= hashedMessage[415:384];
        //7'h20   : reg_data_out <= hashedMessage[447:416];
        //7'h21   : reg_data_out <= hashedMessage[479:448];
        //7'h22   : reg_data_out <= hashedMessage[511:480];
        7'h23   : reg_data_out <= trng[31:0];
        //7'h24   : reg_data_out <= trng[63:32];
        //7'h25   : reg_data_out <= trng[95:64];
        //7'h26   : reg_data_out <= trng[127:96];
        //7'h27   : reg_data_out <= trng[159:128];
        //7'h28   : reg_data_out <= trng[191:160];
        //7'h29   : reg_data_out <= trng[223:192];
        //7'h2A   : reg_data_out <= trng[255:224];
        //7'h2B   : reg_data_out <= trng[287:256];
        //7'h2C   : reg_data_out <= trng[319:288];
        //7'h2D   : reg_data_out <= trng[351:320];
        //7'h2E   : reg_data_out <= trng[383:352];
        //7'h2F   : reg_data_out <= trng[415:384];
        //7'h30   : reg_data_out <= trng[447:416];
        //7'h31   : reg_data_out <= trng[479:448];
        //7'h32   : reg_data_out <= trng[511:480];
        7'h33   : reg_data_out <= {31'b0000000000000000000000000000000,sign_ready};
        7'h34   : reg_data_out <= {31'b0000000000000000000000000000000,verify_ready};
        7'h35   : reg_data_out <= {31'b0000000000000000000000000000000,verified};
        7'h36   : reg_data_out <= {31'b0000000000000000000000000000000,failure};
        7'h37   : reg_data_out <= {31'b0000000000000000000000000000000,infiityPPubKey};
        7'h38   : reg_data_out <= {31'b0000000000000000000000000000000,ecc_done};
        7'h39   : reg_data_out <= {31'b0000000000000000000000000000000,sign_done};
        7'h3A   : reg_data_out <= {31'b0000000000000000000000000000000,verify_done};
        7'h3B   : reg_data_out <= prime[31:0];
        7'h3C   : reg_data_out <= prime[63:32];
        7'h3D   : reg_data_out <= A[31:0];
        7'h3E   : reg_data_out <= A[63:32];
        7'h3F   : reg_data_out <= B[31:0];
        7'h40   : reg_data_out <= B[63:32];
        7'h41   : reg_data_out <= Gx[31:0];
        7'h42   : reg_data_out <= Gx[63:32];
        7'h43   : reg_data_out <= Gy[31:0];
        7'h44   : reg_data_out <= Gy[63:32];
        7'h45   : reg_data_out <= n[31:0];
        7'h46   : reg_data_out <= n[63:32];
        7'h47   : reg_data_out <= Ox[31:0];
        7'h48   : reg_data_out <= Ox[63:32];
        7'h49   : reg_data_out <= Oy[31:0];
        7'h4A   : reg_data_out <= Oy[63:32];
        7'h4B   : reg_data_out <= r_sign[31:0];
        7'h4C   : reg_data_out <= r_sign[63:32];
        //7'h4D   : reg_data_out <= r_sign[95:64];
        //7'h4E   : reg_data_out <= r_sign[127:96];
        //7'h4F   : reg_data_out <= r_sign[159:128];
        //7'h50   : reg_data_out <= r_sign[191:160];
        //7'h51   : reg_data_out <= r_sign[223:192];
        //7'h52   : reg_data_out <= r_sign[255:224];
        7'h53   : reg_data_out <= s_sign[31:0];
        7'h54   : reg_data_out <= s_sign[63:32];
        //7'h55   : reg_data_out <= s_sign[95:64];
        //7'h56   : reg_data_out <= s_sign[127:96];
        //7'h57   : reg_data_out <= s_sign[159:128];
        //7'h58   : reg_data_out <= s_sign[191:160];
        //7'h59   : reg_data_out <= s_sign[223:192];
        //7'h5A   : reg_data_out <= s_sign[255:224];
        7'h5B   : reg_data_out <= verifying_r[31:0];
        7'h5C   : reg_data_out <= verifying_r[63:32];
        //7'h5D   : reg_data_out <= verifying_r[95:64];
        //7'h5E   : reg_data_out <= verifying_r[127:96];
        //7'h5F   : reg_data_out <= verifying_r[159:128];
        //7'h60   : reg_data_out <= verifying_r[191:160];
        //7'h61   : reg_data_out <= verifying_r[223:192];
        //7'h62   : reg_data_out <= verifying_r[255:224];
        7'h63   : reg_data_out <= verifying_s[31:0];
        7'h64   : reg_data_out <= verifying_s[63:32];
        //7'h65   : reg_data_out <= verifying_s[95:64];
        //7'h66   : reg_data_out <= verifying_s[127:96];
        //7'h67   : reg_data_out <= verifying_s[159:128];
        //7'h68   : reg_data_out <= verifying_s[191:160];
        //7'h69   : reg_data_out <= verifying_s[223:192];
        //7'h6A   : reg_data_out <= verifying_s[255:224];
        7'h6B   : reg_data_out <= privateKey[31:0];
        7'h6C   : reg_data_out <= privateKey[63:32];
        //7'h6D   : reg_data_out <= privateKey[95:64];
        //7'h6E   : reg_data_out <= privateKey[127:96];
        //7'h6F   : reg_data_out <= privateKey[159:128];
        //7'h70   : reg_data_out <= privateKey[191:160];
        //7'h71   : reg_data_out <= privateKey[223:192];
        //7'h72   : reg_data_out <= privateKey[255:224];
        default : reg_data_out <= 0;
      endcase
end

// Output register or memory read data
always @( posedge S_AXI_ACLK )
begin
  if ( S_AXI_ARESETN == 1'b0 )
    begin
      axi_rdata  <= 0;
    end 
  else
    begin    
      // When there is a valid read address (S_AXI_ARVALID) with 
      // acceptance of read address by the slave (axi_arready), 
      // output the read dada 
      if (slv_reg_rden)
        begin
          axi_rdata <= reg_data_out;     // register read data
        end   
    end
end    

// Add user logic here
assign ecc_go = slv_reg0[0];
assign sign_go = slv_reg1[0];
assign verify_go = slv_reg2[0];
assign message[31:0] = slv_reg3;
//assign message[63:32] = slv_reg4;
//assign message[95:64] = slv_reg5;
//assign message[127:96] = slv_reg6;
//assign message[159:128] = slv_reg7;
//assign message[191:160] = slv_reg8;
//assign message[223:192] = slv_reg9;
//assign message[255:224] = slv_reg10;
//assign message[287:256] = slv_reg11;
//assign message[319:288] = slv_reg12;
//assign message[351:320] = slv_reg13;
//assign message[383:352] = slv_reg14;
//assign message[415:384] = slv_reg15;
//assign message[447:416] = slv_reg16;
//assign message[479:448] = slv_reg17;
//assign message[511:480] = slv_reg18;
assign hashedMessage[31:0] = slv_reg19;
//assign hashedMessage[63:32] = slv_reg20;
//assign hashedMessage[95:64] = slv_reg21;
//assign hashedMessage[127:96] = slv_reg22;
//assign hashedMessage[159:128] = slv_reg23;
//assign hashedMessage[191:160] = slv_reg24;
//assign hashedMessage[223:192] = slv_reg25;
//assign hashedMessage[255:224] = slv_reg26;
//assign hashedMessage[287:256] = slv_reg27;
//assign hashedMessage[319:288] = slv_reg28;
//assign hashedMessage[351:320] = slv_reg29;
//assign hashedMessage[383:352] = slv_reg30;
//assign hashedMessage[415:384] = slv_reg31;
//assign hashedMessage[447:416] = slv_reg32;
//assign hashedMessage[479:448] = slv_reg33;
//assign hashedMessage[511:480] = slv_reg34;
assign trng[31:0] = slv_reg35;
//assign trng[63:32] = slv_reg36;
//assign trng[95:64] = slv_reg37;
//assign trng[127:96] = slv_reg38;
//assign trng[159:128] = slv_reg39;
//assign trng[191:160] = slv_reg40;
//assign trng[223:192] = slv_reg41;
//assign trng[255:224] = slv_reg42;
//assign trng[287:256] = slv_reg43;
//assign trng[319:288] = slv_reg44;
//assign trng[351:320] = slv_reg45;
//assign trng[383:352] = slv_reg46;
//assign trng[415:384] = slv_reg47;
//assign trng[447:416] = slv_reg48;
//assign trng[479:448] = slv_reg49;
//assign trng[511:480] = slv_reg50;
assign prime[31:0] = slv_reg59;
assign prime[63:32] = slv_reg60;
assign A[31:0] = slv_reg61;
assign A[63:32] = slv_reg62;
assign B[31:0] = slv_reg63;
assign B[63:32] = slv_reg64;
assign Gx[31:0] = slv_reg65;
assign Gx[63:32] = slv_reg66;
assign Gy[31:0] = slv_reg67;
assign Gy[63:32] = slv_reg68;
assign n[31:0] = slv_reg69;
assign n[63:32] = slv_reg70;
assign Ox[31:0] = slv_reg71;
assign Ox[63:32] = slv_reg72;
assign Oy[31:0] = slv_reg73;
assign Oy[63:32] = slv_reg74;
//assign r_sign[31:0] = slv_reg75;
//assign r_sign[63:32] = slv_reg76;
//assign r_sign[95:64] = slv_reg77;
//assign r_sign[127:96] = slv_reg78;
//assign r_sign[159:128] = slv_reg79;
//assign r_sign[191:160] = slv_reg80;
//assign r_sign[223:192] = slv_reg81;
//assign r_sign[255:224] = slv_reg82;
//assign s_sign[31:0] = slv_reg83;
//assign s_sign[63:32] = slv_reg84;
//assign s_sign[95:64] = slv_reg85;
//assign s_sign[127:96] = slv_reg86;
//assign s_sign[159:128] = slv_reg87;
//assign s_sign[191:160] = slv_reg88;
//assign s_sign[223:192] = slv_reg89;
//assign s_sign[255:224] = slv_reg90;
assign verifying_r[31:0] = slv_reg91;
assign verifying_r[63:32] = slv_reg92;
//assign verifying_r[95:64] = slv_reg93;
//assign verifying_r[127:96] = slv_reg94;
//assign verifying_r[159:128] = slv_reg95;
//assign verifying_r[191:160] = slv_reg96;
//assign verifying_r[223:192] = slv_reg97;
//assign verifying_r[255:224] = slv_reg98;
assign verifying_s[31:0] = slv_reg99;
assign verifying_s[63:32] = slv_reg100;
//assign verifying_s[95:64] = slv_reg101;
//assign verifying_s[127:96] = slv_reg102;
//assign verifying_s[159:128] = slv_reg103;
//assign verifying_s[191:160] = slv_reg104;
//assign verifying_s[223:192] = slv_reg105;
//assign verifying_s[255:224] = slv_reg106;
assign privateKey[31:0] = slv_reg107;
assign privateKey[63:32] = slv_reg108;
//assign privateKey[95:64] = slv_reg109;
//assign privateKey[127:96] = slv_reg110;
//assign privateKey[159:128] = slv_reg111;
//assign privateKey[191:160] = slv_reg112;
//assign privateKey[223:192] = slv_reg113;
//assign privateKey[255:224] = slv_reg114;


ecdsa_combined #(
        .key_size(key_size),
        .integer_size(integer_size),
        .message_width(message_width)
        ) ecdsa_combined_DUT (
        .clk(S_AXI_ACLK),
        .rst(~S_AXI_ARESETN), 
        .ecc_go(ecc_go),
        .sign_go(sign_go),
        .verify_go(verify_go),
        .infiityPPubKey(infiityPPubKey),
        .message(message),
        .hashedMessage(hashedMessage),
        .trng(trng),
        .privateKey(privateKey),
        .prime(prime), 
        .A(A), 
        .B(B), 
        .Gx(Gx), 
        .Gy(Gy), 
        .Ox(Ox),
        .Oy(Oy),
        .n(n),
        .sign_ready(sign_ready),
        .verify_ready(verify_ready),
        .verified(verified),
        .failure(failure),
        .r_sign(r_sign),
        .s_sign(s_sign),
        .verifying_r(verifying_r),
        .verifying_s(verifying_s),
        .ecc_done(ecc_done),
        .sign_done(sign_done),
        .verify_done(verify_done)
       );
// User logic ends

endmodule

