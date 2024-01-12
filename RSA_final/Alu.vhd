library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
 
entity Alu is
	generic( 
		size : integer:= 4
	);
	port(
		A	: in  std_logic_vector(size-1 downto 0);
		B	: in  std_logic_vector(size-1 downto 0);
		op	: in  std_logic;
		S 	: out std_logic_vector(size-1 downto 0));
end Alu;
 
architecture Behavioral of Alu is
	--component Adder is
	--	generic( 
	--		size : integer:= 4
	--	);
	--	port(
	--		A		: in  std_logic_vector(size-1 downto 0);
	--		B		: in  std_logic_vector(size-1 downto 0);
	--		Cin	: in  std_logic;
	--		S 		: out std_logic_vector(size-1 downto 0);
	--		Cout 	: out std_logic);
	--end component;
 
	--component XorCrearor is
	--	generic( 
	--		size : integer:= 4
	--	);
	--	port(
	--		input1 : in	 std_logic;
	--		input2 : in  std_logic_vector(size-1 downto 0);
	--		result : out std_logic_vector);
	--end component;
	signal xored: std_logic_vector(A'range);
begin
	XO : entity work.XorCrearor 
		generic map (
			size => size
		)
		port map(
			input1 => op,
			input2 =>B,
			result => xored);
	ADD: entity work.Adder 
		generic map (
			size => size
		)
		port map(
			A=> A,
			B=> xored,
			cin=> op,
			S=> S,
			cout=> open);
 
end Behavioral;
 
