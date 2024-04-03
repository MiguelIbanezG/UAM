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
  char descr[WORD_SIZE + 1];
  BOOL movable;
  Id dependency;
  Id open;
  BOOL illuminate;
  BOOL turnedon;
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
  newObject->movable = FALSE;
  newObject->dependency = NO_ID;
  newObject->open = NO_ID;
  newObject->illuminate = FALSE;
  newObject->turnedon = FALSE;

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

STATUS object_setDescription(Object *object, char *descr)
{ /*Le da una descripción al objeto por: Ignacio González*/
  if (!object || !descr)
    return ERROR;

  strcpy(object->descr, descr);

  return OK;
}

STATUS object_set_movable(Object *object, int movable) /*Determina si un objecto se va a poder mover o no por: Sergio Hidalgo*/
{
  if (!object || movable < 0) return ERROR;

  if (movable == 0)
  {
    object->movable = FALSE;
    return OK;
  }
  else if (movable == 1)
  {
    object->movable = TRUE;
    return OK;
  }
  
  

  return ERROR;
}

BOOL object_get_movable(Object *object) { /*Devuelve si un objecto se puede mover o no por: Mario García*/
  if(!object) return FALSE;
  
  return object->movable;
}

STATUS object_set_dependency(Object *object, Id id){/*Establece la dependencia de un objeto respecto a otro por: Ignacio González*/

  if (!object || id == NO_ID) return ERROR;

  object->dependency = id;

  return OK;

}

Id object_get_dependency(Object *object){/*Devuelve la id del objeto que depende otro object por: Ignacio González*/
  if (!object) return NO_ID;

  return object->dependency;
}

STATUS object_set_open(Object *object, Id id){/*Establece si un objeto puede abrir un enlace por: Miguel Ibáñez*/

  if (!object || id == NO_ID) return ERROR;

  object->open = id;

  return OK;
}

Id object_get_open(Object *object){/* Devuelve si un objecto puede abrir un enlace por: Miguel Ibáñez*/

  if (!object) return NO_ID;

  return object->open;
}

STATUS object_set_illuminate(Object *object, int illuminate){ /*Establece si un objeto puede iluminar por: Mario García*/

  if (!object) return ERROR;

  if (illuminate == 0){
    object->illuminate = FALSE;
    return OK;
  }
  else if(illuminate == 1){
    object->illuminate = TRUE;
    return OK;
  }

  return ERROR;
}

BOOL object_get_illuminate(Object *object){/*Devuelve si un objeto puede iluminar por: Mario García*/

  if (!object) return FALSE;

  return object->illuminate;
}

STATUS object_set_turnedon(Object *object, int turnedon){/*Establece si un objeto está encendido o apagado por: Mario García*/

  if (!object || object->illuminate == FALSE) return ERROR;

  if (turnedon == 0)
  {
    object->turnedon = FALSE;
    return OK;
  }
  else if (turnedon == 1)
  {
    object->turnedon = TRUE;
    return OK;
  }
  

  return ERROR;
}

BOOL object_get_turnedon(Object *object){/*Devuelve si un objeto está encendido o apagado por: Mario García*/

  if (!object) return FALSE;

  return object->turnedon;
}

char *object_getDescription(Object *object)
{ /*Devuelve la descripción del objeto por: Ignacio González*/
  if (!object)
    return NULL;

  return object->descr;
}

/*Se comprueba si el objeto existe*/
BOOL object_Idcheck(Object *object, Id id) /*Por: Sergio Hidalgo*/
{
  if (!object)
    return FALSE;

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
