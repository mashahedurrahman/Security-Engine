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

    //aes_CTR_mode uut(
    //      .clk(clk)
    //    , .rst(rst)
    //    , .encNotDec(encNotDec)
    //    , .key(key)
    //    , .messageIn(messageIn)
    //    , .cipherIn(cipherIn)
    //    , .nonce(nonce)
    //    , .counterIn(counterIn)
    //    , .done_message(done_message)
    //    , .done_cipher(done_cipher)
    //    , .messageOutReg(messageOut)
    //    , .cipherOutReg(cipherOut)
    //);
    aes_CTR_mode uut(
          .clk(clk)
        , .rst(rst)
        , .encNotDec(encNotDec)
        , .key(key)
        , .messageIn(messageIn)
        , .cipherIn(cipherIn)
        , .nonce(nonce)
        , .counterIn(counterIn)
        , .messageOut(messageOut)
        , .cipherOut(cipherOut)
    );

    always #(period) clk = !clk &  !sim_done;

    initial
    begin
        // Encryption stage
        key        <= 128'h2b7e151628aed2a6abf7158809cf4f3c;
        inputBlock <= 128'hf0f1f2f3f4f5f6f7f8f9fafbfcfdfeff;

        clk <= 0;
        rst <= 1;
        encNotDec <= 1;
        sim_done <= 0;

        #(period * 2 + period / 2)
        rst <= 0;

        //#(period * PIPELINE_DELAY) // Begin counting up and calculating new blockOuptuts

        messageIn  <= 128'h6bc1bee22e409f96e93d7e117393172a;
        #(period * 2)

        if (cipherOut !== 128'h874d6191b620e3261bef6864990db6ce)
            $display("ERROR - Encrypt Message 1");

        messageIn <= 128'hae2d8a571e03ac9c9eb76fac45af8e51;
        #(period * 2)

        if (cipherOut !== 128'h9806f66b7970fdff8617187bb9fffdff)
            $display("ERROR - Encrypt Message 2");

        messageIn <= 128'h30c81c46a35ce411e5fbc1191a0a52ef;
        #(period * 2)

        if (cipherOut !== 128'h5ae4df3edbd5d35e5b4f09020db03eab)
            $display("ERROR - Encrypt Message 3");

        messageIn <= 128'hf69f2445df4f9b17ad2b417be66c3710;
        #(period * 2)

        if (cipherOut !== 128'h1e031dda2fbe03d1792170a0f3009cee)
            $display("ERROR - Encrypt Message 4");

        $display("DONE simulation encryption");

        //// Decryption stage
        //// All starting parameters are the same, except for encNotDec = 0
        //clk <= 0;
        //rst <= 1;
        //encNotDec <= 0;
        //sim_done <= 0;

        //#(period * 2 + period / 2)
        //rst <= 0;

        //#(period * PIPELINE_DELAY) // Begin counting up and calculating new blockOuptuts

        //cipherIn  <= 128'h874d6191b620e3261bef6864990db6ce;
        //#(period * 2)

        //if (messageOut !== 128'h6bc1bee22e409f96e93d7e117393172a)
        //    $display("ERROR - Decrypt Message 1");

        //cipherIn  <= 128'h9806f66b7970fdff8617187bb9fffdff;
        //#(period * 2)

        //if (messageOut !== 128'hae2d8a571e03ac9c9eb76fac45af8e51)
        //    $display("ERROR - Decrypt Message 2");

        //cipherIn  <= 128'h5ae4df3edbd5d35e5b4f09020db03eab;
        //#(period * 2)

        //if (messageOut !== 128'h30c81c46a35ce411e5fbc1191a0a52ef)
        //    $display("ERROR - Decrypt Message 3");

        //cipherIn  <= 128'h1e031dda2fbe03d1792170a0f3009cee;
        //#(period * 2)

        //if (messageOut !== 128'hf69f2445df4f9b17ad2b417be66c3710)
        //    $display("ERROR - Decrypt Message 3");

        //$display("DONE simulating decrpytion.");
        //$display("DONE simulating.");        

        //#(period * 2 * 3);
        //sim_done <= 1'b1;

        #1000;
        $finish; 
    end

    initial begin
        $dumpfile("dump.vcd");
        $dumpvars;
    end
endmodule : aes_CTR_mode_tb
