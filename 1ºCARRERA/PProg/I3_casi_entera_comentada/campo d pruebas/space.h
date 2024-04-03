/** 
 * @brief Define el espacio
 * 
 * @file space.h
 * @author Profesores PPROG
 * @version 1.0 
 * @date 13-01-2015
 * @copyright GNU Public License
 * Editado y comentado por: Miguel Ibáñez
 */

#ifndef SPACE_H
#define SPACE_H

#include "types.h"
#include "link.h"

/*Estructura de tipo Space*/
typedef struct _Space Space;

#define MAX_SPACES 100
#define FIRST_SPACE 1
#define MAX_GDESC 3
#define MAX_STRING 8

/*Grupo de funciones publicas que crean, destruyen y mueven el tablero y los objetos*/
Space* space_create(Id id);
STATUS space_destroy(Space* space);
Id space_get_id(Space* space);
STATUS space_set_name(Space* space, char* name);
const char* space_get_name(Space* space);
STATUS space_set_north(Space* space, Link *link);
Id space_get_north(Space* space);
STATUS space_set_south(Space* space, Link *link);
Id space_get_south(Space* space);
STATUS space_set_east(Space* space, Link *link);
Id space_get_east(Space* space);
STATUS space_set_west(Space* space, Link *link);
Id space_get_west(Space* space);
STATUS space_setAdd_object (Space* space, Id value);
STATUS space_setDel_object (Space* space, Id value);
STATUS space_print(Space* space);
BOOL space_setobject_Idcheck(Space *space, Id id);
int space_setgetIds (Space *space);
Id *space_get_object (Space *space);
STATUS space_set_gdesc(Space *space, char *gdesc, int position);
char *space_get_gdesc(Space *space, int position);


#endif
