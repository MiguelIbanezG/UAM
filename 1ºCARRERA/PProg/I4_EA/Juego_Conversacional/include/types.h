/**
 * @brief It defines common types
 *
 * @file types.h
 * @author Profesores PPROG
 * @version 1.0
 * @date 13-01-2015
 * @copyright GNU Public License
 */

#ifndef TYPES_H
#define TYPES_H

#define WORD_SIZE 1000
#define NO_ID -1

typedef long Id;

/*Tipo de respuestas booleanas*/
typedef enum {
  FALSE, 
  TRUE
} BOOL;

/*Tipos de resultados posibles para la orden*/
typedef enum {
  ERROR, 
  OK
} STATUS;

/*Dirección de la ficha*/
typedef enum {
  N,
  S,
  E,
  W
} DIRECTION;

#endif
