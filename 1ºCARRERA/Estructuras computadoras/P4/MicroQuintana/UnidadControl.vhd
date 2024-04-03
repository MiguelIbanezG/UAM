----------------------------------------------------------------------
-- File: UnidadContros
-- Description: Template for the control unit for the mips processor
-- Date last modification: 2019-03-29

-- Authors: Pablo Izaguirre and Pablo Quintanilla
-- Sbuject: Sbuject: C.E. 1st grade
-- Laboratory group:
-- Theory group: 
-- Task: 4
-- Exercise: 3
----------------------------------------------------------------------


library IEEE;
use IEEE.std_logic_1164.ALL;

entity UnidadControl is
	port (
		OPCode : in std_logic_vector(5 downto 0);
		Funct : in std_logic_vector(5 downto 0);
		ALUControl : out std_logic_vector(2 downto 0);
		MemToReg : out std_logic;
		MemWrite : out std_logic;
		Branch : out std_logic;
		ALUSrc : out std_logic;
		RegDest : out std_logic;
		RegWrite : out std_logic;
		ExtCero : out std_logic;
		Jump : out std_logic
	);
end UnidadControl;


architecture Simple of UnidadControl is

begin
	MemToReg <= '1' when OPCode = "100011" else '0';
	MemWrite <= '1' when OPCode = "101011" else '0';
	Branch <= '1' when OPCode = "000100" else '0';
	
	ALUControl <= 	"010" when OPCode = "100011" or	OPCode = "101011" or OPCode = "001000" else
					"110" when OPCode = "000100" else
					"001" when OPCode = "001101" else
					"000" when OPCode = "001100" else
					"000" when OPCode = "000000" and Funct = "100100" else
					"010" when OPCode = "000000" and Funct = "100000" else
					"110" when OPCode = "000000" and Funct = "100010" else
					"101" when OPCode = "000000" and Funct = "100111" else
					"001" when OPCode = "000000" and Funct = "100101" else "111";
	
	ALUSrc <= '0' when OPCode = "000000" or OPCode = "000100" else '1';
	RegDest <= '1' when OPCode = "000000" else '0';
	RegWrite <= '0' when OPCode = "101011" or OPCode = "000100" or OPCode = "000010" else '1';
	ExtCero <= '1' when OPCode = "001100" or OPCode = "001101" else '0';
	Jump <= '1' when OPCode = "000010" else '0';
	  
  
end Simple;