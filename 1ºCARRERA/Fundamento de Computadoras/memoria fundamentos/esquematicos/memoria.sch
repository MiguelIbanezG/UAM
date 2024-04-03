<?xml version="1.0" encoding="UTF-8"?>
<drawing version="7">
    <attr value="spartan3" name="DeviceFamilyName">
        <trait delete="all:0" />
        <trait editname="all:0" />
        <trait edittrait="all:0" />
    </attr>
    <netlist>
        <signal name="Q2" />
        <signal name="Q1" />
        <signal name="Q0" />
        <signal name="S0" />
        <signal name="XLXN_7" />
        <signal name="XLXN_8" />
        <signal name="XLXN_9" />
        <signal name="XLXN_10" />
        <signal name="XLXN_11" />
        <signal name="XLXN_12" />
        <signal name="XLXN_13" />
        <signal name="XLXN_14" />
        <signal name="XLXN_15" />
        <signal name="XLXN_16" />
        <signal name="XLXN_17" />
        <signal name="XLXN_18" />
        <signal name="XLXN_19" />
        <signal name="XLXN_20" />
        <signal name="XLXN_21" />
        <signal name="XLXN_22" />
        <signal name="XLXN_23" />
        <signal name="XLXN_24" />
        <signal name="XLXN_25" />
        <signal name="XLXN_30" />
        <signal name="XLXN_31" />
        <signal name="XLXN_32" />
        <signal name="XLXN_33" />
        <signal name="XLXN_34" />
        <signal name="XLXN_35" />
        <signal name="XLXN_36" />
        <signal name="XLXN_37" />
        <signal name="XLXN_38" />
        <signal name="XLXN_39" />
        <signal name="XLXN_40" />
        <signal name="AD" />
        <signal name="D11" />
        <signal name="AI" />
        <signal name="VD" />
        <signal name="D00" />
        <signal name="XLXN_48" />
        <signal name="XLXN_49" />
        <signal name="XLXN_51" />
        <signal name="XLXN_52" />
        <signal name="XLXN_54" />
        <signal name="XLXN_55" />
        <signal name="VI" />
        <signal name="S1" />
        <signal name="XLXN_59" />
        <signal name="XLXN_60" />
        <signal name="XLXN_61" />
        <signal name="XLXN_62" />
        <signal name="D22" />
        <port polarity="Input" name="Q2" />
        <port polarity="Input" name="Q1" />
        <port polarity="Input" name="Q0" />
        <port polarity="Input" name="S0" />
        <port polarity="Output" name="AD" />
        <port polarity="Output" name="D11" />
        <port polarity="Output" name="AI" />
        <port polarity="Output" name="VD" />
        <port polarity="Output" name="D00" />
        <port polarity="Output" name="VI" />
        <port polarity="Input" name="S1" />
        <port polarity="Output" name="D22" />
        <blockdef name="rom32x1">
            <timestamp>2000-1-1T10:10:10</timestamp>
            <line x2="320" y1="-384" y2="-384" x1="384" />
            <line x2="64" y1="-192" y2="-192" x1="0" />
            <line x2="64" y1="-384" y2="-384" x1="0" />
            <line x2="64" y1="-320" y2="-320" x1="0" />
            <line x2="64" y1="-256" y2="-256" x1="0" />
            <line x2="64" y1="-128" y2="-128" x1="0" />
            <rect width="256" x="64" y="-448" height="384" />
        </blockdef>
        <block symbolname="rom32x1" name="D1">
            <attr value="0FF00FF0" name="INIT">
                <trait verilog="all:0 dp:1nosynth wsynop:1 wsynth:1" />
                <trait vhdl="all:0 gm:1nosynth wa:1 wd:1" />
                <trait valuetype="BitVector 32 h" />
            </attr>
            <blockpin signalname="S0" name="A0" />
            <blockpin signalname="S1" name="A1" />
            <blockpin signalname="Q0" name="A2" />
            <blockpin signalname="Q1" name="A3" />
            <blockpin signalname="Q2" name="A4" />
            <blockpin signalname="D11" name="O" />
        </block>
        <block symbolname="rom32x1" name="S">
            <attr value="F0000000" name="INIT">
                <trait verilog="all:0 dp:1nosynth wsynop:1 wsynth:1" />
                <trait vhdl="all:0 gm:1nosynth wa:1 wd:1" />
                <trait valuetype="BitVector 32 h" />
            </attr>
            <blockpin signalname="S0" name="A0" />
            <blockpin signalname="S1" name="A1" />
            <blockpin signalname="Q0" name="A2" />
            <blockpin signalname="Q1" name="A3" />
            <blockpin signalname="Q2" name="A4" />
            <blockpin signalname="AI" name="O" />
        </block>
        <block symbolname="rom32x1" name="A">
            <attr value="0000F000" name="INIT">
                <trait verilog="all:0 dp:1nosynth wsynop:1 wsynth:1" />
                <trait vhdl="all:0 gm:1nosynth wa:1 wd:1" />
                <trait valuetype="BitVector 32 h" />
            </attr>
            <blockpin signalname="S0" name="A0" />
            <blockpin signalname="S1" name="A1" />
            <blockpin signalname="Q0" name="A2" />
            <blockpin signalname="Q1" name="A3" />
            <blockpin signalname="Q2" name="A4" />
            <blockpin signalname="AD" name="O" />
        </block>
        <block symbolname="rom32x1" name="D2">
            <attr value="0FFFF000" name="INIT">
                <trait verilog="all:0 dp:1nosynth wsynop:1 wsynth:1" />
                <trait vhdl="all:0 gm:1nosynth wa:1 wd:1" />
                <trait valuetype="BitVector 32 h" />
            </attr>
            <blockpin signalname="S0" name="A0" />
            <blockpin signalname="S1" name="A1" />
            <blockpin signalname="Q0" name="A2" />
            <blockpin signalname="Q1" name="A3" />
            <blockpin signalname="Q2" name="A4" />
            <blockpin signalname="D22" name="O" />
        </block>
        <block symbolname="rom32x1" name="q">
            <attr value="0FFF0000" name="INIT">
                <trait verilog="all:0 dp:1nosynth wsynop:1 wsynth:1" />
                <trait vhdl="all:0 gm:1nosynth wa:1 wd:1" />
                <trait valuetype="BitVector 32 h" />
            </attr>
            <blockpin signalname="S0" name="A0" />
            <blockpin signalname="S1" name="A1" />
            <blockpin signalname="Q0" name="A2" />
            <blockpin signalname="Q1" name="A3" />
            <blockpin signalname="Q2" name="A4" />
            <blockpin signalname="VI" name="O" />
        </block>
        <block symbolname="rom32x1" name="D0">
            <attr value="0F0C0F0A" name="INIT">
                <trait verilog="all:0 dp:1nosynth wsynop:1 wsynth:1" />
                <trait vhdl="all:0 gm:1nosynth wa:1 wd:1" />
                <trait valuetype="BitVector 32 h" />
            </attr>
            <blockpin signalname="S0" name="A0" />
            <blockpin signalname="S1" name="A1" />
            <blockpin signalname="Q0" name="A2" />
            <blockpin signalname="Q1" name="A3" />
            <blockpin signalname="Q2" name="A4" />
            <blockpin signalname="D00" name="O" />
        </block>
        <block symbolname="rom32x1" name="Z">
            <attr value="00000FFF" name="INIT">
                <trait verilog="all:0 dp:1nosynth wsynop:1 wsynth:1" />
                <trait vhdl="all:0 gm:1nosynth wa:1 wd:1" />
                <trait valuetype="BitVector 32 h" />
            </attr>
            <blockpin signalname="S0" name="A0" />
            <blockpin signalname="S1" name="A1" />
            <blockpin signalname="Q0" name="A2" />
            <blockpin signalname="Q1" name="A3" />
            <blockpin signalname="Q2" name="A4" />
            <blockpin signalname="VD" name="O" />
        </block>
    </netlist>
    <sheet sheetnum="1" width="3520" height="2720">
        <branch name="Q2">
            <wire x2="432" y1="272" y2="272" x1="272" />
            <wire x2="592" y1="272" y2="272" x1="432" />
            <wire x2="592" y1="272" y2="1056" x1="592" />
            <wire x2="592" y1="1056" y2="2592" x1="592" />
            <wire x2="1392" y1="2592" y2="2592" x1="592" />
            <wire x2="944" y1="1056" y2="1056" x1="592" />
            <wire x2="944" y1="1056" y2="2000" x1="944" />
            <wire x2="1344" y1="2000" y2="2000" x1="944" />
            <wire x2="1360" y1="272" y2="272" x1="592" />
            <wire x2="1360" y1="272" y2="1072" x1="1360" />
            <wire x2="1984" y1="1072" y2="1072" x1="1360" />
            <wire x2="1984" y1="1072" y2="2512" x1="1984" />
            <wire x2="2240" y1="2512" y2="2512" x1="1984" />
            <wire x2="432" y1="272" y2="336" x1="432" />
            <wire x2="1392" y1="336" y2="336" x1="432" />
            <wire x2="1392" y1="336" y2="992" x1="1392" />
            <wire x2="2128" y1="992" y2="992" x1="1392" />
            <wire x2="432" y1="256" y2="256" x1="336" />
            <wire x2="432" y1="256" y2="272" x1="432" />
            <wire x2="336" y1="256" y2="1152" x1="336" />
            <wire x2="2560" y1="1152" y2="1152" x1="336" />
            <wire x2="2560" y1="1152" y2="1552" x1="2560" />
            <wire x2="2624" y1="1552" y2="1552" x1="2560" />
            <wire x2="1312" y1="1072" y2="2096" x1="1312" />
            <wire x2="1952" y1="2096" y2="2096" x1="1312" />
            <wire x2="1360" y1="1072" y2="1072" x1="1312" />
            <wire x2="2768" y1="1040" y2="1040" x1="2560" />
            <wire x2="2560" y1="1040" y2="1152" x1="2560" />
        </branch>
        <branch name="Q1">
            <wire x2="432" y1="384" y2="384" x1="288" />
            <wire x2="672" y1="384" y2="384" x1="432" />
            <wire x2="672" y1="384" y2="992" x1="672" />
            <wire x2="672" y1="992" y2="2528" x1="672" />
            <wire x2="1392" y1="2528" y2="2528" x1="672" />
            <wire x2="1008" y1="992" y2="992" x1="672" />
            <wire x2="1008" y1="992" y2="1936" x1="1008" />
            <wire x2="1344" y1="1936" y2="1936" x1="1008" />
            <wire x2="1280" y1="384" y2="384" x1="672" />
            <wire x2="1280" y1="384" y2="400" x1="1280" />
            <wire x2="1888" y1="400" y2="400" x1="1280" />
            <wire x2="1888" y1="400" y2="2448" x1="1888" />
            <wire x2="2240" y1="2448" y2="2448" x1="1888" />
            <wire x2="1936" y1="384" y2="384" x1="1280" />
            <wire x2="1936" y1="384" y2="2032" x1="1936" />
            <wire x2="1952" y1="2032" y2="2032" x1="1936" />
            <wire x2="432" y1="384" y2="416" x1="432" />
            <wire x2="512" y1="416" y2="416" x1="432" />
            <wire x2="512" y1="416" y2="928" x1="512" />
            <wire x2="2128" y1="928" y2="928" x1="512" />
            <wire x2="432" y1="352" y2="384" x1="432" />
            <wire x2="2576" y1="352" y2="352" x1="432" />
            <wire x2="2576" y1="352" y2="368" x1="2576" />
            <wire x2="2592" y1="368" y2="368" x1="2576" />
            <wire x2="2592" y1="368" y2="976" x1="2592" />
            <wire x2="2768" y1="976" y2="976" x1="2592" />
            <wire x2="2576" y1="368" y2="368" x1="2064" />
            <wire x2="2064" y1="368" y2="1488" x1="2064" />
            <wire x2="2624" y1="1488" y2="1488" x1="2064" />
        </branch>
        <branch name="S0">
            <wire x2="480" y1="704" y2="704" x1="304" />
            <wire x2="576" y1="704" y2="704" x1="480" />
            <wire x2="576" y1="704" y2="2336" x1="576" />
            <wire x2="1392" y1="2336" y2="2336" x1="576" />
            <wire x2="960" y1="704" y2="704" x1="576" />
            <wire x2="960" y1="704" y2="1744" x1="960" />
            <wire x2="1344" y1="1744" y2="1744" x1="960" />
            <wire x2="480" y1="704" y2="720" x1="480" />
            <wire x2="2032" y1="720" y2="720" x1="480" />
            <wire x2="2032" y1="720" y2="736" x1="2032" />
            <wire x2="2128" y1="736" y2="736" x1="2032" />
            <wire x2="576" y1="672" y2="704" x1="576" />
            <wire x2="1296" y1="672" y2="672" x1="576" />
            <wire x2="1296" y1="672" y2="832" x1="1296" />
            <wire x2="1824" y1="832" y2="832" x1="1296" />
            <wire x2="1824" y1="832" y2="2256" x1="1824" />
            <wire x2="2240" y1="2256" y2="2256" x1="1824" />
            <wire x2="1296" y1="832" y2="848" x1="1296" />
            <wire x2="1808" y1="848" y2="848" x1="1296" />
            <wire x2="1808" y1="848" y2="1840" x1="1808" />
            <wire x2="1952" y1="1840" y2="1840" x1="1808" />
            <wire x2="2032" y1="592" y2="720" x1="2032" />
            <wire x2="2560" y1="592" y2="592" x1="2032" />
            <wire x2="2560" y1="592" y2="608" x1="2560" />
            <wire x2="2560" y1="608" y2="784" x1="2560" />
            <wire x2="2768" y1="784" y2="784" x1="2560" />
            <wire x2="2560" y1="608" y2="608" x1="2544" />
            <wire x2="2544" y1="608" y2="1296" x1="2544" />
            <wire x2="2624" y1="1296" y2="1296" x1="2544" />
        </branch>
        <iomarker fontsize="28" x="272" y="272" name="Q2" orien="R180" />
        <iomarker fontsize="28" x="288" y="384" name="Q1" orien="R180" />
        <iomarker fontsize="28" x="288" y="496" name="Q0" orien="R180" />
        <iomarker fontsize="28" x="288" y="608" name="S1" orien="R180" />
        <iomarker fontsize="28" x="304" y="704" name="S0" orien="R180" />
        <instance x="2240" y="2640" name="S" orien="R0">
            <attrtext style="fontsize:28;fontname:Arial;displayformat:NAMEEQUALSVALUE" attrname="INIT" x="192" y="-298" type="instance" />
            <attrtext style="fontsize:28;fontname:Arial" attrname="InstName" x="0" y="-64" type="instance" />
        </instance>
        <instance x="1392" y="2720" name="A" orien="R0">
            <attrtext style="fontsize:28;fontname:Arial;displayformat:NAMEEQUALSVALUE" attrname="INIT" x="0" y="-532" type="instance" />
            <attrtext style="fontsize:28;fontname:Arial" attrname="InstName" x="0" y="-64" type="instance" />
        </instance>
        <instance x="1952" y="2224" name="D1" orien="R0">
            <attrtext style="fontsize:28;fontname:Arial" attrname="InstName" x="0" y="-64" type="instance" />
            <attrtext style="fontsize:28;fontname:Arial;displayformat:NAMEEQUALSVALUE" attrname="INIT" x="0" y="-532" type="instance" />
        </instance>
        <branch name="Q0">
            <wire x2="400" y1="496" y2="496" x1="288" />
            <wire x2="608" y1="496" y2="496" x1="400" />
            <wire x2="400" y1="496" y2="864" x1="400" />
            <wire x2="2128" y1="864" y2="864" x1="400" />
            <wire x2="400" y1="464" y2="496" x1="400" />
            <wire x2="2512" y1="464" y2="464" x1="400" />
            <wire x2="2512" y1="464" y2="480" x1="2512" />
            <wire x2="2640" y1="480" y2="480" x1="2512" />
            <wire x2="2640" y1="480" y2="912" x1="2640" />
            <wire x2="2768" y1="912" y2="912" x1="2640" />
            <wire x2="608" y1="480" y2="496" x1="608" />
            <wire x2="720" y1="480" y2="480" x1="608" />
            <wire x2="784" y1="480" y2="480" x1="720" />
            <wire x2="1264" y1="480" y2="480" x1="784" />
            <wire x2="1264" y1="480" y2="960" x1="1264" />
            <wire x2="1264" y1="960" y2="976" x1="1264" />
            <wire x2="1920" y1="976" y2="976" x1="1264" />
            <wire x2="1920" y1="976" y2="2384" x1="1920" />
            <wire x2="2240" y1="2384" y2="2384" x1="1920" />
            <wire x2="1872" y1="960" y2="960" x1="1264" />
            <wire x2="1872" y1="960" y2="1968" x1="1872" />
            <wire x2="1952" y1="1968" y2="1968" x1="1872" />
            <wire x2="784" y1="480" y2="2464" x1="784" />
            <wire x2="1392" y1="2464" y2="2464" x1="784" />
            <wire x2="720" y1="480" y2="1872" x1="720" />
            <wire x2="1344" y1="1872" y2="1872" x1="720" />
            <wire x2="2512" y1="480" y2="480" x1="2096" />
            <wire x2="2096" y1="480" y2="1424" x1="2096" />
            <wire x2="2624" y1="1424" y2="1424" x1="2096" />
        </branch>
        <branch name="AD">
            <wire x2="1840" y1="2336" y2="2336" x1="1776" />
            <wire x2="1840" y1="2336" y2="2480" x1="1840" />
        </branch>
        <iomarker fontsize="28" x="1840" y="2480" name="AD" orien="R90" />
        <branch name="D11">
            <wire x2="2576" y1="1840" y2="1840" x1="2336" />
        </branch>
        <branch name="AI">
            <wire x2="2768" y1="2256" y2="2256" x1="2624" />
        </branch>
        <instance x="2128" y="1120" name="q" orien="R0">
            <attrtext style="fontsize:28;fontname:Arial;displayformat:NAMEEQUALSVALUE" attrname="INIT" x="0" y="-532" type="instance" />
            <attrtext style="fontsize:28;fontname:Arial" attrname="InstName" x="0" y="-64" type="instance" />
        </instance>
        <instance x="2624" y="1680" name="Z" orien="R0">
            <attrtext style="fontsize:28;fontname:Arial;displayformat:NAMEEQUALSVALUE" attrname="INIT" x="0" y="-532" type="instance" />
        </instance>
        <branch name="VD">
            <wire x2="3152" y1="1296" y2="1296" x1="3008" />
        </branch>
        <instance x="2768" y="1168" name="D0" orien="R0">
            <attrtext style="fontsize:28;fontname:Arial;displayformat:NAMEEQUALSVALUE" attrname="INIT" x="0" y="-532" type="instance" />
            <attrtext style="fontsize:28;fontname:Arial" attrname="InstName" x="0" y="-64" type="instance" />
        </instance>
        <branch name="D00">
            <wire x2="3232" y1="784" y2="784" x1="3152" />
        </branch>
        <branch name="VI">
            <wire x2="2528" y1="736" y2="736" x1="2512" />
            <wire x2="2528" y1="736" y2="816" x1="2528" />
            <wire x2="2528" y1="816" y2="816" x1="2512" />
        </branch>
        <iomarker fontsize="28" x="2576" y="1840" name="D11" orien="R0" />
        <iomarker fontsize="28" x="2768" y="2256" name="AI" orien="R0" />
        <iomarker fontsize="28" x="3152" y="1296" name="VD" orien="R0" />
        <iomarker fontsize="28" x="3232" y="784" name="D00" orien="R0" />
        <iomarker fontsize="28" x="2512" y="816" name="VI" orien="R180" />
        <branch name="S1">
            <wire x2="432" y1="608" y2="608" x1="288" />
            <wire x2="432" y1="608" y2="784" x1="432" />
            <wire x2="2048" y1="784" y2="784" x1="432" />
            <wire x2="2048" y1="784" y2="800" x1="2048" />
            <wire x2="2128" y1="800" y2="800" x1="2048" />
            <wire x2="688" y1="608" y2="608" x1="432" />
            <wire x2="768" y1="608" y2="608" x1="688" />
            <wire x2="1248" y1="608" y2="608" x1="768" />
            <wire x2="1248" y1="608" y2="896" x1="1248" />
            <wire x2="1248" y1="896" y2="912" x1="1248" />
            <wire x2="1840" y1="912" y2="912" x1="1248" />
            <wire x2="1840" y1="912" y2="2320" x1="1840" />
            <wire x2="2240" y1="2320" y2="2320" x1="1840" />
            <wire x2="1792" y1="896" y2="896" x1="1248" />
            <wire x2="1792" y1="896" y2="1904" x1="1792" />
            <wire x2="1952" y1="1904" y2="1904" x1="1792" />
            <wire x2="768" y1="608" y2="2400" x1="768" />
            <wire x2="1392" y1="2400" y2="2400" x1="768" />
            <wire x2="688" y1="608" y2="1808" x1="688" />
            <wire x2="1344" y1="1808" y2="1808" x1="688" />
            <wire x2="2048" y1="608" y2="784" x1="2048" />
            <wire x2="2576" y1="608" y2="608" x1="2048" />
            <wire x2="2576" y1="608" y2="848" x1="2576" />
            <wire x2="2768" y1="848" y2="848" x1="2576" />
            <wire x2="2528" y1="848" y2="1360" x1="2528" />
            <wire x2="2624" y1="1360" y2="1360" x1="2528" />
            <wire x2="2576" y1="848" y2="848" x1="2528" />
        </branch>
        <instance x="1344" y="2128" name="D2" orien="R0">
            <attrtext style="fontsize:28;fontname:Arial" attrname="InstName" x="0" y="-64" type="instance" />
            <attrtext style="fontsize:28;fontname:Arial;displayformat:NAMEEQUALSVALUE" attrname="INIT" x="0" y="-532" type="instance" />
        </instance>
        <branch name="D22">
            <wire x2="1728" y1="1472" y2="1472" x1="1616" />
            <wire x2="1744" y1="1472" y2="1472" x1="1728" />
            <wire x2="1744" y1="1472" y2="1744" x1="1744" />
            <wire x2="1744" y1="1744" y2="1744" x1="1728" />
        </branch>
        <iomarker fontsize="28" x="1616" y="1472" name="D22" orien="R180" />
    </sheet>
</drawing>