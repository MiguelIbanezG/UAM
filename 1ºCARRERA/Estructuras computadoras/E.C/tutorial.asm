# ==========================================================================
# 	This program computes variable F as the factorial of variable N
# ==========================================================================
.text 0x0000
	lw $s1, N($0)		# s1 := N
	beq $s1, $0, Fone	# N == 0 ? -> F := 1
	addi $s2, $s1, -1   	# s2 == next_factor := N - 1
	beq $s2, $0, Fone	# N-1 == 0 ? -> F := 1
	
	add $s3, $s1, $0	# s3 == cumulative_product := N
	
L1:	add $a0, $s3, $0	# a0 := cumulative_product
	add $a1, $s2, $0	# a1 := next_factor
	jal Fact		# v0 := cumulative_product * next_factor 
	add $s3, $v0, $0	# cumulative_product := cumulative_product * next_factor 
	addi $s2, $s2, -1   	# next_factor := next_factor - 1
	beq $s2, $0, end    	# next_factor == 0 ? -> F := cumulative_product
	j L1
	
Fone:	addi $s3, $0, 1		# cumulative_product := 1	
end: 	sw $s3, F($0)		# F := cumulative_product

stop:  j stop

# ==========================================================================
# 				Product( a, b )
# ==========================================================================
# Purpose:  Compute a*b as b cumulative additions of a
# Input:
# 	a0 == a
#	a1 == b
# Output:
#	v0 == a * b
# ==========================================================================
Fact:	and $t0, $t0, $0	# t0 == cumulative_addition := 0
	add $t1, $a1, $zero	# t1 == counter := b
	
L2:	add $t0, $t0, $a0	# cumulative_addition := cumulative_addition + a
	addi $t1, $t1, -1 	# counter := counter - 1
	beq $t1, $0, L3		# counter == 0 ? -> return cumulative_addition
	j L2			# loop

L3: 	add $v0, $t0, $0	# v0 := cumulative_addition
	jr $ra			# return v0

# ==========================================================================
# 	Global variables
# ==========================================================================
.data 0x2000
	N: .word 0x00000003
	F: .word 0x00000000
