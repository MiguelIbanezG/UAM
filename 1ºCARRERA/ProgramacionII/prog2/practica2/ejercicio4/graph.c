#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#include "graph.h"
#include "stack_fp.h"
#include "int.h"

#define MAX_NODES 1096
#define MAX_LINE 256

enum {NO_FILE_POS_VALUES = 2};

extern int errno;

struct _Graph {
    
    Node *nodes[MAX_NODES];
    int num_nodes;
    int num_edges;
    Bool connections[MAX_NODES][MAX_NODES];
    
};

int find_node_index (const Graph * g, int nId1);
int* graph_getConectionsIndex (const Graph * g, int index);

Graph * graph_ini() {
    
    
    Graph *grafo;
    int i, j;
    
    grafo = NULL;
    
    
    grafo = (Graph*)malloc(sizeof(Graph));
    if (!grafo) {
        fprintf (stderr, "%s\n", strerror(errno));
        return NULL;
    }
        
    
    for (i = 0; i < MAX_NODES; i++) {
        grafo->nodes[i] = NULL;
    }
    
    
    grafo->num_nodes = 0;
    grafo->num_edges = 0;
    
    
    return grafo;
}

void graph_destroy(Graph * g) {
    
    int i;

    for (i = 0; i < g->num_nodes; i++) {
        free (g->nodes[i]);
    }
    
    free (g);
}

int find_node_index(const Graph * g, int nId1) { //devuelve la id del nodo de un grafo
    int i;
    
    if (!g) return -1;
    
    for(i = 0; i < g->num_nodes; i++) {
        
        if (node_getId (g->nodes[i]) == nId1) return i;
        
    }
    
    // ID not find
    return -1;
}

int* graph_getConectionsIndex(const Graph * g, int index) {
    
    
    /*Se le pasa la localización en la tabla de nodos del grafo g de un nodo
     del cual queremos saber cuales son las posiciones en la tabla de los
     nodos conectados por él*/
    
    int *array = NULL, i, j=0, size;
    
    if (!g) return NULL;
    
    if (index < 0 || index > g->num_nodes) return NULL;
    
    // get memory for the array with the connected nodes index
    
    size = node_getConnect (g->nodes[index]);
    
    array = (int *) malloc(sizeof(int) * size);
    
    if (!array) {
        
        // print errorr message
        fprintf (stderr, "%s\n", strerror(errno));
        return NULL;
        
    }
    
    // asigno valores al array con los indices de los nodos conectados
    for(i = 0; i < g->num_nodes; i++) {
        
        if (g->connections[index][i] == TRUE) {
            
            array[j] = i;
            j++;
        }
    }
    
    return array;
}

Status graph_insertNode(Graph * g, const Node* n) {
    
    
    int i, id1;
    
    if (!g || !n) return ERROR;
    
    
    id1 = node_getId(n);
    
    for (i = 0; i < g->num_nodes; i++) {
        
        
        if (node_getId(g->nodes[i]) == id1) return ERROR;
    }
    
    
    g->nodes[i] = node_copy(n);
    
    for (i = 0; i <= g->num_nodes; i++) {
        g->connections[g->num_nodes][i] = FALSE;
    }
    
    g->num_nodes++;
    
    return OK;
}

Status graph_insertEdge(Graph * g, const int nId1, const int nId2) {
    
    int indice1, indice2, conexiones1;
    
    if (!g) return ERROR;
    
    /*aprovechamos la función find_node_index para sacar las posiciones
     de cada nodo*/
    indice1 = find_node_index(g, nId1);
    indice2 = find_node_index(g, nId2);
    
    if (indice1 == -1 || indice2 == -1) {
        return ERROR;
    }
    
    if (g->connections[indice1][indice2] == TRUE) return ERROR;
    
    /*Si no lo están, pues los conectamos*/
    
    g->connections[indice1][indice2] = TRUE;
    
    /*Extraemos su numero de conexiones*/
    conexiones1 = node_getConnect(g->nodes[indice1]);
    
    /*Y la aumentamos en 1*/
    g->nodes[indice1] = node_setConnect(g->nodes[indice1], conexiones1 + 1);
    
    g->num_edges++;
    
    return OK;
}

Node *graph_getNode (const Graph *g, int nId) {
    
    int indice1;
    Node *aux = NULL;
    
    if (!g) return NULL;
    
    indice1 = find_node_index(g, nId);
    if (indice1 == -1) return NULL;
    
    aux = node_copy(g->nodes[indice1]);
    return aux;
}

