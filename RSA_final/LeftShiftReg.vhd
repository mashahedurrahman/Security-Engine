library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
 
entity LeftShiftReg is
		generic( 
			size : integer:= 4
		);
		port(
			clock	 :in	std_logic;
			enable :in 	std_logic;
			shift	 :in	std_logic;
			din	 :in 	std_logic_vector(size-1 downto 0);
			dout	 :out std_logic_vector(size-1 downto 0));
end LeftShiftReg;
 
architecture Behavioral of LeftShiftReg is
	signal data : std_logic_vector(din'range);
begin
	process(clock, enable, shift)
	begin
		if(clock'event and clock = '1')then
			if(enable = '1')then
				data <= din;
			elsif(shift = '1') then 
				data <= data(din'length-2 downto 0) & '0';
			else
				data <= data;
			end if;
		end if;
	end process;
	dout <= data;
 
end Behavioral;