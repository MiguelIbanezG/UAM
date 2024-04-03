/** 
 * @brief It implements the game interface and all the associated callbacks
 * for each command
 * 
 * @file game.c
 * @author Profesores PPROG
 * @version 1.0 
 * @date 13-01-2015 
 * @copyright GNU Public License
 * Editado y comentado por: Sergio Hidalgo
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "game.h"
#include "types.h"
#include "game_reader.h"
#include "set.h"
#include "link.h"

#define N_CALLBACK 10

/*Estructura de tipo "Game" que declara tanto la posición del jugador como la del objeto y la del espacio*/
typedef struct _Game
{
  Player *player;
  Object *objects[MAX_OBJECTS + 1];
  Space *spaces[MAX_SPACES + 1];
  Link *links[MAX_LINKS + 1];
  Die *die;
  char description[WORD_SIZE];
  char name_space[WORD_SIZE];
  T_Command last_cmd;
} game;

/**
   Definición de las llamadas del juego
*/
typedef void (*callback_fn)(Game *game);

/**
   Listas de llamadas a los distintos comandos de juego 
*/
void game_callback_unknown(Game *game);
void game_callback_exit(Game *game);
void game_callback_move(Game *game);
void game_callback_take(Game *game);
void game_callback_roll(Game *game);
void game_callback_drop(Game *game);
void game_callback_inspect(Game *game);
void game_callback_turnon(Game *game);
void game_callback_turnoff(Game *game);
void game_callback_open(Game *game);

static callback_fn game_callback_fn_list[N_CALLBACK] = {
    game_callback_unknown,
    game_callback_exit,
    game_callback_move,
    game_callback_take,
    game_callback_roll,
    game_callback_drop,
    game_callback_inspect,
    game_callback_turnon,
    game_callback_turnoff,
    game_callback_open
    };

/**
   Funciones privadas
*/

Id game_get_space_id_at(Game *game, int position);
BOOL game_movable(Game *game, Object *object);
BOOL game_dependency(Game *game, Object *object);
BOOL game_connection_check(Game *game, Id id);

/**
   Implementación de la interfaz del juego
*/

STATUS game_create(Game *game)
{
  int i;

  for (i = 0; i < MAX_SPACES; i++)
  {
    game->spaces[i] = NULL;
  }

  for (i = 0; i < MAX_OBJECTS; i++)
  {
    game->objects[i] = NULL;
  }

  for (i = 0; i < MAX_LINKS; i++)
  {
    game->links[i] = NULL;
  }

  game->player = NULL;
  game->last_cmd = NO_CMD;
  game->die = die_create(1, 1, 6);
  strcpy(game->description, "");
  strcpy(game->name_space, "");

  return OK;
}

Game *game_init()
{
  Game *game = NULL;

  game = (Game *)malloc(sizeof(Game));

  if (!game)
  {
    return NULL;
  }

  return game;
}

/*Se crea el juego a partir de un fichero*/
STATUS game_create_from_file(Game *game, char *filename) /*Editada por: Sergio Hidalgo*/
{

  if (game_create(game) == ERROR)
    return ERROR;

  if (game_reader_load_spaces(game, filename) == ERROR)
    return ERROR;

  if (game_reader_load_objects(game, filename) == ERROR)
    return ERROR;

  if (game_reader_load_players(game, filename) == ERROR)
    return ERROR;

  if (game_reader_load_link(game, filename) == ERROR)
    return ERROR;

  /*Esta última función está en desarrollo, porque el id del objeto dependerá del fichero y falta cambiar el graphic_engine,*/
  /*así que cambiarla no tiene mucho sentido ahora mismo*/

  return OK;
}

/*Destruye el juego*/
STATUS game_destroy(Game *game) /*Editada por: Miguel Ibáñez*/
{
  int i = 0;

  for (i = 0; (i < MAX_SPACES) && (game->spaces[i] != NULL); i++)
  {

    space_destroy(game->spaces[i]);
  }

  for (i = 0; (i < MAX_OBJECTS) && (game->objects[i] != NULL); i++)
  {

    object_destroy(game->objects[i]);
  }

  for (i = 0; (i < MAX_LINKS) && (game->links[i] != NULL); i++)
  {

    link_destroy(game->links[i]);
  }

  player_destroy(game->player);
  die_destroy(game->die);

  free(game);

  return OK;
}

