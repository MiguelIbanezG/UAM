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
#include "inventory.h"

/*Estructura player*/
struct _Player
{
  Id id;
  char name[WORD_SIZE + 1];
  Id location;
  Bag* bag;
};

/*Destruye un jugador y libera su memoria*/
STATUS player_destroy(Player *player)
{ /*Por: Miguel Ibáñez*/
  if (!player)
  {
    return ERROR;
  }

  inventory_destroy (player->bag);

  free(player);
  player = NULL;

  return OK;
}

Player *player_init () /*Inicializa el player. Por: Miguel Ibáñez ESTO ESTA MAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAL MUY MAL HORRIBLE */ 
{
  Player *player = NULL;

  player = (Player*)malloc(sizeof(Player));

  if(!player)
  {
    return NULL;
  }

  return player;
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

  newPlayer->location = NO_ID;

  newPlayer->bag = inventory_create();

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
STATUS player_set_addObject(Player *player, Id value)
{
  if (!player || value == NO_ID)
  { /*Por: Miguel Ibáñez*/
    return ERROR;
  }
  
  
  if ( inventory_set_addId(player->bag, value) == ERROR)
  {
    return ERROR;
  }
  

  return OK;
}

/*Se elimina un objeto en ese jugador*/
STATUS player_set_delObject(Player *player, Id value)
{
  if (!player || value == NO_ID)
  { /*Por: Miguel Ibáñez*/
    return ERROR;
  }
  
  if (inventory_set_delId(player->bag, value) == ERROR);

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

/*Cambia la localización del jugador*/
STATUS player_set_location(Player *player, Id value)
{
  if (!player || value == NO_ID)
  { /*Por: Miguel Ibáñez*/
    return ERROR;
  }
  player->location = value;
  return OK;
}

STATUS player_set_Inventorymax (Player* player, int num) /*Establece el máximo de objetos que puede llevar el jugador por: Mario García*/
{
  if (player == NULL || num < 0)
  {
    return ERROR;
  }

  inventory_setMax (player->bag, num);

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

int player_get_Inventorytam (Player *player) /*Devuelve el tamaño del inventario por: Sergio Hidalgo*/
{
  if (player == NULL)
  {
    return 0;
  }
  

  return inventory_getTam (player->bag);
}

int player_get_Inventorymax (Player* player) /*Devuelve el máximo de objetos que puede llevar el jugador por: Ignacio González*/
{
  if (player == NULL)
  {
    return 0;
  }
  

  return inventory_getMax (player->bag);
}

/*Se imprime un objeto*/
STATUS player_print(Player *player)
{ /*Por: Miguel Ibáñez*/

  if (!player)
  {
    return ERROR;
  }

  fprintf(stdout, "--> Object (Id: %ld; Name: %s, Location: %ld)\n", player->id, player->name, player->location);
  inventory_print (player->bag);

  return OK;
}