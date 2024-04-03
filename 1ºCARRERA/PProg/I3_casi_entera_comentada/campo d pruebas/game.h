/** 
 * @brief Define la intergaz de juego
 * en cada comando
 * 
 * @file game.h.
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


typedef struct _Game Game;

/*Funciones Públicas*/
STATUS game_create(Game* game);
Game* game_init();
STATUS game_create_from_file(Game* game, char* filename);
STATUS game_update(Game* game, T_Command cmd);
STATUS game_destroy(Game* game);
BOOL   game_is_over(Game* game);
void   game_print_data(Game* game);
Die* game_get_die (Game* game);
Player* game_get_player (Game* game);
Object* game_get_objects (Game* game, int position);
Space* game_get_space(Game* game, Id id);
Id     game_get_player_location(Game* game);
Id     game_get_object_location(Game* game, Id id_object);
T_Command game_get_last_command(Game* game);
STATUS game_add_player(Game *game, Player *player);
STATUS game_add_space(Game* game, Space* space);
int game_space_get_position_fromId (Game* game, Id id);
STATUS game_add_object(Game* game, Object* object);
STATUS game_set_object_location(Game* game, Id id_space, Id id_object);
STATUS game_set_player_location(Game *game, Id id);

#endif
