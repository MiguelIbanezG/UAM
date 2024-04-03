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
  char *toks = NULL;
  Id id = NO_ID;
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
      toks = strtok(NULL, "|");
      toks = strtok(NULL, "|");
      toks = strtok(NULL, "|");
      toks = strtok(NULL, "|");
      strcpy(gdesc0, toks);
      toks = strtok(NULL, "|");
      strcpy(gdesc1, toks);
      toks = strtok(NULL, "|");
      strcpy(gdesc2, toks);
      toks = strtok(NULL, "|");

#ifdef DEBUG
      printf("Leido: %ld|%s|%ld|%ld|%ld|%ld\n", id, name, north, east, south, west);
#endif
      space = space_create(id);
      if (space != NULL)
      {
        space_set_name(space, name);
        game_add_space(game, space);
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
      toks = strtok(NULL, "|");
#ifdef DEBUG
      printf("Leido: %ld|%s|%ld\n", id, name, position);
#endif
      object = object_create(id);
      if (object != NULL)
      {
        object_set_name(object, name);
        space_setAdd_object(game_get_space(game, position), id);
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
  Space *space1, *space2;

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

      link = link_create();
      if (link != NULL)
      {
        link_setId(link, id);   /*Seteo de los valores del link*/
        link_setName(link, name);
        link_setIdSpace1(link, space1_id);
        link_setIdSpace2(link, space2_id);

        if (connection == 1)
        {
          link_newConnection(link, space1_id, space2_id); /*comprobación y creación de una conexión*/
        }

        space1 = game_get_space(game, space1_id);
        space2 = game_get_space(game, space2_id);

        if (space1_id - space2_id == -1)  /*Si solo se diferencian en una posición por el id, será un link de norte/sur*/
        {
          space_set_south(space1, link);
          space_set_north(space2, link);
        }
        else if (space1_id - space2_id == -8) /*Si se diferencian por 8 posiciones serán de tipo este/oeste*/
        {
          space_set_east(space2, link);
          space_set_west(space1, link);
        }
        else if (space1_id - space2_id == -4)
        {
          space_set_west(space1, link); /*si es por 4 será tipo oeste*/
        }
        else
        {
          space_set_east(space1, link); /*en caso de que sea cualquier otro (casilla de muerte) será por este/oeste de una dirección*/
          space_set_west(space1, link);

        }
        
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
