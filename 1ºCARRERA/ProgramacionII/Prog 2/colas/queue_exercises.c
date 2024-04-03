/*Creado por Sergio Hidalgo, Programación 2, 213*/
#include <stdio.h>
#include <stdlib.h>
#include "queue.h"
#include "types.h"

/* Include here any other headers you need */

/**
 * @brief Returns a new queue that interleaves the elements in the first and 
 * second halves of a queue.
 *
 * Examples:
 *
 * Input:  [1, 2, 3, 4, 5, 6]
 * Output: [1, 4, 2, 5, 3, 6]
 *
 * Input:  [1, 2, 3, 4, 5]
 * Output: [1, 4, 2, 5, 3]
 *
 * @see https://www.geeksforgeeks.org/interleave-first-half-queue-second-half/
 *
 * @param q, pointer to the queue.
 *
 * @return A new queue with the elements in the first and second halves of q
 * interleaved. See example above.
 **/
Queue *interleave(Queue *q)
{
  Queue *qinter;
  int tam, i;
  char **cola1 = NULL, **cola2 = NULL;

  if (q == NULL) /*Control de errores*/
  {
    return q;
  }

  qinter = queue_new(); /*Inicialización de la cola intercalada*/
  if (!qinter)
  {
    return NULL;
  }

  tam = (int)queue_size(q); /*Tamaño de la cola*/

  if ((tam % 2) == 0) /*Si es par*/
  {

    cola1 = (char **)calloc((tam / 2), sizeof(int *)); /*Se reserva la memoria de las arrays auxiliares*/
    cola2 = (char **)calloc((tam / 2), sizeof(int *));

    for (i = 0; i < tam / 2; i++) /*Se guarda la primera parte en una array*/
    {
      cola1[i] = queue_pop(q);
    }

    for (i = 0; i < tam / 2; i++) /*La segunda en otra*/
    {
      cola2[i] = queue_pop(q);
    }

    for (i = 0; i < tam / 2; i++) /*Se van metiendo los elementos en la cola intercalados*/
    {

      queue_push(qinter, cola1[i]);
      queue_push(qinter, cola2[i]);
    }
  }
  else /*Si es impar*/
  {
    cola1 = (char **)calloc((tam / 2) + 1, sizeof(int *)); /*Se reservará la memoria pero la primera array tiene 1 elemento más*/
    cola2 = (char **)calloc((tam / 2), sizeof(int *));

    for (i = 0; i < (tam / 2) + 1; i++) /*Lo mismo pasa a la hora de introducir los elementos en la array*/
    {
      cola1[i] = queue_pop(q);
    }

    for (i = 0; i < tam / 2; i++)
    {
      cola2[i] = queue_pop(q);
    }

    for (i = 0; i < (tam / 2); i++) /*Se introducen en la cola*/
    {

      queue_push(qinter, cola1[i]);
      queue_push(qinter, cola2[i]);
    }
    queue_push(qinter, cola1[i]); /*Pero al ser impares el push del último elemento de la primera array se hace fuera del bucle*/
  }

  free(cola1); /*Se libera la memoria y se devuelve la cola*/
  free(cola2);

  return qinter;
}

/**
 * @brief Concatenates two queues by adding all the elements in the second queue
 * to the first one. Upon successful exit the first queue will contain the 
 * elements from both queues and the second queue will be empty. In case of 
 * error the two queues will be unchanged.
 *
 * Example:
 *
 * Before concatenation: qa = [1, 2, 3, 4, 5, 6]
 *                       qb = [1, 2, 3, 4]
 *
 * After concatenation:  qa = [1, 2, 3, 4, 5, 6, 1, 2, 3, 4]
 *                       qb = []
 *
 * @param qa, pointer to the first queue.
 * @param qb, pointer to the second queue.
 *
 * @return OK on success, ERROR if there is any error. In case of error the 
 * contents of both queues must remain unchanged.
 **/
Status concatenate(Queue *qa, Queue *qb)
{
  Queue *qconct;
  int i, tama, tamc;
  char *aux;

  if ((qb == NULL) || (qa == NULL)) /*Control de errores*/
  {
    return ERROR;
  }

  qconct = queue_new(); /*Inicialización de la cola concatenada*/
  if (!qconct)
  {
    return ERROR;
  }

  tama = queue_size(qa); /*Tamaño de la cola a*/

  while(!queue_isEmpty(qa)) /*Se pasarán los elementos de la cola a a la cola de concatención*/
  {

    queue_push(qconct, queue_pop(qa));
  }

  while(!queue_isEmpty(qb)) /*Se pasarán los elementos de la cola b a la cola de concatención*/
  {

    aux = queue_pop(qb); /*Se guarda el elemento para no perderlo*/
    queue_push(qconct, aux);

    if (queue_getBack(qconct) != aux) /*En caso de que sea distinto se invierte el proceso*/
    {
      for (i = 0; i < tama; i++) /*Se pasarán los elementos de la cola de concatención a la cola a*/
      {
        queue_push(qa, queue_pop(qconct));
      }

      tamc = queue_size(qconct); /*Tamaño de la cola c*/

      for (i = 0; i < tamc; i++) /*Se pasarán los elementos de la cola de concatención a la cola b*/
      {
        queue_push(qb, queue_pop(qconct));
      }

      queue_push(qb, aux); /*Y por último el elemento que no se pudo pasar*/

      queue_free(qconct); /*Se libera la cola de concatenación y devuelve 1 error*/

      return ERROR;
    }
  }

  tamc = queue_size(qconct);

  while(!queue_isEmpty(qconct)) /*Si todo ha ido bien se pasarán los elementos de la cola de concatenación a la cola a*/
  {
    queue_push(qa, queue_pop(qconct));
  }

  queue_free(qconct); /*Y se liberarña su memoria*/

  return OK;
}
