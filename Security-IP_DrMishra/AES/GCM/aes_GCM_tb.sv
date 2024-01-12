// The test vectors within this file are obtained from NIST Special Publication 800-38A
// for CTR-AES128, found in sections F.5.1 and F.5.2.

`timescale 1ns/1ps

module aes_GCM_tb;
    parameter period = 5; // Clock period
    localparam KEYLEN = 128;
    localparam PIPELINE_DELAY = 41;

    // Inputs
    // NIST defines the state input as a single 128-bit field, Input Block
    // However, our aes_GCM takes the input as a separate
    // 64-bit IV (initialization vector, aka nonce), and 64-bit counter.
    // The two assign statements are to split the NIST test vector into
    // our module's inputs.

    integer testCase;

    reg sim_done;
    reg clk, rst, encNotDec, start, finalBlock, finalAuth;
    reg [KEYLEN-1 : 0] cipherKey, hashKey, blockIn, authIn;
    reg [95:0] nonceIn;
    reg [31:0] counterIn;

    // Outputs
    wire [KEYLEN-1:0] blockOut, authOut;
    wire [(KEYLEN/2)-1:0] blockNum;
    wire blockReady, authInReady, done;

    aes_GCM uut(
          .clk(clk)
        , .rst(rst)
        , .encNotDec(encNotDec)
        , .start(start)
        , .finalBlock(finalBlock)
        , .finalAuth(finalAuth)
        , .cipherKey(cipherKey)
        , .hashKey(hashKey)
        , .blockIn(blockIn)
        , .authIn(authIn)
        , .authInReady(authInReady)
        , .nonceIn(nonceIn)
        , .blockOut(blockOut)
        , .authOut(authOut)
        , .blockNum(blockNum)
        , .blockReady(blockReady)
        , .done(done)
    );

    always #(period) clk = !clk & !sim_done;
    // always #(period) blockIn = blockIn + 1;

    initial
    begin
        sim_done <= 0;

        clk <= 0;
        rst <= 1;
        encNotDec <= 1;
        start <= 0;
        blockIn <= 0;
        finalBlock <= 0;
        nonceIn <= 0;
        counterIn <= 0;
        hashKey <= 0;
        finalAuth <= 0;

        #(period / 4)
        rst <= 0;

        testCase = 1;

        start <= 1;
        nonceIn <= 0;
        hashKey <= 128'h66e94bd4ef8a2c3b884cfa59ca342b2e;
        cipherKey <= 0;
        finalBlock <= 1;
        finalAuth <= 1;

        @(done)
        #(period * 4)
        start <= 0;
        #(period * 4);

        testCase = 2;

        start <= 1;
        nonceIn <= 0;
        blockIn <= 0;
        finalAuth <= 1;
        finalBlock <= 0;
        cipherKey <= 0;
        hashKey <= 128'h66e94bd4ef8a2c3b884cfa59ca342b2e;

        @(blockReady);
        finalBlock <= 1;
        
        @(done)
        #(period * 4)
        start <= 0;
        #(period * 4)
        

        testCase = 3;

        start <= 1;
        nonceIn <= 96'hcafebabefacedbaddecaf888;
        hashKey <= 128'hb83b533708bf535d0aa6e52980d53b78;
        cipherKey <= 128'hfeffe9928665731c6d6a8f9467308308;
        finalAuth <= 1;
        finalBlock <= 0;

        @(blockReady);
        blockIn <= 128'hd9313225f88406e5a55909c5aff5269a;
        @(blockNum == 64'd1);
        blockIn <= 128'h86a7a9531534f7da2e4c303d8a318a72;
        @(blockNum == 64'd2);
        blockIn <= 128'h1c3c0c95956809532fcf0e2449a6b525;
        @(blockNum == 64'd3);
        blockIn <= 128'hb16aedf5aa0de657ba637b391aafd255;
        finalBlock <= 1;

        @(done);
        #(period * 4);
        start <= 0;
        #(period * 4)

        testCase = 4;

        start <= 1;
        cipherKey <= 128'hfeffe9928665731c6d6a8f9467308308;
        nonceIn <= 128'hcafebabefacedbaddecaf888;
        hashKey <= 128'hb83b533708bf535d0aa6e52980d53b78;
        finalAuth <= 0;
        finalBlock <= 0;

        @(authInReady)
        authIn <= 128'hfeedfacedeadbeeffeedfacedeadbeef;
        @(posedge clk);
        authIn <= 128'habaddad2000000000000000000000000;
        finalAuth <= 1;

        @(blockReady)
        blockIn <= 128'hd9313225f88406e5a55909c5aff5269a;
        @(blockNum == 1)
        blockIn <= 128'h86a7a9531534f7da2e4c303d8a318a72;
        @(blockNum == 2)
        blockIn <= 128'h1c3c0c95956809532fcf0e2449a6b525;
        @(blockNum == 3)
        blockIn <= 128'hb16aedf5aa0de657ba637b3900000000;
        finalBlock <= 1;

        @(done)
        #(period * 4)

        // Decoding tests

        clk <= 0;
        rst <= 1;
        encNotDec <= 0;
        start <= 0;
        blockIn <= 0;
        finalBlock <= 0;
        nonceIn <= 0;
        counterIn <= 0;
        hashKey <= 0;
        finalAuth <= 0;

        #(period / 4)
        rst <= 0;

        // Test case 5
        testCase = 5;

        start <= 1;
        nonceIn <= 0;
        hashKey <= 128'h66e94bd4ef8a2c3b884cfa59ca342b2e;
        cipherKey <= 0;
        finalBlock <= 1;
        finalAuth <= 1;

        @(done)
        #(period * 4)
        start <= 0;
        #(period * 4);

        // Test case 6
        testCase = 6;

        start <= 1;
        nonceIn <= 0;
        blockIn <= 0;
        finalAuth <= 1;
        finalBlock <= 0;
        cipherKey <= 0;
        hashKey <= 128'h66e94bd4ef8a2c3b884cfa59ca342b2e;

        @(blockReady);
        blockIn <= 128'h0388dace60b6a392f328c2b971b2fe78;
        finalBlock <= 1;
        
        @(done)
        #(period * 4)
        start <= 0;
        #(period * 4)
        
        // Test case 7
        testCase = 7;

        start <= 1;
        nonceIn <= 96'hcafebabefacedbaddecaf888;
        hashKey <= 128'hb83b533708bf535d0aa6e52980d53b78;
        cipherKey <= 128'hfeffe9928665731c6d6a8f9467308308;
        finalAuth <= 1;
        finalBlock <= 0;

        @(blockReady);
        blockIn <= 128'h42831ec2217774244b7221b784d0d49c;
        @(blockNum == 64'd1);
        blockIn <= 128'he3aa212f2c02a4e035c17e2329aca12e;
        @(blockNum == 64'd2);
        blockIn <= 128'h21d514b25466931c7d8f6a5aac84aa05;
        @(blockNum == 64'd3);
        blockIn <= 128'h1ba30b396a0aac973d58e091473f5985;
        finalBlock <= 1;

        @(done);
        #(period * 4);
        start <= 0;
        #(period * 4)

        // Test case 8
        testCase = 8;

        start <= 1;
        cipherKey <= 128'hfeffe9928665731c6d6a8f9467308308;
        nonceIn <= 128'hcafebabefacedbaddecaf888;
        hashKey <= 128'hb83b533708bf535d0aa6e52980d53b78;
        finalAuth <= 0;
        finalBlock <= 0;

        @(authInReady)
        authIn <= 128'hfeedfacedeadbeeffeedfacedeadbeef;
        @(posedge clk);
        authIn <= 128'habaddad2000000000000000000000000;
        finalAuth <= 1;

        @(blockReady)
        blockIn <= 128'h42831ec2217774244b7221b784d0d49c;
        @(blockNum == 1)
        blockIn <= 128'he3aa212f2c02a4e035c17e2329aca12e;
        @(blockNum == 2)
        blockIn <= 128'h21d514b25466931c7d8f6a5aac84aa05;
        @(blockNum == 3)
        blockIn <= 128'h1ba30b396a0aac973d58e0915d908bd0;
        finalBlock <= 1;

        @(done)
        #(period * 4)



        sim_done <= 1;
        $stop;
    end

    initial
        $timeformat (-9, 0, " ns", 0);

    always @ (blockNum, done, testCase, blockReady) begin
        #(period / 2)
        
        case (testCase)
            // Encoding tests
            1: begin
                if (done && authOut !== 128'h58e2fccefa7e3061367f1d57a4e7455a)
                    $display("ERROR - Test Case 1, Auth Tag. Time: %t", $time);
            end
            2: begin
                if (blockReady) begin
                    if (blockNum == 0 && blockOut !== 128'h0388dace60b6a392f328c2b971b2fe78)
                        $display("ERROR - Test Case 2, Block 0. Time: %t", $time);
                end
            end
            3: begin
                if (blockReady) begin
                    if (blockNum == 0 && blockOut !== 128'h42831ec2217774244b7221b784d0d49c)
                        $display("ERROR - Test Case 3, Block 0. Time: %t", $time);
                    else if (blockNum == 1 && blockOut !== 128'he3aa212f2c02a4e035c17e2329aca12e)
                        $display("ERROR - Test Case 3, Block 1. Time: %t", $time);
                    else if (blockNum == 2 && blockOut !== 128'h21d514b25466931c7d8f6a5aac84aa05)
                        $display("ERROR - Test Case 3, Block 2. Time: %t", $time);
                    else if (blockNum == 3 && blockOut !== 128'h1ba30b396a0aac973d58e091473f5985)
                        $display("ERROR - Test Case 3, Block 3. Time: %t", $time);
                end
            end
            4: begin
                if (blockReady) begin
                    if (blockNum == 0 && blockOut !== 128'h42831ec2217774244b7221b784d0d49c)
                        $display("ERROR - Test Case 4, Block 0. Time: %t", $time);
                    else if (blockNum == 1 && blockOut !== 128'he3aa212f2c02a4e035c17e2329aca12e)
                        $display("ERROR - Test Case 4, Block 1. Time: %t", $time);
                    else if (blockNum == 2 && blockOut !== 128'h21d514b25466931c7d8f6a5aac84aa05)
                        $display("ERROR - Test Case 4, Block 2. Time: %t", $time);
                    else if (blockNum == 3 && blockOut !== 128'h1ba30b396a0aac973d58e0915d908bd0)
                        $display("ERROR - Test Case 4, Block 3. Time: %t", $time);
                end
            end
            // Decoding cases
            5: begin
                if (done && authOut !== 128'h58e2fccefa7e3061367f1d57a4e7455a)
                    $display("ERROR - Test Case 5, Auth Tag. Time: %t", $time);
            end
            6: begin
                if (blockReady) begin
                    if (blockNum == 0 && blockOut !== 0)
                        $display("ERROR - Test Case 6, Block 0. Time: %t", $time);
                end
            end
            7: begin
                if (blockReady) begin
                    if (blockNum == 0 && blockOut !== 128'hd9313225f88406e5a55909c5aff5269a)
                        $display("ERROR - Test Case 7, Block 0. Time: %t", $time);
                    else if (blockNum == 1 && blockOut !== 128'h86a7a9531534f7da2e4c303d8a318a72)
                        $display("ERROR - Test Case 7, Block 1. Time: %t", $time);
                    else if (blockNum == 2 && blockOut !== 128'h1c3c0c95956809532fcf0e2449a6b525)
                        $display("ERROR - Test Case 7, Block 2. Time: %t", $time);
                    else if (blockNum == 3 && blockOut !== 128'hb16aedf5aa0de657ba637b391aafd255)
                        $display("ERROR - Test Case 7, Block 3. Time: %t", $time);
                end
            end
            8: begin
                if (blockReady) begin
                    if (blockNum == 0 && blockOut !== 128'hd9313225f88406e5a55909c5aff5269a)
                        $display("ERROR - Test Case 8, Block 0. Time: %t", $time);
                    else if (blockNum == 1 && blockOut !== 128'h86a7a9531534f7da2e4c303d8a318a72)
                        $display("ERROR - Test Case 8, Block 1. Time: %t", $time);
                    else if (blockNum == 2 && blockOut !== 128'h1c3c0c95956809532fcf0e2449a6b525)
                        $display("ERROR - Test Case 8, Block 2. Time: %t", $time);
                    else if (blockNum == 3 && blockOut !== 128'hb16aedf5aa0de657ba637b3900000000)
                        $display("ERROR - Test Case 8, Block 3. Time: %t", $time);
                end
            end
        endcase
    end
endmodule : aes_GCM_tb