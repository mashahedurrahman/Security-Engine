library ieee;
use ieee.std_logic_1164.all;
use ieee.std_logic_unsigned.all;
 
entity counter is
  generic( 
		size : integer:= 4
	);
	port(	
    clock : in	std_logic;
		reset : in	std_logic;
		value : out	std_logic_vector(size-1 downto 0));
end counter;
 
architecture behavioral of counter is
 
	signal internal_value : std_logic_vector(value'range):= (others => '0');
 
begin
 
  counter_proc:
  process(clock)
  begin
    if (rising_edge(clock)) then
      if (reset = '1') then
        internal_value <= (others => '0');
      else
        internal_value <= internal_value + '1';
      end if;
   end if;
   end process;
 
  value <= internal_value;
 
end;