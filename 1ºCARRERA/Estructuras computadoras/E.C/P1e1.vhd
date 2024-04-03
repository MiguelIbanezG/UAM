library IEEE;
use IEEE.std_logic_1164.ALL;
use IEEE.std_logic_arith.ALL;
use IEEE.std_logic_unsigned.ALL;
entity P1e1 is
port (
A : in std_logic;
B : in std_logic;
C : in std_logic;
Z : out std_logic
);
end P1e1;

architecture Metodo1 of P1e1 is
signal s : std_logic;
begin
process (all)
begin
if A = '1' and B= '1' then
s <= '1';
else
s <= '0';
end if;
end process;
Z <= s xor (not C);
end Metodo1;
