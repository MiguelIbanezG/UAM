#include <stdlib.h>
#include <stdio.h>
#include "screen.h"
#include "string.h"
#include "graphic_engine.h"
#include "command.h"

struct _Graphic_engine
{
  Area *map, *descript, *banner, *help, *feedback; /*Partes de la pantalla*/
};

Graphic_engine *graphic_engine_create()
{
  static Graphic_engine *ge = NULL;

  if (ge)
    return ge;

  screen_init(); /*Se reserva la memoria de la estructura*/
  ge = (Graphic_engine *)malloc(sizeof(Graphic_engine));
  if (ge == NULL)
    return NULL;

  ge->map = screen_area_init(1, 1, 68, 22); /*Tamaño de las casillas*/
  ge->descript = screen_area_init(70, 1, 49, 22);
  ge->banner = screen_area_init(46, 24, 23, 1);
  ge->help = screen_area_init(1, 25, 118, 4);
  ge->feedback = screen_area_init(1, 30, 118, 4);

  return ge;
}

void graphic_engine_destroy(Graphic_engine *ge) /*Destrucción del GE*/
{
  if (!ge)
    return;

  screen_area_destroy(ge->map);
  screen_area_destroy(ge->descript);
  screen_area_destroy(ge->banner);
  screen_area_destroy(ge->help);
  screen_area_destroy(ge->feedback);

  screen_destroy();
  free(ge);
}

