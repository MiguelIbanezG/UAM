#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#include "stack_elestack.h"
#include "int.h"

extern int errno;

double pila_media(Stack *pila) {
    int i;
    double suma = 0;
    Stack *pila2;
    EleStack *ele;

    pila2 = stack_ini();

    for (i = 0; stack_isEmpty(pila) == FALSE; i++) {

        ele = stack_pop(pila);
        suma += *(int*)EleStack_getInfo(ele);
        stack_push(pila2, ele);


    }

    while (stack_isEmpty(pila2) == FALSE) {
        stack_push(pila, stack_pop(pila2));

    }

    stack_destroy(pila2);
    EleStack_destroy(ele);
    return suma / i;
}

int main(int argc, char** argv) {
    int ent, i;
    double media = 0;
    EleStack *ele = NULL;
    Stack *pila = NULL;

    ent = atoi(argv[1]);


    pila = stack_ini();
    if (pila == NULL) {
        fprintf(stderr, "%s\n", strerror(errno));
        return 1;
    }



    for (i = 0; i <= ent; i++) {
        ele = EleStack_ini();
        if (ele == NULL) {
        fprintf(stderr, "%s\n", strerror(errno));
        return 1;
        }
        
        EleStack_setInfo(ele, &i);

        stack_push(pila, ele);
        
        EleStack_destroy(ele);
    }
    printf("Pila antes de la llamada a la función:\n");

    stack_print(stdout, pila);

    printf("\nLa media es %lf", pila_media(pila));

    printf("\nPila después de la llamada a la función:\n");

    stack_print(stdout, pila);

    

    return (EXIT_SUCCESS);
}