Object *game_get_objects(Game *game, int position) /*Devuelve el objeto de la posición que reciba. Por: Mario García*/
{
  if (game == NULL)
  {
    return NULL;
  }

  return game->objects[position];
}

Die *game_get_die(Game *game) /*Devuelve el puntero al dado de game. Por: Mario García*/
{
  if (game == NULL)
  {
    return NULL;
  }

  return game->die;
}

Player *game_get_player(Game *game) /*Devuelve el puntero a jugador de game. Por: Mario García*/
{
  if (game == NULL)
  {
    return NULL;
  }

  return game->player;
}

/*Determina el id del espacio en el juego*/
Id game_get_space_id_at(Game *game, int position) /*Editada por: Sergio Hidalgo. */
{

  if ((position < 0) || (position >= MAX_SPACES))
  {
    return NO_ID;
  }

  return space_get_id(game->spaces[position]);
}

/*Pide los espacios del tablero de juego*/
Space *game_get_space(Game *game, Id id) /*Editada por: Miguel Ibáñez*/
{
  int i = 0;

  if (id == NO_ID)
  {
    return NULL;
  }

  for (i = 0; i < MAX_SPACES && game->spaces[i] != NULL; i++)
  {
    if (id == space_get_id(game->spaces[i]))
    {
      return game->spaces[i];
    }
  }

  return NULL;
}

Link *game_get_link(Game *game, Id id) /*Creada por: Miguel Ibáñez*/
{
  int i = 0;

  if (id == NO_ID)
  {
    return NULL;
  }

  for (i = 0; i < MAX_LINKS && game->links[i] != NULL; i++)
  {
    if (id == link_getId(game->links[i]))
    {
      return game->links[i];
    }
  }

  return NULL;
}

Object *game_get_object(Game *game, Id id) /*Editada por: Miguel Ibáñez*/
{
  int i = 0;

  if (id == NO_ID)
  {
    return NULL;
  }

  for (i = 0; i < MAX_OBJECTS && game->objects[i] != NULL; i++)
  {
    if (id == object_get_id(game->objects[i]))
    {
      return game->objects[i];
    }
  }

  return NULL;
}

/*Pide la ubicación del jugador en el tablero (modificada con funciones de player.c)*/
Id game_get_player_location(Game *game) /*Editada por: Miguel Ibáñez*/
{
  return player_get_location(game->player);
}

BOOL game_movable(Game *game, Object *object)
{
  if (game == NULL || object == NULL)
  {
    return FALSE;
  }

  if (object_get_movable(object) == FALSE)
  {
    return TRUE;
  }

  return FALSE;
}

BOOL game_dependency(Game *game, Object *object)
{
  if (game == NULL || object == NULL)
  {
    return FALSE;
  }

  if (player_check_inventory(game->player, object_get_dependency(object)) == FALSE && object_get_dependency(object) != NO_ID)
  {
    return TRUE;
  }

  return FALSE;
}

BOOL game_connection_check(Game *game, Id id)
{
  if (game == NULL || id == NO_ID)
  {
    return FALSE;
  }

  return link_getConnection(game_get_link(game, id));
}

/*Pide la ubicación de un objeto*/
Id game_get_object_location(Game *game, Id id_object) /*Editada por: Sergio Hidalgo*/
{

  int i;

  for (i = 0; i < MAX_SPACES && game->spaces[i] != NULL; i++)
  {

    if (space_setobject_Idcheck(game->spaces[i], id_object) == TRUE)
    { /*Se repite un bucle y en caso de coincida la id del objeto con el*/
      /*objeto en el espacio en cuestion, se obtiene el id del espacio*/
      return space_get_id(game->spaces[i]);
    }
  }

  return NO_ID;
}

/*Refresca el estado de juego*/
STATUS game_update(Game *game, T_Command cmd)
{
  game->last_cmd = cmd;
  (*game_callback_fn_list[cmd])(game);
  return OK;
}

/*Determina la ubicación en el tablero de un objeto */
STATUS game_set_object_location(Game *game, Id id_space, Id id_object)
{

  int i;

  for (i = 0; i < MAX_SPACES && game->spaces[i] != NULL; i++)
  {
    if (space_get_id(game->spaces[i]) == id_space)
    {
      space_setAdd_object(game->spaces[i], id_object); /*Se repite un bucle y en caso de que coincida la id del objeto con la*/
                                                       /*id del espacio, se coloca en este*/
      return OK;
    }
  }
  return ERROR;
}

