 //Developed by Jennifer Sheldon, Andrew Whigham, Daniel Volya, and Dr. Prabhat Mishra at the University of Florida.
`timescale 100ns/1ns

module ECDSA_full_tb;
 parameter period = 5; // Clock period
    int RAND_SEED = 88; // Hard coded seed for repeatibility
    localparam NUM_VECTORS = 64;
    localparam WIDTH = 32;
    localparam KEY_SIZE = 64;
    localparam INTEGER_SIZE = 64;

    integer errorCount = 0;
    integer correctCount = 0;

    // Inputs
    reg clk, rst, sign_go, verify_go, ecc_go, ecc_done, originGen_go, originGen_done;
    reg sim_done;
    reg [WIDTH-1 : 0] message, hashedMessage, trng;
    reg [KEY_SIZE-1 : 0] privateKey;
    reg [INTEGER_SIZE-1 : 0] prime, A, B, Gx, Gy, Ox, Oy, n, Qx, Qy;

    // Outputs
    wire sign_ready, verify_ready, verified, failure, infiityPPubKey;
    wire sign_done, verify_done;
    wire [KEY_SIZE-1 : 0] r_sign, s_sign;
    reg [KEY_SIZE-1 : 0] verifying_r, verifying_s;

    montgomeryLadder #(
        .key_size(KEY_SIZE),
        .integer_size(INTEGER_SIZE)
        ) publicKeyGen (
        .m(privateKey), 
        .clk(clk), 
        .rst(rst), 
        .go(ecc_go),
        .infinityP(infiityPPubKey), //Why pass point at infinity here? 
        .done(ecc_done),
        .prime(prime), 
        .A(A), 
        .B(B), 
        .Px(Gx), 
        .Py(Gy), 
        .mGx(Qx),
        .mGy(Qy)
    );


    ECDSA_sign #(
        .message_width(WIDTH),
        .key_size(KEY_SIZE),
        .integer_size(INTEGER_SIZE)
        ) DUT_sign (
        .clk(clk),
        .rst(rst),
        .go(sign_go),
        .hash(hashedMessage),
        .trng_value(trng),
        .message(message),
        .ready(sign_ready),
        .n(prime),
        .done(sign_done),
        .privateKey(privateKey),
        .failure(failure),
        .prime(prime),
        .A(A),
        .B(B),
        .Gx(Gx),
        .Gy(Gy),
        .Ox(Ox),
        .Oy(Oy),
        .r(r_sign),
        .s(s_sign)
        );

        ECDSA_verify #(
        .message_width(WIDTH),
        .key_size(KEY_SIZE),
        .integer_size(INTEGER_SIZE)
        ) DUT_verify (
        .clk(clk),
        .rst(rst),
        .go(verify_go),
        .hashedMessage(hashedMessage),
        .verified(verified),
        .trng_value(trng),
        .message(message),
        .ready(verify_ready),
        .done(verify_done),
        .private_key(privateKey),
        .n(prime),
        .prime(prime),
        .A(A),
        .B(B),
        .Gx(Gx),
        .Gy(Gy),
        .Qx(Qx),
        .Qy(Qy),
        .Ox(Ox),
        .Oy(Oy),
        .r(verifying_r),
        .s(verifying_s)
        );

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
        originGen_go <= 0;
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
    endmodule : ECDSA_full_tb