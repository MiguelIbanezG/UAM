<?xml version="1.0" encoding="UTF-8"?>
<drawing version="7">
    <attr value="spartan3" name="DeviceFamilyName">
        <trait delete="all:0" />
        <trait editname="all:0" />
        <trait edittrait="all:0" />
    </attr>
    <netlist>
        <signal name="S1" />
        <signal name="S0" />
        <signal name="XLXN_3" />
        <signal name="XLXN_4" />
        <signal name="XLXN_5" />
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
        <signal name="XLXN_23" />
        <signal name="XLXN_24" />
        <signal name="XLXN_25" />
        <signal name="XLXN_26" />
        <signal name="XLXN_30" />
        <signal name="XLXN_33" />
        <signal name="RI" />
        <signal name="XLXN_35" />
        <signal name="XLXN_36" />
        <signal name="XLXN_37" />
        <signal name="XLXN_38" />
        <signal name="XLXN_32" />
        <signal name="XLXN_40" />
        <signal name="AI" />
        <signal name="XLXN_42" />
        <signal name="XLXN_43" />
        <signal name="XLXN_45" />
        <signal name="VI" />
        <signal name="RD" />
        <signal name="XLXN_51" />
        <signal name="XLXN_52" />
        <signal name="AD" />
        <signal name="XLXN_54" />
        <signal name="XLXN_55" />
        <signal name="XLXN_56" />
        <signal name="VD" />
        <signal name="CLR" />
        <signal name="XLXN_60" />
        <signal name="CLK" />
        <port polarity="Input" name="S1" />
        <port polarity="Input" name="S0" />
        <port polarity="Output" name="XLXN_21" />
        <port polarity="Output" name="RI" />
        <port polarity="Output" name="AI" />
        <port polarity="Output" name="VI" />
        <port polarity="Output" name="RD" />
        <port polarity="Output" name="AD" />
        <port polarity="Output" name="VD" />
        <port polarity="Input" name="CLR" />
        <port polarity="Input" name="CLK" />
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
        <blockdef name="and3">
            <timestamp>2000-1-1T10:10:10</timestamp>
            <line x2="64" y1="-64" y2="-64" x1="0" />
            <line x2="64" y1="-128" y2="-128" x1="0" />
            <line x2="64" y1="-192" y2="-192" x1="0" />
            <line x2="192" y1="-128" y2="-128" x1="256" />
            <line x2="144" y1="-176" y2="-176" x1="64" />
            <line x2="64" y1="-80" y2="-80" x1="144" />
            <arc ex="144" ey="-176" sx="144" sy="-80" r="48" cx="144" cy="-128" />
            <line x2="64" y1="-64" y2="-192" x1="64" />
        </blockdef>
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
        <blockdef name="xor2">
            <timestamp>2000-1-1T10:10:10</timestamp>
            <line x2="64" y1="-64" y2="-64" x1="0" />
            <line x2="60" y1="-128" y2="-128" x1="0" />
            <line x2="208" y1="-96" y2="-96" x1="256" />
            <arc ex="44" ey="-144" sx="48" sy="-48" r="56" cx="16" cy="-96" />
            <arc ex="64" ey="-144" sx="64" sy="-48" r="56" cx="32" cy="-96" />
            <line x2="64" y1="-144" y2="-144" x1="128" />
            <line x2="64" y1="-48" y2="-48" x1="128" />
            <arc ex="128" ey="-144" sx="208" sy="-96" r="88" cx="132" cy="-56" />
            <arc ex="208" ey="-96" sx="128" sy="-48" r="88" cx="132" cy="-136" />
        </blockdef>
        <blockdef name="or3">
            <timestamp>2000-1-1T10:10:10</timestamp>
            <line x2="48" y1="-64" y2="-64" x1="0" />
            <line x2="72" y1="-128" y2="-128" x1="0" />
            <line x2="48" y1="-192" y2="-192" x1="0" />
            <line x2="192" y1="-128" y2="-128" x1="256" />
            <arc ex="192" ey="-128" sx="112" sy="-80" r="88" cx="116" cy="-168" />
            <arc ex="48" ey="-176" sx="48" sy="-80" r="56" cx="16" cy="-128" />
            <line x2="48" y1="-64" y2="-80" x1="48" />
            <line x2="48" y1="-192" y2="-176" x1="48" />
            <line x2="48" y1="-80" y2="-80" x1="112" />
            <arc ex="112" ey="-176" sx="192" sy="-128" r="88" cx="116" cy="-88" />
            <line x2="48" y1="-176" y2="-176" x1="112" />
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
        <block symbolname="fdc" name="XLXI_1">
            <blockpin signalname="CLK" name="C" />
            <blockpin signalname="CLR" name="CLR" />
            <blockpin signalname="XLXN_3" name="D" />
            <blockpin signalname="XLXN_52" name="Q" />
        </block>
        <block symbolname="fdc" name="XLXI_2">
            <blockpin signalname="CLK" name="C" />
            <blockpin signalname="CLR" name="CLR" />
            <blockpin signalname="XLXN_18" name="D" />
            <blockpin signalname="XLXN_32" name="Q" />
        </block>
        <block symbolname="fdc" name="XLXI_3">
            <blockpin signalname="CLK" name="C" />
            <blockpin signalname="CLR" name="CLR" />
            <blockpin signalname="XLXN_38" name="D" />
            <blockpin signalname="RD" name="Q" />
        </block>
        <block symbolname="and3" name="XLXI_5">
            <blockpin signalname="RI" name="I0" />
            <blockpin signalname="XLXN_45" name="I1" />
            <blockpin signalname="S1" name="I2" />
            <blockpin signalname="XLXN_5" name="O" />
        </block>
        <block symbolname="and3" name="XLXI_6">
            <blockpin signalname="RD" name="I0" />
            <blockpin signalname="XLXN_45" name="I1" />
            <blockpin signalname="S0" name="I2" />
            <blockpin signalname="XLXN_14" name="O" />
        </block>
        <block symbolname="and2" name="XLXI_7">
            <blockpin signalname="RD" name="I0" />
            <blockpin signalname="XLXN_24" name="I1" />
            <blockpin signalname="XLXN_37" name="O" />
        </block>
        <block symbolname="and2" name="XLXI_8">
            <blockpin signalname="XLXN_45" name="I0" />
            <blockpin signalname="XLXN_32" name="I1" />
            <blockpin signalname="XLXN_17" name="O" />
        </block>
        <block symbolname="and2" name="XLXI_9">
            <blockpin signalname="RD" name="I0" />
            <blockpin signalname="XLXN_45" name="I1" />
            <blockpin signalname="XLXN_36" name="O" />
        </block>
        <block symbolname="xor2" name="XLXI_10">
            <blockpin signalname="XLXN_32" name="I0" />
            <blockpin signalname="XLXN_52" name="I1" />
            <blockpin signalname="XLXN_18" name="O" />
        </block>
        <block symbolname="or3" name="XLXI_11">
            <blockpin signalname="XLXN_17" name="I0" />
            <blockpin signalname="XLXN_14" name="I1" />
            <blockpin signalname="XLXN_5" name="I2" />
            <blockpin signalname="XLXN_3" name="O" />
        </block>
        <block symbolname="or3" name="XLXI_12">
            <blockpin signalname="XLXN_37" name="I0" />
            <blockpin signalname="XLXN_36" name="I1" />
            <blockpin signalname="XLXN_35" name="I2" />
            <blockpin signalname="XLXN_38" name="O" />
        </block>
        <block symbolname="inv" name="XLXI_14">
            <blockpin signalname="RD" name="I" />
            <blockpin signalname="RI" name="O" />
        </block>
        <block symbolname="inv" name="XLXI_15">
            <blockpin signalname="XLXN_52" name="I" />
            <blockpin signalname="XLXN_45" name="O" />
        </block>
        <block symbolname="inv" name="XLXI_18">
            <blockpin signalname="XLXN_32" name="I" />
            <blockpin signalname="XLXN_24" name="O" />
        </block>
        <block symbolname="and3" name="XLXI_19">
            <blockpin signalname="XLXN_32" name="I0" />
            <blockpin signalname="XLXN_52" name="I1" />
            <blockpin signalname="RI" name="I2" />
            <blockpin signalname="XLXN_35" name="O" />
        </block>
        <block symbolname="and3" name="XLXI_20">
            <blockpin signalname="RD" name="I0" />
            <blockpin signalname="XLXN_32" name="I1" />
            <blockpin signalname="XLXN_52" name="I2" />
            <blockpin signalname="AI" name="O" />
        </block>
        <block symbolname="and2" name="XLXI_21">
            <blockpin signalname="RD" name="I0" />
            <blockpin signalname="XLXN_55" name="I1" />
            <blockpin signalname="VI" name="O" />
        </block>
        <block symbolname="or2" name="XLXI_22">
            <blockpin signalname="XLXN_24" name="I0" />
            <blockpin signalname="XLXN_45" name="I1" />
            <blockpin signalname="XLXN_55" name="O" />
        </block>
        <block symbolname="and3" name="XLXI_23">
            <blockpin signalname="XLXN_52" name="I0" />
            <blockpin signalname="XLXN_32" name="I1" />
            <blockpin signalname="RI" name="I2" />
            <blockpin signalname="AD" name="O" />
        </block>
        <block symbolname="and2" name="XLXI_24">
            <blockpin signalname="RI" name="I0" />
            <blockpin signalname="XLXN_55" name="I1" />
            <blockpin signalname="VD" name="O" />
        </block>
    </netlist>
    <sheet sheetnum="1" width="3520" height="2720">
        <branch name="S1">
            <attrtext style="alignment:SOFT-BCENTER;fontsize:28;fontname:Arial" attrname="Name" x="256" y="320" type="branch" />
            <wire x2="256" y1="320" y2="320" x1="176" />
            <wire x2="864" y1="320" y2="320" x1="256" />
            <wire x2="864" y1="320" y2="336" x1="864" />
        </branch>
        <branch name="S0">
            <attrtext style="alignment:SOFT-BCENTER;fontsize:28;fontname:Arial" attrname="Name" x="272" y="464" type="branch" />
            <wire x2="272" y1="464" y2="464" x1="176" />
            <wire x2="432" y1="464" y2="464" x1="272" />
        </branch>
        <iomarker fontsize="28" x="176" y="320" name="S1" orien="R180" />
        <iomarker fontsize="28" x="176" y="464" name="S0" orien="R180" />
        <instance x="720" y="1136" name="XLXI_1" orien="R0" />
        <branch name="XLXN_3">
            <wire x2="720" y1="880" y2="880" x1="688" />
        </branch>
        <instance x="432" y="1008" name="XLXI_11" orien="R0" />
        <instance x="864" y="528" name="XLXI_5" orien="R0" />
        <instance x="2272" y="1104" name="XLXI_3" orien="R0" />
        <instance x="1456" y="1120" name="XLXI_2" orien="R0" />
        <branch name="XLXN_5">
            <wire x2="432" y1="736" y2="816" x1="432" />
            <wire x2="1200" y1="736" y2="736" x1="432" />
            <wire x2="1200" y1="400" y2="400" x1="1120" />
            <wire x2="1200" y1="400" y2="736" x1="1200" />
        </branch>
        <instance x="2656" y="512" name="XLXI_14" orien="R180" />
        <instance x="1152" y="640" name="XLXI_15" orien="R180" />
        <instance x="432" y="656" name="XLXI_6" orien="R0" />
        <branch name="XLXN_14">
            <wire x2="368" y1="752" y2="880" x1="368" />
            <wire x2="432" y1="880" y2="880" x1="368" />
            <wire x2="752" y1="752" y2="752" x1="368" />
            <wire x2="752" y1="528" y2="528" x1="688" />
            <wire x2="752" y1="528" y2="752" x1="752" />
        </branch>
        <instance x="48" y="1040" name="XLXI_8" orien="R0" />
        <branch name="XLXN_17">
            <wire x2="432" y1="944" y2="944" x1="304" />
        </branch>
        <instance x="1136" y="1152" name="XLXI_10" orien="R0" />
        <branch name="XLXN_18">
            <wire x2="1424" y1="1056" y2="1056" x1="1392" />
            <wire x2="1424" y1="864" y2="1056" x1="1424" />
            <wire x2="1456" y1="864" y2="864" x1="1424" />
        </branch>
        <instance x="1616" y="480" name="XLXI_9" orien="R0" />
        <instance x="2208" y="336" name="XLXI_12" orien="R0" />
        <instance x="2032" y="1392" name="XLXI_18" orien="R0" />
        <instance x="2064" y="544" name="XLXI_7" orien="R0" />
        <branch name="XLXN_24">
            <wire x2="2064" y1="416" y2="416" x1="1984" />
            <wire x2="1984" y1="416" y2="1136" x1="1984" />
            <wire x2="2272" y1="1136" y2="1136" x1="1984" />
            <wire x2="2272" y1="1136" y2="1360" x1="2272" />
            <wire x2="2752" y1="1360" y2="1360" x1="2272" />
            <wire x2="2272" y1="1360" y2="1360" x1="2256" />
            <wire x2="2752" y1="1024" y2="1360" x1="2752" />
            <wire x2="2880" y1="1024" y2="1024" x1="2752" />
        </branch>
        <branch name="RD">
            <wire x2="432" y1="592" y2="592" x1="336" />
            <wire x2="336" y1="592" y2="1184" x1="336" />
            <wire x2="2144" y1="1184" y2="1184" x1="336" />
            <wire x2="2672" y1="1184" y2="1184" x1="2144" />
            <wire x2="1616" y1="416" y2="416" x1="1536" />
            <wire x2="1536" y1="416" y2="672" x1="1536" />
            <wire x2="2672" y1="672" y2="672" x1="1536" />
            <wire x2="2672" y1="672" y2="848" x1="2672" />
            <wire x2="2672" y1="848" y2="1184" x1="2672" />
            <wire x2="2800" y1="848" y2="848" x1="2672" />
            <wire x2="2928" y1="848" y2="848" x1="2800" />
            <wire x2="3232" y1="848" y2="848" x1="2928" />
            <wire x2="2800" y1="848" y2="1056" x1="2800" />
            <wire x2="3200" y1="1056" y2="1056" x1="2800" />
            <wire x2="2064" y1="480" y2="480" x1="2000" />
            <wire x2="2000" y1="480" y2="560" x1="2000" />
            <wire x2="2144" y1="560" y2="560" x1="2000" />
            <wire x2="2144" y1="560" y2="1184" x1="2144" />
            <wire x2="2672" y1="544" y2="544" x1="2656" />
            <wire x2="2672" y1="544" y2="672" x1="2672" />
            <wire x2="2672" y1="848" y2="848" x1="2656" />
            <wire x2="2928" y1="624" y2="848" x1="2928" />
        </branch>
        <instance x="1392" y="304" name="XLXI_19" orien="R0" />
        <branch name="RI">
            <wire x2="864" y1="464" y2="544" x1="864" />
            <wire x2="1328" y1="544" y2="544" x1="864" />
            <wire x2="1376" y1="544" y2="544" x1="1328" />
            <wire x2="2328" y1="544" y2="544" x1="1376" />
            <wire x2="2336" y1="544" y2="544" x1="2328" />
            <wire x2="2432" y1="544" y2="544" x1="2336" />
            <wire x2="1392" y1="112" y2="112" x1="1328" />
            <wire x2="1328" y1="112" y2="544" x1="1328" />
            <wire x2="2336" y1="384" y2="544" x1="2336" />
            <wire x2="2816" y1="384" y2="384" x1="2336" />
            <wire x2="2848" y1="384" y2="384" x1="2816" />
            <wire x2="2816" y1="384" y2="1184" x1="2816" />
            <wire x2="2944" y1="1184" y2="1184" x1="2816" />
            <wire x2="3184" y1="1184" y2="1184" x1="2944" />
            <wire x2="2944" y1="1184" y2="1568" x1="2944" />
            <wire x2="3120" y1="1568" y2="1568" x1="2944" />
        </branch>
        <branch name="XLXN_35">
            <wire x2="1920" y1="176" y2="176" x1="1648" />
            <wire x2="1920" y1="144" y2="176" x1="1920" />
            <wire x2="2208" y1="144" y2="144" x1="1920" />
        </branch>
        <branch name="XLXN_36">
            <wire x2="2032" y1="384" y2="384" x1="1872" />
            <wire x2="2032" y1="208" y2="384" x1="2032" />
            <wire x2="2208" y1="208" y2="208" x1="2032" />
        </branch>
        <branch name="XLXN_37">
            <wire x2="2208" y1="272" y2="352" x1="2208" />
            <wire x2="2384" y1="352" y2="352" x1="2208" />
            <wire x2="2384" y1="352" y2="448" x1="2384" />
            <wire x2="2384" y1="448" y2="448" x1="2320" />
        </branch>
        <branch name="XLXN_38">
            <wire x2="2272" y1="848" y2="848" x1="2208" />
            <wire x2="2208" y1="848" y2="1088" x1="2208" />
            <wire x2="2736" y1="1088" y2="1088" x1="2208" />
            <wire x2="2736" y1="208" y2="208" x1="2464" />
            <wire x2="2736" y1="208" y2="1088" x1="2736" />
        </branch>
        <branch name="XLXN_32">
            <wire x2="16" y1="768" y2="912" x1="16" />
            <wire x2="48" y1="912" y2="912" x1="16" />
            <wire x2="1312" y1="768" y2="768" x1="16" />
            <wire x2="1856" y1="768" y2="768" x1="1312" />
            <wire x2="1904" y1="768" y2="768" x1="1856" />
            <wire x2="1904" y1="768" y2="864" x1="1904" />
            <wire x2="1904" y1="864" y2="1168" x1="1904" />
            <wire x2="1136" y1="1088" y2="1088" x1="1120" />
            <wire x2="1120" y1="1088" y2="1168" x1="1120" />
            <wire x2="1904" y1="1168" y2="1168" x1="1120" />
            <wire x2="1392" y1="240" y2="528" x1="1392" />
            <wire x2="1856" y1="528" y2="528" x1="1392" />
            <wire x2="1856" y1="528" y2="720" x1="1856" />
            <wire x2="1856" y1="720" y2="864" x1="1856" />
            <wire x2="1888" y1="864" y2="864" x1="1856" />
            <wire x2="1904" y1="864" y2="864" x1="1888" />
            <wire x2="1888" y1="864" y2="1376" x1="1888" />
            <wire x2="1904" y1="1376" y2="1376" x1="1888" />
            <wire x2="2752" y1="720" y2="720" x1="1856" />
            <wire x2="1856" y1="864" y2="864" x1="1840" />
            <wire x2="2032" y1="1360" y2="1360" x1="1904" />
            <wire x2="1904" y1="1360" y2="1376" x1="1904" />
            <wire x2="2752" y1="560" y2="720" x1="2752" />
            <wire x2="2896" y1="560" y2="560" x1="2752" />
            <wire x2="2928" y1="560" y2="560" x1="2896" />
            <wire x2="2896" y1="544" y2="544" x1="2832" />
            <wire x2="2896" y1="544" y2="560" x1="2896" />
            <wire x2="2832" y1="544" y2="1248" x1="2832" />
            <wire x2="3184" y1="1248" y2="1248" x1="2832" />
        </branch>
        <iomarker fontsize="28" x="2848" y="384" name="RI" orien="R0" />
        <instance x="2928" y="688" name="XLXI_20" orien="R0" />
        <branch name="AI">
            <wire x2="3216" y1="560" y2="560" x1="3184" />
        </branch>
        <iomarker fontsize="28" x="3216" y="560" name="AI" orien="R0" />
        <branch name="XLXN_45">
            <wire x2="32" y1="832" y2="976" x1="32" />
            <wire x2="48" y1="976" y2="976" x1="32" />
            <wire x2="48" y1="832" y2="832" x1="32" />
            <wire x2="48" y1="784" y2="832" x1="48" />
            <wire x2="848" y1="784" y2="784" x1="48" />
            <wire x2="432" y1="528" y2="528" x1="400" />
            <wire x2="400" y1="528" y2="672" x1="400" />
            <wire x2="656" y1="672" y2="672" x1="400" />
            <wire x2="848" y1="672" y2="672" x1="656" />
            <wire x2="928" y1="672" y2="672" x1="848" />
            <wire x2="848" y1="672" y2="784" x1="848" />
            <wire x2="656" y1="672" y2="800" x1="656" />
            <wire x2="704" y1="800" y2="800" x1="656" />
            <wire x2="704" y1="800" y2="1584" x1="704" />
            <wire x2="704" y1="1584" y2="1584" x1="624" />
            <wire x2="624" y1="1584" y2="1600" x1="624" />
            <wire x2="2848" y1="1600" y2="1600" x1="624" />
            <wire x2="656" y1="608" y2="672" x1="656" />
            <wire x2="1184" y1="608" y2="608" x1="656" />
            <wire x2="864" y1="400" y2="400" x1="848" />
            <wire x2="848" y1="400" y2="672" x1="848" />
            <wire x2="1184" y1="352" y2="608" x1="1184" />
            <wire x2="1616" y1="352" y2="352" x1="1184" />
            <wire x2="2848" y1="960" y2="1008" x1="2848" />
            <wire x2="2848" y1="1008" y2="1584" x1="2848" />
            <wire x2="2848" y1="1584" y2="1600" x1="2848" />
            <wire x2="2880" y1="960" y2="960" x1="2848" />
        </branch>
        <instance x="2880" y="1088" name="XLXI_22" orien="R0" />
        <branch name="VI">
            <wire x2="3472" y1="1024" y2="1024" x1="3456" />
        </branch>
        <iomarker fontsize="28" x="3232" y="848" name="RD" orien="R0" />
        <instance x="3184" y="1376" name="XLXI_23" orien="R0" />
        <branch name="XLXN_52">
            <wire x2="1168" y1="880" y2="880" x1="1104" />
            <wire x2="1216" y1="880" y2="880" x1="1168" />
            <wire x2="1216" y1="880" y2="944" x1="1216" />
            <wire x2="1280" y1="880" y2="880" x1="1216" />
            <wire x2="1120" y1="944" y2="1024" x1="1120" />
            <wire x2="1136" y1="1024" y2="1024" x1="1120" />
            <wire x2="1216" y1="944" y2="944" x1="1120" />
            <wire x2="1216" y1="672" y2="672" x1="1152" />
            <wire x2="1216" y1="672" y2="880" x1="1216" />
            <wire x2="1392" y1="176" y2="176" x1="1168" />
            <wire x2="1168" y1="176" y2="880" x1="1168" />
            <wire x2="1280" y1="688" y2="880" x1="1280" />
            <wire x2="2400" y1="688" y2="688" x1="1280" />
            <wire x2="2400" y1="496" y2="688" x1="2400" />
            <wire x2="2784" y1="496" y2="496" x1="2400" />
            <wire x2="2928" y1="496" y2="496" x1="2784" />
            <wire x2="2784" y1="496" y2="1312" x1="2784" />
            <wire x2="3184" y1="1312" y2="1312" x1="2784" />
        </branch>
        <branch name="AD">
            <wire x2="3472" y1="1248" y2="1248" x1="3440" />
        </branch>
        <iomarker fontsize="28" x="3472" y="1248" name="AD" orien="R0" />
        <instance x="3120" y="1632" name="XLXI_24" orien="R0" />
        <iomarker fontsize="28" x="3472" y="1024" name="VI" orien="R0" />
        <instance x="3200" y="1120" name="XLXI_21" orien="R0" />
        <branch name="XLXN_55">
            <wire x2="3056" y1="1424" y2="1504" x1="3056" />
            <wire x2="3120" y1="1504" y2="1504" x1="3056" />
            <wire x2="3168" y1="1424" y2="1424" x1="3056" />
            <wire x2="3168" y1="992" y2="992" x1="3136" />
            <wire x2="3200" y1="992" y2="992" x1="3168" />
            <wire x2="3168" y1="992" y2="1424" x1="3168" />
        </branch>
        <branch name="VD">
            <wire x2="3408" y1="1536" y2="1536" x1="3376" />
        </branch>
        <iomarker fontsize="28" x="3408" y="1536" name="VD" orien="R0" />
        <branch name="CLR">
            <wire x2="416" y1="1376" y2="1376" x1="304" />
            <wire x2="720" y1="1376" y2="1376" x1="416" />
            <wire x2="720" y1="1104" y2="1152" x1="720" />
            <wire x2="1456" y1="1152" y2="1152" x1="720" />
            <wire x2="1856" y1="1152" y2="1152" x1="1456" />
            <wire x2="720" y1="1152" y2="1376" x1="720" />
            <wire x2="1456" y1="1088" y2="1152" x1="1456" />
            <wire x2="1856" y1="1072" y2="1152" x1="1856" />
            <wire x2="2272" y1="1072" y2="1072" x1="1856" />
        </branch>
        <iomarker fontsize="28" x="304" y="1376" name="CLR" orien="R180" />
        <branch name="CLK">
            <wire x2="384" y1="1744" y2="1744" x1="272" />
            <wire x2="384" y1="624" y2="1008" x1="384" />
            <wire x2="720" y1="1008" y2="1008" x1="384" />
            <wire x2="384" y1="1008" y2="1744" x1="384" />
            <wire x2="1408" y1="624" y2="624" x1="384" />
            <wire x2="1408" y1="624" y2="992" x1="1408" />
            <wire x2="1456" y1="992" y2="992" x1="1408" />
            <wire x2="1408" y1="992" y2="1104" x1="1408" />
            <wire x2="1920" y1="1104" y2="1104" x1="1408" />
            <wire x2="1920" y1="976" y2="1104" x1="1920" />
            <wire x2="2272" y1="976" y2="976" x1="1920" />
        </branch>
        <iomarker fontsize="28" x="272" y="1744" name="CLK" orien="R180" />
    </sheet>
</drawing>