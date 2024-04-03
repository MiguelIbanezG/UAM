/** 
 * @brief Implementa los jugadores en el juego
 * 
 * @file player.c
 * @author Miguel Ibáñez
 * @version 1.0 
 * @date 25-02-2021 
 * Editado y comentado por: Miguel Ibáñez
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "player.h"

/*Estructura player*/
struct _Player
{
  Id id;
  char name[WORD_SIZE + 1];
  Id location;
  Id object;
};

/*Destruye un jugador y libera su memoria*/
STATUS player_destroy(Player *player)
{ /*Por: Miguel Ibáñez*/
  if (!player)
  {
    return ERROR;
  }

  free(player);
  player = NULL;

  return OK;
}

/*Crea un jugador y reserva su memoria*/
Player *player_create(Id id)
{ /*Por: Miguel Ibáñez*/

  Player *newPlayer = NULL;

  if (id == NO_ID)
    return NULL;

  newPlayer = (Player *)malloc(sizeof(Player));

  if (newPlayer == NULL)
  {
    return NULL;
  }
  newPlayer->id = id;

  newPlayer->name[0] = '\0';

  newPlayer->object = NO_ID;

  newPlayer->location = NO_ID;

  return newPlayer;
}

/*Le da un nombre al jugador*/
STATUS player_set_name(Player *player, char *name)
{
  if (!player || !name)
  { /*Por: Miguel Ibáñez*/
    return ERROR;
  }

  if (!strcpy(player->name, name))
  {
    return ERROR;
  }

  return OK;
}

/*Se coloca un objeto en ese jugador*/
STATUS player_set_object(Player *player, Id value)
{
  if (!player)
  { /*Por: Miguel Ibáñez*/
    return ERROR;
  }
  player->object = value;
  return OK;
}

/*Se pide el nombre del jugador*/
const char *player_get_name(Player *player)
{
  if (!player)
  { /*Por: Miguel Ibáñez*/
    return NULL;
  }
  return player->name;
}

/*Se pide la id del jugador*/
Id player_get_id(Player *player)
{
  if (!player)
  { /*Por: Miguel Ibáñez*/
    return NO_ID;
  }
  return player->id;
}

/*Para saber si el jugador tiene un objeto y cual es*/
Id player_get_object(Player *player)
{
  if (!player)
  { /*Por: Miguel Ibáñez*/
    return NO_ID;
  }
  return player->object;
}

/*Cambia la localización del jugador*/
STATUS player_set_location(Player *player, Id value)
{
  if (!player)
  { /*Por: Miguel Ibáñez*/
    return ERROR;
  }
  player->location = value;
  return OK;
}

/*Pide la localización del jugador*/
Id player_get_location(Player *player)
{
  if (!player)
  { /*Por: Miguel Ibáñez*/
    return NO_ID;
  }
  return player->location;
}

/*Se imprime un objeto*/
STATUS player_print(Player *player)
{ /*Por: Miguel Ibáñez*/

  if (!player)
  {
    return ERROR;
  }

  fprintf(stdout, "--> Object (Id: %ld; Name: %s, Location: %ld, Object: %ld)\n", player->id, player->name, player->location, player->object);

  return OK;
}