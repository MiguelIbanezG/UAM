--------------------------------------------------------------------------------
-- Copyright (c) 1995-2013 Xilinx, Inc.  All rights reserved.
--------------------------------------------------------------------------------
--   ____  ____ 
--  /   /\/   / 
-- /___/  \  /    Vendor: Xilinx 
-- \   \   \/     Version : 14.7
--  \   \         Application : sch2hdl
--  /   /         Filename : p3ej1.vhf
-- /___/   /\     Timestamp : 11/11/2020 13:13:45
-- \   \  /  \ 
--  \___\/\___\ 
--
--Command: sch2hdl -intstyle ise -family spartan3e -flat -suppress -vhdl "C:/Users/migue/OneDrive/Escritorio/1 DE CARRERA/Fundamento de Computadoras/h/p3ej1.vhf" -w "C:/Users/migue/OneDrive/Escritorio/1 DE CARRERA/Fundamento de Computadoras/p3ej1.sch"
--Design Name: p3ej1
--Device: spartan3e
--Purpose:
--    This vhdl netlist is translated from an ECS schematic. It can be 
--    synthesized and simulated, but it should not be modified. 
--

library ieee;
use ieee.std_logic_1164.ALL;
use ieee.numeric_std.ALL;
library UNISIM;
use UNISIM.Vcomponents.ALL;

entity p3ej1 is
   port ( CLK : in    std_logic; 
          CLR : in    std_logic; 
          Q0  : out   std_logic; 
          Q1  : out   std_logic; 
          Q2  : out   std_logic; 
          Q3  : out   std_logic);
end p3ej1;

architecture BEHAVIORAL of p3ej1 is
   attribute BOX_TYPE   : string ;
   signal XLXN_112 : std_logic;
   signal XLXN_114 : std_logic;
   signal XLXN_118 : std_logic;
   signal Q0_DUMMY : std_logic;
   signal Q1_DUMMY : std_logic;
   signal Q2_DUMMY : std_logic;
   signal Q3_DUMMY : std_logic;
   component FDC
      generic( INIT : bit :=  '0');
      port ( C   : in    std_logic; 
             CLR : in    std_logic; 
             D   : in    std_logic; 
             Q   : out   std_logic);
   end component;
   attribute BOX_TYPE of FDC : component is "BLACK_BOX";
   
   component AND2
      port ( I0 : in    std_logic; 
             I1 : in    std_logic; 
             O  : out   std_logic);
   end component;
   attribute BOX_TYPE of AND2 : component is "BLACK_BOX";
   
   component INV
      port ( I : in    std_logic; 
             O : out   std_logic);
   end component;
   attribute BOX_TYPE of INV : component is "BLACK_BOX";
   
begin
   Q0 <= Q0_DUMMY;
   Q1 <= Q1_DUMMY;
   Q2 <= Q2_DUMMY;
   Q3 <= Q3_DUMMY;
   XLXI_7 : FDC
      port map (C=>CLR,
                CLR=>CLK,
                D=>XLXN_118,
                Q=>Q0_DUMMY);
   
   XLXI_8 : FDC
      port map (C=>CLR,
                CLR=>CLK,
                D=>XLXN_112,
                Q=>Q1_DUMMY);
   
   XLXI_9 : FDC
      port map (C=>CLR,
                CLR=>CLK,
                D=>XLXN_114,
                Q=>Q2_DUMMY);
   
   XLXI_10 : FDC
      port map (C=>CLR,
                CLR=>CLK,
                D=>Q2_DUMMY,
                Q=>Q3_DUMMY);
   
   XLXI_15 : AND2
      port map (I0=>Q0_DUMMY,
                I1=>XLXN_118,
                O=>XLXN_112);
   
   XLXI_16 : AND2
      port map (I0=>Q1_DUMMY,
                I1=>XLXN_118,
                O=>XLXN_114);
   
   XLXI_18 : AND2
      port map (I0=>Q2_DUMMY,
                I1=>XLXN_118,
                O=>Q2_DUMMY);
   
   XLXI_22 : INV
      port map (I=>Q3_DUMMY,
                O=>XLXN_118);
   
end BEHAVIORAL;


