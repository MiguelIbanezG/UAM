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
#include "space.h"
#include "link.h"

/*Carga los espacios de juego del tablero*/
STATUS game_reader_load_spaces(Game *game, char *filename)
{
  FILE *file = NULL;
  char line[WORD_SIZE] = "";
  char name[WORD_SIZE] = "";
  char descr[WORD_SIZE] = "";
  int light;
  char *toks = NULL;
  Id id = NO_ID, north = NO_ID, east = NO_ID, south = NO_ID, west = NO_ID, up = NO_ID, down = NO_ID;
  Space *space = NULL;
  STATUS status = OK;
  char gdesc0[MAX_STRING] = "", gdesc1[MAX_STRING] = "", gdesc2[MAX_STRING] = "";

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
      strcpy(descr, toks);
      toks = strtok(NULL, "|");
      north = atol(toks);
      toks = strtok(NULL, "|");
      east = atol(toks);
      toks = strtok(NULL, "|");
      south = atol(toks);
      toks = strtok(NULL, "|");
      west = atol(toks);
      toks = strtok(NULL, "|");
      up = atol(toks);
      toks = strtok(NULL, "|");
      down = atol(toks);
      toks = strtok(NULL, "|");
      light = atol(toks);
      toks = strtok(NULL, "|");
      strcpy(gdesc0, toks);
      toks = strtok(NULL, "|");
      strcpy(gdesc1, toks);
      toks = strtok(NULL, "|");
      strcpy(gdesc2, toks);
      toks = strtok(NULL, "|");

#ifdef DEBUG
      printf("Leido: %ld|%s|%s|%ld|%ld|%ld|%ld|%ld|%ld|%d\n", id, name, descr, north, east, south, west, up, down, light);
#endif
      space = space_create(id);
      if (space != NULL)
      {
        space_set_name(space, name);
        space_set_descr(space, descr);
        game_add_space(game, space);
        space_set_north(space, north);
        space_set_east(space, east);
        space_set_south(space, south);
        space_set_west(space, west);
        space_set_up(space, up);
        space_set_down(space, down);
        space_set_light(space, light);
        space_set_gdesc(space, gdesc0, 0);
        space_set_gdesc(space, gdesc1, 1);
        space_set_gdesc(space, gdesc2, 2);
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

STATUS game_reader_load_objects(Game *game, char *filename)
{ /*Se cargan los objetos a partir de un fichero por: Miguel Ibáñez*/
  FILE *file = NULL;
  char line[WORD_SIZE] = "";
  int movable, illuminate, turnedon;
  char name[WORD_SIZE] = "";
  char description[WORD_SIZE] = "";
  char *toks = NULL;
  Id id = NO_ID, position = NO_ID, dependency = NO_ID, open = NO_ID;
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
      toks = strtok(NULL, "|");
      strcpy(description, toks);
      toks = strtok(NULL, "|");
      movable = atol(toks);
      toks = strtok(NULL, "|");
      dependency = atol(toks);
      toks = strtok(NULL, "|");
      open = atol(toks);
      toks = strtok(NULL, "|");
      illuminate = atol(toks);
      toks = strtok(NULL, "|");
      turnedon = atol(toks);
      toks = strtok(NULL, "|");

#ifdef DEBUG
      printf("Leido: %ld|%ld|%s|%s|%d|%ld|%ld|%d|%d\n", id, name, position, description, movable, dependency, open, illuminate, turnedon);
#endif
      object = object_create(id);
      if (object != NULL)
      {
        object_set_name(object, name);
        object_setDescription(object, description);
        object_set_movable(object, movable);
        object_set_dependency(object, dependency);
        object_set_open(object, open);
        object_set_illuminate(object, illuminate);
        if (illuminate == 1)
        {
          object_set_turnedon(object, turnedon);
        }

        game_add_object(game, object);
        game_set_object_location(game, position, id);
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

STATUS game_reader_load_players(Game *game, char *filename)
{ /*Se cargan los jugadores a partir de un fichero por: Mario García*/
  FILE *file = NULL;
  char line[WORD_SIZE] = "";
  char name[WORD_SIZE] = "";
  char *toks = NULL;
  int max_objects;
  Id id = NO_ID, position = NO_ID;
  Player *player = NULL;
  STATUS status = OK;

  if (!filename)
    return ERROR;

  file = fopen(filename, "r");
  if (file == NULL)
  {
    return ERROR;
  }

  while (fgets(line, WORD_SIZE, file))
  {
    if (strncmp("#p:", line, 3) == 0) /*Se leen cada columna del player en el data.dat inicializándolo a cada valor*/
    {
      toks = strtok(line + 3, "|");
      id = atol(toks);
      toks = strtok(NULL, "|");
      strcpy(name, toks);
      toks = strtok(NULL, "|");
      position = atol(toks);
      toks = strtok(NULL, "|");
      max_objects = atoi(toks);
      toks = strtok(NULL, "|");

#ifdef DEBUG
      printf("Leido: %ld|%s|%ld|%d\n", id, name, position, max_objects);
#endif

      player = player_create(id);
      if (player != NULL) /*Se cambian los valores del player y se mete el player a game*/
      {
        player_set_name(player, name);
        player_set_Inventorymax(player, max_objects);
        game_add_player(game, player);
        game_set_player_location(game, position);
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

STATUS game_reader_load_link(Game *game, char *filename)
{ /*Carga los links desde un fichero de datos por: Sergio Hidalgo*/
  FILE *file = NULL;
  char line[WORD_SIZE] = "";
  char name[WORD_SIZE] = "";
  char *toks = NULL;
  BOOL connection;
  Id id = NO_ID, space1_id = NO_ID, space2_id = NO_ID;
  Link *link = NULL;
  STATUS status = OK;

  if (!filename)
    return ERROR;

  file = fopen(filename, "r");
  if (file == NULL)
  {
    return ERROR;
  }

  while (fgets(line, WORD_SIZE, file))
  {
    if (strncmp("#l:", line, 3) == 0) /*Lectura de los valores del link*/
    {
      toks = strtok(line + 3, "|");
      id = atol(toks);
      toks = strtok(NULL, "|");
      strcpy(name, toks);
      toks = strtok(NULL, "|");
      space1_id = atol(toks);
      toks = strtok(NULL, "|");
      space2_id = atol(toks);
      toks = strtok(NULL, "|");
      connection = atoi(toks);
      toks = strtok(NULL, "|");
#ifdef DEBUG
      printf("Leido: %ld|%s|%ld|%d\n", id, space1, space2, connection);
#endif

      link = link_create(id);
      if (link != NULL)
      {
        link_setName(link, name);
        link_setIdSpace1(link, space1_id);
        link_setIdSpace2(link, space2_id);
        Link_setConnection(link, connection);
        game_add_link(game, link);
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
