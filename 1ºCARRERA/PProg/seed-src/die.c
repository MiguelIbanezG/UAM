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
#include <time.h>

#define MAX_ID 1000
#define MAX 6
#define MIN 1

#include "die.h"

struct _Die /*Estructura del dado con su id, número máximo y mínimo y la tirada del dado*/
{
    Id id;
    int max;
    int min;
    int roll;
};

Die *die_create() /*crea el dado por: Miguel Ibáñez*/
{

    Die *newDie = NULL;

    newDie = (Die *)malloc(sizeof(Die));

    if (newDie == NULL)
    {
        return NULL;
    }

    newDie->id = NO_ID;
    newDie->max = MAX;
    newDie->min = MIN;
    newDie->roll = 0;

    return newDie;
}

STATUS die_destroy(Die *die) /*destruye el dado por: Miguel Ibáñez*/
{
    if (!die)
    {
        return ERROR;
    }

    free(die);
    die = NULL;

    return OK;
}

int die_roll(Die *die) /*tira el dado por: Miguel Ibáñez*/
{

    if (die == NULL)
    {
        return ERROR;
    }

    die->roll = (rand() % MAX) + MIN;

    return OK;
}

STATUS die_print(Die *die) /*imprime el dado por: Miguel Ibáñez*/
{

    if (die == NULL)
    {
        return ERROR;
    }

    fprintf(stdout, "--> Die ( Id: %ld, Ultima tirada: %d )\n", die->id, die->roll);

    return OK;
}

int die_lastroll(Die *die) /*muestra el resultado de la ultima tirada por: Miguel Ibáñez*/
{
    if (die == NULL)
    {
        return ERROR;
    }

    return die->roll;
}