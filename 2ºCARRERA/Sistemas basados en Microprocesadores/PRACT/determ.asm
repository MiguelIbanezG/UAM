; Ulysses de Aguilar Gudmundsson SBM - G2261
; ------------------------------------------
; Calcula el determinate de una matriz 3x3
; Componentes principales del programa
;  - Menu
;       - Valores por defecto -- Bueno para testear el módulo de cálculo -> Tiene que dar lo mismo siempre
;       - Valores introducidos por usuario
;  - Cálculo
;  - Mostrar resultados

datos SEGMENT
INMATRIX DB 3*(3*5+2), ?          ; Primero el size, luego el capturado
         DB 3 dup(3*5 dup(?),?,?) ; Reservamos la matriz de entrada para -128 a 127
                                  ; Las dos ?? son para ,_ (_ es la tecla espacio)
MENOS    DW  2DH
OPSET   DB  30H
FIN_STR  DW  '$'
CLR_PANT 	DB 	1BH,"[2","J$"
TITULO      DB  1BH,"[1;27fCALCULADORA DE DETERMINANTES 3x3$"
SELOP       DB  1BH,"[2;3fSelecciona que quieres hacer:$"
OPCION1     DB  1BH,"[3;6fa) Calcular con valores por defecto.$"
OPCION2     DB  1BH,"[4;6fb) Calcular con valores introducidos.$"
ENTRADA     DB  1BH,"[5;6fENTRADA: $"
RESULTADOOALGO     DB  1BH,"[6;6fRESULTADO (supongo): $"
RESULT      DB  8 dup (?)         ; Espacio para sacar los números por pantalla
                                  ; (con espacio suficiente para el operando B + $)
MATRIX DB 32,2,-10
       DB 23,-1,6
       DB 10,31,3 ; Matriz de 3 columnas y 3 filas de elementos de 1 byte
;MATRIX DB 1,2,3
;       DB 4,5,6
;       DB 7,8,9 ; Matriz de 3 columnas y 3 filas de elementos de 1 byte
;MATRIX  DB 127,-127,127
;        DB -127,127,127
;        DB 127,127,127
ROW DB  3
COL DB  3
PAR DB  2
datos ENDS

pila SEGMENT STACK "STACK"
DB 40H dup (?) ; Reservamos un stack con 64 bytes
pila ENDS

extra SEGMENT
DETRES DW   ?   ; El resultado del determinante
CONTADOR DB 0   ; Nos lleva la cuenta de los ",_"
extra ENDS

codigo SEGMENT
ASSUME ds:datos, ss:pila, es:extra, cs:codigo
;----------------------------------------------
; Función que convierte a ASCII un número de 16 bit en C2
;----------------------------------------------
; Entrada: AX
;----------------------------------------------
; Salida : DX:AX
NUMASCII PROC NEAR
    ; Inicializaciones
    MOV BX,0AH
    MOV CX,0
    MOV DX,0
    MOV SI,0
    PUSH FIN_STR ; Para que cuando terminemos tengamos al caracter de final

    ; Inicio de rutina
    CMP AX,0
    JNS P       ; Check si es positivo o no
    NEG AX
    INC SI
P:

OTRO:
    DIV BX
    PUSH DX
    MOV DX,0
    INC CX
    CMP AX,0
    JNE OTRO

    MOV BX,0     ; Ahora BX es nuestro puntero a tabla

    CMP SI,1     ; Si es negativo le añadimos el caracter ascii de '-'
    JNE NOSIGNO
    XCHG BP,CX
    MOV CX,MENOS
    MOV RESULT[BX],CL
    XCHG CX,BP
    INC BX
NOSIGNO:
SIG:
    POP AX
    ADD AL,OPSET
    MOV RESULT[BX],AL
    INC BX
    DEC CX
    CMP CX,0
    JNE SIG

    ; escribimos el '$'
    POP AX
    MOV RESULT[BX],AL

    MOV AX, OFFSET RESULT
    MOV DX, SEG RESULT
    RET
NUMASCII ENDP
;----------------------------------------------
; Función que convierte una secuencia de 5 caracteres en
; un número de 8 bit en C2 indicando su fin con ' ', CARRIAGE RETURN o ','
;----------------------------------------------
; Entrada : SI (índice de cadena)
;----------------------------------------------
; Salida  : AX (Si indica 0FFFFH es que hubo algún error)
;----------------------------------------------
; Errores posibles: La cadena tiene más de 5 caracteres
;                   El número no puede ser representado en 8 bit C2
ASCIINUM PROC NEAR
    MOV AX,0
    MOV CX,0
    MOV DX,0
    MOV DI,0

    ; Check del signo
    MOV AL,INMATRIX[SI]
    CMP AL,'-'
    JNE SIPOS
    MOV DI,1
    INC SI
