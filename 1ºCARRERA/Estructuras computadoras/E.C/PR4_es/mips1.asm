.text
Main:    addi $s0, $0, 0        # inicializar contador a 0
    lw $s1, N($0)            # cargar el numero de iteraciones
    sll $s1, $s1, 2            # cada iteracion consta de 4 posiciones de memoria
bucle:    beq $s0,$s1,fin     # verificacion de la condición del bucle
    lw $t1,A($s0)            # cargamos en $t1 A(i)
    lw $t2,B($s0)            # cargamos en $t2 B(i)
    sll $t2,$t2, 2            # B(i) = B(i)4
    add $t3,$t1, $t2        # C(i) = A(i)+B(i)4
    sw $t3,C($s0)            # guardamos C(i) en memoria
    addi $s0,$s0,4            # incrementamos el contador
    j bucle                    # volvemos al inicio del bucle
fin: j fin                    # final de programa




.data
N: .word 6
A: .word 2 4 6 8 10 12
B: .word -1 -5 4 10 1 -5
C: .space 24
