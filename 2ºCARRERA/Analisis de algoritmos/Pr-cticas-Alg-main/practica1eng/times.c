/**
 *
 * Descripcion: Implementation of time measurement functions
 *
 * Fichero: times.c
 * Autor: Alberto Vicente y Miguel Ibáñez
 * Version: 1.0
 * Fecha: 19-10-2021
 *
 */

#include "times.h"
#include "sorting.h"
#include "permutations.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>

/***************************************************/
/* Function: average_sorting_time Date: 13/10/2021 */
/*                                                 */
/* Authors: Alberto Vicente y Miguel Ibañez        */
/*                                                 */
/* Save in a structure all the important data,     */
/* including the time needed to sort the perm      */
/*                                                 */
/* Input:                                          */
/* pfunc_sort metodo: function which sort the perm */
/* int n_perms: number of perms                    */
/* int N: size of perms                            */
/* PTIME_AA ptime: pointer to the struct           */
/* Output:                                         */
/* int: STATUS                                     */
/***************************************************/

short average_sorting_time(pfunc_sort metodo, int n_perms, int N, PTIME_AA ptime) {
  int **perms, *ob, i, n;
  clock_t ini, fin;

  ob=(int*) malloc(n_perms*sizeof(int));
  if(!ob) return ERR;

  perms=generate_permutations(n_perms,N);
  if(perms==NULL) return ERR;

  ptime->n_elems=n_perms;
  ptime->N=N;

  ini=clock();
  for(i=0;i<n_perms;i++)
    ob[i]=metodo(perms[i],0,N-1);
  fin=clock();

  ptime->min_ob=ob[0];
  ptime->max_ob=ob[0];

  for(i=n=0;i<n_perms;i++){
    if(ptime->min_ob>ob[i]) ptime->min_ob=ob[i];
    if(ptime->max_ob<ob[i]) ptime->max_ob=ob[i];
    n+=ob[i];
  }

  ptime->average_ob=(double) n/n_perms;
  ptime->time = (double) (fin-ini)/n_perms/CLOCKS_PER_SEC;

  free(ob);
  for(i=0;i<n_perms;i++)
    free(perms[i]);
  free(perms);

  return OK;
}

/***************************************************/
/* Function: average_sorting_time Date: 13/10/2021 */
/*                                                 */
/* Authors: Alberto Vicente y Miguel Ibañez        */
/*                                                 */
/* Call the previous function and                  */
/* save in file the structure data                 */
/*                                                 */
/* Input:                                          */
/* pfunc_sort metodo: function which sort the perm */
/* char* file: file where data is saved            */
/* int num_min: min size of perm                   */
/* int num_max: max size of perm                   */
/* int incr: incremental number                    */
/* int n_perms: number of perms                    */
/* Output:                                         */
/* int: STATUS                                     */
/***************************************************/
short generate_sorting_times(pfunc_sort method, char* file, int num_min, int num_max, int incr, int n_perms) {

  PTIME_AA array=NULL;
  int N, i, n_times;

  n_times=(num_max-num_min)/incr+1;
  
  assert(file != NULL);
  assert(method != NULL);

  array=(PTIME_AA) malloc(n_times*sizeof(TIME_AA));
  if(!array) return ERR;

  assert(num_min <= num_max);
  assert(num_min>=0);

  for(N=num_min,i=0;i<n_times;N+=incr, i++)
    if(average_sorting_time(method,n_perms,N,&array[i])==ERR) return ERR;

  if(save_time_table(file,array,n_times)==ERR) return ERR;

  free(array);

  return OK;
}

/***************************************************/
/* Function: average_sorting_time Date: 13/10/2021 */
/*                                                 */
/* Authors: Alberto Vicente y Miguel Ibañez        */
/*                                                 */
/* Save in file the structure data                 */
/*                                                 */
/* Input:                                          */
/* char* file: file where data is saved            */
/* PTIME_AA ptime: struct which is saved           */
/* int n_times: number of perms with different size*/
/* Output:                                         */
/* int: STATUS                                     */
/***************************************************/
short save_time_table(char* file, PTIME_AA ptime, int n_times)
{
  FILE *f;
  int i;

  assert(n_times>=0);

  f=fopen(file,"w");
  if(f==NULL) return ERR;

  for (i=0;i<n_times;i++)
    fprintf(f," %d %.6f %.6f %d %d\n", ptime[i].N, ptime[i].time, ptime[i].average_ob, ptime[i].max_ob, ptime[i].min_ob);

  fclose(f);

  return OK;
}