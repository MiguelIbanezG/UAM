#include <stdio.h>
#include <stdlib.h>
#include "node.h"

int main(int argc, char** argv) {
    Node *first, *second;
    int i, id1;
    char *Name2;
    
    first = node_ini();
    first = node_setId (first, 111);
    first = node_setName (first, "first");
    first = node_setConnect (first, 0);
    
    second = node_ini();
    second = node_setId (second, 222);
    second = node_setName (second, "second");
    second = node_setConnect (second, 0);
    
    node_print(stdout, first);
    node_print(stdout, second);
    
    i = node_cmp(first, second);
    
    printf("\n¿Son iguales?");  
    
    if(i==0){
        printf(" Si\n");
    }
    else{
        printf(" No\n");
    }
    
    id1=node_getId(first);
    printf("Id del primer nodo: %d\n", id1);
    
    Name2=node_getName(second);
    printf("Nombre del segundo nodo es: %s\n", Name2);
    
    second=node_copy(first);
    
    node_print(stdout, first);
    node_print(stdout, second);
    
    i=node_cmp(first, second);
    printf("\n¿Son iguales?");   
    if(i==0){
        printf(" Si");
    }
    else{
        printf(" No");
    }
    
    node_destroy(first);
    node_destroy(second);
    return (EXIT_SUCCESS);
}