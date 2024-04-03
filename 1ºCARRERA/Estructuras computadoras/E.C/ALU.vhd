----------------------------------------------------------------------------------
----------------------------------------------------------------------------------
-- Asignatura: Estructura de computadores
-- Fichero: ALU.vhd
-- Descripción: Diseño de la Unidad Aritmetico Logica de un microprocesador uniciclo (NO es MIPS)
-- Fichero de apoyo para la evaluación de la Practica 2. MODELO A
----------------------------------------------------------------------------------
----------------------------------------------------------------------------------

library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;

entity ALU is
	Port (
		Op1 : in signed (23 downto 0);
		Op2 : in signed (23 downto 0);
		Control : in std_logic_vector (3 downto 0);
		Result : out signed (23 downto 0)
		);
end ALU;


architecture Examen of ALU is

begin

	process (all)
		begin
			case Control is
 				when "0001" => Result <= Op1 or Op2 ;
				when "0010" => Result <= Op1 + Op2 ;
				when "0110" => Result <= Op1 - Op2 ;
				when "0111" => 
					if Op1 < Op2 then
						Result <= (0 => '1', others => '0');
					else Result <= (others => '0');
					end if;
				when others => Result <= (others => '0') ;
			end case;
	end process;		
	
end Examen;
