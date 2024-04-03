/** 
 * @brief Define la lectura
 * del juego
 * 
 * @file game_reader.h
 * @author Miguel Ibáñez
 * @version 1.0 
 * @date 21-02-2021 
 */
#ifndef GAME_READER_H
#define GAME_READER_H

#include "space.h"
#include "game.h"

/*Funciones públicas*/
STATUS gamereader_load_spaces(Game* game, char* filename);
STATUS gamereader_load_objects(Game* game, char* filename);
STATUS gamereader_set_object_location(Game* game, Id id_space, Id id_object);

#endif