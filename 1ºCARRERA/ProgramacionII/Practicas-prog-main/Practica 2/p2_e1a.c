/*
*Título: Funciones vértices, práctica 1, programación 2
*Grupo: viernes 2113
*Autores: Sergio Hidalgo y Miguel Ibáñez 
*/
#include <stdio.h>
#include <stdlib.h>
#include "stack_fDoble.h"
#include "file_utils.h"

/*Cabeceras de las funciones privadas*/
Status mergeStacks(Stack *sin1, Stack *sin2, Stack *sout);
int print_stackgrades(FILE *pf, const void *h);
int stack_read(FILE *pf, Stack *sin, float *cm);

int main(int argc, char *argv[]) /*Argumentos del main*/
{

    FILE *pf1, *pf2;
    Stack *sin1, *sin2, *sout; /*Funciones*/
    float *cm = NULL;

    if (argc != 3) /*Si el número de argumentos es distinto de 3 el programa no se ejecuta*/
    {
        return -1;
    }

    sin1 = stack_init(); /*Inicialización de los stacks*/
    sin2 = stack_init();
    sout = stack_init();

    pf1 = fopen(argv[1], "r"); /*Se pasa el nombre de los ficheros txt que se han introducido como argumentos previamente*/
    pf2 = fopen(argv[2], "r");

    stack_read(pf1, sin1, cm); /*Se lee el primer fichero y se pasa a stack*/

    printf("Ranking 0:\n");
    stack_print(stdout, sin1, print_stackgrades); /*Se imprime*/

    stack_read(pf2, sin2, cm); /*Se lee el segundo fichero y se pasa a stack*/

    printf("Ranking 1:\n");
    stack_print(stdout, sin2, print_stackgrades); /*Se imprime*/

    mergeStacks(sin1, sin2, sout); /*Se ordenan ambos stacks en uno solo de menor a mayor*/

    printf("Joint Ranking:\n");
    stack_print(stdout, sout, print_stackgrades); /*Se imprime*/

    fclose(pf1); /*Se cierran los archivos*/
    fclose(pf2);

    free(cm);   /*Se libera la memoria*/
    stack_free(sin1);
    stack_free(sin2);
    stack_free(sout);

    return 0;
}

Status mergeStacks(Stack *sin1, Stack *sin2, Stack *sout) /*Esta función ordena ambos stacks*/
{
    float *e = NULL;
    Stack *ps;
    if ((stack_isEmpty(sin1) == TRUE) || (stack_isEmpty(sin2) == TRUE) || (stack_isEmpty(sout) == FALSE))
    {
        return ERROR;
    }

    while ((stack_isEmpty(sin1) == FALSE) && (stack_isEmpty(sin2) == FALSE))
    {
        if (float_cmp(stack_top(sin1), stack_top(sin2)) == 1)
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
    else if (stack_isEmpty(sin2) == TRUE)
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

int stack_read (FILE *pf, Stack *sin, float *cm) /*Esta función lee el archivo para pasar sus valores a un stack*/
{

    int num, i;

    if (pf == NULL)
    {
        return -1;
    }

    fscanf (pf, "%d", &num); /*primero analiza el número de notas que hay*/
    i = num;

    do
    {
        cm = NULL;
        cm = (float *)malloc (sizeof(float)); /*después hace una reserva de memoria de un puntero*/
        fscanf (pf, "%f", (float *)cm); /*Para así poder pasar el valor al puntero*/
        stack_push (sin, (float *)cm); /*Se mete en el stack*/
        i--;
    } while (i > 0); /*Se repetirá hasta que se acaben los valores*/

    return num;
}

int print_stackgrades(FILE *pf, const void *h) /*Esta función se usa en stack_print para imprimir los valores*/
{
    int i;

    if (pf == NULL)
    {

        return -1;
    }

    i = fprintf(pf, "%.6f", *(float *)h);
    return i;
}
