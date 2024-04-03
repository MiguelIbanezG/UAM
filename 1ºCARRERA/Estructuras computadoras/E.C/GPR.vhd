----------------------------------------------------------------------------------
----------------------------------------------------------------------------------
-- Asignatura: Estructura de Computadores
-- Fichero: GPR.vhd
-- Descripci�n: Dise�o del banco de registros de un microprocesador uniciclo (NO es MIPS)
-- Fichero de apoyo para la evaluaci�n de la practica 2. MODELO A
--
-- NOMBRE Y APELLIDOS DEL ESTUDIANTE: Miguel Ib��ez  
--
----------------------------------------------------------------------------------
----------------------------------------------------------------------------------

library IEEE;
use IEEE.std_logic_1164.all;
use IEEE.numeric_std.all;
						

entity GPR is
	port (
		Clk : in std_logic; -- Reloj
		Reset : in std_logic; -- Reset as�ncrono a nivel alto
		-- Un puerto de lectura
		R : in unsigned(3 downto 0); -- Seleccion de regsitro de lectura
		Leer : out signed(23 downto 0); -- Dato que se obtiene en la operaci�n de lectura
		-- Un puerto de escritura		
		W : in unsigned(3 downto 0); -- Seleccion de regsitro de escritura
		Escribir : in signed(23 downto 0); -- Dato que se escribe en l GPR en una operaci�n de escritura
		We : in std_logic -- Habilitaci�n del GPR para la escritura
	); 
end GPR;

architecture Examen of GPR is

type regs_t is array (0 to 15) of signed(23 downto 0);
	
----------------------------------------------------------------------------------------
----------------------------------------------------------------------------------------
	-- EVALUABLE EN EL EXAMEN: Definicion de las se�ales auxiliares necesarias
----------------------------------------------------------------------------------------
----------------------------------------------------------------------------------------	
signal regs : regs_t;

begin  

process (all)
begin
	if Reset = '1' then
		for i in 0 to 15 loop
			regs(i) <= (others => '0');
		end loop;
	elsif (rising_edge(Clk) and We = '1' and W /= 0) then
		regs(to_integer(W)) <= Escribir;
	end if;
end process;

Leer <= regs(to_integer(R)); 

----------------------------------------------------------------------------------------
----------------------------------------------------------------------------------------
	-- EVALUABLE EN EL EXAMEN: Puerto de escritura del GPR
		-- Tiene un reset as�ncrono activo en alto que inicializa todos los registros la valor cero. 
		-- En el flanco ascendente de la se�al "clk": 
			-- Si la se�al "We" est� activa, escribe la se�al "Escribir" en el registro indicado por "W"
		-- En el registro R0, nunca se puede escribir
----------------------------------------------------------------------------------------
----------------------------------------------------------------------------------------

	
	
	
	
	


----------------------------------------------------------------------------------------
----------------------------------------------------------------------------------------
	-- EVALUABLE EN EL EXAMEN: Puerto de lectura del GPR
		-- Operaci�n combinacional. 
		-- Lee del registro indicado por "R" un valor que asocia a la se�al "Leer"
		-- La lectura del registro R0, siempre debe ser cero
----------------------------------------------------------------------------------------
----------------------------------------------------------------------------------------

	


end examen;

