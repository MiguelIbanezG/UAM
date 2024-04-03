#include <stdio.h>
#include <stdlib.h>
#include "queue.h"
#include "types.h"

Queue *interleave(Queue *q) {

  Queue *qinter = NULL;
  int taman,i;
  char **aux1,**aux2;
  
  qinter = queue_new();

  if (!qinter) {

    return NULL;

  }
  
  taman = queue_size(q);

  if (taman % 2 == 0){

    aux1 = (char **)calloc((taman/2), sizeof(int*));
    aux2 = (char **)calloc((taman/2), sizeof(int*));

    for (i = 0; i < taman/2; i++)
    {
      aux1[i] = queue_pop(q);
    }

     for (i = 0; i < taman/2; i++)
    {
      aux2[i] = queue_pop(q);
    }

     for (i = 0; i < taman/2; i++)
    {

        queue_push(qinter,aux1[i]);
        queue_push(qinter,aux2[i]);

        
    }
  }
  else{

    aux1 = (char **)calloc((taman/2)+1, sizeof(int*));
    aux2 = (char **)calloc((taman/2), sizeof(int*));

    for (i = 0; i < (taman/2) +1; i++)
    {
      aux1[i] = queue_pop(q);
    }

     for (i = 0; i < taman/2; i++)
    {
      aux2[i] = queue_pop(q);
    }

     for (i = 0; i < taman/2; i++)
    {

        queue_push(qinter,aux1[i]);
        queue_push(qinter,aux2[i]);

    }
    queue_push(qinter,aux1[i]);

  }

  free(aux1);
  free(aux2);

  return qinter;

}

  
Status concatenate(Queue *qa, Queue *qb) {

  int i,taman;

    if ((qb == NULL) || (qa == NULL) || ((queue_size(qa) + queue_size(qb)) > 10)) 
    {
      return ERROR;
    }
    
    
    taman = queue_size(qb) + queue_size(qa);
    
    for (i = 0; i < taman; i++) 
    {
      queue_push (qa, queue_pop(qb));
    }

  return OK;
}
