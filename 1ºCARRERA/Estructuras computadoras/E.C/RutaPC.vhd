----------------------------------------------------------------------------------
----------------------------------------------------------------------------------
-- Asignatura: Estructura de Computadores
-- Fichero: RutaPC.vhd
-- Descripción: Diseño de la ruta del PC para un microprocesador (No es MIPS)
-- Fichero de apoyo para la evalucion de la práctica 2. MODELO A
----------------------------------------------------------------------------------
----------------------------------------------------------------------------------

library IEEE;
use IEEE.std_logic_1164.all;
use IEEE.numeric_std.all;


entity RutaPC is
	port (
		Clk : in std_logic; 
		Reset : in std_logic; 
		PC_out : out unsigned(23 downto 0) );
end RutaPC;


architecture examen of RutaPC is

signal pc : unsigned(23 downto 0) ;


begin 

	process (all)
	begin
		if Reset = '1' then
			pc <= (others => '0');
		elsif rising_edge(clk) then 
			pc <= pc + 3;
		end if;
	end process;

	pc_out <= pc ;

end examen;
