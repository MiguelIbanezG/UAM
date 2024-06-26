library IEEE;
use IEEE.std_logic_1164.ALL;
use IEEE.std_LOGIC_arith.ALL;
use IEEE.std_logic_unsigned.ALL;

entity mux2a1_5 is
	port(
		control: in std_logic;
		dato0: in std_logic_vector(4 downto 0);
		dato1: in std_logic_vector(4 downto 0);
		datoOut: out std_logic_vector(4 downto 0)
		);
end mux2a1_5;

architecture mux of mux2a1_5 is
	begin	
		datoOut <= dato0 when control = '0' else dato1;
end architecture;