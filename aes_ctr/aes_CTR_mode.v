//Pipelined 128-bit key AES CTR mode using https://opencores.org/projects/tiny_aes
module aes_CTR_mode #(
			parameter keylen = 128,
                        parameter done_counter_val = 83
	)
	(
		input clk, encNotDec,
		input rst,
		input [keylen-1:0] key, messageIn, cipherIn,
		input [(keylen/2)-1:0] nonce, counterIn,
		output reg done_message, done_cipher,
		output reg [keylen-1:0] messageOutReg, cipherOutReg
	);

	reg [keylen-1:0] messageOut, cipherOut;
	reg  [(keylen/2)-1:0] counter;
        reg old_done_cipher, old_done_message; 
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
			messageOutReg = 0;
			cipherOutReg = 0;
			old_done_cipher = 0;
			old_done_message = 0;
			done_message = 0;
			done_cipher = 0;
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
                                if ((counter-counterIn) == done_counter_val) begin
					done_cipher = 1;
					if (done_cipher == 1 && old_done_cipher == 0) begin 
						cipherOutReg = cipherOut;
					end
				end
			end
			else begin
				messageOut = blockOutput ^ cipherIn;
                                if ((counter-counterIn) == done_counter_val) begin
					done_message = 1; 
					if (done_message == 1 && old_done_message == 0) begin 
						messageOutReg = messageOut;
					end
				end
			end
			
			old_done_cipher = done_cipher; 
			old_done_message = done_message; 
		end
	end


endmodule
