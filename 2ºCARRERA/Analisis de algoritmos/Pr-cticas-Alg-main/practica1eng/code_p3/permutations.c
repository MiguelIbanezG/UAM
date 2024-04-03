/**
 *
 * Descripcion: Implementation of function that generate permutations
 *
 * File: permutations.c
 * Autor: Alberto Vicente y Miguel Ibañez
 * Version: 1.1
 * Fecha: 21-09-2019
 *
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include "permutations.h"

#define NDBUG



void swap(int *a, int *b){

  int aux;

  aux=*a;
  *a=*b;
  *b=aux;
}

/***************************************************/
/* Function: random_num Date: 29/09/2021           */
/* Authors: Alberto Vicente y Miguel Ibañez        */
/*                                                 */
/* Rutine that generates a random number           */
/* between two given numbers                       */
/*                                                 */
/* Input:                                          */
/* int inf: lower limit                            */
/* int sup: upper limit                            */
/* Output:                                         */
/* int: random number                              */
/***************************************************/
int random_num(int inf, int sup)
{

  assert(inf>=0);
  assert(sup>=inf);

  return inf + rand() % (sup-inf+1);
}

/***************************************************/
/* Function: generate_perm Date: 29/09/2021        */
/* Authors: Alberto Vicente y Miguel Ibañez        */
/*                                                 */
/* Rutine that generates a random permutation      */
/*                                                 */
/* Input:                                          */
/* int n: number of elements in the permutation    */
/* Output:                                         */
/* int *: pointer to integer array                 */
/* that contains the permitation                   */
/* or NULL in case of error                        */
/***************************************************/
int* generate_perm(int N)
{
  int i, *perm;

  assert(N>=0);

  perm=(int*) malloc(N*sizeof(int));
  if(perm==NULL) return NULL;

  for(i=0;i<N;i++)
    perm[i]=i+1;

  for (i=0;i<N;i++)
    swap(&perm[i],&perm[random_num(i,N-1)]);
    
  return perm;
}

/***************************************************/
/* Function: generate_permutations Date:29/09/2021 */
/* Authors: Alberto Vicente y Miguel Ibañez        */
/*                                                 */
/* Function that generates n_perms random          */
/* permutations with N elements                    */
/*                                                 */
/* Input:                                          */
/* int n_perms: Number of permutations             */
/* int N: Number of elements in each permutation   */
/* Output:                                         */
/* int**: Array of pointers to integer that point  */
/* to each of the permutations                     */
/* NULL en case of error                           */
/***************************************************/
int** generate_permutations(int n_perms, int N)
{
  int i, j, **perm;

  assert(n_perms>=0);
  assert(N>=0);

  perm=(int**) malloc(n_perms*sizeof(int*));
  if(perm==NULL) return NULL;

  for(i=0;i<n_perms;i++){
    perm[i]=generate_perm(N);
    if(perm[i]==NULL){
      for(j=0;j<i;j++)
        free(perm[j]);
      free(perm);
      return NULL;
    }
  }

  return perm;
}