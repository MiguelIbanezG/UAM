--------------------------------------------------------------------------------
-- Copyright (c) 1995-2013 Xilinx, Inc.  All rights reserved.
--------------------------------------------------------------------------------
--   ____  ____ 
--  /   /\/   / 
-- /___/  \  /    Vendor: Xilinx 
-- \   \   \/     Version : 14.7
--  \   \         Application : sch2hdl
--  /   /         Filename : e3.vhf
-- /___/   /\     Timestamp : 11/25/2020 10:20:28
-- \   \  /  \ 
--  \___\/\___\ 
--
--Command: sch2hdl -intstyle ise -family spartan3e -flat -suppress -vhdl "C:/Users/migue/OneDrive/Escritorio/1 DE CARRERA/Fundamento de Computadoras/Hh/e3.vhf" -w C:/Users/migue/Downloads/e3.sch
--Design Name: e3
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

entity M2_1_MXILINX_e3 is
   port ( D0 : in    std_logic; 
          D1 : in    std_logic; 
          S0 : in    std_logic; 
          O  : out   std_logic);
end M2_1_MXILINX_e3;

architecture BEHAVIORAL of M2_1_MXILINX_e3 is
   attribute BOX_TYPE   : string ;
   signal M0 : std_logic;
   signal M1 : std_logic;
   component AND2B1
      port ( I0 : in    std_logic; 
             I1 : in    std_logic; 
             O  : out   std_logic);
   end component;
   attribute BOX_TYPE of AND2B1 : component is "BLACK_BOX";
   
   component OR2
      port ( I0 : in    std_logic; 
             I1 : in    std_logic; 
             O  : out   std_logic);
   end component;
   attribute BOX_TYPE of OR2 : component is "BLACK_BOX";
   
   component AND2
      port ( I0 : in    std_logic; 
             I1 : in    std_logic; 
             O  : out   std_logic);
   end component;
   attribute BOX_TYPE of AND2 : component is "BLACK_BOX";
   
begin
   I_36_7 : AND2B1
      port map (I0=>S0,
                I1=>D0,
                O=>M0);
   
   I_36_8 : OR2
      port map (I0=>M1,
                I1=>M0,
                O=>O);
   
   I_36_9 : AND2
      port map (I0=>D1,
                I1=>S0,
                O=>M1);
   
end BEHAVIORAL;



library ieee;
use ieee.std_logic_1164.ALL;
use ieee.numeric_std.ALL;
library UNISIM;
use UNISIM.Vcomponents.ALL;

entity FTCLEX_MXILINX_e3 is
   generic( INIT : bit :=  '0');
   port ( C   : in    std_logic; 
          CE  : in    std_logic; 
          CLR : in    std_logic; 
          D   : in    std_logic; 
          L   : in    std_logic; 
          T   : in    std_logic; 
          Q   : out   std_logic);
end FTCLEX_MXILINX_e3;

architecture BEHAVIORAL of FTCLEX_MXILINX_e3 is
   attribute HU_SET     : string ;
   attribute BOX_TYPE   : string ;
   attribute RLOC       : string ;
   signal MD      : std_logic;
   signal TQ      : std_logic;
   signal Q_DUMMY : std_logic;
   component M2_1_MXILINX_e3
      port ( D0 : in    std_logic; 
             D1 : in    std_logic; 
             S0 : in    std_logic; 
             O  : out   std_logic);
   end component;
   
   component XOR2
      port ( I0 : in    std_logic; 
             I1 : in    std_logic; 
             O  : out   std_logic);
   end component;
   attribute BOX_TYPE of XOR2 : component is "BLACK_BOX";
   
   component FDCE
      generic( INIT : bit :=  '0');
      port ( C   : in    std_logic; 
             CE  : in    std_logic; 
             CLR : in    std_logic; 
             D   : in    std_logic; 
             Q   : out   std_logic);
   end component;
   attribute BOX_TYPE of FDCE : component is "BLACK_BOX";
   
   attribute HU_SET of I_36_30 : label is "I_36_30_0";
   attribute RLOC of I_36_35 : label is "X0Y0";
begin
   Q <= Q_DUMMY;
   I_36_30 : M2_1_MXILINX_e3
      port map (D0=>TQ,
                D1=>D,
                S0=>L,
                O=>MD);
   
   I_36_32 : XOR2
      port map (I0=>T,
                I1=>Q_DUMMY,
                O=>TQ);
   
   I_36_35 : FDCE
   generic map( INIT => INIT)
      port map (C=>C,
                CE=>CE,
                CLR=>CLR,
                D=>MD,
                Q=>Q_DUMMY);
   
end BEHAVIORAL;



