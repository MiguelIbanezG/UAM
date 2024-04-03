/** 
 * @brief Implementa el espacio
 * 
 * @file space.c
 * @author Profesores PPROG
 * @version 1.0 
 * @date 13-01-2015
 * @copyright GNU Public License
 * Editado y comentado por: Miguel Ibáñez
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "types.h"
#include "space.h"
#include "set.h"

/*Estructura del espacio que contiene el id, el nombre, la posición según los puntos cardinales y 1 set de objetos*/
struct _Space
{
  Id id;
  char name[WORD_SIZE + 1];
  Id north;
  Id south;
  Id east;
  Id west;
  Set *objects;
};

/*Crea un espacio y reserva su memoria*/
Space *space_create(Id id)
{/*Por: Miguel Ibáñez*/

  Space *newSpace = NULL;

  if (id == NO_ID)
    return NULL;

  newSpace = (Space *)malloc(sizeof(Space));

  if (newSpace == NULL)
  {
    return NULL;
  }
  newSpace->id = id;

  newSpace->name[0] = '\0';

  newSpace->north = NO_ID;
  newSpace->south = NO_ID;
  newSpace->east = NO_ID;
  newSpace->west = NO_ID;

  newSpace->objects = set_create();

  return newSpace;
}

/*Destruye un espacio y libera su memoria*/
STATUS space_destroy(Space *space)
{/*Por: Miguel Ibáñez*/
  if (!space)
  {
    return ERROR;
  }

  set_destroy(space->objects);

  space->objects = NULL;

  free(space);
  space = NULL;

  return OK;
}

/*Le da un nombre al espacio*/
STATUS space_set_name(Space *space, char *name)
{/*Por: Miguel Ibáñez*/
  if (!space || !name)
  {
    return ERROR;
  }

  if (!strcpy(space->name, name))
  {
    return ERROR;
  }

  return OK;
}

/*El espacio se coloca al norte*/
STATUS space_set_north(Space *space, Id id)
{/*Por: Miguel Ibáñez*/
  if (!space || id == NO_ID)
  {
    return ERROR;
  }
  space->north = id;
  return OK;
}

/*El espacio se coloca al sur*/
STATUS space_set_south(Space *space, Id id)
{/*Por: Miguel Ibáñez*/
  if (!space || id == NO_ID)
  {
    return ERROR;
  }
  space->south = id;
  return OK;
}

/*El espacio se coloca al este*/
STATUS space_set_east(Space *space, Id id)
{/*Por: Miguel Ibáñez*/
  if (!space || id == NO_ID)
  {
    return ERROR;
  }
  space->east = id;
  return OK;
}

/*El espacio se coloca al oeste*/
STATUS space_set_west(Space *space, Id id)
{/*Por: Miguel Ibáñez*/
  if (!space || id == NO_ID)
  {
    return ERROR;
  }
  space->west = id;
  return OK;
}

/*Añade un objeto al set a partir de su id (llama a una función de set.c)*/
STATUS space_setAdd_object(Space *space, Id value)
{/*Por: Miguel Ibáñez*/

  if (set_add_id(space->objects, value) == OK)
  {

    return OK;
  }
  else

    return ERROR;
}

/*Borra un objeto del set del espacio*/
STATUS space_setDel_object(Space *space, Id value)
{/*Por: Miguel Ibáñez*/

  int i;

  for (i = 0; i < set_getnIds(space->objects); i++)
  {
    set_del_id(space->objects, value);
  }

  return OK;
}

/*Se pide el nombre del espacio*/
const char *space_get_name(Space *space)
{/*Por: Miguel Ibáñez*/
  if (!space)
  {
    return NULL;
  }
  return space->name;
}

/*Se pide la id del espacio*/
Id space_get_id(Space *space)
{/*Por: Miguel Ibáñez*/
  if (!space)
  {
    return NO_ID;
  }
  return space->id;
}

/*Para saber si el espacio está al Norte, Sur, Este u Oeste (las siguientes 4 funciones)*/
Id space_get_north(Space *space)
{/*Por: Miguel Ibáñez*/
  if (!space)
  {
    return NO_ID;
  }
  return space->north;
}

Id space_get_south(Space *space)
{
  if (!space)
  {
    return NO_ID;
  }
  return space->south;
}

Id space_get_east(Space *space)
{
  if (!space)
  {
    return NO_ID;
  }
  return space->east;
}

Id space_get_west(Space *space)
{
  if (!space)
  {
    return NO_ID;
  }
  return space->west;
}

/*Se busca un objeto en el set del espacio*/
Id space_setget_object(Space *space, int position)
{/*Por: Miguel Ibáñez*/

  return set_findId(space->objects, position);
}

/*Busca si está un objeto con ese id en el set del espacio*/
BOOL space_setobject_Idcheck(Space *space, Id id)
{/*Por: Miguel Ibáñez*/

  if (set_Idcheck(space->objects, id) == TRUE)
  {
    return TRUE;
  }

  return FALSE;
}

/*Encuentra la posición del objeto en el set del espacio mediante el id*/
int space_setobject_getposition_fromID(Space *space, Id id)
{/*Por: Miguel Ibáñez*/
  int i;

  if (set_Idcheck(space->objects, id) == FALSE)
  {
    return -1;
  }

  for (i = 0; i < set_getnIds(space->objects); i++)
  {
    if (space_setget_object(space, i) == id)
    {
      return i;
    }
  }

  return -1;
}


/*Devuelve el número de ids en el set del espacio*/
int space_setgetIds(Space *space)
{/*Por: Miguel Ibáñez*/

  return set_getnIds(space->objects);
}

/*Devuelve una array de los ids de objetos en el espacio*/
Id *space_get_object(Space *space)
{/*Por: Sergio Hidalgo*/

  if (!space)
  {
    return NULL;
  }

  if (space->objects != NULL)
  {
    if (set_getArrayIds(space->objects) == NULL)
    {
      return NULL;
    }
    else
    {
      return set_getArrayIds(space->objects);
    }
  }
  return NULL;
}

/*Se imprime un espacio*/
STATUS space_print(Space *space, int position)
{/*Por: Sergio Hidalgo*/
  Id idaux = NO_ID;

  if (!space)
  {
    return ERROR;
  }

  fprintf(stdout, "--> Space (Id: %ld; Name: %s)\n", space->id, space->name);

  idaux = space_get_north(space);
  if (NO_ID != idaux)
  {
    fprintf(stdout, "---> North link: %ld.\n", idaux);
  }
  else
  {
    fprintf(stdout, "---> No north link.\n");
  }

  idaux = space_get_south(space);
  if (NO_ID != idaux)
  {
    fprintf(stdout, "---> South link: %ld.\n", idaux);
  }
  else
  {
    fprintf(stdout, "---> No south link.\n");
  }

  idaux = space_get_east(space);
  if (NO_ID != idaux)
  {
    fprintf(stdout, "---> East link: %ld.\n", idaux);
  }
  else
  {
    fprintf(stdout, "---> No east link.\n");
  }

  idaux = space_get_west(space);
  if (NO_ID != idaux)
  {
    fprintf(stdout, "---> West link: %ld.\n", idaux);
  }
  else
  {
    fprintf(stdout, "---> No west link.\n");
  }

  if (space_setobject_Idcheck(space, space_setget_object(space, position)) == TRUE)
  {
    fprintf(stdout, "---> Object in the space.\n");
  }
  else
  {
    fprintf(stdout, "---> No object in the space.\n");
  }

  return OK;
}
