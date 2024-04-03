#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include "stack_elestack.h"
#include "node.h"

void main() {
    int car,i;
    Stack *pila;
    EleStack *ele = NULL;
    Node *n = NULL;

    ele = EleStack_ini();
    if (ele == NULL) {
        fprintf(stderr, "%s\n", strerror(errno));
        return;
    }

    n = node_ini();
    if (n == NULL) {
        fprintf(stderr, "%s\n", strerror(errno));
        return;
    }

    pila = stack_ini();
    if (pila == NULL) {
        fprintf(stderr, "%s\n", strerror(errno));
        return;
    }

    node_setId(n, 111);
    node_setName(n, "first");
    if ((EleStack_setInfo(ele, n)) == ERROR) {
        fprintf(stderr, "%s\n", strerror(errno));
        return;
    }

    if (stack_push(pila, ele) == ERROR) {
        fprintf(stderr, "%s\n", strerror(errno));
        return;
    }
    
    node_setId(n, 222);
    node_setName(n, "second");
    if ((EleStack_setInfo(ele, n)) == ERROR) {
        fprintf(stderr, "%s\n", strerror(errno));
        return;
    }

    if (stack_push(pila, ele) == ERROR) {
        fprintf(stderr, "%s\n", strerror(errno));
        return;
    }
    
    printf("Contenido de la pila: \n");
    car=stack_print(stdout, pila);
    printf("Caracteres imprimidos: %d", car);
    
    printf("\nVaciando pila. Extracciones: \n");

    for(; stack_isEmpty(pila)==FALSE;){
        EleStack_print(stdout, stack_pop(pila));     
        
    }
    
    printf("\nContenido de la pila despues de vaciar: \n");
    car=stack_print(stdout, pila);
    printf(" Caracteres imprimidos: %d", car);
    
    EleStack_destroy(ele);
    node_destroy(n);
    stack_destroy(pila);

    return;
}