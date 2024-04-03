library IEEE;
use IEEE.std_logic_1164.ALL;
use IEEE.std_LOGIC_arith.ALL;
use IEEE.std_logic_unsigned.ALL;

entity zero_extensor is
	port( 
		datoIn: in std_logic_vector(15 downto 0);
		datoOut: out std_logic_vector(31 downto 0)
		);
end zero_extensor;

architecture ext of zero_extensor is 
	begin
		datoOut(31 downto 16) <= (others => '0');
		datoOut(15 downto 0) <= datoIn; 
	end architecture;