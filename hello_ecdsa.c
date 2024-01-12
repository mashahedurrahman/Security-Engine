int main(int argc, char const *argv[]) {
    volatile unsigned int *addr_ecdsa = (int*) 0x47000000;
    int data;
    int done, ready;
    int m1, m2, m3, m4, m5, m6, m7, m8;
    int prime_1, prime_2, A_1, A_2, B_1, B_2, Gx_1, Gx_2, Gy_1, Gy_2, Ox_1, Ox_2, Oy_1, Oy_2;
    int ecc_go, ecc_done, sign_ready, sign_go, sign_done, verify_ready, verify_go, verify_done, infinityP;


    // Sending input data to ECDSA IP
    *(addr_ecdsa+107) = 0x03;
    *(addr_ecdsa+59) = 0x07;
    *(addr_ecdsa+35) = 0x03;
    *(addr_ecdsa+3) = 0x30;
    *(addr_ecdsa+19) = 0x01;
    *(addr_ecdsa+61) = 0x00;
    *(addr_ecdsa+63) = 0x05;
    *(addr_ecdsa+69) = 0x07;
    *(addr_ecdsa+65) = 0x03;
    *(addr_ecdsa+67) = 0x02;
    *(addr_ecdsa+0) = 0x01;

    ecc_done = 0x00;
    while (ecc_done != 0x01){
	ecc_done = *(addr_ecdsa+56);
    }

    *(addr_ecdsa+1) = 0x01;

    sign_done = 0x00;
    while (sign_done == 0x00){
	sign_done = *(addr_ecdsa+57);
    }
    
    data = *(addr_ecdsa+75);
    *(addr_ecdsa+91) = data;
    data = *(addr_ecdsa+76);
    *(addr_ecdsa+92) = data;
    data = *(addr_ecdsa+77);
    *(addr_ecdsa+93) = data;
    data = *(addr_ecdsa+78);
    *(addr_ecdsa+94) = data;
    data = *(addr_ecdsa+79);
    *(addr_ecdsa+95) = data;
    data = *(addr_ecdsa+80);
    *(addr_ecdsa+96) = data;
    data = *(addr_ecdsa+81);
    *(addr_ecdsa+97) = data;
    data = *(addr_ecdsa+82);
    *(addr_ecdsa+98) = data;

    data = *(addr_ecdsa+83);
    *(addr_ecdsa+99) = data;
    data = *(addr_ecdsa+84);
    *(addr_ecdsa+100) = data;
    data = *(addr_ecdsa+85);
    *(addr_ecdsa+101) = data;
    data = *(addr_ecdsa+86);
    *(addr_ecdsa+102) = data;
    data = *(addr_ecdsa+87);
    *(addr_ecdsa+103) = data;
    data = *(addr_ecdsa+88);
    *(addr_ecdsa+104) = data;
    data = *(addr_ecdsa+89);
    *(addr_ecdsa+105) = data;
    data = *(addr_ecdsa+90);
    *(addr_ecdsa+106) = data;

    *(addr_ecdsa+2) = 0x01;
    done = 0x00;
    while (done != 0x01){
	done = *(addr_ecdsa+58);
    }
    *(addr_ecdsa+2) = 0x00;
    *(addr_ecdsa+99) = 0x02;
    *(addr_ecdsa+100) = 0x00;
    *(addr_ecdsa+101) = 0x00;
    *(addr_ecdsa+102) = 0x00;
    *(addr_ecdsa+103) = 0x00;
    *(addr_ecdsa+104) = 0x00;
    *(addr_ecdsa+105) = 0x00;
    *(addr_ecdsa+106) = 0x00;

    *(addr_ecdsa+91) = 0x01;
    *(addr_ecdsa+92) = 0x00;
    *(addr_ecdsa+93) = 0x00;
    *(addr_ecdsa+94) = 0x00;
    *(addr_ecdsa+95) = 0x00;
    *(addr_ecdsa+96) = 0x00;
    *(addr_ecdsa+97) = 0x00;
    *(addr_ecdsa+98) = 0x00;

    ready = 0x00;
    while (ready != 0x01){
	ready = *(addr_ecdsa+52);
    }
    *(addr_ecdsa+2) = 0x01;
    done = 0x00;
    while (done != 0x01){
	done = *(addr_ecdsa+58);
    }
    return 0;
}