library ieee;
use ieee.std_logic_1164.ALL;
use ieee.numeric_std.ALL;
library UNISIM;
use UNISIM.Vcomponents.ALL;

entity CB4CLE_MXILINX_e3 is
   port ( C   : in    std_logic; 
          CE  : in    std_logic; 
          CLR : in    std_logic; 
          D0  : in    std_logic; 
          D1  : in    std_logic; 
          D2  : in    std_logic; 
          D3  : in    std_logic; 
          L   : in    std_logic; 
          CEO : out   std_logic; 
          Q0  : out   std_logic; 
          Q1  : out   std_logic; 
          Q2  : out   std_logic; 
          Q3  : out   std_logic; 
          TC  : out   std_logic);
end CB4CLE_MXILINX_e3;

architecture BEHAVIORAL of CB4CLE_MXILINX_e3 is
   attribute HU_SET     : string ;
   attribute BOX_TYPE   : string ;
   signal OR_CE_L  : std_logic;
   signal T2       : std_logic;
   signal T3       : std_logic;
   signal XLXN_1   : std_logic;
   signal Q0_DUMMY : std_logic;
   signal Q1_DUMMY : std_logic;
   signal Q2_DUMMY : std_logic;
   signal Q3_DUMMY : std_logic;
   signal TC_DUMMY : std_logic;
   component FTCLEX_MXILINX_e3
      generic( INIT : bit :=  '0');
      port ( C   : in    std_logic; 
             CE  : in    std_logic; 
             CLR : in    std_logic; 
             D   : in    std_logic; 
             L   : in    std_logic; 
             T   : in    std_logic; 
             Q   : out   std_logic);
   end component;
   
   component VCC
      port ( P : out   std_logic);
   end component;
   attribute BOX_TYPE of VCC : component is "BLACK_BOX";
   
   component AND4
      port ( I0 : in    std_logic; 
             I1 : in    std_logic; 
             I2 : in    std_logic; 
             I3 : in    std_logic; 
             O  : out   std_logic);
   end component;
   attribute BOX_TYPE of AND4 : component is "BLACK_BOX";
   
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
   
   attribute HU_SET of I_Q0 : label is "I_Q0_1";
   attribute HU_SET of I_Q1 : label is "I_Q1_2";
   attribute HU_SET of I_Q2 : label is "I_Q2_3";
   attribute HU_SET of I_Q3 : label is "I_Q3_4";
begin
   Q0 <= Q0_DUMMY;
   Q1 <= Q1_DUMMY;
   Q2 <= Q2_DUMMY;
   Q3 <= Q3_DUMMY;
   TC <= TC_DUMMY;
   I_Q0 : FTCLEX_MXILINX_e3
      port map (C=>C,
                CE=>OR_CE_L,
                CLR=>CLR,
                D=>D0,
                L=>L,
                T=>XLXN_1,
                Q=>Q0_DUMMY);
   
   I_Q1 : FTCLEX_MXILINX_e3
      port map (C=>C,
                CE=>OR_CE_L,
                CLR=>CLR,
                D=>D1,
                L=>L,
                T=>Q0_DUMMY,
                Q=>Q1_DUMMY);
   
   I_Q2 : FTCLEX_MXILINX_e3
      port map (C=>C,
                CE=>OR_CE_L,
                CLR=>CLR,
                D=>D2,
                L=>L,
                T=>T2,
                Q=>Q2_DUMMY);
   
   I_Q3 : FTCLEX_MXILINX_e3
      port map (C=>C,
                CE=>OR_CE_L,
                CLR=>CLR,
                D=>D3,
                L=>L,
                T=>T3,
                Q=>Q3_DUMMY);
   
   I_36_59 : VCC
      port map (P=>XLXN_1);
   
   I_36_87 : AND4
      port map (I0=>Q0_DUMMY,
                I1=>Q1_DUMMY,
                I2=>Q2_DUMMY,
                I3=>Q3_DUMMY,
                O=>TC_DUMMY);
   
   I_36_98 : AND2
      port map (I0=>Q1_DUMMY,
                I1=>Q0_DUMMY,
                O=>T2);
   
   I_36_99 : AND3
      port map (I0=>Q2_DUMMY,
                I1=>Q1_DUMMY,
                I2=>Q0_DUMMY,
                O=>T3);
   
   I_36_107 : AND2
      port map (I0=>CE,
                I1=>TC_DUMMY,
                O=>CEO);
   
   I_36_120 : OR2
      port map (I0=>CE,
                I1=>L,
                O=>OR_CE_L);
   
end BEHAVIORAL;



library ieee;
use ieee.std_logic_1164.ALL;
use ieee.numeric_std.ALL;
library UNISIM;
use UNISIM.Vcomponents.ALL;

