library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use IEEE.STD_LOGIC_ARITH.ALL;
use IEEE.STD_LOGIC_UNSIGNED.ALL;
use ieee.numeric_std.all;

entity sha_controller is
port(
	clk : in std_logic;
	rst : in std_logic;
	
	reg_enable : out std_logic;
	go : in std_logic;
	
	start_function : out std_logic;
	done_function : in std_logic;
	
	read_valid : out std_logic; --Function is done and data is ready to be read
	done : out std_logic
);
end sha_controller;

architecture ASM of sha_controller is
	type STATE_TYPE is (WAIT_FOR_GO, S_START, POLL_DONE, S_DONE);
	signal state : STATE_TYPE;
begin
	process(clk, rst)
	
	begin
		if(rst = '1') then
			state <= WAIT_FOR_GO;
			done <= '0';
			read_valid <= '0';
		elsif(rising_edge(clk)) then
			reg_enable <= '0';
			read_valid <= '0';
			start_function <= '0';
			case state is
				when WAIT_FOR_GO =>
					reg_enable <= '1';
					if(go = '1') then
						state <= S_START;
						done <= '0';
					else 
						state <= WAIT_FOR_GO;
					end if;
				when S_START =>
					start_function <= '1';
					state <= POLL_DONE;
				when POLL_DONE =>
					if(done_function = '1') then
						read_valid <= '1';
						state <= S_DONE;
					else
						state <= POLL_DONE;
					end if;
				when S_DONE =>
					read_valid <= '1';
					done <= '1';
					if(go <= '0') then
						state <= WAIT_FOR_GO;
					else
						state <= S_DONE;
					end if;
				end case;
			end if;
	end process;
end ASM;
