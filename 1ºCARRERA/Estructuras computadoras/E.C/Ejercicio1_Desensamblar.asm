.text

main: 	lw $1, dato1      # Lee dato1
		sll $2, $1, 8     # Desplaza dato1 2 posiciones hex (8 bits) y lo guarda en $2
		lw $3, dato2      # Lee dato2
		or $4, $2, $3     # añade el número dato2 al final de 0x00ceba00 sustiyendo los últimos dígitos
		addi $5, $0, 5    # pone a 5 este registro
		sw $4, res2       # guarda 0x00cebaXX en res2
final: 	j final           # bucle infinito


.data
res2: .word 0

dato1: .word 0x0000ceba
dato2: .word 0x00000005
