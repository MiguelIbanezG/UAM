----------------------------------------------------------------------
----------------------------------------------------------------------
-- Asignatura: Fundamentos de Microprocesadores. Grado ITST. 2º curso.
-- Fichero: MicroSimple_Tb.vhd
-- Descripción: Archivo de simulacion para el Micro simplificado, sólo suma con dato inmediato
-- Fichero de apoyo para la evaluación de la practica 2.
----------------------------------------------------------------------
----------------------------------------------------------------------

library IEEE;
use IEEE.std_logic_1164.all;
use IEEE.numeric_std.all;

entity MicroSimple_Tb is
end MicroSimple_Tb;
 
architecture examen OF MicroSimple_Tb is
 
  -- Declaración del micro
	component MicroSimple
	port (
		Clk : in std_logic; 	-- Reloj
		Reset : in std_logic  	-- Reset activo a nivel alto
	);
	end component;


	signal reset : std_logic := '0';
	signal clk : std_logic := '0';

	constant CLKPERIOD : time := 10 ns;

	signal finSimu : boolean := false;

begin
 
	-- Instancia del micro
	uut: MicroSimple
	port map(
		CLK => clk,
		Reset => reset
	);

	CLKPROCESS: process
	begin
	while (not finSimu) loop
		clk <= '0';
		wait for CLKPERIOD/2;
		clk <= '1';
		wait for CLKPERIOD/2;
	end loop;
	wait;
	end process;

	StimProc: process
	begin
		reset <= '1'; -- Reset empieza activo
		wait for CLKPERIOD*2;
		reset <= '0'; -- Se desactiva el reset y empieza la ejecución
		wait for CLKPERIOD*6;
 
	
	report "SIMULACION COMPLETADA. Compruebe los errores cometidos y proceda a corregirlos. Compruebe que el resultado de los registros implicados sea el indicado en el archivo MemProg.vhd" severity note;
	finSimu <= true;
	wait;

	end process;


end examen;

