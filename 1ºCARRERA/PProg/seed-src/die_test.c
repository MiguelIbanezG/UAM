/** 
 * @brief Define los conjuntos
 * del juego
 * @file die.c
 * @author Miguel Ibáñez
 * @version 1.0 
 * @date 20-03-2021 
 * Editado y comentado por: Miguel Ibáñez
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "die.h"

int main() /*Test para el módulo del dado*/
{

    Die *die = NULL, *die2 = NULL;

    die = die_create();

    die_roll(die);
    die_print(die);

    die_roll(die);
    die_print(die);

    die_roll(die);
    die_print(die);

    die_roll(die);
    die_print(die);

    die_roll(die);
    die_print(die);

    die_roll(die);
    die_print(die);

    die_destroy(die);

    if (die_print(die2) == ERROR)
    {
        printf("\n");
    }

    die2 = die_create();

    die_print(die2);

    die_destroy(die2);

    return 0;
}