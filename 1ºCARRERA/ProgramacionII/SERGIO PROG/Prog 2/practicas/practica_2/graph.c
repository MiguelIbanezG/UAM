/*
*Título: Funciones vértices, práctica 1, programación 2
*Grupo: viernes 2113
*Autores: Sergio Hidalgo y Miguel Ibáñez 
*/
#include "graph.h"
#include "queue.h"
#include "stack_fDoble.h"
#include <string.h>
#define MAX_VTX 4096

struct _Graph
{
    Vertex *vertices[MAX_VTX];          /*!<Array with the graph vertices */
    Bool connections[MAX_VTX][MAX_VTX]; /*!<Adjacency matrix */
    int num_vertices;                   /*!<Total number of vertices */
    int num_edges;                      /*!<Total number of edges */
};

/*Función privada que obtiene la posición del vértice a partir del id*/
int graph_getVertexpositionFromId(const Graph *g, long id);
int graph_getNumConnections_fromIndex(const Graph *g, int ix);
long *graph_getConnectionsIndex(const Graph *g, int ix);
long graph_getIdfromIndex(const Graph *g, int ix);
Vertex *graph_getVertex (Graph * g, int i);


Graph *graph_init()
{

    Graph *g = NULL; /*Se inicializa un puntero a g como tipo Graph*/
    int i = 0, j = 0;

    g = (Graph *)malloc(sizeof(Graph));
    if (!g) /*Se hace la reserva de memoria*/
    {
        return NULL; /*Si falla dará error*/
    }

    /*Las distintas características del graph 
    estarán todas a 0 (valor inical)*/
    g->num_vertices = 0;
    g->num_edges = 0;

    for (i = 0; i < MAX_VTX; i++)
    {
        g->vertices[i] = NULL;

        for (j = 0; j < MAX_VTX; j++)
        {
            g->connections[i][j] = FALSE;
        }
    }

    return g; /*Se devuelve g*/
}

void graph_free(Graph *g)
{

    int i = 0;

    if (g == NULL)
    {
        return;
    }
    else
    {

        for (i = 0; i < MAX_VTX; i++)
        {
            vertex_free(g->vertices[i]);
        }

        free(g); /*Se libera la memoria*/
        g = NULL;
    }
}

Status graph_newVertex(Graph *g, char *desc)
{

    Vertex *v;
    int i;
    long id;

    if (g == NULL || desc == NULL || graph_getNumberOfVertices(g) == MAX_VTX)
    {
        return ERROR;
    }

    v = vertex_initFromString(desc);

    id = vertex_getId(v);

   
    for (i = 0; i < g->num_vertices; i++)
    {
        if (vertex_getId(g->vertices[i]) == id)
        {
            free(v);
            return OK;
        }
    }
    

    
    
    vertex_setIndex(v,g->num_vertices);
    g->vertices[g->num_vertices] = v;
    g->num_vertices++;
    
    return OK;
}

Status graph_newEdge(Graph *g, long orig, long dest)
{

    if ((graph_contains(g, orig) == FALSE) || (graph_contains(g, dest) == FALSE))
    {

        return ERROR;
    }

    g->connections[graph_getVertexpositionFromId(g, orig)][graph_getVertexpositionFromId(g, dest)] = 1;
    (g->num_edges)++;

    if (((g->connections)[graph_getVertexpositionFromId(g, orig)][graph_getVertexpositionFromId(g, dest)]) == 0)
    {

        return ERROR;
    }

    return ERROR;
}

Bool graph_contains(const Graph *g, long id)
{

    int i;

    if ((!g) || (id < 0) || (g->num_vertices == 0))
    {

        return FALSE;
    }

    for (i = 0; i < g->num_vertices; i++)
    {

        if (vertex_getId((Vertex *)g->vertices[i]) == id)
        {

            return TRUE;
        }
    }

    return FALSE;
}

int graph_getNumberOfVertices(const Graph *g)
{

    if (!g)
    {
        return -1;
    }

    return g->num_vertices;
}

int graph_getNumberOfEdges(const Graph *g)
{

    if (g == NULL)
    {
        return -1;
    }

    return g->num_edges;
}

