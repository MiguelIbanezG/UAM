--------------------------------------------------------------------------------
-- Copyright (c) 1995-2013 Xilinx, Inc.  All rights reserved.
--------------------------------------------------------------------------------
--   ____  ____ 
--  /   /\/   / 
-- /___/  \  /    Vendor: Xilinx 
-- \   \   \/     Version : 14.7
--  \   \         Application : sch2hdl
--  /   /         Filename : p1ej3a.vhf
-- /___/   /\     Timestamp : 10/14/2020 20:03:15
-- \   \  /  \ 
--  \___\/\___\ 
--
--Command: sch2hdl -intstyle ise -family spartan3 -flat -suppress -vhdl "C:/Users/migue/OneDrive/Escritorio/1 DE CARRERA/Fundamento de Computadoras/SZRT6HSR/p1ej3a.vhf" -w C:/Users/migue/Downloads/p1ej3a.sch
--Design Name: p1ej3a
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

entity p1ej3a is
   port ( A : in    std_logic; 
          B : in    std_logic; 
          C : in    std_logic; 
          Z : out   std_logic);
end p1ej3a;

architecture BEHAVIORAL of p1ej3a is
   attribute BOX_TYPE   : string ;
   signal XLXN_1 : std_logic;
   signal XLXN_2 : std_logic;
   signal XLXN_3 : std_logic;
   signal XLXN_7 : std_logic;
   signal XLXN_8 : std_logic;
   component AND2
      port ( I0 : in    std_logic; 
             I1 : in    std_logic; 
             O  : out   std_logic);
   end component;
   attribute BOX_TYPE of AND2 : component is "BLACK_BOX";
   
   component OR3
      port ( I0 : in    std_logic; 
             I1 : in    std_logic; 
             I2 : in    std_logic; 
             O  : out   std_logic);
   end component;
   attribute BOX_TYPE of OR3 : component is "BLACK_BOX";
   
   component INV
      port ( I : in    std_logic; 
             O : out   std_logic);
   end component;
   attribute BOX_TYPE of INV : component is "BLACK_BOX";
   
begin
   XLXI_1 : AND2
      port map (I0=>XLXN_8,
                I1=>C,
                O=>XLXN_1);
   
   XLXI_2 : AND2
      port map (I0=>XLXN_7,
                I1=>A,
                O=>XLXN_2);
   
   XLXI_3 : AND2
      port map (I0=>XLXN_7,
                I1=>XLXN_8,
                O=>XLXN_3);
   
   XLXI_4 : OR3
      port map (I0=>XLXN_3,
                I1=>XLXN_2,
                I2=>XLXN_1,
                O=>Z);
   
   XLXI_5 : INV
      port map (I=>A,
                O=>XLXN_8);
   
   XLXI_6 : INV
      port map (I=>B,
                O=>XLXN_7);
   
end BEHAVIORAL;


