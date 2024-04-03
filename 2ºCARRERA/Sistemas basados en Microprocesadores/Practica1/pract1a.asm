;**************************************************************************
; SBM 2023. ESTRUCTURA BÁSICA DE UN PROGRAMA EN ENSAMBLADOR
;**************************************************************************
; DEFINICION DEL SEGMENTO DE DATOS
DATOS SEGMENT
;-- rellenar con los datos solicitados
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

;Cargar 4BB4H en AX 
MOV AX, 4BB4H 			;Cargamos directamente el número en hexadcimal en AX

;Cargar CFH en BH
MOV BH, 0CFH 			;Cargamos directamente el número en hexadcimal en BX

;Cargar 3412H en DX
MOV DX, 3412H 			;Cargamos directamente el número en hexadcimal en DX

;Cargar -23 en BL
MOV BL, 23 				;Cargamos el número en decimal postivo en BL
NEG BL 					;Cambiamos el número guardado en BL a negativo

;Para comprobar que las anteriores 4 instrucciones estan bien, ejecutamos el codigo 
;instruccion a instruccion con F7 y comprobamos que AX, BX y DX tengan los valores adecuados.

;Cargar 11001011b en ES
MOV AX, 0CBH 			;Pasamos el numero a hexadecimal y lo cargamos en AX
MOV ES, AX 				;Cargamos el valor de AX en ES

;Cargar FABAH en DS
MOV AX, 64186 			;Pasamos el numero a decimal y lo cargamos en AX
MOV DS, AX 				;Cargamos el valor de AX en DS

;Cargar el contenido de DX en [BX]+15
MOV [BX+15], DX			;Cargamos en DS:[BX]+15 el valor de DX

;Cargar en DH el contenido de la posición de memoria 51222H y en DL en contenido de la posición 51223H
MOV AX, 5000H 			;Cargamos 5000H en AX
MOV DS, AX				;Cargamos ese AX en DS
MOV DH, DS:[1222H]		;Cargamos en DH el valor de la poscion de DS: 50000H + 1222H = 51222H
MOV DL, DS:[1223H]		;Cargamos en DH el valor de la poscion de DS: 50000H + 1222H = 51223H

;Cargar en la posición de memoria 70007H el contenido de DH
MOV AX, 7000H			;Cargamos 7000H en AX
MOV DS, AX				;Cargamos ese AX en DS
MOV DS:[7H], DH			;Cargamos en la poscion de DS: 70000H + 7H = 70007H el valor de DH

;Cargar en AX el contenido de la dirección de memoria apuntada por SI
MOV AX, [SI]			;Cargamos en AX el valor de DS:[SI]

;Cargar en BX el contenido de la dirección de memoria que está 10 bytes por encima de la dirección apuntada por BP 
MOV BX, [BP]-10			;Cargamos en AX el valor de SS:[BP-10]

;Para comprobar si las intrucciones de posiciones de memoria estan bien, he añadido un valores a las posiciónes
;de memoria (ya que estan vacias) y he comprobado que se cargaba el dato correcatamente.

; FIN DEL PROGRAMA
MOV AX, 4C00H
INT 21H
INICIO ENDP
; FIN DEL SEGMENTO DE CODIGO
CODE ENDS
; FIN DEL PROGRAMA INDICANDO DONDE COMIENZA LA EJECUCION
END INICIO