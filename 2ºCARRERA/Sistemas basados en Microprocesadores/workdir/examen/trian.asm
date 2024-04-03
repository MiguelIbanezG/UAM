;Sergio Hidalgo Gamborino, 05964532B
trian SEGMENT BYTE PUBLIC 'CODE'

PUBLIC _esTriangular

ASSUME CS: trian

_esTriangular PROC FAR
PUSH BP
MOV BP, SP
PUSH BX
PUSH DX ;se introduce el contenido de los registros en la pila
mov ax, 0


MOV BX, [BP+6] ;se obtiene el int que se ha introducido como parametro


INT 60h ;se llama a la interrupcion instalada


MOV AX, DX ;que devolvera un valor en DX, que se pasara a AX y sera lo que devuelva la funcion

POP DX
POP BX ;se recupera el contenido de los registros
POP BP
RET

_esTriangular ENDP
trian ENDS 
END 


