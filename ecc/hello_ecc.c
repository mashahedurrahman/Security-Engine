int main(int argc, char const *argv[]) {
    volatile unsigned int *addr_ecc = (int*) 0x50000000;
    int m1, m2, m3, m4, m5, m6, m7, m8;
    int prime_1, prime_2, A_1, A_2, B_1, B_2, Px_1, Px_2, Py_1, Py_2, Ox_1, Ox_2, Oy_1, Oy_2;
    int go, done, infinityP;
    int mGx_1, mGx_2, mGx_3, mGx_4, mGx_5, mGx_6, mGx_7, mGx_8;
    int mGy_1, mGy_2, mGy_3, mGy_4, mGy_5, mGy_6, mGy_7, mGy_8;

    m1 = 0x7E;
    m2 = 0x08;
    m3 = 0x00;
    m4 = 0x00;
    m5 = 0x00;
    m6 = 0x00;
    m7 = 0x00;
    m8 = 0x00;

    prime_1 = 0x0B; prime_2 = 0x00;
    A_1 = 0x02; A_2 = 0x00;
    B_1 = 0x03; B_2 = 0x00;
    Px_1 = 0x02; Px_2 = 0x00;
    Py_1 = 0x07; Py_2 = 0x00;
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
    *(addr_ecc+22) = go;

    // Exercise UART
    //*addr_uart = 0xEF;

    //byte_data = *addr_uart;

    //if (byte_data == 0xEF) {
    //    *addr_uart = 0xCD;
    //}
 
    done = 0x00;
    while (done != 0x01){
	done = *(addr_ecc+23);
    }

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
    return 0;
}

