
int main(int argc, char const *argv[]) {
    volatile unsigned int *addr_generator_mult = (int*) 0xB2000000;
    volatile unsigned int *addr_test_response = (int*) 0xB2000004;
    volatile unsigned int *addr_KS_value = (int*) 0xB2000008;
    volatile unsigned int *addr_hsm_public_key = (int*) 0xB2000010;
    volatile unsigned int *addr_poca_start = (int*) 0xB2000200;

    volatile unsigned int *addr_poca_output_response = (int*) 0xB2000040;
    volatile unsigned int *addr_poca_done = (int*) 0xB2000100;
    int data;

    // Exercise POCA
    // Initialize DRAM
    *(addr_generator_mult) = 0x12345678;
    *(addr_test_response)  = 0x12345678;
    *(addr_KS_value)       = 0x5;
    *(addr_hsm_public_key+0) = 0x12345678;
    *(addr_hsm_public_key+1) = 0x0;
    *(addr_hsm_public_key+2) = 0x0;
    *(addr_hsm_public_key+3) = 0x0;
    *(addr_hsm_public_key+4) = 0x0;
    *(addr_hsm_public_key+5) = 0x0;
    *(addr_hsm_public_key+6) = 0x0;
    *(addr_hsm_public_key+7) = 0x0;

    // Clear done
    *(addr_poca_done)       = 0x0;

    // POCA start
    *(addr_poca_start)       = 0x1;

    // Check POCA_Done == 1
    do {
        data = *(addr_poca_done);
    } while (data != 0x1);

    // Read POCA output response
    for (int i = 0; i <= 24; i++) {
        data = *(addr_poca_output_response+i);
    }


    return 0;
}

