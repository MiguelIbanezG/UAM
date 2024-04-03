/**
 * @file graph.h
 * @authors Sergio Fraile Sánchez and Florentino García Aznar
 * @date Created on March 03, 2021
 * @version 1.0
 * @brief Library to manage the Graph ADT
 *
 * @see
 */

#ifndef GRAPH_H
#define GRAPH_H

#include "vertex.h"

typedef struct _Graph Graph;

Graph * graph_init();

void graph_free(Graph *g);

Status graph_newVertex(Graph *g, char *desc);

Status graph_newEdge(Graph *g, long orig, long dest);

Bool graph_contains(const Graph *g, long id);

int graph_getNumberOfVertices(const Graph *g);

int graph_getNumberOfEdges(const Graph *g);

Bool graph_connectionExists(const Graph *g, long orig, long dest);

int graph_getNumberOfConnectionsFromId(const Graph *g, long id);

long *graph_getConnectionsFromId(const Graph *g, long id);

int graph_getNumberOfConnectionsFromTag(const Graph *g, char *tag);

long *graph_getConnectionsFromTag(const Graph *g, char *tag);

int graph_print (FILE *pf, const Graph *g);

Status graph_readFromFile (FILE *fin, Graph *g);

Vertex **graph_Vertex(Graph *g);

Status graph_depthSearch(Graph *g, long from_id, long to_id);

#endif /* GRAPH_H */
