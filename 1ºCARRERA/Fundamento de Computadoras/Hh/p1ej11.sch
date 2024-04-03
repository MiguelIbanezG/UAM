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
        <signal name="XLXN_9" />
        <signal name="XLXN_10" />
        <signal name="XLXN_11" />
        <signal name="CLR" />
        <signal name="XLXN_14" />
        <signal name="XLXN_15" />
        <signal name="XLXN_16" />
        <signal name="CLK" />
        <signal name="Q0" />
        <signal name="Q1" />
        <signal name="Q2" />
        <signal name="Q3" />
        <signal name="XLXN_22" />
        <signal name="XLXN_23" />
        <signal name="XLXN_25" />
        <signal name="XLXN_26" />
        <signal name="XLXN_27" />
        <signal name="XLXN_29" />
        <signal name="XLXN_30" />
        <port polarity="Input" name="CLR" />
        <port polarity="Input" name="CLK" />
        <port polarity="Output" name="Q0" />
        <port polarity="Output" name="Q1" />
        <port polarity="Output" name="Q2" />
        <port polarity="Output" name="Q3" />
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
        <blockdef name="inv">
            <timestamp>2000-1-1T10:10:10</timestamp>
            <line x2="64" y1="-32" y2="-32" x1="0" />
            <line x2="160" y1="-32" y2="-32" x1="224" />
            <line x2="128" y1="-64" y2="-32" x1="64" />
            <line x2="64" y1="-32" y2="0" x1="128" />
            <line x2="64" y1="0" y2="-64" x1="64" />
            <circle r="16" cx="144" cy="-32" />
        </blockdef>
        <block symbolname="fdc" name="XLXI_5">
            <blockpin signalname="CLK" name="C" />
            <blockpin signalname="CLR" name="CLR" />
            <blockpin signalname="XLXN_30" name="D" />
            <blockpin signalname="Q0" name="Q" />
        </block>
        <block symbolname="fdc" name="XLXI_6">
            <blockpin signalname="CLK" name="C" />
            <blockpin signalname="CLR" name="CLR" />
            <blockpin signalname="Q0" name="D" />
            <blockpin signalname="Q1" name="Q" />
        </block>
        <block symbolname="fdc" name="XLXI_7">
            <blockpin signalname="CLK" name="C" />
            <blockpin signalname="CLR" name="CLR" />
            <blockpin signalname="Q1" name="D" />
            <blockpin signalname="Q2" name="Q" />
        </block>
        <block symbolname="fdc" name="XLXI_8">
            <blockpin signalname="CLK" name="C" />
            <blockpin signalname="CLR" name="CLR" />
            <blockpin signalname="Q2" name="D" />
            <blockpin signalname="Q3" name="Q" />
        </block>
        <block symbolname="or2" name="XLXI_9">
            <blockpin signalname="CLR" name="I0" />
            <blockpin signalname="XLXN_23" name="I1" />
            <blockpin signalname="CLR" name="O" />
        </block>
        <block symbolname="and4" name="XLXI_10">
            <blockpin signalname="Q3" name="I0" />
            <blockpin signalname="Q2" name="I1" />
            <blockpin signalname="Q1" name="I2" />
            <blockpin signalname="XLXN_25" name="I3" />
            <blockpin signalname="XLXN_23" name="O" />
        </block>
        <block symbolname="inv" name="XLXI_11">
            <blockpin signalname="Q0" name="I" />
            <blockpin signalname="XLXN_25" name="O" />
        </block>
        <block symbolname="inv" name="XLXI_13">
            <blockpin signalname="Q3" name="I" />
            <blockpin signalname="XLXN_30" name="O" />
        </block>
    </netlist>
    <sheet sheetnum="1" width="3520" height="2720">
        <instance x="864" y="1216" name="XLXI_5" orien="R0" />
        <instance x="1504" y="1200" name="XLXI_6" orien="R0" />
        <instance x="2144" y="1184" name="XLXI_7" orien="R0" />
        <instance x="2752" y="1184" name="XLXI_8" orien="R0" />
        <branch name="Q1">
            <wire x2="1920" y1="320" y2="320" x1="1248" />
            <wire x2="1920" y1="320" y2="944" x1="1920" />
            <wire x2="1936" y1="944" y2="944" x1="1920" />
            <wire x2="1984" y1="944" y2="944" x1="1936" />
            <wire x2="1936" y1="944" y2="1008" x1="1936" />
            <wire x2="2048" y1="1008" y2="1008" x1="1936" />
            <wire x2="1920" y1="944" y2="944" x1="1888" />
            <wire x2="1984" y1="928" y2="944" x1="1984" />
            <wire x2="2048" y1="928" y2="1008" x1="2048" />
            <wire x2="2144" y1="928" y2="928" x1="2048" />
        </branch>
        <branch name="Q2">
            <wire x2="2544" y1="256" y2="256" x1="1248" />
            <wire x2="2544" y1="256" y2="928" x1="2544" />
            <wire x2="2560" y1="928" y2="928" x1="2544" />
            <wire x2="2608" y1="928" y2="928" x1="2560" />
            <wire x2="2560" y1="928" y2="992" x1="2560" />
            <wire x2="2672" y1="992" y2="992" x1="2560" />
            <wire x2="2544" y1="928" y2="928" x1="2528" />
            <wire x2="2672" y1="928" y2="992" x1="2672" />
            <wire x2="2752" y1="928" y2="928" x1="2672" />
        </branch>
        <branch name="Q3">
            <wire x2="3200" y1="192" y2="192" x1="1248" />
            <wire x2="3200" y1="192" y2="944" x1="3200" />
            <wire x2="3184" y1="592" y2="592" x1="2320" />
            <wire x2="3184" y1="592" y2="928" x1="3184" />
            <wire x2="3216" y1="928" y2="928" x1="3184" />
            <wire x2="3152" y1="928" y2="928" x1="3136" />
            <wire x2="3152" y1="928" y2="944" x1="3152" />
            <wire x2="3200" y1="944" y2="944" x1="3152" />
            <wire x2="3184" y1="928" y2="928" x1="3152" />
        </branch>
        <iomarker fontsize="28" x="2608" y="928" name="Q2" orien="R0" />
        <iomarker fontsize="28" x="3216" y="928" name="Q3" orien="R0" />
        <iomarker fontsize="28" x="1984" y="928" name="Q1" orien="R270" />
        <iomarker fontsize="28" x="1312" y="960" name="Q0" orien="R0" />
        <instance x="592" y="1584" name="XLXI_9" orien="R0" />
        <instance x="1248" y="128" name="XLXI_10" orien="R180" />
        <branch name="XLXN_23">
            <wire x2="512" y1="288" y2="1456" x1="512" />
            <wire x2="592" y1="1456" y2="1456" x1="512" />
            <wire x2="992" y1="288" y2="288" x1="512" />
        </branch>
        <branch name="CLR">
            <wire x2="592" y1="1520" y2="1520" x1="512" />
        </branch>
        <iomarker fontsize="28" x="512" y="1520" name="CLR" orien="R180" />
        <iomarker fontsize="28" x="496" y="1328" name="CLK" orien="R180" />
        <instance x="1488" y="560" name="XLXI_11" orien="R180" />
        <branch name="XLXN_25">
            <wire x2="1248" y1="384" y2="592" x1="1248" />
            <wire x2="1264" y1="592" y2="592" x1="1248" />
        </branch>
        <branch name="Q0">
            <wire x2="1264" y1="960" y2="960" x1="1248" />
            <wire x2="1280" y1="960" y2="960" x1="1264" />
            <wire x2="1312" y1="960" y2="960" x1="1280" />
            <wire x2="1568" y1="864" y2="864" x1="1264" />
            <wire x2="1264" y1="864" y2="960" x1="1264" />
            <wire x2="1504" y1="848" y2="848" x1="1280" />
            <wire x2="1504" y1="848" y2="944" x1="1504" />
            <wire x2="1280" y1="848" y2="960" x1="1280" />
            <wire x2="1568" y1="592" y2="592" x1="1488" />
            <wire x2="1568" y1="592" y2="864" x1="1568" />
        </branch>
        <instance x="2320" y="560" name="XLXI_13" orien="R180" />
        <branch name="XLXN_30">
            <wire x2="800" y1="832" y2="960" x1="800" />
            <wire x2="864" y1="960" y2="960" x1="800" />
            <wire x2="880" y1="832" y2="832" x1="800" />
            <wire x2="1584" y1="672" y2="672" x1="880" />
            <wire x2="880" y1="672" y2="832" x1="880" />
            <wire x2="1584" y1="592" y2="672" x1="1584" />
            <wire x2="2096" y1="592" y2="592" x1="1584" />
        </branch>
        <branch name="CLK">
            <wire x2="720" y1="1328" y2="1328" x1="496" />
            <wire x2="1424" y1="1328" y2="1328" x1="720" />
            <wire x2="2048" y1="1328" y2="1328" x1="1424" />
            <wire x2="2688" y1="1328" y2="1328" x1="2048" />
            <wire x2="864" y1="1088" y2="1088" x1="720" />
            <wire x2="720" y1="1088" y2="1328" x1="720" />
            <wire x2="1504" y1="1072" y2="1072" x1="1424" />
            <wire x2="1424" y1="1072" y2="1328" x1="1424" />
            <wire x2="2144" y1="1056" y2="1056" x1="2048" />
            <wire x2="2048" y1="1056" y2="1328" x1="2048" />
            <wire x2="2752" y1="1056" y2="1056" x1="2688" />
            <wire x2="2688" y1="1056" y2="1328" x1="2688" />
        </branch>
        <branch name="CLR">
            <wire x2="864" y1="1184" y2="1184" x1="816" />
            <wire x2="816" y1="1184" y2="1488" x1="816" />
            <wire x2="848" y1="1488" y2="1488" x1="816" />
            <wire x2="1504" y1="1488" y2="1488" x1="848" />
            <wire x2="2160" y1="1488" y2="1488" x1="1504" />
            <wire x2="2752" y1="1488" y2="1488" x1="2160" />
            <wire x2="1504" y1="1168" y2="1488" x1="1504" />
            <wire x2="2144" y1="1152" y2="1312" x1="2144" />
            <wire x2="2160" y1="1312" y2="1312" x1="2144" />
            <wire x2="2160" y1="1312" y2="1488" x1="2160" />
            <wire x2="2752" y1="1152" y2="1488" x1="2752" />
        </branch>
    </sheet>
</drawing>