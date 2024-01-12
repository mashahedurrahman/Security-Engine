// The test vectors within this file are obtained from NIST Special Publication 800-38A
// for CTR-AES128, found in sections F.5.1 and F.5.2.

`timescale 1ns/1ps

module aes_CTR_mode_tb;
    parameter period = 5; // Clock period
    int RAND_SEED = 88; // Hard coded seed for repeatibility
    localparam NUM_VECTORS = 64;
    localparam WIDTH = 32;
    localparam KEY_SIZE = 4;
    localparam INTEGER_SIZE = 64;
    localparam KEYLEN = 128;
    localparam PIPELINE_DELAY = 41;

    integer errorCount = 0;
    integer correctCount = 0;

    // Inputs
    // NIST defines the state input as a single 128-bit field, Input Block
    // However, our aes_CTR_mode_alternative takes the input as a separate
    // 64-bit IV (initialization vector, aka nonce), and 64-bit counter.
    // The two assign statements are to split the NIST test vector into
    // our module's inputs.

    reg clk, rst, encNotDec;
    reg sim_done;
    reg [KEYLEN-1 : 0] key, messageIn, cipherIn, inputBlock;
    wire [(KEYLEN/2)-1 : 0] nonce, counterIn;

    assign counterIn = inputBlock[(KEYLEN/2)-1:0];
    assign nonce = inputBlock[KEYLEN-1 : (KEYLEN/2)];

    // Outputs
    wire [KEYLEN-1 : 0] messageOut, cipherOut;
    wire done_message, done_cipher;

    aes_CTR_mode uut(
          .clk(clk)
        , .rst(rst)
        , .encNotDec(encNotDec)
        , .key(key)
        , .messageIn(messageIn)
        , .cipherIn(cipherIn)
        , .nonce(nonce)
        , .counterIn(counterIn)
        , .done_message(done_message)
        , .done_cipher(done_cipher)
        , .messageOutReg(messageOut)
        , .cipherOutReg(cipherOut)
    );
    //aes_CTR_mode uut(
    //      .clk(clk)
    //    , .rst(rst)
    //    , .encNotDec(encNotDec)
    //    , .key(key)
    //    , .messageIn(messageIn)
    //    , .cipherIn(cipherIn)
    //    , .nonce(nonce)
    //    , .counterIn(counterIn)
    //    , .messageOut(messageOut)
    //    , .cipherOut(cipherOut)
    //);

    always #(period) clk = !clk &  !sim_done;

    initial
    begin
        // Encryption stage
        //key        <= 128'h2b7e151628aed2a6abf7158809cf4f3c;
        //inputBlock <= 128'hf0f1f2f3f4f5f6f7f8f9fafbfcfdfeff;
        key <= 3;
        inputBlock <= 0;

        clk <= 0;
        rst <= 1;
        encNotDec <= 1;
        sim_done <= 0;

        messageIn  <= 8;

        #(period * 2 + period / 2)
        rst <= 0;


        //#(period * 2 * PIPELINE_DELAY)  // 41 clock cycles
        //#(period * 2 * PIPELINE_DELAY)  // 41 clock cycles
        //#(period * 2 * 2)               // 2 clock cycles
        wait(done_cipher);

        if (cipherOut[31:0] !== 32'h9b9c4d84)
            $display("ERROR - Encrypt Message 1, cipherOut[31:0] = %0h", cipherOut[31:0]);


        $display("DONE simulation encryption");


        #100;

        // Decryption stage
        // All starting parameters are the same, except for encNotDec = 0
        rst <= 1;
        encNotDec <= 0;
        sim_done <= 0;

        cipherIn[31:0]  <= 32'h9b9c4d84;

        #(period * 2 + period / 2)
        rst <= 0;

        //#(period * 2 * PIPELINE_DELAY)  // 41 clock cycles
        //#(period * 2 * PIPELINE_DELAY)  // 41 clock cycles
        //#(period * 2 * 2)               // 2 clock cycles
        wait(done_message);

        if (messageOut[31:0] !== 32'd8)
            $display("ERROR - Decrypt Message 1");


        $display("DONE simulating decrpytion.");
        $display("DONE simulating.");        

        #100;
        sim_done <= 1'b1;

        #1000;
        $finish; 
    end

    initial begin
        $dumpfile("dump.vcd");
        $dumpvars;
    end
endmodule : aes_CTR_mode_tb
