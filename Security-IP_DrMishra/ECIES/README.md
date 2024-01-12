ECC-based encryption and decryption scheme.

Uses the files found in the ECCShared directory.

ANSIX963KDF implements the ANSI KDF for ECIES.

Here are the default widths and descriptions to use for the given modules when interfacing:

    message_width = 32, this is the message width. Other seen implementations appear to use varied message width. The used reference
    (https://www.secg.org/sec1-v2.pdf) does not appear to explicitly define a width.
    key_size = 128, this is the key width for ECC (Elliptic Curve Cryptography) private/public key pairs, may become bigger part of
    interfacing if ECC Montgomery Ladder moves onto bus.
    mac_key_length = 256, this is the key size for SHA HMAC taken from among key sizes requested.
    dec_key_len = 128, this is the key size for AES CTR mode encryption.
    enc_key_len = 128, same as above but for decryption.
    hashed_width = 512, this is the return width from the SHA hash module. It is taken from the toplevel IP from the given SHA module.
    integer_size = 64, this is mostly used for ECC curve parameter widths.
    AES_PIPELINE_DELAY, this is the clock cycle delay on the AES pipeline.

Some Initial Questions:

Do the IPs themselves handle ready signals, or is this done by wrappers?
If a module makes a request for a SHA hash and the input is not 1024 bits (data_in width in top module) who pads the request?

