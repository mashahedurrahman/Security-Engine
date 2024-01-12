library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
 
entity BoothDatapath is
	generic(
		size: integer := 4
	);
	port(
		clock :in	std_logic;
		reset :in std_logic;
		load :in std_logic;
		shift :in std_logic;
		X	: in std_logic_vector(size-1 downto 0);
		Y	: in std_logic_vector(size-1 downto 0);
		P	: out std_logic_vector(2*size-1 downto 0));
end BoothDatapath;
 
architecture Behavioral of BoothDatapath is
 
	--component Regeister is
	--	generic (
	--		size: integer := 4
	--	);
	--	port(
	--		clock :in	std_logic;
	--		enable :in 	std_logic;
	--		reset :in	std_logic;
	--		din	 :in 	std_logic_vector(size-1 downto 0);
	--		dout :out std_logic_vector(size-1 downto 0));
	--end component;
 
	--component LeftShiftReg is
	--	generic( 
	--		size : integer:= 4
	--	);
	--	port(
	--		clock	 :in	std_logic;
	--		enable :in 	std_logic;
	--		shift	 :in	std_logic;
	--		din	 :in 	std_logic_vector(size-1 downto 0);
	--		dout	 :out std_logic_vector(size-1 downto 0));
	--end component;
 
	--component RightShiftReg is
	--	generic(
	--		size : integer := 4
	--	);
	--	port(
	--		clock	 :in	std_logic;
	--		enable :in 	std_logic;
	--		shift	 :in	std_logic;
	--		din	 :in 	std_logic_vector(size-1 downto 0);
	--		dout	 :out std_logic_vector(1 downto 0));
	--end component;
	--component BoothEncoder is
	--	port(
	--		input1	: in 	std_logic;
	--		input0	: in 	std_logic;
	--		operator	: out std_logic;
	--		product	: out	std_logic
	--		);
	--end component;
 
	--component Alu is
	--	generic( 
	--		size : integer:= 4
	--	);
	--	port(
	--		A	: in  std_logic_vector(size-1 downto 0);
	--		B	: in  std_logic_vector(size-1 downto 0);
	--		op	: in  std_logic;
	--		S 	: out std_logic_vector(size-1 downto 0));
	--end component;
	--component Ander is
	--	generic( 
	--		size : integer:= 4
	--	);
	--	port(
	--		input1 : in	 std_logic;
	--		input2 : in  std_logic_vector(size-1 downto 0);
	--		result : out std_logic_vector(size-1 downto 0));
	--end component;
	signal sign_extended_x,andout,alu_out,p_out,X_reg_dout: std_logic_vector(2*X'length -1 downto 0);
	signal lessTwoBits : std_logic_vector(1 downto 0);
	signal operator,product : std_logic;
	signal Y_concat_zero : std_logic_vector(y'length downto 0);
begin
	Y_concat_zero <= Y & '0';
	sign_extended_x(X'range) <= X;
	sign_extended_x(sign_extended_x'length - 1 downto X'length) <= (others=> X(X'length-1));
 
  Booth_ENC: entity work.BoothEncoder
    port map(input1 => lessTwoBits(1),
      input0=>lessTwoBits(0),
      operator => operator,
      product => product);
 
	Y_REG		: entity work.RightShiftReg 
	generic map(size => size+1)
	port map(
    clock => clock,
    enable => load,
    shift =>shift,
    din => Y_concat_zero,
    dout => lessTwoBits);
 
  X_REG : entity work.LeftShiftReg
  generic map(size => 2*size)
  port map(
    clock => clock,
    enable => load,
    shift => shift,
    din => sign_extended_x,
    dout => X_reg_dout);
 
  ANDing : entity work.Ander
  generic map(size => 2*size)
  port map(
    input1 => product,
    input2 => X_reg_dout,
    result => AndOut);
 
  Add_Sub : entity work.Alu
  generic map(size => 2*size)
  port map(
    A => P_out,
    B => AndOut,
    op => operator,
    S => ALU_Out);  
 
  P_REG : entity work.Regeister
  generic map(size => 2*size)
    port map(
      clock => clock,
      enable => shift,
      reset => reset,
      din => ALU_Out,
      dout => P_out);
  P <= P_out;
 
end Behavioral;
 
