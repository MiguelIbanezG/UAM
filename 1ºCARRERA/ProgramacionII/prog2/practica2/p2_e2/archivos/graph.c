#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include "graph.h"

extern int errno;

struct _Graph {
    int num_nodes;
    int num_edges;
    Node *nodes [MAX];
    int connections [MAX][MAX];

};

Graph * graph_ini() {
    int i;
    Graph *g;
    g = (Graph*) malloc(sizeof (Graph));

    if (!g) {
        fprintf(stderr, "%s\n", strerror(errno));
        return NULL;
    }

    g->num_nodes = 0;
    g->num_edges = 0;

    for (i = 0; i < MAX; i++)
        g->nodes[i] = NULL;


    return g;
}

void graph_destroy(Graph * g) {
    int i;
	
    for (i = 0; i < MAX; i++)
        node_destroy(g->nodes[i]);

    free(g);

}

Status graph_insertNode(Graph * g, const Node * n) {
    Node *z;
    
    if(g==NULL) return ERROR;
    
    if(n==NULL) return ERROR;
    

    if ((g->num_nodes + 1) > MAX)
        return ERROR;

    if(find_node_index(g, node_getId(n)))
    	return ERROR;
    
    z = node_copy(n);
    if(z==NULL){
        fprintf(stderr, "%s\n", strerror(errno));
        return ERROR;
    }
    
    g->nodes[g->num_nodes] = z;
    node_setId(g->nodes[g->num_nodes], node_getId(z));
    node_setName(g->nodes[g->num_nodes], node_getName(z));
    g->num_nodes++;
    

    return OK;
}

Status graph_insertEdge(Graph * g, const int nId1, const int nId2) {
	
	if(g==NULL)return ERROR;
    
	
	if(find_node_index(g,nId1)==-1 || find_node_index(g,nId2)==-1)
		return ERROR;
	
    if (nId1 == nId2)
        return ERROR;
        
    else {
        g->connections[find_node_index(g,nId1)][find_node_index(g, nId2)] = 1;
        node_setConnect(g->nodes[find_node_index(g,nId1)], node_getConnect(g->nodes[find_node_index(g, nId2)]) + 1);
        g->num_edges++;
        return OK;
    }
    
}

Node *graph_getNode(const Graph *g, int nId) {
    Node *n;
    
    if(g==NULL) return ERROR;
    
    if(find_node_index(g,nId)== -1)
    	return NULL;
    
	n = node_copy(g->nodes[find_node_index(g,nId)]);
         

    return n;
}

Status graph_setNode(Graph *g, const Node *n) {
	
	if(g==NULL)return ERROR;
    
    if(n==NULL)return ERROR;
    
    
    if (find_node_index(g,node_getId(n))==-1)
    	return ERROR;
    
    node_setId(g->nodes[find_node_index(g, node_getId(n))],node_getId(n));
    node_setName(g->nodes[find_node_index(node_getId(n))],node_getName(n));
    node_setConnect(g->nodes[find_node_index(node_getId(n))], node_getConnect(n));
    
    return ERROR;
}

int * graph_getNodesId(const Graph * g) {
    int *array, i;
    
    if(g==NULL)return ERROR;
    

    array = (int *) malloc(g->num_nodes * sizeof (int));
    if (!array) {
        fprintf(stderr, "%s\n", strerror(errno));
        return NULL;
    }


    for (i = 0; i < g->num_nodes; i++) {
        array[i] = node_getId(g->nodes[i]);
    }

    return array;
}

int graph_getNumberOfNodes(const Graph * g) {
    if (g == NULL)
        return -1;
    else
        return g->num_nodes;

}

int graph_getNumberOfEdges(const Graph * g) {

    if (g == NULL)
        return -1;

    
    return g->num_edges;
}

Bool graph_areConnected(const Graph * g, const int nId1, const int nId2) {
    
	if(g==NULL)return ERROR;
	
    if (g->connections[find_node_index(g, nId1)][find_node_index(g, nId2)] == 1)
        return TRUE;
    else
        return FALSE;

}

