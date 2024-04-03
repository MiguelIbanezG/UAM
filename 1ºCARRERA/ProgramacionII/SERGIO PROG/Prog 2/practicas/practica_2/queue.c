/*
*Título: Ejercicio 2, práctica 3, programación 2
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

    q = (Queue *)malloc(sizeof(Queue));
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

    free(q);
}

Bool queue_isEmpty(const Queue *q)
{
    if (q == NULL)
    {
        return TRUE;
    }

    if (queue_size(q) == 0)
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

    if ((q->front == (q->rear)) && (queue_size(q) != 0))
    {
        return TRUE;
    }

    return FALSE;
}

Status queue_push(Queue *q, void *ele)
{
    long size_q = 0;
    if (q == NULL || ele == NULL)
    {
        return ERROR;
    }


    size_q = queue_size (q);
    

    q->data[size_q] = ele;

    if (size_q == 0)
    {
        q->front = q->data[size_q];
    }

    q->rear = q->data[size_q];

    
    

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

    for (i = 0; i < MAX_QUEUE; i++)
    {
        if (q->data[i] != NULL)
        {
            break;
        }
        
    }
    

    e = q->data[i];
    q->front = q->data[i+1];
    
    q->data[i] = NULL;

    return e;
}

void *queue_getBack(const Queue *q)
{
    int back;

    if (q == NULL || queue_isEmpty(q) == TRUE)
    {
        return NULL;
    }


    return q->rear;
}

void *queue_getFront(const Queue *q)
{

    if (q == NULL || queue_isEmpty(q) == TRUE)
    {
        return NULL;
    }

    return q->rear;
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
        if (q->data[i] == NULL)
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
    long s_size = queue_size(q);

    if (fp == NULL || q == NULL || f == NULL)
    {
        return 0;
    }

    for (i = 0; i < s_size; i++)
    {
        a = a + f(fp, q->data[i]);
    }

    fprintf(fp, "\n");

    return a;
}