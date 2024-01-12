//Pipelined 128-bit key AES CTR mode using https://opencores.org/projects/tiny_aes
module aes_CTR_mode #(
			parameter keylen = 128
	)
	(
		input clk, encNotDec,
		input rst,
		input [keylen-1:0] key, messageIn, cipherIn,
		input [(keylen/2)-1:0] nonce, counterIn,
		output reg [keylen-1:0] messageOut, cipherOut
	);

	reg  [(keylen/2)-1:0] counter; 
	reg  [keylen-1:0] messageInReg, cipherInReg;
	wire [keylen-1:0] blockInput, blockOutput;
	wire encrypterClock;

	assign encrypterClock = clk & !rst;
	assign blockInput = {nonce, counter};

	aes_128 encrypter(
		.clk(encrypterClock),
		.state(blockInput),
		.key(key),
		.out(blockOutput)
		);

	always @(posedge clk)
	begin
		if(rst == 1'b1) begin
			counter = counterIn;
			messageOut = 0;
			cipherOut = 0;
		end
	end

	always @(negedge clk)
	begin
		if (rst == 1'b0) begin
			counter = counter + 1;
		end
	end

	always @(posedge clk)
	begin
		if (rst == 1'b0) begin
			if(encNotDec == 1'b1) begin
				cipherOut = blockOutput ^ messageIn;
			end
			else begin
				messageOut = blockOutput ^ cipherIn;
			end
		end
	end


endmodule
