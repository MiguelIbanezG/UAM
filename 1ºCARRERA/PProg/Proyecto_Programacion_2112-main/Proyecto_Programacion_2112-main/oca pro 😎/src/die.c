/** 
 * @brief Implementa las funcionalidad del dado
 * 
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

#include "die.h"

struct _Die /*Estructura del dado con su id, número máximo y mínimo y la tirada del dado*/
{
    Id id;
    int max;
    int min;
    int roll;
};

Die *die_create(Id id, int min, int max) /*crea el dado por: Miguel Ibáñez*/
{

    Die *newDie = NULL;

    newDie = (Die *)malloc(sizeof(Die));

    if (newDie == NULL)
    {
        return NULL;
    }

    srand(time(NULL));

    newDie->id = id;
    newDie->max = max;
    newDie->min = min;
    newDie->roll = rand()% (newDie->max - newDie->min + 1) + newDie->min;

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
        return -1;
    }

    die->roll = rand()% (die->max - die->min + 1) + die->min;

    return die->roll;
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
        return 0;
    }

    return die->roll;
}

Id die_get_id (Die* die){ /*Devuelve el id del dado por: Ignacio González*/

    if (!die) 
    {
    return NO_ID;
    }
    
    return die->id;
}

int die_get_min(Die* die){ /*Devuelve el número mínimo posible al tirar el dado por: Ignacio González*/

    if (!die) return -1;

    return die->min;
}

int die_get_max(Die* die){ /*Devuelve el número máximo posible al tirar el dado por: Ignacio González*/

    if (!die) return -1;

    return die->max;
}

int die_get_last(Die* die){ /*Devuelve la última tirada del dado por: Ignacio González*/

    if (!die) return -1;

    return die->roll;
}