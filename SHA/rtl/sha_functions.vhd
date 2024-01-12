LIBRARY IEEE;
use IEEE.std_logic_1164.all;
use IEEE.numeric_std.all;
use IEEE.std_logic_unsigned.all;


entity sha_functions is
port(
		clk, rst, go : in std_logic;
		function_bits : in std_logic_vector(1 downto 0);
		data_in : in std_logic_vector(1023 downto 0);
		data_out : out std_logic_vector(511 downto 0);
		done : out std_logic
	);
end sha_functions;

architecture STR of sha_functions is
	signal go256, go384, go512 : std_logic;
	signal done256, done384, done512 : std_logic;
	signal out256 : std_logic_vector(255 downto 0);
	signal out384 : std_logic_vector(383 downto 0);
	signal out512, pad384, pad256 : std_logic_vector(511 downto 0);
	signal zeros : std_logic_vector(127 downto 0);
	
begin
	
	pad384 <= x"00000000000000000000000000000000" & out384;
	pad256 <= x"00000000000000000000000000000000" & x"00000000000000000000000000000000" & out256;
	
	U_DECODER : entity work.decoder
		port map(
			input => go,
			select_bits => function_bits,
			out0 => go256,
			out1 => go384,
			out2 => go512,
			out3 => open
		);
	U_SHA256 : entity work.SHA_IP
		port map(
			clk => clk,
			rst => rst,
			go => go256,
			data_in => data_in(511 downto 0),
			data_out => out256,
			done => done256
		);
		
	U_SHA384 : entity work.SHA384_IP
		port map(
			clk => clk,
			rst => rst,
			go => go384,
			data_in => data_in,
			data_out => out384,
			done => done384
		);
		
	U_SHA512 : entity work.SHA512_IP
		port map(
			clk => clk,
			rst => rst,
			go => go512,
			data_in => data_in,
			data_out => out512,
			done => done512
		);
	U_DONEMUX : entity work.mux4x1 
		port map(
			in0 => done256,
			in1 => done384,
			in2 => done512,
			in3 => '0',
			select_bits => function_bits,
			output => done
		);
	U_OUTPUT : entity work.mux512
		port map(
			in0 => pad256,
			in1 => pad384,
			in2 => out512,
			in3 => (others => '0'),
			select_bits => function_bits,
			output => data_out
		);
end STR;