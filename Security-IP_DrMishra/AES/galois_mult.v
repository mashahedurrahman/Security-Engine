module galois_mult #(
      parameter width = 128
    , parameter reversed = 0
)
(
      input [width-1 : 0] x, y
    , output reg [width-1 : 0] z
);

    reg [width-1 : 0] x_rev, y_rev, v;

    // Magic constant for the GF(2^128) field
    // localparam R = 128'hE100_0000_0000_0000_0000_0000_0000_0000;
    localparam R = 128'h8700_0000_0000_0000_0000_0000_0000_0000;
    integer i;

    always @(x, y) begin
        // Reverse X and Y with streaming operator
        if (reversed) begin
            x_rev = {<<{x}};
            y_rev = {<<{y}};
        end
        else begin
            x_rev = x;
            y_rev = y;
        end

        v = y_rev;
        z = 0;

        // Galois multiplication is defined as carry-less multiplication        
        for (i = 1; i <= width; i = i + 1) begin
            if (x_rev[width - i] == 1) begin
                z = z ^ v; // Addition is XOR in galois field
            end

            // Perform the shifts for each multiplication
            if (v[0] == 0) begin
                v = v >> 1;
            end
            else begin
                v = (v >> 1) ^ R; // Funky modulo stuff from Mr. Galois himself
            end
        end

        if (reversed)
            z = {<<{z}}; // Reverse Z with the streaming operator
    end
endmodule
