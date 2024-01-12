//Based on KDF specification in : https://www.secg.org/sec1-v2.pdf
module ANSIX963KDF #(parameter zSize = 128, parameter key_byte_number = 32, parameter hash_size = 160)(
	input wire clk, rst, go, hashDone, hashReady, 
	input wire [hash_size-1:0] hashedOut,
	input wire [zSize-1:0] z,
	output reg [8*key_byte_number-1:0] outputValue,
	output reg done, valid, hashGo,
	output wire [zSize+16-1:0] hashedVal
	);
//20 from SHA implementation (160/8).
localparam iMax = $ceil((key_byte_number)/20);
localparam WAIT = 0, LOAD = 1, CHECKVALUES = 2, INITCTR = 3, HASH = 4, DONEOUT = 5;
localparam outputSize = 8*key_byte_number;
//16 given as constant here.
reg [15:0] counter;
reg[2:0] state;
reg [8*key_byte_number-1:0] finalOutIntermed;
integer i;
reg valid_intermed;
assign hashedVal = {z,counter};

always @(posedge clk)
begin: STATE_FUNCTIONS
	done <= 1'b0;
	valid_intermed <= valid_intermed;
	finalOutIntermed <= finalOutIntermed;
	outputValue <= 0;
	state <= state;
	valid <= 1'b0;
	i <= 1;
	hashGo <= 1'b0;
	case(state)
		WAIT: begin
			done <= 1'b0;
			valid <= 1'b0;
			outputValue <= 0;
			valid_intermed <= 0;
			finalOutIntermed <= 0;
			if(go == 1'b1) begin
				state <= CHECKVALUES;
			end
		end
		CHECKVALUES: begin
			//Constants inserted are based on byte size and specifics of hash implementation used.
			state <= INITCTR;
			if(zSize/8 + 4 >= 512/8) begin
				//$display("invalid input " , sharedInfoLen/8 + zSize/8 + 4 >= 512/8 , " ", key_byte_number >= 20*((2**32)-1), " ", key_byte_number, " ", ((2**32)-1));
				//Do not set valid here.
				state <= DONEOUT;
			end
		end
		INITCTR: begin
			counter <= 16'b1;
			state <= HASH;
		end
		HASH: begin
			if(i <= iMax) begin
				if(hashDone == 1'b1) begin
					finalOutIntermed <= {finalOutIntermed , (hashedOut >> (i-1))};
					counter <= counter + 1;
					i <= i + 1;
				end
				else if(hashReady == 1'b1) begin
					hashGo <= 1'b1;
				end
			end
			else begin
				valid_intermed <= 1'b1;
				state <= DONEOUT;
			end
		end
		DONEOUT: begin
			done <= 1'b1;
			valid <= valid_intermed;
			outputValue <= finalOutIntermed;
			if(go == 1'b0) begin
				state <= WAIT;
			end
		end
	endcase
	if(rst == 1'b1) begin
		state <= WAIT;
	end
end
endmodule
