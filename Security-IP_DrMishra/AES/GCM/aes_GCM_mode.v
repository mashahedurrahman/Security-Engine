module aes_GCM #(
    localparam keylen = 128
)(
      input clk, rst 
    , input encNotDec, start, finalAuth, finalBlock
    , input [keylen-1:0] cipherKey, hashKey, blockIn, authIn
    , input [95:0] nonceIn
    , output [keylen-1:0] blockOut, authOut
    , output [(keylen/2)-1:0] blockNum
    , output blockReady, authInReady, done
);
    // State machine
    localparam S_Ready = 0, S_AuthIn = 1, S_Waiting = 2, S_Ek0 = 3, S_DataIn = 4, S_AuthTag = 5, S_Done = 6;
    integer curState = S_Ready;

    localparam PIPELINE_DELAY = 19; // Number of cycles for AES encryptor to output
    integer curPipelineCount; // Keep track of where we are in the state machine

    // Data values
    reg [(keylen/2)-1:0] numBlocks, numAuth;
    reg [95:0] nonce;
    reg [31:0] counter;
    reg [keylen-1:0] ghash, authTagCipher, gfmulX, lenConcat;
    wire [keylen-1:0] aesBlockInput, aesBlockOutput, gfmulZ, gfmulY, ghashNext;
    
    assign aesBlockInput = curState == S_Ready ? { nonceIn, 32'd1 } : { nonce, counter };
    // assign aesBlockInput = { nonce, counter };

    assign blockOut = blockIn ^ aesBlockOutput;
    assign authOut = ghash ^ authTagCipher; // XOR with final GHASH for the auth tag

    assign blockNum = numBlocks;
    assign blockReady = curState == S_DataIn;
    assign authInReady = curState == S_AuthIn;

    assign gfmulY = hashKey; // We always multiply by the H value: E(K, 0)
    assign ghashNext = gfmulZ;

    assign done = curState == S_Done;

    always @ (rst) begin
        if (rst == 1) begin
            // authOut = 0;
            curState = 0;
            curPipelineCount = 0;
            numBlocks = 0;
            numAuth = 0;
            counter = 1;
            nonce = 0;
            ghash = 0;
            gfmulX = 0;
            lenConcat = 0;
            authTagCipher = 0;
        end
    end

    // State machine logic
    always @ (posedge clk) begin
        if (!rst) begin
            case (curState)
                S_Ready: begin
                    if (start) begin
                        if (finalAuth)
                            curState <= S_Waiting;
                        else
                            curState <= S_AuthIn;
                    end

                    counter = 2;
                    nonce = nonceIn;
                    ghash = 0;
                    authTagCipher = 0;

                    curPipelineCount = 0;
                    numBlocks = 0;
                    numAuth = 0;
                end
                S_AuthIn: begin
                    if (curPipelineCount == PIPELINE_DELAY)
                        curState <= S_Ek0;
                    else if (finalAuth)
                        curState <= S_Waiting;

                    curPipelineCount = curPipelineCount + 1;
                    numAuth = numAuth + 1;
                end
                S_Waiting: begin
                    if (curPipelineCount == PIPELINE_DELAY)
                        curState <= S_Ek0;

                    curPipelineCount = curPipelineCount + 1;
                end
                S_Ek0: begin // Save the output of Counter 0 through AES for the final auth tag
                    authTagCipher = aesBlockOutput;

                    if (finalBlock)
                        curState <= S_AuthTag;
                    else begin
                        curState <= S_DataIn;
                    end
                end
                S_DataIn: begin
                    if (finalBlock)
                        curState <= S_AuthTag;

                    numBlocks = numBlocks + 1;
                end
                S_AuthTag: begin
                    curState <= S_Done;
                end
                S_Done: begin
                    if (!start)
                        curState <= S_Ready;
                end
            endcase

            if (curState != S_Ready && curState != S_AuthTag && curState != S_Done)
                counter = counter + 1;
            
            if (curState == S_AuthIn || curState == S_DataIn || curState == S_AuthTag) begin
                ghash = ghashNext;
            end
        end
    end

    // Combinatorial logic for state machine (ghash)
    always @(curState, ghash, authIn, blockIn, aesBlockOutput, numAuth, numBlocks) begin
        // Calculate ghash
        case (curState)
            S_AuthIn: begin // GHASH with the authentication data
                gfmulX = ghash ^ authIn;
            end
            S_DataIn: begin // GHASH with the cipher texts
                if (encNotDec) 
                    gfmulX = ghash ^ (blockIn ^ aesBlockOutput); // XOR with cipher text
                else
                    gfmulX = ghash ^ blockIn; // XOR with cipher text (which is block input)
            end
            S_AuthTag: begin
                gfmulX = ghash ^ { numAuth << 7, numBlocks << 7 }; // XOR with lenA || len C
            end
        endcase
    end

    aes_128 encrypter(
          .clk(clk)
        , .state(aesBlockInput)
        , .key(cipherKey)
        , .out(aesBlockOutput)
    );

    galois_mult gfmul(
          .x(gfmulX)
        , .y(gfmulY)
        , .z(gfmulZ)
    );
endmodule
