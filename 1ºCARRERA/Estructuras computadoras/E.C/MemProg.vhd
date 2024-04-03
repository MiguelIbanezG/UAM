----------------------------------------------------------------------------
----------------------------------------------------------------------------
-- Asignatura: Estructura de computadores
-- Fichero: MemProg.vhd
-- Descripción: Memoria de programa para probar el correcto diseño de un microprocesador simplificado
-- Fichero de apoyo para la evaluación de la practica 2. MODELO A
----------------------------------------------------------------------------
-----------------------------------------------------------------------------

library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;

entity MemProg is
	port (
		MemAddr : in unsigned(23 downto 0); 
		Instruc : out unsigned(23 downto 0) 
	);
end MemProg;

architecture examen of MemProg is

begin

	LecturaMemProg: process(MemAddr)
	begin
		case MemAddr is
			when X"000000" => Instruc <= x"001019";    -- R1 = R0 + 25		# R1 = 0x000019
			when X"000003" => Instruc <= x"012032";    -- R2 = R1 + 50		# R2 = 0x00004B
			when X"000006" => Instruc <= x"023FF6";    -- R3 = R2 + (-10)	# R3 = 0x000041
			when X"000009" => Instruc <= x"030014";    -- R0 = R3 + 20		# R0 = 0x000000
			when X"00000C" => Instruc <= x"034064";    -- R4 = R3 + 100		# R4 = 0x0000A5
			when others => Instruc <= x"000000"; 		-- Resto de memoria vacía
		end case;
	end process LecturaMemProg;

end examen;









