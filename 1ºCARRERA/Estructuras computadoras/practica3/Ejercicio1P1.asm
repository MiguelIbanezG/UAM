


.text 
main:	lw $t0, x
	lw $t1, y
	sw $t0, 0($sp)	
	addi $sp, $sp, -4
	sw $t1, 0($sp)
	addi $sp, $sp, -4	
	jal suma
	lw $t5, 0($sp)
	addi $sp, $sp, 4
	sw $t5, R
	addi $sp, $sp, -4
	
bucle: j bucle
	 
	
	
suma:	addi $sp, $sp, 4
	lw $t2, 0($sp)
	addi $sp, $sp, 4	
	lw $t3, 0($sp)
	add $t4, $t2, $t3
	sw $t4, 0($sp)  
	jr $ra
	
		
		
			
				
					
.data 
x: 10
y: 4
R: 0						