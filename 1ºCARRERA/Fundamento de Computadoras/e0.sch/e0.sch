<?xml version="1.0" encoding="UTF-8"?>
<drawing version="7">
    <attr value="spartan3" name="DeviceFamilyName">
        <trait delete="all:0" />
        <trait editname="all:0" />
        <trait edittrait="all:0" />
    </attr>
    <netlist>
        <blockdef name="acc16">
            <timestamp>2000-1-1T10:10:10</timestamp>
            <line x2="448" y1="-448" y2="-448" x1="512" />
            <rect width="384" x="64" y="-576" height="512" />
            <rect width="64" x="0" y="-460" height="24" />
            <line x2="64" y1="-448" y2="-448" x1="0" />
            <line x2="448" y1="-512" y2="-512" x1="512" />
            <line x2="64" y1="-256" y2="-256" x1="0" />
            <line x2="64" y1="-128" y2="-144" x1="80" />
            <line x2="80" y1="-112" y2="-128" x1="64" />
            <line x2="64" y1="-192" y2="-192" x1="0" />
            <line x2="64" y1="-128" y2="-128" x1="0" />
            <line x2="64" y1="-32" y2="-32" x1="256" />
            <line x2="256" y1="-64" y2="-32" x1="256" />
            <line x2="64" y1="-32" y2="-32" x1="0" />
            <rect width="64" x="448" y="-524" height="24" />
            <line x2="64" y1="-512" y2="-512" x1="0" />
            <line x2="64" y1="-384" y2="-384" x1="0" />
            <rect width="64" x="0" y="-396" height="24" />
            <line x2="64" y1="-320" y2="-320" x1="0" />
            <line x2="448" y1="-384" y2="-384" x1="512" />
        </blockdef>
        <block symbolname="acc16" name="XLXI_1">
            <blockpin name="ADD" />
            <blockpin name="B(15:0)" />
            <blockpin name="C" />
            <blockpin name="CE" />
            <blockpin name="CI" />
            <blockpin name="D(15:0)" />
            <blockpin name="L" />
            <blockpin name="R" />
            <blockpin name="CO" />
            <blockpin name="OFL" />
            <blockpin name="Q(15:0)" />
        </block>
    </netlist>
    <sheet sheetnum="1" width="3520" height="2720">
        <instance x="432" y="960" name="XLXI_1" orien="R0" />
    </sheet>
</drawing>