//`timescale	1ns/10ps
module tb_mux();

reg sel;
reg [20:0] a;
reg [20:0] b;
wire [20:0] z;

mux #(21) UUT(
.sel(sel),
.a(a),
.b(b),
.z(z)


);

initial begin
sel=0;
a=12;
b=34;
#40
sel=1;


end





endmodule
