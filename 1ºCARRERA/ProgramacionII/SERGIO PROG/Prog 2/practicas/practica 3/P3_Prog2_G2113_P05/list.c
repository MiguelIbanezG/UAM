/*
*Título: Funciones list, práctica 3, programación 2
*Grupo: viernes 2113
*Autores: Sergio Hidalgo y Miguel Ibáñez 
*/
#include <stdlib.h>
#include "list.h"

typedef struct _NodeList
{
    void *data;
    struct _NodeList *next;
} NodeList;

struct _List
{
    NodeList *last;
};

NodeList *node_new();
int float_print(FILE *fp, const void *e);

NodeList *node_new() /*Crea un nuevo nodo*/
{
    NodeList *pn = NULL;

    pn = (NodeList *)malloc(sizeof(NodeList));

    if (!pn)
    {
        return NULL;
    }

    pn->data = NULL;
    pn->next = NULL;

    return pn;
}

List *list_new() /*Crea una nueva lista*/
{

    List *pl = NULL;

    pl = (List *)malloc(sizeof(List));

    if (pl == NULL)
    {

        return NULL;
    }

    pl->last = NULL;

    return pl;
}

Bool list_isEmpty(const List *pl)
{

    if (pl == NULL)
    {
        return TRUE;
    }

    if (((pl->last) == NULL)) /*Si el último nodo de la lista es nulo, está vacía*/
    {
        return TRUE;
    }

    return FALSE;
}

Status list_pushFront(List *pl, void *e)
{
    NodeList *new_n = NULL;

    if (pl == NULL || e == NULL)
    {

        return ERROR;
    }

    new_n = node_new(); /*Inicialización del nuevo nodo*/

    if (new_n == NULL)
    {

        return ERROR;
    }

    new_n->data = e; /*Se iguala al elemento que se desea insertar*/

    if (list_isEmpty(pl)) /*Si está vacía*/
    {
        pl->last = new_n;    /*El ultimo nodo será el nuevo*/
        new_n->next = new_n; /*Y el siguiente, el mismo (al ser circular)*/
    }
    else /*Si no está vacía*/
    {
        new_n->next = pl->last->next; /*El siguiente nodo de el nuevo nodo debe ser el que antes estaba primero*/
        pl->last->next = new_n;       /*El siguiente nodo del último de la lista es ahora el nuevo nodo*/

        /*Explicado por pasos:

        ultimo = pl->last;                  El último nodo será el último de la lista
        
        primero_anterior = ultimo->next;    El primero será el siguiente del último
        
        ultimo->next = nuevo_nodo;          Y el siguiente del último, será el nuevo nodo

        nuevo_nodo->next = primero_anterior; El siguiente del nuevo, será el que antes era el primero
        */
    }

    return OK;
}

Status list_pushBack(List *pl, void *e)
{
    NodeList *new_n = NULL;

    if (pl == NULL || e == NULL)
    {
        return ERROR;
    }

    new_n = node_new(); /*Inicialización del nuevo nodo*/

    if (new_n == NULL)
    {
        return ERROR;
    }

    new_n->data = (void *)e; /*Se iguala al elemento que se desea insertar*/

    if (list_isEmpty(pl) == TRUE) /*Si está vacía*/
    {
        pl->last = new_n;    /*El último de la lista será el nuevo nodo*/
        new_n->next = new_n; /*Y el siguiente de esté, también*/
    }
    else /*Si no lo está*/
    {
        new_n->next = pl->last->next; /*El siguiente del nuevo nodo es el siguiente del último (el primero)*/
        pl->last->next = new_n;       /*Además, el siguiente del antiguo último será el nuevo nodo */
        pl->last = new_n;             /*Para terminar, se asigna el nuevo nodo como el último de la lista*/

        /*Explicado por pasos:

        primero = pl->last->next;   El primero será el siguiente del último
        
        prev_ultimo = pl->last;     El que antes era el último se iguala a prev_último
        
        prev_ultimo->next = new_n;  El siguiente de este será el nuevo nodo
        
        pl->last = new_n;           El último de la lista será ahora el nuevo nodo
        
        new_n->next = primero;      Y el siguiente del nuevo último, el primero
        */
    }
    return OK;
}

