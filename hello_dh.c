
int main(int argc, char const *argv[]) {
    volatile unsigned int *addr_dh = (int*) 0x46000000;
    int data;

    // Exercise DH

    // DH_Go=0;
    *(addr_dh+0) = 0;
   *(addr_dh+1) = 0x00000002;
   *(addr_dh+2) = 0x00000004;
   *(addr_dh+3) = 0x00000006;
   *(addr_dh+4) = 0x00000008;
   *(addr_dh+5) = 0x0000000A;
   *(addr_dh+6) = 0x0000000C;
   *(addr_dh+7) = 0x0000000E;
   *(addr_dh+8) = 0x00000012;
   *(addr_dh+9) = 0x00000014;
   *(addr_dh+10) = 0x00000012;
   *(addr_dh+11) = 0x00000014;
   *(addr_dh+12) = 0x00000016;
   *(addr_dh+13) = 0x00000018;
   *(addr_dh+14) = 0x0000001A;
   *(addr_dh+15) = 0x0000001C;
   *(addr_dh+16) = 0x0000001E;
   *(addr_dh+17) = 0x00000022;
   *(addr_dh+18) = 0x00000024;

   // DH_Go=1;
    *(addr_dh+0) = 1;

   // DH_Go=0;
    *(addr_dh+0) = 0;

    // Check done == 1
    do {
     data = *(addr_dh+28);
    } while (data != 1);

    // Read output
    for (int i = 19; i <= 27; i++) {
        data = *(addr_dh+i);
    }

    return 0;
}
