library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use IEEE.STD_LOGIC_ARITH.ALL;
use IEEE.STD_LOGIC_UNSIGNED.ALL;
use ieee.numeric_std.all;

entity mux512 is
port(
		in0, in1, in2, in3: in std_logic_vector(511 downto 0);
		select_bits : in std_logic_vector(1 downto 0);
		output : out std_logic_vector(511 downto 0)
	);
end mux512;

architecture BHV of mux512 is
begin
	process(in0, in1, in2, in3, select_bits)
	begin
		if(select_bits = "00") then
			output <= in0;
		elsif(select_bits = "01") then	
			output <= in1;
		elsif(select_bits = "10") then
			output <= in2;
		else
			output <= in3;
		end if;
	end process;
end BHV;