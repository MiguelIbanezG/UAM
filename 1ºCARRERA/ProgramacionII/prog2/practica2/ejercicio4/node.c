#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#include "node.h"

#define MAX_NAME 100

struct _Node {
    
	char name[MAX_NAME];
	int id;
	int nConnect; 
	Label etq; // estado del nodo
	int antecesor_id; //solo necesario para el ejercicio opcional
};

Node * node_ini() {

    Node *nodo = NULL;
    
    nodo = (Node*)malloc(sizeof(Node));
    if (!nodo) return NULL;
    
    nodo->nConnect = 0;
    nodo->id = 0;
    nodo->etq = BLANCO;
    nodo->antecesor_id = -2;
    
    return nodo;
}

void node_destroy(void * n) {
    free (n);
}

int node_getId(const Node * n) {
    
    if (!n) {
        return -1;
    }
    
    return (int)n->id;
}

char* node_getName(const Node * n) {
    
    if (!n) {
        return NULL;
    }
    
    return (char*)n->name;
}

int node_getConnect(const Node * n) {
    
    if (!n) {
        return -1;
    }
    
    return (int)n->nConnect;
}

Label node_getLabel (const Node *n) {

    if (!n) return NOT_DEFINED;
    
    return (Label)n->etq;
}

int node_getAntecesorId (const Node *n) {

    if (!n) return -1;
    
    return (int)n->antecesor_id;
}

Node * node_setId(Node * n, const int id) {
    
    if (!n) {
        return NULL;
    }
    
    n->id = (int)id;
    return n;
}

Node * node_setName(Node * n, const char* name) {
    
    if (!n) {
        return NULL;
    }
    
    strncpy (n->name, (char*)name, MAX_NAME-1);
    return n;
}

Node * node_setConnect(Node * n, const int cn) {
    
    if (!n) {
        return NULL;
    }
    
    n->nConnect = (int)cn;
    return n;
}

Node * node_setLabel(Node * n, const Label cn) {

    if (!n) {
        return NULL;
    }
    
    n->etq = (Label)cn;
    return n;
}

Node * node_setAntecesorId(Node * n, const int cn) {
    
    if (!n) {
        return NULL;
    }
    
    n->antecesor_id = (int)cn;
    return n;
}

int node_cmp (const Node * n1, const Node * n2) {
    
    int id1, id2;
    
    if (!n1 || !n2) return -2;
    
    id1 = node_getId(n1);
    id2 = node_getId(n2);
    
    if (id1 < id2) {
        
        return -1;
        
    } else if (id1 > id2) {
        
        return 1;
        
    } else {
        
        return 0;
    }
}

void * node_copy(const void * src) {
    
    Node *copia = NULL;
    
    if (!src) {
        return NULL;
    }
    
    copia = (Node*)malloc(sizeof(Node));
    if (!copia) {
        return NULL;
    }
    
    node_setId(copia, node_getId((Node*)src));
    node_setName(copia, node_getName((Node*)src));
    node_setConnect (copia, node_getConnect((Node*)src));
    node_setLabel (copia, node_getLabel((Node*)src));
    node_setAntecesorId (copia, node_getAntecesorId((Node*)src));
    
    return (void*)copia;
}

int node_print(FILE *pf, const void * n) {

	if (!pf || !n) return 0;
    
	return fprintf (pf, "[%s, %d, %d]", ((Node*)n)->name, ((Node*)n)->id, ((Node*)n)->nConnect);

}
