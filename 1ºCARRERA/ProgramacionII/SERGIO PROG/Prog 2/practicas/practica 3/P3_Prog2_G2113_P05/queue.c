/*
*Título: Funciones queue, práctica 3, programación 2
*Grupo: viernes 2113
*Autores: Sergio Hidalgo y Miguel Ibáñez 
*/

#include <stdlib.h>
#include "queue.h"
#include "types.h"

#define MAX_QUEUE 20

struct _Queue
{
    void *data[MAX_QUEUE];
    void **front;
    void **rear;
};

Bool queue_isFull(const Queue *q);

Queue *queue_new()
{
    int i;
    Queue *q = NULL;

    q = (Queue *)malloc(sizeof(Queue)); /*Reserva de memoria de la cola*/
    if (q == NULL)
    {
        return NULL;
    }

    for (i = 0; i < MAX_QUEUE; i++)
    {
        q->data[i] = NULL;
    }

    q->front = NULL;
    q->rear = NULL;

    return q;
}

void queue_free(Queue *q)
{
    if (q == NULL)
    {
        return;
    }

    free(q); /*Liberación de la cola*/
}

Bool queue_isEmpty(const Queue *q)
{
    if (q == NULL)
    {
        return TRUE;
    }

    if (queue_size(q) == 0) /*Si el tamaño es 0, es que esta vacía*/
    {
        return TRUE;
    }

    return FALSE;
}

Bool queue_isFull(const Queue *q)
{
    if (q == NULL)
    {
        return TRUE;
    }

    if ((queue_size(q) == MAX_QUEUE)) /*Si el tamaño es igual al tamaño máximo, está llena*/
    {
        return TRUE;
    }

    return FALSE;
}

Status queue_push(Queue *q, void *ele)
{
    long size_q = 0;
    if (q == NULL || ele == NULL || queue_isFull(q) == TRUE) /*Control de errores*/
    {
        return ERROR;
    }

    size_q = queue_size(q);

    q->data[size_q] = ele; /*El dato (posición según tamaño) será igual al elemento*/

    if (size_q == 0)
    {
        q->front = q->data[size_q]; /*El frente será igual a ese dato si la cola está vacía*/
    }

    q->rear = q->data[size_q]; /*El último dato, sera ese, pues ha sido el último en añadirse*/

    return OK;
}

void *queue_pop(Queue *q)
{
    void **e;
    int i;

    if (q == NULL || queue_isEmpty(q) == TRUE)
    {
        return NULL;
    }

    for (i = 0; i < MAX_QUEUE; i++) /*Se busca el primer dato no nulo*/
    {
        if (q->data[i] != NULL)
        {
            break;
        }
    }

    e = q->data[i];            /*Se iguala al elemento*/
    q->front = q->data[i + 1]; /*El front será igual al siguiente*/

    q->data[i] = NULL; /*El anterior será igual a NULL*/

    return e;
}

void *queue_getBack(const Queue *q)
{

    if (q == NULL || queue_isEmpty(q) == TRUE)
    {
        return NULL;
    }

    return q->rear; /*Se obtiene un puntero al último elemento*/
}

void *queue_getFront(const Queue *q)
{

    if (q == NULL || queue_isEmpty(q) == TRUE)
    {
        return NULL;
    }

    return q->rear; /*Se obtiene un puntero al primer elemento*/
}

size_t queue_size(const Queue *q)
{
    int i, count = 0;

    if (q == NULL)
    {
        return 0;
    }

    for (i = 0; i < MAX_QUEUE; i++)
    {
        if (q->data[i] == NULL) /*Si el elemento es no nulo se sumará 1*/
        {
        }
        else
        {
            count++;
        }
    }

    return count;
}

int queue_print(FILE *fp, const Queue *q, p_queue_ele_print f)
{
    int a = 0, i = 0;

    if (fp == NULL || q == NULL || f == NULL)
    {
        return 0;
    }

    for (i = 0; q->data[i] != NULL; i++)    /*Se printea si el dato no es NULL*/
    {
        a = a + f(fp, q->data[i]);
    }

    fprintf(fp, "\n");

    return a;
}