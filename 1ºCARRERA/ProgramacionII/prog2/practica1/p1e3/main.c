#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "node.h"
#include "types.h"
#include "graph.h"

int main() {
    Graph *g;
    Node *a, *b;
    
    g= graph_ini();
    
    a=node_ini();
    b=node_ini();
    
    node_setId(a, 111);
    node_setName(a,"first");
    node_setId(b,222);
    node_setName(b, "second");
    
    printf("Insertando nodo 1...resultado...: %d", graph_insertNode(g, a));
    printf("\nInsertando nodo 2...resultado...: %d", graph_insertNode(g, b));
    
    printf("\nInsertando edge: nodo 2 ---> nodo 1");
    
    graph_insertEdge(g, 222, 111);
    
    printf("\nConectados nodo 1 y nodo 2?");
    if(graph_areConnected(g, 111, 222)) printf("Sí.");
    else printf("No.");
           
    printf("\nConectados nodo 2 y nodo 1?");
    if(graph_areConnected(g, 222, 111)) printf("Sí.");
    else printf("No.");
    printf("\nInsertando nodo 2...resultado...: %d", graph_insertNode(g, b));
    
    printf("\nGrafo:\n");
    graph_print(stdout, g);
    
    node_destroy(a);
    node_destroy(b);
    graph_destroy(g);
    
    return 0;
}

/*int main(int argc, char **argv){
    Graph *g;
    FILE *f;
    g=graph_ini();
    f=fopen(argv[1],"r");
    graph_readFromFile(f,g);
    graph_print(stdout,g);    
    
    return 1;
}

*/

