/******************************************************************************

Nombre del modulo: node.c

Descripcion: Implementacion de las funciones de node.h. Sirve para trabajar con nodos,
			 esta adaptado para trabajar con punteros a funciones.

Autor: Jorge Fernandez Garcia y Pedro Sanchez de la Muela

Fecha: 25 - 3 - 2019

******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include "node.h"


#define NAME_L 64

struct _Node {
char name[NAME_L]; // nombre del nodo
int id; // id del nodo
int nConnect; // número de conexiones que parten del nodo

Label etq; // estado del nodo
int antecesor_id; // solo necesario para el ejercicio opcional
};

Node* node_ini() {
    Node *n = NULL;
    n = (Node*) malloc(sizeof (Node));

    if (n == NULL) {
        fprintf(stderr, "%s\n", strerror(errno));
        return NULL;
    }

    n->nConnect = 0;
    n->id = 0;
    n->etq = BLANCO;
    n->antecesor_id = -1;
    return n;
}

void node_destroy(void *n) {
    free(n);
}

int node_getId(const Node *n) {
    if (n == NULL) return FLAG;

    return n->id;
}

char* node_getName(const Node *n) {
    if (n == NULL) return NULL;

    return (char*)n->name;
}

int node_getConnect(const Node *n) {
    if (n == NULL) return FLAG;

    return n->nConnect;
}

Label node_getLabel (const Node* n){
    if (n == NULL) return FLAG;

    return n->etq;

}

int node_getAntecesorId (const Node* n){
    if (n == NULL) return FLAG;

    return n->antecesor_id;
}

Node* node_setLabel (Node* n, Label l){
    if (n == NULL) return NULL;

    n->etq = l;
    return n;
}

Node* node_setAntecesorId (Node* n, int antid){
    if (n == NULL) return NULL;

    n->antecesor_id = antid;
    return n;
}

Node* node_setId(Node *n, const int id) {
    if (n == NULL) return NULL;

    n->id = id;
    return n;
}

Node* node_setName(Node *n, const char *name) {
    if (n == NULL) return NULL;

    strncpy(n->name, name, NAME_L-1);

    return n;
}

Node* node_setConnect(Node *n, const int cn) {
    if (n == NULL) return NULL;

    n->nConnect = cn;

    return n;
}



int node_cmp(const Node *n1, const Node *n2) {
    if (n1 == NULL||n2 == NULL) return FLAG;

    return ((n1->id)-(n2->id));
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
    node_setConnect(n, node_getConnect((Node*)src));
    node_setName(n, node_getName((Node*)src));
    node_setLabel (n, node_getLabel((Node*)src));
    node_setAntecesorId (n, node_getAntecesorId((Node*)src));
    return (void*)n;
}

int node_print(FILE *pf, const void *n) {

    if (n == NULL|| pf == NULL) return FLAG;

    return fprintf(pf, "[%s, %d, %d]", ((Node*)n)->name, ((Node*)n)->id, ((Node*)n)->nConnect);

}
