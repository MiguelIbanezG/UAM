PRAC3B SEGMENT BYTE PUBLIC 'CODE'
PUBLIC _encuentraSubcadena, _calculaSegundoDC
ASSUME CS: PRAC3B

_encuentraSubcadena PROC FAR
    PUSH BP
    MOV BP, SP
    PUSH SI BX DI ES DS ; salvar registros a usar

    LDS SI, [BP+6]   
    LES DI, [BP+10] 
    MOV AX,-1


LOOPSUB:

CMP  BYTE PTR [SI], 0      
JZ ENDSUB

MOV BL, ES:[DI]
CMP  BYTE PTR [SI], BL
JNZ NOTEQSUB

INC DI
INC SI

CMP BYTE PTR ES:[DI], 0 
JZ ENDSUB

CMP AX, -1
JNZ LOOPSUB

DEC SI
SUB SI, OFFSET [BP +6]
MOV AX, SI
ADD SI, OFFSET [BP+6]
INC SI

JMP LOOPSUB


NOTEQSUB:
MOV AX, -1
INC SI
MOV DI, OFFSET[BP+10]

JMP LOOPSUB


ENDSUB:
POP DS ES DI BX SI ; Recuperar registros usados
POP BP
ret
_encuentraSubcadena ENDP


_calculaSegundoDC PROC FAR
    PUSH BP
    MOV BP, SP
    PUSH BX DI ES DS CX DX; salvar registros a usar
    
    LDS DI, [BP + 6]
    
    MOV DX, 0
    MOV BH, 1
    
    LOOPCALC: ; bucle de suma y multiplicación

    MOV BL, DS:[DI] ; caracter actual

    SUB BL, 30H ; paso de asci a numero
    
    MOV CL, BL
    
    MOV AX, CX ; se mueve para ser multiplicado por BH (el numero en cuestion)
    MUL BH
    
    ADD DL, AL ; se añade el resultado a DL (para poder seguir operando con AX)
    

    INC DI ; se incrementa en 1 la posicion del string
    

    CMP BH, 1 ; aqui se elige cual es el numero que se necesita (si es igual salta a la
    JE EXCEPT2 ; etiqueta que lo cambiará por el siguiente)
    CMP BH, 2
    JE EXCEPT4
    CMP BH, 4
    JE EXCEPT8
    CMP BH, 8
    JE EXCEPT5
    CMP BH, 5
    JE EXCEPT10
    CMP BH, 10
    JE EXCEPT9
    CMP BH, 9
    JE EXCEPT7
    CMP BH, 7
    JE EXCEPT3
    CMP BH, 3
    JE EXCEPT6
    
    CMP BH, 6
    JNE LOOPCALC
    JMP FINCALC
    

    EXCEPT2:
    MOV BH, 2
    JMP LOOPCALC 
    EXCEPT4:
    MOV BH, 4
    JMP LOOPCALC    
    EXCEPT8:
    MOV BH, 8
    JMP LOOPCALC 
    EXCEPT5:
    MOV BH, 5
    JMP LOOPCALC  
    EXCEPT10:
    MOV BH, 10
    JMP LOOPCALC 
    EXCEPT9:
    MOV BH, 9
    JMP LOOPCALC
    EXCEPT7:
    MOV BH, 7
    JMP LOOPCALC 
    EXCEPT3:
    MOV BH, 3
    JMP LOOPCALC  
    EXCEPT6:
    MOV BH, 6
    JMP LOOPCALC

    FINCALC:
    MOV AX, DX ; se mueve el resultado a AX
    
    MOV BX, 11
    XOR DX, DX
    
    DIV BX ; se divide entre 11
    
    MOV AX, DX ; se pasa el modulo a ax
    
    SUB BX, AX ; se resta 11

    CMP BX, 10
    JNE FINALFINAL ; si es 10 pasara a ser 1 
    MOV BX, 1

    FINALFINAL:
    MOV AX, BX
    POP DX CX DS ES DI BX ; Recuperar registros usados
    POP BP
    ret
_calculaSegundoDC ENDP

PRAC3B ENDS ; FIN DEL SEGMENTO DE CODIGO
END ; FIN DE pract3a.asm