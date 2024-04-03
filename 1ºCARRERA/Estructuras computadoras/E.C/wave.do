onerror {resume}
quietly WaveActivateNextPane {} 0
add wave -noupdate /microsimple_tb/reset
add wave -noupdate /microsimple_tb/clk
add wave -noupdate -radix hexadecimal -radixshowbase 0 /microsimple_tb/uut/pc_out
add wave -noupdate -radix hexadecimal -radixshowbase 0 /microsimple_tb/uut/instruc
add wave -noupdate -radix hexadecimal -radixshowbase 0 /microsimple_tb/uut/REG/dato(0)
add wave -noupdate -radix hexadecimal -radixshowbase 0 /microsimple_tb/uut/REG/dato(1)
add wave -noupdate -radix hexadecimal -radixshowbase 0 /microsimple_tb/uut/REG/dato(2)
add wave -noupdate -radix hexadecimal -radixshowbase 0 /microsimple_tb/uut/REG/dato(3)
add wave -noupdate -radix hexadecimal -radixshowbase 0 /microsimple_tb/uut/REG/dato(4)
TreeUpdate [SetDefaultTree]
WaveRestoreCursors {{Cursor 1} {0 ns} 0}
quietly wave cursor active 0
configure wave -namecolwidth 215
configure wave -valuecolwidth 100
configure wave -justifyvalue left
configure wave -signalnamewidth 0
configure wave -snapdistance 10
configure wave -datasetprefix 0
configure wave -rowmargin 4
configure wave -childrowmargin 2
configure wave -gridoffset 0
configure wave -gridperiod 1
configure wave -griddelta 40
configure wave -timeline 0
configure wave -timelineunits ns
update
WaveRestoreZoom {0 ns} {155 ns}
