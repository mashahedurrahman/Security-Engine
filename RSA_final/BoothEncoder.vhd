 
library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
 
entity BoothEncoder is
	port(
		input1	: in 	std_logic;
		input0	: in 	std_logic;
		operator : out std_logic;
		product	: out	std_logic
		);
end BoothEncoder;
 
architecture Behavioral of BoothEncoder is
 
begin
	product 	<= input1 xor input0 ;
	operator <=	input1;
end Behavioral;