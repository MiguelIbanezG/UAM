#include <stdio.h>
#include <stdlib.h>
#include "node.h"
#include <string.h>

struct _Node {
    
 char name[100];
 int id;
 int nConnect; 
 
};

Node * node_ini() {
    Node *nodo;
    
    nodo = (Node*)malloc(sizeof(Node));
    
    return nodo;
}

void node_destroy(Node * n) {
    free (n);
}

int node_getId(const Node * n) {
    
    return n->id;
}

char* node_getName(const Node * n) {
    
    if (!n) {
        return NULL;
    }
    
    return n->name;
}

int node_getConnect(const Node * n) {
    
    if (n == NULL) {
        return -1;
    }
    
    return n->nConnect;
}

Node * node_setId(Node * n, const int id) {
    
    if (!n) {
        return NULL;
    }
    
    n->id = id;
    return n;
}

Node * node_setName(Node * n, const char* name) {
    
    if (!n) {
        return NULL;
    }
    
    strcpy (n->name, name);
    return n;
}

Node * node_setConnect(Node * n, const int cn) {
    if (!n) {
        return NULL;
    }
    
    n->nConnect = cn;
    return n;
}

int node_cmp (const Node * n1, const Node * n2) {
    
    if (n1->id < n2->id) {
        
        return -1;
        
    } else if (n1->id > n2->id) {
        
        return 1;
        
    } else {
        
        if (strcmp(n1->name, n2->name) < 0) {
            
            return -1;
            
        } else if (strcmp(n1->name, n2->name) > 0) {
            
            return 1;
            
        } else {
            
            return 0;
            
        }
    }
}

Node * node_copy(const Node * src) {
    
    Node *copia;
    
    if (!src) {
        return NULL;
    }
    
    copia = (Node*)malloc(sizeof(Node));
    if (!copia) {
        return NULL;
    }
    
    copia = node_setId(copia, src->id);
    copia = node_setName(copia, src->name);
    copia = node_setConnect (copia, src->nConnect);
    
    return copia;
}

int node_print(FILE *pf, const Node * n) {
    
    return fprintf (stdout, "[%d %s %d]", n->id, n->name, n->nConnect);
}