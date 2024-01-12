library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
 
entity Regeister is
	generic (
		size: integer := 4
	);
	port(
		clock :in	std_logic;
		enable :in 	std_logic;
		reset :in	std_logic;
		din	 :in 	std_logic_vector(size-1 downto 0);
		dout :out std_logic_vector(size-1 downto 0));
end Regeister;
 
architecture Behavioral of Regeister is
	signal data :std_logic_vector(din'range):=(OTHERS=>'0');
begin
	process(clock)
	begin
		if(clock'event and clock='1')then
			if(reset ='1' )then
				data <=(others =>'0');
			elsif(enable = '1')then
				data <= din;
			else
				data <= data;
			end if;
		end if;
	end process;
	dout <= data;
 
end Behavioral;
 