/**
 * @brief It defines a screen
 *
 * @file screen.h
 * @author Profesores PPROG
 * @version 2.0
 * @date 13-01-2015 
 * @copyright GNU Public License
 * Editado y comentado por: Sergio Hidalgo
 */

#ifndef __SCREEN__
#define __SCREEN__

#define SCREEN_MAX_STR 80

typedef struct _Area Area;

/*Implementación de las funciones que forman el tablero*/
void  screen_init();
void  screen_destroy();
void  screen_paint();

/*Estas funciones indican las dimensiones del tablero*/
Area* screen_area_init(int x, int y, int width, int height);
void  screen_area_destroy(Area* area);
void  screen_area_clear(Area* area);
void  screen_area_reset_cursor(Area* area);
void  screen_area_puts(Area* area, char *str);

#endif
