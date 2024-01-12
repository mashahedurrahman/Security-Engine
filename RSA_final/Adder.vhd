library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
 
entity Adder is
	generic( 
		size : integer:= 4
	);
	port(
		A		: in  std_logic_vector(size-1 downto 0);
		B		: in  std_logic_vector(size-1 downto 0);
		Cin		: in  std_logic;
		S 		: out std_logic_vector(size-1 downto 0);
		Cout 	: out std_logic);
end Adder;
 
architecture Behavioral of Adder is
	--component FullAdder is
	--	port(
	--		A	 :in	std_logic;
	--		B	 :in	std_logic;
	--		Cin :in	std_logic;
	--		Sum :out std_logic;
	--		Cout:out std_logic);
	--end component;
	signal carry : std_logic_vector(A'length downto 0);
begin
	carry(0) <= cin;
	cout <=	carry(A'length);
	AdderGen : for i in A'range generate
		FA : entity work.FullAdder port map(A(i),B(i),carry(i),S(i),carry(i+1));
	end generate;
 
 
end Behavioral;
