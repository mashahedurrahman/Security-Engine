LIBRARY IEEE;
use IEEE.std_logic_1164.all;
use IEEE.numeric_std.all;
use IEEE.std_logic_unsigned.all;

entity top_level is
port(
	clk, rst, go : in std_logic;
	function_bits : in std_logic_vector(1 downto 0);
	data_in : in std_logic_vector(1023 downto 0);
	data_out : out std_logic_vector(511 downto 0);
	read_en,busy : out std_logic;
	done : out std_logic
);
end top_level;

architecture STR of top_level is
	signal function_data : std_logic_vector(1023 downto 0);
	signal select_bits : std_logic_vector(1 downto 0);
	signal data_en, start_function, function_done : std_logic;
	signal block_out : std_logic_vector(511 downto 0);
begin
	
	busy <= not function_done;
	
	U_DATA : entity work.reg
		generic map(width => 1024)
		port map(
			clk => clk,
			rst => rst,
			en => data_en,
			input => data_in,
			output => function_data
		);
	U_SELECT: entity work.reg
		generic map(width => 2)
		port map(
			clk => clk,
			rst => rst,
			en => data_en,
			input => function_bits,
			output => select_bits
		);
	U_OUTPUT: entity work.reg
		generic map(width => 512)
		port map(
			clk => clk,
			rst => rst,
			en => function_done,
			input => block_out,
			output => data_out
		);
----Functions
	U_FUNCTIONS : entity work.sha_functions
		port map(
			clk => clk,
			rst => rst,
			go => start_function,
			function_bits => select_bits,
			data_in => function_data,
			data_out => block_out,
			done => function_done
		);
----COntroller
	U_CONTROLLER : entity work.sha_controller
		port map(
			clk => clk,
			rst => rst,
			reg_enable => data_en,
			go => go,
			start_function => start_function,
			done_function => function_done,
			read_valid => read_en,
			done => done
		);
end STR;