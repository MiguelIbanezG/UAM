/*
*Título: Funciones vértices, práctica 1, programación 2
*Grupo: viernes 2113
*Autores: Sergio Hidalgo y Miguel Ibáñez 
*/
#include "graph.h"
#include <string.h>
#define MAX_VTX 4096

struct _Graph
{
    Vertex *vertices[MAX_VTX];          /*!<Array with the graph
vertices */
    Bool connections[MAX_VTX][MAX_VTX]; /*!<Adjacency matrix */
    int num_vertices;                   /*!<Total number of vertices */
    int num_edges;                      /*!<Total number of edges */
};

/*Función privada que obtiene la posición del vértice a partir del id*/
int graph_getVertexpositionFromId(const Graph *g, long id);

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
        return ERROR;
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
    int i = 0;
    v = vertex_initFromString(desc); /*Se inicializa el vertice*/

    if ((g == NULL) || (v == NULL) || (g->num_vertices == MAX_VTX))
    {

        return ERROR;
    }

    do /*Bucle que comprobará si son iguales los id de el vértice introducido y los de los vértices del graph*/
    {
        if (vertex_getId(v) == vertex_getId((Vertex *)g->vertices[i]))
        {

            return OK;
        }
        else if ((vertex_getId(v) != vertex_getId((Vertex *)g->vertices[i])) && g->num_vertices == i) /*Si no son iguales, en la última interacción del bucle, se piden las 3 características del vértice y se ponen en el graph*/
        {
            g->vertices[g->num_vertices] = vertex_init();

            if (vertex_setId(g->vertices[g->num_vertices], vertex_getId(v)) == ERROR || vertex_setTag(g->vertices[g->num_vertices], vertex_getTag(v)) == ERROR || vertex_setState(g->vertices[g->num_vertices], vertex_getState(v)) == ERROR)
            {
                return ERROR;
            }
            else
            {
                (g->num_vertices)++;
                return OK;
            }
        }
        else if ((vertex_getId(v) != vertex_getId((Vertex *)g->vertices[i])))
        {

            i++;
        }
        else

            return ERROR;

    } while (i <= g->num_vertices);

    return ERROR;
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

    return OK;
}

Bool graph_contains(const Graph *g, long id)
{

    int i;

    if ((!g) || (!id) || (id < 0))
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

    int count = 0;
    int i = 0;

    do
    {
        if (graph_contains(g, vertex_getId((Vertex *)g->vertices[i])) == TRUE)
        {
            count++;
            i++;
        }
        else

            i++;

    } while (i < MAX_VTX);

    if ((count >= 0) || (count <= MAX_VTX))
    {
        return count;
    }

    return -1;
}

int graph_getNumberOfEdges(const Graph *g)
{

    int i = 0, j = 0, count = 0;

    if (g == NULL)
    {
        return -1;
    }

    for (i = 0; i < g->num_vertices; i++)
    {

        for (j = 0; j < g->num_vertices; j++)
        {
            if (graph_connectionExists(g, vertex_getId((Vertex *)g->vertices[i]), vertex_getId((Vertex *)g->vertices[j])) == TRUE)
            {

                count++;
            }
        }
    }

    if ((count >= 0) || (count <= 16777216))
    {

        return count;
    }

    return -1;
}

Bool graph_connectionExists(const Graph *g, long orig, long dest)
{

    if ((graph_contains(g, orig) == FALSE) || (graph_contains(g, dest) == FALSE))
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

    if ((g == NULL) || (vertex_getId((Vertex *)g->vertices) == -1) || (id < 0))
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

    array_vertex_connected = (long *)malloc(sizeof(num_vertex_connected));

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

    int i, num;      /*Se inicializan las variables del número de vértices y de la cadena de cáracteres en la que se*/
    char string[50]; /*imprimirá la información del vértice*/
    long origi, dest;

    if ((fin == NULL) || (g == NULL)) /*Control de errores*/
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

    for (i = 0; i < num; i++)
    {
        fgets(string, 50, fin); /*Obtención de la id de origen y destino de los edges del vértice*/
        sscanf(string, "%ld %ld", &origi, &dest);
        graph_newEdge(g, origi, dest);
    }

    return OK;
}