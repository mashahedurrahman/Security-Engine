library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
 
entity FullAdder is
	port(
		A	 :in	std_logic;
		B	 :in	std_logic;
		Cin :in	std_logic;
		Sum :out std_logic;
		Cout:out std_logic);
end FullAdder;
 
architecture Behavioral of FullAdder is
 
begin
	Cout 	<= (A AND B)OR(B AND Cin)OR(Cin AND A);
	Sum	<= A XOR B XOR Cin;
 
end Behavioral;