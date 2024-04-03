<?xml version="1.0" encoding="UTF-8"?>
<drawing version="7">
    <attr value="spartan3e" name="DeviceFamilyName">
        <trait delete="all:0" />
        <trait editname="all:0" />
        <trait edittrait="all:0" />
    </attr>
    <netlist>
        <signal name="VI" />
        <signal name="VD" />
        <signal name="AD" />
        <signal name="AI" />
        <signal name="XLXN_7" />
        <signal name="XLXN_8" />
        <signal name="RD" />
        <signal name="XLXN_34" />
        <signal name="XLXN_35" />
        <signal name="XLXN_36" />
        <signal name="XLXN_37" />
        <signal name="XLXN_38" />
        <signal name="CLK" />
        <signal name="CLR" />
        <signal name="XLXN_46" />
        <signal name="XLXN_55" />
        <signal name="XLXN_57" />
        <signal name="XLXN_59" />
        <signal name="XLXN_61" />
        <signal name="XLXN_63" />
        <signal name="S1" />
        <signal name="S0" />
        <signal name="XLXN_67" />
        <signal name="RI" />
        <port polarity="Output" name="VI" />
        <port polarity="Output" name="VD" />
        <port polarity="Output" name="AD" />
        <port polarity="Output" name="AI" />
        <port polarity="Output" name="RD" />
        <port polarity="Input" name="CLK" />
        <port polarity="Input" name="CLR" />
        <port polarity="Input" name="S1" />
        <port polarity="Input" name="S0" />
        <port polarity="Output" name="RI" />
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
        <blockdef name="inv">
            <timestamp>2000-1-1T10:10:10</timestamp>
            <line x2="64" y1="-32" y2="-32" x1="0" />
            <line x2="160" y1="-32" y2="-32" x1="224" />
            <line x2="128" y1="-64" y2="-32" x1="64" />
            <line x2="64" y1="-32" y2="0" x1="128" />
            <line x2="64" y1="0" y2="-64" x1="64" />
            <circle r="16" cx="144" cy="-32" />
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
        <block symbolname="fdc" name="XLXI_1">
            <blockpin signalname="CLK" name="C" />
            <blockpin signalname="CLR" name="CLR" />
            <blockpin signalname="XLXN_7" name="D" />
            <blockpin signalname="XLXN_57" name="Q" />
        </block>
        <block symbolname="fdc" name="XLXI_2">
            <blockpin signalname="CLK" name="C" />
            <blockpin signalname="CLR" name="CLR" />
            <blockpin signalname="XLXN_55" name="D" />
            <blockpin signalname="XLXN_63" name="Q" />
        </block>
        <block symbolname="fdc" name="XLXI_3">
            <blockpin signalname="CLK" name="C" />
            <blockpin signalname="CLR" name="CLR" />
            <blockpin signalname="XLXN_35" name="D" />
            <blockpin signalname="RD" name="Q" />
        </block>
        <block symbolname="and2" name="XLXI_4">
            <blockpin signalname="XLXN_34" name="I0" />
            <blockpin signalname="RI" name="I1" />
            <blockpin signalname="VD" name="O" />
        </block>
        <block symbolname="and2" name="XLXI_5">
            <blockpin signalname="XLXN_34" name="I0" />
            <blockpin signalname="RD" name="I1" />
            <blockpin signalname="VI" name="O" />
        </block>
        <block symbolname="and2" name="XLXI_7">
            <blockpin signalname="RD" name="I0" />
            <blockpin signalname="XLXN_8" name="I1" />
            <blockpin signalname="XLXN_37" name="O" />
        </block>
        <block symbolname="and2" name="XLXI_8">
            <blockpin signalname="XLXN_46" name="I0" />
            <blockpin signalname="RD" name="I1" />
            <blockpin signalname="XLXN_38" name="O" />
        </block>
        <block symbolname="and2" name="XLXI_10">
            <blockpin signalname="XLXN_8" name="I0" />
            <blockpin signalname="XLXN_63" name="I1" />
            <blockpin signalname="XLXN_8" name="O" />
        </block>
        <block symbolname="inv" name="XLXI_17">
            <blockpin signalname="XLXN_63" name="I" />
            <blockpin signalname="XLXN_46" name="O" />
        </block>
        <block symbolname="inv" name="XLXI_18">
            <blockpin signalname="XLXN_57" name="I" />
            <blockpin signalname="XLXN_8" name="O" />
        </block>
        <block symbolname="inv" name="XLXI_19">
            <blockpin signalname="RD" name="I" />
            <blockpin signalname="RI" name="O" />
        </block>
        <block symbolname="or3" name="XLXI_20">
            <blockpin signalname="XLXN_8" name="I0" />
            <blockpin signalname="XLXN_59" name="I1" />
            <blockpin signalname="XLXN_61" name="I2" />
            <blockpin signalname="XLXN_7" name="O" />
        </block>
        <block symbolname="and3" name="XLXI_21">
            <blockpin signalname="XLXN_63" name="I0" />
            <blockpin signalname="XLXN_57" name="I1" />
            <blockpin signalname="RI" name="I2" />
            <blockpin signalname="XLXN_36" name="O" />
        </block>
        <block symbolname="and3" name="XLXI_22">
            <blockpin signalname="S0" name="I0" />
            <blockpin signalname="XLXN_8" name="I1" />
            <blockpin signalname="RD" name="I2" />
            <blockpin signalname="XLXN_59" name="O" />
        </block>
        <block symbolname="and3" name="XLXI_24">
            <blockpin signalname="S1" name="I0" />
            <blockpin signalname="XLXN_8" name="I1" />
            <blockpin signalname="RI" name="I2" />
            <blockpin signalname="XLXN_61" name="O" />
        </block>
        <block symbolname="and3" name="XLXI_25">
            <blockpin signalname="XLXN_57" name="I0" />
            <blockpin signalname="RD" name="I1" />
            <blockpin signalname="XLXN_63" name="I2" />
            <blockpin signalname="AI" name="O" />
        </block>
        <block symbolname="and3" name="XLXI_26">
            <blockpin signalname="XLXN_57" name="I0" />
            <blockpin signalname="XLXN_63" name="I1" />
            <blockpin signalname="RI" name="I2" />
            <blockpin signalname="AD" name="O" />
        </block>
        <block symbolname="or2" name="XLXI_27">
            <blockpin signalname="XLXN_46" name="I0" />
            <blockpin signalname="XLXN_8" name="I1" />
            <blockpin signalname="XLXN_34" name="O" />
        </block>
        <block symbolname="or3" name="XLXI_28">
            <blockpin signalname="XLXN_38" name="I0" />
            <blockpin signalname="XLXN_37" name="I1" />
            <blockpin signalname="XLXN_36" name="I2" />
            <blockpin signalname="XLXN_35" name="O" />
        </block>
        <block symbolname="xor2" name="XLXI_29">
            <blockpin signalname="XLXN_63" name="I0" />
            <blockpin signalname="XLXN_57" name="I1" />
            <blockpin signalname="XLXN_55" name="O" />
        </block>
    </netlist>
    <sheet sheetnum="1" width="3520" height="2720">
        <instance x="1664" y="1168" name="XLXI_2" orien="R0" />
        <branch name="VI">
            <wire x2="3360" y1="1120" y2="1120" x1="3312" />
        </branch>
        <branch name="VD">
            <wire x2="3376" y1="1312" y2="1312" x1="3344" />
        </branch>
        <branch name="AD">
            <wire x2="3184" y1="592" y2="592" x1="3088" />
        </branch>
        <branch name="AI">
            <wire x2="3264" y1="1488" y2="1488" x1="3200" />
        </branch>
        <iomarker fontsize="28" x="3264" y="1488" name="AI" orien="R0" />
        <instance x="800" y="1168" name="XLXI_1" orien="R0" />
        <branch name="XLXN_7">
            <wire x2="800" y1="912" y2="912" x1="688" />
        </branch>
        <instance x="432" y="1040" name="XLXI_20" orien="R0" />
        <instance x="544" y="576" name="XLXI_22" orien="R0" />
        <instance x="2944" y="1616" name="XLXI_25" orien="R0" />
        <instance x="2432" y="1168" name="XLXI_3" orien="R0" />
        <branch name="RD">
            <wire x2="544" y1="384" y2="384" x1="496" />
            <wire x2="496" y1="384" y2="800" x1="496" />
            <wire x2="2928" y1="800" y2="800" x1="496" />
            <wire x2="2928" y1="800" y2="832" x1="2928" />
            <wire x2="2928" y1="832" y2="912" x1="2928" />
            <wire x2="2960" y1="912" y2="912" x1="2928" />
            <wire x2="2960" y1="912" y2="1088" x1="2960" />
            <wire x2="3056" y1="1088" y2="1088" x1="2960" />
            <wire x2="2992" y1="912" y2="912" x1="2960" />
            <wire x2="3024" y1="912" y2="912" x1="2992" />
            <wire x2="3216" y1="912" y2="912" x1="3024" />
            <wire x2="2992" y1="832" y2="832" x1="2928" />
            <wire x2="2992" y1="832" y2="912" x1="2992" />
            <wire x2="1200" y1="464" y2="464" x1="1120" />
            <wire x2="1120" y1="464" y2="688" x1="1120" />
            <wire x2="3024" y1="688" y2="688" x1="1120" />
            <wire x2="3024" y1="688" y2="912" x1="3024" />
            <wire x2="1472" y1="544" y2="544" x1="1408" />
            <wire x2="1408" y1="544" y2="832" x1="1408" />
            <wire x2="2928" y1="832" y2="832" x1="1408" />
            <wire x2="2880" y1="736" y2="736" x1="2624" />
            <wire x2="2880" y1="736" y2="912" x1="2880" />
            <wire x2="2912" y1="912" y2="912" x1="2880" />
            <wire x2="2912" y1="912" y2="1488" x1="2912" />
            <wire x2="2944" y1="1488" y2="1488" x1="2912" />
            <wire x2="2928" y1="912" y2="912" x1="2912" />
            <wire x2="2880" y1="912" y2="912" x1="2816" />
        </branch>
        <iomarker fontsize="28" x="3216" y="912" name="RD" orien="R0" />
        <instance x="2832" y="720" name="XLXI_26" orien="R0" />
        <iomarker fontsize="28" x="3184" y="592" name="AD" orien="R0" />
        <instance x="2624" y="704" name="XLXI_19" orien="R180" />
        <instance x="3056" y="1216" name="XLXI_5" orien="R0" />
        <iomarker fontsize="28" x="3360" y="1120" name="VI" orien="R0" />
        <instance x="2736" y="1392" name="XLXI_27" orien="R0" />
        <instance x="1472" y="1376" name="XLXI_18" orien="R0" />
        <instance x="1984" y="1488" name="XLXI_17" orien="R0" />
        <branch name="XLXN_34">
            <wire x2="3024" y1="1296" y2="1296" x1="2992" />
            <wire x2="3056" y1="1152" y2="1152" x1="3024" />
            <wire x2="3024" y1="1152" y2="1216" x1="3024" />
            <wire x2="3024" y1="1216" y2="1296" x1="3024" />
            <wire x2="3056" y1="1216" y2="1216" x1="3024" />
            <wire x2="3056" y1="1216" y2="1344" x1="3056" />
            <wire x2="3088" y1="1344" y2="1344" x1="3056" />
        </branch>
        <instance x="3088" y="1408" name="XLXI_4" orien="R0" />
        <iomarker fontsize="28" x="3376" y="1312" name="VD" orien="R0" />
        <instance x="1968" y="544" name="XLXI_28" orien="R0" />
        <branch name="XLXN_35">
            <wire x2="2320" y1="416" y2="416" x1="2224" />
            <wire x2="2320" y1="416" y2="912" x1="2320" />
            <wire x2="2432" y1="912" y2="912" x1="2320" />
        </branch>
        <instance x="1568" y="432" name="XLXI_21" orien="R0" />
        <branch name="XLXN_36">
            <wire x2="1968" y1="304" y2="304" x1="1824" />
            <wire x2="1968" y1="304" y2="352" x1="1968" />
        </branch>
        <instance x="1472" y="672" name="XLXI_8" orien="R0" />
        <instance x="1200" y="528" name="XLXI_7" orien="R0" />
        <branch name="XLXN_37">
            <wire x2="1712" y1="432" y2="432" x1="1456" />
            <wire x2="1712" y1="416" y2="432" x1="1712" />
            <wire x2="1968" y1="416" y2="416" x1="1712" />
        </branch>
        <branch name="XLXN_38">
            <wire x2="1968" y1="576" y2="576" x1="1728" />
            <wire x2="1968" y1="480" y2="576" x1="1968" />
        </branch>
        <iomarker fontsize="28" x="800" y="1888" name="CLK" orien="R180" />
        <iomarker fontsize="28" x="800" y="2000" name="CLR" orien="R180" />
        <branch name="XLXN_46">
            <wire x2="1472" y1="608" y2="608" x1="1392" />
            <wire x2="1392" y1="608" y2="1536" x1="1392" />
            <wire x2="2224" y1="1536" y2="1536" x1="1392" />
            <wire x2="2224" y1="1456" y2="1456" x1="2208" />
            <wire x2="2464" y1="1456" y2="1456" x1="2224" />
            <wire x2="2224" y1="1456" y2="1536" x1="2224" />
            <wire x2="2464" y1="1328" y2="1456" x1="2464" />
            <wire x2="2736" y1="1328" y2="1328" x1="2464" />
        </branch>
        <branch name="CLR">
            <wire x2="800" y1="1136" y2="1136" x1="624" />
            <wire x2="624" y1="1136" y2="1936" x1="624" />
            <wire x2="1008" y1="1936" y2="1936" x1="624" />
            <wire x2="1008" y1="1936" y2="2000" x1="1008" />
            <wire x2="1664" y1="2000" y2="2000" x1="1008" />
            <wire x2="2464" y1="2000" y2="2000" x1="1664" />
            <wire x2="3168" y1="2000" y2="2000" x1="2464" />
            <wire x2="1008" y1="2000" y2="2000" x1="800" />
            <wire x2="1664" y1="1136" y2="1136" x1="1424" />
            <wire x2="1424" y1="1136" y2="1440" x1="1424" />
            <wire x2="1664" y1="1440" y2="1440" x1="1424" />
            <wire x2="1664" y1="1440" y2="2000" x1="1664" />
            <wire x2="2432" y1="1136" y2="1568" x1="2432" />
            <wire x2="2464" y1="1568" y2="1568" x1="2432" />
            <wire x2="2464" y1="1568" y2="2000" x1="2464" />
        </branch>
        <branch name="CLK">
            <wire x2="800" y1="1040" y2="1040" x1="720" />
            <wire x2="720" y1="1040" y2="1344" x1="720" />
            <wire x2="1008" y1="1344" y2="1344" x1="720" />
            <wire x2="1008" y1="1344" y2="1888" x1="1008" />
            <wire x2="1488" y1="1888" y2="1888" x1="1008" />
            <wire x2="2304" y1="1888" y2="1888" x1="1488" />
            <wire x2="3184" y1="1888" y2="1888" x1="2304" />
            <wire x2="1008" y1="1888" y2="1888" x1="800" />
            <wire x2="1664" y1="1040" y2="1040" x1="1408" />
            <wire x2="1408" y1="1040" y2="1872" x1="1408" />
            <wire x2="1488" y1="1872" y2="1872" x1="1408" />
            <wire x2="1488" y1="1872" y2="1888" x1="1488" />
            <wire x2="2432" y1="1040" y2="1040" x1="2304" />
            <wire x2="2304" y1="1040" y2="1888" x1="2304" />
        </branch>
        <instance x="1072" y="1568" name="XLXI_29" orien="R0" />
        <branch name="XLXN_55">
            <wire x2="1376" y1="1472" y2="1472" x1="1328" />
            <wire x2="1376" y1="1232" y2="1472" x1="1376" />
            <wire x2="1648" y1="1232" y2="1232" x1="1376" />
            <wire x2="1664" y1="912" y2="912" x1="1648" />
            <wire x2="1648" y1="912" y2="1232" x1="1648" />
        </branch>
        <branch name="XLXN_57">
            <wire x2="1024" y1="1360" y2="1440" x1="1024" />
            <wire x2="1072" y1="1440" y2="1440" x1="1024" />
            <wire x2="1200" y1="1360" y2="1360" x1="1024" />
            <wire x2="1184" y1="304" y2="768" x1="1184" />
            <wire x2="1328" y1="768" y2="768" x1="1184" />
            <wire x2="1328" y1="768" y2="912" x1="1328" />
            <wire x2="1360" y1="912" y2="912" x1="1328" />
            <wire x2="1440" y1="912" y2="912" x1="1360" />
            <wire x2="1440" y1="912" y2="1552" x1="1440" />
            <wire x2="2944" y1="1552" y2="1552" x1="1440" />
            <wire x2="1568" y1="304" y2="304" x1="1184" />
            <wire x2="1200" y1="912" y2="912" x1="1184" />
            <wire x2="1280" y1="912" y2="912" x1="1200" />
            <wire x2="1280" y1="912" y2="1344" x1="1280" />
            <wire x2="1472" y1="1344" y2="1344" x1="1280" />
            <wire x2="1328" y1="912" y2="912" x1="1280" />
            <wire x2="1200" y1="912" y2="1360" x1="1200" />
            <wire x2="2832" y1="656" y2="656" x1="1360" />
            <wire x2="1360" y1="656" y2="912" x1="1360" />
        </branch>
        <branch name="XLXN_59">
            <wire x2="352" y1="784" y2="912" x1="352" />
            <wire x2="432" y1="912" y2="912" x1="352" />
            <wire x2="880" y1="784" y2="784" x1="352" />
            <wire x2="880" y1="448" y2="448" x1="800" />
            <wire x2="880" y1="448" y2="784" x1="880" />
        </branch>
        <instance x="464" y="368" name="XLXI_24" orien="R0" />
        <branch name="XLXN_61">
            <wire x2="432" y1="768" y2="848" x1="432" />
            <wire x2="864" y1="768" y2="768" x1="432" />
            <wire x2="864" y1="240" y2="240" x1="720" />
            <wire x2="864" y1="240" y2="768" x1="864" />
        </branch>
        <branch name="S1">
            <wire x2="464" y1="304" y2="304" x1="320" />
        </branch>
        <branch name="S0">
            <wire x2="544" y1="512" y2="512" x1="368" />
        </branch>
        <iomarker fontsize="28" x="368" y="512" name="S0" orien="R180" />
        <iomarker fontsize="28" x="320" y="304" name="S1" orien="R180" />
        <instance x="128" y="1072" name="XLXI_10" orien="R0" />
        <branch name="XLXN_63">
            <wire x2="2064" y1="816" y2="816" x1="96" />
            <wire x2="2064" y1="816" y2="912" x1="2064" />
            <wire x2="2096" y1="912" y2="912" x1="2064" />
            <wire x2="2128" y1="912" y2="912" x1="2096" />
            <wire x2="2128" y1="912" y2="1360" x1="2128" />
            <wire x2="2160" y1="912" y2="912" x1="2128" />
            <wire x2="2192" y1="912" y2="912" x1="2160" />
            <wire x2="2224" y1="912" y2="912" x1="2192" />
            <wire x2="2224" y1="912" y2="1424" x1="2224" />
            <wire x2="2944" y1="1424" y2="1424" x1="2224" />
            <wire x2="2192" y1="912" y2="1392" x1="2192" />
            <wire x2="96" y1="816" y2="944" x1="96" />
            <wire x2="128" y1="944" y2="944" x1="96" />
            <wire x2="992" y1="1392" y2="1504" x1="992" />
            <wire x2="1072" y1="1504" y2="1504" x1="992" />
            <wire x2="2192" y1="1392" y2="1392" x1="992" />
            <wire x2="1568" y1="368" y2="496" x1="1568" />
            <wire x2="2160" y1="496" y2="496" x1="1568" />
            <wire x2="2160" y1="496" y2="912" x1="2160" />
            <wire x2="1920" y1="1360" y2="1456" x1="1920" />
            <wire x2="1984" y1="1456" y2="1456" x1="1920" />
            <wire x2="2128" y1="1360" y2="1360" x1="1920" />
            <wire x2="2064" y1="912" y2="912" x1="2048" />
            <wire x2="2832" y1="592" y2="592" x1="2096" />
            <wire x2="2096" y1="592" y2="912" x1="2096" />
        </branch>
        <branch name="XLXN_8">
            <wire x2="128" y1="1008" y2="1008" x1="96" />
            <wire x2="96" y1="1008" y2="1200" x1="96" />
            <wire x2="1776" y1="1200" y2="1200" x1="96" />
            <wire x2="1776" y1="1200" y2="1344" x1="1776" />
            <wire x2="1808" y1="1344" y2="1344" x1="1776" />
            <wire x2="2208" y1="1344" y2="1344" x1="1808" />
            <wire x2="464" y1="240" y2="240" x1="384" />
            <wire x2="384" y1="240" y2="976" x1="384" />
            <wire x2="384" y1="976" y2="1168" x1="384" />
            <wire x2="1744" y1="1168" y2="1168" x1="384" />
            <wire x2="1744" y1="1168" y2="1344" x1="1744" />
            <wire x2="1776" y1="1344" y2="1344" x1="1744" />
            <wire x2="416" y1="976" y2="976" x1="384" />
            <wire x2="416" y1="976" y2="1296" x1="416" />
            <wire x2="1808" y1="1296" y2="1296" x1="416" />
            <wire x2="1808" y1="1296" y2="1344" x1="1808" />
            <wire x2="432" y1="976" y2="976" x1="416" />
            <wire x2="544" y1="448" y2="448" x1="416" />
            <wire x2="416" y1="448" y2="976" x1="416" />
            <wire x2="1200" y1="400" y2="400" x1="1136" />
            <wire x2="1136" y1="400" y2="544" x1="1136" />
            <wire x2="1248" y1="544" y2="544" x1="1136" />
            <wire x2="1248" y1="544" y2="1216" x1="1248" />
            <wire x2="1712" y1="1216" y2="1216" x1="1248" />
            <wire x2="1712" y1="1216" y2="1344" x1="1712" />
            <wire x2="1744" y1="1344" y2="1344" x1="1712" />
            <wire x2="1712" y1="1344" y2="1344" x1="1696" />
            <wire x2="2208" y1="1264" y2="1344" x1="2208" />
            <wire x2="2736" y1="1264" y2="1264" x1="2208" />
        </branch>
        <branch name="RI">
            <wire x2="464" y1="128" y2="176" x1="464" />
            <wire x2="2368" y1="128" y2="128" x1="464" />
            <wire x2="2368" y1="128" y2="736" x1="2368" />
            <wire x2="2400" y1="736" y2="736" x1="2368" />
            <wire x2="1568" y1="240" y2="240" x1="1168" />
            <wire x2="1168" y1="240" y2="752" x1="1168" />
            <wire x2="2256" y1="752" y2="752" x1="1168" />
            <wire x2="2208" y1="528" y2="736" x1="2208" />
            <wire x2="2256" y1="736" y2="736" x1="2208" />
            <wire x2="2256" y1="736" y2="752" x1="2256" />
            <wire x2="2288" y1="736" y2="736" x1="2256" />
            <wire x2="2368" y1="736" y2="736" x1="2288" />
            <wire x2="2544" y1="528" y2="528" x1="2208" />
            <wire x2="2832" y1="528" y2="528" x1="2544" />
            <wire x2="2544" y1="528" y2="672" x1="2544" />
            <wire x2="3040" y1="672" y2="672" x1="2544" />
            <wire x2="3040" y1="672" y2="1280" x1="3040" />
            <wire x2="3088" y1="1280" y2="1280" x1="3040" />
            <wire x2="2608" y1="352" y2="352" x1="2288" />
            <wire x2="2288" y1="352" y2="736" x1="2288" />
        </branch>
        <iomarker fontsize="28" x="2608" y="352" name="RI" orien="R0" />
    </sheet>
</drawing>