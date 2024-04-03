----------------------------------------------------------------------
----------------------------------------------------------------------
-- Asignatura: Estructura de computadores
-- Fichero: MicroSuma.vhd
-- Descripci�n: Micro MIPS muy simplificado, s�lo suma un registro con un dato inmediato
-- Fichero de apoyo para: Pr�ctica: 2. Ejercicio: 3
----------------------------------------------------------------------
----------------------------------------------------------------------

library IEEE;
use IEEE.std_logic_1164.all;
use IEEE.numeric_std.all;

entity MicroSuma is
	port (
		Clk : in std_logic; -- Reloj
		NRst : in std_logic; -- Reset activo a nivel bajo
		MemProgAddr : out unsigned(31 downto 0); -- Direcci�n para la memoria de programa
		MemProgData : in unsigned(31 downto 0) -- C�digo de operaci�n
	);
	end MicroSuma;

architecture Practica of MicroSuma is

	-- Declaraci�n de RegsMIPS
Component RegsMIPS is
	port (
		Clk : in std_logic; -- Reloj
		NRst : in std_logic; -- Reset as�ncrono a nivel bajo
		A1 : in unsigned(4 downto 0); -- Direcci�n para el puerto Rd1
		Rd1 : out signed(31 downto 0); -- Dato del puerto Rd1
		A2 : in unsigned(4 downto 0); -- Direcci�n para el puerto Rd2
		Rd2 : out signed(31 downto 0); -- Dato del puerto Rd2
		A3 : in unsigned(4 downto 0); -- Direcci�n para el puerto Wd3
		Wd3 : in signed(31 downto 0); -- Dato de entrada Wd3
		We3 : in std_logic -- Habilitaci�n del banco de registros
	);
end Component;
	
	-- Declaraci�n de ALUMIPS
Component ALUMIPS is
	port(
   		Op1 : in signed(31 downto 0);
		Op2 : in signed(31 downto 0);
		ALUControl : in std_logic_vector (2 downto 0);
		Res : out signed(31 downto 0);
		Z : out std_logic
		);
end Component;
		
	-- Declaraci�n de se�ales auxiliares
	signal Op1_aux, ALUC, ExtSig : signed(31 downto 0); 
	signal PC : unsigned(31 downto 0);
	signal Z_aux : std_logic;

begin

	-- Instancia de RegMIPS
	GPR: RegsMIPS port map(
			Clk => Clk, NRst => NRst, A1 => MemProgData(25 downto 21), Rd1 => Op1_aux, 
			A2 => MemProgData(20 downto 16), Rd2 => open, A3 => MemProgData(20 downto 16), Wd3 => ALUC, We3 => '1' );	
	-- Instancia de ALUMIPS
	ALU: ALUMIPS port map(
			Op1 => Op1_aux, Op2 => ExtSig, ALUControl => "010", Res => ALUC, Z => Z_aux );
	
	-- Extensi�n de signo
		ExtSig <= signed(resize(MemProgData(15 downto 0), 32)) ; 

	-- Ruta del PC
	process(all)
	begin
	if Nrst = '0' then 
		PC <= (others => '0');
	elsif rising_edge(clk) then
		PC <= PC + 4;
	end if;
	end process;	

	MemProgAddr <= PC;



end Practica;

