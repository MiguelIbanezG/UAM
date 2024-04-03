----------------------------------------------------------------------
----------------------------------------------------------------------
-- Asignatura: Estructura de Computadores. Grado GII y DGIIM. 1� curso.
-- Fichero: MemProgMIPS.vhd
-- Descripci�n: Memoria de programa para el MIPS
-- Fichero de apoyo para: Pr�ctica: 4. Ejercicio: 3. Se utiliza en la primera prueba de validaci�n del Ejercicio 3
----------------------------------------------------------------------
----------------------------------------------------------------------

library IEEE;
use IEEE.std_logic_1164.ALL;
use IEEE.numeric_std.ALL;

entity MemProgMIPS is										-- Al crear el archivo MemProgVectores.asm, debe cambiar el nombre de la entidad
	port (
		MemProgAddr : in unsigned(31 downto 0);        		-- Direcci�n para la memoria de programa
		MemProgData : out unsigned(31 downto 0) 	-- C�digo de operaci�n
	);
end MemProgMIPS;											-- Al crear el archivo MemProgVectores.asm, debe cambiar el nombre de la entidad

architecture Simple of MemProgMIPS is						-- Al crear el archivo MemProgVectores.asm, debe cambiar el nombre de la entidad

begin

	-- Proceso para la escritura inicial en la memoria de c�digo o de programa. 
	-- La memoria de progrma es de solo lectura, el proceso de escritura es �nico y se realiza antes de ejecutar la simulaci�n.  
	EscrituraMemProg: process(all)
	begin
		-- La memoria devuelve un valor para cada direcci�n.
		-- Estos valores son los c�digos de programa de cada instrucci�n, estando situado cada uno en su direcci�n.
		-- C�digo para la escritura de los datos iniciales quedeben ser cargados previamente en memoria antes de la ejecuci�n del programa.
		
			
		case MemProgAddr is
-- *********************************************************************
			when x"00000000" => MemProgData <= x"20100000";
			when x"00000004" => MemProgData <= x"8c112000";
			when x"00000008" => MemProgData <= x"02318820";
			when x"0000000C" => MemProgData <= x"02318820";
			when x"00000010" => MemProgData <= x"12110007";
			when x"00000014" => MemProgData <= x"8e092004";
			when x"00000018" => MemProgData <= x"8e0a201c";
			when x"0000001C" => MemProgData <= x"014a5020";
			when x"00000020" => MemProgData <= x"014a5020";
			when x"00000024" => MemProgData <= x"012a5820";
			when x"00000028" => MemProgData <= x"ae0b2034";
			when x"0000002C" => MemProgData <= x"22100004";
			when x"00000030" => MemProgData <= x"0800000c";		
-- *********************************************************************			
			when others => MemProgData <= x"00000000"; -- Resto de memoria vac�a
		end case;
	end process EscrituraMemProg;

		
	
end Simple;
