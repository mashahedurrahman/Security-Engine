
module tb_poca_wrapper ();
    reg clk_i, ndmreset_n;
    wire [31:0] aw_addr, ar_addr, w_data, r_data;
    wire aw_valid, aw_ready, w_valid, w_ready, b_valid, b_ready, ar_valid, ar_ready, r_valid, r_ready;
    wire [3:0] w_strb;
    wire [1:0] b_resp, r_resp;


    POCA_v1_0_POCA_master poca_wrapper (
      .M_AXI_ACLK          (clk_i   ),
      .M_AXI_ARESETN       (ndmreset_n   ),
      .M_AXI_AWADDR        (aw_addr   ),
      .M_AXI_AWPROT        (   ),
      .M_AXI_AWVALID       (aw_valid   ),
      .M_AXI_AWREADY       (aw_ready   ),
      .M_AXI_WDATA         (w_data   ),
      .M_AXI_WSTRB         (w_strb   ),
      .M_AXI_WVALID        (w_valid   ),
      .M_AXI_WREADY        (w_ready   ),
      .M_AXI_BRESP         (b_resp   ),
      .M_AXI_BVALID        (b_valid   ),
      .M_AXI_BREADY        (b_ready   ),
      .M_AXI_ARADDR        (ar_addr   ),
      .M_AXI_ARPROT        (   ),
      .M_AXI_ARVALID       (ar_valid   ),
      .M_AXI_ARREADY       (ar_ready   ),
      .M_AXI_RDATA         (r_data   ),
      .M_AXI_RRESP         (r_resp   ),
      .M_AXI_RVALID        (r_valid   ),
      .M_AXI_RREADY        (r_ready   )
    );
  

    slave_wrapper  axi_slave (
      .S_AXI_ACLK          (clk_i   ),
      .S_AXI_ARESETN       (ndmreset_n   ),
      .S_AXI_AWADDR        (aw_addr   ),
      .S_AXI_AWPROT        (   ),
      .S_AXI_AWVALID       (aw_valid   ),
      .S_AXI_AWREADY       (aw_ready   ),
      .S_AXI_WDATA         (w_data   ),
      .S_AXI_WSTRB         (w_strb   ),
      .S_AXI_WVALID        (w_valid   ),
      .S_AXI_WREADY        (w_ready   ),
      .S_AXI_BRESP         (b_resp   ),
      .S_AXI_BVALID        (b_valid   ),
      .S_AXI_BREADY        (b_ready   ),
      .S_AXI_ARADDR        (ar_addr   ),
      .S_AXI_ARPROT        (   ),
      .S_AXI_ARVALID       (ar_valid   ),
      .S_AXI_ARREADY       (ar_ready   ),
      .S_AXI_RDATA         (r_data   ),
      .S_AXI_RRESP         (r_resp   ),
      .S_AXI_RVALID        (r_valid   ),
      .S_AXI_RREADY        (r_ready   )
    );

    always #5 clk_i = ~clk_i;

    initial begin
      clk_i = 0;
      ndmreset_n = 1;
      #10;
      ndmreset_n = 0;
      #10;
      ndmreset_n = 1;
      #20000;
      $finish;
    end

    initial begin
      $dumpfile("dump_wrapper.vcd");
      $dumpvars;
    end


endmodule
