/*
*Título: Main file, práctica 1, ejercicio 2, programación 2
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

    Graph *g;
    long *connections;
    int i, num_connections;

    g = graph_init();

    printf("Inserting Madrid... result...: %d", graph_newVertex(g, "id:111 tag:Madrid state:0"));

    printf("\nInserting Madrid... result...: %d", graph_newVertex(g, "id:222 tag:Toledo state:0"));

    printf("\nInserting edge: 222 --> 111");

    graph_newEdge(g, 222, 111);

    printf("\n111 --> 222? ");
    if (graph_connectionExists(g, 111, 222) == TRUE)
    {
        printf("Yes");
    }
    else
        printf("No");

    printf("\n222 --> 111? ");
    if (graph_connectionExists(g, 222, 111) == TRUE)
    {
        printf("Yes");
    }
    else
        printf("No");

    printf("\nNumber of connections from 111: %d", graph_getNumberOfConnectionsFromId(g, 111));
    printf("\nNumber of connections from Toledo: %d", graph_getNumberOfConnectionsFromTag(g, "Toledo"));

    printf("\nConnections from Toledo:");

    connections = graph_getConnectionsFromTag(g, "Toledo");
    num_connections = graph_getNumberOfConnectionsFromTag(g, "Toledo");

    for (i = 0; i < num_connections; i++)
    {
        printf(" %ld", connections[i]);
    }

    printf("\nGraph:");
    graph_print(stdout, g);

    graph_free(g);
    free(connections);

    return 0;
}