LIBRARY IEEE;
use IEEE.std_logic_1164.all;
use IEEE.numeric_std.all;
use IEEE.std_logic_unsigned.all;

entity controller512 is
port(
	clk : in std_logic;
	rst : in std_logic;
	go : in std_logic;
	data_in : in std_logic_vector(2047 downto 0);
	data : out std_logic_vector(31 downto 0);
	done_SHA : in std_logic;
	cmd_i : out std_logic_vector(3 downto 0);
	cmd_w_i : out std_logic;
	cmd_o : in std_logic_vector(4 downto 0);
	done : out std_logic
);
end controller512;

architecture BHV of controller512 is
	type STATE_TYPE is (WAIT_FOR_GO, SHA_1, SHA_READ_1, SHA_WAIT1, SHA_SET1, SHA_READ_2, SHA_WAIT2, SHA_SET2, S_DONE);
	signal state : STATE_TYPE;
	type data_array is array(63 downto 0) of std_logic_vector(31 downto 0);
	signal arr : data_array;
	signal count : std_logic_vector(5 downto 0) := "000000";
begin
	process(clk, rst)

	begin
		if(rst = '1') then	
			state <= WAIT_FOR_GO;
		elsif(rising_edge(clk)) then
			cmd_w_i <= '0';
			done <= '0';
			case state is
				when WAIT_FOR_GO =>
					if(go = '1') then
						state <= SHA_1;
						for i in 0 to 63 loop
								arr(i) <= data_in(((i+1)*32)-1 downto i*32);
						end loop;
					else
						state <= WAIT_FOR_GO;
					end if;
				when SHA_1 =>
					cmd_w_i <= '1';
					cmd_i <= "1010";
					state <= SHA_READ_1;
				when SHA_READ_1 =>
						data <= arr(63);
						for i in 1 to 63 loop
							arr(i) <= arr(i-1);
						end loop;
						arr(0) <= (others => '0');
						count <= count + 1;
						if(unsigned(count) = 31) then 
							state <= SHA_WAIT1;
						else
							state <= SHA_READ_1;
						end if;
				WHEN SHA_WAIT1 =>
					if(cmd_o(4) = '1') then
						state <= SHA_WAIT1;
					else 
						state <= SHA_SET1;
					end if;
				when SHA_SET1 =>
					cmd_i <= "1110";
					cmd_w_i <= '1';
					state <= SHA_READ_2;
				when SHA_READ_2 =>
					data <= arr(63);
						for i in 1 to 63 loop
							arr(i) <= arr(i-1);
						end loop;
						arr(0) <= (others => '0');
						count <= count + 1;
					if(unsigned(count) = 31) then
						state <= SHA_WAIT2;
					else	
						state <= SHA_READ_2;
					end if;
				when SHA_WAIT2 =>
					if(cmd_o(4) = '1') then
						state <= SHA_WAIT2;
					else 
						state <= SHA_SET2;
					end if;
				when SHA_SET2 =>
					cmd_i <= "1001";
					cmd_w_i <= '1';
					if(done_SHA = '1') then
						state <= S_DONE;
					end if;
				when S_DONE =>
					done <= '1';
					if(go = '0') then
						state <= WAIT_FOR_GO;
					end if;
				when others => null;
					
			end case;
		end if;	
	end process;

end BHV;