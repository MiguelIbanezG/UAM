<?xml version="1.0" encoding="UTF-8"?>
<drawing version="7">
    <attr value="spartan3" name="DeviceFamilyName">
        <trait delete="all:0" />
        <trait editname="all:0" />
        <trait edittrait="all:0" />
    </attr>
    <netlist>
        <signal name="XLXN_1" />
        <signal name="XLXN_2" />
        <signal name="XLXN_3" />
        <signal name="XLXN_4" />
        <signal name="XLXN_6" />
        <signal name="XLXN_8" />
        <signal name="XLXN_9" />
        <signal name="XLXN_10" />
        <signal name="XLXN_11" />
        <signal name="XLXN_13" />
        <signal name="XLXN_14" />
        <signal name="Z" />
        <signal name="A" />
        <signal name="XLXN_31" />
        <signal name="B" />
        <signal name="C" />
        <signal name="D" />
        <signal name="XLXN_36" />
        <port polarity="Output" name="Z" />
        <port polarity="Input" name="A" />
        <port polarity="Input" name="B" />
        <port polarity="Input" name="C" />
        <port polarity="Input" name="D" />
        <blockdef name="and2">
            <timestamp>2000-1-1T10:10:10</timestamp>
            <line x2="64" y1="-64" y2="-64" x1="0" />
            <line x2="64" y1="-128" y2="-128" x1="0" />
            <line x2="192" y1="-96" y2="-96" x1="256" />
            <arc ex="144" ey="-144" sx="144" sy="-48" r="48" cx="144" cy="-96" />
            <line x2="64" y1="-48" y2="-48" x1="144" />
            <line x2="144" y1="-144" y2="-144" x1="64" />
            <line x2="64" y1="-48" y2="-144" x1="64" />
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
        <blockdef name="inv">
            <timestamp>2000-1-1T10:10:10</timestamp>
            <line x2="64" y1="-32" y2="-32" x1="0" />
            <line x2="160" y1="-32" y2="-32" x1="224" />
            <line x2="128" y1="-64" y2="-32" x1="64" />
            <line x2="64" y1="-32" y2="0" x1="128" />
            <line x2="64" y1="0" y2="-64" x1="64" />
            <circle r="16" cx="144" cy="-32" />
        </blockdef>
        <block symbolname="and2" name="XLXI_1">
            <blockpin signalname="XLXN_3" name="I0" />
            <blockpin signalname="XLXN_4" name="I1" />
            <blockpin signalname="XLXN_14" name="O" />
        </block>
        <block symbolname="and2" name="XLXI_3">
            <blockpin signalname="B" name="I0" />
            <blockpin signalname="D" name="I1" />
            <blockpin signalname="XLXN_8" name="O" />
        </block>
        <block symbolname="and2" name="XLXI_4">
            <blockpin signalname="XLXN_1" name="I0" />
            <blockpin signalname="XLXN_3" name="I1" />
            <blockpin signalname="XLXN_6" name="O" />
        </block>
        <block symbolname="or2" name="XLXI_5">
            <blockpin signalname="XLXN_13" name="I0" />
            <blockpin signalname="XLXN_14" name="I1" />
            <blockpin signalname="Z" name="O" />
        </block>
        <block symbolname="or2" name="XLXI_6">
            <blockpin signalname="XLXN_6" name="I0" />
            <blockpin signalname="XLXN_8" name="I1" />
            <blockpin signalname="XLXN_11" name="O" />
        </block>
        <block symbolname="inv" name="XLXI_7">
            <blockpin signalname="D" name="I" />
            <blockpin signalname="XLXN_1" name="O" />
        </block>
        <block symbolname="inv" name="XLXI_9">
            <blockpin signalname="C" name="I" />
            <blockpin signalname="XLXN_10" name="O" />
        </block>
        <block symbolname="inv" name="XLXI_10">
            <blockpin signalname="B" name="I" />
            <blockpin signalname="XLXN_3" name="O" />
        </block>
        <block symbolname="and2" name="XLXI_2">
            <blockpin signalname="XLXN_11" name="I0" />
            <blockpin signalname="XLXN_10" name="I1" />
            <blockpin signalname="XLXN_13" name="O" />
        </block>
        <block symbolname="inv" name="XLXI_8">
            <blockpin signalname="A" name="I" />
            <blockpin signalname="XLXN_4" name="O" />
        </block>
    </netlist>
    <sheet sheetnum="1" width="3520" height="2720">
        <instance x="1520" y="1120" name="XLXI_1" orien="R0" />
        <instance x="1504" y="1488" name="XLXI_3" orien="R0" />
        <instance x="1520" y="1712" name="XLXI_4" orien="R0" />
        <instance x="2048" y="1536" name="XLXI_6" orien="R0" />
        <instance x="784" y="1680" name="XLXI_7" orien="R0" />
        <instance x="784" y="1600" name="XLXI_10" orien="R0" />
        <branch name="XLXN_1">
            <wire x2="1520" y1="1648" y2="1648" x1="1008" />
        </branch>
        <branch name="XLXN_3">
            <wire x2="1040" y1="1568" y2="1568" x1="1008" />
            <wire x2="1264" y1="1568" y2="1568" x1="1040" />
            <wire x2="1264" y1="1568" y2="1584" x1="1264" />
            <wire x2="1520" y1="1584" y2="1584" x1="1264" />
            <wire x2="1520" y1="1056" y2="1056" x1="1040" />
            <wire x2="1040" y1="1056" y2="1568" x1="1040" />
        </branch>
        <branch name="XLXN_4">
            <wire x2="1520" y1="992" y2="992" x1="880" />
        </branch>
        <branch name="XLXN_6">
            <wire x2="1904" y1="1616" y2="1616" x1="1776" />
            <wire x2="1904" y1="1472" y2="1616" x1="1904" />
            <wire x2="2048" y1="1472" y2="1472" x1="1904" />
        </branch>
        <branch name="XLXN_8">
            <wire x2="1904" y1="1392" y2="1392" x1="1760" />
            <wire x2="1904" y1="1392" y2="1408" x1="1904" />
            <wire x2="2048" y1="1408" y2="1408" x1="1904" />
        </branch>
        <instance x="1216" y="1312" name="XLXI_9" orien="R0" />
        <branch name="XLXN_10">
            <wire x2="1456" y1="1280" y2="1280" x1="1440" />
            <wire x2="1456" y1="1280" y2="1328" x1="1456" />
            <wire x2="2416" y1="1328" y2="1328" x1="1456" />
        </branch>
        <branch name="XLXN_11">
            <wire x2="2352" y1="1440" y2="1440" x1="2304" />
            <wire x2="2352" y1="1392" y2="1440" x1="2352" />
            <wire x2="2416" y1="1392" y2="1392" x1="2352" />
        </branch>
        <instance x="2736" y="1360" name="XLXI_5" orien="R0" />
        <branch name="XLXN_13">
            <wire x2="2704" y1="1360" y2="1360" x1="2672" />
            <wire x2="2704" y1="1296" y2="1360" x1="2704" />
            <wire x2="2736" y1="1296" y2="1296" x1="2704" />
        </branch>
        <instance x="2416" y="1456" name="XLXI_2" orien="R0" />
        <branch name="XLXN_14">
            <wire x2="2256" y1="1024" y2="1024" x1="1776" />
            <wire x2="2256" y1="1024" y2="1232" x1="2256" />
            <wire x2="2736" y1="1232" y2="1232" x1="2256" />
        </branch>
        <branch name="Z">
            <wire x2="3104" y1="1264" y2="1264" x1="2992" />
        </branch>
        <instance x="656" y="1024" name="XLXI_8" orien="R0" />
        <branch name="A">
            <wire x2="640" y1="1360" y2="1360" x1="528" />
            <wire x2="656" y1="992" y2="992" x1="640" />
            <wire x2="640" y1="992" y2="1360" x1="640" />
        </branch>
        <branch name="B">
            <wire x2="672" y1="1424" y2="1424" x1="544" />
            <wire x2="672" y1="1424" y2="1440" x1="672" />
            <wire x2="672" y1="1440" y2="1568" x1="672" />
            <wire x2="784" y1="1568" y2="1568" x1="672" />
            <wire x2="1088" y1="1440" y2="1440" x1="672" />
            <wire x2="1088" y1="1424" y2="1440" x1="1088" />
            <wire x2="1504" y1="1424" y2="1424" x1="1088" />
        </branch>
        <branch name="C">
            <wire x2="880" y1="1504" y2="1504" x1="544" />
            <wire x2="880" y1="1280" y2="1504" x1="880" />
            <wire x2="1216" y1="1280" y2="1280" x1="880" />
        </branch>
        <branch name="D">
            <wire x2="704" y1="1648" y2="1648" x1="560" />
            <wire x2="784" y1="1648" y2="1648" x1="704" />
            <wire x2="1504" y1="1360" y2="1360" x1="704" />
            <wire x2="704" y1="1360" y2="1648" x1="704" />
        </branch>
        <iomarker fontsize="28" x="528" y="1360" name="A" orien="R180" />
        <iomarker fontsize="28" x="544" y="1424" name="B" orien="R180" />
        <iomarker fontsize="28" x="544" y="1504" name="C" orien="R180" />
        <iomarker fontsize="28" x="560" y="1648" name="D" orien="R180" />
        <iomarker fontsize="28" x="3104" y="1264" name="Z" orien="R0" />
        <text style="fontsize:36;fontname:Arial" x="380" y="1348">SWI1</text>
        <text style="fontsize:36;fontname:Arial" x="392" y="1416">SWI2</text>
        <text style="fontsize:36;fontname:Arial" x="392" y="1496">SWI3</text>
        <text style="fontsize:36;fontname:Arial" x="400" y="1640">SWI4</text>
        <text style="fontsize:36;fontname:Arial" x="3080" y="1212">LED</text>
        <text style="fontsize:36;fontname:Arial" x="1276" y="1336">74HC04</text>
        <text style="fontsize:36;fontname:Arial" x="912" y="1520">74HC04</text>
        <text style="fontsize:36;fontname:Arial" x="908" y="1700">74HC04</text>
        <text style="fontsize:36;fontname:Arial" x="1632" y="1552">74HC08</text>
        <text style="fontsize:36;fontname:Arial" x="2808" y="1188">74HC32</text>
        <text style="fontsize:36;fontname:Arial" x="764" y="944">74HC04</text>
        <text style="fontsize:36;fontname:Arial" x="844" y="1020">2</text>
        <text style="fontsize:36;fontname:Arial" x="684" y="964">1</text>
        <text style="fontsize:36;fontname:Arial" x="1548" y="964">1</text>
        <text style="fontsize:36;fontname:Arial" x="1740" y="996">3</text>
        <text style="fontsize:36;fontname:Arial" x="2752" y="1208">1</text>
        <text style="fontsize:36;fontname:Arial" x="2960" y="1236">3</text>
        <text style="fontsize:36;fontname:Arial" x="1544" y="1032">2</text>
        <text style="fontsize:36;fontname:Arial" x="820" y="1544">3</text>
        <text style="fontsize:36;fontname:Arial" x="956" y="1584">4</text>
        <text style="fontsize:36;fontname:Arial" x="1236" y="1252">5</text>
        <text style="fontsize:36;fontname:Arial" x="1396" y="1252">6</text>
        <text style="fontsize:36;fontname:Arial" x="1528" y="1352">4</text>
        <text style="fontsize:36;fontname:Arial" x="1536" y="1408">5</text>
        <text style="fontsize:36;fontname:Arial" x="1712" y="1372">6</text>
        <text style="fontsize:36;fontname:Arial" x="1552" y="1564">9</text>
        <text style="fontsize:36;fontname:Arial" x="1524" y="1628">10</text>
        <text style="fontsize:36;fontname:Arial" x="1736" y="1596">11</text>
        <text style="fontsize:36;fontname:Arial" x="2432" y="1300">12</text>
        <text style="fontsize:36;fontname:Arial" x="2432" y="1376">13</text>
        <text style="fontsize:36;fontname:Arial" x="2628" y="1340">14</text>
        <text style="fontsize:36;fontname:Arial" x="2756" y="1272">2</text>
        <text style="fontsize:36;fontname:Arial" x="2060" y="1384">4</text>
        <text style="fontsize:36;fontname:Arial" x="2064" y="1452">5</text>
        <text style="fontsize:36;fontname:Arial" x="2252" y="1420">6</text>
        <text style="fontsize:36;fontname:Arial" x="796" y="1628">9</text>
        <text style="fontsize:36;fontname:Arial" x="952" y="1628">10</text>
        <text style="fontsize:36;fontname:Arial" x="1584" y="1028">74HC08</text>
        <text style="fontsize:36;fontname:Arial" x="1564" y="1392">74HC08</text>
        <text style="fontsize:36;fontname:Arial" x="2112" y="1448">74HC32</text>
        <text style="fontsize:36;fontname:Arial" x="2548" y="1416">74HC08</text>
    </sheet>
</drawing>