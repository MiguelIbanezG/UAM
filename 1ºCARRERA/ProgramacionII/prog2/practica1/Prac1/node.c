/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "node.h"
#include "types.h"

struct _Node {
 char name[100];
 int id;
 int nConnect; 
};
Node* node_ini(){
    Node *n;
    n=(Node*)malloc(sizeof(Node));
    
    if(n==NULL){
        fprintf(stdout,"La asignación de memoria ha fallado.");
    }
    return n;
}
void node_destroy(Node *n){
    free(n);
}
int node_getId(const Node *n){
    if(n==NULL){
        return -1;
    }
    else
        return n->id;
}
char* node_getName(const Node *n){
    if(n==NULL){
        return NULL;
    }
    else
        return n->name;
}
int node_getConnect(const Node *n){
    if(n==NULL){
        return -1;
    }
    else
        return n->nConnect;
}
Node* node_setId(Node *n,const int id){
    n->id=id;
    if(n==NULL){
        return NULL;
    }
}
Node* node_setName(Node *n,const char *name){
    strcpy(n->name,name);
    if(n==NULL){
        return NULL;
    }
}
Node* node_setConnect(Node *n,const int cn){
    n->nConnect=cn;
    if(n==NULL){
        return NULL;
    }
}
int node_cmp(const Node *n1,const Node *n2){
    return ((n1->id)-(n2->id));
}
Node* node_copy(const Node *src){
    Node *n;
    n=(Node*)malloc(sizeof(Node));
        if(n==NULL){
        return NULL;
    }
    n->id=src->id;
    n->nConnect=src->nConnect;
    strcpy(n->name,src->name);
    return n;
}
int node_print(FILE *pf,const Node *n){
    int i;
    i=fprintf(pf,"[%d, %s, %d]",n->id,n->name,n->nConnect);
    return i;
}