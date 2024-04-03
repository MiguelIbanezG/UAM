/** 
 * @brief Implementa la lectura y ejecución de los comandos
 * 
 * @file command.c
 * @author Profesores PPROG
 * @version 2.0 
 * @date 13-01-2020 
 * @copyright GNU Public License
 * Editado y comentado por: Sergio Hidalgo
 */
#include <stdio.h>
#include <strings.h>
#include "command.h"

#define CMD_LENGHT 30

/*En las siguientes dos lineas de código se muestra por pantalla las opciones del usuario.*/

char *cmd_to_str[N_CMD][N_CMDT] = {{"", "No command"}, {"", "Unknown"}, {"e", "Exit"}, {"n", "Next"}, {"b", "Back"}, {"t", "Take"}, {"rl", "Roll"}, {"l", "Left"}, {"r", "Right"}, {"d", "Drop"}};

/*Define la función para que el usuario pueda introducir datos*/
T_Command command_get_user_input()
{
	T_Command cmd = NO_CMD;
	char input[CMD_LENGHT] = "";
	int i = UNKNOWN - NO_CMD + 1;

	/*El código a continuación, representa un bucle que hará que el usuario introduzca una letra para 
	avanzar, retroceder o salir. En caso de que el valor no se reconozca, no habrá cambios en el tablero*/
	if (scanf("%s", input) > 0)
	{
		cmd = UNKNOWN;
		while (cmd == UNKNOWN && i < N_CMD)
		{

			/*En este bucle se comparan dos cadenas entre si, con la función strcasecmp (si ambas son iguales,
			devuelve 0 y si no, un número distinto de 0)*/
			if (!strcasecmp(input, cmd_to_str[i][CMDS]) || !strcasecmp(input, cmd_to_str[i][CMDL]))
			{
				cmd = i + NO_CMD;
			}
			else
			{
				i++; /*En caso de que ninguna de las 2 sea distinta de 0, el valor de i aumenta en 1 su valor*/
			}
		}
	}
	return cmd;
}