/*Selecciona la ubicación del jugador en el tablero de juego (modificada con funciones de player.c)*/
STATUS game_set_player_location(Game *game, Id id) /*Editada por: Sergio Hidalgo*/
{

  if (id == NO_ID)
  {
    return ERROR;
  }

  player_set_location(game->player, id);

  return OK;
}

/*Pide el último comando*/
T_Command game_get_last_command(Game *game)
{
  return game->last_cmd;
}

/*Imprime por pantalla los datos de juego */
void game_print_data(Game *game) /*Editada por: Miguel Ibáñez*/
{
  int i = 0;

  printf("\n\n-------------\n\n");

  printf("=> Spaces: \n");
  for (i = 0; i < MAX_SPACES && game->spaces[i] != NULL; i++)
  {
    space_print(game->spaces[i]);
  }

  printf("=> Object location: %d\n", (int)game_get_object_location(game, object_get_id(game->objects[space_setgetIds(game->spaces[i])])));
  printf("=> Player location: %d\n", (int)game_get_player_location(game));
  printf("prompt:> ");
}

/*Finaliza el juego*/
BOOL game_is_over(Game *game)
{
  return FALSE;
}

/**
   Implementación de las llamadas por cada acción 
*/

void game_callback_unknown(Game *game)
{
}

void game_callback_exit(Game *game)
{
}

void game_callback_move(Game *game)
{
  int i = 0;
  Id current_id = NO_ID;
  Id space_id = NO_ID;
  char name_move[15];

  scanf(" %s", name_move);

  space_id = (Id)game_get_player_location(game);
  if (space_id == NO_ID)
  {
    return;
  }

  for (i = 0; i < MAX_SPACES && game->spaces[i] != NULL; i++) /*Bucle en el que se busca el espacio del jugador y se seleciona el siguiente espacio (sur)*/
  {
    current_id = space_get_id(game->spaces[i]);
    if (current_id == space_id)
    {
      if (strncmp(name_move, "north", 5) == 0 || strncmp(name_move, "n", 1) == 0)
      {
        if (game_connection_check(game, space_get_north(game->spaces[i])) == TRUE)
        {
          return;
        }

        current_id = link_getSpace1Id(game_get_link(game, space_get_north(game->spaces[i])));
      }
      else if (strncmp(name_move, "south", 5) == 0 || strncmp(name_move, "s", 1) == 0)
      {
        if (game_connection_check(game, space_get_south(game->spaces[i])) == TRUE)
        {
          return;
        }
        current_id = link_getSpace2Id(game_get_link(game, space_get_south(game->spaces[i])));
      }
      else if (strncmp(name_move, "east", 4) == 0 || strncmp(name_move, "e", 1) == 0)
      {
        if (game_connection_check(game, space_get_east(game->spaces[i])) == TRUE)
        {
          return;
        }
        current_id = link_getSpace2Id(game_get_link(game, space_get_east(game->spaces[i])));
      }
      else if (strncmp(name_move, "west", 4) == 0 || strncmp(name_move, "w", 1) == 0)
      {
        if (game_connection_check(game, space_get_west(game->spaces[i])) == TRUE)
        {
          return;
        }
        current_id = link_getSpace1Id(game_get_link(game, space_get_west(game->spaces[i])));
      }
      else if (strncmp(name_move, "up", 2) == 0 || strncmp(name_move, "u", 1) == 0)
      {
        if (game_connection_check(game, space_get_up(game->spaces[i])) == TRUE)
        {
          return;
        }
        current_id = link_getSpace2Id(game_get_link(game, space_get_up(game->spaces[i])));
      }
      else if (strncmp(name_move, "down", 4) == 0 || strncmp(name_move, "d", 1) == 0)
      {
        if (game_connection_check(game, space_get_down(game->spaces[i])) == TRUE)
        {
          return;
        }
        current_id = link_getSpace1Id(game_get_link(game, space_get_down(game->spaces[i])));
      }

      if (current_id != NO_ID)
      {
        game_set_player_location(game, current_id); /*Se setea esa ubicación para el jugador*/
      }
      return;
    }
  }
}

