----------------------------------------------------------------------
-- Fichero: Deco2a4.vhd
-- Descripci�n: Decodificador 2 a 4
-- Fecha �ltima modificaci�n: 2020-01-29

-- Autores: Alberto S�nchez (2012), Fernando L�pez (2010) 
-- Asignatura: E.C. 1� grado
-- Grupo de Pr�cticas:
-- Grupo de Teor�a:
-- Pr�ctica: 1
-- Ejercicio: 2
----------------------------------------------------------------------


library IEEE;
use IEEE.std_logic_1164.ALL;
use IEEE.numeric_std.ALL;



entity Deco3a8 is
    port ( 
		D : in  std_logic_vector (2 downto 0);
		CE : in std_logic;
		Clk : in std_logic;
		Reset : in std_logic;
		Q : out  std_logic_vector (7 downto 0)
	);
end Deco3a8;

architecture Practica of Deco3a8 is

begin

	process (all)
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
