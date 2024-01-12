library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
 
entity RightShiftReg is
	generic(
		size : integer := 4
	);
	port(
		clock	 :in	std_logic;
		enable :in 	std_logic;
		shift	 :in	std_logic;
		din	 :in 	std_logic_vector(size-1 downto 0);
		dout	 :out std_logic_vector(1 downto 0));
end RightShiftReg;
 
architecture Behavioral of RightShiftReg is
	signal data : std_logic_vector(din'length-1 downto 0);
begin
	process(clock, enable, shift)
	begin
		if(clock'event and clock = '1')then
			if(enable = '1')then
				data <= din;
			elsif(shift = '1') then 
				data <= '0' & data(din'length-1 downto 1);
			else
				data <= data;
			end if;
		end if;
	end process;
	dout <= data(1 downto 0);
end Behavioral;
 
 