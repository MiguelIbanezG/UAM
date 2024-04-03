--------------------------------------------------------------------------------
-- Copyright (c) 1995-2013 Xilinx, Inc.  All rights reserved.
--------------------------------------------------------------------------------
--   ____  ____ 
--  /   /\/   / 
-- /___/  \  /    Vendor: Xilinx 
-- \   \   \/     Version : 14.7
--  \   \         Application : sch2hdl
--  /   /         Filename : p1ej1a.vhf
-- /___/   /\     Timestamp : 10/14/2020 10:53:18
-- \   \  /  \ 
--  \___\/\___\ 
--
--Command: sch2hdl -intstyle ise -family spartan3 -flat -suppress -vhdl "C:/Users/migue/OneDrive/Escritorio/1 DE CARRERA/Fundamento de Computadoras/p1ej1a/p1ej1a.vhf" -w "C:/Users/migue/OneDrive/Escritorio/1 DE CARRERA/Fundamento de Computadoras/p1ej1a/p1ej1a.sch"
--Design Name: p1ej1a
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

entity p1ej1a is
   port ( A : in    std_logic; 
          B : in    std_logic; 
          C : in    std_logic; 
          D : in    std_logic; 
          Z : out   std_logic);
end p1ej1a;

architecture BEHAVIORAL of p1ej1a is
   attribute BOX_TYPE   : string ;
   signal XLXN_1 : std_logic;
   signal XLXN_2 : std_logic;
   signal XLXN_4 : std_logic;
   signal XLXN_7 : std_logic;
   signal XLXN_8 : std_logic;
   component AND2
      port ( I0 : in    std_logic; 
             I1 : in    std_logic; 
             O  : out   std_logic);
   end component;
   attribute BOX_TYPE of AND2 : component is "BLACK_BOX";
   
   component AND3
      port ( I0 : in    std_logic; 
             I1 : in    std_logic; 
             I2 : in    std_logic; 
             O  : out   std_logic);
   end component;
   attribute BOX_TYPE of AND3 : component is "BLACK_BOX";
   
   component OR2
      port ( I0 : in    std_logic; 
             I1 : in    std_logic; 
             O  : out   std_logic);
   end component;
   attribute BOX_TYPE of OR2 : component is "BLACK_BOX";
   
   component INV
      port ( I : in    std_logic; 
             O : out   std_logic);
   end component;
   attribute BOX_TYPE of INV : component is "BLACK_BOX";
   
begin
   XLXI_1 : AND2
      port map (I0=>D,
                I1=>B,
                O=>XLXN_1);
   
   XLXI_4 : AND3
      port map (I0=>XLXN_8,
                I1=>XLXN_7,
                I2=>XLXN_4,
                O=>XLXN_2);
   
   XLXI_6 : OR2
      port map (I0=>XLXN_2,
                I1=>XLXN_1,
                O=>Z);
   
   XLXI_7 : INV
      port map (I=>A,
                O=>XLXN_4);
   
   XLXI_8 : INV
      port map (I=>C,
                O=>XLXN_7);
   
   XLXI_9 : INV
      port map (I=>D,
                O=>XLXN_8);
   
end BEHAVIORAL;


