//Developed by Jennifer Sheldon, Andrew Whigham, Daniel Volya, and Dr. Prabhat Mishra at the University of Florida.
//Need FSM for variable m because cannot unroll unknown m in parameter.
//NOTE:RESET AND GO ARE SYNCHRONOUS
module montgomeryLadder #(parameter key_size = 256, parameter integer_size = 64) (input wire [key_size - 1:0] m, input wire clk, rst, go, output reg done, infinityP, input wire [integer_size-1:0] prime, A, B, Px, Py, Ox, Oy, output reg [key_size-1:0] mGx, mGy);
	localparam WAIT = 0, LOADINITIALS = 1, CHECKI = 2, R0SETUP = 3, I0 = 4, I1 = 5, FAKERUN = 6, DONEOUT = 7;
	reg [2:0] state;
	wire internalDoneDouble0, internalDoneDouble1, internalDoneAdd, doneFull, infiniteDoubleR0, infiniteDoubleR1, infiniteR0R1, mregCheck;
	reg internalGoAdd, internalGoDouble0, internalGoDouble1, hit1, infiniteR0, infiniteR1;
	integer i;
	reg [key_size-1:0] m_reg;
	reg [integer_size-1:0] prime_reg, A_reg, B_reg, Gx_reg, Gy_reg, R0x, R0y, R1x, R1y, Px_reg, Py_reg, Ox_reg, Oy_reg;
	wire [integer_size-1:0] get2R0x, get2R1x, get2R0y, get2R1y, getR0R1x, getR0R1y;
	get_2P #(.integer_size(integer_size)) twoPR0version(.prime(prime_reg), .A(A_reg), .B(B_reg), .Px(R0x), .Py(R0y), .doublePx(get2R0x), .doublePy(get2R0y), .clk(clk), .rst(rst), .go(internalGoDouble0), .done(internalDoneDouble0), .infiniteP(infiniteR0), .infiniteDoubleP(infiniteDoubleR0));
	get_2P #(.integer_size(integer_size)) twoPR1version(.prime(prime_reg), .A(A_reg), .B(B_reg), .Px(R1x), .Py(R1y), .doublePx(get2R1x), .doublePy(get2R1y), .clk(clk), .rst(rst), .go(internalGoDouble1), .done(internalDoneDouble1), .infiniteP(infiniteR1), .infiniteDoubleP(infiniteDoubleR1));
	get_PQ #(.integer_size(integer_size)) R0R1version(.prime(prime_reg), .A(A_reg), .B(B_reg), .Px(R0x), .Py(R0y), .Qx(R1x), .Qy(R1y), .PQx(getR0R1x), .PQy(getR0R1y), .clk(clk), .rst(rst), .go(internalGoAdd), .done(internalDoneAdd), .infiniteQ(infiniteR1), .infiniteP(infiniteR0), .infinitePQ(infiniteR0R1));
	//Both need to finish before moving on. And Go signal in so that dones do not overlap.
	assign doneFull = ((internalDoneDouble0 & internalGoDouble0) | (internalDoneDouble1 & internalGoDouble1))  & (internalDoneAdd & internalGoAdd);
	//FSM
	assign mregCheck = m_reg[i];
	always @ (posedge clk)
	begin : STATE_FUNCTIONS
		done <= 1'b0;
		state <= state;
		prime_reg <= prime_reg;
		A_reg <= A_reg;
		B_reg <= B_reg;
		//$display("***MONTGOMERY***");
		m_reg <= m_reg;
		mGx <= 0;
		mGy <= 0;
		Px_reg <= Px_reg;
		Py_reg <= Py_reg;
		Ox_reg <= Ox_reg;
		Oy_reg <= Oy_reg;
		R0x <= R0x;
		R0y <= R0y;
		R1x <= R1x;
		R1y <= R1y;
		internalGoAdd <= internalGoAdd;
		internalGoDouble0 <= internalGoDouble0;
		internalGoDouble1 <= internalGoDouble1;
		hit1 <= hit1;
		i <= i;
		infiniteR0 <= infiniteR0;
		infiniteR1 <= infiniteR1;
		infinityP <= infinityP;
		case(state)
			WAIT: begin
				done <= 1'b0;
				i <= 0;
				R0x <= 0;
				R0y <= 0;
				R1x <= 0;
				R1y <= 0;
				infiniteR0 <= 1'b0;
				infiniteR1 <= 1'b0;
				hit1 <= 1'b0;
				internalGoAdd <= 1'b0;
				internalGoDouble0 <= 1'b0;
				internalGoDouble1 <= 1'b0;
				infinityP <= 1'b0;
				infiniteR0 <= 1'b0;
				infiniteR1 <= 1'b0;
				if(go == 1'b1) begin
					//Taking one input checking for point at infinity.
					state <= LOADINITIALS;
				end
			end
			LOADINITIALS: begin
				i <= key_size-1;
				prime_reg <= prime;
				A_reg <= A;
				B_reg <= B;
				m_reg <= m;
				Px_reg <= Px;
				Py_reg <= Py;
				Ox_reg <= Ox;
				Oy_reg <= Oy;
					//Is this the right thing to load here?
					R0x <= Px;
					R0y <= Py;
					R1x <= 0;
					R1y <= 0;
					//Get 2P for R1.
					internalGoDouble0 <= 1'b1;
					state <= R0SETUP;
				end
				R0SETUP: begin
					if(internalDoneDouble0 == 1'b1) begin
						internalGoDouble0 <= 1'b0;
						R1x <=  get2R0x;
						R1y <= get2R0y;
						infiniteR1 <= infiniteDoubleR0;
						state <= CHECKI;
					end
				end
				CHECKI: begin
					//$display("R0x: ", R0x, " R0y: ", R0y, " R1x", R1x, " R1y", R1y);
					//$display("Signed ", $signed(i) < 0, " ",$signed(i), " ", (i >= 0 && m_reg[i] == 1 && hit1 != 1'b0));
					if(i >= 0 && m_reg[i] == 1 && hit1 != 1'b1) begin
						hit1 <= 1'b1;
						//$display("in the hit");
						i <= i-1;
					end
					else begin
						//$display("in the outer");
						i <= i-1;
						if(hit1 == 1'b1)
						begin
							if (m_reg[i] == 0) begin
								internalGoAdd <= 1'b1;
								internalGoDouble0 <= 1'b1;
								state <= I0;
							//$display("zero value");
						end
						else begin
							internalGoAdd <= 1'b1;
							internalGoDouble1 <= 1'b1;
							state <= I1;
							//$display("one value");
						end
						//$display("countDown");
					end
					if ($signed(i) < 0) begin
						//done <= 1'b1;
						mGx <= R0x;
						mGy <= R0y;
						state <= DONEOUT;
					end
				end
			end
			FAKERUN: begin
				if(doneFull == 1'b1) begin
					internalGoAdd <= 1'b0;
					internalGoDouble1 <= 1'b0;
					state <= CHECKI;
				end
			end
			I0 : begin
				if(doneFull == 1'b1) begin
					//$display("Ran I0", $time);
					R1x <= getR0R1x;
					R1y <= getR0R1y;
					R0x <= get2R0x;
					R0y <= get2R0y;
					infiniteR0 <= infiniteDoubleR0;
					infiniteR1 <= infiniteR0R1;
					internalGoAdd <= 1'b0;
					internalGoDouble0 <= 1'b0;
					state <= CHECKI;
				end
			end
			I1 : begin
				if(doneFull == 1'b1) begin
					//$display("Ran I1", $time);
					R0x <= getR0R1x;
					R0y <= getR0R1y;
					R1x <= get2R1x;
					R1y <= get2R1y;
					infiniteR0 <= infiniteR0R1;
					infiniteR1 <= infiniteDoubleR0;
					internalGoAdd <= 1'b0;
					internalGoDouble1 <= 1'b0;
					state <= CHECKI;
				end
			end
			DONEOUT: begin
					//$display("FINAL: R0x: ", R0x, " R0y: ", R0y, " R1x", R1x, " R1y", R1y);
					//$display("i is ", i);
					done <= 1'b1;
					if(m_reg % prime_reg == 0) begin
						infinityP <= 1'b1;
					end
					if(m_reg > 1) begin
						mGx <= R0x;
						mGy <= R0y;
					end
					else begin
						mGx <= Px_reg;
						mGy <= Py_reg;
					end
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