entity e3 is
   port ( CLK      : in    std_logic; 
          INIT     : in    std_logic; 
          FREQ_DIV : out   std_logic);
end e3;

architecture BEHAVIORAL of e3 is
   attribute BOX_TYPE   : string ;
   attribute HU_SET     : string ;
   signal XLXN_5         : std_logic;
   signal XLXN_6         : std_logic;
   signal XLXN_7         : std_logic;
   signal XLXN_11        : std_logic;
   signal XLXN_18        : std_logic;
   signal XLXN_23        : std_logic;
   signal XLXN_25        : std_logic;
   signal XLXN_28        : std_logic;
   signal XLXN_29        : std_logic;
   signal XLXN_30        : std_logic;
   signal XLXN_36        : std_logic;
   signal XLXN_42        : std_logic;
   signal XLXN_43        : std_logic;
   signal XLXN_44        : std_logic;
   signal XLXN_45        : std_logic;
   signal XLXN_46        : std_logic;
   signal XLXN_47        : std_logic;
   signal XLXN_48        : std_logic;
   signal XLXN_49        : std_logic;
   signal FREQ_DIV_DUMMY : std_logic;
   component AND4
      port ( I0 : in    std_logic; 
             I1 : in    std_logic; 
             I2 : in    std_logic; 
             I3 : in    std_logic; 
             O  : out   std_logic);
   end component;
   attribute BOX_TYPE of AND4 : component is "BLACK_BOX";
   
   component VCC
      port ( P : out   std_logic);
   end component;
   attribute BOX_TYPE of VCC : component is "BLACK_BOX";
   
   component GND
      port ( G : out   std_logic);
   end component;
   attribute BOX_TYPE of GND : component is "BLACK_BOX";
   
   component CB4CLE_MXILINX_e3
      port ( C   : in    std_logic; 
             CE  : in    std_logic; 
             CLR : in    std_logic; 
             D0  : in    std_logic; 
             D1  : in    std_logic; 
             D2  : in    std_logic; 
             D3  : in    std_logic; 
             L   : in    std_logic; 
             CEO : out   std_logic; 
             Q0  : out   std_logic; 
             Q1  : out   std_logic; 
             Q2  : out   std_logic; 
             Q3  : out   std_logic; 
             TC  : out   std_logic);
   end component;
   
   attribute HU_SET of XLXI_33 : label is "XLXI_33_5";
   attribute HU_SET of XLXI_34 : label is "XLXI_34_6";
begin
   FREQ_DIV <= FREQ_DIV_DUMMY;
   XLXI_3 : AND4
      port map (I0=>XLXN_7,
                I1=>XLXN_11,
                I2=>XLXN_6,
                I3=>XLXN_5,
                O=>XLXN_30);
   
   XLXI_8 : VCC
      port map (P=>XLXN_18);
   
   XLXI_10 : AND4
      port map (I0=>XLXN_25,
                I1=>XLXN_29,
                I2=>XLXN_28,
                I3=>XLXN_23,
                O=>FREQ_DIV_DUMMY);
   
   XLXI_15 : VCC
      port map (P=>XLXN_36);
   
   XLXI_23 : GND
      port map (G=>XLXN_42);
   
   XLXI_24 : GND
      port map (G=>XLXN_43);
   
   XLXI_25 : GND
      port map (G=>XLXN_44);
   
   XLXI_26 : GND
      port map (G=>XLXN_45);
   
   XLXI_27 : GND
      port map (G=>XLXN_46);
   
   XLXI_28 : GND
      port map (G=>XLXN_47);
   
   XLXI_30 : GND
      port map (G=>XLXN_48);
   
   XLXI_32 : GND
      port map (G=>XLXN_49);
   
   XLXI_33 : CB4CLE_MXILINX_e3
      port map (C=>CLK,
                CE=>XLXN_36,
                CLR=>INIT,
                D0=>XLXN_46,
                D1=>XLXN_47,
                D2=>XLXN_48,
                D3=>XLXN_49,
                L=>XLXN_30,
                CEO=>open,
                Q0=>XLXN_23,
                Q1=>XLXN_28,
                Q2=>XLXN_29,
                Q3=>XLXN_25,
                TC=>open);
   
   XLXI_34 : CB4CLE_MXILINX_e3
      port map (C=>CLK,
                CE=>XLXN_18,
                CLR=>INIT,
                D0=>XLXN_42,
                D1=>XLXN_43,
                D2=>XLXN_44,
                D3=>XLXN_45,
                L=>FREQ_DIV_DUMMY,
                CEO=>open,
                Q0=>XLXN_5,
                Q1=>XLXN_6,
                Q2=>XLXN_11,
                Q3=>XLXN_7,
                TC=>open);
   
end BEHAVIORAL;


