/******************************************************************************

Nombre del modulo: graph.c

Descripcion: Implementacion de las funciones de graph.h. Sirve para trabajar con grafos.
			 Es el mismo fichero que el de la practica anterior con algunas correcciones
			 y con la funcion graph_findDeepSearch.

Autor: Jorge Fernandez Garcia y Pedro Sanchez de la Muela

Fecha: 25 - 3 - 2019

******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#include "graph.h"
#include "queue.h"


extern int errno;

#define MAX_NODES 1096
#define MAX_LINE 256

enum {NO_FILE_POS_VALUES = 2};

struct _Graph {
    int num_nodes;
    int num_edges;
    Node *nodes [MAX_NODES];
    Bool connections [MAX_NODES][MAX_NODES];

};

Graph * graph_ini() {
    int i, j;
    Graph *g=NULL;
    g = (Graph*) malloc(sizeof (Graph));

    if (!g) {
        fprintf(stderr, "%s\n", strerror(errno));
        return NULL;
    }

    g->num_nodes = 0;
    g->num_edges = 0;

    for (i = 0; i < MAX_NODES; i++)
        g->nodes[i] = NULL;

    for (i = 0; i < MAX_NODES; i++)
        for (j = 0; j < MAX_NODES; j++)
          g->connections [i][j] = FALSE;



    return g;
}

void graph_destroy(Graph * g) {
    int i;

    if (g==NULL)return;

    for (i = 0; i < g-> num_nodes; i++)
        node_destroy(g->nodes[i]);

    free(g);

}

Status graph_insertNode(Graph * g, const Node * n) {
    int i, indice;

    if (!g || !n || (g->num_nodes + 1) > MAX_NODES) return ERROR;

    indice = find_node_index(g, node_getId(n));
    if (indice != -1)
        return ERROR;

    g->nodes[g->num_nodes] = node_copy(n);
    if (g->nodes[g->num_nodes] == NULL) {
        fprintf(stderr, "%s\n", strerror(errno));
        return ERROR;
    }

    for (i = 0; i <= g->num_nodes; i++) {
           g->connections[g->num_nodes][i] = 0;
    }

    g->num_nodes++;


    return OK;
}

Status graph_insertEdge(Graph * g, const int nId1, const int nId2) {
    int ind1, ind2;

    if (g == NULL)return ERROR;

    ind1 = find_node_index(g, nId1);
    ind2 = find_node_index(g, nId2);
    if (ind1 == -1 || ind2 == -1)
        return ERROR;

    if (nId1 == nId2 || g->connections[ind1][ind2] == TRUE)
        return ERROR;

    g->connections[ind1][ind2] = 1;
    node_setConnect(g->nodes[ind1], node_getConnect(g->nodes[ind1]) + 1);
    g->num_edges++;
    return OK;


}

Node *graph_getNode(const Graph *g, int nId) {
    Node *n;

    if (g == NULL) return ERROR;

    if (find_node_index(g, nId) == -1)
        return NULL;

    n = node_copy(g->nodes[find_node_index(g, nId)]);


    return n;
}

Status graph_setNode(Graph *g, const Node *n) {
    int index;
    if (g == NULL)return ERROR;

    if (n == NULL)return ERROR;

    index = find_node_index(g, node_getId(n));
    if (index == -1)
        return ERROR;

    node_setId(g->nodes[index], node_getId(n));
    node_setName(g->nodes[index], node_getName(n));
    node_setConnect(g->nodes[index], node_getConnect(n));

    return ERROR;
}

int * graph_getNodesId(const Graph * g) {
    int *array, i;

    if (g == NULL)return ERROR;


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

    return g->num_nodes;

}

int graph_getNumberOfEdges(const Graph * g) {

    if (g == NULL)
        return -1;


    return g->num_edges;
}

Bool graph_areConnected(const Graph * g, const int nId1, const int nId2) {
    int index1, index2;

    if (g == NULL)return ERROR;

    index1 = find_node_index(g, nId1);
    index2 = find_node_index(g, nId2);
    if (index1 == -1 || index2 == -1) return FALSE;

    if (g->connections[index1][index2] == 1)
        return TRUE;
    else
        return FALSE;

}

int graph_getNumberOfConnectionsFrom(const Graph * g, const int fromId) {
	  int i;

    if (g == NULL)return -1;

    i = find_node_index(g, fromId);

    if (i == -1) return -1;

    return node_getConnect(g->nodes[i]);
}

//Ya que el comentario de la funcion en graph.h es el mismo que el de la funcion graph_getNodesId
//hemos supuesto que esta funcion devuelve un array con las direcciones de los nodos conectados al nodo de id fromId

int* graph_getConnectionsFrom(const Graph * g, const int fromId) {
    int *array, i, connect;

    if (g == NULL) {
        fprintf(stderr, "%s\n", strerror(errno));
        return NULL;
    }

    if (find_node_index(g, fromId) == -1)
        return NULL;

    connect = graph_getNumberOfConnectionsFrom(g, fromId);

    array = (int *) malloc(connect * sizeof (int));
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
    int i = 0, j = 0, suma = 0;

    if (!g || !pf) {
       fprintf (stderr, "%s\n", strerror(errno));
       return -1;
   }


    for (j = 0; j < g->num_nodes; j++) {

        suma += fprintf(pf, "[%s, %d, %d]", node_getName(g->nodes[j]), node_getId(g->nodes[j]), node_getConnect(g->nodes[j]));
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

    for (i = 0; i < g->num_nodes; i++) {
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

        if (graph_insertNode (g, n) == ERROR) break;
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

void graph_DeepSearch_free (Queue* q, Queue* q_print, int* index_node, int *index_vecinos, int *id_nodo1);

Node *graph_findDeepSearch(Graph *g, int from_id, int to_id) {
    Queue* q = NULL, *q_print=NULL;
    int og_index, fin_index, num_vecinos, i, id_flag=1, id_inicial,  id_antecesor, *index_node = NULL, *index_vecinos = NULL, *id_nodo1=NULL;


    if (!g|| from_id == to_id) return NULL;

    q_print = queue_ini(int_destroy, int_copy, int_print);

    if (!q_print) {
        graph_DeepSearch_free (q, q_print, index_node, index_vecinos, id_nodo1);
        fprintf(stderr, "%s", strerror(errno));
        return NULL;
    }

    og_index = find_node_index(g, from_id);
    fin_index = find_node_index(g, to_id);

    if (og_index == -1 || fin_index == -1) {
    	graph_DeepSearch_free (q, q_print, index_node, index_vecinos, id_nodo1);
        return NULL;
    }

    q = queue_ini(int_destroy, int_copy, int_print);

    if (!q) {
        graph_DeepSearch_free (q, q_print, index_node, index_vecinos, id_nodo1);
        fprintf(stderr, "%s", strerror(errno));
        return NULL;
    }

    if (queue_insert(q, &og_index) == ERROR) {
        graph_DeepSearch_free (q, q_print, index_node, index_vecinos, id_nodo1);
        return NULL;
    }

    while (queue_isEmpty(q) == FALSE) {

        index_node = (int*) queue_extract(q);

        if (node_getLabel(g->nodes[*index_node]) == BLANCO) {

            node_setLabel(g->nodes[*index_node], NEGRO);

            index_vecinos = graph_getConectionsIndex(g, *index_node);

            if (index_vecinos == NULL) {
                graph_DeepSearch_free (q, q_print, index_node, index_vecinos, id_nodo1);
                fprintf(stderr, "%s", strerror(errno));
                return NULL;
            }

            num_vecinos = graph_getNumberOfConnectionsFrom(g, node_getId(g->nodes[*index_node]));

            for (i = 0; i < num_vecinos; i++) {

                if (index_vecinos[i] == fin_index) {

                    node_setAntecesorId (g->nodes[fin_index], node_getId(g->nodes[*index_node]));
                    id_inicial = node_getId(g->nodes[fin_index]);
                    if (queue_insert(q_print, &id_inicial) == ERROR) {
                        graph_DeepSearch_free (q, q_print, index_node, index_vecinos, id_nodo1);
                        return NULL;
                    }

                    while (id_flag != -1 ){
                      id_nodo1 = (int*) queue_extract (q_print);

                      id_antecesor = node_getAntecesorId(g->nodes[find_node_index(g, *id_nodo1)]);
                      if (queue_insert(q_print, id_nodo1) == ERROR) {
                    	graph_DeepSearch_free (q, q_print, index_node, index_vecinos, id_nodo1);
                        return NULL;
                      }

                      id_flag = id_antecesor;

                      if (queue_insert(q_print, &id_antecesor) == ERROR) {
                        graph_DeepSearch_free (q, q_print, index_node, index_vecinos, id_nodo1);
                        return NULL;
                      }

                      node_print ( stdout, g->nodes[find_node_index(g, *id_nodo1)]);
                      fprintf(stdout,"\n");

                      int_destroy(id_nodo1);
                    }

                    queue_destroy (q_print);

                    queue_destroy(q);
                    int_destroy(index_vecinos);
                    int_destroy(index_node);

                    return g->nodes[fin_index];
                }

                else if (node_getLabel(g->nodes[index_vecinos[i]]) == BLANCO) {
                    node_setAntecesorId (g->nodes[index_vecinos[i]], node_getId(g->nodes[*index_node]));
                    if (queue_insert(q, index_vecinos+i) == ERROR) {
                        graph_DeepSearch_free (q, q_print, index_node, index_vecinos, id_nodo1);
                        return NULL;
                    }
                }
            }

            int_destroy(index_vecinos);
        }

        int_destroy(index_node);
    }


	  queue_destroy(q_print);
    queue_destroy(q);
    return NULL;
}

void graph_DeepSearch_free (Queue* q, Queue* q_print, int* index_node, int *index_vecinos, int *id_nodo1){
	queue_destroy(q);
    queue_destroy(q_print);
	int_destroy(index_vecinos);
    int_destroy(index_node);
    int_destroy(id_nodo1);
}
