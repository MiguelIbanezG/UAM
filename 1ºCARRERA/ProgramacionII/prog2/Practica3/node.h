#ifndef NODE_H_
#define NODE_H_
#include <stdio.h>
#include "types.h"

typedef enum {
 BLANCO, NEGRO
} Label;

typedef struct _Node Node;

Node * node_ini();

void node_destroy(void * n);

int node_getId(const Node * n);

char* node_getName(const Node * n);

int node_getConnect(const Node * n);

Node * node_setId(Node * n, const int id);

Node * node_setName(Node * n, const char* name);

Node * node_setConnect(Node * n, const int cn);

int node_cmp (const Node * n1, const Node * n2);

void * node_copy(const void* src);

int node_print(FILE *pf, const void * n);

//Funciones adicionales del ejercicio 4

Label node_getLabel (const Node* n);
Node* node_setLabel (Node* n, Label l);

int node_getAntecesorId (const Node* n);
Node* node_setAntecesorId (Node* n, int antid);



#endif /* NODE_H_ */
