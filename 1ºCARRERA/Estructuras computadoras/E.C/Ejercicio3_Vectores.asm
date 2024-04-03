.text
Main:	addi $s0, $0, 0		# inicializar contador $s0 a 0
	lw $t1,A($s0)		# cargamos en $t1 el contenido de A(1)
	lw $t2,B($s0)		# cargamos en $2 el contenido de B(1)
	sll $t2,$t2, 2		# B(0) = B(0)*4
	add $t3,$t1, $t2	# C(0) = A(0)+B(0)*4
	sw $t3,C($s0)		# guardamos en memoria C(0)

	addi $s0,$s0,4		# incrementamos contador $s0 = 4
	lw $t1,A($s0)		# cargamos en $t1 el contenido de A(1)
	lw $t2,B($s0)		# cargamos en $2 el contenido de B(1)
	sll $t2,$t2, 2		# B(1) = B(1)*4
	add $t3,$t1, $t2	# C(1) = A(1)+B(1)*4
	sw $t3,C($s0)		# guardamos en memoria C(1)
fin: j fin			# fin del programa




.data
N: .word 2
A: .word 2 2 
B: .word -1 -5 
C: .space 8
