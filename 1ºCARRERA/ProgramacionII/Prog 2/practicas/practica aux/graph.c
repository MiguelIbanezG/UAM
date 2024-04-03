#include "graph.h"
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
long graph_getVertexIDfromVertexTag(const Graph *g, char *tag);
int find_vertex_position(const Graph *g, long id);
int _graph_findVertexById(Graph *, long id);
/* Functions */

/**
 * @brief Creates a new empty graph.
 *
 * Allocates memory for a new graph and initializes it to be empty 
 * (no vertices and no edges).
 *
 * @return A pointer to the graph if it was correctly allocated, 
 * NULL otherwise.
 **/
Graph *graph_init()
{

    Graph *g;
    int i, j;

    if (!(g = (Graph *)malloc(sizeof(Graph))))
    {
        return NULL;
    }
    for (i = 0; i < MAX_VTX; i++)
    {
        g->vertices[i] = NULL;
        for (j = 0; j < MAX_VTX; j++)
        {
            g->connections[i][j] = FALSE;
        }
    }
    g->num_vertices = 0;
    g->num_edges = 0;
    return g;
}

/**
 * @brief Frees a graph.
 *
 * Frees all the memory allocated for the graph.
 *
 * @param g Pointer to graph to be freed.
 **/
void graph_free(Graph *g)
{

    int i;
    if (!g)
    {
        return;
    }

    for (i = 0; i < g->num_vertices; i++)
    {
        free(g->vertices[i]);
        g->vertices[i] = NULL;
    }
    free(g);
}

/**
 * @brief Inserts a new vertex in a graph.
 *
 * Creates a vertex by calling vertex_initFromString and adds it to
 * a graph. If a vertex with the same id already exists in the graph, 
 * it is not added. 
 *
 * @param g Pointer to the graph.
 * @param desc Description of the vertex.
 *
 * @return Returns OK if the vertex could be created (or if it exists 
 * already), ERROR otherwise.
 **/
