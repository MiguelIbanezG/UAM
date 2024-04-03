/**
 *
 * Description: Implementation of functions for search
 *
 * File: search.c
 * Author: Carlos Aguirre and Javier Sanz-Cruzado
 * Version: 1.0
 * Date: 14-11-2016
 *
 */

#include "search.h"

#include <stdlib.h>
#include <math.h>
#include <assert.h>

/**
 *  Key generation functions
 *
 *  Description: Receives the number of keys to generate in the n_keys
 *               parameter. The generated keys go from 1 to max. The
 * 				 keys are returned in the keys parameter which must be 
 *				 allocated externally to the function.
 */
  
/**
 *  Function: uniform_key_generator
 *               This function generates all keys from 1 to max in a sequential
 *               manner. If n_keys == max, each key will just be generated once.
 */
void uniform_key_generator(int *keys, int n_keys, int max)
{
  int i;

  for(i = 0; i < n_keys; i++) keys[i] = 1 + (i % max);

  return;
}

/**
 *  Function: potential_key_generator
 *               This function generates keys following an approximately
 *               potential distribution. The smaller values are much more 
 *               likely than the bigger ones. Value 1 has a 50%
 *               probability, value 2 a 17%, value 3 the 9%, etc.
 */
void potential_key_generator(int *keys, int n_keys, int max)
{
  int i;

  for(i = 0; i < n_keys; i++) 
  {
    keys[i] = .5+max/(1 + max*((double)rand()/(RAND_MAX)));
  }

  return;
}

PDICT init_dictionary (int size, char order)
{
	PDICT dic;

  assert(size>0);
  assert(order==SORTED || order==NOT_SORTED);

  dic=(PDICT) malloc(sizeof(DICT));
  if(dic==NULL) return NULL;

  dic->size=size;
  dic->n_data=0;
  dic->order=order;
  dic->table=(int*) malloc(size*sizeof(int));
  if (dic->table==NULL) return NULL;

  return dic;
}

void free_dictionary(PDICT pdict)
{
	if (pdict==NULL) return;

  free(pdict->table);
  free(pdict);
}

int insert_dictionary(PDICT pdict, int key)
{
  int aux, j, ob=1;

  assert(pdict!=NULL);

  if(pdict->size<=pdict->n_data) return ERR;
	
  pdict->table[pdict->n_data]=key;
  pdict->n_data++;

  if(pdict->order==NOT_SORTED) return ob;

  aux=pdict->table[pdict->n_data-1];
  
  for(j=pdict->n_data-2;j>=0 && pdict->table[j]>aux;j--,ob++)
    pdict->table[j+1]=pdict->table[j];
  
  pdict->table[j+1]=aux;

  return ob;
}

int massive_insertion_dictionary (PDICT pdict,int *keys, int n_keys)
{
  int ob=0, n, i;

	assert(pdict!=NULL);
  assert(keys!=NULL);

  for(i=0;i<n_keys;i++){
    n=insert_dictionary(pdict,keys[i]);
    if(n==ERR) return ERR;
    ob+=n;
  }

  return ob;
}

int search_dictionary(PDICT pdict, int key, int *ppos, pfunc_search method)
{
	assert(pdict!=NULL);
  assert(method!=NULL);

  return method(pdict->table,0,pdict->n_data,key,ppos);
}
/*
int search_dictionary(PDICT pdict, int key, int ppos, pfunc_search method)
{
  if (pdict == NULL  method == NULL  ppos == NULL || key < 0)
  {
    return ERR;
  }

  if (method(pdict->table, 0, pdict->size - 1, key, ppos) == ERR)
    return ERR;

  if (ppos == NOT_FOUND)
  {
    return NOT_FOUND;
  }

  if (*ppos < 0)
  {
    return ERR;
  }

  return OK;
}
*/

/* Search functions of the Dictionary ADT */
int bin_search(int *table,int F,int L,int key, int *ppos)
{
  int m, ob;

  assert(table!=NULL);

  for(ob=1;F<=L;ob++){
    m=(F+L)/2;
    if(table[m]==key) {
      *ppos=m+1;
      return ob;
    }
    if(table[m]<key) F=m+1;
    if(table[m]>key) L=m-1;
  }
  *ppos=NOT_FOUND;
  return ob;
}

int lin_search(int *table,int F,int L,int key, int *ppos)
{
  int i;

  assert(table!=NULL);
	
  for(i=F;i<L;i++)
    if(table[i]==key){
      *ppos=i+1;
      return i-F+1;
    }
  
  *ppos=NOT_FOUND;
  return i-F+1;
}

int lin_auto_search(int *table,int F,int L,int key, int *ppos)
{
	int i;

  assert(table!=NULL);
	
  for(i=F;i<L;i++)
    if(table[i]==key){
      if(i!=F){
        swap(&table[i],&table[i-1]);
        *ppos=i-1;
      }
      else *ppos=i+1;
      return i-F+1;
    }
  
  *ppos=NOT_FOUND;
  return i-F+1;
}

/*
int lin_search(int *table, int F, int L, int key, int *ppos)
{
  int i = 0, OB = 0;

  if (table == NULL  F > L  ppos == NULL  key < 0)
    return ERR;

  *ppos = NOT_FOUND;

  for (i = F, OB = 0; i <= L; i++, OB++)
  {
    if (table[i] == key)
    {
      *ppos = i;
      break;
    }
  }

  return OB;
}

int lin_auto_search(int *table, int F, int L, int key, int *ppos)
{
  int i = 0, aux = 0, OB = 0;

  if (table == NULL  F > L  ppos == NULL  key < 0)
  {
    return ERR;
  }

  *ppos = NOT_FOUND;

  if (key == table[F])
  {
    *ppos = F;
    return 1;
  }

  for (i = F, OB = 0; i < L; i++, OB++)
  {
    if (table[i] == key)
    {
      aux = table[i - 1];
      table[i - 1] = table[i];
      table[i] = aux;
      *ppos = i - 1;
      break;
    }
  }

  return OB;
}
*/