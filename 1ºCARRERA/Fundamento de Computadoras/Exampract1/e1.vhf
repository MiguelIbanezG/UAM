--------------------------------------------------------------------------------
-- Copyright (c) 1995-2013 Xilinx, Inc.  All rights reserved.
--------------------------------------------------------------------------------
--   ____  ____ 
--  /   /\/   / 
-- /___/  \  /    Vendor: Xilinx 
-- \   \   \/     Version : 14.7
--  \   \         Application : sch2hdl
--  /   /         Filename : e1.vhf
-- /___/   /\     Timestamp : 10/28/2020 10:20:41
-- \   \  /  \ 
--  \___\/\___\ 
--
--Command: sch2hdl -intstyle ise -family spartan3 -flat -suppress -vhdl "C:/Users/migue/OneDrive/Escritorio/1 DE CARRERA/Fundamento de Computadoras/Exampract1/e1.vhf" -w "C:/Users/migue/OneDrive/Escritorio/1 DE CARRERA/Fundamento de Computadoras/Exampract1/e1.sch"
--Design Name: e1
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

entity e1 is
   port ( A : in    std_logic; 
          B : in    std_logic; 
          C : in    std_logic; 
          D : in    std_logic; 
          Z : out   std_logic);
end e1;

architecture BEHAVIORAL of e1 is
   attribute BOX_TYPE   : string ;
   signal XLXN_1  : std_logic;
   signal XLXN_2  : std_logic;
   signal XLXN_3  : std_logic;
   signal XLXN_4  : std_logic;
   signal XLXN_7  : std_logic;
   signal XLXN_10 : std_logic;
   signal XLXN_11 : std_logic;
   signal XLXN_13 : std_logic;
   signal XLXN_19 : std_logic;
   component AND3
      port ( I0 : in    std_logic; 
             I1 : in    std_logic; 
             I2 : in    std_logic; 
             O  : out   std_logic);
   end component;
   attribute BOX_TYPE of AND3 : component is "BLACK_BOX";
   
   component AND4
      port ( I0 : in    std_logic; 
             I1 : in    std_logic; 
             I2 : in    std_logic; 
             I3 : in    std_logic; 
             O  : out   std_logic);
   end component;
   attribute BOX_TYPE of AND4 : component is "BLACK_BOX";
   
   component OR5
      port ( I0 : in    std_logic; 
             I1 : in    std_logic; 
             I2 : in    std_logic; 
             I3 : in    std_logic; 
             I4 : in    std_logic; 
             O  : out   std_logic);
   end component;
   attribute BOX_TYPE of OR5 : component is "BLACK_BOX";
   
   component INV
      port ( I : in    std_logic; 
             O : out   std_logic);
   end component;
   attribute BOX_TYPE of INV : component is "BLACK_BOX";
   
begin
   XLXI_1 : AND3
      port map (I0=>XLXN_19,
                I1=>A,
                I2=>C,
                O=>XLXN_1);
   
   XLXI_2 : AND3
      port map (I0=>B,
                I1=>D,
                I2=>C,
                O=>XLXN_2);
   
   XLXI_3 : AND3
      port map (I0=>XLXN_13,
                I1=>B,
                I2=>XLXN_19,
                O=>XLXN_3);
   
   XLXI_4 : AND3
      port map (I0=>XLXN_13,
                I1=>A,
                I2=>XLXN_19,
                O=>XLXN_4);
   
   XLXI_5 : AND4
      port map (I0=>D,
                I1=>XLXN_13,
                I2=>XLXN_10,
                I3=>XLXN_11,
                O=>XLXN_7);
   
   XLXI_6 : OR5
      port map (I0=>XLXN_7,
                I1=>XLXN_4,
                I2=>XLXN_3,
                I3=>XLXN_2,
                I4=>XLXN_1,
                O=>Z);
   
   XLXI_7 : INV
      port map (I=>D,
                O=>XLXN_19);
   
   XLXI_8 : INV
      port map (I=>A,
                O=>XLXN_11);
   
   XLXI_9 : INV
      port map (I=>B,
                O=>XLXN_10);
   
   XLXI_10 : INV
      port map (I=>C,
                O=>XLXN_13);
   
end BEHAVIORAL;


