PRAC3A SEGMENT BYTE PUBLIC 'CODE'

PUBLIC _imparPositivo, _calculaDigito, _siguientePrimo
ASSUME CS: PRAC3A


_imparPositivo PROC FAR
PUSH BP
MOV BP, SP
PUSH DX ; salvar registros a usar
MOV AX, [BP + 6] ; recuperar datos

;impares acaban en 1
;pares acaban en 0

cmp AX, 0
jl NEGA ;si es negativo


MOV DX, 1 
AND AX, DX  ;si acaba en 0 devolverá 0 en AX, si acaba en 1, 1
JMP FIN

NEGA: 
MOV AX, 0 ;mover a AX el 0 al ser negativo

FIN:
POP DX BP ;recuperar registros usados
ret
_imparPositivo ENDP


_calculaDigito PROC FAR
PUSH BP
MOV BP, SP
PUSH DX CX DI SI

MOV AX, [BP + 6]; variables
MOV SI, [BP + 8] 


MOV DI, 0; contador

MOV CX, 10 ; divisor

CMP AX, 0
JL NEGA2 ; si es negativo

LOOP_L: ; bucle de division para seleccionar el númerod

XOR DX, DX ; reseteo de DX 

DIV CX; división de AX entre CX, en AX-->AX/CX, en DX-->AX%CX

CMP SI, DI; contador de posición y contador actual
JE END_L

CONT:
INC DI
JMP LOOP_L


END_L:

MOV AX, DX; se pone el módulo de la división en AX

POP SI DI CX DX BP;recuperar registros usados

RET 

NEGA2:

NEG AX ; se invierte la flag de AX
JMP LOOP_L

_calculaDigito ENDP


_siguientePrimo PROC FAR

PUSH BP
MOV BP, SP
MOV BX, [BP + 6]
PUSH DX BX CX



LOOP_P:

INC BX
MOV CX, 2; siempre que empice el bucle, CX será 2 (el primer primo)

COMP:
MOV AX, BX; se mueve el número tras el incremento a AX


CMP AX, CX; se compara para ver si es el mismo(al ser CX siempre primo se habrá terminado)
JE END_P


XOR DX, DX; limpieza de DX para la división
DIV CX

INC CX; incremento de 1 a CX (para que sea 3)

JMP TEST_N

COMP2:


MOV AX, BX ; toda esta parte es igual que la anterior

CMP AX, CX 
JE END_P

XOR DX, DX
DIV CX

ADD CX, 2 ; salvo el incremento que es de 2 en vez de 1 

JMP TEST_N



TEST_N:

CMP DX, 0; si el resto de la división es 0 no es primo
JE LOOP_P

CMP CX, 9; si cx es menor o igual que 9 continua
JLE COMP2

END_P:

MOV AX, BX

POP CX BX DX BP
RET
_siguientePrimo ENDP




PRAC3A ENDS ; FIN DEL SEGMENTO DE CODIGO
END ; FIN DE pract3a.asm