`timescale 100ns/1ns

module ECDSA_combined_tb;
 parameter period = 5; // Clock period
    int RAND_SEED = 42; // Hard coded seed for repeatibility
    localparam WIDTH = 32;
    localparam KEY_SIZE = 64;
    localparam INTEGER_SIZE = 64;
    
    // Inputs
    reg clk, rst, sign_go, verify_go, ecc_go;
    reg [WIDTH-1 : 0] message, hashedMessage, trng;
    reg [KEY_SIZE-1 : 0] privateKey;
    reg [INTEGER_SIZE-1 : 0] prime, A, B, Gx, Gy, Ox, Oy, n;

    // Outputs
    wire sign_ready, verify_ready, verified, failure, infiityPPubKey;
    wire ecc_done, sign_done, verify_done;
    wire [KEY_SIZE-1 : 0] r_sign, s_sign;
    reg [KEY_SIZE-1 : 0] verifying_r, verifying_s;
    
    ecdsa_combined #(
        .key_size(KEY_SIZE),
        .integer_size(INTEGER_SIZE),
        .message_width(WIDTH)
        ) ecdsa_combined_DUT (
        .clk(clk), 
        .rst(rst), 
        .ecc_go(ecc_go),
        .sign_go(sign_go),
        .verify_go(verify_go),
        .infiityPPubKey(infiityPPubKey),
        .message(message),
        .hashedMessage(hashedMessage),
        .trng(trng),
        .privateKey(privateKey),
        .prime(prime), 
        .A(A), 
        .B(B), 
        .Gx(Gx), 
        .Gy(Gy), 
        .Ox(Ox),
        .Oy(Oy),
        .n(n),
        .sign_ready(sign_ready),
        .verify_ready(verify_ready),
        .verified(verified),
        .failure(failure),
        .r_sign(r_sign),
        .s_sign(s_sign),
        .verifying_r(verifying_r),
        .verifying_s(verifying_s),
        .ecc_done(ecc_done),
        .sign_done(sign_done),
        .verify_done(verify_done)
       );
       
       reg sim_done;
       always
        #(period / 2) clk <= !clk & !sim_done;

        initial begin
            clk <= 1;
        sim_done <= 1'b0;
        rst <= 1;
        message <= 0;
        privateKey <= 0;
        prime <= 0;
        sign_go <= 0;
        verify_go <= 0;
        ecc_go <= 0;
        A <= 0;
        B <= 0;
        Gx <= 0;
        Gy <= 0;
        #period;
            rst <= 0;
            privateKey <= 3; /* Arbitrary prime less than 37 */
            prime <= 7;
            trng <= 3;
            ecc_go <= 1'b1;
            message <= 48;
            hashedMessage <= 1;
            A <= 0;
            B <= 5;
            n <= 7;
            Gx <= 3;
            Gy <= 2;
            wait(ecc_done == 1'b1);
            sign_go <= 1;
            wait(sign_done == 1'b1);
            #period;
            verifying_r <= r_sign;
            verifying_s <= s_sign;
            verify_go <= 1'b1;
            wait(verify_done == 1'b1);
            assert (verified == 1'b1) $display("Verified");
            else $error("Failed to verify valid signature");
            verify_go <= 1'b0;
            verifying_s <= 2;
            verifying_r <= 1;
            #period;
            wait(verify_ready == 1'b1);
            verify_go <= 1'b1;
            wait(verify_done == 1'b1);
            assert (verified == 1'b0) $display("Correctly caught invalid");
            else $error("Verified invalid signature");
            sim_done <= 1'b1;
            $stop;
        end

endmodule : ECDSA_combined_tb
