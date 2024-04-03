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

Stack *stack_ini(P_stack_ele_destroy fd, P_stack_ele_copy fc, P_stack_ele_print fp) {
    Stack *s;
    int i;

    s = (Stack*) malloc(sizeof (Stack));
    if (!s) {
        fprintf(stderr, "%s", strerror(errno));
        return NULL;
    }
    // Inicializo tope y asigno los punteros a función
    s->top = -1;
    s->pf_copy = fc;
    s->pf_destroy = fd;
    s->pf_print = fp;

    // Asigno los punteros de los elementos
    for (i = 0; i < MAXSTACK; i++)
        s->item[i] = NULL;

    return s;
}

void stack_destroy(Stack* stc) {
    if (!stc) return;

    while (stc->top != EMPTY_STACK) {
        stc->pf_destroy(stc->item[stc->top]); // Llamada a la función cuyo puntero se almacenó como campo
        // de la pila, es decir, utilizando el puntero a la función
        stc->top--;
    }
    free(stc);
}

Status stack_push(Stack *pila, const void *ele) {
    void *elc = NULL;

    if (pila == NULL || ele == NULL || stack_isFull(pila) == TRUE) return ERROR;


    elc = pila->pf_copy(ele);

    if (elc == NULL) {
        fprintf(stderr, "%s\n", strerror(errno));
        return ERROR;
    }

    pila->top++;
    pila->item[pila->top] = elc;

    return OK;
}
void * stack_pop(Stack *pila){
    void *ele = NULL;

    if (pila == NULL || stack_isEmpty(pila) == TRUE) return NULL;


    ele = pila->item[pila->top];

    pila->item[pila->top] = NULL;
    pila->top--;

    return ele;
}

Bool stack_isEmpty(const Stack *pila){
    if (pila == NULL) return TRUE;

    if (pila->top == EMPTY_STACK) return TRUE;
    return FALSE;
}

Bool stack_isFull(const Stack *pila){
    if (pila == NULL) return TRUE;

    if (pila->top == MAXSTACK - 1) return TRUE;
    return FALSE;
}

int stack_print(FILE* f, const Stack* pila){
    int i, c = 0;
    if (pila == NULL) return -1;

    for (i = pila->top; i > -1; i--) {
        c += pila->pf_print(f, pila->item[i]);
        fprintf(f, "\n");

    }
    return c;
    
}