Bool graph_connectionExists(const Graph *g, long orig, long dest)
{

    if ((graph_contains(g, orig) == FALSE) || (graph_contains(g, dest) == FALSE) || !g || (orig < 0) || (dest < 0))
    {

        return FALSE;
    }

    if (g->connections[graph_getVertexpositionFromId(g, orig)][graph_getVertexpositionFromId(g, dest)] == 1)
    {
        return TRUE;
    }
    else

        return FALSE;
}

int graph_getNumberOfConnectionsFromId(const Graph *g, long id)
{

    int i, count = 0;

    if ((g == NULL) || (id < 0) || (graph_contains(g, id) == FALSE))
    {
        return -1;
    }

    if (graph_contains(g, id) == FALSE)
    {

        return FALSE;
    }

    for (i = 0; i < MAX_VTX; i++)
    {

        if (graph_connectionExists(g, id, vertex_getId((Vertex *)g->vertices[i])) == TRUE)
        {

            count++;
        }
    }

    if ((count >= 0) || (count <= MAX_VTX))
    {
        return count;
    }

    return -1;
}

long *graph_getConnectionsFromId(const Graph *g, long id)
{

    long *array_vertex_connected;
    int i = 0, j = 0;
    int num_vertex_connected;

    if ((g == NULL) || (vertex_getId((Vertex *)g->vertices) == -1) || (id < 0))
    {
        return NULL;
    }

    num_vertex_connected = graph_getNumberOfConnectionsFromId(g, id);

    array_vertex_connected = (long *)malloc(num_vertex_connected*sizeof(long));

    if (array_vertex_connected == NULL)
    {

        return NULL;
    }

    for (i = 0; i < g->num_vertices; i++)
    {
        if ((graph_connectionExists(g, id, vertex_getId((Vertex *)g->vertices[i]))) == TRUE)
        {
            array_vertex_connected[j] = vertex_getId((Vertex *)g->vertices[i]);
            j++;
        }
    }
    if (j != num_vertex_connected)
    {
        return NULL;
    }

    return array_vertex_connected;
}

int graph_getNumberOfConnectionsFromTag(const Graph *g, char *tag)
{

    int i = 0;
    long id;

    if (g == NULL || vertex_getTag((Vertex *)g->vertices) == NULL)
    {
        return -1;
    }

    for (i = 0; i < g->num_vertices; i++)
    {
        if (strcmp(tag, vertex_getTag((Vertex *)g->vertices[i])) == 0)
        {

            id = vertex_getId((Vertex *)g->vertices[i]);

            i = graph_getNumberOfConnectionsFromId(g, id);

            return i;
        }
    }

    return -1;
}

long *graph_getConnectionsFromTag(const Graph *g, char *tag)
{

    int i = 0;
    long id;

    if (g == NULL || vertex_getTag((Vertex *)g->vertices) == NULL)
    {
        return NULL;
    }

    for (i = 0; i < g->num_vertices; i++)
    {
        if (strcmp(tag, vertex_getTag((Vertex *)g->vertices[i])) == 0)
        {

            id = vertex_getId((Vertex *)g->vertices[i]);

            return graph_getConnectionsFromId(g, id);
        }
    }

    return NULL;
}

int graph_print(FILE *pf, const Graph *g)
{

    int i, j, charact_print = 0;

    if (g == NULL)
    {
        return -1;
    }

    for (i = 0; i < g->num_vertices; i++)
    {
        if (graph_contains(g, vertex_getId(g->vertices[i])) == TRUE)
        {
            printf("\n");
            charact_print = charact_print + vertex_print(stdout, g->vertices[i]);
            printf(": ");

            if (graph_getNumberOfConnectionsFromId(g, vertex_getId(g->vertices[i])) > 0) /*Si tiene al menos una conexión, el bucle se inicia*/
            {

                for (j = 0; j < g->num_vertices; j++) /*Se repetirá tantas veces como vértices tenga*/
                {

                    if (graph_connectionExists(g, vertex_getId(g->vertices[i]), vertex_getId(g->vertices[j])) == TRUE) /*si existe una conexión entre ambos se imprime el segundo*/
                    {
                        charact_print = charact_print + vertex_print(stdout, g->vertices[j]);
                    }
                }
            }
        }
    }

    printf("\n");
    return charact_print;
}

