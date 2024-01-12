`timescale 1ns / 1ps






module tb_rsa_ip;

parameter [15:0] width  = 2048;

// Input/control of the IP 

reg clk, rst, go;

reg [(width-1):0] X, E, N;

// Outputs  of the IP

wire done;
wire [(width-1):0] O;

rsa_mont uut ( .clk(clk), .rst(rst), .go(go), .message_in(X),
				.exponent(E), .modulus(N), .cypher(O), .done(done));
				
always 
begin
		clk = 0;
		#5;
		clk = !clk;
		#5;
 	end
	
initial
		begin
		rst = 1;
                go = 0;
		#50
		rst = 0;
		X= 8;
		E= 13;
		N= 77;
		go= 1;
		
		#10
		go = 0;
		
		wait (done ==1'b1);
		
		$display("Current output:\n%b \nCurrent Key:\n%b", O[127:0], E[63:0]);
		
		X= O;
		E= 37;
		N= 77;
		
		#50
		
		go= 1;		
		
		#10
		go = 0; 
		
		
		
		wait (done ==1'b1);
		
		$display("Current output:\n%b \nCurrent Key:\n%b", O[127:0], E[63:0]);
		
		if (O== 8)
		
		$display("Output matches original message"); 
		
		else
		
		$display("Key/output mismatch !!!"); 

		
		X= 25;
		E= 7;
		N= 143;
		
		#50
		
		go= 1;		
		
		#10
		go = 0; 

		
		wait (done ==1'b1);
		$display("Current output:\n%b \nCurrent Key:\n%b", O[127:0], E[63:0]);
		
		X= O;
		E= 103;
		N= 143;
		
		#50
		
		go= 1;		
		
		#10
		go = 0; 
		
		wait (done ==1'b1);
		$display("Current output:\n%b \nCurrent Key:\n%b", O[127:0], E[63:0]);
		
		if (O== 25)
		
		$display("Output matches original message"); 
		
		else
		
		$display("Key/output mismatch !!!"); 
		
		$finish;
		
		end

   initial begin
      $dumpfile("dump.vcd");
      $dumpvars;
   end
		
		endmodule
		
