#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "graph.h"
#include "vertex.h"

int main(){
    
    Graph *g;
    long* c;
    int n;

    g = graph_init();
    
    printf ("Inserting Madrid... result...: %d", graph_newVertex (g, "id:111 tag:Madrid state:WHITE"));
    printf ("\nInserting Toledo... result...: %d", graph_newVertex (g, "id:222 tag:Toledo state:WHITE"));
    printf ("\nInserting edge: 222 --> 111");
    
    graph_newEdge(g, 222, 111);
    
    printf ("\n111 --> 222? ");
    
    if (graph_connectionExists(g, 111, 222) == TRUE)
    {
        printf ("Yes");
    }
    else
        printf ("No");
    

    printf ("\n222 --> 111? ");
    if (graph_connectionExists(g, 222, 111) == TRUE)
    {
        printf ("Yes");
    }
    else
        printf ("No");


    printf ("\nNumber of connections from 111: %d", graph_getNumberOfConnectionsFromId(g, 111));
    printf ("\nNumber of connections from Toledo: %d", graph_getNumberOfConnectionsFromTag(g, "Toledo"));

    printf("\nConnections from Toledo:");

   
    c = graph_getConnectionsFromTag(g, "Toledo");
    n = graph_getNumberOfConnectionsFromTag(g, "Toledo");

    for (int j = 0; j < n; j++)
    {
        printf (" %ld", c[j]);    
    }

    printf ("\nGraph:");
    graph_print (stdout, g);

    graph_free (g);
    free (c);

    
    
    return 0;

}
