--------------------------------------------------------------------------------
-- Copyright (c) 1995-2013 Xilinx, Inc.  All rights reserved.
--------------------------------------------------------------------------------
--   ____  ____ 
--  /   /\/   / 
-- /___/  \  /    Vendor: Xilinx 
-- \   \   \/     Version : 14.7
--  \   \         Application : sch2hdl
--  /   /         Filename : p4ej1.vhf
-- /___/   /\     Timestamp : 12/06/2020 18:55:09
-- \   \  /  \ 
--  \___\/\___\ 
--
--Command: sch2hdl -intstyle ise -family spartan3e -flat -suppress -vhdl "C:/Users/migue/OneDrive/Escritorio/1 DE CARRERA/Fundamento de Computadoras/ss/p4ej1.vhf" -w C:/Users/migue/OneDrive/Escritorio/p4ej1.sch
--Design Name: p4ej1
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

entity p4ej1 is
   port ( CLK : in    std_logic; 
          CLR : in    std_logic; 
          S0  : in    std_logic; 
          S1  : in    std_logic; 
          AD  : out   std_logic; 
          AI  : out   std_logic; 
          RD  : out   std_logic; 
          RI  : out   std_logic; 
          VD  : out   std_logic; 
          VI  : out   std_logic);
end p4ej1;

architecture BEHAVIORAL of p4ej1 is
   attribute BOX_TYPE   : string ;
   signal XLXN_7   : std_logic;
   signal XLXN_8   : std_logic;
   signal XLXN_34  : std_logic;
   signal XLXN_35  : std_logic;
   signal XLXN_36  : std_logic;
   signal XLXN_37  : std_logic;
   signal XLXN_38  : std_logic;
   signal XLXN_46  : std_logic;
   signal XLXN_55  : std_logic;
   signal XLXN_57  : std_logic;
   signal XLXN_59  : std_logic;
   signal XLXN_61  : std_logic;
   signal XLXN_63  : std_logic;
   signal RD_DUMMY : std_logic;
   signal RI_DUMMY : std_logic;
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
   
   component OR3
      port ( I0 : in    std_logic; 
             I1 : in    std_logic; 
             I2 : in    std_logic; 
             O  : out   std_logic);
   end component;
   attribute BOX_TYPE of OR3 : component is "BLACK_BOX";
   
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
   
   component XOR2
      port ( I0 : in    std_logic; 
             I1 : in    std_logic; 
             O  : out   std_logic);
   end component;
   attribute BOX_TYPE of XOR2 : component is "BLACK_BOX";
   
begin
   RD <= RD_DUMMY;
   RI <= RI_DUMMY;
   XLXI_1 : FDC
      port map (C=>CLK,
                CLR=>CLR,
                D=>XLXN_7,
                Q=>XLXN_57);
   
   XLXI_2 : FDC
      port map (C=>CLK,
                CLR=>CLR,
                D=>XLXN_55,
                Q=>XLXN_63);
   
   XLXI_3 : FDC
      port map (C=>CLK,
                CLR=>CLR,
                D=>XLXN_35,
                Q=>RD_DUMMY);
   
   XLXI_4 : AND2
      port map (I0=>XLXN_34,
                I1=>RI_DUMMY,
                O=>VD);
   
   XLXI_5 : AND2
      port map (I0=>XLXN_34,
                I1=>RD_DUMMY,
                O=>VI);
   
   XLXI_7 : AND2
      port map (I0=>RD_DUMMY,
                I1=>XLXN_8,
                O=>XLXN_37);
   
   XLXI_8 : AND2
      port map (I0=>XLXN_46,
                I1=>RD_DUMMY,
                O=>XLXN_38);
   
   XLXI_10 : AND2
      port map (I0=>XLXN_8,
                I1=>XLXN_63,
                O=>XLXN_8);
   
   XLXI_17 : INV
      port map (I=>XLXN_63,
                O=>XLXN_46);
   
   XLXI_18 : INV
      port map (I=>XLXN_57,
                O=>XLXN_8);
   
   XLXI_19 : INV
      port map (I=>RD_DUMMY,
                O=>RI_DUMMY);
   
   XLXI_20 : OR3
      port map (I0=>XLXN_8,
                I1=>XLXN_59,
                I2=>XLXN_61,
                O=>XLXN_7);
   
   XLXI_21 : AND3
      port map (I0=>XLXN_63,
                I1=>XLXN_57,
                I2=>RI_DUMMY,
                O=>XLXN_36);
   
   XLXI_22 : AND3
      port map (I0=>S0,
                I1=>XLXN_8,
                I2=>RD_DUMMY,
                O=>XLXN_59);
   
   XLXI_24 : AND3
      port map (I0=>S1,
                I1=>XLXN_8,
                I2=>RI_DUMMY,
                O=>XLXN_61);
   
   XLXI_25 : AND3
      port map (I0=>XLXN_57,
                I1=>RD_DUMMY,
                I2=>XLXN_63,
                O=>AI);
   
   XLXI_26 : AND3
      port map (I0=>XLXN_57,
                I1=>XLXN_63,
                I2=>RI_DUMMY,
                O=>AD);
   
   XLXI_27 : OR2
      port map (I0=>XLXN_46,
                I1=>XLXN_8,
                O=>XLXN_34);
   
   XLXI_28 : OR3
      port map (I0=>XLXN_38,
                I1=>XLXN_37,
                I2=>XLXN_36,
                O=>XLXN_35);
   
   XLXI_29 : XOR2
      port map (I0=>XLXN_63,
                I1=>XLXN_57,
                O=>XLXN_55);
   
end BEHAVIORAL;