/*En esta el jugador obtiene un objeto*/
void game_callback_take(Game *game) /*Creada por: Sergio Hidalgo*/
{
  int i = 0;
  char name_object[10];
  Id space_id = NO_ID;
  Id object_id = NO_ID;
  scanf(" %s", name_object);

  space_id = game_get_player_location(game);

  if (space_setgetIds(game_get_space(game, space_id)) == 0)
  {
    return;
  }

  for (i = 0; i < MAX_OBJECTS; i++)
  {
    if (game->objects[i] != NULL)
    {
      if (strcmp(object_get_name(game->objects[i]), name_object) == 0)
      {
        object_id = object_get_id(game->objects[i]);
        break;
      }
    }
  }

  if (game_movable(game, game->objects[i]) == TRUE)
  {
    return;
  }

  if (game_dependency(game, game->objects[i]) == TRUE)
  {
    return;
  }

  for (i = 0; i < MAX_SPACES && game->spaces[i] != NULL; i++)
  {

    if (space_id == space_get_id(game->spaces[i])) /*Bucle que busca el espacio donde está el jugador*/
    {
      break;
    }
  }

  if (space_setobject_Idcheck(game->spaces[i], object_id) == FALSE)
  {
    return;
  }

  /*Llamando a las siguientes funciones, se actualiza el objeto que lleva el jugador y se quita el objeto del tablero*/

  if (player_set_addObject(game->player, object_id) == ERROR)
  {
    player_set_delObject(game->player, object_id);
    return;
  }

  space_setDel_object(game->spaces[i], object_id);

  return;
}

/*Se tira el dado*/
void game_callback_roll(Game *game) /*Creada por: Miguel Ibáñez*/
{
  if (!game)
  {
    return;
  }

  die_roll(game->die);
  return;
}

/*En esta el jugador suelta un objeto*/
void game_callback_drop(Game *game) /*Creada por Sergio Hidalgo*/
{

  int i;
  char name_object[10];
  Id player_id = NO_ID;
  Id object_id = NO_ID;
  scanf(" %s", name_object);

  player_id = game_get_player_location(game);

  for (i = 0; i < MAX_OBJECTS; i++)
  {
    if (strcmp(object_get_name(game->objects[i]), name_object) == 0)
    {
      object_id = object_get_id(game->objects[i]);
      break;
    }
  }

  for (i = 0; i < MAX_SPACES && game->spaces[i] != NULL; i++)
  {

    if (player_id == space_get_id(game->spaces[i])) /*Bucle que busca el espacio donde está el jugador*/
    {
      break;
    }
  }

  if (object_get_open(game->objects[i]) != NO_ID)
  {
    Link_setConnection(game_get_link(game, object_get_open(game->objects[i])), FALSE);
  }

  /*Llamando a las siguientes funciones, se actualiza el objeto que lleva el jugador y se pone en el tablero*/
  space_setAdd_object(game->spaces[i], object_id);
  player_set_delObject(game->player, object_id);

  return;
}

void game_callback_inspect(Game *game)
{
  int i;
  Id player_id;
  char name[WORD_SIZE];
  scanf(" %s", name);

  player_id = game_get_player_location(game);

  if (strncmp(name, "space", 5) == 0 || strncmp(name, "s", 1) == 0)
  {
    for (i = 0; i < MAX_SPACES && game->spaces[i] != NULL; i++)
    {

      if (player_id == space_get_id(game->spaces[i])) /*Bucle que busca el espacio donde está el jugador*/
      {
        break;
      }
    }

    if (space_get_light(game->spaces[i]) == FALSE)
    {
      return;
    }

    strcpy(game->description, (char *)space_get_descr(game->spaces[i]));
    return;
  }

  for (i = 0; i < MAX_OBJECTS; i++)
  {

    if (game->objects[i] != NULL)
    {
      if (strcmp(object_get_name(game->objects[i]), name) == 0)
      {

        strcpy(game->description, object_getDescription(game->objects[i]));
        return;
      }
    }
  }

  return;
}

