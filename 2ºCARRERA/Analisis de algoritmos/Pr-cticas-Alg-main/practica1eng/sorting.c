/**
 *
 * Descripcion: Implementation of sorting functions
 *
 * Fichero: sorting.c
 * Autor: Carlos Aguirre
 * Version: 1.0
 * Fecha: 19-10-2021
 *
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "permutations.h"
#include "sorting.h"
#include <assert.h>

#define NDBUG

/***************************************************/
/* Function: BubbleSort    Date:  06/10/2021       */
/* Authors: Alberto Vicente y Miguel Ibañez        */
/*                                                 */
/* Rutine that sort a permutation by               */
/* comparing elements in the array                 */
/*                                                 */
/* Input:                                          */
/* int* array: The permutation to sort             */
/* int ip: starting point in the array             */
/* int iu: last number in the array                */
/* Output:                                         */
/* int: obs needing                                */
/***************************************************/
int BubbleSort(int* array, int ip, int iu)
{
  int i, j, ob=0;

  assert(ip>=0);

  for(i=iu;i>ip;i--)
    for(j=ip;j<i;j++){
      ob++;
      if(array[j]>array[j+1])
        swap(&array[j],&array[j+1]);
      
    }
  

  return ob;
}

int BubbleSortFlag(int* array, int ip, int iu)
{

  int flag=1, i, j, ob=0;

  assert(ip>=0);

  for(i=iu;flag==1 && i>ip;i--){
    flag=0;
    for(j=ip;j<i;j++){
      ob++;
      if(array[j]>array[j+1]){
        swap(&array[j],&array[j+1]);
        flag=1;
      }
    }
  }

  return ob;
}


/***************************************************/
/* Function: MergeSort     Date:  06/10/2021       */
/* Authors: Alberto Vicente y Miguel Ibañez        */
/*                                                 */
/* Rutine that sort a permutation by               */
/* comparing elements in the array                 */
/*                                                 */
/* Input:                                          */
/* int* array: The permutation to sort             */
/* int ip: starting point in the array             */
/* int iu: last number in the array                */
/* Output:                                         */
/* int: obs needing                                */
/***************************************************/
int mergesort(int* tabla, int ip, int iu) {

  int m, a, b;

  assert(ip>=0);

  if(ip>iu) return ERR;

  if(ip==iu) return OK;
  
  else {
    m=(iu+ip)/2;
    a=mergesort(tabla,ip,m);
    b=mergesort(tabla,m+1,iu);
    if (a==ERR || b==ERR) return ERR;
    return a + b + merge(tabla,ip,iu,m);
  }
}

int merge(int* tabla, int ip, int iu, int imedio){

  int* aux;
  int i, j, k, ob=0;
  
  aux=(int*) malloc((iu-ip+1)*sizeof(int));

  if(aux==NULL) return ERR;

  i=ip;
  j=imedio+1;
  k=0;

  while(i<=imedio && j<=iu){
    ob++;
    if(tabla[i]<tabla[j]){
      aux[k]=tabla[i];
      i++;
    }
    else {
      aux[k]=tabla[j];
      j++;
    }
    k++;
  }

  if (i>imedio)
    while(j<=iu){
      aux[k]=tabla[j];
      j++;
      ob++;
      k++;
    }
  
  else if (j>iu)
    while(i<=imedio){
      aux[k]=tabla[i];
      i++;
      ob++;
      k++;
    }
  

  copiar(aux,tabla,ip,iu);
  free(aux);

  return ob;
}

int copiar(int* aux, int* tabla, int ip, int iu){
  int i;
  
  for(i=ip;i<=iu;i++)
    tabla[i]=aux[i-ip];
  
  return OK;
}

int quicksort(int* tabla, int ip, int iu){

  int pos=ip, o=0, b=0, ob=0;

  assert(ip>=0);

  if(ip>iu) return ERR;

  if(ip==iu) return OK;

  else{
    ob=partition(tabla,ip,iu,&pos);
    if(ip<pos-1)
      o=quicksort(tabla,ip,pos-1);
    if(pos+1<iu)
      b=quicksort(tabla,pos+1,iu);
      
    if(o==ERR || b== ERR) return ERR;
  }
  return o + b + ob;
}

int partition(int* tabla, int ip, int iu,int *pos){

  int k, i, ob=0;

  median(tabla,ip,iu,pos);

  k=tabla[*pos];
  swap(&tabla[ip],&tabla[*pos]);

  *pos=ip;

  for(i=ip;i<=iu;i++){
    ob++;
    if(tabla[i]<k){
      *pos=*pos+1;
      swap(&tabla[i],&tabla[*pos]);
    }
  }
  swap(&tabla[ip],&tabla[*pos]);

  return ob;
}

int median(int *tabla, int ip, int iu,int *pos){

  assert(ip>=0);

  *pos=ip;

  return OK;
}

int quicksort_src(int* tabla, int ip, int iu){

  int pos=ip, ob=0;

  assert(ip>=0);

  while(ip<iu){
    ob+=partition(tabla,ip,iu,&pos);
    if(ip<pos-1)
      ob+=quicksort(tabla,ip,pos-1);
    if(pos+1<=iu)
      ip=pos+1;
  }

  return ob;
}
