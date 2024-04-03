----------------------------------------------------------------------
-- Fichero: Registro.vhd
-- Descripción: Registro de 1 bit con Chip Enable
-- Fecha última modificación: 2020-01-29

-- Autores: Sofia Martínez (2020),Alberto Sánchez (2012), Fernando López (2010) 
-- Asignatura: E.C. 1º grado
-- Grupo de Prácticas:
-- Grupo de Teoría:
-- Práctica: 1
-- Ejercicio: 2
----------------------------------------------------------------------


library IEEE;
use IEEE.std_logic_1164.ALL;
use IEEE.numeric_std.ALL;


--Definición de la entidad
--El registro tiene una entrada de datos (D), entrada de Reset, CLK y CE
--Como salida tiene un sólo bit (Q)

entity Registro is
    port ( 
		D : in  std_logic_vector (7 downto 0);
		Reset : in  std_logic;
		Clk : in  std_logic;
		Ce : in  std_logic;
		Q : out  std_logic_vector (7 downto 0)
	);
end Registro;

architecture Practica of Registro is
	
begin

	--El registro es sensible al Reset (asíncrono) y a la señal del reloj
	process (all)
	begin
		-- Si el reset está activo la salida vale 0
		if Reset = '1' then
			Q <= (others => '0');
		-- Si hay un flanco de subida del reloj
		elsif rising_edge (Clk) then
			-- Si el chip enable está activo
			if Ce = '1' then
				Q <= D;
			end if;
		end if;
	end process;

end Practica;
