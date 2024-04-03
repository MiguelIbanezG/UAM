/** 
 * @brief Implementa los conjuntos en el juego
 * 
 * @file set.c
 * @author Sergio Hidalgo
 * @version 1.0 
 * @date 03-03-2021 
 * Editado y comentado por: Sergio Hidalgo
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "set.h"

/*Estructura tipo set que almacena los id y cuantos hay*/
struct _Set
{
    Id array_id[MAX_ID];
    int ids;
};

/*Crea un set*/
Set *set_create()
{ /*Por: Sergio Hidalgo*/

    Set *newSet = NULL;

    int i;

    newSet = (Set *)malloc(sizeof(Set));

    if (newSet == NULL)
    {
        return NULL;
    }

    newSet->ids = 0;

    for (i = 0; i < MAX_ID; i++)
    {
        newSet->array_id[i] = NO_ID;
    }

    return newSet;
}

/*Destruye un set*/
STATUS set_destroy(Set *set)
{ /*Por: Sergio Hidalgo*/
    int i;

    if (!set)
    {
        return ERROR;
    }

    for (i = 0; i < set->ids; i++)
    {
        set_del_id(set, set_findId(set, i));
    }

    free(set);

    return OK;
}

/*Añade al set 1 id*/
STATUS set_add_id(Set *set, Id id)
{ /*Por: Sergio Hidalgo*/

    if ((!id) || (set == NULL))
    {
        return ERROR;
    }

    set->array_id[set->ids] = id;
    (set->ids)++;

    return OK;
}

/*Elimina 1 id del set*/
STATUS set_del_id(Set *set, Id id)
{ /*Por: Sergio Hidalgo*/

    int i;
    Id del_aux[MAX_ID];

    if ((!id) || (set == NULL)) /*Control de errores*/
    {
        return ERROR;
    }

    for (i = 0; i < set->ids; i++) /*Bucle para encontrar el id*/
    {
        del_aux[i] = set->array_id[i]; /*Array auxiliar para eliminar un id concreto*/
    }

    for (i = 0; i < set->ids; i++) /*Bucle para encontrar el id*/
    {

        if (id == set->array_id[i])
        {
            while (i < set->ids)
            {

                set->array_id[i] = del_aux[i + 1]; /*Se copian los valores de la array auxiliar en una posición más para ignorar el valor del id que*/
                i++;                               /*se quiere eliminar*/
            }

            (set->ids)--;

            return OK;
        }
    }

    return ERROR;
}

/*Imprime 1 set*/
STATUS set_print(Set *set)
{ /*Por: Sergio Hidalgo*/

    int i;

    if (!set)
    {
        return ERROR;
    }

    fprintf(stdout, "--> Set ( nIds: %d ids:", set->ids);

    for (i = 0; i < set->ids; i++)
    {
        fprintf(stdout, " %ld", set->array_id[i]);
    }

    fprintf(stdout, " )\n");

    return OK;
}

/*Encuentra el id a partir de su posición en la array*/
Id set_findId(Set *set, int position)
{ /*Por: Sergio Hidalgo*/
    if ((set->array_id[position]) == NO_ID)
    {
        return NO_ID;
    }

    return set->array_id[position];
}

/*Se comprueba si el id está en el set*/
BOOL set_Idcheck(Set *set, Id id)
{ /*Por: Sergio Hidalgo*/
    int i;

    for (i = 0; i < set->ids; i++)
    {
        if (set->array_id[i] == id)
        {
            return TRUE;
        }
    }

    return FALSE;
}

/*Se obtiene el número de ids en el set*/
int set_getnIds(Set *set)
{ /*Por: Sergio Hidalgo*/

    return set->ids;
}

/*Devuelve la array de ids completa*/
Id *set_getArrayIds(Set *set)
{ /*Por: Sergio Hidalgo*/

    if (set == NULL)
    {
        return NULL;
    }

    return set->array_id;
}
