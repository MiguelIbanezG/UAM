#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "permutations.h"
#include "sorting.h"
#include <assert.h>

#define NDBUG

int quicksort_inv(int* tabla, int ip, int iu){

  int pos=ip, o=0, b=0, ob=0;

  assert(ip>=0);

  if(ip>iu) return ERR;

  if(ip==iu) return OK;

  else{
    ob=partition_inv(tabla,ip,iu,&pos);
    if(ip<pos-1)
      o=quicksort_inv(tabla,ip,pos-1);
    if(pos+1<iu)
      b=quicksort_inv(tabla,pos+1,iu);
      
    if(o==ERR || b== ERR) return ERR;
  }
  return o + b + ob;
}

int partition_inv(int* tabla, int ip, int iu,int *pos){

  int k, i, ob=0;

  median_inv(tabla,ip,iu,pos);

  k=tabla[*pos];
  swap(&tabla[ip],&tabla[*pos]);

  *pos=ip;

  for(i=ip;i<=iu;i++){
    ob++;
    if(tabla[i]>k){
      *pos=*pos+1;
      swap(&tabla[i],&tabla[*pos]);
    }
  }
  swap(&tabla[ip],&tabla[*pos]);

  return ob;
}

int median_inv(int *tabla, int ip, int iu,int *pos){

  assert(ip>=0);

  *pos=ip;

  return OK;
}
