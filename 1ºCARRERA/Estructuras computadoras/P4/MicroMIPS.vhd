----------------------------------------------------------------------
-- File: MicroMIPS.vhd
-- Description: microprocessor MIPS
-- Date last modification: 2019-94-10

-- Authors: Alejandro Vázquez, Fernando Peláez
-- Sbuject: Sbuject: C.E. 1st grade
-- Laboratory group: 2101
-- Theory group: 210
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
    MemProgAddr : out std_logic_vector(31 downto 0); -- Address for the program memory
	MemProgData : in std_logic_vector(31 downto 0); -- Operation code
	MemDataAddr : out std_logic_vector(31 downto 0); -- Address for the data memory
	MemDataDataRead : in std_logic_vector(31 downto 0); -- Data to read in the data memory
	MemDataDataWrite : out std_logic_vector(31 downto 0); -- Data to save in the data memory
	MemDataWE : out std_logic
	);
end MicroMIPS;

architecture BestMicroEver of MicroMips is
  
  ------------------------------------------------------
  --
  --              DECLARACIÓN COMPONENTES
  --
  ------------------------------------------------------ 
  
  --DECLARACIÓN ALU
  
  component ALUMIPS is
    port (
		Op1 : in std_logic_vector (31 downto 0);
		Op2 : in std_logic_vector (31 downto 0);
	   	ALUControl : in std_logic_vector (2 downto 0);
		Res : out std_logic_vector (31 downto 0);
		  Z : out std_logic
		  );
  end component;
  
  --DECLARACIÓN DEL BANCO DE REGISTROS
  
  component RegMIPS is
    port (
		  Clk : in std_logic; -- Clock
		  NRst : in std_logic; -- Asynchronous Reset in low level
		
		  A1 : in std_logic_vector(4 downto 0); -- Address for the port Rd1
		  Rd1 : out std_logic_vector(31 downto 0); -- Data of the port Rd1
		
		  A2 : in std_logic_vector(4 downto 0); -- Address for the port Rd2
		  Rd2 : out std_logic_vector(31 downto 0); -- Data of the port Rd2
		
		  A3 : in std_logic_vector(4 downto 0); -- Address for the port Wd3
		  Wd3 : in std_logic_vector(31 downto 0); -- Input data Wd3
		
		  We3 : in std_logic -- Enable of the register bank
	   );
  end component;
  
  --DECLARACIÓN DEL EXTENSOR DE SIGNO DEL INMEDIATO
    
  component Extensor is
    port (
      A : in std_logic_vector (15 downto 0);
      S : out std_logic_vector (31  downto 0)
      );
  end component;
  
  --DECLARACIÓN DEL EXTENSOR SIN SIGNO DEL INMEDIATO
    
  component ExtensorNOSIG is
      port (
        A : in std_logic_vector (15 downto 0);
        S : out std_logic_vector (31  downto 0)
        );
  end component;
  
  --DECLARACIÓN DE LA UNIDAD DE CONTROL
  
  component UnidadControl is
    port (
      OPCode : std_logic_vector(5 downto 0);
      Funct : std_logic_vector(5 downto 0);
      MemToReg : out std_logic;
      MemWrite : out std_logic;
      Branch : out std_logic;
      ALUControl : out std_logic_vector(2 downto 0);
      ALUSrc : out std_logic;
      RegDest : out std_logic;
      RegWrite : out std_logic;
      ExtCero: out std_logic;
      Jump : out std_logic
  );
  end component;
  --DECLARACIÓN DEL SUMADOR
    
  component sumador is
	 Port (
		  Op1 : in std_logic_vector (31 downto 0);
		  Op2 : in std_logic_vector (31 downto 0);
	 	  Res : out std_logic_vector (31 downto 0)
	 	 );
  end component;
  
  --DECLARACIÓN DEL PC
  
  component PC is
    port (
      Clk : in std_logic;
      D : in std_logic_vector (31 downto 0);
      Q : out std_logic_vector (31 downto 0)
    );
  end component;
  
  ------------------------------------------------------
  --
  --              SEÑALES AUXILIARES
  --
  ------------------------------------------------------ 
  
  --SEÑALES USADAS PARA EL BLOQUE 1
  
  signal entradaInstr : std_logic_vector (31 downto 0);
  signal SalidaInstr : std_logic_vector (31 downto 0);
  
  --SEÑALES USADAS PARA EL BLOQUE 2
  
  signal A1, A2, A3 : std_logic_vector (4 downto 0);
  signal Imm : std_logic_vector (15 downto 0);
  signal Addr : std_logic_vector (25 downto 0);
  signal Opcode : std_logic_vector (5 downto 0);
  signal func : std_logic_vector (5 downto 0);
  
  --SEÑALES USADAS PARA EL BLOQUE 3
  
  signal Rd1 : std_logic_vector (31 downto 0);
  signal Rd2 : std_logic_vector (31 downto 0);
  signal EntradaDatosPuerto3 : std_logic_vector (31 downto 0);
  
  --SEÑALES USADAS PARA EL BLOQUE 4
  
  signal SalidaImmSIGNO : std_logic_vector (31 downto 0);
  signal SalidaImmNOSIGNO : std_logic_vector (31 downto 0);
  
  --SEÑALES USADAS PARA EL BLOQUE 5
  
  signal LlegadaOp2 : std_logic_vector (31 downto 0);
  signal Zero : std_logic;
  signal ResultadoALU : std_logic_vector (31 downto 0);
  
  --SEÑALES USADAS PARA EL BLOQUE 6
  
  signal SalidaDatos : std_logic_vector (31 downto 0);
  
  --SEÑALES USADAS PARA EL BLOQUE 7
  
  signal entradaOp1 : std_logic_vector (31 downto 0);
  signal BTA : std_logic_vector (31 downto 0);
  
  --SEÑALES USADAS PARA EL BLOQUE 8
  
  signal JTA : std_logic_vector (31 downto 0);
  
  --SEÑALES USADAS PARA EL BLOQUE 9
  
  signal PCmas4 : std_logic_vector (31 downto 0);
  signal solo4 : std_logic_vector (31 downto 0);
  signal EntradaPC : std_logic_vector (31 downto 0);
  signal PCSrc : std_logic;
  
  --SEÑALES USADAS PARA EL BLOQUE 10
  
  signal MemtoReg, MemWrite, Branch, ALUSrc, RegDest, RegWrite, ExtCero, Jump : std_logic;
  signal ALUControl : std_logic_vector (2 downto 0);
  
  ------------------------------------------------------
  --
  --              INICIO DEL BEGIN
  --
  ------------------------------------------------------ 
  
  begin
    
    --BLOQUE 1: MEMORIA DE INSTRUCCIONES CON SALIDAS Y ENTRADAS
    
    
    MemProgAddr <= entradaInstr;
    MemProgData <= SalidaInstr;
    
    
    --BLOQUE 2: REDISTRIBUCIÓN DE LA SALIDA DE LA MEMORIA DE INSTRUCCIONES
    
    OPcode <= SalidaInstr (31 downto 26);
    func <= SalidaInstr (5 downto 0);
    A1 <= SalidaInstr (25 downto 21);
    A2 <= SalidaInstr (20 downto 16);
    A3 <= SalidaInstr (20 downto 16) when RegDest = '0' else SalidaInstr (15 downto 11) when RegDest = '1';
    Imm <= SalidaInstr (15 downto 0);
    Addr <= SalidaInstr (25 downto 0);
    
    --BLOQUE 3: BANCO DE REGISTROS
    
    EntradaDatosPuerto3 <= ResultadoALU when MemToReg = '0' else SalidaDatos;
    
    BancoDeRegistros : RegMIPS port map (
		  Clk => Clk,
		  NRst => NRst,
		
		  A1 => A1,
		  Rd1 => Rd1,
		
		  A2 => A2,
		  Rd2 => Rd2,
		
		  A3 => A3,
		  Wd3 => EntradaDatosPuerto3,
		
		  We3 => RegWrite
		);
		
		--BLOQUE 4: EXTENSORES DE SIGNO Y  SIN SIGNO
		
		Signo : Extensor port map (
      A => Imm,
      S => SalidaImmSIGNO
    );
    
    NOSigno : ExtensorNOSIG port map (
        A =>Imm,
        S => SalidaImmNOSIGNO
    );
    
    --BLOQUE 5: ALU
    
    LlegadaOp2 <= Rd2 when AluSrc = '0' else SalidaImmSIGNO when ExtCero = '0' else SalidaImmNOSIGNO;
    
    ALU : ALUMIPS port map (
		Op1 => Rd1,
		Op2 => LLegadaOp2,
	   	ALUControl => ALUControl,
		Res => ResultadoALU,
		Z => Zero
		);
		
		--BLOQUE 6: MEMORIA DE DATOS
		
		MemDataAddr <= ResultadoALU;
		MemDataDataWrite <= Rd2;
		MemDataWE <= MemWrite;
		MemDataDataRead <= SalidaDatos;
	  
    
    --BLOQUE 7: OBTENCIÓN DEL BTA
    
    entradaOp1 <= SalidaImmSIGNO (29 downto 0) & "00";
    
    CalculoBTA : sumador port map (
		  Op1 => entradaOp1,
		  Op2 => PCmas4,
	 	  Res => BTA
	 	 );
	 	 
	 	--BLOQUE 8: CALCULO DEL JTA
	 	
	 	JTA <= PCmas4 (31 downto 28) & addr & "00";
	 	
	 	--BLOQUE 9: RUTA DEL PC (LOS DOS MULIS DE ARRIBA Y PCMAS4)
	 	
	 	solo4 <= "00000000000000000000000000000100";
	 	
	 	calculoPCmas4 : sumador port map (
		  Op1 => EntradaInstr,
		  Op2 => solo4,
	 	  Res => PCmas4
	 	 );
	 	
	 	PCSrc <= Branch and Zero;
	 	
	 	EntradaPC <= JTA when Jump = '1' else BTA when PCSrc = '1' else PCmas4;
	 	
	 	pcBiestable : PC port map (
      Clk => Clk,
      D => EntradaPC,
      Q => EntradaInstr
    );
    
    --BLOQUE 10: UNIDAD DE CONTROL
    
    UC : UnidadControl port map (
      OPCode => opcode,
      Funct => func,
      MemToReg => MemToReg,
      MemWrite => MemWrite,
      Branch => Branch,
      ALUControl => ALUControl,
      ALUSrc => ALUSrc,
      RegDest => RegDest,
      RegWrite => RegWrite,
      ExtCero => ExtCero,
      Jump => Jump
    );
    
end BestMicroEver;