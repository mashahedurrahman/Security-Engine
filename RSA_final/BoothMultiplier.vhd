library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
 
entity BoothMultiplier is
  generic(COUNTER_SIZE : positive := 4;
			DATA_SIZE  : positive := 11);
	port(
		clock : in	std_logic;
		clear : in 	std_logic;
    start : in  std_logic;
		X_data: in 	std_logic_vector(2**DATA_SIZE-1 downto 0);
		Y_data: in 	std_logic_vector(2**DATA_SIZE-1 downto 0);
		ready : out std_logic;
		Result: out std_logic_vector(2*(2**DATA_SIZE)-1 downto 0));
end BoothMultiplier;
 
architecture Behavioral of BoothMultiplier is
 
 -- component counter is
 --   generic(
 --     size: integer := 2048
 --   );
  --  port(	clock : in	std_logic;
  --        reset : in	std_logic;
  --        value : out	std_logic_vector);
  --end component counter;
 
  --component BoothDatapath is
  --  generic(
  --    size: integer := 2048
  --  );
  --  port(
  --  clock :in  std_logic;
  --  reset :in std_logic;
  --  load :in std_logic;
  --  shift :in std_logic;
  --  X  :in std_logic_vector;
  --  Y  :in std_logic_vector;
  --  P  :out std_logic_vector);
  --  end component BoothDatapath;
 
  --      component BoothController is
  --    Port (
  --      clock : in  std_logic;
  --      reset : in  std_logic;
  --      start : in  std_logic;
  --      interrupt : in std_logic;
  --      load : out std_logic;
  --      shift : out std_logic;
  --      cnt_clear : out std_logic;
  --      reg_clear : out std_logic;
  --      ready : out std_logic);
  --  end component BoothController;
 
    signal load : std_logic;
    signal counter_value : std_logic_vector(COUNTER_SIZE - 1 downto 0);
    signal shift : std_logic;
    signal counter_interrupt : std_logic;
    signal cnt_clear : std_logic;
    signal reg_clear : std_logic;
 
    CONSTANT ONES : std_logic_vector(COUNTER_SIZE - 1 downto 0) := (others => '1');
 
begin
 
	datapath:  entity work.BoothDatapath
  generic map(2**DATA_SIZE)
	port map(
	   clock => clock,
	   reset => reg_clear,
	   load => load,
	   shift => shift,
	   X => X_data,
	   Y => Y_data,
	   P => Result);
 
	U_counter: entity work.counter  
    generic map(size => COUNTER_SIZE)
    port map(
       clock => clock,
       reset => cnt_clear,
       value => counter_value);
 
  counter_interrupt <= '1' when (counter_value = ONES) else '0';  
 
	controller: entity work.BoothController
       port map(
          clock => clock,
          reset => clear,
          start => start,
          interrupt => counter_interrupt,
          load => load,
          shift => shift,
          cnt_clear => cnt_clear,
          reg_clear => reg_clear,
          ready => ready);
 
end Behavioral;
