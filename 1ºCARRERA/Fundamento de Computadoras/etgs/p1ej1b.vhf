--------------------------------------------------------------------------------
-- Copyright (c) 1995-2013 Xilinx, Inc.  All rights reserved.
--------------------------------------------------------------------------------
--   ____  ____ 
--  /   /\/   / 
-- /___/  \  /    Vendor: Xilinx 
-- \   \   \/     Version : 14.7
--  \   \         Application : sch2hdl
--  /   /         Filename : p1ej1b.vhf
-- /___/   /\     Timestamp : 10/14/2020 12:45:06
-- \   \  /  \ 
--  \___\/\___\ 
--
--Command: sch2hdl -intstyle ise -family spartan3 -flat -suppress -vhdl "C:/Users/migue/OneDrive/Escritorio/1 DE CARRERA/Fundamento de Computadoras/etgs/p1ej1b.vhf" -w C:/Users/migue/Downloads/p1ej1b.sch
--Design Name: p1ej1b
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

entity p1ej1b is
   port ( A : in    std_logic; 
          B : in    std_logic; 
          C : in    std_logic; 
          D : in    std_logic; 
          Z : out   std_logic);
end p1ej1b;

architecture BEHAVIORAL of p1ej1b is
   attribute BOX_TYPE   : string ;
   signal XLXN_2 : std_logic;
   signal XLXN_3 : std_logic;
   signal XLXN_5 : std_logic;
   signal XLXN_6 : std_logic;
   signal XLXN_7 : std_logic;
   component NAND2
      port ( I0 : in    std_logic; 
             I1 : in    std_logic; 
             O  : out   std_logic);
   end component;
   attribute BOX_TYPE of NAND2 : component is "BLACK_BOX";
   
   component NAND3
      port ( I0 : in    std_logic; 
             I1 : in    std_logic; 
             I2 : in    std_logic; 
             O  : out   std_logic);
   end component;
   attribute BOX_TYPE of NAND3 : component is "BLACK_BOX";
   
   component INV
      port ( I : in    std_logic; 
             O : out   std_logic);
   end component;
   attribute BOX_TYPE of INV : component is "BLACK_BOX";
   
begin
   XLXI_1 : NAND2
      port map (I0=>XLXN_2,
                I1=>XLXN_3,
                O=>Z);
   
   XLXI_2 : NAND2
      port map (I0=>D,
                I1=>B,
                O=>XLXN_3);
   
   XLXI_4 : NAND3
      port map (I0=>XLXN_7,
                I1=>XLXN_6,
                I2=>XLXN_5,
                O=>XLXN_2);
   
   XLXI_5 : INV
      port map (I=>A,
                O=>XLXN_5);
   
   XLXI_6 : INV
      port map (I=>C,
                O=>XLXN_6);
   
   XLXI_7 : INV
      port map (I=>D,
                O=>XLXN_7);
   
end BEHAVIORAL;


