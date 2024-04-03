----------------------------------------------------------------------
-- Fichero: MicroSuma.vhd
-- Descripci�n: Micro MIPS muy simplificado, s�lo suma con dato inmediato
-- Fecha �ltima modificaci�n: 

-- Autores: Alberto S�nchez (2012), �ngel de Castro (2011) 
-- Asignatura: E.C. 1� grado
-- Grupo de Pr�cticas:
-- Grupo de Teor�a:
-- Pr�ctica: 2
-- Ejercicio: 3
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

	-- Declaraci�n de RegMIPS
	component RegsMIPS
	port(
		D : in  std_logic_vector (7 downto 0);
		Reset : in  std_logic;
		Clk : in  std_logic;
		Ce : in  std_logic;
		Q : out  std_logic_vector (7 downto 0)
	);

	-- Declaraci�n de ALUMIPS
	component ALUMIPS
	port(
		Op1 : in signed(31 downto 0);
		Op2 : in signed(31 downto 0);
		ALUControl : in std_logic_vector (2 downto 0);
		Res : out signed(31 downto 0);
		Z : out std_logic
	);
	-- Declaraci�n de se�ales auxiliares
	
begin

	-- Instancia de RegMIPS
	GPR: RegsMIPS port map(
			Clk => Clk
			NRst => Nrst
			A1 => rs
			Rd1 => aux_data1
			A2 => "00000"
			Rd2 => open
			A3 => rt
			Wd3 => aux_resul_ALU
			We3 => '1'  );
	-- Instancia de ALUMIPS
	GPR: RegsMIPS port map(
			Op1 => aux_data1
			Op2 => exit_sigmed (imm)
			ALUControl => "010"
			Res => aux_resul_ALU
			Z => open );

	-- Extensi�n de signo
		
	-- Ruta del PC

end Practica;

