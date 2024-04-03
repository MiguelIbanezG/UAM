/** 
 * @brief Define los jugadores
 * del juego
 * 
 * 
 * @file player.h
 * @author Miguel Ibáñez
 * @version 1.0 
 * @date 25-02-2021
 * Editado y comentado por: Miguel Ibáñez 
 */
#ifndef PLAYER_H
#define PLAYER_H

#include "types.h"

/*Definición de la estructura*/
typedef struct _Player Player;

/*Funciones públicas*/
STATUS player_destroy(Player *player);
Player *player_init();
Player *player_create(Id id);
STATUS player_set_name(Player *player, char *name);
STATUS player_set_addObject(Player *player, Id value);
STATUS player_set_delObject(Player *player, Id value);
const char *player_get_name(Player *player);
Id player_get_id(Player *player);
STATUS player_set_location(Player *player, Id value);
Id player_get_location(Player *player);
STATUS player_set_Inventorymax(Player *player, int num);
int player_get_Inventorytam(Player *player);
BOOL player_check_inventory(Player *player, Id id);
int player_get_Inventorymax(Player *player);
STATUS player_print(Player *player);
Id player_get_inventory_item(Player *player, int ident);

#endif