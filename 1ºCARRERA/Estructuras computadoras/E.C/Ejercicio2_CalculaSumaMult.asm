.text
Main:	lw	$a0,X($0)	# cargamos en el primer parametro X en $a0
	lw	$a1,Y($0)		# cargamos en el segundo parámetro Y en $a1
	jal	func			# llamamos a la función
	sw	$v0, R($0)		# guardamos el resultado en memoria
	
func:	add	$v0, $a0, $a1	$ Z = X + Y
	sll	$v0, $v0, 1			$ Z = 2*Z
	jr	$ra					$ devolvemos el control a main y el resultado en $v0
	
	




.data
X: .word 10
Y: .word 4
R: .space 4
 