void graphic_engine_paint_game(Graphic_engine *ge, Game *game) /*Esta función pitna el tablero*/
{
  Id id_act = NO_ID, id_back = NO_ID, id_next = NO_ID, obj_loc = NO_ID;
  Space *space_act = NULL;
  char *obj[4];
  char str[255];
  int i = 0;
  T_Command last_cmd = UNKNOWN;
  extern char *cmd_to_str[N_CMD][N_CMDT];

  /* Paint the in the map area */
  screen_area_clear(ge->map);
  if ((id_act = game_get_player_location(game)) != NO_ID)
  {
    space_act = game_get_space(game, id_act);
    id_back = space_get_north(space_act);
    id_next = space_get_south(space_act);

    for (i = 0; i < 4; i++)
    {

      if (game_get_object_location(game, object_get_id(game_get_objects(game, i))) == id_back)
      {
        if (i == 0)
          obj[i] = "O1";
        else if (i == 1)
          obj[i] = "O2";
        else if (i == 2)
          obj[i] = "O3";
        else if (i == 3)
          obj[i] = "O4";
      }
      else
        obj[i] = "  ";
    }

    if (id_back != NO_ID)
    {
      if (space_get_east(game_get_space(game, id_back)) != NO_ID) /*Si tiene una conexión desde el oeste hasta el este, se printeará*/
      {
        sprintf(str, "  %ld<--|             %2d|", space_get_east(game_get_space(game, id_back)), (int)id_back);
      }
      else if (space_get_west(game_get_space(game, id_back)) != NO_ID) /*Si tiene una conexión desde el oeste hasta el este, se printeará*/
      {
        sprintf(str, "      |             %2d|-->%ld", (int)id_back, space_get_west(game_get_space(game, id_back)));
      }
      else    /*Sino, no se printea nada, y sí, estan al revés (no sabemos como solucionarlo)*/
      {
        sprintf(str, "      |             %2d|", (int)id_back);
      }
      screen_area_puts(ge->map, str);
      sprintf(str, "      |    %s    |", space_get_gdesc(game_get_space(game, id_back), 0));
      screen_area_puts(ge->map, str);
      sprintf(str, "      |    %s    |", space_get_gdesc(game_get_space(game, id_back), 1));
      screen_area_puts(ge->map, str);
      sprintf(str, "      |    %s    |", space_get_gdesc(game_get_space(game, id_back), 2));
      screen_area_puts(ge->map, str);
      sprintf(str, "      |  %s %s %s %s  |", obj[0], obj[1], obj[2], obj[3]);
      screen_area_puts(ge->map, str);
      sprintf(str, "      +---------------+");
      screen_area_puts(ge->map, str);
      sprintf(str, "              ^% ld", space_get_north(game_get_space(game, id_act)));
      screen_area_puts(ge->map, str);
    }

    for (i = 0; i < 4; i++)
    {

      if (game_get_object_location(game, object_get_id(game_get_objects(game, i))) == id_act)
      {
        if (i == 0)
          obj[i] = "O1";
        else if (i == 1)
          obj[i] = "O2";
        else if (i == 2)
          obj[i] = "O3";
        else if (i == 3)
          obj[i] = "O4";
      }
      else
        obj[i] = "  ";
    }

    if (id_act != NO_ID)
    {
      sprintf(str, "      +---------------+");
      screen_area_puts(ge->map, str);
      if (space_get_east(game_get_space(game, id_act)) != NO_ID)
      {
        sprintf(str, "  %ld<--| 8D          %2d|", space_get_east(game_get_space(game, id_act)), (int)id_act);
      }
      else if (space_get_west(game_get_space(game, id_act)) != NO_ID)
      {
        sprintf(str, "      | 8D          %2d|-->%ld", (int)id_act, space_get_west(game_get_space(game, id_act)));
      }
      else
      {
        sprintf(str, "      | 8D          %2d|", (int)id_act);
      }
      screen_area_puts(ge->map, str);
      sprintf(str, "      |    %s    |", space_get_gdesc(game_get_space(game, id_act), 0));
      screen_area_puts(ge->map, str);
      sprintf(str, "      |    %s    |", space_get_gdesc(game_get_space(game, id_act), 1));
      screen_area_puts(ge->map, str);
      sprintf(str, "      |    %s    |", space_get_gdesc(game_get_space(game, id_act), 2));
      screen_area_puts(ge->map, str);
      sprintf(str, "      |  %s %s %s %s  |", obj[0], obj[1], obj[2], obj[3]);
      screen_area_puts(ge->map, str);
      sprintf(str, "      +---------------+");
      screen_area_puts(ge->map, str);
    }

    for (i = 0; i < 4; i++)
    {

      if (game_get_object_location(game, object_get_id(game_get_objects(game, i))) == id_next)
      {
        if (i == 0)
          obj[i] = "O1";
        else if (i == 1)
          obj[i] = "O2";
        else if (i == 2)
          obj[i] = "O3";
        else if (i == 3)
          obj[i] = "O4";
      }
      else
        obj[i] = "  ";
    }
    if (id_next != NO_ID)
    {
      sprintf(str, "              v %ld", space_get_south(game_get_space(game, id_act)));
      screen_area_puts(ge->map, str);
      sprintf(str, "      +---------------+");
      screen_area_puts(ge->map, str);
      if (space_get_east(game_get_space(game, id_next)) != NO_ID)
      {
        sprintf(str, "  %ld<--|             %2d|", space_get_east(game_get_space(game, id_next)), (int)id_next);
      }
      else if (space_get_west(game_get_space(game, id_next)) != NO_ID)
      {
        sprintf(str, "      |             %2d|-->%ld", (int)id_next, space_get_west(game_get_space(game, id_next)));
      }
      else
      {
        sprintf(str, "      |             %2d|", (int)id_next);
      }
      screen_area_puts(ge->map, str);
      sprintf(str, "      |    %s    |", space_get_gdesc(game_get_space(game, id_next), 0));
      screen_area_puts(ge->map, str);
      sprintf(str, "      |    %s    |", space_get_gdesc(game_get_space(game, id_next), 1));
      screen_area_puts(ge->map, str);
      sprintf(str, "      |    %s    |", space_get_gdesc(game_get_space(game, id_next), 2));
      screen_area_puts(ge->map, str);
      sprintf(str, "      |  %s %s %s %s  |", obj[0], obj[1], obj[2], obj[3]);
      screen_area_puts(ge->map, str);
    }
  }

  /* Paint in the description area */
  screen_area_clear(ge->descript);

  for (i = 0; i < 4; i++)
  {

    if ((obj_loc = game_get_object_location(game, object_get_id(game_get_objects(game, i)))) != NO_ID)
    {
      sprintf(str, "  Object %d location:%d id:%d", i + 1, (int)obj_loc, (int)object_get_id(game_get_objects(game, i)));
      screen_area_puts(ge->descript, str);
    }
  }

  if (player_get_Inventorytam(game_get_player(game)) >= 0)
  {
    sprintf(str, "  Player carrying %d objects", player_get_Inventorytam(game_get_player(game)));
    screen_area_puts(ge->descript, str);
  }

  if (die_lastroll(game_get_die(game)) != 0)
  {
    sprintf(str, "  Ultima tirada:%d", die_lastroll(game_get_die(game)));
    screen_area_puts(ge->descript, str);
  }

  if (strcmp (game_get_lastObject_description (game), " ") != 0)
  {
    sprintf(str, "  Ultima descripcion: %s", game_get_lastObject_description (game));
    screen_area_puts(ge->descript, str);
  }

  /* Paint in the banner area */
  screen_area_puts(ge->banner, " The game of the Goose ");

  /* Paint in the help area */
  screen_area_clear(ge->help);
  sprintf(str, " The commands you can use are:");
  screen_area_puts(ge->help, str);
  sprintf(str, "     t or take, m or move, d or drop, roll or rl, inspect or i, exit or e");
  screen_area_puts(ge->help, str);

  /* Paint in the feedback area */
  last_cmd = game_get_last_command(game);
  sprintf(str, " %s (%s)", cmd_to_str[last_cmd - NO_CMD][CMDL], cmd_to_str[last_cmd - NO_CMD][CMDS]);
  screen_area_puts(ge->feedback, str);

  /* Dump to the terminal */
  screen_paint();
  printf("prompt:> ");
}