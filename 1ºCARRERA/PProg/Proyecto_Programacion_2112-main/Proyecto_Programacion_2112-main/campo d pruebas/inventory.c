/** 
 * @brief Implementa la funcionalidad del
 * inventario
 * 
 * @file inventory.c
 * @author Ignacio González
 * @version 1.0 
 * @date 25-02-2021
 * Editado y comentado por: Ignacio González
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "inventory.h"

struct _Bag {
    Set *id;
    int max_object;
};

Bag *inventory_create(){ /*Reserva memoria para el inventario por: Mario García*/
    Bag *newBag;

    newBag = (Bag*)malloc(sizeof(Bag));

    if(newBag == NULL) {
        return NULL;
    }

    newBag->id = set_create();

    newBag->max_object = MAX_OBJECTS;
    
    return newBag;
}

STATUS inventory_destroy(Bag *b){ /*Libera la memoria del inventario por: Mario García*/
    if (!b) return ERROR;
    
    set_destroy(b->id);
    
    free(b);

    return OK;
}

STATUS inventory_set_addId(Bag *b, Id id){ /*Añade un id en el inventario por: Ignacio González*/ 
    if (!b || !id) return ERROR;

    if (set_add_id(b->id, id) == ERROR) return ERROR;

    return OK;
}

STATUS inventory_set_delId(Bag *b, Id id){ /*Elimina un id en el inventario por: Ignacio González*/
    if (!b || !id) return ERROR;

    if (set_del_id(b->id, id) == ERROR) return ERROR;

    return OK;
}

STATUS inventory_setMax(Bag *b, int num){ /*Establece un número maximo de objetos que puede llevar un jugador por: Ignacio González*/
    if (!b) return ERROR;
    
    b->max_object = num; 

    return OK;
}

Set* inventory_getId(Bag *b){ /*Devuelve el set del inventario por: Ignacio González*/
    if (!b) return NULL;

    return b->id;
}

int inventory_getMax(Bag *b){ /*Devuelve el máximo de objetos que puede llevar un jugador por: Ignacio González*/
    if (!b) return -1;

    return b->max_object;
}

BOOL inventory_existId(Bag *b, Id id) { /*Indica si en el inventario ya hay un id determinado por: Mario García*/
    if(b == NULL || id < 0) {
        return FALSE;
    }

    
    return set_Idcheck(b->id, id);

}

STATUS inventory_print(Bag *b) { /*Imprime el inventario por: Mario García*/

    if(b == NULL){
        return ERROR;
    }

    fprintf(stdout, "max: %d\n", b->max_object);
    if(set_print(b->id) == ERROR) {
        return ERROR;
    }

    return OK;
}

int inventory_getTam (Bag *b) /*Devuelve el número de ids que tiene el inventario en ese momento por: Ignacio González*/
{
    if (b == NULL)
    {
        return 0;
    }
    
    return set_getnIds(b->id);

}



















