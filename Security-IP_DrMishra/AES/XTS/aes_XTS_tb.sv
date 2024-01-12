// The test vectors within this file are obtained from NIST Special Publication 800-38A
// for CTR-AES128, found in sections F.5.1 and F.5.2.

//Created by Dylan Ferris and Prabhat Mishra at the University of Florida.

`timescale 1ns/1ps

module aes_XTS_tb;
    parameter period = 5; // Clock period
    localparam keylen = 128;
    localparam PIPELINE_DELAY = 41;

    integer testcase;

    reg sim_done;
    reg clk, rst;
    wire done;
    reg encNotDec, start;
    wire [keylen-1:0] tweakKey, cipherKey;
    reg [keylen-1:0] sectorAddress, firstBlockIndex, blockIn;

    // Outputs
    wire [keylen-1:0] blockOut, blockInIndex, blockOutIndex;
    wire blockInReady, blockOutReady;

    reg [(keylen*2)-1:0] key;

    // assign cipherKey = key[keylen-1:0];
    // assign tweakKey = key[(keylen*2)-1:keylen];
    assign tweakKey = key[keylen-1:0];
    assign cipherKey = key[(keylen*2)-1:keylen];

    aes_XTS uut(
          .clk(clk)
        , .rst(rst)
        , .encNotDec(encNotDec)
        , .start(start)
        , .tweakKey(tweakKey)
        , .sectorAddress(sectorAddress)
        , .firstBlockIndex(firstBlockIndex)
        , .cipherKey(cipherKey)
        , .blockIn(blockIn)
        , .blockOut(blockOut)
        , .blockInIndex(blockInIndex)
        , .blockOutIndex(blockOutIndex)
        , .blockInReady(blockInReady)
        , .blockOutReady(blockOutReady)
        , .done(done)
    );

    always #(period) clk = !clk & !sim_done;

    initial
    begin
        sim_done <= 0;

        clk <= 0;

        start <= 0;

        key <= 0;
        encNotDec <= 1;
        sectorAddress <= 0;
        firstBlockIndex <= 0;
        blockIn <= 0;

        rst <= 1;

        #(period / 4)
        rst <= 0;

        //////////////
        // Test case 0
        //////////////

        testcase = 0;

        key <= 0;
        sectorAddress <= 0;
        blockIn <= 0;

        start <= 1;

        @(blockOutReady)
        @(blockOutIndex == 1)

        start <= 0;
        #(period * 5)

        rst <= 1;
        #(period / 4)
        rst <= 0;

        //////////////
        // Test case 1
        //////////////

        testcase = 1;

        key <= 256'h1111111111111111111111111111111122222222222222222222222222222222;
        sectorAddress = {<<8{128'h3333333333}};
        blockIn <= 128'h44444444444444444444444444444444;

        start <= 1;

        @(blockOutReady)
        @(blockOutIndex == 1)

        start <= 0;
        #(period * 5)

        rst <= 1;
        #(period / 4)
        rst <= 0;

        //////////////
        // Test case 2
        //////////////

        testcase = 2;

        key <= 256'h2718281828459045235360287471352631415926535897932384626433832795;
        sectorAddress <= 0;
        start <= 1;

        @(blockInReady)
        blockIn <= 128'h000102030405060708090a0b0c0d0e0f;
        @(blockInIndex == 1)
        blockIn <= 128'h101112131415161718191a1b1c1d1e1f;
        @(blockInIndex == 2)
        blockIn <= 128'h202122232425262728292a2b2c2d2e2f;
        @(blockInIndex == 3)
        blockIn <= 128'h303132333435363738393a3b3c3d3e3f;
        @(blockInIndex == 4)
        blockIn <= 128'h404142434445464748494a4b4c4d4e4f;
        @(blockInIndex == 5)
        blockIn <= 128'h505152535455565758595a5b5c5d5e5f;
        @(blockInIndex == 6)
        blockIn <= 128'h606162636465666768696a6b6c6d6e6f;
        @(blockInIndex == 7)
        blockIn <= 128'h707172737475767778797a7b7c7d7e7f;
        @(blockInIndex == 8)
        blockIn <= 128'h808182838485868788898a8b8c8d8e8f;
        @(blockInIndex == 9)
        blockIn <= 128'h909192939495969798999a9b9c9d9e9f;
        @(blockInIndex == 10)
        blockIn <= 128'ha0a1a2a3a4a5a6a7a8a9aaabacadaeaf;
        @(blockInIndex == 11)
        blockIn <= 128'hb0b1b2b3b4b5b6b7b8b9babbbcbdbebf;
        @(blockInIndex == 12)
        blockIn <= 128'hc0c1c2c3c4c5c6c7c8c9cacbcccdcecf;
        @(blockInIndex == 13)
        blockIn <= 128'hd0d1d2d3d4d5d6d7d8d9dadbdcdddedf;
        @(blockInIndex == 14)
        blockIn <= 128'he0e1e2e3e4e5e6e7e8e9eaebecedeeef;
        @(blockInIndex == 15)
        blockIn <= 128'hf0f1f2f3f4f5f6f7f8f9fafbfcfdfeff;
        @(blockInIndex == 16)
        blockIn <= 128'h000102030405060708090a0b0c0d0e0f;
        @(blockInIndex == 17)
        blockIn <= 128'h101112131415161718191a1b1c1d1e1f;
        @(blockInIndex == 18)
        blockIn <= 128'h202122232425262728292a2b2c2d2e2f;
        @(blockInIndex == 19)
        blockIn <= 128'h303132333435363738393a3b3c3d3e3f;
        @(blockInIndex == 20)
        blockIn <= 128'h404142434445464748494a4b4c4d4e4f;
        @(blockInIndex == 21)
        blockIn <= 128'h505152535455565758595a5b5c5d5e5f;
        @(blockInIndex == 22)
        blockIn <= 128'h606162636465666768696a6b6c6d6e6f;
        @(blockInIndex == 23)
        blockIn <= 128'h707172737475767778797a7b7c7d7e7f;
        @(blockInIndex == 24)
        blockIn <= 128'h808182838485868788898a8b8c8d8e8f;
        @(blockInIndex == 25)
        blockIn <= 128'h909192939495969798999a9b9c9d9e9f;
        @(blockInIndex == 26)
        blockIn <= 128'ha0a1a2a3a4a5a6a7a8a9aaabacadaeaf;
        @(blockInIndex == 27)
        blockIn <= 128'hb0b1b2b3b4b5b6b7b8b9babbbcbdbebf;
        @(blockInIndex == 28)
        blockIn <= 128'hc0c1c2c3c4c5c6c7c8c9cacbcccdcecf;
        @(blockInIndex == 29)
        blockIn <= 128'hd0d1d2d3d4d5d6d7d8d9dadbdcdddedf;
        @(blockInIndex == 30)
        blockIn <= 128'he0e1e2e3e4e5e6e7e8e9eaebecedeeef;
        @(blockInIndex == 31)
        blockIn <= 128'hf0f1f2f3f4f5f6f7f8f9fafbfcfdfeff;

        start <= 0;

        @(blockOutIndex == 31)
        #(period*5)

        rst <= 1;
        #(period / 4)
        rst <= 0;

        //////////////
        // Test case 3
        //////////////
        
        testcase = 3;

        key <= 256'h2718281828459045235360287471352631415926535897932384626433832795;
        sectorAddress <= {<<8{1}};
        start <= 1;

        @(blockInReady)
        blockIn <= 128'h27a7479befa1d476489f308cd4cfa6e2;
        @(blockInIndex == 1)
        blockIn <= 128'ha96e4bbe3208ff25287dd3819616e89c;
        @(blockInIndex == 2)
        blockIn <= 128'hc78cf7f5e543445f8333d8fa7f560000;
        @(blockInIndex == 3)
        blockIn <= 128'h05279fa5d8b5e4ad40e736ddb4d35412;
        @(blockInIndex == 4)
        blockIn <= 128'h328063fd2aab53e5ea1e0a9f332500a5;
        @(blockInIndex == 5)
        blockIn <= 128'hdf9487d07a5c92cc512c8866c7e860ce;
        @(blockInIndex == 6)
        blockIn <= 128'h93fdf166a24912b422976146ae20ce84;
        @(blockInIndex == 7)
        blockIn <= 128'h6bb7dc9ba94a767aaef20c0d61ad0265;
        @(blockInIndex == 8)
        blockIn <= 128'h5ea92dc4c4e41a8952c651d33174be51;
        @(blockInIndex == 9)
        blockIn <= 128'ha10c421110e6d81588ede82103a252d8;
        @(blockInIndex == 10)
        blockIn <= 128'ha750e8768defffed9122810aaeb99f91;
        @(blockInIndex == 11)
        blockIn <= 128'h72af82b604dc4b8e51bcb08235a6f434;
        @(blockInIndex == 12)
        blockIn <= 128'h1332e4ca60482a4ba1a03b3e65008fc5;
        @(blockInIndex == 13)
        blockIn <= 128'hda76b70bf1690db4eae29c5f1badd03c;
        @(blockInIndex == 14)
        blockIn <= 128'h5ccf2a55d705ddcd86d449511ceb7ec3;
        @(blockInIndex == 15)
        blockIn <= 128'h0bf12b1fa35b913f9f747a8afd1b130e;
        @(blockInIndex == 16)
        blockIn <= 128'h94bff94effd01a91735ca1726acd0b19;
        @(blockInIndex == 17)
        blockIn <= 128'h7c4e5b03393697e126826fb6bbde8ecc;
        @(blockInIndex == 18)
        blockIn <= 128'h1e08298516e2c9ed03ff3c1b7860f6de;
        @(blockInIndex == 19)
        blockIn <= 128'h76d4cecd94c8119855ef5297ca67e9f3;
        @(blockInIndex == 20)
        blockIn <= 128'he7ff72b1e99785ca0a7e7720c5b36dc6;
        @(blockInIndex == 21)
        blockIn <= 128'hd72cac9574c8cbbc2f801e23e56fd344;
        @(blockInIndex == 22)
        blockIn <= 128'hb07f22154beba0f08ce8891e643ed995;
        @(blockInIndex == 23)
        blockIn <= 128'hc94d9a69c9f1b5f499027a78572aeebd;
        @(blockInIndex == 24)
        blockIn <= 128'h74d20cc39881c213ee770b1010e4bea7;
        @(blockInIndex == 25)
        blockIn <= 128'h18846977ae119f7a023ab58cca0ad752;
        @(blockInIndex == 26)
        blockIn <= 128'hafe656bb3c17256a9f6e9bf19fdd5a38;
        @(blockInIndex == 27)
        blockIn <= 128'hfc82bbe872c5539edb609ef4f79c203e;
        @(blockInIndex == 28)
        blockIn <= 128'hbb140f2e583cb2ad15b4aa5b655016a8;
        @(blockInIndex == 29)
        blockIn <= 128'h449277dbd477ef2c8d6c017db738b18d;
        @(blockInIndex == 30)
        blockIn <= 128'heb4a427d1923ce3ff262735779a418f2;
        @(blockInIndex == 31)
        blockIn <= 128'h0a282df920147beabe421ee5319d0568;

        start <= 0;

        @(blockOutIndex == 31)
        #(period*5)
        rst <= 1;
        #(period / 4)
        rst <= 0;
        encNotDec <= 1'b0;

        //////////////
        // Test case 4 - Simple Decryption Case
        //////////////

        testcase = 4;

        key <= 256'h1111111111111111111111111111111122222222222222222222222222222222;
        sectorAddress = {<<8{128'h3333333333}};
        start <= 1'b1;
        @(blockInReady)
        blockIn <= 128'hc454185e6a16936e39334038acef838b;
        @(blockOutIndex == 1)
        blockIn <= 128'hfb186fff7480adc4289382ecd6d394f0;
        #(period*5)
        start <= 1'b0;      

        $stop;

        sim_done <= 1;
        $stop;
    end
  
    initial
        $timeformat (-9, 0, " ns", 0);

    always @ (blockOutReady, blockOutIndex, blockOut) begin
        #(period / 5)

        if (blockOutReady) begin
            if (testcase == 0) begin
                if      (blockOutIndex == 0 && blockOut !== 128'h917cf69ebd68b2ec9b9fe9a3eadda692)
                    $display("ERROR - Test Case 0, Block 0. Time: %t", $time);
                else if (blockOutIndex == 1 && blockOut !== 128'hcd43d2f59598ed858c02c2652fbf922e)
                    $display("ERROR - Test Case 0, Block 1. Time: %t", $time);
            end
            else if (testcase == 1) begin
                if      (blockOutIndex == 0 && blockOut !== 128'hc454185e6a16936e39334038acef838b)
                    $display("ERROR - Test Case 1, Block 0. Time: %t", $time);
                else if (blockOutIndex == 1 && blockOut !== 128'hfb186fff7480adc4289382ecd6d394f0)
                    $display("ERROR - Test Case 1, Block 1. Time: %t", $time);
            end
            else if (testcase == 2) begin
                if      (blockOutIndex == 0  && blockOut !== 128'h27a7479befa1d476489f308cd4cfa6e2)
                    $display("ERROR - Test Case 2, Block 0 . Time: %t", $time);
                else if (blockOutIndex == 1  && blockOut !== 128'ha96e4bbe3208ff25287dd3819616e89c)
                    $display("ERROR - Test Case 2, Block 1 . Time: %t", $time);
                else if (blockOutIndex == 2  && blockOut !== 128'hc78cf7f5e543445f8333d8fa7f560000)
                    $display("ERROR - Test Case 2, Block 2 . Time: %t", $time);
                else if (blockOutIndex == 3  && blockOut !== 128'h05279fa5d8b5e4ad40e736ddb4d35412)
                    $display("ERROR - Test Case 2, Block 3 . Time: %t", $time);
                else if (blockOutIndex == 4  && blockOut !== 128'h328063fd2aab53e5ea1e0a9f332500a5)
                    $display("ERROR - Test Case 2, Block 4 . Time: %t", $time);
                else if (blockOutIndex == 5  && blockOut !== 128'hdf9487d07a5c92cc512c8866c7e860ce)
                    $display("ERROR - Test Case 2, Block 5 . Time: %t", $time);
                else if (blockOutIndex == 6  && blockOut !== 128'h93fdf166a24912b422976146ae20ce84)
                    $display("ERROR - Test Case 2, Block 6 . Time: %t", $time);
                else if (blockOutIndex == 7  && blockOut !== 128'h6bb7dc9ba94a767aaef20c0d61ad0265)
                    $display("ERROR - Test Case 2, Block 7 . Time: %t", $time);
                else if (blockOutIndex == 8  && blockOut !== 128'h5ea92dc4c4e41a8952c651d33174be51)
                    $display("ERROR - Test Case 2, Block 8 . Time: %t", $time);
                else if (blockOutIndex == 9  && blockOut !== 128'ha10c421110e6d81588ede82103a252d8)
                    $display("ERROR - Test Case 2, Block 9 . Time: %t", $time);
                else if (blockOutIndex == 10 && blockOut !== 128'ha750e8768defffed9122810aaeb99f91)
                    $display("ERROR - Test Case 2, Block 10. Time: %t", $time);
                else if (blockOutIndex == 11 && blockOut !== 128'h72af82b604dc4b8e51bcb08235a6f434)
                    $display("ERROR - Test Case 2, Block 11. Time: %t", $time);
                else if (blockOutIndex == 12 && blockOut !== 128'h1332e4ca60482a4ba1a03b3e65008fc5)
                    $display("ERROR - Test Case 2, Block 12. Time: %t", $time);
                else if (blockOutIndex == 13 && blockOut !== 128'hda76b70bf1690db4eae29c5f1badd03c)
                    $display("ERROR - Test Case 2, Block 13. Time: %t", $time);
                else if (blockOutIndex == 14 && blockOut !== 128'h5ccf2a55d705ddcd86d449511ceb7ec3)
                    $display("ERROR - Test Case 2, Block 14. Time: %t", $time);
                else if (blockOutIndex == 15 && blockOut !== 128'h0bf12b1fa35b913f9f747a8afd1b130e)
                    $display("ERROR - Test Case 2, Block 15. Time: %t", $time);
                else if (blockOutIndex == 16 && blockOut !== 128'h94bff94effd01a91735ca1726acd0b19)
                    $display("ERROR - Test Case 2, Block 16. Time: %t", $time);
                else if (blockOutIndex == 17 && blockOut !== 128'h7c4e5b03393697e126826fb6bbde8ecc)
                    $display("ERROR - Test Case 2, Block 17. Time: %t", $time);
                else if (blockOutIndex == 18 && blockOut !== 128'h1e08298516e2c9ed03ff3c1b7860f6de)
                    $display("ERROR - Test Case 2, Block 18. Time: %t", $time);
                else if (blockOutIndex == 19 && blockOut !== 128'h76d4cecd94c8119855ef5297ca67e9f3)
                    $display("ERROR - Test Case 2, Block 19. Time: %t", $time);
                else if (blockOutIndex == 20 && blockOut !== 128'he7ff72b1e99785ca0a7e7720c5b36dc6)
                    $display("ERROR - Test Case 2, Block 20. Time: %t", $time);
                else if (blockOutIndex == 21 && blockOut !== 128'hd72cac9574c8cbbc2f801e23e56fd344)
                    $display("ERROR - Test Case 2, Block 21. Time: %t", $time);
                else if (blockOutIndex == 22 && blockOut !== 128'hb07f22154beba0f08ce8891e643ed995)
                    $display("ERROR - Test Case 2, Block 22. Time: %t", $time);
                else if (blockOutIndex == 23 && blockOut !== 128'hc94d9a69c9f1b5f499027a78572aeebd)
                    $display("ERROR - Test Case 2, Block 23. Time: %t", $time);
                else if (blockOutIndex == 24 && blockOut !== 128'h74d20cc39881c213ee770b1010e4bea7)
                    $display("ERROR - Test Case 2, Block 24. Time: %t", $time);
                else if (blockOutIndex == 25 && blockOut !== 128'h18846977ae119f7a023ab58cca0ad752)
                    $display("ERROR - Test Case 2, Block 25. Time: %t", $time);
                else if (blockOutIndex == 26 && blockOut !== 128'hafe656bb3c17256a9f6e9bf19fdd5a38)
                    $display("ERROR - Test Case 2, Block 26. Time: %t", $time);
                else if (blockOutIndex == 27 && blockOut !== 128'hfc82bbe872c5539edb609ef4f79c203e)
                    $display("ERROR - Test Case 2, Block 27. Time: %t", $time);
                else if (blockOutIndex == 28 && blockOut !== 128'hbb140f2e583cb2ad15b4aa5b655016a8)
                    $display("ERROR - Test Case 2, Block 28. Time: %t", $time);
                else if (blockOutIndex == 29 && blockOut !== 128'h449277dbd477ef2c8d6c017db738b18d)
                    $display("ERROR - Test Case 2, Block 29. Time: %t", $time);
                else if (blockOutIndex == 30 && blockOut !== 128'heb4a427d1923ce3ff262735779a418f2)
                    $display("ERROR - Test Case 2, Block 30. Time: %t", $time);
                else if (blockOutIndex == 31 && blockOut !== 128'h0a282df920147beabe421ee5319d0568)
                    $display("ERROR - Test Case 2, Block 31. Time: %t", $time);
            end
            else if (testcase == 3) begin
                if      (blockOutIndex == 0 && blockOut !== 128'h264d3ca8512194fec312c8c9891f279f)
                    $display("ERROR - Test Case 3, Block 0. Time: %t", $time);
                else if (blockOutIndex == 1 && blockOut !== 128'hefdd608d0c027b60483a3fa811d65ee5)
                    $display("ERROR - Test Case 3, Block 1. Time: %t", $time);
                else if (blockOutIndex == 2 && blockOut !== 128'h9d52d9e40ec5672d81532b38b6b089ce)
                    $display("ERROR - Test Case 3, Block 2. Time: %t", $time);
                else if (blockOutIndex == 3 && blockOut !== 128'h951f0f9c35590b8b978d175213f329bb)
                    $display("ERROR - Test Case 3, Block 3. Time: %t", $time);
                else if (blockOutIndex == 4 && blockOut !== 128'h1c2fd30f2f7f30492a61a532a79f51d3)
                    $display("ERROR - Test Case 3, Block 4. Time: %t", $time);
                else if (blockOutIndex == 5 && blockOut !== 128'h6f5e31a7c9a12c286082ff7d2394d18f)
                    $display("ERROR - Test Case 3, Block 5. Time: %t", $time);
                else if (blockOutIndex == 6 && blockOut !== 128'h783e1a8e72c722caaaa52d8f065657d2)
                    $display("ERROR - Test Case 3, Block 6. Time: %t", $time);
                else if (blockOutIndex == 7 && blockOut !== 128'h631fd25bfd8e5baad6e527d763517501)
                    $display("ERROR - Test Case 3, Block 7. Time: %t", $time);
                else if (blockOutIndex == 8 && blockOut !== 128'hc68c5edc3cdd55435c532d7125c8614d)
                    $display("ERROR - Test Case 3, Block 8. Time: %t", $time);
                else if (blockOutIndex == 9 && blockOut !== 128'heed9adaa3acade5888b87bef641c4c99)
                    $display("ERROR - Test Case 3, Block 9. Time: %t", $time);
                else if (blockOutIndex == 10 && blockOut !== 128'h4c8091b5bcd387f3963fb5bc37aa922f)
                    $display("ERROR - Test Case 3, Block 10. Time: %t", $time);
                else if (blockOutIndex == 11 && blockOut !== 128'hbfe3df4e5b915e6eb514717bdd2a7407)
                    $display("ERROR - Test Case 3, Block 11. Time: %t", $time);
                else if (blockOutIndex == 12 && blockOut !== 128'h9a5073f5c4bfd46adf7d282e7a393a52)
                    $display("ERROR - Test Case 3, Block 12. Time: %t", $time);
                else if (blockOutIndex == 13 && blockOut !== 128'h579d11a028da4d9cd9c77124f9648ee3)
                    $display("ERROR - Test Case 3, Block 13. Time: %t", $time);
                else if (blockOutIndex == 14 && blockOut !== 128'h83b1ac763930e7162a8d37f350b2f74b)
                    $display("ERROR - Test Case 3, Block 14. Time: %t", $time);
                else if (blockOutIndex == 15 && blockOut !== 128'h8472cf09902063c6b32e8c2d9290cefb)
                    $display("ERROR - Test Case 3, Block 15. Time: %t", $time);
                else if (blockOutIndex == 16 && blockOut !== 128'hd7346d1c779a0df50edcde4531da07b0)
                    $display("ERROR - Test Case 3, Block 16. Time: %t", $time);
                else if (blockOutIndex == 17 && blockOut !== 128'h99c638e83a755944df2aef1aa31752fd)
                    $display("ERROR - Test Case 3, Block 17. Time: %t", $time);
                else if (blockOutIndex == 18 && blockOut !== 128'h323dcb710fb4bfbb9d22b925bc3577e1)
                    $display("ERROR - Test Case 3, Block 18. Time: %t", $time);
                else if (blockOutIndex == 19 && blockOut !== 128'hb8949e729a90bbafeacf7f7879e7b114)
                    $display("ERROR - Test Case 3, Block 19. Time: %t", $time);
                else if (blockOutIndex == 20 && blockOut !== 128'h7e28ba0bae940db795a61b15ecf4df8d)
                    $display("ERROR - Test Case 3, Block 20. Time: %t", $time);
                else if (blockOutIndex == 21 && blockOut !== 128'hb07b824bb062802cc98a9545bb2aaeed)
                    $display("ERROR - Test Case 3, Block 21. Time: %t", $time);
                else if (blockOutIndex == 22 && blockOut !== 128'h77cb3fc6db15dcd7d80d7d5bc406c497)
                    $display("ERROR - Test Case 3, Block 22. Time: %t", $time);
                else if (blockOutIndex == 23 && blockOut !== 128'h0a3478ada8899b329198eb61c193fb62)
                    $display("ERROR - Test Case 3, Block 23. Time: %t", $time);
                else if (blockOutIndex == 24 && blockOut !== 128'h75aa8ca340344a75a862aebe92eee1ce)
                    $display("ERROR - Test Case 3, Block 24. Time: %t", $time);
                else if (blockOutIndex == 25 && blockOut !== 128'h032fd950b47d7704a3876923b4ad6284)
                    $display("ERROR - Test Case 3, Block 25. Time: %t", $time);
                else if (blockOutIndex == 26 && blockOut !== 128'h4bf4a09c4dbe8b4397184b7471360c95)
                    $display("ERROR - Test Case 3, Block 26. Time: %t", $time);
                else if (blockOutIndex == 27 && blockOut !== 128'h64880aedddb9baa4af2e75394b08cd32)
                    $display("ERROR - Test Case 3, Block 27. Time: %t", $time);
                else if (blockOutIndex == 28 && blockOut !== 128'hff479c57a07d3eab5d54de5f9738b8d2)
                    $display("ERROR - Test Case 3, Block 28. Time: %t", $time);
                else if (blockOutIndex == 29 && blockOut !== 128'h7f27a9f0ab11799d7b7ffefb2704c95c)
                    $display("ERROR - Test Case 3, Block 29. Time: %t", $time);
                else if (blockOutIndex == 30 && blockOut !== 128'h6ad12c39f1e867a4b7b1d7818a4b753d)
                    $display("ERROR - Test Case 3, Block 30. Time: %t", $time);
                else if (blockOutIndex == 31 && blockOut !== 128'hfd2a89ccb45e001a03a867b187f225dd)
                    $display("ERROR - Test Case 3, Block 31. Time: %t", $time);
            end
            else if (testcase == 4) begin
                 if (blockOutIndex == 0 && blockOut !== 128'h44444444444444444444444444444444)
                    $display("ERROR - Test Case 4, Block 0. Time: %t", $time);
                else if (blockOutIndex == 1 && blockOut !== 128'h44444444444444444444444444444444)
                    $display("ERROR - Test Case 4, Block 1. Time: %t", $time);
            end
        end
    end

endmodule : aes_XTS_tb