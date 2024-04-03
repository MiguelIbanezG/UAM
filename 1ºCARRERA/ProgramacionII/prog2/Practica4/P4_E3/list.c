/******************************************************************************

Nombre del modulo: list.c

Descripcion: Implementacion de las funciones del list.h. Implementa una LEC

Autor: Jorge Fernandez Garcia y Pedro Sanchez de la Muela

Fecha: 15 - 4 - 2019

******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include "list.h"

#define info(pn) (pn)->info
#define next(pn) (pn)->next
#define last(pl) (pl)->last

extern int errno;

typedef struct _NodeList { /* EdD privada, necesaria para implementar lista */
    void* info;
    struct _NodeList *next;
} NodeList; /* Tipo NodeList privado */

struct _List {
    NodeList *last; /*La LEC apunta al último nodo y el último al primero*/

    destroy_element_function_type destroy_element_function;
    copy_element_function_type copy_element_function;
    print_element_function_type print_element_function;
    cmp_element_function_type cmp_element_function;
};

NodeList *node_ini();
void node_destroy(NodeList *pn, List *l);
//void list_destroyRec (NodeList * n, const list *l);
//Status InsertAfterNode (NodeList * afterThis, const void *pelem, const List *l);

NodeList *node_ini() {
    NodeList *pn = NULL;
    pn = (NodeList *) malloc(sizeof (NodeList));
    if (!pn) return NULL;
    pn->info = NULL;
    pn->next = NULL;
    return pn;
}

void node_destroy(NodeList *pn, List *l) {
    if (pn) {
        l->destroy_element_function(pn->info);
        free(pn);
    }
}

List* list_ini(destroy_element_function_type f1, copy_element_function_type f2, print_element_function_type f3, cmp_element_function_type f4) {
    List* l = NULL;

    if (!f1 || !f2 || !f3 || !f4) return NULL;


    l = (List*) malloc(sizeof (List));
    if (!l) {
        fprintf(stderr, "%s", strerror(errno));
        return NULL;
    }

    l->last = NULL;

    l->destroy_element_function = f1;
    l->copy_element_function = f2;
    l->print_element_function = f3;
    l->cmp_element_function = f4;

    return l;

}

void list_destroy(List* list) {
    if (!list) return;

    while (list_isEmpty(list) == FALSE)
        list->destroy_element_function(list_extractFirst(list));

    free(list);
}

List* list_insertFirst(List* list, const void *pelem) {
    NodeList *pn = NULL;

    if (!list || !pelem) return ERROR;
    pn = node_ini();
    if (!pn) {
        fprintf(stderr, "%s", strerror(errno));
        return NULL;
    }

    info(pn) = list->copy_element_function(pelem);
    if (!info(pn)) {
        node_destroy(pn, list);
        return NULL;
    }

    if (list_isEmpty(list) == TRUE) {
        next(pn) = pn;
        last(list) = pn;
    } else {
        next(pn) = next(last(list));
        next(last(list)) = pn;
    }
    return list;
}

List* list_insertLast(List* list, const void *pelem) {
    NodeList *pn = NULL;
    if (!list || !pelem) return ERROR;
    pn = node_ini();
    if (!pn) {
        fprintf(stderr, "%s", strerror(errno));
        return NULL;
    }
    info(pn) = list->copy_element_function(pelem);
    if (!info(pn)) {
        node_destroy(pn, list);
        return NULL;
    }

    if (list_isEmpty(list) == TRUE) {
        next(pn) = pn;
        last(list) = pn;
    } else {
        next(pn) = next(last(list));
        next(last(list)) = pn;
        last(list) = pn;
    }
    return list;


}

List* list_insertInOrder(List* list, const void *pelem) {

    NodeList * pn = NULL, *pncpy = NULL;


    if (!list || !pelem) return ERROR;

    if (list_isEmpty(list) == TRUE || list->cmp_element_function(pelem, info(next(last(list)))) <= 0) {
        if (list_insertFirst(list, pelem) == ERROR)
            return NULL;
        return list;
    }

    for (pn = last(list); next(pn) != last(list); pn = next(pn)) {

        if (list->cmp_element_function(pelem, info(pn)) >= 0 && list->cmp_element_function(pelem, info(next(pn))) <= 0) {

            pncpy = node_ini();
            if (!pncpy) {
                fprintf(stderr, "%s", strerror(errno));
                return NULL;
            }
            info(pncpy) = list->copy_element_function(pelem);
            if (!info(pncpy)) {
                node_destroy(pncpy, list);
                return NULL;
            }

            next(pncpy) = next(pn);
            next(pn) = pncpy;
            return list;


        }


    }
    if (list_insertLast(list, pelem) == ERROR)
        return NULL;
    return list;
}

void * list_extractFirst(List* list) {
    NodeList *pn = NULL;
    void *pe = NULL;

    if (!list || list_isEmpty(list) == TRUE) return NULL;
    pe = info(next(last(list)));
    info(next(last(list))) = NULL;

    if (next(last(list)) == last(list)) {
        node_destroy(last(list), list);
        last(list) = NULL;
    } else {
        pn = next(last(list));
        next(last(list)) = next(pn);
        node_destroy(pn, list);
    }
    return pe;

}

void * list_extractLast(List* list) {
    NodeList *pn = NULL;
    void *pe = NULL;
    if (!list || list_isEmpty(list) == TRUE) return NULL;
    pe = info(last(list));


    if (next(last(list)) == last(list)) {
        node_destroy(last(list), list);
        last(list) = NULL;
        return pe;
    }

    for (pn = last(list); next(pn) != last(list); pn = next(pn));
    next(pn) = next(last(list));
    node_destroy(last(list), list);
    last(list) = pn;
    return pe;
}

Bool list_isEmpty(const List* list) {
    if (!list) return TRUE;

    if (list->last == NULL) return TRUE;
    return FALSE;
}

const void* list_get(const List* list, int index) {
    int numrec;
    NodeList * pn = NULL;
    void * info = NULL;

    if (!list || index < 1) return NULL;

    if (list_isEmpty(list) == TRUE) return 0;

    for (pn = next(last(list)), numrec = 1; numrec != index; pn = next(pn), numrec++);

    if (numrec > index) return NULL;

    info = list->copy_element_function(info(pn));
    if (!info) {
        fprintf(stderr, "%s", strerror(errno));
        return NULL;
    }

    return info;
}

int list_size(const List* list) {
    NodeList * pn = NULL;
    int size;

    if (!list) return -1;
    if (list_isEmpty(list) == TRUE) return 0;

    for (pn = next(last(list)), size = 1; pn != last(list); pn = next(pn), size++);

    return size;
}

int list_print(FILE *fd, const List* list) {
    NodeList * pn = NULL;
    int i = 0;
    if (!list) return -1;
    if (list_isEmpty(list) == TRUE) return -1;

    for (pn = next(last(list)); pn != last(list); pn = next(pn)) {

        i += list->print_element_function(fd, info(pn));
        fprintf(fd, "\n");

    }
    i += i += list->print_element_function(fd, info(pn));
    fprintf(fd,"\n" );

    return i;
}
