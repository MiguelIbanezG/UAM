--------------------------------------------------------------------------------
-- Copyright (c) 1995-2013 Xilinx, Inc.  All rights reserved.
--------------------------------------------------------------------------------
--   ____  ____ 
--  /   /\/   / 
-- /___/  \  /    Vendor: Xilinx 
-- \   \   \/     Version : 14.7
--  \   \         Application : sch2hdl
--  /   /         Filename : p1ej3b.vhf
-- /___/   /\     Timestamp : 10/14/2020 20:16:21
-- \   \  /  \ 
--  \___\/\___\ 
--
--Command: sch2hdl -intstyle ise -family spartan3 -flat -suppress -vhdl "C:/Users/migue/OneDrive/Escritorio/1 DE CARRERA/Fundamento de Computadoras/ZXRTHSRXT/p1ej3b.vhf" -w "C:/Users/migue/OneDrive/Escritorio/1 DE CARRERA/Fundamento de Computadoras/ZXRTHSRXT/p1ej3b.sch"
--Design Name: p1ej3b
--Device: spartan3
--Purpose:
--    This vhdl netlist is translated from an ECS schematic. It can be 
--    synthesized and simulated, but it should not be modified. 
--

library ieee;
use ieee.std_logic_1164.ALL;
use ieee.numeric_std.ALL;
library UNISIM;
use UNISIM.Vcomponents.ALL;

entity p1ej3b is
   port ( A : in    std_logic; 
          B : in    std_logic; 
          C : in    std_logic; 
          Z : out   std_logic);
end p1ej3b;

architecture BEHAVIORAL of p1ej3b is
   attribute BOX_TYPE   : string ;
   signal XLXN_1 : std_logic;
   signal XLXN_2 : std_logic;
   signal XLXN_3 : std_logic;
   signal XLXN_5 : std_logic;
   component NOR2
      port ( I0 : in    std_logic; 
             I1 : in    std_logic; 
             O  : out   std_logic);
   end component;
   attribute BOX_TYPE of NOR2 : component is "BLACK_BOX";
   
begin
   XLXI_1 : NOR2
      port map (I0=>XLXN_1,
                I1=>XLXN_2,
                O=>Z);
   
   XLXI_2 : NOR2
      port map (I0=>XLXN_5,
                I1=>XLXN_3,
                O=>XLXN_2);
   
   XLXI_3 : NOR2
      port map (I0=>C,
                I1=>XLXN_5,
                O=>XLXN_1);
   
   XLXI_4 : NOR2
      port map (I0=>A,
                I1=>A,
                O=>XLXN_3);
   
   XLXI_5 : NOR2
      port map (I0=>B,
                I1=>B,
                O=>XLXN_5);
   
end BEHAVIORAL;


