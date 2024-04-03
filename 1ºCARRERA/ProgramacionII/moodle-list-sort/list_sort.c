#include "elements.h"
#include "list.h"
#include "list_sort.h"
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
Status list_pushSorted(List *pl, const void *e, elem_cmp_fn elem_cmp)
{

  int a, i=0;
  Node *pn = NULL, *qn = NULL;
  void *ele;

  if (pl == NULL || e == NULL || elem_cmp == NULL)
  {
    return ERROR;
  }
  pn = node_new();

  if (pn == NULL)
  {
    return ERROR;
  }

  pn->info = (void *)e;
  
  if (list_isEmpty(pl) == TRUE)
  {
    pl->first = pn;
    return OK;
  }

  else
  {

    qn = pl->first;

    while ( qn->next != NULL)
    {
      qn = qn -> next;
      ele = qn; 
      a = elem_cmp(ele,e);

        if(a>0) 
        {
            qn->next = qn->info;
            qn->info = pn;
            return OK;
            break;
        }
    
    }

    if(i==0)
    {
      qn->next = pn;
      return OK;
    }
    
  }
return ERROR;

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

Status sort_int_array(int *array, int n_elem){ 
  return ERROR; 
  }