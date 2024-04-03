/** 
 * @brief Testea el funcionamiento de
 * las funciones de inventory.c
 * 
 * @file inventory_test.c
 * @author Mario Iribas
 * @version 1.0 
 * @date 25-02-2021
 * Editado y comentado por: Mario Iribas 
 */
#include "inventory.h"

int main(){
    Bag *b;

    b = inventory_create();

    if (!b) return -1;

    if (inventory_setId(b, 1) == ERROR){
        printf ("La función inventory_setId falla\n");
    }
    else if(inventory_existId(b, 1) == TRUE){
        printf ("La función inventory_setId es correcta\n");
    }
    else {
        printf ("La función inventory_setId falla\n");
    }

    if (inventory_setMax(b, 10) == ERROR) {
        printf("La función inventory_setMax falla\n");
    }
    else if(inventory_getMax(b) == 10){
        printf ("La función inventory_setMax es correcta\n");
    }
    else {
        printf ("Las función inventory_setMax falla\n");
    }

    if(inventory_print(b) == ERROR) {
        printf ("La función inventory_print falla\n");
    }
    else {
        printf("Expected output:\nmax: 10\n");
        set_print(inventory_getId(b));
        printf("\n");
    }

    if(inventory_destroy(b) == ERROR) {
        printf("La función inventory_destroy falla\n");
    }
    else {
        printf("La función inventory_destroy es correcta (correr valgrind)\n");
    }

    return 0;
}