
int main(int argc, char const *argv[]) {
    volatile unsigned int *addr_sha = (int*) 0x43000000;
    int data;

    // Exercise SHA

    // RO_ODOMETER_Go=0;
    *(addr_sha+0) = 0;
    *(addr_sha+1) = 0;
   *(addr_sha+2) = 0xFFFFFFFF;
   *(addr_sha+3) = 0xFFFFFFFF;
   *(addr_sha+4) = 0xFFFFFFFF;
   *(addr_sha+5) = 0xFFFFFFFF;
   *(addr_sha+6) = 0xFFFFFFFF;
   *(addr_sha+7) = 0xFFFFFFFF;
   *(addr_sha+8) = 0xFFFFFFFF;
   *(addr_sha+9) = 0xFFFFFFFF;
   *(addr_sha+10) = 0xFFFFFFFF;
   *(addr_sha+11) = 0xFFFFFFFF;
   *(addr_sha+12) = 0xFFFFFFFF;
   *(addr_sha+13) = 0xFFFFFFFF;
   *(addr_sha+14) = 0xFFFFFFFF;
   *(addr_sha+15) = 0xFFFFFFFF;
   *(addr_sha+16) = 0xFFFFFFFF;
   *(addr_sha+17) = 0x1234FFFF;
   *(addr_sha+18) = 0x00000000;
   *(addr_sha+19) = 0x00000000;
   *(addr_sha+20) = 0x00000000;
   *(addr_sha+21) = 0x00000000;
   *(addr_sha+22) = 0x00000000;
   *(addr_sha+23) = 0x00000000;
   *(addr_sha+24) = 0x00000000;
   *(addr_sha+25) = 0x00000000;
   *(addr_sha+26) = 0x00000000;
   *(addr_sha+27) = 0x00000000;
   *(addr_sha+28) = 0x00000000;
   *(addr_sha+29) = 0x00000000;
   *(addr_sha+30) = 0x00000000;
   *(addr_sha+31) = 0x00000000;
   *(addr_sha+32) = 0x00000000;
   *(addr_sha+33) = 0x00000000;
   *(addr_sha+0) = 1;
   *(addr_sha+0) = 0;
    // Check Valid_out == 1
    do {
     data = *(addr_sha+52);
    } while (data != 1);

    // Read output
    for (int i = 34; i <= 49; i++) {
        data = *(addr_sha+i);
    }
   *(addr_sha+2) = 0xFFFF1234;
   *(addr_sha+3) = 0xFFFFFFFF;
   *(addr_sha+4) = 0xFFFFFFFF;
   *(addr_sha+5) = 0xFFFFFFFF;
   *(addr_sha+6) = 0xFFFFFFFF;
   *(addr_sha+7) = 0xFFFFFFFF;
   *(addr_sha+8) = 0xFFFFFFFF;
   *(addr_sha+9) = 0xFFFFFFFF;
   *(addr_sha+10) = 0xFFFFFFFF;
   *(addr_sha+11) = 0xFFFFFFFF;
   *(addr_sha+12) = 0xFFFFFFFF;
   *(addr_sha+13) = 0xFFFFFFFF;
   *(addr_sha+14) = 0xFFFFFFFF;
   *(addr_sha+15) = 0xFFFFFFFF;
   *(addr_sha+16) = 0xFFFFFFFF;
   *(addr_sha+17) = 0xFFFFFFFF;
   *(addr_sha+18) = 0xFFFFFFFF;
   *(addr_sha+19) = 0xFFFFFFFF;
   *(addr_sha+20) = 0xFFFFFFFF;
   *(addr_sha+21) = 0xFFFFFFFF;
   *(addr_sha+22) = 0xFFFFFFFF;
   *(addr_sha+23) = 0xFFFFFFFF;
   *(addr_sha+24) = 0xFFFFFFFF;
   *(addr_sha+25) = 0xFFFFFFFF;
   *(addr_sha+26) = 0xFFFFFFFF;
   *(addr_sha+27) = 0xFFFFFFFF;
   *(addr_sha+28) = 0xFFFFFFFF;
   *(addr_sha+29) = 0xFFFFFFFF;
   *(addr_sha+30) = 0xFFFFFFFF;
   *(addr_sha+31) = 0xFFFFFFFF;
   *(addr_sha+32) = 0xFFFFFFFF;
   *(addr_sha+33) = 0xFFFFFFFF;
    *(addr_sha+1) = 1;
   *(addr_sha+0) = 1;
   *(addr_sha+0) = 0;
    // Check Valid_out == 1
    do {
     data = *(addr_sha+52);
    } while (data != 1);

    // Read output
    for (int i = 34; i <= 49; i++) {
        data = *(addr_sha+i);
    }
    *(addr_sha+1) = 2;

   *(addr_sha+0) = 1;
   *(addr_sha+0) = 0;
    // Check Valid_out == 1
    do {
     data = *(addr_sha+52);
    } while (data != 1);

    // Read output
    for (int i = 34; i <= 49; i++) {
        data = *(addr_sha+i);
    }

    *(addr_sha+0) = 0;

    return 0;
}

