library IEEE;
use IEEE.std_logic_1164.ALL;
use IEEE.std_LOGIC_arith.ALL;
use IEEE.std_logic_unsigned.ALL;

entity UnidadControl is
	port (
		OPCode : in std_logic_vector(5 downto 0); 
		Funct : in std_logic_vector(5 downto 0);
		MemToReg : out std_logic;
		MemWrite : out std_logic;
		Branch : out std_logic;
		ALUControl : out std_logic_vector(2 downto 0);
		ALUSrc : out std_logic;
		RegDest : out std_logic;
		RegWrite : out std_logic;
		ExtCero : out std_logic;
		Jump : out std_logic 
	);
end UnidadControl;

architecture Func of UnidadControl is
	signal aux : std_logic_vector(2 downto 0);
begin
  
  with OPCode select
    MemToReg <= '0' when "000000", --Rtype
                '1' when "100011", --lw
                'U' when "101011", --sw
                'U' when "000100", --beq
                '0' when "001101", --ori
                '0' when "001100", --andi
                '0' when "001000", --addi 
                '0' when "001010", --slti             
                'U' when others;   --j
                
  with OPCode select
    MemWrite <= '0' when "000000", --Rtype
                '0' when "100011", --lw
                '1' when "101011", --sw
                '0' when "000100", --beq
                '0' when "001101", --ori
                '0' when "001100", --andi
                '0' when "001000", --addi 
                '0' when "001010", --slti             
                '0' when "000010", --j 
                'U' when  others;   
  
  
  with OPCode select
    Branch   <= '0' when "000000", --Rtype
                '0' when "100011", --lw
                '0' when "101011", --sw
                '1' when "000100", --beq
                '0' when "001101", --ori
                '0' when "001100", --andi
                '0' when "001000", --addi 
                '0' when "001010", --slti             
                'U' when "000010", --j 
                'U' when  others;  
  with OPCode select
    ALUSrc   <= '0' when "000000", --Rtype
                '1' when "100011", --lw
                '1' when "101011", --sw
                '0' when "000100", --beq
                '1' when "001101", --ori
                '1' when "001100", --andi
                '1' when "001000", --addi 
                '1' when "001010", --slti             
                'U' when "000010", --j 
                'U' when  others;    
                
  with OPCode select
    RegDest  <= '1' when "000000", --Rtype
                '0' when "100011", --lw
                'U' when "101011", --sw
                'U' when "000100", --beq
                '0' when "001101", --ori
                '0' when "001100", --andi
                '0' when "001000", --addi 
                '0' when "001010", --slti             
                'U' when "000010", --j 
                'U' when  others;                
                
  with OPCode select
    RegWrite <= '1' when "000000", --Rtype
                '1' when "100011", --lw
                '0' when "101011", --sw
                '0' when "000100", --beq
                '1' when "001101", --ori
                '1' when "001100", --andi
                '1' when "001000", --addi 
                '1' when "001010", --slti             
                '0' when "000010", --j 
                'U' when  others;  		
  with OPCode select
    ExtCero  <= 'U' when "000000", --Rtype
                '0' when "100011", --lw
                '0' when "101011", --sw
                'U' when "000100", --beq
                '1' when "001101", --ori
                '1' when "001100", --andi
                '0' when "001000", --addi 
                '0' when "001010", --slti             
                'U' when "000010", --j 
                'U' when  others;  				
  
  with OPCode select
    Jump     <= '0' when "000000", --Rtype
                '0' when "100011", --lw
                '0' when "101011", --sw
                '0' when "000100", --beq
                '0' when "001101", --ori
                '0' when "001100", --andi
                '0' when "001000", --addi 
                '0' when "001010", --slti             
                '1' when "000010", --j 
                'U' when  others;   
				
  with Funct select
    aux  	<= "000" when "100100", --and
		   "010" when "100000", --add
		   "110" when "100010", --sub
                   "101" when "100111", --nor
                   "001" when "100101", --or
                   "111" when "101010", --slt
                   "UUU"   when  others;   					
				
				
  with OPCode select
    ALUControl  <= aux   when "000000", --Rtype
		   "010" when "100011", --lw
		   "010" when "101011", --sw
                   "110" when "000100", --beq
                   "001" when "001101", --ori
                   "000" when "001100", --andi
                   "010" when "001000", --addi 
                   "111" when "001010", --slti             
                   "UUU"   when "000010", --j 
                   "UUU"   when  others;   				
end architecture;  