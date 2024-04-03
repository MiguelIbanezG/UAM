#include "elements.h"
#include "list.h"
#include "types.h"
#include <stdlib.h>

/**
 * @brief Public function that pushes an element into a sorted List.
 *
 * Inserts into the corresponding position the element received as argument.
 *
 * @param pl Pointer to the List.
 * @param e Element to be inserted into the List.
 * @param f Pointer to the compare function.

 *
 * @return Status value OK if the insertion could be done, Status value ERROR
 * otherwise.
 */
Status list_pushSorted (List *pl, const void *e, elem_cmp_fn elem_cmp)
{
  Node *pn = NULL, *pnq = NULL, *p_aux;

  if (!pl || !e || !elem_cmp)
  {
    return ERROR;
  }

  pnq = node_new(); /*Nuevo nodo (guarda los nuevos datos)*/

  if (list_isEmpty(pl))
  { /*Si esta vacía se guarda en el nuevo nodo*/
    pl->first = pnq;
    pnq->info = (void *)e;

    return OK;
  }

  pn = pl->first; /*el nuevo nodo será el*/

  while (pn != NULL)
  {
    if (elem_cmp(pn->info, e) < 0)
    { /*Si el nodo es mayot que el nodo de la lista se inserta antes*/
      pnq->next = pn->next;
      pn->next = pnq;
      pnq->info = pn->info;
      pn->info = (void *)e;

      return OK;
    }
    p_aux = pn; /*Si no, se checkean otros nodos de la lista*/
    pn = pn->next;
  }

  pn = p_aux; /*Si no hay ninguno más pequeño, será el último*/
  pnq->info = (void *)e;
  pn->next = pnq;

  return OK;
}

/**
 * @brief Public function that sorts an integer array.
 *
 *
 * @param array An integer array.
 * @param n_elem Size of array

 *
 * @return Status value OK if array sorted without problems, Status value ERROR
 * otherwise. The array is sorted in decreasing order upon return.
 */

Status sort_int_array (int *array, int n_elem)
{

  List *lp = NULL; 
  void *aux = NULL;
  int c = 0;
  int aux_em[n_elem];

  lp = list_new ();
  if (!array || n_elem == 0)
  { 
    return ERROR;
  }
  for (int i = 0; i < n_elem; i++)
  { 
    /*Se pasa a una función que los ordena*/
    list_pushSorted (lp, array + i, int_cmp);
  }
  while (list_isEmpty (lp) == FALSE)
  { 
    /*se pasan a una variable auxiliar para que lleguen a la array*/
    aux = list_popFront (lp);
    aux_em[c] = *(int *)aux;
    c++;
  }
  free (lp);
  for (int i = 0; i < n_elem; i++)
  { 
    /*se pasa la array auxiliar a la original*/
    array[i] = aux_em[i];
  }
  return OK;
}