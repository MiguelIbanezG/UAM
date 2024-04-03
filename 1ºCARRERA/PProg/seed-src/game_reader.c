/** 
 * @brief Implementa la lectura
 * del juego
 * 
 * @file game_reader.c
 * @author Miguel Ibáñez
 * @version 1.0 
 * @date 21-02-2021 
 * Editado y comentado por: Miguel Ibáñez
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "game_reader.h"

/*Carga los espacios de juego del tablero*/
STATUS gamereader_load_spaces(Game *game, char *filename)
{
  FILE *file = NULL;
  char line[WORD_SIZE] = "";
  char name[WORD_SIZE] = "";
  char *toks = NULL;
  Id id = NO_ID, north = NO_ID, east = NO_ID, south = NO_ID, west = NO_ID;
  Space *space = NULL;
  STATUS status = OK;

  if (!filename)
  {
    return ERROR;
  }

  file = fopen(filename, "r");
  if (file == NULL)
  {
    return ERROR;
  }

  while (fgets(line, WORD_SIZE, file))
  {
    if (strncmp("#s:", line, 3) == 0)
    {
      toks = strtok(line + 3, "|");
      id = atol(toks);
      toks = strtok(NULL, "|");
      strcpy(name, toks);
      toks = strtok(NULL, "|");
      north = atol(toks);
      toks = strtok(NULL, "|");
      east = atol(toks);
      toks = strtok(NULL, "|");
      south = atol(toks);
      toks = strtok(NULL, "|");
      west = atol(toks);
#ifdef DEBUG
      printf("Leido: %ld|%s|%ld|%ld|%ld|%ld\n", id, name, north, east, south, west);
#endif
      space = space_create(id);
      if (space != NULL)
      {
        space_set_name(space, name);
        space_set_north(space, north);
        space_set_east(space, east);
        space_set_south(space, south);
        space_set_west(space, west);
        game_add_space(game, space);
      }
    }
  }

  if (ferror(file))
  {
    status = ERROR;
  }

  fclose(file);

  return status;
}

STATUS gamereader_load_objects(Game *game, char *filename)
{ /*Se cargan los objetos a partir de un fichero por: Miguel Ibáñez*/
  FILE *file = NULL;
  char line[WORD_SIZE] = "";
  char name[WORD_SIZE] = "";
  char *toks = NULL;
  Id id = NO_ID, position = NO_ID;
  Object *object = NULL;
  STATUS status = OK;

  if (!filename)
  {
    return ERROR;
  }

  file = fopen(filename, "r");
  if (file == NULL)
  {
    return ERROR;
  }

  while (fgets(line, WORD_SIZE, file))
  {
    if (strncmp("#o:", line, 3) == 0)
    { /*Una vez abierto el fichero se leen los datos de los objetos*/
      toks = strtok(line + 3, "|");
      id = atol(toks);
      toks = strtok(NULL, "|");
      strcpy(name, toks);
      toks = strtok(NULL, "|");
      position = atol(toks);
#ifdef DEBUG
      printf("Leido: %ld|%s|%ld\n", id, name, position);
#endif
      object = object_create(id);
      if (object != NULL)
      {
        object_set_name(object, name);
        space_setAdd_object(game_get_space(game, position), id);
        game_add_object(game, object);
      }
    }
  }

  if (ferror(file))
  {
    status = ERROR;
  }

  fclose(file);

  return status;
}

/*Determina la ubicación en el tablero de un objeto */
STATUS gamereader_set_object_location(Game *game, Id id_space, Id id_object)
{

  int i;

  for (i = 0; i < MAX_SPACES && game->spaces[i] != NULL; i++)
  {
    if (space_get_id(game->spaces[i]) == id_space)
    {
      space_setAdd_object(game->spaces[i], id_object); /*Se repite un bucle y en caso de coincida la id del objeto con la*/
                                                       /*id del espacio, se coloca en este*/
      return OK;
    }
  }
  return ERROR;
}