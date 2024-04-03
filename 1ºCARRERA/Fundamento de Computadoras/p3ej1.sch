<?xml version="1.0" encoding="UTF-8"?>
<drawing version="7">
    <attr value="spartan3e" name="DeviceFamilyName">
        <trait delete="all:0" />
        <trait editname="all:0" />
        <trait edittrait="all:0" />
    </attr>
    <netlist>
        <signal name="CLK" />
        <signal name="Q3" />
        <signal name="Q2" />
        <signal name="Q0" />
        <signal name="Q1" />
        <signal name="CLR" />
        <signal name="XLXN_125" />
        <signal name="XLXN_128" />
        <signal name="XLXN_133" />
        <signal name="XLXN_134" />
        <signal name="XLXN_135" />
        <signal name="XLXN_136" />
        <signal name="XLXN_137" />
        <signal name="XLXN_138" />
        <signal name="XLXN_139" />
        <port polarity="Input" name="CLK" />
        <port polarity="Output" name="Q3" />
        <port polarity="Output" name="Q2" />
        <port polarity="Output" name="Q0" />
        <port polarity="Output" name="Q1" />
        <port polarity="Input" name="CLR" />
        <blockdef name="fdc">
            <timestamp>2000-1-1T10:10:10</timestamp>
            <line x2="64" y1="-128" y2="-128" x1="0" />
            <line x2="64" y1="-32" y2="-32" x1="0" />
            <line x2="64" y1="-256" y2="-256" x1="0" />
            <line x2="320" y1="-256" y2="-256" x1="384" />
            <rect width="256" x="64" y="-320" height="256" />
            <line x2="80" y1="-112" y2="-128" x1="64" />
            <line x2="64" y1="-128" y2="-144" x1="80" />
            <line x2="192" y1="-64" y2="-32" x1="192" />
            <line x2="64" y1="-32" y2="-32" x1="192" />
        </blockdef>
        <blockdef name="inv">
            <timestamp>2000-1-1T10:10:10</timestamp>
            <line x2="64" y1="-32" y2="-32" x1="0" />
            <line x2="160" y1="-32" y2="-32" x1="224" />
            <line x2="128" y1="-64" y2="-32" x1="64" />
            <line x2="64" y1="-32" y2="0" x1="128" />
            <line x2="64" y1="0" y2="-64" x1="64" />
            <circle r="16" cx="144" cy="-32" />
        </blockdef>
        <blockdef name="or2">
            <timestamp>2000-1-1T10:10:10</timestamp>
            <line x2="64" y1="-64" y2="-64" x1="0" />
            <line x2="64" y1="-128" y2="-128" x1="0" />
            <line x2="192" y1="-96" y2="-96" x1="256" />
            <arc ex="192" ey="-96" sx="112" sy="-48" r="88" cx="116" cy="-136" />
            <arc ex="48" ey="-144" sx="48" sy="-48" r="56" cx="16" cy="-96" />
            <line x2="48" y1="-144" y2="-144" x1="112" />
            <arc ex="112" ey="-144" sx="192" sy="-96" r="88" cx="116" cy="-56" />
            <line x2="48" y1="-48" y2="-48" x1="112" />
        </blockdef>
        <blockdef name="and4">
            <timestamp>2000-1-1T10:10:10</timestamp>
            <line x2="64" y1="-112" y2="-112" x1="144" />
            <arc ex="144" ey="-208" sx="144" sy="-112" r="48" cx="144" cy="-160" />
            <line x2="144" y1="-208" y2="-208" x1="64" />
            <line x2="64" y1="-64" y2="-256" x1="64" />
            <line x2="192" y1="-160" y2="-160" x1="256" />
            <line x2="64" y1="-256" y2="-256" x1="0" />
            <line x2="64" y1="-192" y2="-192" x1="0" />
            <line x2="64" y1="-128" y2="-128" x1="0" />
            <line x2="64" y1="-64" y2="-64" x1="0" />
        </blockdef>
        <block symbolname="fdc" name="XLXI_7">
            <blockpin signalname="CLK" name="C" />
            <blockpin signalname="CLR" name="CLR" />
            <blockpin signalname="XLXN_125" name="D" />
            <blockpin signalname="Q0" name="Q" />
        </block>
        <block symbolname="fdc" name="XLXI_9">
            <blockpin signalname="CLK" name="C" />
            <blockpin signalname="CLR" name="CLR" />
            <blockpin signalname="Q1" name="D" />
            <blockpin signalname="Q2" name="Q" />
        </block>
        <block symbolname="fdc" name="XLXI_10">
            <blockpin signalname="CLK" name="C" />
            <blockpin signalname="CLR" name="CLR" />
            <blockpin signalname="Q2" name="D" />
            <blockpin signalname="Q3" name="Q" />
        </block>
        <block symbolname="fdc" name="XLXI_8">
            <blockpin signalname="CLK" name="C" />
            <blockpin signalname="CLR" name="CLR" />
            <blockpin signalname="Q0" name="D" />
            <blockpin signalname="Q1" name="Q" />
        </block>
        <block symbolname="and4" name="XLXI_24">
            <blockpin signalname="Q3" name="I0" />
            <blockpin signalname="Q2" name="I1" />
            <blockpin signalname="Q1" name="I2" />
            <blockpin signalname="Q0" name="I3" />
            <blockpin signalname="XLXN_128" name="O" />
        </block>
        <block symbolname="or2" name="XLXI_26">
            <blockpin signalname="CLR" name="I0" />
            <blockpin signalname="XLXN_128" name="I1" />
            <blockpin signalname="CLR" name="O" />
        </block>
        <block symbolname="inv" name="XLXI_28">
            <blockpin signalname="Q3" name="I" />
            <blockpin signalname="XLXN_125" name="O" />
        </block>
        <block symbolname="inv" name="XLXI_31">
            <blockpin signalname="Q3" name="I" />
            <blockpin signalname="Q3" name="O" />
        </block>
        <block symbolname="inv" name="XLXI_33">
            <blockpin signalname="Q0" name="I" />
            <blockpin signalname="Q0" name="O" />
        </block>
    </netlist>
    <sheet sheetnum="1" width="3520" height="2720">
        <instance x="592" y="960" name="XLXI_7" orien="R0" />
        <instance x="2928" y="960" name="XLXI_10" orien="R0" />
        <instance x="2224" y="944" name="XLXI_9" orien="R0" />
        <instance x="1424" y="976" name="XLXI_8" orien="R0" />
        <iomarker fontsize="28" x="3440" y="704" name="Q3" orien="R0" />
        <iomarker fontsize="28" x="384" y="1152" name="CLK" orien="R180" />
        <branch name="CLK">
            <wire x2="528" y1="1152" y2="1152" x1="384" />
            <wire x2="1248" y1="1152" y2="1152" x1="528" />
            <wire x2="2080" y1="1152" y2="1152" x1="1248" />
            <wire x2="2768" y1="1152" y2="1152" x1="2080" />
            <wire x2="592" y1="832" y2="832" x1="528" />
            <wire x2="528" y1="832" y2="1152" x1="528" />
            <wire x2="1424" y1="848" y2="848" x1="1248" />
            <wire x2="1248" y1="848" y2="1152" x1="1248" />
            <wire x2="2224" y1="816" y2="816" x1="2080" />
            <wire x2="2080" y1="816" y2="1152" x1="2080" />
            <wire x2="2928" y1="832" y2="832" x1="2768" />
            <wire x2="2768" y1="832" y2="1152" x1="2768" />
        </branch>
        <branch name="Q1">
            <wire x2="1824" y1="208" y2="208" x1="1136" />
            <wire x2="1824" y1="208" y2="720" x1="1824" />
            <wire x2="1888" y1="720" y2="720" x1="1824" />
            <wire x2="1888" y1="720" y2="816" x1="1888" />
            <wire x2="1952" y1="816" y2="816" x1="1888" />
            <wire x2="2160" y1="720" y2="720" x1="1888" />
            <wire x2="1824" y1="720" y2="720" x1="1808" />
            <wire x2="2224" y1="688" y2="688" x1="2160" />
            <wire x2="2160" y1="688" y2="720" x1="2160" />
        </branch>
        <branch name="Q2">
            <wire x2="2624" y1="144" y2="144" x1="1136" />
            <wire x2="2624" y1="144" y2="688" x1="2624" />
            <wire x2="2624" y1="688" y2="704" x1="2624" />
            <wire x2="2672" y1="704" y2="704" x1="2624" />
            <wire x2="2672" y1="704" y2="768" x1="2672" />
            <wire x2="2720" y1="768" y2="768" x1="2672" />
            <wire x2="2928" y1="704" y2="704" x1="2672" />
            <wire x2="2624" y1="688" y2="688" x1="2608" />
        </branch>
        <branch name="CLR">
            <wire x2="592" y1="1392" y2="1392" x1="464" />
            <wire x2="1376" y1="1392" y2="1392" x1="592" />
            <wire x2="2208" y1="1392" y2="1392" x1="1376" />
            <wire x2="2928" y1="1392" y2="1392" x1="2208" />
            <wire x2="592" y1="928" y2="1392" x1="592" />
            <wire x2="1424" y1="944" y2="944" x1="1376" />
            <wire x2="1376" y1="944" y2="1392" x1="1376" />
            <wire x2="2224" y1="912" y2="912" x1="2208" />
            <wire x2="2208" y1="912" y2="1392" x1="2208" />
            <wire x2="2928" y1="928" y2="1392" x1="2928" />
        </branch>
        <branch name="XLXN_125">
            <wire x2="592" y1="704" y2="704" x1="512" />
        </branch>
        <branch name="CLR">
            <wire x2="192" y1="1424" y2="1424" x1="112" />
            <wire x2="208" y1="1424" y2="1424" x1="192" />
        </branch>
        <instance x="288" y="736" name="XLXI_28" orien="R0" />
        <branch name="Q3">
            <wire x2="1280" y1="400" y2="400" x1="272" />
            <wire x2="272" y1="400" y2="704" x1="272" />
            <wire x2="288" y1="704" y2="704" x1="272" />
        </branch>
        <instance x="1136" y="16" name="XLXI_24" orien="R180" />
        <branch name="Q3">
            <wire x2="3376" y1="80" y2="80" x1="1136" />
            <wire x2="3376" y1="80" y2="432" x1="3376" />
            <wire x2="3376" y1="432" y2="704" x1="3376" />
            <wire x2="3440" y1="704" y2="704" x1="3376" />
            <wire x2="2432" y1="400" y2="400" x1="1504" />
            <wire x2="2432" y1="400" y2="432" x1="2432" />
            <wire x2="3376" y1="432" y2="432" x1="2432" />
            <wire x2="3376" y1="704" y2="704" x1="3312" />
        </branch>
        <instance x="208" y="1488" name="XLXI_26" orien="R0" />
        <branch name="XLXN_128">
            <wire x2="128" y1="176" y2="1360" x1="128" />
            <wire x2="208" y1="1360" y2="1360" x1="128" />
            <wire x2="880" y1="176" y2="176" x1="128" />
        </branch>
        <branch name="Q0">
            <wire x2="992" y1="704" y2="704" x1="976" />
            <wire x2="1040" y1="704" y2="704" x1="992" />
            <wire x2="1424" y1="704" y2="704" x1="1040" />
            <wire x2="1424" y1="704" y2="720" x1="1424" />
            <wire x2="992" y1="480" y2="704" x1="992" />
            <wire x2="1120" y1="640" y2="640" x1="1040" />
            <wire x2="1040" y1="640" y2="704" x1="1040" />
        </branch>
        <branch name="Q0">
            <wire x2="1232" y1="272" y2="272" x1="1136" />
            <wire x2="1232" y1="272" y2="480" x1="1232" />
            <wire x2="1232" y1="480" y2="480" x1="1216" />
        </branch>
        <iomarker fontsize="28" x="1120" y="640" name="Q0" orien="R0" />
        <iomarker fontsize="28" x="1952" y="816" name="Q1" orien="R0" />
        <iomarker fontsize="28" x="2720" y="768" name="Q2" orien="R0" />
        <instance x="1504" y="368" name="XLXI_31" orien="R180" />
        <iomarker fontsize="28" x="112" y="1424" name="CLR" orien="R180" />
        <instance x="992" y="512" name="XLXI_33" orien="R0" />
    </sheet>
</drawing>