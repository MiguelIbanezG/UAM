/** 
 * @brief Define los conjuntos
 * del juego
 * 
 * 
 * @file set.h
 * @author Sergio Hidalgo
 * @version 1.0 
 * @date 03-03-2021 
 * Editado y comentado por: Sergio Hidalgo
 */
#ifndef SET_H
#define SET_H

#include "types.h"

/*Definición de la estructura*/
typedef struct _Set Set;

#define MAX_ID 100

/*Funcuines públicass*/
Set *set_create();
STATUS set_destroy(Set *set);
STATUS set_add_id(Set *set, Id id);
STATUS set_del_id(Set *set, Id id);
STATUS set_print(Set *set);
Id set_findId(Set *set, int position);
BOOL set_Idcheck(Set *set, Id id);
int set_getnIds(Set *set);
Id *set_getArrayIds(Set *set);

#endif