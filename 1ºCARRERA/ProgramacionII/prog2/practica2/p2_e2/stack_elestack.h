#ifndef STACK_ELESTACK_H
#define STACK_ELESTACK_H

#include "types.h"
#include "elestack.h"

#define MAXSTACK 1024

typedef struct _Stack Stack;
/**------------------------------------------------------------------
Inicializa la pila reservando memoria. Salida: NULL si ha habido error o el puntero a la pila si ha ido bien
------------------------------------------------------------------*/
Stack * stack_ini();
/**------------------------------------------------------------------
Elimina la pila Entrada: puntero a la pila que se desea eliminar
------------------------------------------------------------------*/
void stack_destroy(Stack *pila);
/**------------------------------------------------------------------
Inserta un elemento en la pila. Entrada: elemento a insertar y pila donde insertarlo. Salida: OK si logra insertarlo o ERROR
si no.
------------------------------------------------------------------*/
Status stack_push(Stack *pila, const EleStack *ele);
/**------------------------------------------------------------------
Extrae un elemento de la pila. Entrada: la pila de donde extraerlo. Salida: NULL si no logra extraerlo, o el elemento
extraÃ­do si lo logra. NÃ³tese que la pila quedarÃ¡ modificada.
------------------------------------------------------------------*/
EleStack * stack_pop(Stack *pila);
/**------------------------------------------------------------------
Comprueba si la pila esta vacÃ­a. Entrada: puntero a la pila. Salida: TRUE si estÃ¡ vacÃ­a o FALSE si no lo esta
------------------------------------------------------------------*/
Bool stack_isEmpty(const Stack *pila);
/**------------------------------------------------------------------
Comprueba si la pila esta llena. Entrada: puntero a la pila. Salida: TRUE si estÃ¡ llena o FALSE si no lo esta
------------------------------------------------------------------*/
Bool stack_isFull(const Stack *pila);
/**------------------------------------------------------------------
Imprime toda la pila, comenzando por el Ãºltimo elemento insertado (aquel en la cima o tope) y terminando por el primero
que se insertÃ³. Imprime un elemento por lÃ­nea. Entrada: pila y fichero abierto donde imprimir. Salida: nÃºmero de
caracteres escritos en total.
------------------------------------------------------------------*/
int stack_print(FILE *f, const Stack *pila);

#endif
