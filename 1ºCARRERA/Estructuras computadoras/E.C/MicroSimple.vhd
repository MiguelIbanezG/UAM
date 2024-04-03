----------------------------------------------------------------------
----------------------------------------------------------------------
-- Asignatura: Estructura de computadores
-- Fichero: MicroSimple.vhd
-- Descripci贸n: Micro muy simplificado, s贸lo suma con dato inmediato
-- Fichero de apoyo para la evaluaci贸n de la practica 2. MODELO A
--
-- NOMBRE Y APELLIDOS DEL ESTUDIANTE: Miguel Ib狁ez 
--
----------------------------------------------------------------------
----------------------------------------------------------------------

library IEEE;
use IEEE.std_logic_1164.all;
use IEEE.numeric_std.all;

entity MicroSimple is
	port (
		Clk : in std_logic; -- Reloj
		Reset : in std_logic ); -- Reset activo a nivel alto
end MicroSimple;

architecture Examen of MicroSimple is

-- Declaraci贸n del componente MemProg 
component MemProg is
	port (
		MemAddr : in unsigned(23 downto 0); -- Direcci贸n para la memoria de programa
		Instruc : out unsigned(23 downto 0) -- C贸digo de operaci贸n
	);
end component;

-- Declaraci贸n del componente RutaPC
component RutaPC is
	port (
		Clk : in std_logic; -- Reloj
		Reset : in std_logic; -- Reset as铆ncrono a nivel alto
		-- Un puerto de salida
		PC_out : out unsigned(23 downto 0) -- Se帽ala la direcci贸n de la instrucccion a ejecutar
	); 
end component;

----------------------------------------------------------------------------------------
----------------------------------------------------------------------------------------
	-- EVALUABLE EN EL EXAMEN: Declaraci贸n de la ALU
----------------------------------------------------------------------------------------
----------------------------------------------------------------------------------------





-- Declaraci贸n del componente  GPR 

component GPR is
	port (
		Clk : in std_logic; -- Reloj
		Reset : in std_logic; -- Reset as铆ncrono a nivel alto
		-- Un puerto de lectura
		R : in unsigned(3 downto 0); -- Seleccion de regsitro de lectura
		Leer : out signed(23 downto 0); -- Dato que se obtiene en la operaci贸n de lectura
		-- Un puerto de escritura		
		W : in unsigned(3 downto 0); -- Seleccion de regsitro de escritura
		Escribir : in signed(23 downto 0); -- Dato que se escribe en l GPR en una operaci贸n de escritura
		We : in std_logic -- Habilitaci贸n del GPR para la escritura
	); 
end component;

-- Declaraci贸n de se帽ales auxiliares (algunas)
signal instruc,Op1_aux,ExtSig, pc_out : unsigned (23 downto 0) ;

signal ALUC : signed (23 downto 0);





----------------------------------------------------------------------------------------
----------------------------------------------------------------------------------------
	-- EVALUABLE EN EL EXAMEN: Dise帽o de otras se帽ales auxiliares en el caso que SEAN NECESARIAS
----------------------------------------------------------------------------------------
----------------------------------------------------------------------------------------




begin

-- Instanciaci贸n de la Memoria de programa, entidad MemProg 
MEM: MemProg port map (MemAddr => pc_out, Instruc => instruc);

-- Instanciaci贸n de la ruta del PC, entidad RutaPC
RPC: RutaPC port map (Clk => clk, Reset => reset, PC_out => pc_out );

----------------------------------------------------------------------------------------
----------------------------------------------------------------------------------------
	-- EVALUABLE EN EL EXAMEN: Instanciacion del componente GPR
----------------------------------------------------------------------------------------
----------------------------------------------------------------------------------------
GPRR: GPR port map(
			Clk => Clk, Reset => Reset, Leer => open, W => instruc(15 downto 12), Escribir => ALUC, We => '1' );




----------------------------------------------------------------------------------------
----------------------------------------------------------------------------------------
	-- EVALUABLE EN EL EXAMEN: Instanciacion del componente ALU
----------------------------------------------------------------------------------------
----------------------------------------------------------------------------------------

ALUU: ALU port map(
			Op1 => Op1_aux, Op2 => ExtSig, Control => "0010", Result => ALUC);




----------------------------------------------------------------------------------------
----------------------------------------------------------------------------------------
	-- EVALUABLE EN EL EXAMEN: calculo de la se帽al de entrada al segundo operando de la ALU despu茅s de la extensi贸n de signo
----------------------------------------------------------------------------------------
----------------------------------------------------------------------------------------

 ExtSig <= signed(resize(instruc(11 downto 0), 24)) ;

process(all)
begin
	if Reset = '1' then 
		pc_out <= (others => '0');
	elsif rising_edge(clk) then
		pc_out <= ALUC;
	end if;
	end process;	
 
end Examen;


