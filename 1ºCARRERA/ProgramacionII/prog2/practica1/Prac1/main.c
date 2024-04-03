/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: eps
 *
 * Created on 5 de febrero de 2019, 12:28
 */

#include <stdio.h>
#include <stdlib.h>
#include "node.h"
#include "types.h"

/*
 * 
 */
int main() {
    Node *n,*a;
    int c;
    n=node_ini();
    node_setId(n,111);
    node_setName(n,"first");
    
    a=node_ini();
    node_setId(a,222);
    node_setName(a,"second");
    
    c=node_print(stdout,n);
    c=node_print(stdout,a);
    printf("\n");
    
    printf("Son iguales?");
    if(node_cmp(a,n)==0){
        printf(" Sí.\n");
    }
    else printf(" No.\n");
    
    printf("Id del primer nodo: %d\n",node_getId(n));
    printf("Nombre del segundo nodo: %s\n",node_getName(a));
    
    a=node_copy(n);
    c=node_print(stdout,n);
    c=node_print(stdout,a);
    
    printf("\nSon iguales?");
    if(node_cmp(a,n)==0){
        printf(" Sí.\n");
    }
    else printf(" No.\n");
    
    node_destroy(n);
    node_destroy(a);
    return (EXIT_SUCCESS);
}

