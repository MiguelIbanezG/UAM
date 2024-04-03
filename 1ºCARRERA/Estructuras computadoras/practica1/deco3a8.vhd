---------------------------------------------------------------------------------
-- File: Deco2a4.vhd
-- Description: Decoder 2 to 4
-- Last modification date: 2019-01-23

-- Authors: Sofia Martínez (2019), Alberto Sánchez (2012), Fernando López (2010) 
-- Subject: C.E. 1º grade
-- Laboratory group:
-- Theory group:
-- Task: 1
-- Exercise: 2
---------------------------------------------------------------------------------


library IEEE;
use IEEE.std_logic_1164.ALL;
use IEEE.std_LOGIC_arith.ALL;
use IEEE.std_logic_unsigned.ALL;


entity Deco3a8 is
    port ( 
		D : in  std_logic_vector (2 downto 0);
		Q : out  std_logic_vector (7 downto 0)
	);
end Deco3a8;

architecture Practica of Deco3a8 is

begin

	process (D)
	begin
		case D is
			when "000" => Q <= "00000001";
			when "001" => Q <= "00000010";
			when "010" => Q <= "00000100";
			when "011" => Q <= "00001000";
			when "100" => Q <= "00010000";
			when "101" => Q <= "00100000";
			when "110" => Q <= "01000000";
			when others => Q <= "10000000";
		end case;
	end process;

end Practica;
  