Status graph_newVertex(Graph *g, char *desc)
{

    Vertex *v;
    int i;
    long id;

    if (!g || !desc)
    {
        return ERROR;
    }

    if (graph_getNumberOfVertices(g) == MAX_VTX)
    {
        return ERROR;
    }

    if (!(v = vertex_initFromString(desc)))
    {
        return ERROR;
    }

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
/**
 * @brief Creates an edge between to vertices of a graph.
 *
 * If any of the two vertices does not exist in the graph the edge is
 * not created.
 *
 * @param g Pointer to the graph.
 * @param orig ID of the origin vertex.
 * @param dest ID of the destination vertex.
 *
 * @return OK if the edge could be added to the graph, ERROR otherwise.
 **/
Status graph_newEdge(Graph *g, long orig, long dest)
{

    int a, b;

    if (!g || orig < 0 || dest < 0)
    {
        return ERROR;
    }

    if ((a = find_vertex_position(g, orig)) >= 0 && (b = find_vertex_position(g, dest)) >= 0)
    {
        if (g->connections[a][b] == TRUE)
        {
            return ERROR;
        }
        else
        {
            g->connections[a][b] = TRUE;
            g->num_edges++;
            return OK;
        }
    }
    return ERROR;
}

/**
 * @brief Checks if a graph contains a vertex.
 *
 * @param g Pointer to the graph.
 * @param id ID of the vertex.
 *
 * @return Returns TRUE if there is a vertex in the graph g with the
 * ID id, FALSE otherwise.
 **/
Bool graph_contains(const Graph *g, long id)
{

    int i = 0;
    if (!g || id < 0 || g->num_vertices == 0)
    {
        return FALSE;
    }

    for (i = 0; i < g->num_vertices; i++)
    {
        if (vertex_getId(g->vertices[i]) == id)
        {
            return TRUE;
        }
    }
    return FALSE;
}

/**
 * @brief Returns the total number of vertices in a graph.
 *
 * @param g Pointer to the graph.
 *
 * @return Returns The number of vertices in the graph, or -1 if 
 * there is any error.
 **/
int graph_getNumberOfVertices(const Graph *g)
{

    if (!g)
    {
        return -1;
    }
    return g->num_vertices;
}
/**
 * @brief Returns the total number of edges  * in the graph.
 *
 * @param g Pointer to the graph.
 *
 * @return Returns The number of vertices in the graph, or -1 if 
 * there is any error.
 **/
int graph_getNumberOfEdges(const Graph *g)
{

    if (!g)
    {
        return -1;
    }
    return g->num_edges;
}

/**
 * @brief Determines if there is a connection between a pair of vertices.
 *
 * @param g Pointer to the graph.
 * @param orig ID of the origin vertex.
 * @param dest ID of the destination vertex.
 *
 * @return Returns TRUE if there is a connection in g from orig
 *  to dest, FALSE otherwise.
 **/
Bool graph_connectionExists(const Graph *g, long orig, long dest)
{

    int a, b;

    if (!g || orig < 0 || dest < 0)
    {
        return FALSE;
    }
    if ((a = find_vertex_position(g, orig)) == -1 || (b = find_vertex_position(g, dest)) == -1)
    {
        return FALSE;
    }

    return g->connections[a][b];
}

/**
 * @brief Gets the number of connections starting at a given vertex.
 *
 * @param g Pointer to the graph.
 * @param id ID of the origin vertex.
 *
 * @return Returns the total number of connections starting at 
 * vertex with ID id, or -1 if there is any error.
 **/
int graph_getNumberOfConnectionsFromId(const Graph *g, long id)
{

    int i, num = 0;
    if (!g || id < 0 || !graph_contains(g, id))
    {
        return -1;
    }

    for (i = 0; i < g->num_vertices; i++)
    {

        if (graph_connectionExists(g, id, vertex_getId(g->vertices[i])) == TRUE)
        {
            num++;
        }
    }
    return num;
}
/**
 * @brief Returns an array with the ids of all the vertices which a 
 * given vertex connects to.
 *
 * This function allocates memory for the array.
 *
 * @param g Pointer to the graph.
 * @param id ID of the origin vertex.
 *
 * @return Returns an array with the ids of all the vertices to which 
 * the vertex with ID id is connected, or NULL if there is any error.
 */
/*long *graph_getConnectionsFromId(const Graph *g, long id)
{

    long *conns = NULL;
    int a, n, k = 0;
    long dest_id;

    if (!g || id <= 0 || graph_contains(g, id) == FALSE)
    {
        return NULL;
    }
    if ((n = graph_getNumberOfConnectionsFromId(g, id)) == -1)
    {
        return NULL;
    }
    conns = (long *)malloc(n * sizeof(long));
    if (conns == NULL)
    {
        return NULL;
    }
    for (a = 0; a < n; a++)
    {
        if ((dest_id = vertex_getId(g->vertices[a])) == -1)
        {
            return NULL;
        }
        if (graph_connectionExists(g, id, dest_id) == TRUE)
        {
            conns[k] = dest_id;
            k++;
        }
    }
    printf("INDICE MAXIMO: %d\n",k);
    return conns;
}*/
long *graph_getConnectionsFromId(const Graph *g, long id)
{
    long *conns=NULL;
    int i,n,k=0;
    long dest_id;

    if(!g||graph_contains(g,id)==FALSE)
    {
        return NULL;
    }
    if((n=graph_getNumberOfConnectionsFromId(g,id))==-1)
    {
        return NULL;
    }
    conns=(long *)malloc(n*sizeof(long));
    if(conns==NULL)
    {
        return NULL;
    }
    for(i=0;i<g->num_vertices;i++)
    {
        if((dest_id=vertex_getId(g->vertices[i]))==-1)
        {
            return NULL;
        }
        if(graph_connectionExists(g,id,dest_id)==TRUE)
        {
            conns[k]=dest_id;
            k++;
        }
    }
    return conns;
}
/**
 * @brief Gets the number of connections starting at a given vertex.
 *
 * @param g Pointer to the graph.
 * @param tag Tag of the origin vertex.
 *
 * @return Returns the total number of connections starting at 
 * vertex with Tag tag, or -1 if there is any error.
 **/
int graph_getNumberOfConnectionsFromTag(const Graph *g, char *tag)
{

    int a;

    if (!g || !tag || (a = graph_getVertexIDfromVertexTag(g, tag)) == -1)
    {
        return -1;
    }
    return graph_getNumberOfConnectionsFromId(g, a);
}
/**
 * @brief Returns an array with the ids of all the vertices which a 
 * given vertex connects to.
 *
 * This function allocates memory for the array.
 *
 * @param g Pointer to the graph.
 * @param tag Tag of the origin vertex.
 *
 * @return Returns an array with the ids of all the vertices to which 
 * the vertex with Tag tag is connected, or NULL if there is any error.
 */
long *graph_getConnectionsFromTag(const Graph *g, char *tag)
{

    long *conns = NULL;
    int a, n;
    long dest_id, id;

    id = graph_getVertexIDfromVertexTag(g, tag);

    if (!g || id <= 0 || graph_contains(g, id) == FALSE)
    {
        return NULL;
    }
    if ((n = graph_getNumberOfConnectionsFromId(g, id)) == -1)
    {
        return NULL;
    }
    conns = (long *)malloc(n * sizeof(long));
    if (conns == NULL)
    {
        return NULL;
    }
    for (a = 0; a < n; a++)
    {
        if ((dest_id = vertex_getId(g->vertices[a])) == -1)
        {
            return NULL;
        }
        if (graph_connectionExists(g, id, dest_id) == TRUE)
        {
            conns[a] = dest_id;
        }
    }
    return conns;
}
/**
 * @brief Prints a graph.
 *
 * Prints the graph g to the file pf.
 * The format to be followed is: print a line by vertex with the 
 * information associated with the vertex and the id of their connections:
 *
 * For example:
 * [1, Madrid, 0]: [2, Toledo, 0] [3, Avila, 0] 
 * [2, Toledo, 0]: [4, Segovia, 0] 
 * [3, Avila, 0]: 
 * [4, Segovia, 0]: [3, Avila, 0]
 *
 * @param pf File descriptor.
 * @param g Pointer to the graph.
 *
 * @return The number of characters printed, or -1 if there is any error.
 */
int graph_print(FILE *pf, const Graph *g)
{
    int i, j, x = 0;
    long org_id = 0, dest_id = 0;
    if (!g || !pf)
        return -1;
    for (i = 0; i < g->num_vertices; i++)
    {
        if (g->vertices[i] == NULL)
            return -1;
        x = x + vertex_print(pf, g->vertices[i]);
        fprintf(stdout, ": ");
        x = x + 2;

        if ((org_id = vertex_getId(g->vertices[i])) == -1)
            return -1;

        for (j = 0; j < g->num_vertices; j++)
        {
            if (g->vertices[j] == NULL)
                return -1;
            if ((dest_id = vertex_getId(g->vertices[j])) == -1)
                return -1;
            if (graph_connectionExists(g, org_id, dest_id) == TRUE)
            {
                x = x + vertex_print(pf, g->vertices[j]);
            }
        }
        fprintf(stdout, "\n");
    }
    return x;
}
/**
 * @brief Reads a graph definition from a text file.
 *
 * Reads a graph description from the text file pointed to by fin,
 * and fills the graph g.
 *
 * The first line in the file contains the number of vertices.
 * Then one line per vertex with the vertex description.  
 * Finally one line per connection, with the ids of the origin and 
 * the destination. 
 *
 * For example:
 *
 * 4
 * id:1 tag:Madrid
 * id:2 tag:Toledo
 * id:3 tag:Avila
 * id:4 tag:Segovia
 * 1 2
 * 1 3
 * 2 4
 * 4 3
 *
 * @param fin Pointer to the input stream.
 * @param g Pointer to the graph.
 *
 * @return OK or ERROR
 */

Status graph_readFromFile(FILE *fin, Graph *g)
{
    char str[60];
    int n = 0, i;
    long orig, dest;

    if (!fin || !g)
        return ERROR;

    fgets(str, 60, fin);
    sscanf(str, "%d", &n);

    for (i = 0; i < n; i++)
    {
        fgets(str, 60, fin);
        graph_newVertex(g, str);
    }

    while (fscanf(fin,"%ld %ld",&orig,&dest)==2)
    {
        fgets(str, 60, fin);
        sscanf(str, "%ld %ld", &orig, &dest);
        graph_newEdge(g, orig, dest);
    }

    return OK;
}

/**
 * @brief gives the vertex of a graph.
 *
 * @param g Pointer to the graph.
 *
 * @return Returns the vertex of the graph.
 */
Vertex **graph_Vertex(Graph *g)
{
    return g->vertices;
}

/**
* @brief: Makes a search from the origin vertex to the destination
* vertex of a graph using the depth-first search algorithm
* using an ADT Stack
*
* The function prints each visited vertex while traversing the graph
*
* @param g, Pointer to graph
* @param from_id, id of the origin Vertex
* @param to_id, id of the destination Vertex
* @return The function returns OK or ERROR
**/
Status graph_depthSearch(Graph *g, long from_id, long to_id)
{
    long *idconns;
    int i, j = 0, notEnd = 1;
    Vertex **v;
    Stack *s;

    if (!g || from_id < 0 || to_id < 0)
    {
        return ERROR;
    }

    s = stack_init();
    if (!s)
    {
        return ERROR;
    }
    
    v = graph_Vertex(g);

    for (i = 0; i < graph_getNumberOfVertices(g); i++)
    {
        vertex_setState(v[i], WHITE);
    }

    /* SETS INITIAL ID TO BLACK AND PUSH IT TO THE STACK */
    vertex_setState(v[_graph_findVertexById(g, from_id)], BLACK);
    stack_push(s, g->vertices[_graph_findVertexById(g, from_id)]);

    while (notEnd)
    {
        /* CHECK IF THE ROUTE FROM INITIAL ID TO DEST ID HAS ALREADY FINISHED BEEN TRACED*/
        if (vertex_getId(stack_top(s)) == to_id)
        {
            notEnd = 0;
            break;
        }
        /* IF A NON FROMID-CONNECTIONS VERTEX REACHED, IT GETS A STEP BACK AND 
           INCREMENT J FOR SEARCHING THROUGH ANOTHER VERTEX IN PREVIOUS ARRAY*/
        if (graph_getNumberOfConnectionsFromId(g, vertex_getId(stack_top(s))) == 0 )
        {  
            vertex_setState(stack_top(s), WHITE);
            stack_pop(s);
            j++;
        }
        /* IF A FROMID-CONNECTIONS VERTEX REACHED, RESET J TO 0 TO START SEARCHING IN ITS CONNECTIONS ARRAY */
        else
        {
            j = 0;
        }
        /* IF J GETS OUT OF INDEX THERES NO CONNECTION ROUTE BETWEEN FROM_ID AND TO_ID.
        IT SHOULD EMPTY THE STACK, SET LABELS TO WHITE AND FREE IT*/
        if (j-1 == graph_getNumberOfConnectionsFromId(g, vertex_getId(stack_top(s))))
        {
            while (!stack_isEmpty(s))
            {
                vertex_setState(stack_top(s), WHITE);
                stack_pop(s);
            }
            stack_free(s);
            return ERROR;
        }
        /* ELSE IT WILL CONTINUE TRACING THE ROUTE*/
        else
        {
            idconns = graph_getConnectionsFromId(g, vertex_getId(stack_top(s)));
            stack_push(s, g->vertices[find_vertex_position(g, idconns[j])]);
            vertex_setState(stack_top(s), BLACK);
        }
    };
    return OK;
}

//Private Functions

/**
 * @brief Locate vertex in the vertex array.
 *
 * @param g Pointer to the graph.
 * @param id Id of the vertex to find.
 *
 * @return Returns the vertex position in the array, or -1 if there is any error.
 */
int find_vertex_position(const Graph *g, long id)
{

    int i = 0;

    if (!g || id < 0)
        return -1;

    for (i = 0; i < g->num_vertices; i++)
    {
        if (vertex_getId(g->vertices[i]) == id)
            return i;
    }

    return -1;
}

/**
 * @brief Returns the Id of the vertex with the Tag given.
 *
 * @param g Pointer to the graph.
 * @param tag Tag of the origin vertex.
 *
 * @return Returns the Id of the vertex with the Tag given, or -1 if there is any error.
 */
long graph_getVertexIDfromVertexTag(const Graph *g, char *tag)
{

    if (!g || !tag)
        return -1;
    long id;
    int i;

    for (i = 0; i < g->num_vertices; i++)
    {
        if (strcmp(vertex_getTag(g->vertices[i]), tag) == 0)
        {
            id = vertex_getId(g->vertices[i]);
            return id;
        }
    }
    printf("\n");

    return -1;
}

/**
 * @brief Returns the index of the vertex with the id given.
 *
 * @param g Pointer to the graph.
 * @param id Id of the vertex.
 *
 * @return Returns the index of the vertex with the id given, or -1 if there is any error.
 */
int _graph_findVertexById(Graph *g, long id)
{
    Vertex *v;
    Vertex **aux;
    if (!g || !id || graph_getNumberOfVertices(g) == -1)
        return -1;
    aux = graph_Vertex(g);
    for (int i = 0; i < graph_getNumberOfVertices(g); i++)
    {
        if (vertex_getId(aux[i]) == id)
        {
            v = aux[i];
            return vertex_getIndex(v);
        }
    }
    return -1;
}
