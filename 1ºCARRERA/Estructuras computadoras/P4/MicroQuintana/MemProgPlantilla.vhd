----------------------------------------------------------------------
-- File: MemProgPlantilla.vhd
-- Description: Template for the prorammemory MIPS
-- Date last modification: 2019-03-29

-- Authors: Sofía Martínez (2019), Alberto Sánchez (2012-2018), Ángel de Castro (2010-2015)
-- Sbuject: Sbuject: C.E. 1st grade
-- Laboratory group:
-- Theory group:
-- Task: 4
-- Exercise: 3
----------------------------------------------------------------------


library IEEE;
use IEEE.std_logic_1164.ALL;
use IEEE.std_LOGIC_arith.ALL;
use IEEE.std_logic_unsigned.ALL;

entity MemProgPlantilla is
	port (
		MemProgAddr : in std_logic_vector(31 downto 0); -- Address of the program memory
		MemProgData : out std_logic_vector(31 downto 0) -- Operation code
	);
end MemProgPlantilla;

architecture Simple of MemProgPlantilla is

begin

	LecturaMemProg: process(MemProgAddr)
	begin
		-- The memory gives back a value for each address.
		-- These values are the program codes for each instruction,
		-- which are located in its address.
		case MemProgAddr is
		-------------------------------------------------------------
		-- Only introduce changes from here!!		
		
			-- For each instruction in.text, we add a line as:
			-- when DIRECCION => MemProgData <= INSTRUCCION;
			-- For example, of the position 0x00000000 shuld be save the instruction with machine code 0x20010004, it is:
			--when X"00000000" => MemProgData <= X"20010004";
		-- Until here!	
		---------------------------------------------------------------------	

			when X"00000000" => MemProgData <= X"8c042000";
			when X"00000004" => MemProgData <= X"00842020";
			when X"00000008" => MemProgData <= X"00842020";
			when X"0000000C" => MemProgData <= X"30a50000";
			  
			when X"00000010" => MemProgData <= X"10850008";
			when X"00000014" => MemProgData <= X"8ca12004";
			when X"00000018" => MemProgData <= X"8ca2201c";
			when X"0000001C" => MemProgData <= X"00421020";
			  
			when X"00000020" => MemProgData <= X"00421020";
			when X"00000024" => MemProgData <= X"00221820";
			when X"00000028" => MemProgData <= X"aca32034";
			when X"0000002C" => MemProgData <= X"20a50004";
			  
			when X"00000030" => MemProgData <= X"08000004";
			when X"00000034" => MemProgData <= X"0800000d";
			when others => MemProgData <= X"00000000"; -- Rest of empty memory
			  
		end case;
	end process LecturaMemProg;

end Simple;

