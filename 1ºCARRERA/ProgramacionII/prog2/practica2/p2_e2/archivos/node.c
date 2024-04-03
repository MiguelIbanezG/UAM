#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include "node.h"
#include "types.h"


struct _Node {
    char name[100];
    int id;
    int nConnect;
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
    
    return n;
}

void node_destroy(void *n) {
    free(n);
}

int node_getId(const Node *n) {
    if (n == NULL) {
        return FLAG;
    }
    return n->id;
}

char* node_getName(const Node *n) {
    if (n == NULL) {
        return NULL;
    }
    return n->name;
}

int node_getConnect(const Node *n) {
    if (n == NULL) {
        return FLAG;
    }
    return n->nConnect;
}

Node* node_setId(Node *n, const int id) {
    if (n == NULL) {
        return NULL;
    }
    n->id = id;

}

Node* node_setName(Node *n, const char *name) {
    if (n == NULL) {
        return NULL;
    }
    strncpy(n->name, name, MAXN-1);

    return n;
}

Node* node_setConnect(Node *n, const int cn) {
    if (n == NULL) {
        return NULL;
    }
    n->nConnect = cn;
    
    return n;
}

int node_cmp(const Node *n1, const Node *n2) {
    if (n1 == NULL||n2 == NULL) {
        return FLAG;
    }
    return ((n1->id)-(n2->id));
}

void* node_copy(const void *src) {
    Node *n;
    if (src == NULL) {
        return NULL;
    }
    
    n = (Node*) malloc(sizeof (Node));
    if (n == NULL) {
        fprintf(stderr, "%s\n", strerror(errno));
        return NULL;
    }
    node_setId(n, node_getId((Node*)src));
    node_setConnect(n, node_getConnect((Node*)src));
    node_setName(n, node_getName((Node*)src));
    return (void*)n;
}

int node_print(FILE *pf, const void *n) {
    int i;
    if (n == NULL|| pf == NULL) {
        return FLAG;
    }
    i = fprintf(pf, "[%d, %s, %d]", node_getId((Node*)n), node_getName((Node*)n), node_getConnect((Node*)n));
    return i;
}
