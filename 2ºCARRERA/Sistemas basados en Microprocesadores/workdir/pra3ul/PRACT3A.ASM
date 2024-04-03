PRAC3A SEGMENT BYTE PUBLIC 'CODE'
PUBLIC _imparPositivo
PUBLIC _calculaDigito
PUBLIC _siguientePrimo
MASCARA DW 1b           ; Dato para la fase final
ASSUME CS: PRAC3A
_imparPositivo PROC FAR
    PUSH BP
    MOV BP, SP
    PUSH BX DX CX; salvar registros a usar
    MOV AX, [BP + 6] ; recuperar datos
    MOV CX,0
    ; testeamos si el número es negativo
    CMP AX,0
    JNS  CONTINUE   ; Si es positivo continuamos
    MOV AX,0
    JMP FIN
CONTINUE:
    AND AX,MASCARA
FIN:
    POP CX DX BX BP ;recuperar registros usados
    RET
_imparPositivo ENDP
_calculaDigito PROC FAR
    PUSH BP
    MOV BP,SP
    PUSH CX BX DX SI
    MOV AX, [BP+6]    ; Sacar al numero
    MOV CX, [BP+8]    ; Sacar la posición
    MOV BX, 0Ah       ; Inicializamos a BX = 10
    MOV DX,0          ; Inicializamos a DX

OTRO:
    DIV BX
    MOV SI,DX
    MOV DX,0    ; Reiniciamos a dx pq sino problemas
    DEC CX
    CMP CX,0    ; CX - 0 -> FLAGS
    JGE OTRO    ; CX >= 0

    MOV AX, SI ; El resultado que queremos
    ; Final de la función
    POP SI DX BX CX
    POP BP
    RET
_calculaDigito ENDP
_siguientePrimo PROC FAR
    PUSH BP
    MOV BP,SP
    PUSH CX BX DX SI
    MOV CX, [BP+6]    ; Sacamos al número en cuestión
    INC CX            ; Para buscar al num siguiente

WHILE1:
    MOV SI,1          ; Flag que indica que en principio el número a examinar es primo
    MOV BX,2
WHILE2:
    MOV DX,0          ; Inicializamos a DX
    MOV AX,CX         ; Cargamos al número actual
    DIV BX            ; Dividimos entre el número

    CMP DX,0          ; DX - 0 (Básicamente si AX multp de DX)
    JNZ SIGUE
    MOV SI,0
    JMP OUTWHILE
SIGUE:
    INC BX
    CMP CX,BX         ; CX - BX -> FLAGS
    JE PRIMO          ; Si BX == CX -> Primo !

    CMP BX,256        ; sqrt(2^16) = 256 Num máximo a comprobar
    JZ OUTWHILE            ; Si BX == 256 -> el número de CX es primo
    JMP WHILE2

OUTWHILE:
    CMP SI,0
    JNZ PRIMO         ; Si la flag persistió -> Encontrado !

    CMP CX,0FFFFH     ; Si  CX == FFFFh no lo tenemos houston
    JE NOPRIMO       ; F-ésima chavales

    INC CX
    JMP WHILE1
NOPRIMO:
    MOV CX, 0
PRIMO:
    MOV AX, CX

    POP SI DX BX CX
    POP BP
    RET
_siguientePrimo ENDP
PRAC3A ENDS ; FIN DEL SEGMENTO DE CODIGO
END 
; FIN DE pract3a.asm
