/** 
 * @brief Define la intergaz de juego
 * en cada comando
 * 
 * @file game.h
 * @author Profesores PPROG
 * @version 1.0 
 * @date 13-01-2015 
 * @copyright GNU Public License
 * Editado y comentado por: Sergio Hidalgo
 */

#ifndef GAME_H
#define GAME_H

#include "space.h"
#include "player.h"
#include "command.h"
#include "object.h"
#include "die.h"



/*Estructura de tipo "Game" que declara tanto la posición del jugador como la del objeto y la del espacio*/ 
typedef struct _Game{
  Player* player;
  Object* objects [MAX_OBJECTS + 1];
  Space* spaces [MAX_SPACES + 1];
  Die* die;
  T_Command last_cmd;
} Game;

/*Funciones Públicas*/
STATUS game_create(Game* game);
STATUS game_create_from_file(Game* game, char* filename);
STATUS game_update(Game* game, T_Command cmd);
STATUS game_destroy(Game* game);
BOOL   game_is_over(Game* game);
void   game_print_data(Game* game);
Space* game_get_space(Game* game, Id id);
Id     game_get_player_location(Game* game);
Id     game_get_object_location(Game* game, Id id_object);
T_Command game_get_last_command(Game* game);
STATUS game_add_space(Game* game, Space* space);
int game_space_get_position_fromId (Game* game, Id id);
STATUS game_add_object(Game* game, Object* object);


#endif
