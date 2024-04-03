/** 
 * @brief Implementa los objetos en el juego
 * 
 * @file object.c
 * @author Sergio Hidalgo
 * @version 1.0 
 * @date 25-02-2021
 * Editado y comentado por: Sergio Hidalgo
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "object.h"

/*Estructura de Objetos con id y nombre*/
struct _Object
{
  Id id;
  char name[WORD_SIZE + 1];
  char descr[WORD_SIZE +1];
};

/*Crea un objeto y reserva su memoria*/
Object *object_create(Id id)
{ /*Por: Sergio Hidalgo*/

  Object *newObject = NULL;

  if (id == NO_ID)
    return NULL;

  newObject = (Object *)malloc(sizeof(Object));

  if (newObject == NULL)
  {
    return NULL;
  }
  newObject->id = id;

  newObject->name[0] = '\0';
  newObject->descr[0] = '\0';

  return newObject;
}

/*Destruye un objeto y libera su memoria*/
STATUS object_destroy(Object *object)
{ /*Por: Sergio Hidalgo*/
  if (!object)
  {
    return ERROR;
  }

  free(object);
  object = NULL;

  return OK;
}

/*Le da un nombre al objeto*/
STATUS object_set_name(Object *object, char *name)
{ /*Por: Sergio Hidalgo*/
  if (!object || !name)
  {
    return ERROR;
  }

  strcpy(object->name, name);
  
  
  return OK;
}

/*Se pide la id del objeto*/
Id object_get_id(Object *object)
{ /*Por: Sergio Hidalgo*/
  if (!object)
  {
    return NO_ID;
  }
  return object->id;
}

STATUS object_setDescription (Object *object, char *descr){ /*Le da una descripción al objeto por: Ignacio González*/
  if (!object || !descr) return ERROR;

  strcpy(object->descr, descr);

  return OK;
}

char *object_getDescription (Object *object){ /*Devuelve la descripción del objeto por: Ignacio González*/
  if (!object) return '\0';

  return object->descr;
}

/*Se comprueba si el objeto existe*/
BOOL object_Idcheck(Object *object, Id id) /*Por: Sergio Hidalgo*/
{
  if (object_get_id(object) == id)
  {
    return TRUE;
  }

  return FALSE;
}

/*Se obtiene el nombre del objeto*/
const char *object_get_name(Object *object)
{ /*Por: Sergio Hidalgo*/
  if (!object)
  {
    return NULL;
  }
  return object->name;
}

/*Se imprime un objeto*/
STATUS object_print(Object *object)
{ /*Por: Sergio Hidalgo*/

  if (!object)
  {
    return ERROR;
  }

  fprintf(stdout, "--> Object (Id: %ld; Name: %s; Description: %s)\n", object->id, object->name, object->descr);

  return OK;
}
