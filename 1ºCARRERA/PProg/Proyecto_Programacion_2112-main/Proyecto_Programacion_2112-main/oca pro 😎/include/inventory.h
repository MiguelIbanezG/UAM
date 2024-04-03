/** 
 * @brief Implementa las funciones del
 * inventario
 * 
 * @file inventory.h
 * @author Ignacio González
 * @version 1.0 
 * @date 25-02-2021
 * Editado y comentado por: Ignacio González
 */
#include "types.h"
#include "set.h"
#include "object.h"

#ifndef INVENTORY_H
#define INVENTORY_H

typedef struct _Bag Bag;

Bag *inventory_create();
STATUS inventory_destroy(Bag *b);
STATUS inventory_set_addId(Bag *b, Id id);
STATUS inventory_set_delId(Bag *b, Id id);
STATUS inventory_setMax(Bag *b, int num);
Id inventory_getId(Bag *b, int position);
int inventory_getMax(Bag *b);
BOOL inventory_existId(Bag *b, Id id);
STATUS inventory_print(Bag *b);
int inventory_getTam (Bag *b);

#endif