Status list_pushInOrder(List *pl, void *e, P_ele_cmp f, int order)
{
    float *ele[20], *ele_aux;
    int i, num, j, w = 0;

    if (pl == NULL || e == NULL)
    {
        return ERROR;
    }

    list_pushBack(pl, e);

    num = list_size(pl);

    fprintf(stdout, "SIZE: %ld\n", list_size(pl)); /*Tamaño de la lista*/

    list_print(stdout, pl, float_print);

    fprintf(stdout, "Finished inserting. Now we extract from the beginning and insert in order:\n");

    ele_aux = (float *)malloc(sizeof(float));

    for (i = 1; i <= num; i++)
    {

        ele[i - 1] = (float *)malloc(sizeof(float));

        if (i < num / 2)
        {
            ele[i - 1] = list_popFront(pl);
            fprintf(stdout, "%.6f ", *(float *)ele[i - 1]);
        }
        else
        {
            if (i - 1 == num / 2)
            {
                printf("\nNow we extract from the end and insert in order:\n");
            }

            ele[i - 1] = list_popBack(pl);
            fprintf(stdout, "%.6f ", *(float *)ele[i - 1]);
        }
    }

    printf("\n");

    for (i = 0; i < num; i++)
    {
        for (j = 0; j < num - 1; j++)
        {
            if (ele[j] < ele[j + 1])
            {
                ele_aux = ele[j];
                ele[j] = ele[j + 1];
                ele[j + 1] = ele_aux;
            }
        }
    }

    for (i = 0; i < num; i++)
    {

        if (order >= 0)
        {
            list_pushBack(pl, ele[i]);
        }
        if (order < 0)
        {
            list_pushFront(pl, ele[i]);
        }

        if (w == 0)
        {
            ele[i] = 0;
        }
        else
        {
            ele[w] = 0;
        }
    }

    fprintf(stdout, "\nSIZE: %d\n", num); /*Tamaño de la lista*/

    i = 0;

    list_print(stdout, pl, float_print);

    printf("\n");

    return OK;
}

void *list_popFront(List *pl)
{
    NodeList *nl = NULL; /*Nodo a extraer*/
    void *pe = NULL;

    if (pl == NULL || list_isEmpty(pl) == TRUE)
    {
        return NULL;
    }

    nl = pl->last->next; /*El nodo a extraer es el primero*/
    pe = nl->data;       /*Se guarda su dato en un auxiliar*/

    if (pl->last->next == pl->last) /*Si es el único elemento, se iguala a NULL*/
    {
        pl->last = NULL;
    }
    else
    {
        pl->last->next = nl->next; /*Sino, el siguiente, del último, el primero, será el siguiente del nodo a extraer*/
    }

    free(nl);

    return pe;
}

void *list_popBack(List *pl)
{
    NodeList *nl = NULL; /*Nodo a extraer*/
    void *pe = NULL;

    if (pl == NULL || list_isEmpty(pl) == TRUE)
    {
        return NULL;
    }

    if (pl->last->next == pl->last) /*Si solo hay un elemento*/
    {
        pe = pl->last->data; /*Se extrae el dato*/

        free(pl->last); /*Se libera el nodo*/

        pl->last = NULL; /*Se iguala a NULL*/

        return pe; /*Y devuelve el dato*/
    }

    nl = pl->last; /*Sino, el nodo a extraer será el último*/

    while (nl->next != pl->last) /*Y mientras su siguiente, el primero, sea distinto del último*/
    {
        nl = nl->next; /*El nodo se igualará a su siguiente*/
    }

    pe = pl->last->data;       /*Un vez se obtiene el dato*/
    nl->next = pl->last->next; /*El siguiente del nodo será el primero*/

    free(pl->last); /*Se libera la memoria*/

    pl->last = nl; /*Y el último será el que antes era penúltimo*/

    return pe;
}

void list_free(List *pl)
{

    if (pl == NULL)
    {
        return;
    }

    free(pl); /*Se libera la memoria*/
}

size_t list_size(const List *pl)
{
    int count = 0;
    NodeList *n;

    if (pl == NULL)
    {
        return -1;
    }

    if (!list_isEmpty(pl)) /*Si la lista no esta vacía*/
    {

        n = pl->last->next; /*El nodo será igual al primero*/

        do /*Y mientras el nodo sea distinto del primero otra vez*/
        {
            count++;
            n = n->next; /*El nodo será igual a sus siguiente y el contador sumara +1*/

        } while (n != pl->last->next);
    }

    return count;
}

int list_print(FILE *fp, const List *pl, P_ele_print f)
{
    int a = 0, i = 0, b = 0;
    long l_size;
    NodeList *n = NULL;

    l_size = list_size(pl); /*Se obtiene el tamaño de la lista*/

    if (fp == NULL || pl == NULL || f == NULL)
    {
        return -1;
    }

    n = pl->last->next; /*El nodo auxiliar será igual al primero*/

    for (i = 0; i < l_size; i++) /*Mientras no se haya impreso toda la lista*/
    {
        b = f(fp, n->data); /*Se imprimirá el dato del nodo*/

        if (b == -1) /*Si devuelve -1, significará que ha habido un error*/
        {
            return -1;
        }

        a = a + b; /*Sino, se sumará el valor a a*/

        n = n->next; /*Y el nodo se igualará a su siguiente*/
    }

    fprintf(fp, "\n");

    return a;
}

int float_print(FILE *fp, const void *e)
{
    if (fp == NULL || e == NULL)
    {
        return -1;
    }

    fprintf(stdout, "%.6f ", *(float *)e);
    return 1;
}