/** 
 * @brief Implementa la funcionalidad del
 * link
 * 
 * @file link.c
 * @author Mario García
 * @version 1.0 
 * @date 25-02-2021
 * Editado y comentado por: Mario García
 */
#include <string.h>
#include <stdlib.h>
#include "link.h"

struct _Link
{
    Id id, space1, space2;
    char name[MAX_WORD];
    BOOL connection;
};

Link *link_create(Id id)
{ /*Reserva memoria necesaria para la estructura Link por: Miguel Ibáñez*/
    Link *l;

    if (id == NO_ID)
        return NULL;

    l = (Link *)malloc(sizeof(Link));

    if (!l)
    {
        return NULL;
    }

    l->id = id;
    l->space1 = NO_ID;
    l->space2 = NO_ID;
    strcpy(l->name, "\0");

    l->connection = FALSE;

    return l;
}

STATUS link_destroy(Link *l)
{ /*libera la memoria de la estructura Link por: Miguel Ibáñez*/

    if (!l)
        return ERROR;

    free(l);

    return OK;
}

STATUS link_setName(Link *l, char *name)
{ /*Establece un nombre para el link por: Mario García*/
    if (!l || !name)
        return ERROR;

    strcpy(l->name, name);

    return OK;
}

STATUS link_setIdSpace1(Link *l, Id id)
{ /*Establece un id para el primer espacio del link por: Mario García*/
    if (!l || id == NO_ID)
        return ERROR;

    l->space1 = id;

    return OK;
}

STATUS link_setIdSpace2(Link *l, Id id)
{ /*Establece un id para el segundo espacio del link por: Mario García*/
    if (!l || id == NO_ID)
        return ERROR;

    l->space2 = id;

    return OK;
}

STATUS Link_setConnection(Link *l, BOOL connection)
{ /*Establece si la conexión entre dos espacios es abierta o cerrada por: Ignacio González*/

    if (!l) return ERROR;

    l->connection = connection;

    return OK;
}

Id link_getId(Link *l)
{ /*Devuelve el id de un link por: Miguel Ibáñez*/
    if (!l)
        return NO_ID;

    return l->id;
}

Id link_getSpace1Id(Link *l)
{ /*Devuelve el id del primer espacio por: Miguel Ibáñez*/
    if (!l)
        return NO_ID;

    return l->space1;
}

Id link_getSpace2Id(Link *l)
{ /*Devuelve el id del segundo espacio por: Miguel Ibáñez*/
    if (!l)
        return NO_ID;

    return l->space2;
}

char *link_getName(Link *l)
{ /*Devuelve el nombre del link por: Ignacio González*/
    if (!l)
        return NULL;

    return l->name;
}

BOOL link_getConnection(Link *l)
{ /*Devuelve si la conecxión entre dos espacios es abierta o cerrada por: Ignacio González*/
    if (!l)
        return FALSE;

    return l->connection;
}
