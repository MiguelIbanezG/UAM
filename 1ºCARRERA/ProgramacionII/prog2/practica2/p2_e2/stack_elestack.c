#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include "stack_elestack.h"


struct _Stack {
    int top;
    EleStack * item[MAXSTACK];
};

Stack* stack_ini() {
    int i;
	Stack *pila = NULL;
    
	pila = (Stack*) malloc(sizeof (Stack));
    if (pila == NULL) {
        fprintf(stderr, "%s\n", strerror(errno));
        return NULL;
    }

    for (i = 0; i < MAXSTACK; i++) {
        pila->item[i] = NULL;
    }
    pila->top = -1;

    return pila;
}

void stack_destroy(Stack *pila) {
    int i;
	
    if (pila == NULL) {
        fprintf(stderr, "%s\n", strerror(errno));
        return;
    }

    for (i = 0; i < pila->top + 1; i++) {
        EleStack_destroy(pila->item[i]);
        pila->item[i] = NULL;
    }

    free(pila);

    return;
}

Status stack_push(Stack *pila, const EleStack *ele) {
    EleStack *elc = NULL;

    if (pila == NULL || ele == NULL || stack_isFull(pila) == TRUE){
        fprintf(stderr, "%s\n", strerror(errno));
        return ERROR;
    }

    elc = EleStack_copy(ele);
	if(elc == NULL) return ERROR;
	
    pila->top++;
    pila->item[pila->top] = elc;
    
    return OK;
}

EleStack * stack_pop(Stack *pila) {
	EleStack *ele = NULL;
	
    if (pila == NULL || stack_isEmpty(pila) == TRUE){
        fprintf(stderr, "%s\n", strerror(errno));
        return NULL;
    }

    ele = pila->item[pila->top];
    pila->item[pila->top] = NULL;
    pila->top--;

    return ele;
}

Bool stack_isEmpty(const Stack *pila) {
    if (pila == NULL){
        fprintf(stderr, "%s\n", strerror(errno));
        return TRUE;
    }
    if (pila->top == -1) return TRUE;
    return FALSE;
}

Bool stack_isFull(const Stack *pila) {
    if (pila == NULL){
        fprintf(stderr, "%s\n", strerror(errno));
        return TRUE;
    }
    if (pila->top == MAXSTACK-1) return TRUE;
    return FALSE;
}

int stack_print(FILE *f, const Stack *pila) {
    int i, c = 0;
    if (pila == NULL){
        fprintf(stderr, "%s\n", strerror(errno));
        return -1;
    }
    for (i = pila->top; i > -1; i--) {
        c += EleStack_print(f, pila->item[i]);
        fprintf(f, "\n");

    }
    return c;
}
