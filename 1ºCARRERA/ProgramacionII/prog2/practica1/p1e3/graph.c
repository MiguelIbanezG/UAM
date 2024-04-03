#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "node.h"
#include "types.h"
#include "graph.h"



struct _Graph{
    int num_nodes;
    Node  *nodes [MAX];
    int connections [MAX][MAX];
    
};

Graph * graph_ini(){
    int i, j;
    Graph *g;
    g=(Graph*)malloc(sizeof(Graph));
    
    g->num_nodes = 0;
    
    for(i=0;i<MAX;i++)
        g->nodes[i] = node_ini(); 
        
    if(g==NULL){
        fprintf(stdout,"La asignación de memoria ha fallado.");
    }
    return g;
}

void graph_destroy(Graph * g){
    int i;
    
    for(i=0;i<MAX;i++)
        node_destroy(g->nodes[i]); 
    
    free(g);
    
}

Status graph_insertNode(Graph * g, const Node * n){
    Node *z;
    
    if ((g->num_nodes +1)> MAX)
        return ERROR;
    
    for(int i = 0; i< g->num_nodes; i++){
        if ( node_getId(n) == node_getId(g->nodes[i]) )
            return ERROR;
    }
    z=node_copy(n);
    node_setId(g->nodes[g->num_nodes],node_getId(z));
    node_setName(g->nodes[g->num_nodes],node_getName(z));
    g->num_nodes++;
    
    return OK;
}

Status graph_insertEdge(Graph * g, const int nId1, const int nId2){
    int i, j;
    
    for( i = 0; i< g->num_nodes; i++){
        if (node_getId(g->nodes[i]) == nId1 )
            break;          
    }
    for( j = 0; j< g->num_nodes; j++){
        if (node_getId(g->nodes[j]) == nId2 )
            break;
    }
    
    if (i==j)
        return ERROR;
    else{
        g->connections[i][j] = 1;
        node_setConnect(g->nodes[i], node_getConnect(g->nodes[i])+1);    
    }
} 

Node *graph_getNode (const Graph *g, int nId){
    Node *n;
    int i;
    n = node_ini();
    for( i = 0; i< g->num_nodes; i++){
        if (node_getId(g->nodes[i]) == nId ){
            n = node_copy(g->nodes[i]);
            break;          
        }
    }
    
    return n;
}

Status graph_setNode (Graph *g, const Node *n){
    int i;
    
    for( i = 0; i< g->num_nodes; i++){
        if (node_getId(g->nodes[i]) == node_getId(n) ){
            g->nodes[i]=node_copy(n); 
            return OK;          
        }
    }
    return ERROR;
}

int * graph_getNodesId (const Graph * g){
    int *array, i;

    array = (int *) malloc(g->num_nodes*sizeof(int));
    if (!array) {
       return NULL;
    }

    for(i = 0; i< g->num_nodes; i++) {
        array[i]= node_getId(g->nodes[i]);
    }

    return array;    
}


int graph_getNumberOfNodes(const Graph * g){
    if (g==NULL)
        return -1;
    else 
        return g->num_nodes;
    
}

int graph_getNumberOfEdges(const Graph * g){
    int i, j, aristas=0;
    
    if (g==NULL)
        return -1;
    
    for(i=0; i< g->num_nodes;i++){
        for(j=0; j<i;j++)
            if(g->connections[i][j] == 1)
                aristas++;
            
    }
    
    return aristas;
}

Bool graph_areConnected(const Graph * g, const int nId1, const int nId2){
    int i, j;
    
    for( i = 0; i< g->num_nodes; i++){
        if (node_getId(g->nodes[i]) == nId1 )
            break;          
    }
    for( j = 0; j< g->num_nodes; j++){
        if (node_getId(g->nodes[j]) == nId2 )
            break;
    }
    
    if(g->connections[i][j]== 1)
        return TRUE;
    else 
        return FALSE;
    
}

int graph_getNumberOfConnectionsFrom(const Graph * g, const int fromId){
    int i;
    
    for( i = 0; i< g->num_nodes; i++){
        if (node_getId(g->nodes[i]) == fromId )
            break;          
    }
    
    return node_getConnect(g->nodes[i]);
    
}


int graph_print (FILE *pf, const Graph * g ){
    int i=0, k=0, suma=0, suma2=0;
    
    for(int j=0;j< g->num_nodes; j++){
        
        i=fprintf(pf,"[%s, %d, %d]", node_getName(g->nodes[j]), node_getId(g->nodes[j]), node_getConnect(g->nodes[j]));
        for(int h=0; h < g->num_nodes;h++)
            if(g->connections[j][h]==1){
                k = fprintf (pf, " %d", node_getId(g->nodes[h]));
                suma2=+ k;
            }
        fprintf(pf, "\n");
        i++;
        suma =+ i;
    }
    return suma + suma2;
}


int find_node_index(const Graph * g, int nId1) {
 int i;
 if (!g) return -1;

 for(i=0; i < g->num_nodes; i++) {
 if (node_getId (g->nodes[i]) == nId1) return i;
 }

 // ID not find
 return -1;
}
int* graph_getConectionsIndex(const Graph * g, int index) {
 int *array = NULL, i, j=0, size;

 if (!g) return NULL;
 if (index < 0 || index >g->num_nodes) return NULL;
 // get memory for the array with the connected nodes index
 size = node_getConnect (g->nodes[index]);
 array = (int *) malloc(sizeof(int) * size);
 if (!array) {
 // print errorr message
 fprintf (stderr, "%s\n", strerror(ERROR));
 return NULL;
 }

 // asigno valores al array con los indices de los nodos conectados
 for(i = 0; i< g->num_nodes; i++) {
 if (g->connections[index][i] == TRUE) {
 array[j] = i;
 j++;
 }
 }

 return array;
}

Status graph_readFromFile (FILE *fin, Graph *g) {
 Node *n;
 char buff[MAX_LINE], name[MAX_LINE];
 int i, nnodes = 0, id1, id2;
 Status flag = ERROR;

 // read number of nodes
 if ( fgets (buff, MAX_LINE, fin) != NULL)
 if ( sscanf(buff, "%d", &nnodes) != 1) return ERROR;

 // init buffer_node
 n = node_ini();
 if (!n) return ERROR;

 // read nodes line by line
 for(i=0; i < nnodes; i++) {
 if ( fgets(buff, MAX_LINE, fin) != NULL)
 if (sscanf(buff, "%d %s", &id1, name) != NO_FILE_POS_VALUES) break;

 // set node name and node id
 node_setName (n, name);
 node_setId (n, id1);

 // insert node in the graph
if ( graph_insertNode (g, n) == ERROR) break;
 }

 // Check if all node have been inserted
 if (i < nnodes) {
 node_destroy(n);
 return ERROR;
 }

 // read connections line by line and insert it
 while ( fgets(buff, MAX_LINE, fin) ) {
 if ( sscanf(buff, "%d %d", &id1, &id2) == NO_FILE_POS_VALUES )
 if (graph_insertEdge(g, id1, id2) == ERROR) break;
 }

 // check end of file
 if (feof(fin)) flag = OK;

 // clean up, free resources
 node_destroy (n);
 return flag;
}