int graph_getNumberOfConnectionsFrom(const Graph * g, const int fromId) {
	
	if(g==NULL)return -1;
    

    return node_getConnect(g->nodes[find_node_index(g, fromId)]);

}

//Ya que el comentario de la funcion en graph.h es el mismo que el de la funcion graph_getNodesId
//hemos supuesto que esta funcion devuelve un array con las direcciones de los nodos conectados al nodo de id fromId

int* graph_getConnectionsFrom(const Graph * g, const int fromId) {
    int *array, i, j;
    
    if(g==NULL){
        fprintf(stderr, "%s\n", strerror(errno));
        return NULL;
    }
	
	if (find_node_index(g, fromId)== -1 )
		return NULL;

    j = graph_getNumberOfConnectionsFrom(g, fromId);

    array = (int *) malloc(j * sizeof (int));
    if (!array) {
        fprintf(stderr, "%s\n", strerror(errno));
        return NULL;
    }

    for (i = 0; i < g->num_nodes; i++) {
        if (graph_areConnected(g, fromId, node_getId(g->nodes[i])) == 1)
            array[i] = node_getId(g->nodes[i]);
    }

    return array;


}

int graph_print(FILE *pf, const Graph * g) {
    int i = 0, j=0, suma = 0;

    for (j = 0; j < g->num_nodes; j++) {

        suma = fprintf(pf, "[%s, %d, %d]", node_getName(g->nodes[j]), node_getId(g->nodes[j]), node_getConnect(g->nodes[j]));
        for (i = 0; i < g->num_nodes; i++)
            if (g->connections[j][i] == 1) {
                suma += fprintf(pf, " %d", node_getId(g->nodes[i]));
                
            }
        fprintf(pf, "\n");

    }
    return suma;
}

int find_node_index(const Graph * g, int nId1) {
    int i;
    if (!g) return -1;

    for (i = 0; i < g->num_nodes; i++) {
        if (node_getId(g->nodes[i]) == nId1) return i;
    }

    // ID not find
    return -1;
}

int* graph_getConectionsIndex(const Graph * g, int index) {
    int *array = NULL, i, j = 0, size;

    if (!g) return NULL;
    if (index < 0 || index > g->num_nodes) return NULL;
    // get memory for the array with the connected nodes index
    size = node_getConnect(g->nodes[index]);
    array = (int *) malloc(sizeof (int) * size);
    if (!array) {
        // print errorr message
        fprintf(stderr, "%s\n", strerror(errno));
        return NULL;
    }

    // asigno valores al array con los indices de los nodos conectados
    for (i = 0; i < g->num_nodes; i++) {
        if (g->connections[index][i] == TRUE) {
            array[j] = i;
            j++;
        }
    }

    return array;
}

Status graph_readFromFile(FILE *fin, Graph *g) {
    Node *n;
    char buff[MAX_LINE], name[MAX_LINE];
    int i, nnodes = 0, id1, id2;
    Status flag = ERROR;

    // read number of nodes
    if (fgets(buff, MAX_LINE, fin) != NULL)
        if (sscanf(buff, "%d", &nnodes) != 1) return ERROR;

    // init buffer_node
    n = node_ini();
    if (!n) return ERROR;

    // read nodes line by line
    for (i = 0; i < nnodes; i++) {
        if (fgets(buff, MAX_LINE, fin) != NULL)
            if (sscanf(buff, "%d %s", &id1, name) != NO_FILE_POS_VALUES) break;

        // set node name and node id
        node_setName(n, name);
        node_setId(n, id1);

        // insert node in the graph
        if (graph_insertNode(g, n) == ERROR) break;
    }

    // Check if all node have been inserted
    if (i < nnodes) {
        node_destroy(n);
        return ERROR;
    }

    // read connections line by line and insert it
    while (fgets(buff, MAX_LINE, fin)) {
        if (sscanf(buff, "%d %d", &id1, &id2) == NO_FILE_POS_VALUES)
            if (graph_insertEdge(g, id1, id2) == ERROR) break;
    }

    // check end of file
    if (feof(fin)) flag = OK;

    // clean up, free resources
    node_destroy(n);
    return flag;
}
