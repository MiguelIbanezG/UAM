#include "stack_fDoble.h"
#include <string.h>
#include <stdio.h>
#define MAX_STACK 20

Status mergeStacks (Stack *sin1, Stack *sin2, Stack *sout){

    void *e = NULL;
    Stack *ps;

    if (sin1 == NULL || sin2 == NULL || sout == NULL){

        return ERROR;

    }

    while ((stack_isEmpty(sin1) == FALSE) && (stack_isEmpty(sin2) == FALSE))
    {
        if (stack_top(sin1) > stack_top(sin2))
        {
            e = stack_pop(sin1);
        }

        else{

            e = stack_pop(sin2);
        }
    
        stack_push(sout,e);

        
    }
    
    if (stack_isEmpty(sin1) == TRUE )
    {
        ps = sin2;
    }
    
    else {

        ps = sin1;

    }
    
    while (stack_isEmpty(ps) == FALSE) 
    {
        e = stack_pop(ps);
        stack_push(sout, e);

    }

    return OK;
    
}

int stack_read (FILE *pf, Stack *sin){

    int num, num_aux;
    char string[50];
    long *cm;

    if ((pf == NULL) || (stack_isEmpty(sin) == TRUE))
    {

        return ERROR;
    }

    fgets(string, 50, pf);
    sscanf(string, "%d", &num);
    
    num = num_aux;

    for (num ; num > 0; num--)
    {
        fgets (string, 50, pf);
        sscanf (string, "%ld", cm);
        stack_push (sin, cm);
    }
    

    return num_aux;
}

