LIBRARY IEEE;
use IEEE.std_logic_1164.all;
use IEEE.numeric_std.all;
use IEEE.std_logic_unsigned.all;

entity SHA_IP is
port(
	clk : in std_logic;
	rst : in std_logic;
	go : in std_logic;
	
	data_in : in std_logic_vector(511 downto 0);
	data_out : out std_logic_vector(255 downto 0);
	
	done: out std_logic
);
end SHA_IP;

architecture BHV of SHA_IP is
	component sha256
	port(
		clk_i : in std_logic;
		rst_i : in std_logic;
		text_i : in std_logic_vector(31 downto 0);
		text_o : out std_logic_vector(31 downto 0);
		text_o0 : out std_logic_vector(31 downto 0);
		text_o1 : out std_logic_vector(31 downto 0);
		text_o2 : out std_logic_vector(31 downto 0);
		text_o3 : out std_logic_vector(31 downto 0);
		text_o4 : out std_logic_vector(31 downto 0);
		text_o5 : out std_logic_vector(31 downto 0);
		text_o6 : out std_logic_vector(31 downto 0);
		text_o7 : out std_logic_vector(31 downto 0);
		done : out std_logic;
		cmd_i : in std_logic_vector(2 downto 0);
		cmd_w_i : in std_logic;
		cmd_o : out std_logic_vector(3 downto 0));
	end component;
	
	signal data : std_logic_vector(31 downto 0);
	signal text_o0 :  std_logic_vector(31 downto 0);
	signal text_o1 :  std_logic_vector(31 downto 0);
	signal	text_o2 :  std_logic_vector(31 downto 0);
	signal	text_o3 :  std_logic_vector(31 downto 0);
	signal	text_o4 :  std_logic_vector(31 downto 0);
	signal	text_o5 :  std_logic_vector(31 downto 0);
	signal	text_o6 :  std_logic_vector(31 downto 0);
	signal	text_o7 :  std_logic_vector(31 downto 0);
	signal	done_SHA :  std_logic;
	signal	cmd_i : std_logic_vector(2 downto 0);
	signal	cmd_w_i :  std_logic;
	signal	cmd_o : std_logic_vector(3 downto 0);
	signal zeros : std_logic_vector(446 downto 0) := (others => '0');
	signal length_sha : std_logic_vector(63 downto 0) := "0000000000000000000000000000000000000000000000000000001000000000";
	signal padded_data : std_logic_vector(1023 downto 0);
	
begin
	UUT: sha256
		port map(
			clk_i => clk,
			rst_i => rst,
			text_i => data,
			text_o => open,
			text_o0 => text_o0,
			text_o1 => text_o1,
			text_o2 => text_o2,
			text_o3 => text_o3,
			text_o4 => text_o4,
			text_o5 => text_o5,
			text_o6 => text_o6,
			text_o7 => text_o7,
			done => done_SHA,
			cmd_i => cmd_i,
			cmd_w_i => cmd_w_i,
			cmd_o => cmd_o
		);
	U_CONTROL : entity work.controller
		port map(
			clk => clk,
			rst => rst,
			go => go,
			data_in => padded_data,
			data => data,
			done_SHA => done_SHA,
			cmd_i => cmd_i,
			cmd_w_i => cmd_w_i,
			cmd_o => cmd_o,
			done => done
		);
		
	process(go)
	begin
		padded_data <= data_in & '1' & zeros & length_sha;
	end process;
	
	data_out <= text_o7 & text_o6 & text_o5 & text_o4 & text_o3 & text_o2 & text_o1 & text_o0;


end BHV;