void game_callback_turnon(Game *game)
{
  int i;
  char name[10];
  scanf(" %s", name);

  for (i = 0; i < MAX_OBJECTS; i++)
  {
    if (strcmp(name, object_get_name(game->objects[i])) == 0)
    {
      break;
    }
  }

  if (object_get_illuminate(game->objects[i]) == FALSE)
  {
    return;
  }
  else
  {
    object_set_turnedon(game->objects[i], 1);
    space_set_light(game_get_space(game, game_get_object_location(game, object_get_id(game->objects[i]))), 1);
    return;
  }
}

void game_callback_turnoff(Game *game)
{
  int i;
  char name[10];
  scanf(" %s", name);

  for (i = 0; i < MAX_OBJECTS; i++)
  {
    if (strcmp(name, object_get_name(game->objects[i])) == 0)
    {
      break;
    }
  }

  if (object_get_illuminate(game->objects[i]) == FALSE)
  {
    return;
  }

  object_set_turnedon(game->objects[i], 0);
  space_set_light(game_get_space(game, game_get_object_location(game, object_get_id(game->objects[i]))), 0);

  return;
}

char *game_get_lastObject_description(Game *game)
{
  if (!game)
    return NULL;

  return game->description;
}

void game_callback_open(Game *game)
{
  int i, j;

  char name_lnk[20] = "";
  char name_obj[20] = "";
  char aux[20] = "";

  scanf (" %s", name_lnk);
  scanf (" %s", aux);
  scanf (" %s", name_obj);

  for (i = 0; i < MAX_LINKS; i++)
  {
    if (game->links[i] == NULL)
    {
      return;
    }
    if (strcmp(name_lnk, link_getName(game->links[i])) == 0)
    {
      break;
    }
  }

  for (j = 0; j < MAX_OBJECTS; j++)
  {
    if (game->objects[i] == NULL)
    {
      return;
    }
    if (strcmp(name_obj, object_get_name(game->objects[j])) == 0)
    {
      break;
    }
  }

  if (object_get_open(game->objects[j]) != link_getId(game->links[i]))
  {
    return;
  }

  Link_setConnection(game->links[i], FALSE);
  player_set_delObject(game->player, object_get_id(game->objects[j]));
  return;
}

STATUS game_add_player(Game *game, Player *player) /*Añade un jugador recibiendo el puntero a éste. Por: Sergio Hidalgo*/
{

  if (player == NULL)
  {
    return ERROR;
  }

  game->player = player;

  return OK;
}

/*Se añaden espacios al tablero de juego*/
STATUS game_add_space(Game *game, Space *space)
{
  int i = 0;

  if (space == NULL)
  {
    return ERROR;
  }

  while ((i < MAX_SPACES) && (game->spaces[i] != NULL))
  {
    i++;
  }

  if (i >= MAX_SPACES)
  {
    return ERROR;
  }

  game->spaces[i] = space;

  return OK;
}

/*Se obtiene la posición en la array de espacios*/
int game_space_get_position_fromId(Game *game, Id id) /*Por: Sergio Hidalgo*/
{
  int i;

  for (i = 0; i < MAX_SPACES; i++)
  {
    if (space_get_id(game->spaces[i]) == id)
    {
      return i;
    }
  }

  return -1;
}

/*Se obtiene el resultado de la última tirada*/
int game_last_roll(Game *game) /*Por: Miguel Ibáñez*/
{
  if (!(game->die))
  {
    return -1;
  }

  return die_lastroll(game->die);
}

/*Se añade un objeto a la array de objetos*/
STATUS game_add_object(Game *game, Object *object) /*Por: Sergio Hidalgo*/
{
  int i = 0;

  if (object == NULL)
  {
    return ERROR;
  }

  while (game->objects[i] != NULL) /*Mientras haya un objeto en esa posición se sumara 1 en la i (identificador de posición)*/
  {
    i++;
  }

  if (i >= MAX_SPACES)
  {
    return ERROR;
  }

  game->objects[i] = object;

  return OK;
}

/*Se añade un objeto a la array de links*/
STATUS game_add_link(Game *game, Link *link) /*Por: Sergio Hidalgo*/
{
  int i = 0;

  if (link == NULL)
  {
    return ERROR;
  }

  while (game->links[i] != NULL) /*Mientras haya un objeto en esa posición se sumara 1 en la i (identificador de posición)*/
  {
    i++;
  }

  if (i >= MAX_LINKS)
  {
    return ERROR;
  }

  game->links[i] = link;

  return OK;
}