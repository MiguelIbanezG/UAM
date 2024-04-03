/** 
 * @brief Define los objetos
 * del juego
 * 
 * 
 * @file object.h
 * @author Sergio Hidalgo
 * @version 1.0 
 * @date 25-02-2021 
 * Editado y comentado por: Sergio Hidalgo
 */
#ifndef OBJECT_H
#define OBJECT_H

#define MAX_OBJECTS 100

#include "types.h"

/*Definición de la estructura*/
typedef struct _Object Object;

/*Compendio de funciones públicas que crean, destruyen y mueven el objeto*/
Object *object_create(Id id);
STATUS object_destroy(Object *object);
Id object_get_id(Object *object);
STATUS object_setDescription (Object *o, char *descr);
char *object_getDescription (Object *object);
STATUS object_set_name(Object *space, char *object);
const char *object_get_name(Object *object);
STATUS object_print(Object *object);
BOOL object_Idcheck(Object *object, Id id);
STATUS object_set_movable(Object *object, int movable);
BOOL object_get_movable(Object *object);
STATUS object_set_dependency(Object *object, Id id);
Id object_get_dependency(Object *object);
STATUS object_set_open(Object *object, Id id);
Id object_get_open(Object *object);
STATUS object_set_illuminate(Object *object, int illuminate);
BOOL object_get_illuminate(Object *object);
STATUS object_set_turnedon(Object *object, int turnedon);
BOOL object_get_turnedon(Object *object);

#endif