int graph_getVertexpositionFromId(const Graph *g, long id)
{

    int i = 0;

    if (!g)
    {
        return -1;
    }

    for (i = 0; i < g->num_vertices; i++)
    {
        if (vertex_getId((Vertex *)g->vertices[i]) == id)
        {
            return i;
        }
    }
    return -1;
}

Status graph_readFromFile(FILE *fin, Graph *g)
{

    int i, num=0;      /*Se inicializan las variables del número de vértices y de la cadena de cáracteres en la que se*/
    char string[50]; /*imprimirá la información del vértice*/
    long origi, dest;

    if ((!fin) || (!g)) /*Control de errores*/
    {
        return ERROR;
    }

    fgets(string, 50, fin); /*Obtención del número de vértices*/
    sscanf(string, "%d", &num);

    for (i = 0; i < num; i++)
    {
        fgets(string, 50, fin); /*Obtención de la descripción del vértice*/
        graph_newVertex(g, string);
    }

    while (fscanf(fin,"%ld %ld",&origi,&dest)==2)
    {
        fgets(string, 50, fin); /*Obtención de la id de origen y destino de los edges del vértice*/
        sscanf(string, "%ld %ld", &origi, &dest);
        graph_newEdge(g, origi, dest);
    }

    return OK;
}

Vertex *graph_getVertex(Graph *g, int i)
{

    return g->vertices[i];
}

int graph_getNumConnections_fromIndex(const Graph *g, int ix)
{
    if (!g)
    {
        return ERROR;
    }

    return sizeof(graph_getNumberOfConnectionsFromId(g, vertex_getId(g->vertices[ix])));
}

long *graph_getConnectionsIndex(const Graph *g, int ix)
{
    if (!g)
    {
        return ERROR;
    }

    return graph_getConnectionsFromId(g, vertex_getId(g->vertices[ix]));
}

Status graph_set_Vertex_state(Graph *g, const Label state, int position)
{

    if (!g)
    {
        return ERROR;
    }

    vertex_setState(g->vertices[position], WHITE);

    return OK;
}

long graph_getIdfromIndex(const Graph *g, int ix)
{
    if (!g)
    {
        return -1;
    }

    return vertex_getId(g->vertices[ix]);
}

Status graph_depthSearch(Graph *g, long from_id, long to_id)
{
    Status st = OK;
    Queue *s = NULL;
    int i = 0, end = 0;
    long *connections = NULL;
    long id0 = 0;

    if (!g || (from_id < 0) || (to_id < 0) || (graph_getVertexpositionFromId(g, from_id) == -1) || (graph_getVertexpositionFromId(g, to_id) == -1))
    {
        return ERROR;
    }

    for (i = 0; i < g->num_vertices; i++)
    {
        graph_set_Vertex_state(g, WHITE, i);
    }

    st = OK;

    s = queue_new();

    vertex_setState(g->vertices[graph_getVertexpositionFromId(g, from_id)], BLACK);

    queue_push(s, g->vertices[graph_getVertexpositionFromId(g, from_id)]);
    
    vertex_print(stdout,queue_getFront(s));
    printf ("\n");

    while ((queue_isEmpty(s) == FALSE) && (st == OK) && (end == 0))
    {

        id0 = vertex_getId(queue_pop(s));

        if (id0 == to_id)
        {
            end = 1;
            break;
        }

        connections = graph_getConnectionsFromId(g, id0);

        

        for (i = 0; i < graph_getNumberOfConnectionsFromId(g, id0); i++)
        {
            
            if (vertex_getState(g->vertices[ graph_getVertexpositionFromId(g, connections[i]) ]) == WHITE)
            {
                vertex_setState(g->vertices[ graph_getVertexpositionFromId(g, connections[i]) ], BLACK);

                queue_push(s, g->vertices[ graph_getVertexpositionFromId(g, connections[i]) ]);
            }
        }
        vertex_print(stdout,queue_getFront(s));
        printf ("\n");
        free (connections);
    }

    
    queue_free(s);
    return st;
}
