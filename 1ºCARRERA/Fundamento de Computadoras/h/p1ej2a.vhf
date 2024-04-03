--------------------------------------------------------------------------------
-- Copyright (c) 1995-2013 Xilinx, Inc.  All rights reserved.
--------------------------------------------------------------------------------
--   ____  ____ 
--  /   /\/   / 
-- /___/  \  /    Vendor: Xilinx 
-- \   \   \/     Version : 14.7
--  \   \         Application : sch2hdl
--  /   /         Filename : p1ej2a.vhf
-- /___/   /\     Timestamp : 10/18/2020 15:17:36
-- \   \  /  \ 
--  \___\/\___\ 
--
--Command: sch2hdl -intstyle ise -family spartan3 -flat -suppress -vhdl "C:/Users/migue/OneDrive/Escritorio/1 DE CARRERA/Fundamento de Computadoras/h/p1ej2a.vhf" -w C:/Users/migue/Downloads/p1ej2a.sch
--Design Name: p1ej2a
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

entity p1ej2a is
   port ( A : in    std_logic; 
          B : in    std_logic; 
          C : in    std_logic; 
          D : in    std_logic; 
          Z : out   std_logic);
end p1ej2a;

architecture BEHAVIORAL of p1ej2a is
   attribute BOX_TYPE   : string ;
   signal XLXN_2  : std_logic;
   signal XLXN_6  : std_logic;
   signal XLXN_7  : std_logic;
   signal XLXN_8  : std_logic;
   signal XLXN_10 : std_logic;
   signal XLXN_13 : std_logic;
   signal XLXN_22 : std_logic;
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
      port map (I0=>XLXN_22,
                I1=>XLXN_8,
                O=>XLXN_6);
   
   XLXI_2 : AND3
      port map (I0=>B,
                I1=>XLXN_10,
                I2=>D,
                O=>XLXN_7);
   
   XLXI_3 : AND3
      port map (I0=>XLXN_13,
                I1=>XLXN_10,
                I2=>XLXN_22,
                O=>XLXN_2);
   
   XLXI_5 : OR3
      port map (I0=>XLXN_2,
                I1=>XLXN_7,
                I2=>XLXN_6,
                O=>Z);
   
   XLXI_6 : INV
      port map (I=>A,
                O=>XLXN_8);
   
   XLXI_9 : INV
      port map (I=>B,
                O=>XLXN_22);
   
   XLXI_10 : INV
      port map (I=>C,
                O=>XLXN_10);
   
   XLXI_11 : INV
      port map (I=>D,
                O=>XLXN_13);
   
end BEHAVIORAL;