Status graph_setNode (Graph *g, const Node *n) {
    
    int indice;
    
    if (!g || !n) return ERROR;
    
    /*Si no hay nodo con esa id devolvemos error*/
    indice = find_node_index(g, node_getId(n));
    if (indice == -1) return ERROR;
    
    /*Si lo hay, su puntero asociado está en la posición indice de nodes, luego
     lo actualizamos desde ahí*/
    g->nodes[indice] = node_setId(g->nodes[indice], node_getId(n)); 
    g->nodes[indice] = node_setName(g->nodes[indice], node_getName(n));
    g->nodes[indice] = node_setConnect(g->nodes[indice], node_getConnect(n));
    
    return OK;
}

int * graph_getNodesId (const Graph * g) {
    /*Primero revisamos que exista el grafo*/
    
    int *array = NULL, i;  
    
    if (!g) return NULL;
    
    /*Ahora inicializamos array con una longitud igual al número de
     nodos del grafo*/
    array = (int*)malloc(g->num_nodes * sizeof(int));
    if (!array) return NULL;
    
    /*y le vamos metiendo las id*/
    
    for (i = 0; i < g->num_nodes; i++) {
        array[i] = node_getId(g->nodes[i]);
    }
    
    return array;
}

int graph_getNumberOfNodes(const Graph * g) {
    /*Revisamos que el grafo exista y devolvemos num_nodes*/
    if (!g) return -1;
    return g->num_nodes;
}

int graph_getNumberOfEdges(const Graph * g) {
    /*Devolvemos directamente g->num_edges*/
    
    if (!g) return -1;
    return g->num_edges;
}

Bool graph_areConnected(const Graph * g, const int nId1, const int nId2) {
    
    int indice1, indice2;
    
    if (!g) return FALSE;
    
    indice1 = find_node_index(g, nId1);
    indice2 = find_node_index(g, nId2);
    
    if (indice1 == -1 || indice2 == -1) {
        return FALSE;
    }
    
    if (g->connections[indice1][indice2] == TRUE) return TRUE;
    else return FALSE;
}

int graph_getNumberOfConnectionsFrom(const Graph * g, const int fromId) {
    
    int indice;
   
    if (!g) return -1;
    
    indice = find_node_index(g, fromId);
    
    if (indice == -1) return -1;
    
    return node_getConnect(g->nodes[indice]);
}

int* graph_getConnectionsFrom(const Graph * g, const int fromId) {
    
    int *conexiones = NULL, *Ids = NULL, i, indice, nConnect;
    
    if (!g) return NULL;
    
    indice = find_node_index(g, fromId);
    if (indice == -1) return NULL;
    
    
    conexiones = graph_getConectionsIndex(g, indice);
    if (!conexiones) return NULL;
    
    
    nConnect = node_getConnect(g->nodes[indice]);
    Ids = (int*)malloc(sizeof(int)*nConnect);
    if (!Ids) return NULL;
    
    
    for (i = 0; i < nConnect; i++) {
        Ids[i] = node_getId(g->nodes[conexiones[i]]);
    }
    
    free (conexiones);
    return Ids;
}

