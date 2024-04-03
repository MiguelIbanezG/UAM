;Sergio Hidalgo Gamborino, 05964532B
codigo SEGMENT
    ASSUME cs:codigo

    ORG 256

    inicio: JMP instalador ;Salto al instalador de la rutina

        rutina PROC FAR ;rutina del programa residente
        
        PUSH BP
        MOV BP, SP
        PUSH AX
        PUSH BX ;el valor original se guarda en BX
        PUSH ES
        PUSH DI
        PUSH SI ;DX no se salva porque en el se guardara el resultado

        MOV DI, 1 ;contador
        MOV SI, 2 ;divisor


        FOR_RUT: ;inicio del bucle

        MOV AX, DI ;AX == contador
        ADD AX, 1 ;Se le suma 1 (n+1)

        MUL DI ;se multiplica AX * contador, n*(n+1)

        MOV DX, 0 ;se asegura que DX este vacio
        DIV SI ;se divide entre 2,  n*(n+1)/2

        CMP AX, BX ;si son iguales el numero es triangular
        JE TRIANGULITO

        ADD DI, 1 ;si no lo son, se suma 1 al contador y se sigue probando

        CMP DI, 361 ;esto se repite hasta 361, porque con n = 362 T(n) = 65703, que es más de lo que el usuario puede meter
        JLE FOR_RUT
        
        MOV DX, 0 ;si llega hasta aqui, el numero no es triangular, por lo que devuelve 0


        FIN_T:
        POP SI 
        POP DI
        POP ES
        POP BX
        POP AX
        POP BP
        IRET

        TRIANGULITO:
        MOV DX, 1 ;si llega hasta aqui, el numero es triangular, por lo que devuelve 1
        JMP FIN_T

        rutina ENDP


        instalador PROC

        MOV AX, 0
        MOV ES, AX ;se limpian los registros
        MOV AX, OFFSET rutina ;se guarda el offset en ax

        MOV BX, CS ;y el segmento en BX

        CLI ;proteccion de señales

        MOV ES:[60H*4], AX
        MOV ES:[60H*4 +2], BX; se pasan segmento y offset

        STI ;fin de la proteccion

        MOV DX, OFFSET instalador ;se muve el offset a dx

        INT 27H ;y se deja el programa residente


        instalador ENDP


codigo ENDS     

END inicio