#include <stdio.h>
#include <string.h>
#include "object.h"

int main() {
    Object *object;

    object = object_create(1);

    if(object) {
        if(object_get_id(object) == 1 && object_Idcheck(object, 1) == TRUE) {
            printf("La función object_create funciona correctamente.\n");
        }
        else {
            printf("La función object_create falla.\n");
        }
    }
    else {
        printf("La función object_create falla.");
    }

    if(object_set_name(object, "linterna") == OK){
        if (strcmp(object_get_name(object), "linterna") == 0){ 
            printf("La función object_set_name funciona correctamente.\n");
        }
        else {
            printf("La función object_set_name falla.\n");
        }
    }
    
    if (object_setDescription(object, "ilumina") == OK){
        if (strcmp(object_getDescription(object), "ilumina") == 0){
            printf ("La función object_setDescription funciona correctamente.\n");
        }
    }
    else{
        printf ("La función object_setDescription falla.\n");
    }
    
    printf("Obtained output:\n");
    if(object_print(object) == OK) {
        printf("Expected output: \n--> Object (Id: 1; Name: linterna; Description: ilumina)\n");
    }
    else {
        printf("La función object_print falla.");
    }


    if(object_destroy(object) == OK) {
        printf("La función object_destroy funciona correctamente (correr valgrind).\n");
    }
    else {
        printf("La función object_destroy falla.\n");
    }

    return 0;
    
}