int graph_print(FILE *pf, const Graph * g) {
    
    int i, j, *array = NULL, contador, conexiones;
    
    contador = 0;
    
    
    if (!g || !pf) {
        fprintf (stderr, "%s\n", strerror(errno));
        return -1;
    }
    
    
    for (i = 0; i < g->num_nodes; i++) {
        
        conexiones = node_getConnect(g->nodes[i]);
        contador += fprintf (pf, "[%s, %d, %d] ", node_getName (g->nodes[i]), node_getId(g->nodes[i]), conexiones);
        
        
        if (conexiones != 0) {
            
            array = graph_getConectionsIndex (g, i);
            
            for (j = 0; j < conexiones; j++) {
                contador += fprintf (pf, "%d", node_getId(g->nodes[array[j]]));
            }
            
        }
        
        free (array);
        contador += fprintf (pf, "\n");
    }
    
    return contador;
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

Node *graph_findDeepSearch (Graph *g, int from_id, int to_id) {
    
    Stack *pila = NULL;
    int from_index, to_index, *indice_pivote = NULL, *indices_pivotados = NULL, num_pivotados, i;
    Bool es_directo = FALSE;
    
    if (!g) { //revisamos parámetros de entrada. Como las id son a elección del usuario, no las revisamos
    
        fprintf (stderr, "%s", strerror(errno));
        return NULL;
        
    }
    
    from_index = find_node_index(g, from_id); //índices de los nodos inicial y final extraídos
    to_index = find_node_index(g, to_id);
    
    if (from_index == -1 || to_index == -1) { //alguno de los dos nodos no está en el grafo
    
        fprintf (stderr, "%s", strerror(errno)); 
        return NULL;
    }
    
    
    
    //pila inicializada
    
    
    
    pila = stack_ini (int_destroy, int_copy, int_print);
    
    if (!pila) {
        fprintf (stderr, "%s", strerror(errno));
        return NULL;
    }
    
    if (stack_push (pila, &from_index) == ERROR) { //índice del nodo inicial introducido en la pila
        stack_destroy (pila);
        fprintf (stderr, "%s", strerror(errno));
        return NULL;
    }
    
    while (stack_isEmpty(pila) == FALSE) {
    
    
    
        //Memoria dinámica extraída -> VIGILAR
    
    
        
        indice_pivote = (int*)stack_pop (pila); //índice del pivote extraído. Como hemos vigilado que no está vacía, aquí no puede dar error
        
        if (node_getLabel (g->nodes[*indice_pivote]) == BLANCO) { //los argumentos existen, luego esta no da error
            
            node_setLabel(g->nodes[*indice_pivote], NEGRO); //el nodo existe al haber obtenido indice_pivote luego aquí no puede dar error
            
            
            
            //array de enteros inicializado -> VIGILAR
            
            
            
            indices_pivotados = graph_getConectionsIndex(g, *indice_pivote); //índices de los pivotados extraído
            
            num_pivotados = graph_getNumberOfConnectionsFrom(g, node_getId(g->nodes[*indice_pivote])); //número de pivotados extraído. Si hay pivotados, esto no dará error
            
            if (indices_pivotados == NULL) { //la única fomra de caer en esto es que el grafo sea un único nodo aislado, ya que siempre se conecta con el pivote si no
            
                stack_destroy (pila);
                fprintf (stderr, "%s", strerror(errno));
                return NULL;
                
            }
            
            for (i = 0; i < num_pivotados; i++) { //vamos mirando los pivotados
                
                if (indices_pivotados[i] == to_index) { //si alguno es el objetivo, lo devolvemos y liberamos todo
                    
                    node_print (stdout, g->nodes[to_index]);
                    fprintf (stdout, "\n");
                    node_print (stdout, g->nodes[*indice_pivote]);
                    fprintf (stdout, "\n");
                    
                    num_pivotados = node_getAntecesorId(g->nodes[*indice_pivote]);
                    
                    while (num_pivotados != -2 && num_pivotados != from_index) {
                        node_print (stdout, g->nodes[num_pivotados]);
                        fprintf (stdout, "\n");
                        num_pivotados = node_getAntecesorId(g->nodes[num_pivotados]);
                        es_directo = TRUE;
                    }
                    
                    if (es_directo == TRUE) {
                        
                        node_print (stdout, g->nodes[from_index]);
                        fprintf (stdout, "\n");
                    }
                    
                    stack_destroy (pila);
                    int_destroy (indices_pivotados);
                    int_destroy (indice_pivote);
                    
                    return g->nodes[to_index];
                    
                } else if (node_getLabel (g->nodes[indices_pivotados[i]]) == BLANCO) { //si no es el objetivo y está en blanco, a la pila (será un candidato a pivote)
                    
                    node_setAntecesorId (g->nodes[indices_pivotados[i]], *indice_pivote);
                    //fprintf (stdout, "%d", node_getAntecesorId(g->nodes[indices_pivotados[i]]));
                    //printf ("\n");
                    
                    if (stack_push (pila, indices_pivotados+i) == ERROR) {
                    
                        stack_destroy (pila);
                        int_destroy (indices_pivotados);
                        int_destroy (indice_pivote);
                        fprintf (stderr, "%s", strerror(errno));
                        return NULL;
                        
                    }
                }
            }
            
            int_destroy (indices_pivotados);
        }
        
        int_destroy (indice_pivote);
    }
    
    stack_destroy (pila);
    return NULL;
}

















