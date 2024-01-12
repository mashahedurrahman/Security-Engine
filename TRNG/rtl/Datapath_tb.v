


module tb_Datapath();
//parameter A= 3'b000,B=3'b001,C=3'b010, D=3'b011, E= 3'b100,F=3'b101,G=3'b110,H=3'b111, Address_Size=32,in_bus_size=16,number_of_addresses=64,out_bus_size=32;

	reg clk;
   
	reg Resetn;
   
	reg [511:0] data_in;
	wire [255:0]data_out;
	
	//Mux Select
	reg mux1_sel;
	reg mux2_sel;
	//SHA Control
	reg Hash_Go;
	wire Hash_done; 
	//Reg Control
	reg rst_reg_1;
	reg en_reg_1;
	reg rst_reg_2;
	reg en_reg_2;




	
	Data_Path UUT(

	.clk(clk),
	.Resetn(Resetn),
	.data_in(data_in),
	.data_out(data_out),
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
			rst_reg_1=0;
			rst_reg_2=0;
			en_reg_1=0;
			en_reg_2=0;
			mux2_sel=0;
			#40
			Resetn=1;
			data_in=24324253;
			Hash_Go=0;
			#40
			mux1_sel=0;
			Hash_Go=1;
			#40
			Hash_Go=0;
			#40	

			while(Hash_done==0)
				begin
			
			     Hash_Go=0;
				#20;
				
				end			
			en_reg_1=1;
			#40
			en_reg_2=1;
			mux1_sel=0;
			#40
			data_in=455686;
			en_reg_1=0;
			en_reg_2=0;
			#40
			Hash_Go=1;
			#40
			Hash_Go=0;
			#40	
			while(Hash_done==0)
				begin
			
			     Hash_Go=0;
				#20;
				
				end			
			en_reg_1=1;
			#40
			mux1_sel=1;
			#40
			Hash_Go=1;
			#40
			Hash_Go=0;
			#40	
			while(Hash_done==0)
				begin
			
			     Hash_Go=0;
				#20;
				
				end		
				
			en_reg_1=1;
			

			
				
			
			
			
			
	end
		

endmodule
