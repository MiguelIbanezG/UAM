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


int main (int argc, char *args[])
{
    FILE *pf = NULL;
    Graph *g = NULL;
    int i;
    long from_id = atol(args[2]), to_id = atol(args[3]);

    if (argc != 4)
    {
        printf ("Input file is NULL");
        return -1;
    }
    
    g = graph_init();

   pf = fopen(args[1],"r");

   if (pf == NULL)
   {
       return -1;
   }
   
    graph_readFromFile (pf, g);

    fclose(pf);

    fprintf(stdout,"Input graph:");
    graph_print(stdout, g);

    fprintf(stdout,"From Vertex id: %ld\n", from_id);
    fprintf(stdout,"To Vertex id: %ld\n", to_id);

    fprintf(stdout,"Output: \n");

    graph_depthSearch(g, from_id, to_id);

    for (i = 0; i < graph_getNumberOfVertices(g); i++)
    {
        if (vertex_getState(graph_getVertex(g, i)) == 1)
        {
            vertex_print(stdout, graph_getVertex(g, i));
            printf("\n"); 
        }
        
    }
    graph_free(g);
    


    return 0;
}