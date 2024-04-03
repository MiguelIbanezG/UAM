<?xml version="1.0" encoding="UTF-8"?>
<drawing version="7">
    <attr value="spartan3" name="DeviceFamilyName">
        <trait delete="all:0" />
        <trait editname="all:0" />
        <trait edittrait="all:0" />
    </attr>
    <netlist>
        <signal name="I0" />
        <signal name="I1" />
        <signal name="I2" />
        <signal name="XLXN_5" />
        <signal name="O7" />
        <signal name="O0" />
        <signal name="O1" />
        <signal name="O2" />
        <signal name="O3" />
        <signal name="O4" />
        <signal name="O5" />
        <signal name="O6" />
        <port polarity="Input" name="I0" />
        <port polarity="Input" name="I1" />
        <port polarity="Input" name="I2" />
        <port polarity="Output" name="O7" />
        <port polarity="Output" name="O0" />
        <port polarity="Output" name="O1" />
        <port polarity="Output" name="O2" />
        <port polarity="Output" name="O3" />
        <port polarity="Output" name="O4" />
        <port polarity="Output" name="O5" />
        <port polarity="Output" name="O6" />
        <blockdef name="d3_8e">
            <timestamp>2000-1-1T10:10:10</timestamp>
            <line x2="64" y1="-576" y2="-576" x1="0" />
            <line x2="64" y1="-512" y2="-512" x1="0" />
            <line x2="64" y1="-448" y2="-448" x1="0" />
            <line x2="320" y1="-576" y2="-576" x1="384" />
            <line x2="320" y1="-512" y2="-512" x1="384" />
            <line x2="320" y1="-448" y2="-448" x1="384" />
            <line x2="320" y1="-384" y2="-384" x1="384" />
            <line x2="320" y1="-320" y2="-320" x1="384" />
            <line x2="320" y1="-256" y2="-256" x1="384" />
            <line x2="320" y1="-192" y2="-192" x1="384" />
            <line x2="320" y1="-128" y2="-128" x1="384" />
            <rect width="256" x="64" y="-640" height="576" />
            <line x2="64" y1="-128" y2="-128" x1="0" />
        </blockdef>
        <blockdef name="vcc">
            <timestamp>2000-1-1T10:10:10</timestamp>
            <line x2="64" y1="-32" y2="-64" x1="64" />
            <line x2="64" y1="0" y2="-32" x1="64" />
            <line x2="32" y1="-64" y2="-64" x1="96" />
        </blockdef>
        <block symbolname="d3_8e" name="XLXI_1">
            <blockpin signalname="I0" name="A0" />
            <blockpin signalname="I1" name="A1" />
            <blockpin signalname="I2" name="A2" />
            <blockpin signalname="XLXN_5" name="E" />
            <blockpin signalname="O0" name="D0" />
            <blockpin signalname="O1" name="D1" />
            <blockpin signalname="O2" name="D2" />
            <blockpin signalname="O3" name="D3" />
            <blockpin signalname="O4" name="D4" />
            <blockpin signalname="O5" name="D5" />
            <blockpin signalname="O6" name="D6" />
            <blockpin signalname="O7" name="D7" />
        </block>
        <block symbolname="vcc" name="XLXI_2">
            <blockpin signalname="XLXN_5" name="P" />
        </block>
    </netlist>
    <sheet sheetnum="1" width="3520" height="2720">
        <instance x="1584" y="1392" name="XLXI_1" orien="R0" />
        <branch name="I0">
            <attrtext style="alignment:SOFT-BCENTER;fontsize:28;fontname:Arial" attrname="Name" x="1536" y="816" type="branch" />
            <wire x2="1536" y1="816" y2="816" x1="1520" />
            <wire x2="1584" y1="816" y2="816" x1="1536" />
        </branch>
        <branch name="I1">
            <attrtext style="alignment:SOFT-BCENTER;fontsize:28;fontname:Arial" attrname="Name" x="1552" y="880" type="branch" />
            <wire x2="1552" y1="880" y2="880" x1="1520" />
            <wire x2="1584" y1="880" y2="880" x1="1552" />
        </branch>
        <branch name="I2">
            <attrtext style="alignment:SOFT-BCENTER;fontsize:28;fontname:Arial" attrname="Name" x="1536" y="944" type="branch" />
            <wire x2="1536" y1="944" y2="944" x1="1520" />
            <wire x2="1584" y1="944" y2="944" x1="1536" />
        </branch>
        <branch name="XLXN_5">
            <wire x2="1584" y1="1264" y2="1264" x1="1520" />
        </branch>
        <branch name="O7">
            <attrtext style="alignment:SOFT-BCENTER;fontsize:28;fontname:Arial" attrname="Name" x="1984" y="1264" type="branch" />
            <wire x2="1984" y1="1264" y2="1264" x1="1968" />
            <wire x2="2032" y1="1264" y2="1264" x1="1984" />
        </branch>
        <branch name="O0">
            <attrtext style="alignment:SOFT-BCENTER;fontsize:28;fontname:Arial" attrname="Name" x="1984" y="816" type="branch" />
            <wire x2="1984" y1="816" y2="816" x1="1968" />
            <wire x2="2048" y1="816" y2="816" x1="1984" />
        </branch>
        <branch name="O1">
            <attrtext style="alignment:SOFT-BCENTER;fontsize:28;fontname:Arial" attrname="Name" x="1984" y="880" type="branch" />
            <wire x2="1984" y1="880" y2="880" x1="1968" />
            <wire x2="2048" y1="880" y2="880" x1="1984" />
        </branch>
        <branch name="O2">
            <attrtext style="alignment:SOFT-BCENTER;fontsize:28;fontname:Arial" attrname="Name" x="1984" y="944" type="branch" />
            <wire x2="1984" y1="944" y2="944" x1="1968" />
            <wire x2="2048" y1="944" y2="944" x1="1984" />
        </branch>
        <branch name="O3">
            <attrtext style="alignment:SOFT-BCENTER;fontsize:28;fontname:Arial" attrname="Name" x="1984" y="1008" type="branch" />
            <wire x2="1984" y1="1008" y2="1008" x1="1968" />
            <wire x2="2048" y1="1008" y2="1008" x1="1984" />
        </branch>
        <branch name="O4">
            <attrtext style="alignment:SOFT-BCENTER;fontsize:28;fontname:Arial" attrname="Name" x="1984" y="1072" type="branch" />
            <wire x2="1984" y1="1072" y2="1072" x1="1968" />
            <wire x2="2048" y1="1072" y2="1072" x1="1984" />
        </branch>
        <branch name="O5">
            <attrtext style="alignment:SOFT-BCENTER;fontsize:28;fontname:Arial" attrname="Name" x="1984" y="1136" type="branch" />
            <wire x2="1984" y1="1136" y2="1136" x1="1968" />
            <wire x2="2048" y1="1136" y2="1136" x1="1984" />
        </branch>
        <branch name="O6">
            <attrtext style="alignment:SOFT-BCENTER;fontsize:28;fontname:Arial" attrname="Name" x="2000" y="1200" type="branch" />
            <wire x2="2000" y1="1200" y2="1200" x1="1968" />
            <wire x2="2048" y1="1200" y2="1200" x1="2000" />
        </branch>
        <instance x="1456" y="1264" name="XLXI_2" orien="R0" />
        <iomarker fontsize="28" x="2048" y="816" name="O0" orien="R0" />
        <iomarker fontsize="28" x="2048" y="880" name="O1" orien="R0" />
        <iomarker fontsize="28" x="2048" y="944" name="O2" orien="R0" />
        <iomarker fontsize="28" x="2048" y="1008" name="O3" orien="R0" />
        <iomarker fontsize="28" x="2048" y="1072" name="O4" orien="R0" />
        <iomarker fontsize="28" x="2048" y="1136" name="O5" orien="R0" />
        <iomarker fontsize="28" x="2048" y="1200" name="O6" orien="R0" />
        <iomarker fontsize="28" x="2032" y="1264" name="O7" orien="R0" />
        <iomarker fontsize="28" x="1520" y="816" name="I0" orien="R180" />
        <iomarker fontsize="28" x="1520" y="880" name="I1" orien="R180" />
        <iomarker fontsize="28" x="1520" y="944" name="I2" orien="R180" />
    </sheet>
</drawing>