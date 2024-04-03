/** 
 * @brief Implementa las funciones de
 * link.c
 * 
 * @file link.h
 * @author Ignacio González
 * @version 1.0 
 * @date 25-02-2021
 * Editado y comentado por: Ignacio González
 */
#ifndef LINK_H
#define LINK_H

#include <stdio.h>
#include "types.h"

#define MAX_WORD 100
#define MAX_LINKS 100

typedef struct _Link Link;

Link * link_create(Id id);
STATUS link_destroy(Link *l);
STATUS link_setName (Link *l, char *name);
STATUS link_setIdSpace1 (Link *l, Id id);
STATUS link_setIdSpace2 (Link *l, Id id);
STATUS Link_setConnection(Link *l, BOOL connection);
Id link_getId(Link *l);
Id link_getSpace1Id(Link *l);
Id link_getSpace2Id(Link *l);
char *link_getName(Link *l);
BOOL link_getConnection (Link *l);

#endif

