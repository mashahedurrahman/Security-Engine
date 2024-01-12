
//`timescale	1ns/10ps


module tb_TRNG_Top_128();
//parameter A= 3'b000,B=3'b001,C=3'b010, D=3'b011, E= 3'b100,F=3'b101,G=3'b110,H=3'b111, Address_Size=32,in_bus_size=16,number_of_addresses=64,out_bus_size=32;

	
	
	reg			TRNG_Go			;
	reg	[1:0]	Op_Type			;
	reg			clk				;
    reg			Resetn			;
	wire		TRNG_Done		;
	reg [511:0] data_in;
	wire [127:0]data_out;
	
	
	
   
	
	





	
	TRNG_Top_128 UUT(
	.TRNG_Go(TRNG_Go),
	.Op_Type(Op_Type),
	.clk(clk),
	.Resetn(Resetn),
	.TRNG_Done(TRNG_Done),
	.data_in(data_in),
	.data_out(data_out)


);


	always
	begin
		#20 clk= !clk;
	end


	initial	begin
	
	
			clk=0;
			Resetn=0;	
			
			#40
			Resetn=1;
			Op_Type=2'b00;
			TRNG_Go=0;
			data_in=1452664;
			#40
			TRNG_Go=1;
			$display("\nSRAM Data in %b",data_in);
			#40
			TRNG_Go=0;
						
			#40
			while(TRNG_Done==0)
				begin
			
			     TRNG_Go=0;
				#20;
				
				end	
				
			
			#80
			$display("\nTRNG Output %h",data_out);
			
			Op_Type=2'b10;
			#40
			TRNG_Go=1;
			data_in=323464;
			$display("\nSRAM Data in %b",data_in);
			#40
			TRNG_Go=0;
			while(TRNG_Done==0)
				begin
			
			     TRNG_Go=0;
				#20;
				
				end	
			
			
			#80
			$display("\nTRNG Output %h",data_out);
			
			Op_Type=2'b11;
			#40
			TRNG_Go=1;
			data_in=0;
			$display("\nSRAM Data in %b",data_in);
			#40
			TRNG_Go=0;
			while(TRNG_Done==0)
				begin
			
			     TRNG_Go=0;
				#20;
				
				end	
			
			
			#80
			$display("\nTRNG Output %h",data_out);
			Op_Type=2'b11;
			

                        #100;
		        $finish;	
				
			
			
			
			
	end

   initial begin
       $dumpfile("dump.vcd");
       $dumpvars;
   end
		

endmodule

