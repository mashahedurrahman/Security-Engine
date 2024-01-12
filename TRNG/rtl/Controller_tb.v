
//`timescale	1ns/10ps


module tb_TRNG_Controller();
//parameter A= 3'b000,B=3'b001,C=3'b010, D=3'b011, E= 3'b100,F=3'b101,G=3'b110,H=3'b111, Address_Size=32,in_bus_size=16,number_of_addresses=64,out_bus_size=32;

	
	
	reg			TRNG_Go			;
	reg	[1:0]	Op_Type			;
	reg			clk				;
    reg			Resetn			;
	wire		TRNG_Done		;
	//Control Signals
	wire		mux1_sel		;
	wire		mux2_sel		;
	wire		Hash_Go			;
	reg			Hash_done		;
	wire		rst_reg_1		;
	wire		rst_reg_2		;
	wire		en_reg_1		;
	wire		en_reg_2		;
   
	
	





	
	TRNG_Controller UUT(
	.TRNG_Go(TRNG_Go),
	.Op_Type(Op_Type),
	.clk(clk),
	.Resetn(Resetn),
	.TRNG_Done(TRNG_Done),
	.mux1_sel(mux1_sel),
	.mux2_sel(mux2_sel),
	.Hash_Go(Hash_Go),
	.Hash_done(Hash_done),
	.rst_reg_1(rst_reg_1),
	.en_reg_1(en_reg_1),
	.rst_reg_2(rst_reg_2),
	.en_reg_2(en_reg_2)


);


	always
	begin
		#20 clk= !clk;
	end


	initial	begin
	
	
			clk=0;
			Resetn=0;	
			Hash_done=1;
			#40
			Resetn=1;
			Op_Type=2'b00;
			TRNG_Go=0;
			#40
			TRNG_Go=1;
			#40
			TRNG_Go=0;
			Hash_done=0;
			#40
			
			#40
			Hash_done=1;
			#40
			Hash_done=0;
			#40
			Op_Type=2'b11;
			#40
			TRNG_Go=1;
			#40
			TRNG_Go=0;
			#40	
			
			#40
			
			#40
			Hash_done=1;
			

			
				
			
			
			
			
	end
		

endmodule
