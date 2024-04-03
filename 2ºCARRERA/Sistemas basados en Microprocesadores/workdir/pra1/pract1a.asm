; Sergio Hidalgo 
; DEFINICION DEL SEGMENTO DE DATOS
    DATOS SEGMENT 






    DATOS ENDS

; DEFINICION DEL SEGMENTO DE PILA
    PILA SEGMENT STACK "STACK"
        DB 40H DUP (0) ;ejemplo de inicialización, 64 bytes inicializados a 0
    PILA ENDS

; DEFINICION DEL SEGMENTO EXTRA
    EXTRA SEGMENT
        RESULT DW 0,0 ;ejemplo de inicialización. 2 PALABRAS (4 BYTES)
    EXTRA ENDS

; DEFINICION DEL SEGMENTO DE CODIGO
    CODE SEGMENT
        ASSUME CS: CODE, DS: DATOS, ES: EXTRA, SS: PILA
; COMIENZO DEL PROCEDIMIENTO PRINCIPAL
    INICIO PROC
; INICIALIZA LOS REGISTROS DE SEGMENTO CON SU VALOR
    MOV AX, DATOS
    MOV DS, AX
    MOV AX, PILA
    MOV SS, AX
    MOV AX, EXTRA
    MOV ES, AX
    MOV SP, 64 ; CARGA EL PUNTERO DE PILA CON EL VALOR MAS ALTO
; FIN DE LAS INICIALIZACIONES
; COMIENZO DEL PROGRAMA 

    ;Cargar 8BH en AX
    MOV AX, 08BH

    ;Cargar CFH en BL
    MOV BL, 0CFH    

    ;Cargar 3412H en DX
    MOV DX, 3412H

    ;Cargar 11001011b en DS
    MOV AX, 0CBH
    MOV DS, AX

    ;Cargar el contenido de DX en CX
    MOV CX, DX 

    ;Cargar en BH el contenido de la posición de memoria 51223H 
    ;y en BL en contenido de la posición 51222H
    MOV AX, 5000H
    MOV DS, AX
    MOV BH, DS:[1223H]
    MOV BL, DS:[1222H]

    ;Cargar en la posición de memoria 60006H el contenido de DH
    MOV AX, 6000H
    MOV DS, AX
    MOV AX, DS:[6]

    ;Cargar en AX el contenido de la dirección de memoria apuntada por SI 
    MOV AX, DS:[SI]

    ;Cargar en BX el contenido de la dirección de memoria que está 10 bytes 
    ;por encima de la dirección apuntada por BP
    MOV BX, DS:[BP]+10

; FIN DEL PROGRAMA
MOV AX, 4C00H
INT 21H
INICIO ENDP
; FIN DEL SEGMENTO DE CODIGO
CODE ENDS
; FIN DEL PROGRAMA INDICANDO DONDE COMIENZA LA EJECUCION
END INICIO