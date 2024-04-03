/******************************************************************************

Nombre del modulo: node_p4.c

Descripcion: Implementacion de las funciones de node_p4.h. Sirve para trabajar con nodos,
			 esta adaptado para trabajar con punteros a funciones y solo tiene el id y
       el nombre en la estructura de datos.

Autor: Jorge Fernandez Garcia y Pedro Sanchez de la Muela

Fecha: 23 - 4 - 2019

******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include "node.h"

struct _Node {
  char* name;
  int id;
};

Node* node_ini() {
    Node *n = NULL;
    n = (Node*) malloc(sizeof (Node));

    if (n == NULL) {
        fprintf(stderr, "%s\n", strerror(errno));
        return NULL;
    }

    n->name = NULL;
    n->id = 0;

    return n;
}

void node_destroy(void *n) {
    if(!n) return;
    free(n->name);
    free(n);
}

int node_getId(const Node *n) {
    if (n == NULL) return FLAG;

    return n->id;
}

char* node_getName(const Node *n) {
    if (n == NULL) return NULL;

    return n->name;
}

Node* node_setId(Node *n, const int id) {
    if (n == NULL) return NULL;

    n->id = id;
    return n;
}

Node* node_setName(Node *n, const char *name) {
    if (n == NULL) return NULL;

    n->name = (char*) malloc((1 + strlen(name))*sizeof (char))

    strncpy(n->name, name, (1 + strlen(name)));

    return n;
}

int node_cmp(const void *n1, const void *n2) {
    if (n1 == NULL||n2 == NULL) return FLAG;

    return (node_getId((Node*)n1)-node_getId((Node*)n2));
}

void* node_copy(const void *src) {
    Node *n;
    if (src == NULL) return NULL;


    n = (Node*) malloc(sizeof (Node));
    if (n == NULL) {
        fprintf(stderr, "%s\n", strerror(errno));
        return NULL;
    }

    node_setId(n, node_getId((Node*)src));
    node_setName(n, node_getName((Node*)src));
    return (void*)n;
}

int node_print(FILE *pf, const void *n) {

    if (n == NULL|| pf == NULL) return FLAG;

    return fprintf(pf, "[%s, %d, %d]", ((Node*)n)->name, ((Node*)n)->id);
}
