module ecdsa_combined #(		
		parameter message_width = 512,
		parameter key_size = 256,
		parameter integer_size = 64
	)
	(
		input wire clk, rst, ecc_go, sign_go, verify_go, 
		input wire[message_width-1 : 0] message, hashedMessage, trng, 
		output sign_ready, verify_ready, verified, failure, infiityPPubKey,
		output ecc_done, sign_done, verify_done, 
                output wire [key_size-1:0] r_sign, s_sign,
		input wire [integer_size-1:0] prime, A, B, Gx, Gy, n, Ox,Oy,
		input wire [key_size-1:0] verifying_r, verifying_s, privateKey
    );
        wire [key_size-1:0] Qx, Qy;
        
        montgomeryLadder #(
        .key_size(key_size),
        .integer_size(integer_size)
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
        .message_width(message_width),
        .key_size(key_size),
        .integer_size(integer_size)
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
        .message_width(message_width),
        .key_size(key_size),
        .integer_size(integer_size)
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
endmodule
