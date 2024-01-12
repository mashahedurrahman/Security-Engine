
int main(int argc, char const *argv[]) {
    volatile unsigned int *addr_ecies = (int*) 0x70000000;
    int data, data1;

    //----------------ECC------------------
    volatile unsigned int *addr_ecc = (int*) 0x44000000;
    int m1, m2, m3, m4, m5, m6, m7, m8;
    int prime_1, prime_2, A_1, A_2, B_1, B_2, Px_1, Px_2, Py_1, Py_2, Ox_1, Ox_2, Oy_1, Oy_2;
    int go, done, infinityP;
    int mGx_1, mGx_2, mGx_3, mGx_4, mGx_5, mGx_6, mGx_7, mGx_8;
    int mGy_1, mGy_2, mGy_3, mGy_4, mGy_5, mGy_6, mGy_7, mGy_8;
    //----------------ECC------------------

    volatile unsigned int *addr_aes = (int*) 0x45000000;
    int cipher_1, cipher_2, cipher_3, cipher_4, msg_1, msg_2, msg_3, msg_4;

    // Exercise ECIES
    
    // hash_ready <= 1'b1
    *(addr_ecies+0) = 1;

    // AES_rst <= 1'b1
    // Need to soft reset AES

    // counter <= 0
    for (int i = 1; i <= 4; i++) {
        *(addr_ecies+i) = 0;
    }

    // enc_kdf_hashDone <= 1'b0
    *(addr_ecies+5) = 0;

    // dec_kdf_hashDone <= 1'b0
    *(addr_ecies+6) = 0;

    // privateKey <= 3
    *(addr_ecies+7) = 3;
    *(addr_ecies+8) = 0;
    *(addr_ecies+9) = 0;
    *(addr_ecies+10) = 0;

    // prime <= 7
    *(addr_ecies+11) = 7;
    *(addr_ecies+12) = 0;

    // A <= 0
    *(addr_ecies+13) = 0;
    *(addr_ecies+14) = 0;

    // B <= 5
    *(addr_ecies+15) = 5;
    *(addr_ecies+16) = 0;

    // n <= 7
    *(addr_ecies+17) = 7;
    *(addr_ecies+18) = 0;

    // Px <= 3
    *(addr_ecies+19) = 3;
    *(addr_ecies+20) = 0;

    // Py <= 2
    *(addr_ecies+21) = 2;
    *(addr_ecies+22) = 0;

    // nonce <= 0
    *(addr_ecies+23) = 0;
    *(addr_ecies+24) = 0;
    *(addr_ecies+25) = 0;
    *(addr_ecies+26) = 0;

    // counter <= 0
    for (int i = 1; i <= 4; i++) {
        *(addr_ecies+i) = 0;
    }
   
    //----------------ECC------------------
    m1 = 3;
    m2 = 0x00;
    m3 = 0x00;
    m4 = 0x00;
    m5 = 0x00;
    m6 = 0x00;
    m7 = 0x00;
    m8 = 0x00;

    prime_1 = 7; prime_2 = 0x00;
    A_1 = 0x00; A_2 = 0x00;
    B_1 = 5; B_2 = 0x00;
    Px_1 = 3; Px_2 = 0x00;
    Py_1 = 2; Py_2 = 0x00;
    Ox_1 = 0x09; Ox_2 = 0x00;
    Oy_1 = 0x11; Oy_2 = 0x00;

    go = 0x01;

    // Sending input data to ECC IP
    *(addr_ecc+0) = m1;
    *(addr_ecc+1) = m2;
    *(addr_ecc+2) = m3;
    *(addr_ecc+3) = m4;
    *(addr_ecc+4) = m5;
    *(addr_ecc+5) = m6;
    *(addr_ecc+6) = m7;
    *(addr_ecc+7) = m8;
    *(addr_ecc+8) = prime_1;
    *(addr_ecc+9) = prime_2;
    *(addr_ecc+10) = A_1;
    *(addr_ecc+11) = A_2;
    *(addr_ecc+12) = B_1;
    *(addr_ecc+13) = B_2;
    *(addr_ecc+14) = Px_1;
    *(addr_ecc+15) = Px_2;
    *(addr_ecc+16) = Py_1;
    *(addr_ecc+17) = Py_2;
    *(addr_ecc+18) = Ox_1;
    *(addr_ecc+19) = Ox_2;
    *(addr_ecc+20) = Oy_1;
    *(addr_ecc+21) = Oy_2;
    // keyGen_go <= 1'b1;
    *(addr_ecc+22) = go;

    // wait(keyGen_done == 1'b1);
    done = 0x00;
    while (done != 0x01){
        done = *(addr_ecc+23);
    }

    // Read publicKeyX and publicKeyY from ECC
    mGx_1 = *(addr_ecc+25);
    mGx_2 = *(addr_ecc+26);
    mGx_3 = *(addr_ecc+27);
    mGx_4 = *(addr_ecc+28);
    mGx_5 = *(addr_ecc+29);
    mGx_6 = *(addr_ecc+30);
    mGx_7 = *(addr_ecc+31);
    mGx_8 = *(addr_ecc+32);
    mGy_1 = *(addr_ecc+33);
    mGy_2 = *(addr_ecc+34);
    mGy_3 = *(addr_ecc+35);
    mGy_4 = *(addr_ecc+36);
    mGy_5 = *(addr_ecc+37);
    mGy_6 = *(addr_ecc+38);
    mGy_7 = *(addr_ecc+39);
    mGy_8 = *(addr_ecc+40);

    //----------------ECC------------------

    
    // Send mGx and mGy to ECIES
    // publicKeyX <= mGx
    *(addr_ecies+99) = mGx_1;
    *(addr_ecies+100) = mGx_2;
    *(addr_ecies+101) = mGx_3;
    *(addr_ecies+102) = mGx_4;

    // publicKeyY <= mGy
    *(addr_ecies+103) = mGy_1;
    *(addr_ecies+104) = mGy_2;
    *(addr_ecies+105) = mGy_3;
    *(addr_ecies+106) = mGy_4;


    // message <= 4'b1000
    *(addr_ecies+28) = 8;

    // encrypter_go <= 1
    *(addr_ecies+27) = 1;

    // Check if enc_kdf_hashGo == 1'b1
    do {
        data = *(addr_ecies+109);
    } while (data != 1);

    // encrypt_kdf_hashed <= 300
    *(addr_ecies+29) = 300;
    for (int i = 30; i <= 44; i++) {
        *(addr_ecies+i) = 0;
    }

    // enc_kdf_hashDone <= 1'b1
    *(addr_ecies+5) = 1;

    // Check if enc_go == 1'b1
    do {
        data = *(addr_ecies+110);
    } while (data != 1);

    //---------------------AES encryption----------------------
    //aes key
    *(addr_aes+1) = 3;
    *(addr_aes+2) = 0x0;
    *(addr_aes+3) = 0x0;
    *(addr_aes+4) = 0x0;

    //aes nonce & counter
    *(addr_aes+13) = 0x0;
    *(addr_aes+14) = 0x0;
    *(addr_aes+15) = 0x0;
    *(addr_aes+16) = 0x0;

    // AES Software reset
    *(addr_aes+17) = 1;

    // aes encryption signal
    *(addr_aes+0) = 1;
 

    // Read enc_messageToProcess from ECIES
    // and send them to AES messageIn
    
    // Read enc_messageToProcess
    data = *(addr_ecies+121);

    // Need to send data to AES messageIn
    // message in 
    *(addr_aes+5) = data;
    *(addr_aes+6) = 0x0;
    *(addr_aes+7) = 0x0;
    *(addr_aes+8) = 0x0;


    // AES_rst <= 1'b0
    // Enable AES
    *(addr_aes+17) = 0;

    // Wait for AES to finish encryption and then
    // read cipherOut
    // Check done_cipher == 1
    do {
        data = *(addr_aes+26);
    } while (data != 1);
    
    
    // Send cipherOut[31:0] to ECIES enc_encryptedMessage
    // Read AES cipher output
    cipher_1 = *(addr_aes+21);
    cipher_2 = *(addr_aes+22);
    cipher_3 = *(addr_aes+23);
    cipher_4 = *(addr_aes+24);

    // enc_encryptedMessage <= cipherOut[31:0]
    *(addr_ecies+108) = cipher_1;

    // AES Software reset
    *(addr_aes+17) = 1;

    //---------------------AES encryption----------------------

    // enc_done <= 1'b1
    *(addr_ecies+46) = 1;



    // Switch to decryption

    // enc_hashedMessage <= message ^ 10
    *(addr_ecies+47) = 8 ^ 10;
    for (int i = 48; i <= 62; i++) {
         *(addr_ecies+i) = 0;
    } 

    // enc_hash_done <= 1'b1
    *(addr_ecies+63) = 1; 

    // Check if encrypter_done == 1'b1
    do {
        data = *(addr_ecies+112);
    } while (data != 1);

    // Check if enc_valid == 1'b1
    do {
        data = *(addr_ecies+113);
    } while (data != 1);

    // decrypter_go <= 1'b1
    *(addr_ecies+64) = 1;


    // AES_rst <= 1'b1
    // Need to soft reset AES
    *(addr_aes+17) = 1;

    // Check if dec_kdf_hashGo == 1'b1
    do {
        data = *(addr_ecies+114);
    } while (data != 1);

    // decrypt_kdf_hashed <= 300
    *(addr_ecies+65) = 300;
    for (int i = 66; i <= 80; i++) {
         *(addr_ecies+i) = 0;
    }

    // dec_kdf_hashDone <= 1'b1
    *(addr_ecies+6) = 1;

    // Check if dec_hash_go == 1'b1
    do {
        data = *(addr_ecies+115);
    } while (data != 1);

    // dec_hashedMessage <= enc_hashedMessage
    *(addr_ecies+81) = 8 ^ 10;
    for (int i = 82; i <= 96; i++) {
         *(addr_ecies+i) = 0;
    }

    // dec_hash_done <= 1'b1
    *(addr_ecies+97) = 1;

    // Check if dec_go == 1'b1 || decrypter_done == 1'b1
    do {
        data  = *(addr_ecies+116);
        data1 = *(addr_ecies+117);
    } while (data != 1 && data1 != 1);

     

    //---------------------AES decryption----------------------
    // aes encryption signal
    *(addr_aes+0) = 0;


    // Read dec_messageToProcess from ECIES
    // and send them to AES cipherIn
    
    // Read dec_messageToProcess
    data = *(addr_ecies+118);

    // Need to send data to AES cipherIn
    //cipher in
    *(addr_aes+9) = data;
    *(addr_aes+10) = 0x0;
    *(addr_aes+11) = 0x0;
    *(addr_aes+12) = 0x0;


    // AES_rst <= 1'b0
    // Enable AES
    *(addr_aes+17) = 0;


    // Wait for AES to finish decryption and then
    // read messageOut
    // Check done_message == 1
    do {
        data = *(addr_aes+25);
    } while (data != 1);

    // Read AES message output
    msg_1 = *(addr_aes+17);
    msg_2 = *(addr_aes+18);
    msg_3 = *(addr_aes+19);
    msg_4 = *(addr_aes+20);

    // Send messageOut[31:0] to ECIES messageReturn 
    // messageReturn <= messageOut[31:0]
    *(addr_ecies+107) = msg_1;

    // AES Software reset
    *(addr_aes+17) = 1;

    //---------------------AES decryption----------------------



    // dec_done <= 1'b1
    *(addr_ecies+98) = 1;

    // Check if decrypter_done == 1'b1
    do {
        data = *(addr_ecies+117);
    } while (data != 1);

    // Check if dec_valid == 1'b1
    do {
        data = *(addr_ecies+119);
    } while (data != 1);

    // Read messageOutput
    data = *(addr_ecies+120);







    //*(addr_ecies+1) = 0xEF;

    //data = *(addr_ecies+1);

    //if (data == 0xEF) {
    //    *(addr_ecies+2) = 0xCD;
    //}
    //*(addr_ecies+7) = data;

    return 0;
}

