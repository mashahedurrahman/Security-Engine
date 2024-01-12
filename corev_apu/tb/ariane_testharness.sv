// Copyright 2018 ETH Zurich and University of Bologna.
// Copyright and related rights are licensed under the Solderpad Hardware
// License, Version 0.51 (the "License"); you may not use this file except in
// compliance with the License.  You may obtain a copy of the License at
// http://solderpad.org/licenses/SHL-0.51. Unless required by applicable law
// or agreed to in writing, software, hardware and materials distributed under
// this License is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR
// CONDITIONS OF ANY KIND, either express or implied. See the License for the
// specific language governing permissions and limitations under the License.
//
// Author: Florian Zaruba, ETH Zurich
// Date: 19.03.2017
// Description: Test-harness for Ariane
//              Instantiates an AXI-Bus and memories

`include "axi/assign.svh"

module ariane_testharness #(
  parameter int unsigned AXI_USER_WIDTH    = 1,
  parameter int unsigned AXI_ADDRESS_WIDTH = 64,
  parameter int unsigned AXI_DATA_WIDTH    = 64,
`ifdef DROMAJO
  parameter bit          InclSimDTM        = 1'b0,
`else
  parameter bit          InclSimDTM        = 1'b1,
`endif
  parameter int unsigned NUM_WORDS         = 2**25,         // memory size
  parameter bit          StallRandomOutput = 1'b0,
  parameter bit          StallRandomInput  = 1'b0
) (
  input  logic                           clk_i,
  input  logic                           rtc_i,
  input  logic                           rst_ni,
  output logic [31:0]                    exit_o
);

  localparam [7:0] hart_id = '0;

  // disable test-enable
  logic        test_en;
  logic        ndmreset;
  logic        ndmreset_n;
  logic        debug_req_core;

  int          jtag_enable;
  logic        init_done;
  logic [31:0] jtag_exit, dmi_exit;

  logic        jtag_TCK;
  logic        jtag_TMS;
  logic        jtag_TDI;
  logic        jtag_TRSTn;
  logic        jtag_TDO_data;
  logic        jtag_TDO_driven;

  logic        debug_req_valid;
  logic        debug_req_ready;
  logic        debug_resp_valid;
  logic        debug_resp_ready;

  logic        jtag_req_valid;
  logic [6:0]  jtag_req_bits_addr;
  logic [1:0]  jtag_req_bits_op;
  logic [31:0] jtag_req_bits_data;
  logic        jtag_resp_ready;
  logic        jtag_resp_valid;

  logic        dmi_req_valid;
  logic        dmi_resp_ready;
  logic        dmi_resp_valid;

  dm::dmi_req_t  jtag_dmi_req;
  dm::dmi_req_t  dmi_req;

  dm::dmi_req_t  debug_req;
  dm::dmi_resp_t debug_resp;

  assign test_en = 1'b0;

  AXI_BUS #(
    .AXI_ADDR_WIDTH ( AXI_ADDRESS_WIDTH   ),
    .AXI_DATA_WIDTH ( AXI_DATA_WIDTH      ),
    .AXI_ID_WIDTH   ( ariane_soc::IdWidth ),
    .AXI_USER_WIDTH ( AXI_USER_WIDTH      )
  ) slave[ariane_soc::NrSlaves-1:0]();

  AXI_BUS #(
    .AXI_ADDR_WIDTH ( AXI_ADDRESS_WIDTH        ),
    .AXI_DATA_WIDTH ( AXI_DATA_WIDTH           ),
    .AXI_ID_WIDTH   ( ariane_soc::IdWidthSlave ),
    .AXI_USER_WIDTH ( AXI_USER_WIDTH           )
  ) master[ariane_soc::NB_PERIPHERALS-1:0]();

  rstgen i_rstgen_main (
    .clk_i        ( clk_i                ),
    .rst_ni       ( rst_ni & (~ndmreset) ),
    .test_mode_i  ( test_en              ),
    .rst_no       ( ndmreset_n           ),
    .init_no      (                      ) // keep open
  );

  // ---------------
  // Debug
  // ---------------
  assign init_done = rst_ni;

  logic debug_enable;
  initial begin
    if (!$value$plusargs("jtag_rbb_enable=%b", jtag_enable)) jtag_enable = 'h0;
    if ($test$plusargs("debug_disable")) debug_enable = 'h0; else debug_enable = 'h1;
    if (riscv::XLEN != 32 & riscv::XLEN != 64) $error("XLEN different from 32 and 64");
  end

  // debug if MUX
  assign debug_req_valid     = (jtag_enable[0]) ? jtag_req_valid     : dmi_req_valid;
  assign debug_resp_ready    = (jtag_enable[0]) ? jtag_resp_ready    : dmi_resp_ready;
  assign debug_req           = (jtag_enable[0]) ? jtag_dmi_req       : dmi_req;
  assign exit_o              = (jtag_enable[0]) ? jtag_exit          : dmi_exit;
  assign jtag_resp_valid     = (jtag_enable[0]) ? debug_resp_valid   : 1'b0;
  assign dmi_resp_valid      = (jtag_enable[0]) ? 1'b0               : debug_resp_valid;

  // SiFive's SimJTAG Module
  // Converts to DPI calls
  //SimJTAG i_SimJTAG (
  //  .clock                ( clk_i                ),
  //  .reset                ( ~rst_ni              ),
  //  .enable               ( jtag_enable[0]       ),
  //  .init_done            ( init_done            ),
  //  .jtag_TCK             ( jtag_TCK             ),
  //  .jtag_TMS             ( jtag_TMS             ),
  //  .jtag_TDI             ( jtag_TDI             ),
  //  .jtag_TRSTn           ( jtag_TRSTn           ),
  //  .jtag_TDO_data        ( jtag_TDO_data        ),
  //  .jtag_TDO_driven      ( jtag_TDO_driven      ),
  //  .exit                 ( jtag_exit            )
  //);

  dmi_jtag i_dmi_jtag (
    .clk_i            ( clk_i           ),
    .rst_ni           ( rst_ni          ),
    .testmode_i       ( test_en         ),
    .dmi_req_o        ( jtag_dmi_req    ),
    .dmi_req_valid_o  ( jtag_req_valid  ),
    .dmi_req_ready_i  ( debug_req_ready ),
    .dmi_resp_i       ( debug_resp      ),
    .dmi_resp_ready_o ( jtag_resp_ready ),
    .dmi_resp_valid_i ( jtag_resp_valid ),
    .dmi_rst_no       (                 ), // not connected
    .tck_i            ( jtag_TCK        ),
    .tms_i            ( jtag_TMS        ),
    .trst_ni          ( jtag_TRSTn      ),
    .td_i             ( jtag_TDI        ),
    .td_o             ( jtag_TDO_data   ),
    .tdo_oe_o         ( jtag_TDO_driven )
  );

  // SiFive's SimDTM Module
  // Converts to DPI calls
  logic [1:0] debug_req_bits_op;
  assign dmi_req.op = dm::dtm_op_e'(debug_req_bits_op);

  //if (InclSimDTM) begin
  //  SimDTM i_SimDTM (
  //    .clk                  ( clk_i                 ),
  //    .reset                ( ~rst_ni               ),
  //    .debug_req_valid      ( dmi_req_valid         ),
  //    .debug_req_ready      ( debug_req_ready       ),
  //    .debug_req_bits_addr  ( dmi_req.addr          ),
  //    .debug_req_bits_op    ( debug_req_bits_op     ),
  //    .debug_req_bits_data  ( dmi_req.data          ),
  //    .debug_resp_valid     ( dmi_resp_valid        ),
  //    .debug_resp_ready     ( dmi_resp_ready        ),
  //    .debug_resp_bits_resp ( debug_resp.resp       ),
  //    .debug_resp_bits_data ( debug_resp.data       ),
  //    .exit                 ( dmi_exit              )
  //  );
  //end else begin
    assign dmi_req_valid = '0;
    assign debug_req_bits_op = '0;
    assign dmi_exit = 1'b0;
  //end

  // this delay window allows the core to read and execute init code
  // from the bootrom before the first debug request can interrupt
  // core. this is needed in cases where an fsbl is involved that
  // expects a0 and a1 to be initialized with the hart id and a
  // pointer to the dev tree, respectively.
  localparam int unsigned DmiDelCycles = 500;

  logic debug_req_core_ungtd;
  int dmi_del_cnt_d, dmi_del_cnt_q;

  assign dmi_del_cnt_d  = (dmi_del_cnt_q) ? dmi_del_cnt_q - 1 : 0;
  assign debug_req_core = (dmi_del_cnt_q) ? 1'b0 :
                          (!debug_enable) ? 1'b0 : debug_req_core_ungtd;

  always_ff @(posedge clk_i or negedge rst_ni) begin : p_dmi_del_cnt
    if(!rst_ni) begin
      dmi_del_cnt_q <= DmiDelCycles;
    end else begin
      dmi_del_cnt_q <= dmi_del_cnt_d;
    end
  end

  ariane_axi_soc::req_t    dm_axi_m_req;
  ariane_axi_soc::resp_t   dm_axi_m_resp;

  logic                dm_slave_req;
  logic                dm_slave_we;
  logic [64-1:0]       dm_slave_addr;
  logic [64/8-1:0]     dm_slave_be;
  logic [64-1:0]       dm_slave_wdata;
  logic [64-1:0]       dm_slave_rdata;

  logic                dm_master_req;
  logic [64-1:0]       dm_master_add;
  logic                dm_master_we;
  logic [64-1:0]       dm_master_wdata;
  logic [64/8-1:0]     dm_master_be;
  logic                dm_master_gnt;
  logic                dm_master_r_valid;
  logic [64-1:0]       dm_master_r_rdata;

  // debug module
  dm_top #(
    .NrHarts              ( 1                           ),
    .BusWidth             ( AXI_DATA_WIDTH              ),
    .SelectableHarts      ( 1'b1                        )
  ) i_dm_top (
    .clk_i                ( clk_i                       ),
    .rst_ni               ( rst_ni                      ), // PoR
    .testmode_i           ( test_en                     ),
    .ndmreset_o           ( ndmreset                    ),
    .dmactive_o           (                             ), // active debug session
    .debug_req_o          ( debug_req_core_ungtd        ),
    .unavailable_i        ( '0                          ),
    .hartinfo_i           ( {ariane_pkg::DebugHartInfo} ),
    .slave_req_i          ( dm_slave_req                ),
    .slave_we_i           ( dm_slave_we                 ),
    .slave_addr_i         ( dm_slave_addr               ),
    .slave_be_i           ( dm_slave_be                 ),
    .slave_wdata_i        ( dm_slave_wdata              ),
    .slave_rdata_o        ( dm_slave_rdata              ),
    .master_req_o         ( dm_master_req               ),
    .master_add_o         ( dm_master_add               ),
    .master_we_o          ( dm_master_we                ),
    .master_wdata_o       ( dm_master_wdata             ),
    .master_be_o          ( dm_master_be                ),
    .master_gnt_i         ( dm_master_gnt               ),
    .master_r_valid_i     ( dm_master_r_valid           ),
    .master_r_rdata_i     ( dm_master_r_rdata           ),
    .dmi_rst_ni           ( rst_ni                      ),
    .dmi_req_valid_i      ( debug_req_valid             ),
    .dmi_req_ready_o      ( debug_req_ready             ),
    .dmi_req_i            ( debug_req                   ),
    .dmi_resp_valid_o     ( debug_resp_valid            ),
    .dmi_resp_ready_i     ( debug_resp_ready            ),
    .dmi_resp_o           ( debug_resp                  )
  );


  axi2mem #(
    .AXI_ID_WIDTH   ( ariane_soc::IdWidthSlave ),
    .AXI_ADDR_WIDTH ( AXI_ADDRESS_WIDTH        ),
    .AXI_DATA_WIDTH ( AXI_DATA_WIDTH           ),
    .AXI_USER_WIDTH ( AXI_USER_WIDTH           )
  ) i_dm_axi2mem (
    .clk_i      ( clk_i                     ),
    .rst_ni     ( rst_ni                    ),
    .slave      ( master[ariane_soc::Debug] ),
    .req_o      ( dm_slave_req              ),
    .we_o       ( dm_slave_we               ),
    .addr_o     ( dm_slave_addr             ),
    .be_o       ( dm_slave_be               ),
    .data_o     ( dm_slave_wdata            ),
    .data_i     ( dm_slave_rdata            )
  );

  `AXI_ASSIGN_FROM_REQ(slave[1], dm_axi_m_req)
  `AXI_ASSIGN_TO_RESP(dm_axi_m_resp, slave[1])

  axi_adapter #(
    .DATA_WIDTH            ( AXI_DATA_WIDTH            ),
    .AXI_ID_WIDTH          ( ariane_soc::IdWidth       )
  ) i_dm_axi_master (
    .clk_i                 ( clk_i                     ),
    .rst_ni                ( rst_ni                    ),
    .req_i                 ( dm_master_req             ),
    .type_i                ( ariane_axi::SINGLE_REQ    ),
    .gnt_o                 ( dm_master_gnt             ),
    .gnt_id_o              (                           ),
    .addr_i                ( dm_master_add             ),
    .we_i                  ( dm_master_we              ),
    .wdata_i               ( dm_master_wdata           ),
    .be_i                  ( dm_master_be              ),
    .size_i                ( 2'b11                     ), // always do 64bit here and use byte enables to gate
    .id_i                  ( '0                        ),
    .valid_o               ( dm_master_r_valid         ),
    .rdata_o               ( dm_master_r_rdata         ),
    .id_o                  (                           ),
    .critical_word_o       (                           ),
    .critical_word_valid_o (                           ),
    .axi_req_o             ( dm_axi_m_req              ),
    .axi_resp_i            ( dm_axi_m_resp             )
  );


  // ---------------
  // ROM
  // ---------------
  logic                         rom_req;
  logic [AXI_ADDRESS_WIDTH-1:0] rom_addr;
  logic [AXI_DATA_WIDTH-1:0]    rom_rdata;

  axi2mem #(
    .AXI_ID_WIDTH   ( ariane_soc::IdWidthSlave ),
    .AXI_ADDR_WIDTH ( AXI_ADDRESS_WIDTH        ),
    .AXI_DATA_WIDTH ( AXI_DATA_WIDTH           ),
    .AXI_USER_WIDTH ( AXI_USER_WIDTH           )
  ) i_axi2rom (
    .clk_i  ( clk_i                   ),
    .rst_ni ( ndmreset_n              ),
    .slave  ( master[ariane_soc::ROM] ),
    .req_o  ( rom_req                 ),
    .we_o   (                         ),
    .addr_o ( rom_addr                ),
    .be_o   (                         ),
    .data_o (                         ),
    .data_i ( rom_rdata               )
  );

`ifdef DROMAJO
  dromajo_bootrom i_bootrom (
    .clk_i      ( clk_i     ),
    .req_i      ( rom_req   ),
    .addr_i     ( rom_addr  ),
    .rdata_o    ( rom_rdata )
  );
`else
  bootrom i_bootrom (
    .clk_i      ( clk_i     ),
    .req_i      ( rom_req   ),
    .addr_i     ( rom_addr  ),
    .rdata_o    ( rom_rdata )
  );
`endif

  // ------------------------------
  // GPIO
  // ------------------------------

  // GPIO not implemented, adding an error slave here

  ariane_axi_soc::req_slv_t  gpio_req;
  ariane_axi_soc::resp_slv_t gpio_resp;
  `AXI_ASSIGN_TO_REQ(gpio_req, master[ariane_soc::GPIO])
  `AXI_ASSIGN_FROM_RESP(master[ariane_soc::GPIO], gpio_resp)
  axi_err_slv #(
    .AxiIdWidth ( ariane_soc::IdWidthSlave   ),
    .req_t      ( ariane_axi_soc::req_slv_t  ),
    .resp_t     ( ariane_axi_soc::resp_slv_t )
  ) i_gpio_err_slv (
    .clk_i      ( clk_i      ),
    .rst_ni     ( ndmreset_n ),
    .test_i     ( test_en    ),
    .slv_req_i  ( gpio_req ),
    .slv_resp_o ( gpio_resp )
  );


  // ------------------------------
  // Memory + Exclusive Access
  // ------------------------------
  AXI_BUS #(
    .AXI_ADDR_WIDTH ( AXI_ADDRESS_WIDTH        ),
    .AXI_DATA_WIDTH ( AXI_DATA_WIDTH           ),
    .AXI_ID_WIDTH   ( ariane_soc::IdWidthSlave ),
    .AXI_USER_WIDTH ( AXI_USER_WIDTH           )
  ) dram();

  logic                         req;
  logic                         we;
  logic [AXI_ADDRESS_WIDTH-1:0] addr;
  logic [AXI_DATA_WIDTH/8-1:0]  be;
  logic [AXI_DATA_WIDTH-1:0]    wdata;
  logic [AXI_DATA_WIDTH-1:0]    rdata;

  axi_riscv_atomics_wrap #(
    .AXI_ADDR_WIDTH ( AXI_ADDRESS_WIDTH        ),
    .AXI_DATA_WIDTH ( AXI_DATA_WIDTH           ),
    .AXI_ID_WIDTH   ( ariane_soc::IdWidthSlave ),
    .AXI_USER_WIDTH ( AXI_USER_WIDTH           ),
    .AXI_MAX_WRITE_TXNS ( 1  ),
    .RISCV_WORD_WIDTH   ( 64 )
  ) i_axi_riscv_atomics (
    .clk_i,
    .rst_ni ( ndmreset_n               ),
    .slv    ( master[ariane_soc::DRAM] ),
    .mst    ( dram                     )
  );

  AXI_BUS #(
    .AXI_ADDR_WIDTH ( AXI_ADDRESS_WIDTH        ),
    .AXI_DATA_WIDTH ( AXI_DATA_WIDTH           ),
    .AXI_ID_WIDTH   ( ariane_soc::IdWidthSlave ),
    .AXI_USER_WIDTH ( AXI_USER_WIDTH           )
  ) dram_delayed();

  axi_delayer_intf #(
    .AXI_ID_WIDTH        ( ariane_soc::IdWidthSlave ),
    .AXI_ADDR_WIDTH      ( AXI_ADDRESS_WIDTH        ),
    .AXI_DATA_WIDTH      ( AXI_DATA_WIDTH           ),
    .AXI_USER_WIDTH      ( AXI_USER_WIDTH           ),
    .STALL_RANDOM_INPUT  ( StallRandomInput         ),
    .STALL_RANDOM_OUTPUT ( StallRandomOutput        ),
    .FIXED_DELAY_INPUT   ( 0                        ),
    .FIXED_DELAY_OUTPUT  ( 0                        )
  ) i_axi_delayer (
    .clk_i  ( clk_i        ),
    .rst_ni ( ndmreset_n   ),
    .slv    ( dram         ),
    .mst    ( dram_delayed )
  );

  axi2mem #(
    .AXI_ID_WIDTH   ( ariane_soc::IdWidthSlave ),
    .AXI_ADDR_WIDTH ( AXI_ADDRESS_WIDTH        ),
    .AXI_DATA_WIDTH ( AXI_DATA_WIDTH           ),
    .AXI_USER_WIDTH ( AXI_USER_WIDTH           )
  ) i_axi2mem (
    .clk_i  ( clk_i        ),
    .rst_ni ( ndmreset_n   ),
    .slave  ( dram_delayed ),
    .req_o  ( req          ),
    .we_o   ( we           ),
    .addr_o ( addr         ),
    .be_o   ( be           ),
    .data_o ( wdata        ),
    .data_i ( rdata        )
  );

  sram #(
    .DATA_WIDTH ( AXI_DATA_WIDTH ),
`ifdef DROMAJO
    .DROMAJO_RAM (1),
`endif
    .NUM_WORDS  ( NUM_WORDS      )
  ) i_sram (
    .clk_i      ( clk_i                                                                       ),
    .rst_ni     ( rst_ni                                                                      ),
    .req_i      ( req                                                                         ),
    .we_i       ( we                                                                          ),
    .addr_i     ( addr[$clog2(NUM_WORDS)-1+$clog2(AXI_DATA_WIDTH/8):$clog2(AXI_DATA_WIDTH/8)] ),
    .wdata_i    ( wdata                                                                       ),
    .be_i       ( be                                                                          ),
    .rdata_o    ( rdata                                                                       )
  );

  // ---------------
  // AXI Xbar
  // ---------------

  axi_pkg::xbar_rule_64_t [ariane_soc::NB_PERIPHERALS-1:0] addr_map;

  assign addr_map = '{
    '{ idx: ariane_soc::Debug,    start_addr: ariane_soc::DebugBase,    end_addr: ariane_soc::DebugBase + ariane_soc::DebugLength       },
    '{ idx: ariane_soc::ROM,      start_addr: ariane_soc::ROMBase,      end_addr: ariane_soc::ROMBase + ariane_soc::ROMLength           },
    '{ idx: ariane_soc::CLINT,    start_addr: ariane_soc::CLINTBase,    end_addr: ariane_soc::CLINTBase + ariane_soc::CLINTLength       },
    '{ idx: ariane_soc::PLIC,     start_addr: ariane_soc::PLICBase,     end_addr: ariane_soc::PLICBase + ariane_soc::PLICLength         },
    '{ idx: ariane_soc::UART,     start_addr: ariane_soc::UARTBase,     end_addr: ariane_soc::UARTBase + ariane_soc::UARTLength         },
    '{ idx: ariane_soc::Timer,    start_addr: ariane_soc::TimerBase,    end_addr: ariane_soc::TimerBase + ariane_soc::TimerLength       },
    '{ idx: ariane_soc::SPI,      start_addr: ariane_soc::SPIBase,      end_addr: ariane_soc::SPIBase + ariane_soc::SPILength           },
    '{ idx: ariane_soc::Ethernet, start_addr: ariane_soc::EthernetBase, end_addr: ariane_soc::EthernetBase + ariane_soc::EthernetLength },
    '{ idx: ariane_soc::GPIO,     start_addr: ariane_soc::GPIOBase,     end_addr: ariane_soc::GPIOBase + ariane_soc::GPIOLength         },
    '{ idx: ariane_soc::ECDSA,    start_addr: ariane_soc::ECDSABase,    end_addr: ariane_soc::ECDSABase + ariane_soc::ECDSALength       },
    '{ idx: ariane_soc::DH,       start_addr: ariane_soc::DHBase,       end_addr: ariane_soc::DHBase + ariane_soc::DHLength             },
    '{ idx: ariane_soc::AES,      start_addr: ariane_soc::AESBase,      end_addr: ariane_soc::AESBase + ariane_soc::AESLength           },
    '{ idx: ariane_soc::ECC,      start_addr: ariane_soc::ECCBase,      end_addr: ariane_soc::ECCBase + ariane_soc::ECCLength           },
    '{ idx: ariane_soc::TRNG,     start_addr: ariane_soc::TRNGBase,     end_addr: ariane_soc::TRNGBase + ariane_soc::TRNGLength         },
    '{ idx: ariane_soc::RSA,      start_addr: ariane_soc::RSABase,      end_addr: ariane_soc::RSABase + ariane_soc::RSALength           },
    '{ idx: ariane_soc::SHA,      start_addr: ariane_soc::SHABase,      end_addr: ariane_soc::SHABase + ariane_soc::SHALength           },
    '{ idx: ariane_soc::ODO,      start_addr: ariane_soc::ODOBase,      end_addr: ariane_soc::ODOBase + ariane_soc::ODOLength           },
    '{ idx: ariane_soc::PUF,      start_addr: ariane_soc::PUFBase,      end_addr: ariane_soc::PUFBase + ariane_soc::PUFLength           },
    '{ idx: ariane_soc::ECIES,    start_addr: ariane_soc::ECIESBase,    end_addr: ariane_soc::ECIESBase + ariane_soc::ECIESLength       },
    '{ idx: ariane_soc::DRAM,     start_addr: ariane_soc::DRAMBase,     end_addr: ariane_soc::DRAMBase + ariane_soc::DRAMLength         }
  };

  localparam axi_pkg::xbar_cfg_t AXI_XBAR_CFG = '{
    NoSlvPorts: ariane_soc::NrSlaves,
    NoMstPorts: ariane_soc::NB_PERIPHERALS,
    MaxMstTrans: 1, // Probably requires update
    MaxSlvTrans: 1, // Probably requires update
    FallThrough: 1'b0,
    LatencyMode: axi_pkg::NO_LATENCY,
    AxiIdWidthSlvPorts: ariane_soc::IdWidth,
    AxiIdUsedSlvPorts: ariane_soc::IdWidth,
    UniqueIds: 1'b0,
    AxiAddrWidth: AXI_ADDRESS_WIDTH,
    AxiDataWidth: AXI_DATA_WIDTH,
    NoAddrRules: ariane_soc::NB_PERIPHERALS
  };

  axi_xbar_intf #(
    .AXI_USER_WIDTH ( AXI_USER_WIDTH          ),
    .Cfg            ( AXI_XBAR_CFG            ),
    .rule_t         ( axi_pkg::xbar_rule_64_t )
  ) i_axi_xbar (
    .clk_i                 ( clk_i      ),
    .rst_ni                ( ndmreset_n ),
    .test_i                ( test_en    ),
    .slv_ports             ( slave      ),
    .mst_ports             ( master     ),
    .addr_map_i            ( addr_map   ),
    .en_default_mst_port_i ( '0         ),
    .default_mst_port_i    ( '0         )
  );


  // ---------------
  // RSA : mash
  // ---------------
  AXI_LITE #(
      .AXI_ADDR_WIDTH (64),
      .AXI_DATA_WIDTH (64)
  ) rsa_lite();

  axi_to_axi_lite_mod  axi_to_axi_lite_rsa (
      .clk_i      (clk_i),
      .rst_ni     (ndmreset_n),
      .testmode_i (test_en),
      .in         (master[ariane_soc::RSA]),
      .out        (rsa_lite)
  );

  rsa_wrapper  rsa (
      .S_AXI_ACLK          (clk_i   ),
      .S_AXI_ARESETN       (ndmreset_n   ),
      .S_AXI_AWADDR        (rsa_lite.aw_addr   ),
      .S_AXI_AWPROT        (   ),
      .S_AXI_AWVALID       (rsa_lite.aw_valid   ),
      .S_AXI_AWREADY       (rsa_lite.aw_ready   ),
      .S_AXI_WDATA         (rsa_lite.w_data   ),
      .S_AXI_WSTRB         (rsa_lite.w_strb   ),
      .S_AXI_WVALID        (rsa_lite.w_valid   ),
      .S_AXI_WREADY        (rsa_lite.w_ready   ),
      .S_AXI_BRESP         (rsa_lite.b_resp   ),
      .S_AXI_BVALID        (rsa_lite.b_valid   ),
      .S_AXI_BREADY        (rsa_lite.b_ready   ),
      .S_AXI_ARADDR        (rsa_lite.ar_addr   ),
      .S_AXI_ARPROT        (   ),
      .S_AXI_ARVALID       (rsa_lite.ar_valid   ),
      .S_AXI_ARREADY       (rsa_lite.ar_ready   ),
      .S_AXI_RDATA         (rsa_lite.r_data   ),
      .S_AXI_RRESP         (rsa_lite.r_resp   ),
      .S_AXI_RVALID        (rsa_lite.r_valid   ),
      .S_AXI_RREADY        (rsa_lite.r_ready   )
  );


  // ---------------
  // TRNG : mash
  // ---------------
  AXI_LITE #(
      .AXI_ADDR_WIDTH (32),
      .AXI_DATA_WIDTH (32)
  ) trng_lite();

  axi_to_axi_lite_mod  axi_to_axi_lite_trng (
      .clk_i      (clk_i),
      .rst_ni     (ndmreset_n),
      .testmode_i (test_en),
      .in         (master[ariane_soc::TRNG]),
      .out        (trng_lite)
  );

  trng_128_wrapper  trng (
      .S_AXI_ACLK          (clk_i   ),
      .S_AXI_ARESETN       (ndmreset_n   ),
      .S_AXI_AWADDR        (trng_lite.aw_addr   ),
      .S_AXI_AWPROT        (   ),
      .S_AXI_AWVALID       (trng_lite.aw_valid   ),
      .S_AXI_AWREADY       (trng_lite.aw_ready   ),
      .S_AXI_WDATA         (trng_lite.w_data   ),
      .S_AXI_WSTRB         (trng_lite.w_strb   ),
      .S_AXI_WVALID        (trng_lite.w_valid   ),
      .S_AXI_WREADY        (trng_lite.w_ready   ),
      .S_AXI_BRESP         (trng_lite.b_resp   ),
      .S_AXI_BVALID        (trng_lite.b_valid   ),
      .S_AXI_BREADY        (trng_lite.b_ready   ),
      .S_AXI_ARADDR        (trng_lite.ar_addr   ),
      .S_AXI_ARPROT        (   ),
      .S_AXI_ARVALID       (trng_lite.ar_valid   ),
      .S_AXI_ARREADY       (trng_lite.ar_ready   ),
      .S_AXI_RDATA         (trng_lite.r_data   ),
      .S_AXI_RRESP         (trng_lite.r_resp   ),
      .S_AXI_RVALID        (trng_lite.r_valid   ),
      .S_AXI_RREADY        (trng_lite.r_ready   )
  );



  // ---------------
  // ECIES : mash
  // ---------------
  //axi_to_axi_lite_intf  #(
  //    .AXI_ADDR_WIDTH (32),
  //    .AXI_DATA_WIDTH (32),
  //    .AXI_ID_WIDTH   ( ariane_soc::IdWidthSlave ),
  //    .AXI_USER_WIDTH ( AXI_USER_WIDTH           )
  //) axi_to_axi_lite_ecies (
  //    .clk_i      (clk_i),
  //    .rst_ni     (ndmreset_n),
  //    .testmode_i (test_en),
  //    .slv        (master[ariane_soc::ECIES]),
  //    .mst        (ecies_lite)
  //);

  AXI_LITE #(
      .AXI_ADDR_WIDTH (32),
      .AXI_DATA_WIDTH (32)
  ) ecies_lite();

  axi_to_axi_lite_mod  axi_to_axi_lite_ecies (
      .clk_i      (clk_i),
      .rst_ni     (ndmreset_n),
      .testmode_i (test_en),
      .in         (master[ariane_soc::ECIES]),
      .out        (ecies_lite)
  );

  ECIES_wrapper  ecies (
      .S_AXI_ACLK          (clk_i   ),
      .S_AXI_ARESETN       (ndmreset_n   ),
      .S_AXI_AWADDR        (ecies_lite.aw_addr   ),
      .S_AXI_AWPROT        (   ),
      .S_AXI_AWVALID       (ecies_lite.aw_valid   ),
      .S_AXI_AWREADY       (ecies_lite.aw_ready   ),
      .S_AXI_WDATA         (ecies_lite.w_data   ),
      .S_AXI_WSTRB         (ecies_lite.w_strb   ),
      .S_AXI_WVALID        (ecies_lite.w_valid   ),
      .S_AXI_WREADY        (ecies_lite.w_ready   ),
      .S_AXI_BRESP         (ecies_lite.b_resp   ),
      .S_AXI_BVALID        (ecies_lite.b_valid   ),
      .S_AXI_BREADY        (ecies_lite.b_ready   ),
      .S_AXI_ARADDR        (ecies_lite.ar_addr   ),
      .S_AXI_ARPROT        (   ),
      .S_AXI_ARVALID       (ecies_lite.ar_valid   ),
      .S_AXI_ARREADY       (ecies_lite.ar_ready   ),
      .S_AXI_RDATA         (ecies_lite.r_data   ),
      .S_AXI_RRESP         (ecies_lite.r_resp   ),
      .S_AXI_RVALID        (ecies_lite.r_valid   ),
      .S_AXI_RREADY        (ecies_lite.r_ready   )
  );


  // ---------------
  // PUF: Shams 
  // ---------------
  AXI_LITE #(
      .AXI_ADDR_WIDTH (32),
      .AXI_DATA_WIDTH (32)
  ) PUF_lite();

  axi_to_axi_lite_mod  axi_to_axi_lite_PUF (
      .clk_i      (clk_i),
      .rst_ni     (ndmreset_n),
      .testmode_i (test_en),
      .in         (master[ariane_soc::PUF]),
      .out        (PUF_lite)
  );

  PUF_wrapper  PUF (
      .S_AXI_ACLK          (clk_i   ),
      .S_AXI_ARESETN       (ndmreset_n   ),
      .S_AXI_AWADDR        (PUF_lite.aw_addr   ),
      .S_AXI_AWPROT        (   ),
      .S_AXI_AWVALID       (PUF_lite.aw_valid   ),
      .S_AXI_AWREADY       (PUF_lite.aw_ready   ),
      .S_AXI_WDATA         (PUF_lite.w_data   ),
      .S_AXI_WSTRB         (PUF_lite.w_strb   ),
      .S_AXI_WVALID        (PUF_lite.w_valid   ),
      .S_AXI_WREADY        (PUF_lite.w_ready   ),
      .S_AXI_BRESP         (PUF_lite.b_resp   ),
      .S_AXI_BVALID        (PUF_lite.b_valid   ),
      .S_AXI_BREADY        (PUF_lite.b_ready   ),
      .S_AXI_ARADDR        (PUF_lite.ar_addr   ),
      .S_AXI_ARPROT        (   ),
      .S_AXI_ARVALID       (PUF_lite.ar_valid   ),
      .S_AXI_ARREADY       (PUF_lite.ar_ready   ),
      .S_AXI_RDATA         (PUF_lite.r_data   ),
      .S_AXI_RRESP         (PUF_lite.r_resp   ),
      .S_AXI_RVALID        (PUF_lite.r_valid   ),
      .S_AXI_RREADY        (PUF_lite.r_ready   )
  );


  // ---------------
  // RO_ODOMETER : azim
  // ---------------
  AXI_LITE #(
      .AXI_ADDR_WIDTH (32),
      .AXI_DATA_WIDTH (32)
  ) RO_ODOMETER_lite();

  axi_to_axi_lite_mod  axi_to_axi_lite_RO_ODOMETER (
      .clk_i      (clk_i),
      .rst_ni     (ndmreset_n),
      .testmode_i (test_en),
      .in         (master[ariane_soc::ODO]),
      .out        (RO_ODOMETER_lite)
  );

  ro_odometer_wrapper  RO_ODOMETER (
      .S_AXI_ACLK          (clk_i   ),
      .S_AXI_ARESETN       (ndmreset_n   ),
      .S_AXI_AWADDR        (RO_ODOMETER_lite.aw_addr   ),
      .S_AXI_AWPROT        (   ),
      .S_AXI_AWVALID       (RO_ODOMETER_lite.aw_valid   ),
      .S_AXI_AWREADY       (RO_ODOMETER_lite.aw_ready   ),
      .S_AXI_WDATA         (RO_ODOMETER_lite.w_data   ),
      .S_AXI_WSTRB         (RO_ODOMETER_lite.w_strb   ),
      .S_AXI_WVALID        (RO_ODOMETER_lite.w_valid   ),
      .S_AXI_WREADY        (RO_ODOMETER_lite.w_ready   ),
      .S_AXI_BRESP         (RO_ODOMETER_lite.b_resp   ),
      .S_AXI_BVALID        (RO_ODOMETER_lite.b_valid   ),
      .S_AXI_BREADY        (RO_ODOMETER_lite.b_ready   ),
      .S_AXI_ARADDR        (RO_ODOMETER_lite.ar_addr   ),
      .S_AXI_ARPROT        (   ),
      .S_AXI_ARVALID       (RO_ODOMETER_lite.ar_valid   ),
      .S_AXI_ARREADY       (RO_ODOMETER_lite.ar_ready   ),
      .S_AXI_RDATA         (RO_ODOMETER_lite.r_data   ),
      .S_AXI_RRESP         (RO_ODOMETER_lite.r_resp   ),
      .S_AXI_RVALID        (RO_ODOMETER_lite.r_valid   ),
      .S_AXI_RREADY        (RO_ODOMETER_lite.r_ready   )
  );


  // ---------------
  // SHA : azim
  // ---------------
  AXI_LITE #(
      .AXI_ADDR_WIDTH (32),
      .AXI_DATA_WIDTH (32)
  ) SHA_lite();

  axi_to_axi_lite_mod  axi_to_axi_lite_SHA (
      .clk_i      (clk_i),
      .rst_ni     (ndmreset_n),
      .testmode_i (test_en),
      .in         (master[ariane_soc::SHA]),
      .out        (SHA_lite)
  );

  sha_wrapper  SHA (
      .S_AXI_ACLK          (clk_i   ),
      .S_AXI_ARESETN       (ndmreset_n   ),
      .S_AXI_AWADDR        (SHA_lite.aw_addr   ),
      .S_AXI_AWPROT        (   ),
      .S_AXI_AWVALID       (SHA_lite.aw_valid   ),
      .S_AXI_AWREADY       (SHA_lite.aw_ready   ),
      .S_AXI_WDATA         (SHA_lite.w_data   ),
      .S_AXI_WSTRB         (SHA_lite.w_strb   ),
      .S_AXI_WVALID        (SHA_lite.w_valid   ),
      .S_AXI_WREADY        (SHA_lite.w_ready   ),
      .S_AXI_BRESP         (SHA_lite.b_resp   ),
      .S_AXI_BVALID        (SHA_lite.b_valid   ),
      .S_AXI_BREADY        (SHA_lite.b_ready   ),
      .S_AXI_ARADDR        (SHA_lite.ar_addr   ),
      .S_AXI_ARPROT        (   ),
      .S_AXI_ARVALID       (SHA_lite.ar_valid   ),
      .S_AXI_ARREADY       (SHA_lite.ar_ready   ),
      .S_AXI_RDATA         (SHA_lite.r_data   ),
      .S_AXI_RRESP         (SHA_lite.r_resp   ),
      .S_AXI_RVALID        (SHA_lite.r_valid   ),
      .S_AXI_RREADY        (SHA_lite.r_ready   )
  );


  // ---------------
  // ECC : Dr. Sujan
  // ---------------
  AXI_LITE #(
      .AXI_ADDR_WIDTH (32),
      .AXI_DATA_WIDTH (32)
  ) ecc_lite();

  axi_to_axi_lite_mod  axi_to_axi_lite_ecc (
      .clk_i      (clk_i),
      .rst_ni     (ndmreset_n),
      .testmode_i (test_en),
      .in         (master[ariane_soc::ECC]),
      .out        (ecc_lite)
  );

  ECC_v1_0_S00_AXI  ecc (
      .S_AXI_ACLK          (clk_i   ),
      .S_AXI_ARESETN       (ndmreset_n   ),
      .S_AXI_AWADDR        (ecc_lite.aw_addr   ),
      .S_AXI_AWPROT        (   ),
      .S_AXI_AWVALID       (ecc_lite.aw_valid   ),
      .S_AXI_AWREADY       (ecc_lite.aw_ready   ),
      .S_AXI_WDATA         (ecc_lite.w_data   ),
      .S_AXI_WSTRB         (ecc_lite.w_strb   ),
      .S_AXI_WVALID        (ecc_lite.w_valid   ),
      .S_AXI_WREADY        (ecc_lite.w_ready   ),
      .S_AXI_BRESP         (ecc_lite.b_resp   ),
      .S_AXI_BVALID        (ecc_lite.b_valid   ),
      .S_AXI_BREADY        (ecc_lite.b_ready   ),
      .S_AXI_ARADDR        (ecc_lite.ar_addr   ),
      .S_AXI_ARPROT        (   ),
      .S_AXI_ARVALID       (ecc_lite.ar_valid   ),
      .S_AXI_ARREADY       (ecc_lite.ar_ready   ),
      .S_AXI_RDATA         (ecc_lite.r_data   ),
      .S_AXI_RRESP         (ecc_lite.r_resp   ),
      .S_AXI_RVALID        (ecc_lite.r_valid   ),
      .S_AXI_RREADY        (ecc_lite.r_ready   )
  );



  // ---------------
  // AES : mash
  // ---------------
  AXI_LITE #(
      .AXI_ADDR_WIDTH (32),
      .AXI_DATA_WIDTH (32)
  ) aes_lite();

  axi_to_axi_lite_mod  axi_to_axi_lite_aes (
      .clk_i      (clk_i),
      .rst_ni     (ndmreset_n),
      .testmode_i (test_en),
      .in         (master[ariane_soc::AES]),
      .out        (aes_lite)
  );

  aes_ctr_wrapper  aes (
      .S_AXI_ACLK          (clk_i   ),
      .S_AXI_ARESETN       (ndmreset_n   ),
      .S_AXI_AWADDR        (aes_lite.aw_addr   ),
      .S_AXI_AWPROT        (   ),
      .S_AXI_AWVALID       (aes_lite.aw_valid   ),
      .S_AXI_AWREADY       (aes_lite.aw_ready   ),
      .S_AXI_WDATA         (aes_lite.w_data   ),
      .S_AXI_WSTRB         (aes_lite.w_strb   ),
      .S_AXI_WVALID        (aes_lite.w_valid   ),
      .S_AXI_WREADY        (aes_lite.w_ready   ),
      .S_AXI_BRESP         (aes_lite.b_resp   ),
      .S_AXI_BVALID        (aes_lite.b_valid   ),
      .S_AXI_BREADY        (aes_lite.b_ready   ),
      .S_AXI_ARADDR        (aes_lite.ar_addr   ),
      .S_AXI_ARPROT        (   ),
      .S_AXI_ARVALID       (aes_lite.ar_valid   ),
      .S_AXI_ARREADY       (aes_lite.ar_ready   ),
      .S_AXI_RDATA         (aes_lite.r_data   ),
      .S_AXI_RRESP         (aes_lite.r_resp   ),
      .S_AXI_RVALID        (aes_lite.r_valid   ),
      .S_AXI_RREADY        (aes_lite.r_ready   )
  );


  // ---------------
  // DH : azim
  // ---------------
  AXI_LITE #(
      .AXI_ADDR_WIDTH (32),
      .AXI_DATA_WIDTH (32)
  ) DH_lite();

  axi_to_axi_lite_mod  axi_to_axi_lite_DH (
      .clk_i      (clk_i),
      .rst_ni     (ndmreset_n),
      .testmode_i (test_en),
      .in         (master[ariane_soc::DH]),
      .out        (DH_lite)
  );

  dh_wrapper  DH(
      .S_AXI_ACLK          (clk_i   ),
      .S_AXI_ARESETN       (ndmreset_n   ),
      .S_AXI_AWADDR        (DH_lite.aw_addr   ),
      .S_AXI_AWPROT        (   ),
      .S_AXI_AWVALID       (DH_lite.aw_valid   ),
      .S_AXI_AWREADY       (DH_lite.aw_ready   ),
      .S_AXI_WDATA         (DH_lite.w_data   ),
      .S_AXI_WSTRB         (DH_lite.w_strb   ),
      .S_AXI_WVALID        (DH_lite.w_valid   ),
      .S_AXI_WREADY        (DH_lite.w_ready   ),
      .S_AXI_BRESP         (DH_lite.b_resp   ),
      .S_AXI_BVALID        (DH_lite.b_valid   ),
      .S_AXI_BREADY        (DH_lite.b_ready   ),
      .S_AXI_ARADDR        (DH_lite.ar_addr   ),
      .S_AXI_ARPROT        (   ),
      .S_AXI_ARVALID       (DH_lite.ar_valid   ),
      .S_AXI_ARREADY       (DH_lite.ar_ready   ),
      .S_AXI_RDATA         (DH_lite.r_data   ),
      .S_AXI_RRESP         (DH_lite.r_resp   ),
      .S_AXI_RVALID        (DH_lite.r_valid   ),
      .S_AXI_RREADY        (DH_lite.r_ready   )
  );


  // ---------------
  // POCA : mash
  // ---------------
  POCA_v1_0_POCA_master poca_wrapper (
      .M_AXI_ACLK          (clk_i   ),
      .M_AXI_ARESETN       (ndmreset_n   ),
      .M_AXI_AWADDR        (slave[2].aw_addr   ),
      .M_AXI_AWID          (slave[2].aw_id   ),
      .M_AXI_AWLEN         (slave[2].aw_len  ),
      .M_AXI_AWSIZE        (slave[2].aw_size   ),
      .M_AXI_AWPROT        (   ),
      .M_AXI_AWVALID       (slave[2].aw_valid   ),
      .M_AXI_AWREADY       (slave[2].aw_ready   ),
      .M_AXI_WDATA         (slave[2].w_data   ),
      .M_AXI_WSTRB         (slave[2].w_strb   ),
      .M_AXI_WVALID        (slave[2].w_valid   ),
      .M_AXI_WLAST         (slave[2].w_last   ),
      .M_AXI_WREADY        (slave[2].w_ready   ),
      .M_AXI_BRESP         (slave[2].b_resp   ),
      .M_AXI_BVALID        (slave[2].b_valid   ),
      .M_AXI_BREADY        (slave[2].b_ready   ),
      .M_AXI_ARADDR        (slave[2].ar_addr   ),
      .M_AXI_ARID          (slave[2].ar_id   ),
      .M_AXI_ARLEN         (slave[2].ar_len  ),
      .M_AXI_ARSIZE        (slave[2].ar_size   ),
      .M_AXI_ARPROT        (   ),
      .M_AXI_ARVALID       (slave[2].ar_valid   ),
      .M_AXI_ARREADY       (slave[2].ar_ready   ),
      .M_AXI_RDATA         (slave[2].r_data   ),
      .M_AXI_RRESP         (slave[2].r_resp   ),
      .M_AXI_RVALID        (slave[2].r_valid   ),
      .M_AXI_RREADY        (slave[2].r_ready   )
    );



  // ---------------
  // ECDSA : azim
  // ---------------
  AXI_LITE #(
      .AXI_ADDR_WIDTH (32),
      .AXI_DATA_WIDTH (32)
  ) ECDSA_lite();

  axi_to_axi_lite_mod  axi_to_axi_lite_ECDSA (
      .clk_i      (clk_i),
      .rst_ni     (ndmreset_n),
      .testmode_i (test_en),
      .in         (master[ariane_soc::ECDSA]),
      .out        (ECDSA_lite)
  );

  ecdsa_wrapper  ECDSA(
      .S_AXI_ACLK          (clk_i   ),
      .S_AXI_ARESETN       (ndmreset_n   ),
      .S_AXI_AWADDR        (ECDSA_lite.aw_addr   ),
      .S_AXI_AWPROT        (   ),
      .S_AXI_AWVALID       (ECDSA_lite.aw_valid   ),
      .S_AXI_AWREADY       (ECDSA_lite.aw_ready   ),
      .S_AXI_WDATA         (ECDSA_lite.w_data   ),
      .S_AXI_WSTRB         (ECDSA_lite.w_strb   ),
      .S_AXI_WVALID        (ECDSA_lite.w_valid   ),
      .S_AXI_WREADY        (ECDSA_lite.w_ready   ),
      .S_AXI_BRESP         (ECDSA_lite.b_resp   ),
      .S_AXI_BVALID        (ECDSA_lite.b_valid   ),
      .S_AXI_BREADY        (ECDSA_lite.b_ready   ),
      .S_AXI_ARADDR        (ECDSA_lite.ar_addr   ),
      .S_AXI_ARPROT        (   ),
      .S_AXI_ARVALID       (ECDSA_lite.ar_valid   ),
      .S_AXI_ARREADY       (ECDSA_lite.ar_ready   ),
      .S_AXI_RDATA         (ECDSA_lite.r_data   ),
      .S_AXI_RRESP         (ECDSA_lite.r_resp   ),
      .S_AXI_RVALID        (ECDSA_lite.r_valid   ),
      .S_AXI_RREADY        (ECDSA_lite.r_ready   )
  );





  // ---------------
  // CLINT
  // ---------------
  logic ipi;
  logic timer_irq;

  ariane_axi_soc::req_slv_t  axi_clint_req;
  ariane_axi_soc::resp_slv_t axi_clint_resp;

  clint #(
    .AXI_ADDR_WIDTH ( AXI_ADDRESS_WIDTH          ),
    .AXI_DATA_WIDTH ( AXI_DATA_WIDTH             ),
    .AXI_ID_WIDTH   ( ariane_soc::IdWidthSlave   ),
    .NR_CORES       ( 1                          ),
    .axi_req_t      ( ariane_axi_soc::req_slv_t  ),
    .axi_resp_t     ( ariane_axi_soc::resp_slv_t )
  ) i_clint (
    .clk_i       ( clk_i          ),
    .rst_ni      ( ndmreset_n     ),
    .testmode_i  ( test_en        ),
    .axi_req_i   ( axi_clint_req  ),
    .axi_resp_o  ( axi_clint_resp ),
    .rtc_i       ( rtc_i          ),
    .timer_irq_o ( timer_irq      ),
    .ipi_o       ( ipi            )
  );

  `AXI_ASSIGN_TO_REQ(axi_clint_req, master[ariane_soc::CLINT])
  `AXI_ASSIGN_FROM_RESP(master[ariane_soc::CLINT], axi_clint_resp)

  // ---------------
  // Peripherals
  // ---------------
  logic tx, rx;
  logic [1:0] irqs;

  ariane_peripherals #(
    .AxiAddrWidth ( AXI_ADDRESS_WIDTH        ),
    .AxiDataWidth ( AXI_DATA_WIDTH           ),
    .AxiIdWidth   ( ariane_soc::IdWidthSlave ),
`ifndef VERILATOR
  // disable UART when using Spike, as we need to rely on the mockuart
  `ifdef SPIKE_TANDEM
    .InclUART     ( 1'b0                     ),
  `else
    .InclUART     ( 1'b1                     ),
  `endif
`else
    .InclUART     ( 1'b0                     ),
`endif
    .InclSPI      ( 1'b0                     ),
    .InclEthernet ( 1'b0                     )
  ) i_ariane_peripherals (
    .clk_i     ( clk_i                        ),
    .rst_ni    ( ndmreset_n                   ),
    .plic      ( master[ariane_soc::PLIC]     ),
    .uart      ( master[ariane_soc::UART]     ),
    .spi       ( master[ariane_soc::SPI]      ),
    .ethernet  ( master[ariane_soc::Ethernet] ),
    .timer     ( master[ariane_soc::Timer]    ),
    .irq_o     ( irqs                         ),
    .rx_i      ( rx                           ),
    .tx_o      ( tx                           ),
    .eth_txck  ( ),
    .eth_rxck  ( ),
    .eth_rxctl ( ),
    .eth_rxd   ( ),
    .eth_rst_n ( ),
    .eth_tx_en ( ),
    .eth_txd   ( ),
    .phy_mdio  ( ),
    .eth_mdc   ( ),
    .mdio      ( ),
    .mdc       ( ),
    .spi_clk_o ( ),
    .spi_mosi  ( ),
    .spi_miso  ( ),
    .spi_ss    ( )
  );

  uart_bus #(.BAUD_RATE(115200), .PARITY_EN(0)) i_uart_bus (.rx(tx), .tx(rx), .rx_en(1'b1));

  // ---------------
  // Core
  // ---------------
  ariane_axi_soc::req_t    axi_ariane_req;
  ariane_axi_soc::resp_t   axi_ariane_resp;
  ariane_rvfi_pkg::rvfi_port_t rvfi;

  ariane #(
    .ArianeCfg  ( ariane_soc::ArianeSocCfg )
  ) i_ariane (
    .clk_i                ( clk_i               ),
    .rst_ni               ( ndmreset_n          ),
    .boot_addr_i          ( ariane_soc::ROMBase ), // start fetching from ROM
    .hart_id_i            ( {56'h0, hart_id}    ),
    .irq_i                ( irqs                ),
    .ipi_i                ( ipi                 ),
    .time_irq_i           ( timer_irq           ),
`ifdef RVFI_TRACE
    .rvfi_o               ( rvfi                ),
`endif
// Disable Debug when simulating with Spike
`ifdef SPIKE_TANDEM
    .debug_req_i          ( 1'b0                ),
`else
    .debug_req_i          ( debug_req_core      ),
`endif
    .axi_req_o            ( axi_ariane_req      ),
    .axi_resp_i           ( axi_ariane_resp     )
  );

  `AXI_ASSIGN_FROM_REQ(slave[0], axi_ariane_req)
  `AXI_ASSIGN_TO_RESP(axi_ariane_resp, slave[0])

  // -------------
  // Simulation Helper Functions
  // -------------
  // check for response errors
  always_ff @(posedge clk_i) begin : p_assert
    if (axi_ariane_req.r_ready &&
      axi_ariane_resp.r_valid &&
      axi_ariane_resp.r.resp inside {axi_pkg::RESP_DECERR, axi_pkg::RESP_SLVERR}) begin
      $warning("R Response Errored");
    end
    if (axi_ariane_req.b_ready &&
      axi_ariane_resp.b_valid &&
      axi_ariane_resp.b.resp inside {axi_pkg::RESP_DECERR, axi_pkg::RESP_SLVERR}) begin
      $warning("B Response Errored");
    end
  end

  rvfi_tracer  #(
    .HART_ID(hart_id),
    .DEBUG_START(0),
    .DEBUG_STOP(0)
  ) rvfi_tracer_i (
    .clk_i(clk_i),
    .rst_ni(rst_ni),
    .rvfi_i(rvfi)
  );

`ifdef AXI_SVA
  // AXI 4 Assertion IP integration - You will need to get your own copy of this IP if you want
  // to use it
  Axi4PC #(
    .DATA_WIDTH(ariane_axi_soc::DataWidth),
    .WID_WIDTH(ariane_soc::IdWidthSlave),
    .RID_WIDTH(ariane_soc::IdWidthSlave),
    .AWUSER_WIDTH(ariane_axi_soc::UserWidth),
    .WUSER_WIDTH(ariane_axi_soc::UserWidth),
    .BUSER_WIDTH(ariane_axi_soc::UserWidth),
    .ARUSER_WIDTH(ariane_axi_soc::UserWidth),
    .RUSER_WIDTH(ariane_axi_soc::UserWidth),
    .ADDR_WIDTH(ariane_axi_soc::AddrWidth)
  ) i_Axi4PC (
    .ACLK(clk_i),
    .ARESETn(ndmreset_n),
    .AWID(dram.aw_id),
    .AWADDR(dram.aw_addr),
    .AWLEN(dram.aw_len),
    .AWSIZE(dram.aw_size),
    .AWBURST(dram.aw_burst),
    .AWLOCK(dram.aw_lock),
    .AWCACHE(dram.aw_cache),
    .AWPROT(dram.aw_prot),
    .AWQOS(dram.aw_qos),
    .AWREGION(dram.aw_region),
    .AWUSER(dram.aw_user),
    .AWVALID(dram.aw_valid),
    .AWREADY(dram.aw_ready),
    .WLAST(dram.w_last),
    .WDATA(dram.w_data),
    .WSTRB(dram.w_strb),
    .WUSER(dram.w_user),
    .WVALID(dram.w_valid),
    .WREADY(dram.w_ready),
    .BID(dram.b_id),
    .BRESP(dram.b_resp),
    .BUSER(dram.b_user),
    .BVALID(dram.b_valid),
    .BREADY(dram.b_ready),
    .ARID(dram.ar_id),
    .ARADDR(dram.ar_addr),
    .ARLEN(dram.ar_len),
    .ARSIZE(dram.ar_size),
    .ARBURST(dram.ar_burst),
    .ARLOCK(dram.ar_lock),
    .ARCACHE(dram.ar_cache),
    .ARPROT(dram.ar_prot),
    .ARQOS(dram.ar_qos),
    .ARREGION(dram.ar_region),
    .ARUSER(dram.ar_user),
    .ARVALID(dram.ar_valid),
    .ARREADY(dram.ar_ready),
    .RID(dram.r_id),
    .RLAST(dram.r_last),
    .RDATA(dram.r_data),
    .RRESP(dram.r_resp),
    .RUSER(dram.r_user),
    .RVALID(dram.r_valid),
    .RREADY(dram.r_ready),
    .CACTIVE('0),
    .CSYSREQ('0),
    .CSYSACK('0)
  );
`endif
endmodule
