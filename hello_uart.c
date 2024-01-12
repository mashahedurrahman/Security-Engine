int main(int argc, char const *argv[]) {
    volatile unsigned char *addr_uart = (char*) 0x1000000C;
    char byte_data;

    // Exercise UART
    *addr_uart = 0xEF;

    byte_data = *addr_uart;

    if (byte_data == 0xEF) {
        *addr_uart = 0xCD;
    }

    return 0;
}

