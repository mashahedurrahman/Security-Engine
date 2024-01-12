
int main(int argc, char const *argv[]) {
    volatile unsigned int *addr_PUF = (int*) 0x41000000;
    int data;

    // Exercise PUF
    // Op_Type=2'b00;
    *(addr_PUF+1) = 0;

    // PUF_Go=0;
    *(addr_PUF+0) = 0;

    //Challenge_Seed=142
     *(addr_PUF+2) = 142;
   
    //helper_bit
    *(addr_PUF+3) = 2463535830;
    *(addr_PUF+4) = 2463535830;
    *(addr_PUF+5) = 2463535830;


    // data_in=1452664;
    *(addr_PUF+6) = 1452664;
    for (int i = 7; i <= 13; i++) {
        *(addr_PUF+i) = 1234567;
    }

    // PUF_Go=1
 //  int a = *(addr_PUF+22); 
 //  if ( a==0 ) 
     *(addr_PUF+0) = 1;
//   else 
    // PUF_Go=0;
     *(addr_PUF+0) = 0;


    // Check PUF_Done == 1
    do {
        data = *(addr_PUF+22);
    } while (data != 1);

    // Read output
    for (int i = 14; i <= 21; i++) {
        data = *(addr_PUF+i);
    }

    return 0;
}


