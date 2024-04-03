/*
*Título: Main file, práctica 1, ejercicio 2.3, programación 2
*Grupo: viernes 2113
*Autores: Sergio Hidalgo y Miguel Ibáñez 
*/

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "graph.h"
#include "vertex.h"
#include "types.h"

int main()
{
    FILE *pf;
    Graph *g;

    pf = fopen("g1.txt", "r");

    if (pf == NULL)
    {

        return -1;
    }

    g = graph_init();

    if (graph_readFromFile(pf, g) == ERROR)
    {
        return -1;
    }

    graph_print(stdout, g);

    fclose(pf);

    graph_free(g);

    return 0;
}
