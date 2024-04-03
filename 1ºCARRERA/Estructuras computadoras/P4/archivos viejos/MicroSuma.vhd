----------------------------------------------------------------------
-- File: MicroSuma.vhd
-- Description: Simplified Micro MIPS, only addition with immediate data
-- Date last modification: 2019-02-22
-- Authors: 
-- Sbuject: Sbuject: C.E. 1st grade
-- Laboratory group:
-- Theory group:
-- Task: 2
-- Exercise: 3
----------------------------------------------------------------------



library IEEE;
use IEEE.std_logic_1164.ALL;
use IEEE.std_LOGIC_arith.ALL;
use IEEE.std_logic_unsigned.ALL;

entity MicroSuma is
	port (
		Clk : in std_logic; -- Clock
		NRst : in std_logic; -- Reset active low level
		MemProgAddr : out std_logic_vector(31 downto 0); -- Address for the program memory
		MemProgData : in std_logic_vector(31 downto 0) -- Operation code
	);
	end MicroSuma;

architecture Practica of MicroSuma is

	-- Declaration of RegsMIPS
	component RegsMIPS port (
		Clk : in std_logic; -- Clock
		NRst : in std_logic; -- Asynchronous Reset in low level
		A1 : in std_logic_vector(4 downto 0); -- Address for the port Rd1
		A2 : in std_logic_vector(4 downto 0); -- Address for the port Rd2
		A3 : in std_logic_vector(4 downto 0); -- Address for the port Wd3
		Wd3 : in std_logic_vector(31 downto 0); -- Input data Wd3
		We3 : in std_logic; -- Enable of the register bank
		Rd1 : out std_logic_vector(31 downto 0); -- Data of the port Rd1
		Rd2 : out std_logic_vector(31 downto 0) -- Dataof the port Rd2
	); 
	END component;
	
	-- Declaration of ALUMIPS
	component ALUMIPS Port (
		Op1 : in std_logic_vector (31 downto 0);
		Op2 : in std_logic_vector (31 downto 0);
		ALUControl : in std_logic_vector (2 downto 0);
		Res : out std_logic_vector (31 downto 0);
		Z : out std_logic
		);
	end component;
	
	-- Declaration PC
	component sumador4 port(
  		Clk : in std_logic;
		Nrst : in std_logic;
  		Pcout : out std_logic_vector(31 downto 0)
 		);
	end component;

	-- Declaration sign extensor
	component sign_extensor port(
		datoIn: in std_logic_vector(15 downto 0);
		datoOut: out std_logic_vector(31 downto 0)
	);
	end component;
	
	-- Declaration of auxiliary signal
		
	signal Wd3 : std_logic_vector(31 downto 0);
	signal Op1 : std_logic_vector (31 downto 0);
	signal Op2 : std_logic_vector (31 downto 0);
	
	
	

begin
	
	-- Instantiation of RegMIPS
	Registro: RegsMIPS port map (
		Clk => Clk,
		Nrst => Nrst,
		A1 => MemProgData(25 downto 21),
		A2 => "00000",
		A3 => MemProgData(20 downto 16),
		Wd3 => Wd3,
		We3 => '1',
		Rd1 => Op1,
		Rd2 => open);
		
	
		
	
	-- Instantiation of ALUMIPS
	ALU: ALUMIPS port map (
		Op1 => Op1,
		Op2 => Op2,
		ALUControl => "010",
		Res => Wd3,
		Z => open );
		
	
	-- Sign Extension
	SIGNEXT: sign_extensor port map (
		datoIn => MemProgData(15 downto 0),
		datoOut => Op2 );
	
	-- PC route
	PCROUTE: sumador4 port map (
		Nrst => Nrst,
		Clk => Clk,
		Pcout => MemProgAddr ); 
	

end Practica;
