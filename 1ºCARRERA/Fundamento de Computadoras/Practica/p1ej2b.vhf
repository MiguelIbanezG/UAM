--------------------------------------------------------------------------------
-- Copyright (c) 1995-2013 Xilinx, Inc.  All rights reserved.
--------------------------------------------------------------------------------
--   ____  ____ 
--  /   /\/   / 
-- /___/  \  /    Vendor: Xilinx 
-- \   \   \/     Version : 14.7
--  \   \         Application : sch2hdl
--  /   /         Filename : p1ej2b.vhf
-- /___/   /\     Timestamp : 10/14/2020 12:30:41
-- \   \  /  \ 
--  \___\/\___\ 
--
--Command: sch2hdl -intstyle ise -family spartan3 -flat -suppress -vhdl "C:/Users/migue/OneDrive/Escritorio/1 DE CARRERA/Fundamento de Computadoras/Practica/p1ej2b.vhf" -w C:/Users/migue/Downloads/p1ej2b.sch
--Design Name: p1ej2b
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

entity p1ej2b is
   port ( A : in    std_logic; 
          B : in    std_logic; 
          C : in    std_logic; 
          D : in    std_logic; 
          Z : out   std_logic);
end p1ej2b;

architecture BEHAVIORAL of p1ej2b is
   attribute BOX_TYPE   : string ;
   signal XLXN_1  : std_logic;
   signal XLXN_2  : std_logic;
   signal XLXN_3  : std_logic;
   signal XLXN_4  : std_logic;
   signal XLXN_8  : std_logic;
   signal XLXN_11 : std_logic;
   signal XLXN_12 : std_logic;
   signal XLXN_13 : std_logic;
   component OR2
      port ( I0 : in    std_logic; 
             I1 : in    std_logic; 
             O  : out   std_logic);
   end component;
   attribute BOX_TYPE of OR2 : component is "BLACK_BOX";
   
   component OR3
      port ( I0 : in    std_logic; 
             I1 : in    std_logic; 
             I2 : in    std_logic; 
             O  : out   std_logic);
   end component;
   attribute BOX_TYPE of OR3 : component is "BLACK_BOX";
   
   component AND4
      port ( I0 : in    std_logic; 
             I1 : in    std_logic; 
             I2 : in    std_logic; 
             I3 : in    std_logic; 
             O  : out   std_logic);
   end component;
   attribute BOX_TYPE of AND4 : component is "BLACK_BOX";
   
   component INV
      port ( I : in    std_logic; 
             O : out   std_logic);
   end component;
   attribute BOX_TYPE of INV : component is "BLACK_BOX";
   
begin
   XLXI_1 : OR2
      port map (I0=>XLXN_8,
                I1=>XLXN_11,
                O=>XLXN_1);
   
   XLXI_2 : OR2
      port map (I0=>XLXN_8,
                I1=>XLXN_12,
                O=>XLXN_2);
   
   XLXI_3 : OR2
      port map (I0=>D,
                I1=>XLXN_11,
                O=>XLXN_3);
   
   XLXI_4 : OR3
      port map (I0=>XLXN_13,
                I1=>B,
                I2=>XLXN_12,
                O=>XLXN_4);
   
   XLXI_5 : AND4
      port map (I0=>XLXN_4,
                I1=>XLXN_3,
                I2=>XLXN_2,
                I3=>XLXN_1,
                O=>Z);
   
   XLXI_6 : INV
      port map (I=>A,
                O=>XLXN_12);
   
   XLXI_7 : INV
      port map (I=>B,
                O=>XLXN_11);
   
   XLXI_8 : INV
      port map (I=>C,
                O=>XLXN_8);
   
   XLXI_9 : INV
      port map (I=>D,
                O=>XLXN_13);
   
end BEHAVIORAL;


