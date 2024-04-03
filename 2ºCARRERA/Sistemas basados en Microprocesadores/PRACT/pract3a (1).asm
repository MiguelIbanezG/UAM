
_imparPositivo SEGMENT BYTE PUBLIC 'CODE'
PUBLIC _imparPositivo, _calculaDigito, _siguientePrimo
ASSUME CS: _imparPositivo

_imparPositivo PROC FAR
PUSH BP
MOV BP, SP
PUSH BX DX ; salvar registros a usar
MOV AX, [BP + 6] ; recuperar datos
MOV BX, [BP + 8] ; recuperar datos
MOV AX, Resultado ; en caso de retorno de datos por AX.
POP DX BX BP ;recuperar registros usados
RET
_imparPositivo ENDP
PRAC3A ENDS ; FIN DEL SEGMENTO DE CODIGO
END ; FIN DE pract3a.asm