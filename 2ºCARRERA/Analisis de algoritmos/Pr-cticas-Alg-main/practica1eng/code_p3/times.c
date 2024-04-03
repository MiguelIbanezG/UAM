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
#include "search.h"
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
  int **perms, i, aux;
  clock_t ini, fin;

  perms=generate_permutations(n_perms,N);
  ptime->n_elems=n_perms;
  ptime->N=N;
  ptime->min_ob=0;
  ptime->max_ob=0;
  ptime->average_ob=0;

  ini=clock();
  for(i=0;i<n_perms;i++){
    aux=metodo(perms[i],0,N-1);
    ptime->average_ob+=aux;
    if(ptime->min_ob>aux) ptime->min_ob=aux;
    if(ptime->max_ob<aux) ptime->max_ob=aux;
  }
  fin=clock();

  ptime->average_ob=(double) ptime->average_ob/n_perms;
  ptime->time = (double) (fin-ini)/n_perms/CLOCKS_PER_SEC;

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




short average_search_time(pfunc_search method, pfunc_key_generator generator, char order, int N, int n_times, PTIME_AA ptime){

  PDICT dict;
  int *perm, *keys, i, aux, pos;
  clock_t ini, fin;

  dict=init_dictionary(N,order);
  if(dict==NULL) return ERR;

  perm=generate_perm(N);
  if(dict==NULL) {
    free_dictionary(dict);
    return ERR;
  }

  if (massive_insertion_dictionary(dict,perm,N)==ERR){
    free_dictionary(dict);
    free(perm);
    return ERR;
  }

  keys=(int*) malloc(n_times*N*sizeof(int));
  if(keys==NULL){
    free_dictionary(dict);
    free(perm);
    return ERR;
  }

  generator(keys,n_times*N,N);

  ptime->N=N;
  ptime->n_elems=N*n_times;

  ptime->max_ob=0;
  ptime->average_ob=0;

  ini=clock();
  for(i=0;i<ptime->n_elems;i++){
    aux=method(keys,0,ptime->n_elems,keys[i],&pos);
    if(i==0) ptime->min_ob=aux;
    else if(ptime->min_ob>aux) ptime->min_ob=aux;
    if(ptime->max_ob<aux) ptime->max_ob=aux;
    ptime->average_ob+=aux;
  }
  fin=clock();

  ptime->average_ob=(double) ptime->average_ob/ptime->n_elems;
  ptime->time = (double) (fin-ini)/ptime->n_elems/CLOCKS_PER_SEC;

  free_dictionary(dict);
  free(perm);
  free(keys);

  return OK;
}

short generate_search_times(pfunc_search method, pfunc_key_generator generator, int order, char* file, int num_min, int num_max, int incr, int n_times){

  PTIME_AA array=NULL;
  int N, i, nt;

  nt=(num_max-num_min)/incr+1;
  
  assert(file != NULL);
  assert(method != NULL);
  assert(generator != NULL);

  array=(PTIME_AA) malloc(nt*sizeof(TIME_AA));
  if(array==NULL) return ERR;

  assert(num_min <= num_max);
  assert(num_min>=0);

  for(N=num_min,i=0;i<nt;N+=incr, i++)
    if(average_search_time(method,generator,order,N,n_times,&array[i])==ERR) return ERR;
    
  if(save_time_table(file,array,nt)==ERR) return ERR;
  free(array);

  return OK;
}