<?xml version="1.0" encoding="UTF-8"?>
<drawing version="7">
    <attr value="spartan3e" name="DeviceFamilyName">
        <trait delete="all:0" />
        <trait editname="all:0" />
        <trait edittrait="all:0" />
    </attr>
    <netlist>
        <signal name="XLXN_1" />
        <signal name="XLXN_2" />
        <signal name="XLXN_3" />
        <signal name="XLXN_4" />
        <signal name="XLXN_5" />
        <signal name="CLK" />
        <signal name="CLR" />
        <signal name="XLXN_11" />
        <signal name="XLXN_12" />
        <signal name="XLXN_17" />
        <signal name="XLXN_18" />
        <signal name="XLXN_20" />
        <signal name="XLXN_24" />
        <signal name="XLXN_25" />
        <signal name="XLXN_26" />
        <signal name="XLXN_27" />
        <signal name="XLXN_28" />
        <signal name="XLXN_29" />
        <port polarity="Input" name="CLK" />
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
        <block symbolname="fdc" name="XLXI_1">
            <blockpin signalname="CLK" name="C" />
            <blockpin signalname="CLR" name="CLR" />
            <blockpin signalname="XLXN_12" name="D" />
            <blockpin signalname="XLXN_26" name="Q" />
        </block>
        <block symbolname="fdc" name="XLXI_2">
            <blockpin signalname="CLK" name="C" />
            <blockpin signalname="CLR" name="CLR" />
            <blockpin name="D" />
            <blockpin signalname="XLXN_27" name="Q" />
        </block>
        <block symbolname="fdc" name="XLXI_3">
            <blockpin signalname="CLK" name="C" />
            <blockpin signalname="CLR" name="CLR" />
            <blockpin name="D" />
            <blockpin signalname="XLXN_28" name="Q" />
        </block>
        <block symbolname="fdc" name="XLXI_4">
            <blockpin signalname="CLK" name="C" />
            <blockpin signalname="CLR" name="CLR" />
            <blockpin name="D" />
            <blockpin signalname="XLXN_29" name="Q" />
        </block>
        <block symbolname="and4" name="XLXI_5">
            <blockpin signalname="XLXN_26" name="I0" />
            <blockpin signalname="XLXN_27" name="I1" />
            <blockpin signalname="XLXN_28" name="I2" />
            <blockpin signalname="XLXN_29" name="I3" />
            <blockpin signalname="XLXN_18" name="O" />
        </block>
        <block symbolname="or2" name="XLXI_6">
            <blockpin signalname="XLXN_18" name="I0" />
            <blockpin signalname="CLK" name="I1" />
            <blockpin signalname="CLK" name="O" />
        </block>
    </netlist>
    <sheet sheetnum="1" width="3520" height="2720">
        <instance x="560" y="1248" name="XLXI_1" orien="R0" />
        <instance x="1056" y="1248" name="XLXI_2" orien="R0" />
        <instance x="1536" y="1248" name="XLXI_3" orien="R0" />
        <instance x="2032" y="1248" name="XLXI_4" orien="R0" />
        <branch name="CLR">
            <wire x2="560" y1="1280" y2="1280" x1="464" />
            <wire x2="1056" y1="1280" y2="1280" x1="560" />
            <wire x2="1536" y1="1280" y2="1280" x1="1056" />
            <wire x2="2032" y1="1280" y2="1280" x1="1536" />
            <wire x2="2400" y1="1280" y2="1280" x1="2032" />
            <wire x2="560" y1="1216" y2="1280" x1="560" />
            <wire x2="1056" y1="1216" y2="1280" x1="1056" />
            <wire x2="1536" y1="1216" y2="1280" x1="1536" />
            <wire x2="2032" y1="1216" y2="1280" x1="2032" />
        </branch>
        <iomarker fontsize="28" x="464" y="1280" name="CLR" orien="R180" />
        <branch name="CLK">
            <wire x2="560" y1="1120" y2="1120" x1="496" />
            <wire x2="496" y1="1120" y2="1264" x1="496" />
            <wire x2="656" y1="1264" y2="1264" x1="496" />
            <wire x2="656" y1="1264" y2="1376" x1="656" />
            <wire x2="1024" y1="1376" y2="1376" x1="656" />
            <wire x2="656" y1="1376" y2="1376" x1="592" />
            <wire x2="1056" y1="1120" y2="1120" x1="1024" />
            <wire x2="1024" y1="1120" y2="1344" x1="1024" />
            <wire x2="1488" y1="1344" y2="1344" x1="1024" />
            <wire x2="1984" y1="1344" y2="1344" x1="1488" />
            <wire x2="2432" y1="1344" y2="1344" x1="1984" />
            <wire x2="1024" y1="1344" y2="1376" x1="1024" />
            <wire x2="1536" y1="1120" y2="1120" x1="1488" />
            <wire x2="1488" y1="1120" y2="1344" x1="1488" />
            <wire x2="2032" y1="1120" y2="1120" x1="1984" />
            <wire x2="1984" y1="1120" y2="1344" x1="1984" />
        </branch>
        <branch name="CLK">
            <wire x2="304" y1="1488" y2="1488" x1="112" />
            <wire x2="304" y1="1408" y2="1488" x1="304" />
            <wire x2="336" y1="1408" y2="1408" x1="304" />
        </branch>
        <iomarker fontsize="28" x="112" y="1488" name="CLK" orien="R180" />
        <instance x="336" y="1280" name="XLXI_6" orien="M180" />
        <branch name="XLXN_18">
            <wire x2="320" y1="1328" y2="1344" x1="320" />
            <wire x2="336" y1="1344" y2="1344" x1="320" />
        </branch>
        <branch name="XLXN_12">
            <wire x2="560" y1="992" y2="992" x1="464" />
        </branch>
        <instance x="64" y="1168" name="XLXI_5" orien="M180" />
        <branch name="XLXN_26">
            <wire x2="64" y1="736" y2="1232" x1="64" />
            <wire x2="944" y1="736" y2="736" x1="64" />
            <wire x2="960" y1="736" y2="736" x1="944" />
            <wire x2="960" y1="736" y2="992" x1="960" />
            <wire x2="960" y1="992" y2="992" x1="944" />
        </branch>
        <branch name="XLXN_27">
            <wire x2="32" y1="704" y2="1296" x1="32" />
            <wire x2="64" y1="1296" y2="1296" x1="32" />
            <wire x2="1024" y1="704" y2="704" x1="32" />
            <wire x2="1440" y1="704" y2="704" x1="1024" />
            <wire x2="1456" y1="704" y2="704" x1="1440" />
            <wire x2="1456" y1="704" y2="992" x1="1456" />
            <wire x2="1456" y1="992" y2="992" x1="1440" />
        </branch>
        <branch name="XLXN_28">
            <wire x2="16" y1="864" y2="1360" x1="16" />
            <wire x2="64" y1="1360" y2="1360" x1="16" />
            <wire x2="1984" y1="864" y2="864" x1="16" />
            <wire x2="1984" y1="864" y2="992" x1="1984" />
            <wire x2="1984" y1="992" y2="992" x1="1920" />
        </branch>
        <branch name="XLXN_29">
            <wire x2="48" y1="912" y2="1424" x1="48" />
            <wire x2="64" y1="1424" y2="1424" x1="48" />
            <wire x2="2512" y1="912" y2="912" x1="48" />
            <wire x2="2512" y1="912" y2="992" x1="2512" />
            <wire x2="2512" y1="992" y2="992" x1="2416" />
        </branch>
    </sheet>
</drawing>