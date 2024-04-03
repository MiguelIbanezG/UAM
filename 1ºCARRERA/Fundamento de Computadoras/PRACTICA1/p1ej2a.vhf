--------------------------------------------------------------------------------
-- Copyright (c) 1995-2013 Xilinx, Inc.  All rights reserved.
--------------------------------------------------------------------------------
--   ____  ____ 
--  /   /\/   / 
-- /___/  \  /    Vendor: Xilinx 
-- \   \   \/     Version : 14.7
--  \   \         Application : sch2hdl
--  /   /         Filename : p1ej2a.vhf
-- /___/   /\     Timestamp : 10/18/2020 15:35:17
-- \   \  /  \ 
--  \___\/\___\ 
--
--Command: sch2hdl -intstyle ise -family spartan3 -flat -suppress -vhdl "C:/Users/migue/OneDrive/Escritorio/1 DE CARRERA/Fundamento de Computadoras/PRACTICA1/p1ej2a.vhf" -w "C:/Users/migue/OneDrive/Escritorio/1 DE CARRERA/Fundamento de Computadoras/PRACTICA1/p1ej2a.sch"
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
   signal XLXN_1  : std_logic;
   signal XLXN_3  : std_logic;
   signal XLXN_4  : std_logic;
   signal XLXN_6  : std_logic;
   signal XLXN_8  : std_logic;
   signal XLXN_10 : std_logic;
   signal XLXN_11 : std_logic;
   signal XLXN_13 : std_logic;
   signal XLXN_14 : std_logic;
   component AND2
      port ( I0 : in    std_logic; 
             I1 : in    std_logic; 
             O  : out   std_logic);
   end component;
   attribute BOX_TYPE of AND2 : component is "BLACK_BOX";
   
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
      port map (I0=>XLXN_3,
                I1=>XLXN_4,
                O=>XLXN_14);
   
   XLXI_2 : AND2
      port map (I0=>XLXN_11,
                I1=>XLXN_10,
                O=>XLXN_13);
   
   XLXI_3 : AND2
      port map (I0=>B,
                I1=>D,
                O=>XLXN_8);
   
   XLXI_4 : AND2
      port map (I0=>XLXN_1,
                I1=>XLXN_3,
                O=>XLXN_6);
   
   XLXI_5 : OR2
      port map (I0=>XLXN_13,
                I1=>XLXN_14,
                O=>Z);
   
   XLXI_6 : OR2
      port map (I0=>XLXN_6,
                I1=>XLXN_8,
                O=>XLXN_11);
   
   XLXI_7 : INV
      port map (I=>D,
                O=>XLXN_1);
   
   XLXI_8 : INV
      port map (I=>A,
                O=>XLXN_4);
   
   XLXI_9 : INV
      port map (I=>C,
                O=>XLXN_10);
   
   XLXI_10 : INV
      port map (I=>B,
                O=>XLXN_3);
   
end BEHAVIORAL;


