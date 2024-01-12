module dmux
#(parameter WIDTH = 4)
(input in,
input [WIDTH-1:0] addr,
output reg [(1<<WIDTH)-1:0] out
);

always @*
begin
out = 0;
out[addr] = in;
end

endmodule
