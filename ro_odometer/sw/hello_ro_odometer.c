
int main(int argc, char const *argv[]) {
    volatile unsigned int *addr_ro_odometer = (int*) 0x60000000;
    int data;

    // Exercise RO_ODOMETER

    // RO_ODOMETER_Go=0;
    *(addr_ro_odometer+0) = 0;
    *(addr_ro_odometer+2) = 2;
    *(addr_ro_odometer+3) = 6;

    // RO_ODOMETER_Go=1;
    *(addr_ro_odometer+0) = 1;
    // RO_ODOMETER_Go=0;
    *(addr_ro_odometer+0) = 0;
    // RO_ODOMETER_en_out=1;
    *(addr_ro_odometer+1) = 1;
    // RO_ODOMETER_en_out=0;
    *(addr_ro_odometer+1) = 0;

    // Check Valid_out == 1
    do {
     data = *(addr_ro_odometer+6);
    } while (data != 1);

    // Read output
    for (int i = 4; i <= 5; i++) {
        data = *(addr_ro_odometer+i);
    }

    return 0;
}

