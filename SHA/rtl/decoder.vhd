library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use IEEE.STD_LOGIC_ARITH.ALL;
use IEEE.STD_LOGIC_UNSIGNED.ALL;
use ieee.numeric_std.all;

entity decoder is
port(
	input : in std_logic;
	select_bits : in std_logic_vector(1 downto 0);
	out0 : out std_logic;
	out1 : out std_logic;
	out2 : out std_logic;
	out3 : out std_logic
);
end decoder;

architecture BHV of decoder is 

begin

	process(select_bits, input)
	begin
		out0 <= '0';
		out1 <= '0';
		out2 <= '0';
		out3 <= '0';
		if(select_bits = "00") then
			out0 <= input;
		elsif(select_bits = "01") then 
			out1 <= input;
		elsif(select_bits = "10") then
			out2 <= input;
		else	
			out3 <= input;
		end if;
	end process;
end BHV;