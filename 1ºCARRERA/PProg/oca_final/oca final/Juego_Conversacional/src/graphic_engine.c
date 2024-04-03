#include <stdlib.h>
#include <stdio.h>
#include "screen.h"
#include "string.h"
#include "graphic_engine.h"
#include "command.h"
#include "link.h"

#define MAX_OBJ_SPCS 23

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
  Id id_act = NO_ID, id_back = NO_ID, id_next = NO_ID, *objects;
  Space *space_act = NULL;
  Link *l = NULL;
  char *obj_back[4];
  char *obj_act[MAX_OBJ_SPCS];
  char *obj_next[4];
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

    l = game_get_link(game, id_back);

    id_back = link_getSpace1Id(l);

    id_next = space_get_south(space_act);

    l = game_get_link(game, id_next);

    id_next = link_getSpace2Id(l);

    if (id_back != NO_ID)
    {

      for (i = 0; i < 4; i++) 
      {
        objects = space_get_object(game_get_space(game, id_back));

        if (game_get_object_location(game, objects[i]) == id_back)
        {

          obj_back[i] = (char *)object_get_name(game_get_object(game, objects[i]));
        }
        else
          obj_back[i] = "  ";
      }

      if (link_getSpace1Id(game_get_link(game, space_get_west(game_get_space(game, id_back)))) != NO_ID)
      {
        sprintf(str, "  %ld<--|               |", link_getSpace1Id(game_get_link(game, space_get_west(game_get_space(game, id_back)))));
        screen_area_puts(ge->map, str);
      }
      if (link_getSpace2Id(game_get_link(game, space_get_east(game_get_space(game, id_back)))) != NO_ID)
      {
        sprintf(str, "      |               |-->%ld", link_getSpace2Id(game_get_link(game, space_get_east(game_get_space(game, id_back)))));
        screen_area_puts(ge->map, str);
      }

      sprintf(str, "      | 8D          %2d|", (int)id_back);
      screen_area_puts(ge->map, str);
      sprintf(str, "      |    %s    |", space_get_gdesc(game_get_space(game, id_back), 0));
      screen_area_puts(ge->map, str);
      sprintf(str, "      |    %s    |", space_get_gdesc(game_get_space(game, id_back), 1));
      screen_area_puts(ge->map, str);
      sprintf(str, "      |    %s    |", space_get_gdesc(game_get_space(game, id_back), 2));
      screen_area_puts(ge->map, str);
      if (space_get_light(game_get_space(game, id_back)) == TRUE)
      {
        sprintf(str, "      |  %s %s %s %s  |", obj_back[0], obj_back[1], obj_back[2], obj_back[3]);
      }
      else
      {
        sprintf(str, "      |               |");

      }
      screen_area_puts(ge->map, str);
      sprintf(str, "      +---------------+");
      screen_area_puts(ge->map, str);
      sprintf(str, "              ^% ld", link_getSpace1Id(game_get_link(game, space_get_north(game_get_space(game, id_act)))));
      screen_area_puts(ge->map, str);
    }

    if (id_act != NO_ID)
    {
      for (i = 0; i < MAX_OBJ_SPCS; i++)
      {
        objects = space_get_object(game_get_space(game, id_act));

        if (game_get_object_location(game, objects[i]) == id_act)
        {

          obj_act[i] = (char *)object_get_name(game_get_object(game, objects[i]));
        }
        else
          obj_act[i] = "  ";
      }

      sprintf(str, "      +---------------+");
      screen_area_puts(ge->map, str);
      if (link_getSpace1Id(game_get_link(game, space_get_west(game_get_space(game, id_act)))) != NO_ID)
      {
        sprintf(str, "  %ld<--|               |", link_getSpace1Id(game_get_link(game, space_get_west(game_get_space(game, id_act)))));
        screen_area_puts(ge->map, str);
      }
      if (link_getSpace2Id(game_get_link(game, space_get_east(game_get_space(game, id_act)))) != NO_ID)
      {
        sprintf(str, "      |               |-->%ld", link_getSpace2Id(game_get_link(game, space_get_east(game_get_space(game, id_act)))));
        screen_area_puts(ge->map, str);
      }

      sprintf(str, "      | 8D          %2d|", (int)id_act);
      screen_area_puts(ge->map, str);

      sprintf(str, "      |    %s    |", space_get_gdesc(game_get_space(game, id_act), 0));
      screen_area_puts(ge->map, str);
      sprintf(str, "      |    %s    |", space_get_gdesc(game_get_space(game, id_act), 1));
      screen_area_puts(ge->map, str);
      sprintf(str, "      |    %s    |", space_get_gdesc(game_get_space(game, id_act), 2));
      screen_area_puts(ge->map, str);
      if (space_get_light(game_get_space(game, id_act)) == TRUE)
      {
        sprintf(str, "      |  %s %s %s %s  |", obj_act[0], obj_act[1], obj_act[2], obj_act[3]);
      }
      else
      {
        sprintf(str, "      |               |");

      }
      screen_area_puts(ge->map, str);
      sprintf(str, "      +---------------+");
      screen_area_puts(ge->map, str);
    }

    
    if (id_next != NO_ID)
    {

      for (i = 0; i < 4; i++)
      {
        objects = space_get_object(game_get_space(game, id_next));

        if (game_get_object_location(game, objects[i]) == id_next)
        {

          obj_next[i] = (char *)object_get_name(game_get_object(game, objects[i]));
        }
        else
          obj_next[i] = "  ";
      }

      sprintf(str, "              v %ld", link_getSpace2Id(game_get_link(game, space_get_south(game_get_space(game, id_act)))));
      screen_area_puts(ge->map, str);
      sprintf(str, "      +---------------+");
      screen_area_puts(ge->map, str);
      if (link_getSpace1Id(game_get_link(game, space_get_west(game_get_space(game, id_next)))) != NO_ID)
      {
        sprintf(str, "  %ld<--|               |", link_getSpace1Id(game_get_link(game, space_get_west(game_get_space(game, id_next)))));
        screen_area_puts(ge->map, str);
      }
      if (link_getSpace2Id(game_get_link(game, space_get_east(game_get_space(game, id_next)))) != NO_ID)
      {
        sprintf(str, "      |               |-->%ld", link_getSpace2Id(game_get_link(game, space_get_east(game_get_space(game, id_next)))));
        screen_area_puts(ge->map, str);
      }

      sprintf(str, "      | 8D          %2d|", (int)id_next);
      screen_area_puts(ge->map, str);
      sprintf(str, "      |    %s    |", space_get_gdesc(game_get_space(game, id_next), 0));
      screen_area_puts(ge->map, str);
      sprintf(str, "      |    %s    |", space_get_gdesc(game_get_space(game, id_next), 1));
      screen_area_puts(ge->map, str);
      sprintf(str, "      |    %s    |", space_get_gdesc(game_get_space(game, id_next), 2));
      screen_area_puts(ge->map, str);
      if (space_get_light(game_get_space(game, id_next)) == TRUE)
      {
        sprintf(str, "      |  %s %s %s %s  |", obj_next[0], obj_next[1], obj_next[2], obj_next[3]);
      }
      else
      {
        sprintf(str, "      |               |");

      }
      screen_area_puts(ge->map, str);
    }
  }

  /* Paint in the description area */
  screen_area_clear(ge->descript);

  sprintf(str, "  ");
  screen_area_puts(ge->descript, str);

  if (player_get_location(game_get_player(game)) == 11)
  {
    sprintf(str, " ENHORABUENA HAS ESCAPADO Y ACABADO EL JUEGO ");
    screen_area_puts(ge->descript, str);

    sprintf(str, "  ");
    screen_area_puts(ge->descript, str);
  }

  if (player_get_Inventorytam(game_get_player(game)) >= 0)
  {
    sprintf(str, "  El jugador lleva %d objeto(s):", player_get_Inventorytam(game_get_player(game)));
    screen_area_puts(ge->descript, str);
  }

  if (player_get_Inventorytam(game_get_player(game)) >= 0)
  {
    for (i = 0; i < player_get_Inventorytam (game_get_player (game)) ; i++)
    {
     sprintf(str, "  %s", object_get_name (game_get_object( game,player_get_inventory_item(game_get_player (game), i))) );
      screen_area_puts(ge->descript, str);
    }
    
  }


  sprintf(str, "  ");
  screen_area_puts(ge->descript, str);

  sprintf(str, "  Nombre espacio: %s", space_get_name(game_get_space(game, id_act)));
  screen_area_puts(ge->descript, str);

  sprintf(str, "  ");
  screen_area_puts(ge->descript, str);

  if (space_get_numObjects(game_get_space(game, id_act)))
  {
    sprintf(str, "  Objetos en el espacio: ");
    screen_area_puts(ge->descript, str);

    for (i = 4; i < space_get_numObjects(game_get_space(game, id_act)); i++)
    {
      if (obj_act[i] != NULL)
      {
        sprintf(str, "  %s ", obj_act[i]);
        screen_area_puts(ge->descript, str);
      }
    }
  }

  sprintf(str, "  ");
  screen_area_puts(ge->descript, str);

  if (strcmp(game_get_lastObject_description(game), " ") != 0)
  {
    sprintf(str, "  Ultima descripcion: ");
    screen_area_puts(ge->descript, str);
    sprintf(str, "  %s", game_get_lastObject_description(game));
    screen_area_puts(ge->descript, str);
  }

  /* Paint in the banner area */
  screen_area_puts(ge->banner, " La Pantera Rosa ");

  /* Paint in the help area */
  screen_area_clear(ge->help);
  sprintf(str, " Comandos utiles:");
  screen_area_puts(ge->help, str);
  sprintf(str, "     t or take, m or move, d or drop, to or turnon, tf or turnoff, o or open, inspect or i, exit or e");
  screen_area_puts(ge->help, str);

  /* Paint in the feedback area */
  last_cmd = game_get_last_command(game);
  sprintf(str, " %s (%s)", cmd_to_str[last_cmd - NO_CMD][CMDL], cmd_to_str[last_cmd - NO_CMD][CMDS]);
  screen_area_puts(ge->feedback, str);

  /* Dump to the terminal */
  screen_paint();
  printf("prompt:> ");
}