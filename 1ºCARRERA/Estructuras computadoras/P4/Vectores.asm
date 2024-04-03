######################################################################
## File: Vectores.asm
## Description: Program to...
## Date: 

## Authors: 
## Subject: E.C. 1º grado
## Laboratory group:
## Theory group
## Task: 3
## Exercise: 2
######################################################################

.text

main:		
	#Reading N variable
	lw $s0, N($0)
	
	
	#Adaptation of N
	add $s0, $s0, $s0
	add $s0, $s0, $s0
	
	#Initialization the for loop
	addi $s1, $s1, 0
	
	
	
	#Checking the loop
bucle:	slt $s2, $s1, $s0
	beq $s0, $s1, fin
	
	#Reading of A(i)
	lw $s3, A($s1)
	
	
	
	#Reading of B(i)
	lw $s6, B($s1)
	
	#Multiplication by 4 of B(i)
	add $s6, $s6, $s6 
	add $s6, $s6, $s6
	
	#Addition 
	add $s7, $s6, $s3
	
	#Writing in C(i)
	sw $s7, C($s1)
	
	#Loop opeartion
	addi $s1, $s1, 4
	
	#Jump to the comparison
	j bucle
	
	#Infinitive loop
fin:  	j fin	

.data # Start of user memory data
A: 2,2,4,6,5,6,7,8,9,10
B: -1,-5,4,10,1,-2,5,10,-10,0
C: .space 40 #.space reserve space in bytes.
N: .word 10

