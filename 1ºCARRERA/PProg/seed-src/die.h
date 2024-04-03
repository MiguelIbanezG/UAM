/** 
 * @brief Define los conjuntos
 * del juego
 * @file die.h
 * @author Miguel Ibáñez
 * @version 1.0 
 * @date 20-03-2021 
 * Editado y comentado por: Miguel Ibáñez
 */
#include "types.h"

typedef struct _Die Die; /*Definición de la estructura*/

/*Funciones públicas*/
Die *die_create();
STATUS die_destroy(Die *die);
STATUS die_print(Die *die);
int die_roll(Die *die);
int die_lastroll(Die *die);