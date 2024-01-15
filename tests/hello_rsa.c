
int main(int argc, char const *argv[]) {
    volatile unsigned long long int *addr_rsa = (long long int*) 0x50000000;
    unsigned long long int data;

    // Exercise RSA
    // Test 1
    // go = 0
    *(addr_rsa+96) = 0;
    
    // message = 8
    for (int i = 31; i >= 1; i--) {
        *(addr_rsa+i) = 0;
    }
    *(addr_rsa+0) = 8;

    // exponent = 13
    for (int i = 63; i >= 33; i--) {
        *(addr_rsa+i) = 0;
    }
    *(addr_rsa+32) = 13;

    // modulus = 77
    for (int i = 95; i >= 65; i--) {
        *(addr_rsa+i) = 0;
    }
    *(addr_rsa+64) = 77;

    // go = 1
    *(addr_rsa+96) = 1;

    // check done = 1
    do {
        data = *(addr_rsa+129);
    } while (data != 1);

    // read output
    for (int i = 97; i <= 128; i++) {
        data = *(addr_rsa+i);
    }
    // Test 1 complete
    

    // Test 2
    // go = 0
    *(addr_rsa+96) = 0;
    
    // message <= cipher = 50
    for (int i = 1; i <= 31; i++) {
        *(addr_rsa+i) = 0;
    }
    *(addr_rsa+0) = 50;

    // exponent = 37
    for (int i = 63; i >= 33; i--) {
        *(addr_rsa+i) = 0;
    }
    *(addr_rsa+32) = 37;

    // modulus = 77
    for (int i = 95; i >= 65; i--) {
        *(addr_rsa+i) = 0;
    }
    *(addr_rsa+64) = 77;

    // go = 1
    *(addr_rsa+96) = 1;

    // check done = 1
    do {
        data = *(addr_rsa+129);
    } while (data != 1);

    // read output
    for (int i = 128; i >= 97; i--) {
        data = *(addr_rsa+i);
    }
    // Test 2 complete


    // Test 3
    // go = 0
    *(addr_rsa+96) = 0;
    
    // message = 25
    for (int i = 1; i <= 31; i++) {
        *(addr_rsa+i) = 0;
    }
    *(addr_rsa+0) = 25;

    // exponent = 7
    for (int i = 63; i >= 33; i--) {
        *(addr_rsa+i) = 0;
    }
    *(addr_rsa+32) = 7;

    // modulus = 143
    for (int i = 95; i >= 65; i--) {
        *(addr_rsa+i) = 0;
    }
    *(addr_rsa+64) = 143;

    // go = 1
    *(addr_rsa+96) = 1;

    // check done = 1
    do {
        data = *(addr_rsa+129);
    } while (data != 1);

    // read output
    for (int i = 128; i >= 97; i--) {
        data = *(addr_rsa+i);
    }
    // Test 3 complete


    // Test 4
    // go = 0
    *(addr_rsa+96) = 0;
    
    // message <= cipher = 64
    for (int i = 1; i <= 31; i++) {
        *(addr_rsa+i) = 0;
    }
    *(addr_rsa+0) = 64;

    // exponent = 103
    for (int i = 63; i >= 33; i--) {
        *(addr_rsa+i) = 0;
    }
    *(addr_rsa+32) = 103;

    // modulus = 143
    for (int i = 95; i >= 65; i--) {
        *(addr_rsa+i) = 0;
    }
    *(addr_rsa+64) = 143;

    // go = 1
    *(addr_rsa+96) = 1;

    // check done = 1
    do {
        data = *(addr_rsa+129);
    } while (data != 1);

    // read output
    for (int i = 128; i >= 97; i--) {
        data = *(addr_rsa+i);
    }
    // Test 4 complete





    //*addr_rsa = 0x123456789ABCDEF1;

    //data = *addr_rsa;

    //if (data == 0x123456789ABCDEF1) {
    //    *(addr_rsa+1) = 0x1FEDCBA987654321;
    //    *(addr_rsa+2) = 0x1FEDCBA9876543;
    //    *(addr_rsa+3) = 0x1FEDCBA98765;
    //    *(addr_rsa+4) = 0x1FEDCBA987;
    //    *(addr_rsa+5) = 0x1FEDCBA9;
    //    *(addr_rsa+6) = 0x1FEDCB;
    //    *(addr_rsa+7) = 0x1FED;
    //    *(addr_rsa+8) = 0x1F;
    //}

    return 0;
}

