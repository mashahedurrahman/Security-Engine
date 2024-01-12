library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
 
entity XorCrearor is
	generic (
		size: integer := 4
	);
	port(
		input1 : in	 std_logic;
		input2 : in  std_logic_vector(size-1 downto 0);
		result : out std_logic_vector(size-1 downto 0));
end XorCrearor;
 
architecture Behavioral of XorCrearor is
 
begin
	process(input1,input2)
	begin
		 for i in input2'range loop
			result(i) <= input1 xor input2(i);
		 end loop;
	end process;
 
 
end Behavioral;
 