SIPOS:
    MOV AL,INMATRIX[SI]
     
    CMP AL,' '          ; Condición de salida normal por espacio
    JE  FINBUCLE
    CMP AL,','          ; Condición de salida normal por coma
    JE  FINBUCLE
    CMP AL,0DH          ; Condición de salida normal por CARRIAGE RETURN
    JE  FINBUCLE

    CMP CL, 3
    JE  ERROR_CL        ; Condicion de salida con error

    SUB AL,'0'          ; Lo pasamos de ASCII a HEX
    PUSH AX             ; Lo pasamos al stack

    INC CL              ; Incrementamos al contador del stack
    INC SI              ; Incrementamos al indice de la string
    JMP SIPOS
ERROR_CL:
    MOV AX, 0FFFFH
    RET
FINBUCLE:
    MOV BX,1
    MOV AX,1

    CMP CH,0
    JE UNO
    MOV BH,CH
ELEVADO:
    MOV BL, 0AH
    MUL BL
    DEC BH
    CMP BH,0
    JNE ELEVADO
    MOV BL,AL
UNO:
    POP AX
    MUL BL
    ADD DL,AL   ; DL va a acumular el resultado
    INC CH
    DEC CL
    CMP CL,0
    JNZ FINBUCLE
    
    MOV AL, DL
    MOV AH,0
    ; Invertir si hubo signo
    CMP DI,0
    JE NONEG
    NEG AL
NONEG:
    RET
ASCIINUM ENDP
;----------------------------------------------
; Función que convierte el input del usuario en la matriz de entrada
;----------------------------------------------
ASCIIMAT PROC NEAR
    MOV BX,0
    MOV CX,0
    MOV SI,2
OTROMAS:
    PUSH BX
    PUSH CX
    CALL ASCIINUM       ; Convierte el núm
    POP CX
    POP BX
    MOV MATRIX[BX], AL

    MOV AL,INMATRIX[SI] ; Saltamos dos si nos encontramos una coma
    CMP AL, 0DH         ; CARRIAGE RETURN
    JE FIN
    CMP AL, ','
    JNE NOSUM
    INC CX
    INC SI
NOSUM:
    INC BX
    INC SI
    CMP CX,3

    JNZ OTROMAS
FIN:
    RET
ASCIIMAT ENDP
; Rutina principal del programa
INICIO PROC FAR
    ; INICIALIZA LOS REGISTROS DE SEGMENTO CON SU VALOR
    MOV AX, DATOS
    MOV DS, AX
    MOV AX, PILA
    MOV SS, AX
    MOV AX, EXTRA
    MOV ES, AX
    MOV SP, 64
    
    ; COMIENZO DEL PROGRAMA
    MOV AH,9
    MOV DX, OFFSET CLR_PANT
    INT 21H

    MOV DX, OFFSET TITULO
    INT 21H

    MOV DX, OFFSET SELOP
    INT 21H

    MOV DX, OFFSET OPCION1
    INT 21H

    MOV DX, OFFSET OPCION2
    INT 21H

    MOV DX, OFFSET ENTRADA
    INT 21H

    ; CAPTURAMOS LA CADENA ESCRITA POR EL USUARIO
    MOV AH, 0AH
    MOV DX, OFFSET INMATRIX
    INT 21H

    ; testeo del ASCIIMATRIX
    CALL ASCIIMAT

    ; Sección de cálculo del resultado de la matriz
    MOV CX,0
GENIUS:
    PUSH CX
    MOV BX,CX
    CALL DIAGSUP

    POP CX       ; En este instante apunta al contador
    PUSH CX
    PUSH AX
    PUSH DX         ; Guardamos el primer resultado DX:AX

    MOV BX,CX
    CALL DIAGINF

    POP CX
    POP BX
    SUB BX,AX
    SBB CX,DX
    
    XCHG DX,CX
    POP CX          ; Rescatamos al contador del bucle
    PUSH BX         ; Pareja n-ésima de diagonales
    PUSH DX

    INC CX
    CMP CX,3
    JNE GENIUS

    ; Unimos los resultados
    POP DX
    POP AX
    POP CX
    POP BX

    ADD AX,BX   ; Parte baja
    ADC DX,CX   ; Parte alta con carry
    POP CX
    POP BX

    ADD AX,BX   
    ADC DX,CX   ; Resultado en DX:AX
    MOV BX,AX

    CALL NUMASCII   ; lo convertimos a ASCII pa verlo por pantalla
    ; Lo sacamos por pantalla
    MOV AH,9
    MOV DX, OFFSET RESULTADOOALGO
    INT 21H

    MOV AH,9
    MOV DX, OFFSET RESULT
    INT 21H

    ; FIN DEL PROGRAMA
    MOV AX, 4C00H
    INT 21H
INICIO ENDP

