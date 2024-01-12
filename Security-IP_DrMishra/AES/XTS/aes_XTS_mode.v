module aes_XTS #(
    localparam keylen = 128
)(
      input clk, rst
    , input encNotDec, start
    , input [keylen-1:0] tweakKey, sectorAddress, firstBlockIndex, cipherKey, blockIn
    , output [keylen-1:0] blockOut, blockInIndex, blockOutIndex
    , output blockInReady, blockOutReady, done
);
    wire rst_n;
    assign rst_n = !rst;
    
    // State machine
    localparam S_Ready = 0, S_Tweak = 1, S_Powers = 2, S_Crypt = 3;
    integer curState = S_Ready;

    localparam PIPELINE_DELAY = 20; // Number of cycles for AES encryptor to output
    localparam DECRYPT_DELAY = 51; // Number of cycles for AES decryptor to output
    integer curTweakPipelineCnt, curCryptPipelineCnt, curDecryptCnt; // Keep track of where we are in the pipeline

    // Data values
    reg decryptStartDelay;
    reg [keylen-1:0] curBlockIndex, decryptTweak, decryptInput;
    wire [keylen-1:0] aesBlockInput, aesDecryptBlockInput, aesBlockOutput, aesDecryptOutput, aesKey, curTweak, delayedTweak;
    wire decryptReady, decryptNext, decryptInit;

    assign decryptRst_n = !rst;
    assign decryptInit = !encNotDec && curState == S_Ready && start;
    assign decryptNext = !encNotDec && curState == S_Crypt && decryptReady;

    assign aesBlockInput = curState == S_Crypt ? (blockIn ^ curTweak) : sectorAddress;
    assign aesDecryptBlockInput = decryptInput ^ curTweak;
    assign aesKey = curState == S_Crypt ? cipherKey : tweakKey;

    assign blockOut = encNotDec ? (aesBlockOutput ^ delayedTweak) : (aesDecryptOutput ^ decryptTweak);
    assign blockInIndex = curBlockIndex;
    assign blockOutIndex = encNotDec ? (curBlockIndex - PIPELINE_DELAY - 1) : (blockInIndex - 1);

    assign blockInReady = curState == S_Crypt && (encNotDec || decryptReady);
    assign blockOutReady = curState == S_Crypt && ((encNotDec && curCryptPipelineCnt > PIPELINE_DELAY) || (!encNotDec && decryptReady && curBlockIndex != 0));

    // LFSR control
    wire LFSR_shift, LFSR_load;

    assign LFSR_shift = (curState == S_Powers && curBlockIndex != firstBlockIndex) || (curState == S_Crypt && encNotDec) || (curState == S_Crypt && !encNotDec && curDecryptCnt == DECRYPT_DELAY);
    // assign LFSR_shift = curState == S_Powers;
    assign LFSR_load = curState == S_Tweak;

    always @ (rst) begin
        if (rst == 1) begin
            curState = 0;
            curTweakPipelineCnt = 0;
            curCryptPipelineCnt = 0;
            curDecryptCnt = 0;
            curBlockIndex = 0;
            decryptStartDelay = 0;
            decryptTweak = 0;
        end
    end

    // State machine logic
    always @ (posedge clk) begin
        if (!rst) begin
            case (curState)
                S_Ready: begin
                    curTweakPipelineCnt = 0;
                    curCryptPipelineCnt = 0;
                    curBlockIndex = 0;
                    curDecryptCnt = 0;

                    if (start)
                        curState = S_Tweak;
                end
                S_Tweak: begin
                    if (curTweakPipelineCnt == PIPELINE_DELAY) begin
                        if (curBlockIndex == firstBlockIndex) // Basically if firstBlockIndex == 0
                            curState = S_Crypt;
                        else
                            curState = S_Powers;
                    end
                    else begin
                        curTweakPipelineCnt = curTweakPipelineCnt + 1;
                    end
                end
                S_Powers: begin
                    if (curBlockIndex == firstBlockIndex) begin
                        curState = S_Crypt;
                    end
                    else begin
                        curBlockIndex = curBlockIndex + 1;
                    end
                end
                S_Crypt: begin
                    if (encNotDec) begin
                        curCryptPipelineCnt = curCryptPipelineCnt + 1;
                        curBlockIndex = curBlockIndex + 1;
                    end
                    else begin
                        if (decryptReady) begin
                            curBlockIndex = curBlockIndex + 1;
                            decryptTweak = curTweak;
                            decryptInput = blockIn;
                            curDecryptCnt = 0;
                        end
                        else
                            curDecryptCnt = curDecryptCnt + 1;
                    end

                    if (done)
                        curState = S_Ready;
                end
            endcase
        end
    end

    aes_128 encryptor(
          .clk(clk)
        , .state(aesBlockInput)
        , .key(aesKey)
        , .out(aesBlockOutput)
    );

    aes_core decryptor(
          .clk(clk)
        , .reset_n(decryptRst_n)
        , .encdec(1'h0) // 0 = Decrypt
        , .init(decryptInit)
        , .next(decryptNext)
        , .keylen(1'h0)
        , .key({ cipherKey, 128'h0 }) // Right pad 128-bit key to 256-bits (256 bit core)
        , .block(aesDecryptBlockInput)
        , .result(aesDecryptOutput)
        , .ready(decryptReady)
    );

    tweak_LFSR tweaker(
          .clk(clk)
        , .rst(rst)
        , .shift(LFSR_shift)
        , .load(LFSR_load)
        , .loadIn(aesBlockOutput)
        , .value(curTweak)
    );

    fifo #(.depth(PIPELINE_DELAY + 1), .width(keylen)) tweaks_fifo (
          .clk(clk)
        , .rst(rst)
        , .regIn(curTweak)
        , .regOut(delayedTweak)
    );
endmodule

module tweak_LFSR #(localparam keylen = 128)(
      input clk, rst
    , input shift, load
    , input [keylen-1:0] loadIn
    , output reg [keylen-1:0] value
);
    reg cin, cout;
    integer byteI;

    always @ (posedge clk, rst) begin
        if (rst)
            value = 0;
        else if (clk) begin
            if (load)
                value = loadIn;
            else if (shift) begin

                // Reverse the byte order, then do a left shift, then reverse back.
                value = {<<8{value}};

                cout = value[keylen - 1];
                value = value << 1;

                // XOR with a constant (galois field stuff for GF(2^128)) if original carries out
                if (cout)
                    value = value ^ 128'h87;

                value = {<<8{value}};
            end
        end
    end
endmodule

module fifo #(
    parameter depth, width
)(
      input clk, rst
    , input [width-1 : 0] regIn
    , output [width-1 : 0] regOut
);
    reg [width - 1 : 0] pipeline [depth-1 : 0];

    integer index;

    assign regOut = pipeline[index];

    integer i;
    always @ (posedge clk, rst) begin
        if (rst) begin
            index = 0;

            for (i = 0; i < depth; i = i + 1)
                pipeline[i] <= 0;
        end
        else if (clk) begin
            pipeline[index] <= regIn;

            // Circular increment on indexes
            index = index + 1;
            
            if (index == depth)
                index = 0;
        end
    end
endmodule
