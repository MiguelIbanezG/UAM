PRAC3B SEGMENT BYTE PUBLIC 'CODE'
PUBLIC _encuentraSubcadena
PUBLIC _calculaSegundoDC
ASSUME CS: PRAC3B
_encuentraSubcadena PROC FAR
    PUSH BP
    MOV BP, SP
    PUSH SI BX DI ES DS ; salvar registros a usar

    LDS SI, [BP+6]   ; Cogemos al puntero *string en DS:SI
    LES DI, [BP+10]  ; Cogemos al puntero *substr en ES:DI
    MOV AX,-1

WHILE1:
    CMP  BYTE PTR [SI], 0      ; str[i] == '\0' ?
    JZ FIN

    MOV BL, ES:[DI]
    CMP  BYTE PTR [SI], BL     ; str[i] == substr[j] ?
    JNZ NOIGUAL
    INC DI                     ; j++
    CMP  BYTE PTR ES:[DI], 0   ; Hemos acabado la substring ?
    JZ FIN                     ; Si es así AX -> posición
    CMP AX, -1                 ; tmp == -1 ?
    JNZ NORESET
    MOV AX, SI                 ; tmp = i
    SUB AX, [BP+6]
NORESET:
    JMP IGUAL
NOIGUAL:
    MOV AX,-1
    MOV DX, [BP+10]             ; Recarga de la pila a la "j"
IGUAL:

    INC SI
    JMP WHILE1 
FIN:
    CMP BYTE PTR [DI], 0
    JZ OK                       ; Caso extremo de str="a" y substr="aBZ"
    MOV AX,-1
OK:
    POP DS ES DI BX SI  ; Recuperar registros usados
    POP BP
    RET
_encuentraSubcadena ENDP
TABLA DW 1, 2, 4, 8, 5, 10, 9, 7, 3, 6
_calculaSegundoDC PROC FAR
    PUSH BP
    MOV BP,SP
    PUSH ES CX BX DX DI SI
    ; CARGA DE DATOS
    LES DI,[BP+6]       ; ES:DI puntero char* en FAR
    MOV SI,OFFSET TABLA ; CS:SI puntero a la tabla
    XOR AX,AX           ; Limpiampos al acumulador y contador
    XOR CX,CX
WHILE_MUL:
    MOV AL,ES:[DI]
    SUB AL,30h              ; Convertir de ASCII a dígito
    MUL WORD PTR CS:[SI]
    PUSH AX
    XOR AX,AX
    INC DI
    ADD SI,2                ; De 2 en 2 pq WORD
    INC CX
    CMP CX,10
    JNE WHILE_MUL

    MOV SI,SP       ; Para que apunte al principio de la pila
WHILE_SUM:
    ADD AX, SS:[SI]
    ADD SI,2
    DEC CX
    JNZ WHILE_SUM
    ADD SP,10*2         ; Rebalanceo del stack

    XOR DX,DX           ; Preparamos a DX
    MOV BX,11
    DIV BX              ; DX:AX entre BX -> Modulo en DX
    SUB BX,DX           ; 11 - (SUMA % 11)

    CMP BX,10
    JNE NODIEZ          ; if (BX == 10) -> si no continúa
    MOV BX,1
NODIEZ:
    XCHG AX,BX
    POP SI DI DX BX CX ES
    POP BP
    RET
_calculaSegundoDC ENDP
PRAC3B ENDS ; FIN DEL SEGMENTO DE CODIGO
END 
; FIN DE pract3a.asm
