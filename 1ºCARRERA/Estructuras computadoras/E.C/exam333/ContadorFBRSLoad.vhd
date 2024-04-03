----------------------------------------------------------------------
-- ¡IMPORTANTE! Rellene la cabecera del fichero
-- Fecha:
-- Autores:
----------------------------------------------------------------------

library IEEE;
use IEEE.std_logic_1164.ALL;
use IEEE.numeric_std.ALL;


entity ContadorFBRSLoad is
    port ( 
		Clk : IN  std_logic;
		Reset : IN  std_logic;
		Load : IN std_logic;
		D : IN unsigned(9 downto 0);
		Q : OUT  unsigned(9 downto 0)
	);
end ContadorFBRSLoad;

architecture Practica of ContadorFBRSLoad is
	
begin

	process(all)
	begin
		if rising_edge(Clk) then
			if Reset = '1' then
				Q <= (others => '0');
				if Load = '1' then
					Q <= D;
				else
					Q <= Q+1;
				end if;
			end if;
		end if;

	end process;	
end Practica;