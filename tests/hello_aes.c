
int main(int argc, char const *argv[]) {
    volatile unsigned int *addr_aes = (int*) 0x45000000;
    int data;

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


    // Encryption stage
    // AES Software reset 
    *(addr_aes+17) = 1;

    // aes encryption signal;
    *(addr_aes+0) = 1;

     //message in 
     *(addr_aes+5) = 8;
     *(addr_aes+6) = 0x0;
     *(addr_aes+7) = 0x0;
     *(addr_aes+8) = 0x0;

    // AES Software reset off 
    *(addr_aes+17) = 0;


    // Check done_cipher == 1
    do {
        data = *(addr_aes+26);
    } while (data != 1);

    // Read cipher output
    for (int i = 21; i <= 24; i++) {
        data = *(addr_aes+i);
    }


    // Decryption stage
    // AES Software reset 
    *(addr_aes+17) = 1;
    
    // aes encryption signal;
    *(addr_aes+0) = 0;

     //cipher in 
     *(addr_aes+9) = 0x9b9c4d84;
     *(addr_aes+10) = 0x0;
     *(addr_aes+11) = 0x0;
     *(addr_aes+12) = 0x0;

    // AES Software reset off 
    *(addr_aes+17) = 0;

    // Check done_message == 1
    do {
        data = *(addr_aes+25);
    } while (data != 1);

    // Read message output
    for (int i = 17; i <= 20; i++) {
        data = *(addr_aes+i);
    }




    return 0;
}


