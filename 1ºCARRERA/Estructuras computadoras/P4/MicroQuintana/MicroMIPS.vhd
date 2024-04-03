----------------------------------------------------------------------
-- File: MicroMIPS.vhd
-- Description: Template for the prorammemory MIPS
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
use IEEE.std_LOGIC_arith.ALL;
use IEEE.std_logic_unsigned.ALL;

entity MicroMIPS is
	port (
		Clk : in std_logic;
		NRst : in std_logic;
		MemProgData : in std_logic_vector(31 downto 0);
		MemDataDataRead: in std_logic_vector(31 downto 0);
		MemProgAddr : out std_logic_vector(31 downto 0); -- Address of the program memory
		MemDataWe : out std_logic;
		MemDataAddr : out std_logic_vector(31 downto 0);
		MemDataDataWrite : out std_logic_vector(31 downto 0)
	);
end MicroMIPS;

architecture MIPS of MicroMIPS is
	
	component ALUMIPS
	Port (
		Op1 : in std_logic_vector (31 downto 0);
		Op2 : in std_logic_vector (31 downto 0);
		ALUControl : in std_logic_vector (2 downto 0);
		Res : out std_logic_vector (31 downto 0);
		Z : out std_logic
		);
	end component;
	
	component RegsMIPS
	port (
		Clk : in std_logic; -- Clock
		NRst : in std_logic; -- Asynchronous Reset in low level
		A1 : in std_logic_vector(4 downto 0); -- Address for the port Rd1
		Rd1 : out std_logic_vector(31 downto 0); -- Data of the port Rd1
		A2 : in std_logic_vector(4 downto 0); -- Address for the port Rd2
		Rd2 : out std_logic_vector(31 downto 0); -- Dataof the port Rd2
		A3 : in std_logic_vector(4 downto 0); -- Address for the port Wd3
		Wd3 : in std_logic_vector(31 downto 0); -- Input data Wd3
		We3 : in std_logic -- Enable of the register bank
		); 
	end component;
	
	component UnidadControl
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
	end component;
	
	signal RD1 : std_logic_vector(31 downto 0);
	signal RD2 : std_logic_vector(31 downto 0);
	signal ALUControl : std_logic_vector(2 downto 0);
	signal MemToReg : std_logic;
	signal MemWrite : std_logic;
	signal Branch : std_logic;
	signal ALUSrc : std_logic;
	signal RegDest : std_logic;
	signal RegWrite : std_logic;
	signal ExtCero : std_logic;
	signal Jump : std_logic;
	signal Op2 : std_logic_vector(31 downto 0);
	signal Res : std_logic_vector(31 downto 0);
	signal Z : std_logic;
	signal A3 : std_logic_vector(4 downto 0);
	signal Wd3 : std_logic_vector(31 downto 0);
	signal CeroExt : std_logic_vector(31 downto 0);
	signal SignExt : std_logic_vector(31 downto 0);
	signal ALUSrc1 : std_logic_vector(31 downto 0);
	signal leftShifted : std_logic_vector(31 downto 0);
	signal Adder4 : std_logic_vector(31 downto 0);
	signal Adder : std_logic_vector(31 downto 0);
	signal PCAux : std_logic_vector(31 downto 0);
	signal Jump1 : std_logic_vector(31 downto 0);
	signal PCin : std_logic_vector(31 downto 0);
	signal PCSrc : std_logic;
	
begin

	-- Instantiation of ALU
	alu: ALUMIPS
	port map(		
		Op1 => RD1,
		Op2 => Op2,
		ALUControl => ALUControl,
		Res => Res,
		Z => Z
	);
	
	-- Instantiation of Register bank
	regs: RegsMIPS
	port map(		
		Clk => Clk,
		NRst => NRst,
		We3 => RegWrite,
		A1 => MemProgData(25 downto 21),
		A2 => MemProgData(20 downto 16),
		A3 => A3,
		Wd3 => Wd3,
		Rd1 => RD1,
		Rd2 => RD2
	);
	
	-- Instantiation of Control Unit
	cu: UnidadControl
	port map(		
		OPCode => MemProgData(31 downto 26),
		Funct => MemProgData(5 downto 0),
		
		ALUControl => ALUControl,
		MemToReg => MemToReg,
		MemWrite => MemWrite,
		Branch => Branch,
		ALUSrc => ALUSrc,
		RegDest => RegDest,
		RegWrite => RegWrite,
		ExtCero => ExtCero,
		Jump => Jump
	);
	
	-- Make connections
	A3 <= MemProgData(20 downto 16) when RegDest = '0' else MemProgData(15 downto 11);
	CeroExt <= x"0000" & MemProgData(15 downto 0);
	SignExt(31 downto 16) <= (others => MemProgData(15));
	SignExt(15 downto 0) <= MemProgData(15 downto 0);
	ALUSrc1 <= CeroExt when ExtCero = '1' else SignExt;
	Op2 <= RD2 when ALUSrc = '0' else ALUSrc1;
	MemDataAddr <= Res;
	MemDataDataWrite <= RD2;
	MemDataWe <= MemWrite;
	Wd3 <= Res when MemToReg = '0' else MemDataDataRead;
	
	--PC signals
	leftShifted <= SignExt(29 downto 0) & "00";
	Adder4 <= PCAux + 4;
	Adder <= leftShifted + Adder4;
	MemProgAddr <= PCAux;
	Jump1 <= Adder4(31 downto 28) & MemProgData(25 downto 0) & "00";
	PCSrc <= branch and Z;
	PCin <= Jump1 when Jump = '1' else Adder when PCSrc = '1' else Adder4;
	
	--PCProccess
	process(Clk, NRst)
	begin
		if NRst = '0' then
			PCAux <= (others => '0');
		elsif rising_edge(Clk) then
			PCAux <= PCin;
		end if;
	end process;
	
end MIPS;

