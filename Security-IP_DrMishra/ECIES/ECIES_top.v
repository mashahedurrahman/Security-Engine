
module ECIES_top #(parameter message_width = 32, parameter hashed_width = 512,  parameter key_size = 128, parameter mac_key_length = 256, parameter enc_key_len = 128, parameter dec_key_len = 128, parameter integer_size = 64) (
  input wire clk, rst, encrypter_go, decrypter_go, hash_ready, enc_hash_done, dec_hash_done, enc_kdf_done, dec_kdf_done, enc_done, dec_done, enc_kdf_hashDone, dec_kdf_hashDone,
  input wire [message_width-1 : 0] messageReturn, message, enc_encryptedMessage, 
  output wire [message_width-1 : 0] enc_messageToProcess, dec_messageToProcess, messageOutput,
  input wire [hashed_width-1 : 0] hashedMessage, enc_hashedMessage, dec_hashedMessage, encrypt_kdf_hashed, decrypt_kdf_hashed,
  output wire [integer_size+16-1:0] encrypt_kdf_req, decrypt_kdf_req,
  output wire enc_kdf_hashGo, dec_kdf_hashGo, enc_ready, dec_ready, enc_hash_go, dec_hash_go, dec_go, enc_go, encrypter_done, decrypter_done, key_done, enc_valid, dec_valid, 
  input wire [key_size-1:0] privateKey, counter, nonce,publicKeyX, publicKeyY,
  output wire [enc_key_len-1: 0] enc_key,
  output wire [dec_key_len-1: 0] dec_key,
  input wire [integer_size-1:0] prime, A, B, Px, Py, n
);

  wire [message_width + 2*integer_size + hashed_width -1:0] full_cipher;
  wire [mac_key_length - 1: 0] mac_key;


  ECIES_encrypt #(
            .message_width(message_width),
            .key_size(key_size),
            .mac_key_length(mac_key_length),
            .enc_key_len(enc_key_len),
            .integer_size(integer_size),
            .hashed_width(hashed_width)
        ) inst_ECIES_encrypt (
            .clk              (clk),
            .rst              (rst),
            .go               (encrypter_go),
            .hash_ready       (hash_ready),
            .hash_done        (enc_hash_done),
            .enc_done         (enc_done),
            .message          (message),
            .hashedMessage    (enc_hashedMessage),
            .encryptedMessage (enc_encryptedMessage),
            .messageToProcess (enc_messageToProcess),
            .kdf_hashedVal (encrypt_kdf_req),
            .KDF_done         (enc_kdf_done),
            .kdf_hashOut (encrypt_kdf_hashed),
            .kdf_hashGo (enc_kdf_hashGo),
            .kdf_hashDone (enc_kdf_hashDone),
            .privateKey       (privateKey),
            .counter          (counter),
            .nonce            (nonce),
            .publicKeyX       (publicKeyX),
            .publicKeyY       (publicKeyY),
            .full_cipher      (full_cipher),
            .mac_key          (mac_key),
            .enc_key          (enc_key),
            .ready            (enc_ready),
            .hash_go          (enc_hash_go),
            .enc_go           (enc_go),
            .done             (encrypter_done),
            .key_done         (key_done),
            .valid            (enc_valid),
            .prime            (prime),
            .A                (A),
            .B                (B),
            .Gx               (Px),
            .Gy               (Py),
            .n                (n)
        );

     ECIES_decrypt #(
            .message_width(message_width),
            .key_size(key_size),
            .mac_key_length(mac_key_length),
            .dec_key_len(dec_key_len),
            .integer_size(integer_size),
            .hashed_width(hashed_width)
        ) inst_ECIES_decrypt (
            .clk              (clk),
            .rst              (rst),
            .hash_ready       (hash_ready),
            .KDF_done         (dec_kdf_done),
            .go               (decrypter_go),
            .hash_done        (dec_hash_done),
            .dec_done         (dec_done),
            .messageReturn    (messageReturn),
            .hashedMessage    (hashedMessage),
            .encryptedMessage (dec_hashedMessage),
            .messageToProcess (dec_messageToProcess),
            .messageOutput    (messageOutput),
            .kdf_hashedVal (decrypt_kdf_req),
            .kdf_hashOut (decrypt_kdf_hashed),
            .kdf_hashGo (dec_kdf_hashGo),
            .kdf_hashDone (dec_kdf_hashDone),
            .privateKey       (privateKey),
            .counter          (counter),
            .nonce            (nonce),
            .publicKeyX       (publicKeyX),
            .publicKeyY       (publicKeyY),
            .full_cipher      (full_cipher),
            .mac_key          (mac_key),
            .dec_key          (dec_key),
            .ready            (dec_ready),
            .hash_go          (dec_hash_go),
            .dec_go           (dec_go),
            .done             (decrypter_done),
            .valid            (dec_valid),
            .prime            (prime),
            .A                (A),
            .B                (B),
            .Gx               (Px),
            .Gy               (Py),
            .n                (n)
        );



endmodule
