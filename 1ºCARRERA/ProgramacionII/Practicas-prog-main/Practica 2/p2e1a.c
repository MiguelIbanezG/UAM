#include <stdio.h>
#include <stdlib.h>
#include "stack_fDoble.h"

Status mergeStacks (Stack *sin1, Stack *sin2, Stack *sout);
int print_stackgrades (FILE *pf, const void *h);
int stack_read (FILE *pf, Stack *sin);

int main()
{

    FILE *pf1, *pf2;
    Stack *sin1, *sin2, *sout;
    int s1, s2;

    sin1 = stack_init();
    sin2 = stack_init();
    sout = stack_init();

    pf1 = fopen("grades1.txt", "r");
    pf2 = fopen("grades2.txt", "r");

    s1 = stack_read(pf1, sin1);
    s2 = stack_read(pf2, sin2);

    mergeStacks(sin1, sin2, sout);

    stack_print(stdout, sout, print_stackgrades);

    fclose(pf1);
    fclose(pf2);

    stack_free(sin1);
    stack_free(sin2);
    stack_free(sout);

    return 0;
}

Status mergeStacks(Stack *sin1, Stack *sin2, Stack *sout)
{

    void *e = NULL;
    Stack *ps;

    if (sin1 == NULL || sin2 == NULL || sout == NULL)
    {

        return ERROR;
    }

    while ((stack_isEmpty(sin1) == FALSE) && (stack_isEmpty(sin2) == FALSE))
    {
        if (stack_top(sin1) > stack_top(sin2))
        {
            e = stack_pop(sin1);
        }

        else
        {

            e = stack_pop(sin2);
        }

        stack_push(sout, e);
    }

    if (stack_isEmpty(sin1) == TRUE)
    {
        ps = sin2;
    }

    else
    {

        ps = sin1;
    }

    while (stack_isEmpty(ps) == FALSE)
    {
        e = stack_pop(ps);
        stack_push(sout, e);
    }

    return OK;
}

int stack_read(FILE *pf, Stack *sin) /*!*/
{

    int num, i;
    char string[50];
    double* cm;

   

    fgets(string, 50, pf);
    num = atol (string);
    
    i = num;
    
    do
    {
        cm = NULL;
        cm = (double*) malloc (sizeof(double));
        fgets(string, 50, pf);
        *cm = atof (string);
        stack_push(sin, cm);
        free (cm);
        i--;
    } while (i > 0);

    return num;
}

int print_stackgrades(FILE *pf, const void *h)
{
    int i;

    i = fprintf(pf, "%.6f", (*(float *)h));
    return i;
}
