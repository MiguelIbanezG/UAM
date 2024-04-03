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
      k++;
    }
  
  else if (j>iu)
    while(i<=imedio){
      aux[k]=tabla[i];
      i++;
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

/*
int quicksort_src(int* tabla, int ip, int iu) {

  int obs=0, m=0, aux=0;

  if(tabla==NULL || ip>iu || ip<0){
    return ERR;
  }

  if(ip==iu)
    return 0;

  while(ip<iu){
    aux=partition(tabla, ip, iu, &m);
    if(aux==ERR){
      return ERR;
    }
    obs+=aux;
    if(ip<(m-1)){
        aux=quicksort_src(tabla,ip, m-1);       
        if(aux==ERR)
          return ERR;
        
        obs+=aux;
    }
    ip=m+1;
  }  
  return obs;
}

int quicksort_src2(int* tabla, int ip, int iu) {
  int obs=0, m=0, aux=0;

  if(tabla==NULL || ip>iu || ip<0||iu<0){
    return ERR;
  }

  if(ip==iu)
    return 0;

  while(ip<iu){
    aux=partition(tabla, ip, iu, &m);
    if(aux==ERR){
      return ERR;
    }
    obs+=aux;
    if(iu>(m+1)){
        aux=quicksort_src(tabla,m+1, iu);       
        if(aux==ERR)
          return ERR;
        
        obs+=aux;
    }
    iu=m-1;
  }  
  return obs; 
}

int quicksort_src3(int *tabla, int ip, int iu){
 int izda=0, dcha=0, m=0, ob=0, aux=0;

 if(tabla==NULL||ip<0||iu<ip) return ERR;

 while(ip<iu){
   aux=partition(tabla, ip, iu, &m);
   if(aux==ERR){
     return ERR;
   }

   ob+=aux;
   izda=m-1-ip;
   dcha=iu-(m+1);

   if(izda<dcha){
     aux=quicksort_src3(tabla, ip, m-1);
     if(aux==ERR){
       return ERR;
     }
     ob+=aux;
     iu=m-1;
   }
   else{
     aux=quicksort_src3(tabla, m+1, iu);
     if(aux==ERR){
       return ERR;
     }
     ob+=aux;
     ip=m+1;
   }
 }
 return ob;
  
}

int selectsort(int *tabla, int n) {

  int ob = 0;
  int min = 0;
  int i = 0;
 
    for (i = 0; i < n-1; i++)  
    {  
        min = i;  
        for (int j = i+1; j < n; j++){}
          if (tabla[j] < tabla[min]){
            min = j;
            ob++;
            swap(tabla[min], tabla[i]); 
          } 
        }
    }  
    return ob;
}

int RaroSort(int *tabla, int P, int U){

int aux=0;
  
 if(tabla==NULL||P<0||U<P) return ERR;

 if(tabla[P] < tabla[U]){
   aux=quicksort(tabla,P,U);
 }
 ob+=aux;
 else{
   selectsort(tabla,P,U);
 }
 ob+=aux;

 return ob;
}

*/
