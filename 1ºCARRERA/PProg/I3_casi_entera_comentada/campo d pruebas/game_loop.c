/**
 * @brief It defines the game loop
 *
 * @file game_loop.c
 * @author Profesores PPROG
 * @version 2.0
 * @date 13-01-2020
 * @copyright GNU Public License
 * Editado y comentado por Miguel Ibáñez
 */

#include <stdio.h>
#include <stdlib.h>
#include "graphic_engine.h"
#include "game.h"

int game_loop_init(Game *game, Graphic_engine **gengine, char *file_name);
void game_loop_run(Game *game, Graphic_engine *gengine);
void game_loop_cleanup(Game *game, Graphic_engine *gengine);

/*Aquí se encuentra el main del programa*/
int main(int argc, char *argv[])
{
  Game *game = game_init ();
  Graphic_engine *gengine;

  /*En caso de que el usuario no indique usar el data.dat, saltará este mensaje*/
  if (argc < 2)
  {
    fprintf(stderr, "Use: %s <game_data_file>\n", argv[0]);
    return 1;
  }

  /*Se inicia el juego*/
  if (!game_loop_init(game, &gengine, argv[1]))
  {
    game_loop_run(game, gengine);
    game_loop_cleanup(game, gengine);
  }

  return 0;
}

/*Inicia el bucle en el que se creará el juego*/
int game_loop_init(Game *game, Graphic_engine **gengine, char *file_name)
{
  if (game_create_from_file(game, file_name) == ERROR)
  {
    fprintf(stderr, "Error while initializing game.\n");
    return 1;
  }

  if ((*gengine = graphic_engine_create()) == NULL)
  {
    fprintf(stderr, "Error while initializing graphic engine.\n");
    game_destroy(game);
    return 1;
  }

  return 0;
}

/*Se pinta el juego y se actualiza el tablero*/
void game_loop_run(Game *game, Graphic_engine *gengine)
{
  T_Command command = NO_CMD;

  while ((command != EXIT) && !game_is_over(game))
  {
    graphic_engine_paint_game(gengine, game);
    command = command_get_user_input();
    game_update(game, command);
  }
}

/*Se finaliza el juego*/
void game_loop_cleanup(Game *game, Graphic_engine *gengine)
{
  game_destroy(game);
  graphic_engine_destroy(gengine);
}
