/*
*Título: Funciones vértices, práctica 1, programación 2
*Grupo: viernes 2113
*Autores: Sergio Hidalgo y Miguel Ibáñez 
*/
#include <stdio.h>
#include <stdlib.h>
#include "stack_fDoble.h"
#include "file_utils.h"
#include "vertex.h"
#include "graph.h"

/*Cabeceras de las funciones privadas*/
Status mergeStacks(Stack *sin1, Stack *sin2, Stack *sout, P_vertex_cmp cmp);
int print_stackgrades(FILE *pf, const void *h);
void stack_Vertexpush(Stack *sin, int v, Graph *g);

int main(int argc, char *argv[]) /*Argumentos del main*/
{

    FILE *pf1 = NULL, *pf2 = NULL;
    Stack *sin1 = NULL, *sin2 = NULL, *sout = NULL; /*Funciones*/
    Graph *g1 = NULL, *g2 = NULL;
    int v1 = 0, v2 = 0;

    if (argc != 3) /*Si el número de argumentos es distinto de 3 el programa no se ejecuta*/
    {
        return -1;
    }
    
    g1 = graph_init(); /*Inicialización de los graph*/
    g2 = graph_init();
    sin1 = stack_init(); /*Inicialización de los stacks*/
    sin2 = stack_init();
    sout = stack_init();

    pf1 = fopen(argv[1], "r"); /*Se pasa el nombre de los ficheros txt que se han introducido como argumentos previamente*/
    pf2 = fopen(argv[2], "r");

    graph_readFromFile(pf1, g1);  /*Se lee el primer graph*/
    v1 = graph_getNumberOfVertices (g1); /*Se obtiene el número de vértices*/
    stack_Vertexpush (sin1, v1, g1); /*Se llama a la función que los meterá en el stack*/

    printf("Ranking 0:\n");
    stack_print(stdout, sin1, vertex_print); /*Se imprime el stack*/

    graph_readFromFile(pf2, g2); /*Se lee el segundo graph*/
    v2 = graph_getNumberOfVertices (g2); /*Se obtiene el número de vértices*/
    stack_Vertexpush (sin2, v2, g2); /*Se llama a la función que los meterá en el stack*/

    printf("Ranking 1:\n");
    stack_print(stdout, sin2, vertex_print); /*Se imprime el stack*/

    mergeStacks(sin1, sin2, sout, vertex_cmp); /*Se ordenan ambos stacks en uno solo de menor a mayor*/

    printf("Joint Ranking:\n");
    stack_print(stdout, sout, vertex_print); /*Se imprime el stack*/

    fclose(pf1); /*Se cierran los archivos*/
    fclose(pf2);

    stack_free(sin1);/*Se libera la memoria*/
    stack_free(sin2);
    stack_free(sout);

    return 0;
}

Status mergeStacks(Stack *sin1, Stack *sin2, Stack *sout, P_vertex_cmp cmp) /*Esta función ordena ambos stacks*/
{
    float *e = NULL;
    Stack *ps;
    if ((stack_isEmpty (sin1) == TRUE)|| (stack_isEmpty (sin2) == TRUE) || (stack_isEmpty (sout) == FALSE))
    {
        return ERROR;
    }

    while ((stack_isEmpty (sin1) == FALSE) && (stack_isEmpty (sin2) == FALSE))
    {
        if (cmp (stack_top (sin1) , stack_top (sin2)) == 1)  
        {
            e = stack_pop (sin1);
        }
        else
        {
            e = stack_pop (sin2);
        }
        stack_push (sout, e);
    }

    if (stack_isEmpty (sin1) == TRUE)
    {
        ps = sin2;
    }
    else if (stack_isEmpty (sin2) == TRUE)
    {
        ps = sin1;
    }

    while (stack_isEmpty (ps) == FALSE)
    {
        e = stack_pop (ps);
        stack_push (sout, e);
    }


    return OK;
}

void stack_Vertexpush(Stack *sin, int v, Graph *g) /*Esta función mete en el stack el vértice*/
{
    int i;

    for (i = 0; i < v; i++)
    {
        stack_push (sin, (Vertex *)graph_getVertex(g, i)); /*La función graoh_getVertex encuentra el vértice segun su posición*/
    }
}


