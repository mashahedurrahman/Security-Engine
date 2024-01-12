`timescale	1ns/10ps
module decoder_top#(
			  parameter OUTPUT_SIZE=256
			  

			)(
  input wire [0:263] i_Data,
  input wire [0:95] i_helper,
  input wire clk,
  input wire enable,
  input wire reset,
  output reg done,
  output reg [0:263] o_Data
  
   
	);
	
	
	reg [10:0]dec_dat;
	reg [3:0]dec_p;
	wire [0:10]dec_out;
	wire [0:14]dec_in;
	//integer i;
	reg[7:0]count,count1;
	
	decoder_ECC base(
	.c_h(dec_in),
	.data_out(dec_out),
	.enable(enable)
		
				);
				
				
	assign dec_in[0]=dec_p[0];
	assign dec_in[1]=dec_p[1];
	assign dec_in[2]=dec_dat[0];
	assign dec_in[3]=dec_dat[2];
	assign dec_in[4]=dec_dat[1];
	assign dec_in[5]=dec_dat[2];
	assign dec_in[6]=dec_dat[3];
	assign dec_in[7]=dec_p[3];
	assign dec_in[8]=dec_dat[4];
	assign dec_in[9]=dec_dat[5];
	assign dec_in[10]=dec_dat[6];
	assign dec_in[11]=dec_dat[7];
	assign dec_in[12]=dec_dat[8];
	assign dec_in[13]=dec_dat[9];
	assign dec_in[14]=dec_dat[10];
	
	always @(posedge clk)
	begin
	
		if(enable==1'b1)
		begin
		
			if(reset==1)
			begin
			count<=0;
			done<=0;
			//o_Data<=0;
			end
			else
			begin
			count<=count+1;
		
			end
			
			
		if(count1==24-1)
		begin
		done<=1;
		
		end
		if(count==24-1)
		begin
		count<=0;
		
		end
		
		
		end
		
		
		
	end
		
		
	always@(posedge clk)
	begin
		
		count1=count;
		if(done==0)
		begin
			dec_dat<=i_Data[(11*count1)+:11];
			dec_p<=i_helper[(4 *count1)+:4];
		end
	
	
	
	end	
		
		
	always@(negedge clk)
	begin
		
		
		if(done==0)
		begin
			o_Data[(11*count1)+:11]<= dec_out;
		end
	
	
	
	end
	
	
	
	
	
endmodule
