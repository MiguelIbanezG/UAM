#ifndef NODE_H_
#define NODE_H_
#include <stdio.h>
#include "types.h"

#define FLAG -1

typedef struct _Node Node;

Node * node_ini();

void node_destroy(void * n);

int node_getId(const Node * n);

char* node_getName(const Node * n);

Node * node_setId(Node * n, const int id);

Node * node_setName(Node * n, const char* name);

int node_cmp(const void *n1, const void *n2);

void * node_copy(const void* src);

int node_print(FILE *pf, const void * n);

#endif /* NODE_H_ */
