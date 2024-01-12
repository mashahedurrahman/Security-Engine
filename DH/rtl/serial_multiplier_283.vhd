----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date: 02/03/2022 01:54:57 AM
-- Design Name: 
-- Module Name: serial_multiplier_283 - Behavioral
-- Project Name: 
-- Target Devices: 
-- Tool Versions: 
-- Description: 
-- 
-- Dependencies: 
-- 
-- Revision:
-- Revision 0.01 - File Created
-- Additional Comments:
-- 
----------------------------------------------------------------------------------

----------------------------------------------------------------------------------------------------
--											serial_multiplier.vhd											 ---
----------------------------------------------------------------------------------------------------
-- Author		: Miguel Morales-Sandoval														 ---
-- Project		: "Hardware Arquitecture for ECC and Lossless Data Compression					 ---
-- Organization	: INAOE, Computer Science Department											 ---
-- Date			: July, 2004.																	 ---
----------------------------------------------------------------------------------------------------
--	Serial multiplier for F_2^m
----------------------------------------------------------------------------------------------------
-- Coments: The input buses need to have valid data when Reset signal is asserted
----------------------------------------------------------------------------------------------------
library IEEE;
use IEEE.STD_LOGIC_1164.all;
use IEEE.std_logic_arith.all;
use IEEE.std_logic_unsigned.all;
--------------------------------------------------------
entity serial_multiplier_283 is
	generic (
		NUM_BITS : positive := 283							-- The order of the finite field
	);
	port(
	 	ax : in  std_logic_vector(NUM_BITS-1 downto 0); 
		bx : in  std_logic_vector(NUM_BITS-1 downto 0);	 
		cx : out std_logic_vector(NUM_BITS-1 downto 0);		-- cx = ax*bx mod Fx
		reset : in std_logic;
		go    : in std_logic;
		clk	  : in std_logic;
		done  : out std_logic
	);	
end serial_multiplier_283;
-----------------------------------------------------------
architecture behave of serial_multiplier_283 is		  		
-----------------------------------------------------------
-- m = 283        x283 + x12 + x7 + x5 + 1														
constant Fx: std_logic_vector(NUM_BITS-1 downto 0) := "0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000001000010100001";
-----------------------------------------------------------
signal Op1  	: std_logic_vector(NUM_BITS-1 downto 0);	-- Multiplexers for ax and cx  depending upon b_i and c_m 
signal Op2 		: std_logic_vector(NUM_BITS-1 downto 0);
signal bx_shift : std_logic_vector(NUM_BITS-1 downto 0);	-- B and C shifted one position to the rigth
signal cx_shift : std_logic_vector(NUM_BITS-1 downto 0);	
signal bx_int	: std_logic_vector(NUM_BITS-1 downto 0);	-- Internal registers 
signal cx_int	: std_logic_vector(NUM_BITS-1 downto 0);	-- Internal registers

signal counter: std_logic_vector(8 downto 0);				-- 8-bit counter, controling the number of iterations: m

-----------------------------------------------------------
-- States for the finite state machine
-----------------------------------------------------------
type CurrentState_type is (MUL_STATE, WAIT_STATE, END_STATE);			
signal CurrentState: CurrentState_type;					
-----------------------------------------------------------
begin
-----------------------------------------------------------
cx <= cx_int;												-- Result of the multiplication

Bx_shift <= bx_int(NUM_BITS-2 downto 0)& '0';				-- Shift Bx and Cx to left one position
Cx_shift <= cx_int(NUM_BITS-2 downto 0)& '0';
															-- Multiplexer to determine what value is added to C_x in each iteration
Op1 <= ax when bx_int(NUM_BITS-1) = '1' else				-- The selector for these multiplexors are the most significant bits of B_x and C_x
	(others => '0');
Op2 <= Fx when cx_int(NUM_BITS-1) = '1' else
	(others => '0');
------------------------------------------------------------
-- The finite state machine, it takes m cycles to compute 
-- the multiplication, a counter is used to keep this count
------------------------------------------------------------
FSM_MUL: process (CLK)
	Begin						
		if CLK'event and CLK = '1' then
			if Reset = '1' then
				counter <= "100011010"; 						-- m-1 value, in this case, it is 162, be sure to set the correct value      
				bx_int  <= bx;
				cx_int  <= (others => '0');
				Done    <= '0';
				CurrentState <= WAIT_STATE;
			else
			 case CurrentState is
                when WAIT_STATE =>
                       counter <= "100011010"; 						-- m-1 value, in this case, it is 162, be sure to set the correct value      
                       bx_int  <= bx;
                       if go = '1' then
					       CurrentState <= MUL_STATE;
					       Done <= '0';
					       cx_int  <= (others => '0');
                        else    
                            CurrentState <= WAIT_STATE;
                        end if;
				when MUL_STATE =>							-- processes a bit of bx					
					Cx_int  <= cx_shift xor Op1 xor Op2;
					counter <= counter - 1;
					if counter = "000000000" then			-- The done signal is asserted at the same time that the result is computed.
						CurrentState <= END_STATE;
						Done <= '1';	
					else
						bx_int <= bx_shift;
					end if;
					
				when END_STATE =>
				   if go = '0' then
					   CurrentState <= WAIT_STATE;
                   else 
                        CurrentState <= END_STATE;
                   end if;
				
				when others =>
					null;
				end case;
			end if;
		end if;
end process;		 
end behave;
