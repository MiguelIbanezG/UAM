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

#define N_CALLBACK 9

/**
   Definición de las llamadas del juego
*/
typedef void (*callback_fn)(Game *game);

/**
   Listas de llamadas a los distintos comandos de juego 
*/
void game_callback_unknown(Game *game);
void game_callback_exit(Game *game);
void game_callback_next(Game *game);
void game_callback_back(Game *game);
void game_callback_take(Game *game);
void game_callback_roll(Game *game);
void game_callback_left(Game *game);
void game_callback_right(Game *game);
void game_callback_drop(Game *game);

static callback_fn game_callback_fn_list[N_CALLBACK] = {
    game_callback_unknown,
    game_callback_exit,
    game_callback_next,
    game_callback_back,
    game_callback_take,
    game_callback_roll,
    game_callback_left,
    game_callback_right,
    game_callback_drop};

/**
   Funciones privadas
*/

Id game_get_space_id_at(Game *game, int position);
STATUS game_set_player_location(Game *game, Id id);

/**
   Implementación de la interfaz del juego
*/

STATUS game_create(Game *game)
{
  int i;

  for (i = 0; i < MAX_SPACES; i++)
  {
    game->spaces[i] = NULL;
    game->objects[i] = NULL;
  }

  game->player = player_create(1);
  game->last_cmd = NO_CMD;
  game->die = die_create(1);

  return OK;
}

/*Se crea el juego a partir de un fichero*/
STATUS game_create_from_file(Game *game, char *filename) /*Editada por: Sergio Hidalgo*/
{

  if (game_create(game) == ERROR)
    return ERROR;

  if (gamereader_load_spaces(game, filename) == ERROR)
    return ERROR;

  if (gamereader_load_objects(game, filename) == ERROR)
    return ERROR;

  game_set_player_location(game, game_get_space_id_at(game, 0));

  gamereader_set_object_location(game, game_get_space_id_at(game, 0), object_get_id(game->objects[0]));
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
    object_destroy(game->objects[i]);
  }

  player_destroy(game->player);
  die_destroy(game->die);

  return OK;
}

/*Determina el id del espacio en el juego*/
Id game_get_space_id_at(Game *game, int position) /*Editada por: Sergio Hidalgo*/
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

/*Pide la ubicación del jugador en el tablero (modificada con funciones de player.c)*/
Id game_get_player_location(Game *game) /*Editada por: Miguel Ibáñez*/
{
  return player_get_location(game->player);
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
    space_print(game->spaces[i], i);
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

/*En esta el jugador avanza*/
void game_callback_next(Game *game)
{
  int i = 0;
  Id current_id = NO_ID;
  Id space_id = NO_ID;

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
      current_id = space_get_south(game->spaces[i]);
      if (current_id != NO_ID)
      {
        game_set_player_location(game, current_id); /*Se setea esa ubicación para el jugador*/
      }
      return;
    }
  }
}

/*En esta el jugador retrocede*/
void game_callback_back(Game *game)
{
  int i = 0;
  Id current_id = NO_ID;
  Id space_id = NO_ID;

  space_id = (long)game_get_player_location(game);

  if (NO_ID == space_id)
  {
    return;
  }

  for (i = 0; i < MAX_SPACES && game->spaces[i] != NULL; i++) /*Bucle en el que se busca el espacio del jugador y se seleciona el espacio anterior(norte)*/
  {
    current_id = space_get_id(game->spaces[i]);
    if (current_id == space_id)
    {
      current_id = space_get_north(game->spaces[i]);
      if (current_id != NO_ID)
      {
        game_set_player_location(game, current_id);
      }
      return;
    }
  }
}

/*En esta el jugador obtiene un objeto*/
void game_callback_take(Game *game) /*Creada por: Sergio Hidalgo*/
{
  int i = 0;

  Id space_id = NO_ID;

  space_id = game_get_player_location(game);

  for (i = 0; i < MAX_SPACES && game->spaces[i] != NULL; i++)
  {

    if (space_id == space_get_id(game->spaces[i])) /*Bucle que busca el espacio donde está el jugador*/
    {
      break;
    }
  }

  if (space_setobject_Idcheck(game->spaces[i], object_get_id(game->objects[0])) == FALSE) /*Mira si en el espacio hay un objeto*/
  {
    return;
  }

  /*Llamando a las siguientes funciones, se actualiza el objeto que lleva el jugador y se quita el objeto del tablero*/
  player_set_object(game->player, object_get_id(game->objects[0]));
  space_setDel_object(game->spaces[i], object_get_id(game->objects[0]));

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

/*Se mueve el jugador a la izquierda (este)*/
void game_callback_left(Game *game) /*Creada por: Miguel Ibáñez*/
{
  int i = 0;
  Id current_id = NO_ID;
  Id space_id = NO_ID;

  space_id = (long)game_get_player_location(game);

  if (NO_ID == space_id)
  {
    return;
  }

  for (i = 0; i < MAX_SPACES && game->spaces[i] != NULL; i++) /*Bucle en el que se busca el espacio del jugador y se seleciona el espacio de la izquierda*/
  {
    current_id = space_get_id(game->spaces[i]);
    if (current_id == space_id)
    {
      current_id = space_get_east(game->spaces[i]);
      if (current_id != NO_ID)
      {
        game_set_player_location(game, current_id);
      }
      return;
    }
  }
}

/*Se mueve el jugador a la derecha (oeste)*/
void game_callback_right(Game *game) /*Creada por: Miguel Ibáñez*/
{
  int i = 0;
  Id current_id = NO_ID;
  Id space_id = NO_ID;

  space_id = (Id)game_get_player_location(game);
  if (space_id == NO_ID)
  {
    return;
  }

  for (i = 0; i < MAX_SPACES && game->spaces[i] != NULL; i++) /*Bucle en el que se busca el espacio del jugador y se seleciona el espacio de la derecha*/
  {
    current_id = space_get_id(game->spaces[i]);
    if (current_id == space_id)
    {
      current_id = space_get_west(game->spaces[i]);
      if (current_id != NO_ID)
      {
        game_set_player_location(game, current_id);
      }
      return;
    }
  }
}

/*En esta el jugador suelta un objeto*/
void game_callback_drop(Game *game) /*Creada por Sergio Hidalgo*/
{

  int i;

  Id player_id = NO_ID;

  player_id = game_get_player_location(game);

  for (i = 0; i < MAX_SPACES && game->spaces[i] != NULL; i++)
  {

    if (space_setobject_Idcheck(game->spaces[i], player_get_object(game->player)) == TRUE)
    {
      return; /*Si el jugador no tiene objeto no podrá dropear nada y si lo tiene y está en el espacio (control de duplicados) tampoco*/
    }

    if (player_id == space_get_id(game->spaces[i])) /*Bucle que busca el espacio donde está el jugador*/
    {
      break;
    }
  }

  /*Llamando a las siguientes funciones, se actualiza el objeto que lleva el jugador y se pone en el tablero*/
  space_setAdd_object(game->spaces[i], player_get_object(game->player));
  player_set_object(game->player, NO_ID);

  return;
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