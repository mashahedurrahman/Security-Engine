
int main(int argc, char const *argv[]) {
    volatile unsigned int *addr_trng = (int*) 0x60000000;
    int data;

    // Exercise TRNG
    // Test 1
    // Op_Type=2'b00;
    *(addr_trng+1) = 0;

    // TRNG_Go=0;
    *(addr_trng+0) = 0;

    // data_in=1452664;
    *(addr_trng+2) = 1452664;
    for (int i = 3; i <= 17; i++) {
        *(addr_trng+i) = 0;
    }

    // TRNG_Go=1
    *(addr_trng+0) = 1;

    // TRNG_Go=0;
    *(addr_trng+0) = 0;

    // Check TRNG_Done == 1
    do {
        data = *(addr_trng+22);
    } while (data != 1);

    // Read output
    for (int i = 18; i <= 21; i++) {
        data = *(addr_trng+i);
    }
    // Test 1 Complete



    // Test 2
    // Op_Type=2'b10;
    *(addr_trng+1) = 2;

    // TRNG_Go=0;
    *(addr_trng+0) = 0;

    // data_in=323464;
    *(addr_trng+2) = 323464;
    for (int i = 3; i <= 17; i++) {
        *(addr_trng+i) = 0;
    }

    // TRNG_Go=1
    *(addr_trng+0) = 1;

    // TRNG_Go=0;
    *(addr_trng+0) = 0;

    // Check TRNG_Done == 1
    do {
        data = *(addr_trng+22);
    } while (data != 1);

    // Read output
    for (int i = 18; i <= 21; i++) {
        data = *(addr_trng+i);
    }
    // Test 2 Complete



    // Test 3
    // Op_Type=2'b11;
    *(addr_trng+1) = 3;

    // TRNG_Go=0;
    *(addr_trng+0) = 0;

    // data_in=0;
    *(addr_trng+2) = 0;
    for (int i = 3; i <= 17; i++) {
        *(addr_trng+i) = 0;
    }

    // TRNG_Go=1
    *(addr_trng+0) = 1;

    // TRNG_Go=0;
    *(addr_trng+0) = 0;

    // Check TRNG_Done == 1
    do {
        data = *(addr_trng+22);
    } while (data != 1);

    // Read output
    for (int i = 18; i <= 21; i++) {
        data = *(addr_trng+i);
    }
    // Test 3 Complete





    //*(addr_trng+2) = 0xEF;

    //data = *(addr_trng+2);

    //if (data == 0xEF) {
    //    *(addr_trng+3) = 0xCD;
    //}

    return 0;
}

