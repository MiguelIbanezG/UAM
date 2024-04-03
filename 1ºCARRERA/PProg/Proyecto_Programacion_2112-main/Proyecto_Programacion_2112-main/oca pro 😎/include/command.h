/**
 * @brief It implements the command interpreter
 *
 * @file command.h
 * @author Profesores PPROG
 * @version 2.0
 * @date 13-01-2020
 * @copyright GNU Public License
 */

#ifndef COMMAND_H
#define COMMAND_H

#define N_CMDT 2
#define N_CMD 11

typedef enum enum_CmdType
{ /*Tipo de comando (si es una letra o una palabra)*/
  CMDS,
  CMDL
} T_CmdType;

typedef enum enum_Command
{ /*Comandos que se podrán utilizar en el juego*/
  NO_CMD = -1,
  UNKNOWN,
  EXIT,
  TAKE,
  ROLL,
  MOVE,
  DROP,
  INSPECT,
  TURNON,
  TURNOFF,
  OPEN
} T_Command;

T_Command command_get_user_input();

#endif
