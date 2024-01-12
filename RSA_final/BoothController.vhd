library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
 
 
entity BoothController is
  Port (
    clock     : in  std_logic;
    reset     : in  std_logic;
    start     : in  std_logic;
    interrupt : in  std_logic;
    load      : out std_logic;
    shift     : out std_logic;
    cnt_clear : out std_logic;
    reg_clear : out std_logic;
    ready     : out std_logic);
end BoothController;
 
 
architecture Behavioral of BoothController is
 
  type state_t is (reset_st,reset_and_load_st,calculating_st, calculated_st, done_st);
  signal current_state : state_t := reset_st;
  signal next_state : state_t := reset_st;
 
begin
  process(clock, reset)
  begin
    if(reset = '1') then
        current_state <= reset_st;
    elsif (rising_edge(clock)) then
        current_state <= next_state;
    end if;
  end process;
 
  process(current_state, start, interrupt)
  begin
    load <= '0';
    shift <= '0';
    cnt_clear <= '0';
    reg_clear <= '0';
 
    case current_state is
 
      when  reset_st =>
        if(start = '1') then 
            load <= '1'; 
            reg_clear <= '1';
            next_state <= reset_and_load_st;
        else
            next_state <= reset_st;
        end if;
 
      when  reset_and_load_st =>
          shift <= '1';
          cnt_clear <= '1';
          next_state <= calculating_st;
 
      when  calculating_st =>
          if(interrupt = '1') then
              next_state <= calculated_st;
          else    
              shift <= '1';
              next_state <= calculating_st;
          end if;
 
      when calculated_st =>
          next_state <= done_st;
 
      when done_st =>
          next_state <= reset_st;
 
    end case;
 
   end process;
  ready <= '1' when current_state = done_st else '0';
end Behavioral;