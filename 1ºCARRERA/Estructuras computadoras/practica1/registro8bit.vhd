---------------------------------------------------------------------------------
-- File: Registro.vhd
-- Description: 1 bit register with Chip Enable
-- Last modification date: 2019-01-23

-- Authors: Sofia Martínez (2019), Alberto Sánchez (2012), Fernando López (2010) 
-- Subject: C.E. 1º grade
-- Laboratory group:
-- Theory group:
-- Task: 1
-- Exercise: 2
---------------------------------------------------------------------------------


library IEEE;
use IEEE.std_logic_1164.ALL;
use IEEE.std_LOGIC_arith.ALL;
use IEEE.std_logic_unsigned.ALL;


--Entity definition
--The register has a data input (D), a Reset input, CLK and CE
-- And one bit output (Q)
entity Registro8bit is
    port ( 
		D : in  std_logic_vector (7 downto 0);
		Reset : in  std_logic;
		Clk : in  std_logic;
		Ce : in  std_logic;
		Q : out  std_logic_vector (7 downto 0)
	);
end Registro8bit;


architecture Practica of Registro8bit is 
	
	component Registro port 
	(
		D : in  std_logic;
		Reset : in  std_logic;
		Clk : in  std_logic;
		Ce : in  std_logic;
		Q : out  std_logic);
	end component;
	
	begin
		r1: Registro port map (D => D(0), Reset => Reset, Clk => Clk, Ce => Ce, Q => Q(0));
		r2: Registro port map (D => D(1), Reset => Reset, Clk => Clk, Ce => Ce, Q => Q(1));
		r3: Registro port map (D => D(2), Reset => Reset, Clk => Clk, Ce => Ce, Q => Q(2));
		r4: Registro port map (D => D(3), Reset => Reset, Clk => Clk, Ce => Ce, Q => Q(3));
		r5: Registro port map (D => D(4), Reset => Reset, Clk => Clk, Ce => Ce, Q => Q(4));
		r6: Registro port map (D => D(5), Reset => Reset, Clk => Clk, Ce => Ce, Q => Q(5));
		r7: Registro port map (D => D(6), Reset => Reset, Clk => Clk, Ce => Ce, Q => Q(6));
		r8: Registro port map (D => D(7), Reset => Reset, Clk => Clk, Ce => Ce, Q => Q(7));
	
end Practica;

