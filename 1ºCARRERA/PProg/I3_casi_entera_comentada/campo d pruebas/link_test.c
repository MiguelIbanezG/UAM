/** 
 * @brief Testea la funcionalidad de link.c
 * 
 * @file link_test.c
 * @author Mario García
 * @version 1.0 
 * @date 25-02-2021
 * Editado y comentado por: Mario García
 */
#include <stdio.h>
#include <string.h>
#include "link.h"

int main() {
    Link *l;

    l = link_create();

    if(l && link_getId(l) == NO_ID && link_getSpace1Id(l) == NO_ID && link_getSpace2Id(l) == NO_ID) {
        printf("La función link_create es correcta.\n");
    }
    else {
        printf("La función link_create falla.\n");
    }
    

    if(link_setId(l, 1) == OK) {
        if(link_getId(l) == 1) {
            printf("La función link_setId es correcta.\n");
        }
        else {
        printf("La función link_setId falla.\n");
        }
    }
    else {
        printf("La función link_setId falla.\n");
    }

    if(link_setName(l, "link") == OK) {
        if (strcmp(link_getName(l), "link") == 0){
            printf("La función link_setName es correcta.\n");
        }
        else {
            printf("La función link_setName falla.\n");
        }
    }
    else {
        printf("La función link_setName falla.\n");
    }

    if(link_newConnection(l, 2, 3) == OK) {
        if(link_exist(l, 2, 3) == TRUE) {
            printf("La función link_exist es correcta.\n");
            printf("La función link_newConnection es correcta.\n");
        }
        else {
        printf("La función link_newConnection falla.\n");
        }
    }
    else {
        printf("La función link_newConnection falla.\n");
    }

    if (link_destroy(l) == OK){
        printf ("La función link_destroy es correcta (correr valgrind).\n");
    }
    else{
        printf ("La función link_destroy falla.\n");
    }

    return 0;
}