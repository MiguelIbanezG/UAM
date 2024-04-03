----------------------------------------------------------------------
-- Fichero: MemProgPlantilla.vhd
-- Descripci�n: Plantilla para la memoria de programa para el MIPS
-- Fecha �ltima modificaci�n: 2017-03-27

-- Autores: Alberto S�nchez (2012-2017), �ngel de Castro (2010-2015) 
-- Asignatura: EC 1� grado
-- Grupo de Pr�cticas:
-- Grupo de Teor�a:
-- Pr�ctica: 5
-- Ejercicio: 3
----------------------------------------------------------------------


library IEEE;
use IEEE.std_logic_1164.ALL;
use IEEE.numeric_std.ALL;

entity MemProgVectores is
	port (
		MemProgAddr : in  unsigned(31 downto 0);      -- Direcci�n para la memoria de programa
		MemProgData : out unsigned(31 downto 0)  -- C�digo de operaci�n
	);
end MemProgVectores;

architecture Simple of MemProgVectores is

begin

	LecturaMemProg: process(MemProgAddr)
	begin
		-- La memoria devuelve un valor para cada direcci�n.
		-- Estos valores son los c�digos de programa de cada instrucci�n,
		-- estando situado cada uno en su direcci�n.
		case MemProgAddr is
		-------------------------------------------------------------
		-- S�lo introducir cambios desde aqu�	
			when x"00000000" => MemProgData <= x"8c042000";
			when x"00000004" => MemProgData <= x"00842020";
			when x"00000008" => MemProgData <= x"00842020";
			when x"0000000C" => MemProgData <= x"00a52826";
			when x"00000010" => MemProgData <= x"10850008";
			when x"00000014" => MemProgData <= x"8ca12004";
			when x"00000018" => MemProgData <= x"8ca2201c";
			when x"0000001C" => MemProgData <= x"00421020";
			when x"00000020" => MemProgData <= x"00421020";
			when x"00000024" => MemProgData <= x"00221820";
			when x"00000028" => MemProgData <= x"aca32034";
			when x"0000002C" => MemProgData <= x"20a50004";
			when x"00000030" => MemProgData <= x"08000004";
			when x"00000034" => MemProgData <= x"0800000d";
			-- Por cada instrucci�n en .text, agregar una l�nea del tipo:
			-- when DIRECCION => MemProgData <= INSTRUCCION;
			-- Por ejemplo, si la posici�n 0x00000000 debe guardarse la instrucci�n con c�digo m�quina 0x20010004, poner:
			--when X"00000000" => MemProgData <= X"20010004";
		-- Hasta aqu�	
		---------------------------------------------------------------------	
			
			when others => MemProgData <= X"00000000"; -- Resto de memoria vac�a
		end case;
	end process LecturaMemProg;

end Simple;

