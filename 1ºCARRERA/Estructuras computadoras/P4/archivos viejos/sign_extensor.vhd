library IEEE;
use IEEE.std_logic_1164.ALL;
use IEEE.std_LOGIC_arith.ALL;
use IEEE.std_logic_unsigned.ALL;

entity sign_extensor is
	port (
		datoIn: in std_logic_vector(15 downto 0);
		datoOut: out std_logic_vector(31 downto 0)
	);
end sign_extensor;

architecture extensor of sign_extensor is

begin

	datoOut(31 downto 16) <=  (others => datoIn(15)); 
	datoOut (15 downto 0) <= datoIn;

end extensor;




