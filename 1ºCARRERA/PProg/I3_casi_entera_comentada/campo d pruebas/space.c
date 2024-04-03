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
  Link *north;
  Link *south;
  Link *east;
  Link *west;
  Set *objects;
  char gdesc[MAX_GDESC][MAX_STRING];
};

/*Crea un espacio y reserva su memoria*/
Space *space_create(Id id)
{/*Por: Miguel Ibáñez*/
  int i, j;


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

  newSpace->objects = set_create();

    for (i=0, j = 0; i<MAX_GDESC; i++){
     
      newSpace->gdesc[i][j] = '\0';
    }

  newSpace->north = NULL;
  newSpace->south = NULL;
  newSpace->east = NULL;
  newSpace->west = NULL;

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

  link_destroy(space->west);
  link_destroy (space->north);
  
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
STATUS space_set_north(Space *space, Link *link)
{/*Por: Miguel Ibáñez*/
  if (!space)
  {
    return ERROR;
  }

  space->north = link;

  return OK;
}

/*El espacio se coloca al sur*/
STATUS space_set_south(Space *space, Link *link)
{/*Por: Miguel Ibáñez*/
  if (!space)
  {
    return ERROR;
  }
  space->south = link;
  return OK;
}

/*El espacio se coloca al este*/
STATUS space_set_east(Space *space, Link *link)
{/*Por: Miguel Ibáñez*/
  if (!space)
  {
    return ERROR;
  }
  space->east = link;
  return OK;
}

/*El espacio se coloca al oeste*/
STATUS space_set_west(Space *space, Link *link)
{/*Por: Miguel Ibáñez*/
  if (!space)
  {
    return ERROR;
  }
  space->west = link;
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
/*Editado para ser usado implementando el módulo link por: Mario García*/
Id space_get_north(Space *space)
{/*Por: Miguel Ibáñez*/
  if (!space || space->north == NULL)
  {
    return NO_ID;
  }

  if (space->id == link_getSpace1Id (space->north)) /*Devolverá el valor que no sea el actual, es decir, el valor ligado a esa casilla*/
  {
    return link_getSpace2Id (space->north);
  }
  
  if (space->id == link_getSpace2Id (space->north))
  {
    return link_getSpace1Id (space->north);
  }

  return NO_ID;
}

Id space_get_south(Space *space) /*Devuelve la id del espacio con el que está conectado en south. Por: Mario García*/
{
  if (!space || space->south == NULL)
  {
    return NO_ID;
  }

  if (space->id == link_getSpace1Id (space->south))
  {
    return link_getSpace2Id (space->south);
  }
  
  if (space->id == link_getSpace2Id (space->south))
  {
    return link_getSpace1Id (space->south);
  }

  return NO_ID;
}

Id space_get_east(Space *space) /*Devuelve la id del espacio con el que está conectado en east. Por: Mario García*/
{
  if (!space || space->east == NULL)
  {
    return NO_ID;
  }

  if (space->id == link_getSpace1Id (space->east))
  {
    return link_getSpace2Id (space->east);
  }
  
  if (space->id == link_getSpace2Id (space->east))
  {
    return link_getSpace1Id (space->east);
  }

  return NO_ID;
}

Id space_get_west(Space *space) /*Devuelve la id del espacio con el que está conectado en west. Por: Mario García*/
{
  if (!space || space->west == NULL)
  {
    return NO_ID;
  }
  
  if (space->id == link_getSpace1Id (space->west))
  {
    return link_getSpace2Id (space->west);
  }
  
  if (space->id == link_getSpace2Id (space->west))
  {
    return link_getSpace1Id (space->west);
  }

  return NO_ID;
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

/*Devuelve el número de ids en el set del espacio*/
int space_setgetIds(Space *space)
{/*Por: Miguel Ibáñez*/
  if (!space) return -1;

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

STATUS space_set_gdesc(Space *space, char *gdesc, int position) 

{


  if (!space || !gdesc)
  {
    return ERROR;
  }
  
    strcpy(space->gdesc[position], gdesc); 
  

  return OK;
}

char *space_get_gdesc(Space *space, int position)
{
  if (!space)
  {
    return NULL;
  }

  return space->gdesc[position];
}

/*Se imprime un espacio*/
STATUS space_print(Space *space)
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

  fprintf (stdout, "Objects:\n");

  set_print(space->objects);


  fprintf (stdout, "Gdesc: ");


  return OK;
}
