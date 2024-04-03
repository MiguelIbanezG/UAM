#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#include "stack_fp.h"

#define MAXSTACK 100

#define EMPTY_STACK -1

extern int errno;

struct _Stack {

    int top;
    void * item[MAXSTACK];

    P_stack_ele_destroy pf_destroy;
    P_stack_ele_copy pf_copy;
    P_stack_ele_print pf_print;
    
};

Stack *stack_ini (P_stack_ele_destroy fd, P_stack_ele_copy fc, P_stack_ele_print fp) {
      
    Stack *s;
    int i;

    s = (Stack*) malloc(sizeof(Stack));
    if (!s) {
            fprintf(stderr, "%s", strerror(errno));
            return NULL;
    }

    // Inicializo tope y asigno los punteros a función

    s->top = 0;
    s->pf_copy = fc;
    s->pf_destroy = fd;
    s->pf_print = fp;

    // Asigno los punteros de los elementos

    for (i=0; i< MAXSTACK; i++)
            s->item[i] = NULL;
    return s;
}

void stack_destroy(Stack * ppila) {
    
    int i;
    
    if (!ppila) return;
    
    for (i = 0; i < ppila->top; i++) {
        ppila-> pf_destroy (ppila->item[i]);
    }
    
    free (ppila);
    return;
}

Bool stack_isFull(const Stack *entrada) {
	
	if (!entrada) return TRUE; //si no hay dirección reservada, no se puede meter nada
	if (entrada->top == MAXSTACK) return TRUE;
	
	return FALSE;
}

Bool stack_isEmpty(const Stack * entrada) {

	if (!entrada) return TRUE; //consideramos el vacío en dirección como que no se puede extraer nada, luego pasamos false
	if (entrada->top == 0) return TRUE;
	
	return FALSE;
}

Status stack_push(Stack * ppila, const void * pelestack) {
	
	void *copia = NULL;
	
	if (!ppila  || !pelestack) return ERROR;
	if (stack_isFull (ppila) == TRUE) return ERROR;
	
	copia = ppila->pf_copy (pelestack);
	if (!copia) return ERROR;
	
	ppila->item[ppila->top] = copia;
	ppila->top++;
	
	return OK;
}

void * stack_pop(Stack * ppila) {
	
	void *aux = NULL;
	
	if (!ppila) return NULL;
	if (stack_isEmpty(ppila) == TRUE) return NULL;
	
	ppila->top--;
	aux = ppila->item[ppila->top];
	ppila->item[ppila->top] = NULL;
	
	return aux;
}

int stack_print(FILE * pf, const Stack* ppila) {
	
	int i, contador = 0;
	
	if (!pf || !ppila) return -1; //-1 será nuestra codificación de error en esta función
	if (stack_isEmpty(ppila) == TRUE) return 0; //si no hay elementos no hay nada que imprimir
	
	for (i = ppila->top-1; i >= 0; i--) {
		
		contador += ppila-> pf_print (pf, ppila->item[i]);
		if (i != 0) contador += fprintf (pf, "\n");
	}
	
	return contador;
}
