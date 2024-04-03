<?xml version="1.0" encoding="UTF-8"?>
<drawing version="7">
    <attr value="spartan3" name="DeviceFamilyName">
        <trait delete="all:0" />
        <trait editname="all:0" />
        <trait edittrait="all:0" />
    </attr>
    <netlist>
        <signal name="XLXN_1" />
        <signal name="XLXN_4" />
        <signal name="XLXN_5" />
        <signal name="XLXN_7" />
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
        <block symbolname="and2" name="XLXI_1">
            <blockpin name="I0" />
            <blockpin name="I1" />
            <blockpin signalname="XLXN_4" name="O" />
        </block>
        <block symbolname="and3" name="XLXI_2">
            <blockpin name="I0" />
            <blockpin name="I1" />
            <blockpin name="I2" />
            <blockpin signalname="XLXN_5" name="O" />
        </block>
        <block symbolname="and4" name="XLXI_3">
            <blockpin name="I0" />
            <blockpin name="I1" />
            <blockpin name="I2" />
            <blockpin name="I3" />
            <blockpin signalname="XLXN_1" name="O" />
        </block>
        <block symbolname="inv" name="XLXI_5">
            <blockpin name="I" />
            <blockpin name="O" />
        </block>
        <block symbolname="inv" name="XLXI_6">
            <blockpin name="I" />
            <blockpin name="O" />
        </block>
        <block symbolname="inv" name="XLXI_7">
            <blockpin name="I" />
            <blockpin name="O" />
        </block>
    </netlist>
    <sheet sheetnum="1" width="3520" height="2720">
        <instance x="1072" y="1216" name="XLXI_6" orien="R0" />
        <instance x="1200" y="800" name="XLXI_5" orien="R0" />
        <instance x="1072" y="1472" name="XLXI_7" orien="R0" />
        <branch name="XLXN_1">
            <wire x2="2288" y1="1520" y2="1520" x1="1872" />
            <wire x2="2304" y1="1296" y2="1296" x1="2288" />
            <wire x2="2288" y1="1296" y2="1520" x1="2288" />
        </branch>
        <branch name="XLXN_7">
            <wire x2="2784" y1="1232" y2="1232" x1="2560" />
        </branch>
        <instance x="1616" y="1680" name="XLXI_3" orien="R0" />
        <instance x="1648" y="1472" name="XLXI_1" orien="R0" />
        <branch name="XLXN_4">
            <wire x2="2096" y1="1376" y2="1376" x1="1904" />
            <wire x2="2096" y1="1168" y2="1376" x1="2096" />
            <wire x2="2304" y1="1168" y2="1168" x1="2096" />
        </branch>
        <instance x="1632" y="1152" name="XLXI_2" orien="R0" />
        <branch name="XLXN_5">
            <wire x2="2080" y1="1024" y2="1024" x1="1888" />
            <wire x2="2080" y1="1024" y2="1232" x1="2080" />
            <wire x2="2304" y1="1232" y2="1232" x1="2080" />
        </branch>
    </sheet>
</drawing>