----------------------------------------------------------------------
-- File: sumador4.vhd
-- Description: Register bank of the microprocessor MIPS
-- Date last modification: 2019-02-22

-- Authors: 
-- Sbuject: Sbuject: C.E. 1st grade
-- Laboratory group:
-- Theory group:
-- Task: 2
-- Exercise: 1
----------------------------------------------------------------------


library IEEE;
use IEEE.std_logic_1164.all;
use IEEE.std_logic_unsigned.all;
use IEEE.std_logic_arith.all;

entity sumador4 is port(
  Clk : in std_logic;
  Nrst : in std_logic;
  Pcout : out std_logic_vector(31 downto 0)
  );
end sumador4;

architecture sumador of sumador4 is 
  
  signal res : std_logic_vector(31 downto 0) := (others => '0');
  
  begin
  
  Pcout <= res;
  
  process(Clk, Nrst) begin
    if Nrst = '0' then 
	res <= (others => '0');
    elsif rising_edge(Clk) then 
      res <= res + 4;
    end if;
  end process;
  
end architecture; 