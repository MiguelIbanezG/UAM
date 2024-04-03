----------------------------------------------------------------------
-- File: ALUMIPS.vhd
-- Description: ALU of the microprocessor MIPS
-- Date last modification: 

-- Authors: 
-- Sbuject: Sbuject: C.E. 1st grade
-- Laboratory group:
-- Theory group:
-- Task: 2
-- Exercise: 2
----------------------------------------------------------------------


library IEEE;
use IEEE.std_logic_1164.ALL;
use IEEE.std_LOGIC_arith.ALL;
use IEEE.std_logic_signed.ALL;

entity ALUMIPS is
	Port (
		Op1 : in std_logic_vector (31 downto 0);
		Op2 : in std_logic_vector (31 downto 0);
		ALUControl : in std_logic_vector (2 downto 0);
		Res : out std_logic_vector (31 downto 0);
		Z : out std_logic
		);
end ALUMIPS;

architecture Practica of ALUMIPS is

signal slt : std_logic_vector(31 downto 0);
signal result : std_logic_vector(31 downto 0);

begin
  
  slt <= (0 => '1', others => '0') when Op1<Op2 else (others => '0');
  
  with ALUControl select 
    result <=  Op1 and Op2 when "000",
            Op1 or Op2 when "001",
            Op1 nor Op2 when "101",
            Op1 + Op2 when "010",
            Op1 - Op2 when "110",
            slt when "111",
            (others => 'X') when others;
            
    Res <= result;
    z <= '1' when result = 0 else '0';

end Practica;
