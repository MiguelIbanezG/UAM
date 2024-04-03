#include <stdio.h>
#include "queue.h"
#include <string.h>
#include <stdlib.h>
#include "types.h"

struct _Queue {
  void* items [MAXQUEUE];
  int front;
  int rear;
  destroy_element_function_type    destroy_element_function;
  copy_element_function_type        copy_element_function;
  print_element_function_type         print_element_function;
};

Queue* queue_ini(destroy_element_function_type f1, copy_element_function_type f2, print_element_function_type f3){
  Queue *q = NULL;
  int i;

  q = (Queue*)malloc(sizeof(Queue));

  if(q == NULL){
    return NULL;
  }

  q->front = 0;
  q-> rear = 0;

  for(i = 0; i < MAXQUEUE;i++){
    q-> items[i] = NULL;
  }
  q->destroy_element_function = f1;
  q->copy_element_function = f2;
  q->print_element_function = f3;

  return q;
}

void queue_destroy(Queue *q){
  int i;

  if (q == NULL){
    return;
  }

  for(i = 0; i < MAXQUEUE; i++){
    q->destroy_element_function(q->items[i]);
    q->items[i] = NULL;
  }
  free(q);
}

Bool queue_isEmpty(const Queue* q){

  if(q == NULL) return TRUE;

  if(q->front == q->rear){
    return TRUE;
  }
  return FALSE;
}

Bool queue_isFull(const Queue* q){
  if(q == NULL) return TRUE;

  if ((q->rear+1 % MAXQUEUE) == (q->front % MAXQUEUE)){
    return TRUE;
  }
  return FALSE;
}

Status queue_insert(Queue *q, const void* pElem){
  void *ele = NULL;

  if(q == NULL || pElem == NULL || queue_isFull(q) == TRUE) return ERROR;

  ele = q->copy_element_function(pElem);
  if (ele == NULL) return ERROR;

  q->items[q->rear] = ele;
  q->rear = (q->rear + 1) % MAXQUEUE;

  return OK;
}

void* queue_extract(Queue *q){
  void *ele = NULL;

  if(q == NULL || queue_isEmpty(q) == TRUE) return NULL;

  ele = q->items[q->front];
  q->items[q->front] = NULL;
  q->front = (q->front + 1) % MAXQUEUE;

  return ele;
}

int queue_size(const Queue *q){

    if(!q) return -1;

    if(q->rear < q->front){

        return (q->rear + MAXQUEUE) - q->front;

    }
    else
        return q->rear - q->front;

}

int queue_print(FILE *pf, const Queue *q){
    int i, suma = 0;

    if (pf==NULL||q==NULL)return -1;

    if(queue_isEmpty(q) == TRUE) fprintf(pf, "Queue vacía.\n");

    for(i = q->front; i <= q->rear; i++)
      suma += q-> print_element_function(pf, q->items[i]);

    return i;
}