;-----------------------------------------
; Función que calcula la diagonal derecha superior con anillos
;-----------------------------------------
; Entrada: BX (Debe ser 0, 1 o 2)
; Hay que especificar la diagonal correcta correspondiente 
; con su esquina superior izquierda.
; Ejemplos de esquinas (asume ROW = 0) 0,1,2
;-----------------------------------------
; Retorno: DX:AX
;-----------------------------------------
; Utiliza los registros AX,BX,CX,SI, sálvalos si hay algo que importe dentro
DIAGSUP PROC NEAR
    ; Inicialización del programa
    MOV SI, 0
    MOV AX, 1 ; Acumulador principal del resultado    
    MOV DX, 0 ; Parte superior
WHILE:  ; Bucle principal
    MOV CH, MATRIX[BX][SI]
    CALL MULT32
    
    PUSH AX
    PUSH DX

    INC BX
    MOV AX, BX ; Ajustar BX con DIV RESTO EN AL

    DIV COL    ; Dividimos para ver si BX se desborda o no de la matriz
    MOV BL,AH  ; Movemos el resto a BL (operación del módulo)

    POP DX  ; Restauramos al acumulador con la parte baja
    POP AX

    ADD SI,3   ; Incrementamos SI en 3 para ir a la siguiente fila
    CMP SI,9   ; Si llegamos a 9 en SI hemos terminado
    JNE WHILE

    ; Volvemos de la función
    RET
DIAGSUP ENDP

;-----------------------------------------
; Función que calcula la diagonal derecha inferior con anillos
;-----------------------------------------
; Entrada: BX (Debe ser 0, 1 o 2)
; Hay que especificar la diagonal correcta correspondiente 
; con su esquina superior izquierda.
; Ejemplos de esquinas (asume ROW = 6) 0,1,2
;-----------------------------------------
; Retorno: AX
;-----------------------------------------
; Utiliza los registros AX,BX,CX,SI, sálvalos si hay algo que importe dentro
DIAGINF PROC NEAR
    ; Inicialización del programa
    MOV SI, 6
    MOV AX, 1 ; Acumulador principal del resultado
    MOV DX, 0 ; Parte superior
WHILE2:  ; Bucle principal
    MOV CH, MATRIX[BX][SI]
    CALL MULT32

    PUSH AX
    PUSH DX

    INC BX
    MOV AX, BX ; Ajustar BX con DIV RESTO EN AL

    DIV COL    ; Dividimos para ver si BX se desborda o no de la matriz
    MOV BL,AH  ; Movemos el resto a BL (operación del módulo)

    POP DX  ; Restauramos al acumulador con la parte baja
    POP AX

    SUB SI,3   ; Decrementamos SI en 3 para ir a la siguiente fila
    CMP SI,0   ; Si llegamos a 9 en SI hemos terminado
    JGE WHILE2

    ; Volvemos de la función
    RET
DIAGINF ENDP
;-----------------------------------------
; Función que calcula la multiplicación con signo de un numero 8 bit con uno de 32
; almacenándo el resultado en 32 bit
;-----------------------------------------
; Entrada: DX:AX, CH
;          Posiciones del stack
;           AX*CH      <- SP (BP)
;           CARRY      <- +2
;           DX         <- +4
;-----------------------------------------
; Retorno: DX:AX
;-----------------------------------------
; Utiliza los registros AX,BX,CX,DI,BP sálvalos si hay algo que importe dentro
AX_CH EQU 0
CARRY EQU 1*2
DXP   EQU 2*2
MULT32 PROC NEAR
    SUB SP, 3*2
    MOV BP, SP
    MOV CL,8
    SAR CX, CL
    MOV DI,0     ; Nos lleva unas cuentas muy interesantes
    
    ; Inicio del procedimiento
    CMP DX,0
    JNS NOINV1  ; Si es negativo entrará al procedimiento de invertir
    NOT AX
    ADD AX,1
    NOT DX
    ADC DX,0
    INC DI
NOINV1:
    CMP CX,0
    JNS NOINV2  ; Si es negativo entrará al procedimiento de invertir
    NEG CX
    INC DI
NOINV2:
    MOV DXP[BP], DX   ; Salvamos a DX
    MUL CX
    MOV AX_CH[BP], AX ; Tenemos inferior y carry
    MOV CARRY[BP], DX

    MOV AX,DXP[BP]    ; Sacamos al DX anterior
    MUL CX
    ADD AX,CARRY[BP]  ; Le sumamos el carry
    MOV DXP[BP], AX   ; Lo salvamos (parte superior completa)
    
    CMP DI,0
    JE  ZERO    
    MOV AX,DI
    DIV PAR
    CMP AH,0
ZERO:
    MOV AX,AX_CH[BP]
    MOV DX,DXP[BP]

    JE POSIT
    NOT AX
    ADD AX,1
    NOT DX
    ADC DX,0
POSIT:
    ADD SP,3*2  ; Restauramos al STACK
    RET
MULT32 ENDP
codigo ENDS
END INICIO
