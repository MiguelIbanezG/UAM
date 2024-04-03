;**************************************************************************
; SBM 2023. ESTRUCTURA BÁSICA DE UN PROGRAMA EN ENSAMBLADOR
;**************************************************************************
; DEFINICION DEL SEGMENTO DE DATOS
DATOS SEGMENT
        VIVA_SBM2023 DB 0 									;DB es el tamaño para 1 byrte
	    BEBA DW 0CAFEH	  									;DW es el tamanño para 2 bytes
	    TABLA300 DB 300 DUP(0)								;Ponemos 300 para la reserva de bytes y dup(0) para inicializarla a 0
	    ERRORFATAL2 DB "ESTE PROGRAMA SE CUELGA SIEMPRE."	;Guardamos la cadena de texto
DATOS ENDS
;**************************************************************************
; DEFINICION DEL SEGMENTO DE PILA
PILA SEGMENT STACK "STACK"
DB 40H DUP (0) ;ejemplo de inicialización, 64 bytes inicializados a 0
PILA ENDS
;**************************************************************************
; DEFINICION DEL SEGMENTO EXTRA
EXTRA SEGMENT
RESULT DW 0,0 ;ejemplo de inicialización. 2 PALABRAS (4 BYTES)
EXTRA ENDS
;**************************************************************************
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

;Copiar el segundo carácter de la cadena ERRORFATAL2 en la posición 63H de TABLA300 
MOV AL, ERRORFATAL2[1]			;Se carga el segundo caracter de ERRORFATAL en AL (el primer carcater es el 0)
MOV TABLA300[63H], AL			;Se carga AL de ERRORFATAL en la posiciones 63

;Copiar el contenido de la variable BEBA a partir de la posición 4 de TABLA300 
MOV SI, 04H						;Se carga el valor 4 en SI
MOV DI, 0H						;Se carga el el valor 0 en DI
MOV AL, BYTE PTR BEBA[DI]       ;Se carga el contenido de la variable BEBA en AL
MOV TABLA300[SI], AL			;Se carga AL en la posción SI=4 de la tabla

;Copiar el byte más significativo de BEBA a la variable VIVA_SBM2023
MOV AL, BYTE PTR BEBA+1			;Cargamos el byte más significativo en AL
MOV VIVA_SBM2023, AL			;Cargamos AL en VIVA_SBM2023

;Para confirmar que esta bien comprobamos que la compilacion no da errores, y vamos
;ejecutando las instrucciones con F7 viendo si van cambiando los valores de las tablas correctamente.
	
; FIN DEL PROGRAMA
MOV AX, 4C00H
INT 21H
INICIO ENDP
; FIN DEL SEGMENTO DE CODIGO
CODE ENDS
; FIN DEL PROGRAMA INDICANDO DONDE COMIENZA LA EJECUCION
END INICIO