library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use IEEE.STD_LOGIC_ARITH.ALL;
use IEEE.STD_LOGIC_UNSIGNED.ALL;
use ieee.numeric_std.all;

entity sha_ip_tb is
end sha_ip_tb;

architecture tb of sha_ip_tb is
	signal clk, rst, go, busy, done, read_en : std_logic := '0';
	signal function_bits : std_logic_vector(1 downto 0);
	signal data_in : std_logic_vector(1023 downto 0);
	signal data_out : std_logic_vector(511 downto 0);
begin
	UUT: entity work.top_level
		port map(
			clk => clk,
			rst => rst,	
			go => go,
			function_bits => function_bits,
			data_in => data_in,
			data_out => data_out,
			read_en => read_en,
			busy => busy,
			done => done
		);
	clk <= not clk after 5 ns;
	
	process
		begin
			$dumpfile("tb_sha_top.vcd");
			$dumpvars(0, tb_sha_top);
			rst <= '1';
			for i in 0 to 20 loop 
				wait until rising_edge(clk);
			end loop;
			
			rst <= '0';
			for i in 0 to 20 loop 
				wait until rising_edge(clk);
			end loop;
			--SHA256
			function_bits <= "00";
			data_in <= x"000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000001234FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF";
			wait until rising_edge(clk);
			go <= '1';
			wait until rising_edge(clk);
			go <= '0';
			wait until done = '1';
			--SHA384
			function_bits <= "01";
			data_in <= x"FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF1234";
			wait until rising_edge(clk);
			go <= '1';
			wait until rising_edge(clk);
			go <= '0';
			wait until done = '1';
			--SHA512
			function_bits <= "10";
			data_in <= x"FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF1234";
			wait until rising_edge(clk);
			go <= '1';
			wait until done = '1';
 			$finish;
		wait;
	end process;
end tb;
