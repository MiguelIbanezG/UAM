/*
*Título: Funciones vértices, práctica 1, programación 2
*Grupo: viernes 2113
*Autores: Sergio Hidalgo y Miguel Ibáñez 
*/
#include <stdio.h>
#include <stdlib.h>
#include "stack_fDoble.h"
#include "file_utils.h"
#include "vertex.h"
#include "graph.h"

Status *DFS(Graph *g, Vertex *vf, Vertex *vt);




Status *DFS(Graph *g, Vertex *vf, Vertex *vt)
{
    Status st;
    Stack *s;

    graph_set_allVertex_state (g, WHITE);

    st = OK;

    s = stack_init();

    while ((stack_isEmpty(s) == FALSE) && (st == OK))
    {
        /* code */
    }
    
}