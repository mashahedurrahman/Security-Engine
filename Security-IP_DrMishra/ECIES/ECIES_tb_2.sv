 //Developed by Jennifer Sheldon, Andrew Whigham, Daniel Volya, and Dr. Prabhat Mishra at the University of Florida.
//`timescale 100ns/1ns

module ECIES_full_tb;
 parameter period = 10; // Clock period
    parameter     message_width = 32;
    //For Elliptic Curve private and public key (public so no cutoffs by multiplication)
    parameter          key_size = 128;
    //For SHA HMAC
    parameter    mac_key_length = 256;
    //For AES 128 bit key CTR mode.
    parameter       dec_key_len = 128;
    parameter       enc_key_len = 128;
    //From SHA interface.
    parameter       hashed_width = 512;
    //Mostly ECC curve parameter size widths.
    parameter      integer_size = 64;
    parameter AES_PIPELINE_DELAY = 41;

    integer errorCount = 0;
    integer correctCount = 0;

    // Inputs
    logic                                         rst, clk, sim_done, AES_rst, enc_kdf_hashGo, dec_kdf_hashGo, enc_kdf_hashDone, dec_kdf_hashDone, hash_ready;
    logic                                         decrypter_go, encrypter_go, keyGen_go, infinityP, encNotDec;
    logic                                         dec_hash_done, enc_hash_done;
    logic                                         dec_done, enc_done;
    logic                   [message_width-1 : 0] messageReturn, message;
    logic                   [hashed_width-1 : 0] enc_hashedMessage, dec_hashedMessage;
    logic                   [message_width-1 : 0] enc_encryptedMessage, dec_encryptedMessage;
    logic                   [message_width-1 : 0] enc_messageToProcess, dec_messageToProcess;
    logic                   [message_width-1 : 0] messageOutput;
    logic                          [key_size-1:0] privateKey;
    logic                          [key_size-1:0] counter;
    logic                          [key_size-1:0] nonce;
    logic                          [key_size-1:0] publicKeyX;
    logic                          [key_size-1:0] publicKeyY;
    logic [message_width + 2*integer_size + hashed_width -1:0] full_cipher;
    logic                 [mac_key_length - 1: 0] mac_key;
    logic                      [dec_key_len-1: 0] dec_key;
    logic                                         enc_ready, dec_ready;
    logic                                         enc_hash_go, dec_hash_go;
    logic                                         dec_go, enc_go, keyGen_done;
    logic                                         encrypter_done, decrypter_done;
    logic                                         enc_valid, dec_valid;
    logic                      [integer_size-1:0] prime;
    logic                      [integer_size-1:0] A;
    logic                      [integer_size-1:0] B;
    logic                      [integer_size-1:0] Px, Py;
    logic                      [integer_size-1:0] Ox,Oy;
    logic                      [integer_size-1:0] n;
    logic                      [integer_size+16-1:0] encrypt_kdf_req, decrypt_kdf_req;
    logic                      [hashed_width-1:0] encrypt_kdf_hashed, decrypt_kdf_hashed;

        aes_CTR_mode #(
            //.keylen(enc_key_size)
            .keylen(enc_key_len)
        ) inst_aes_CTR_mode (
            .clk        (clk),
            .encNotDec  (encNotDec),
            .rst        (AES_rst),
            .key        (privateKey),
            .messageIn  (enc_messageToProcess),
            .cipherIn   (dec_messageToProcess),
            .nonce      (nonce),
            .counterIn  (counter),
            .messageOut (messageReturn),
            .cipherOut  (enc_encryptedMessage)
        );
        assign encNotDec = enc_go;

            montgomeryLadder #(
            .key_size(key_size),
            .integer_size(integer_size)
        ) inst_montgomeryLadder (
            .m         (privateKey),
            .clk       (clk),
            .rst       (rst),
            .go        (keyGen_go),
            .done      (keyGen_done),
            .infinityP (infinityP),
            .prime     (prime),
            .A         (A),
            .B         (B),
            .Px        (Px),
            .Py        (Py),
            .Ox        (Ox),
            .Oy        (Oy),
            .mGx       (publicKeyX),
            .mGy       (publicKeyY)
        );

        ECIES_top #(
            .message_width(message_width),
            .hashed_width(hashed_width),
            .key_size(key_size),
            .mac_key_length(mac_key_length),
            .enc_key_len(enc_key_len),
            .dec_key_len(dec_key_len),
            .integer_size(integer_size)
        ) inst_ECIES_top (
            .clk              (clk),
            .rst              (rst),
            .encrypter_go     (encrypter_go),
            .decrypter_go     (decrypter_go),
            .hash_ready       (hash_ready),
            .enc_hash_done    (enc_hash_done),
            .dec_hash_done    (dec_hash_done),
            .enc_kdf_done     (enc_kdf_done),
            .dec_kdf_done     (dec_kdf_done),
            .enc_done         (enc_done),
            .dec_done         (dec_done),
            .enc_kdf_hashDone (enc_kdf_hashDone),
            .dec_kdf_hashDone (dec_kdf_hashDone),
            .messageReturn    (messageReturn),
            .message          (message),
            .enc_encryptedMessage (enc_encryptedMessage),
            .enc_messageToProcess (enc_messageToProcess),
            .dec_messageToProcess (dec_messageToProcess),
            .messageOutput    (messageOutput),
            .hashedMessage    (hashedMessage),
            .enc_hashedMessage    (enc_hashedMessage),
            .dec_hashedMessage    (dec_hashedMessage),
            .encrypt_kdf_hashed (encrypt_kdf_hashed),
            .decrypt_kdf_hashed (decrypt_kdf_hashed),
            .encrypt_kdf_req  (encrypt_kdf_req),
            .decrypt_kdf_req  (decrypt_kdf_req),
            .enc_kdf_hashGo   (enc_kdf_hashGo),
            .dec_kdf_hashGo   (dec_kdf_hashGo),
            .enc_ready        (enc_ready),
            .dec_ready        (dec_ready),
            .enc_hash_go      (enc_hash_go),
            .dec_hash_go      (dec_hash_go),
            .enc_go           (enc_go),
            .dec_go           (dec_go),
            .encrypter_done   (encrypter_done),
            .decrypter_done   (decrypter_done),
            .key_done         (key_done),
            .enc_valid        (enc_valid),
            .dec_valid        (dec_valid),
            .privateKey       (privateKey),
            .counter          (counter),
            .nonce            (nonce),
            .publicKeyX       (publicKeyX),
            .publicKeyY       (publicKeyY),
            .enc_key          (enc_key),
            .dec_key          (dec_key),
            .prime            (prime),
            .A                (A),
            .B                (B),
            .Px               (Px),
            .Py               (Py),
            .n                (n)
        );


        always
        #(period / 2) clk <= !clk & !sim_done;

        initial begin
            clk <= 1;
        sim_done <= 1'b0;
        rst <= 1;
        //Simulated hasher is always ready.
        hash_ready <= 1'b1;
        //AES is separate reset to restart counter for decryption.
        AES_rst <= 1'b1;
        counter <= 0;
        #period;
            rst <= 0;
            enc_kdf_hashDone <= 1'b0;
            dec_kdf_hashDone <= 1'b0;
            privateKey <= 3; /* Arbitrary prime less than 37 */
            prime <= 7;
            A <= 0;
            B <= 5;
            n <= 7;
            Px <= 3;
            Py <= 2;
            nonce <= 0;
            counter <= 0;
            keyGen_go <= 1'b1;
            wait(keyGen_done == 1'b1);
            encrypter_go <= 1;
            //"Random" message.
            message <= 4'b1000;
            wait(enc_kdf_hashGo == 1'b1);
            //Hash just needs to be deterministic for decryption.
            encrypt_kdf_hashed <= 300;
            enc_kdf_hashDone <= 1'b1;
            wait(enc_go == 1'b1);
            //For AES encryption.
            AES_rst <= 1'b0;
             #(period*AES_PIPELINE_DELAY);
             #(period*AES_PIPELINE_DELAY);
            #(2*period);
            $display("Encrypted output ", enc_encryptedMessage);
            enc_done <= 1'b1;
            //Switch to decryption.
            //"Random" hash from random oracle model.
            enc_hashedMessage <= message ^ 10;
            enc_hash_done <= 1'b1;
            wait(encrypter_done == 1'b1);
            assert (enc_valid == 1'b1) $display("Valid encryption");
            else $error("Failed encryption");
            //Don't switch off go so that decrypter can get ciphertext because encrypt will reset on go switch.
             decrypter_go <= 1'b1;
            AES_rst <= 1'b1;
            wait(dec_kdf_hashGo == 1'b1);
            //Hash just needs to be deterministic for decryption.
            decrypt_kdf_hashed <= 300;
            dec_kdf_hashDone <= 1'b1;
            wait(dec_hash_go == 1'b1);
            //Same value hashes to same thing bc hash is deterministic.
            dec_hashedMessage <= enc_hashedMessage;
            dec_hash_done <= 1'b1;
            wait(dec_go == 1'b1 || decrypter_done == 1'b1);
            //enc_go <= 1'b0;
            AES_rst <= 1'b0;
            #(period*AES_PIPELINE_DELAY);
            #(period*AES_PIPELINE_DELAY + 2*period);
            $display("decrypting ", dec_messageToProcess);
            $display("messageOut[31:0] ", messageReturn);   // mash
            $display("cipherOut[31:0] ", enc_encryptedMessage);     // mash
            dec_done <= 1'b1;
            wait(decrypter_done == 1'b1);
            assert (dec_valid == 1'b1) $display("Valid decrypt");
            else $error("invalid decrypt");
            assert (messageOutput == message) $display("Correct Message");
            else $error("Incorrect Message ", messageOutput, " ", message);
            sim_done <= 1'b1;
            #100;
            $finish;
        end


        initial begin
            $dumpfile("dump.vcd");
            $dumpvars;
        end
    endmodule : ECIES_full_tb
