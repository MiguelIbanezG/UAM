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
Player *player_create(Id id);
STATUS player_set_name(Player *player, char *name);
STATUS player_set_object(Player *player, Id value);
const char *player_get_name(Player *player);
Id player_get_id(Player *player);
Id player_get_object(Player *player);
STATUS player_set_location(Player *player, Id value);
Id player_get_location(Player *player);
STATUS player_print(Player *player);

#endif