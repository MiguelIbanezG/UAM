/******************************************************************************

Nombre del modulo: int.c

Descripcion: Implementacion de las funciones de int.h. Sirve para trabajar con elementos tipo int.
			 Esta adaptado para trabajar con punteros a funciones.

Autor: Jorge Fernandez Garcia y Pedro Sanchez de la Muela

Fecha: 15 - 4 - 2019

******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include "int.h"
extern int errno;

int* int_ini(){
  int *p = NULL;
  p = (int*)malloc(sizeof(int));
  if(p == NULL){
    fprintf(stderr, "%s\n", strerror(errno));
    return NULL;
  }
  return p;
}

void* int_copy(const void *i){
  int *e= NULL;

  if (i == NULL) return NULL;

  e = int_ini();
  if (e == NULL) return NULL;
  *e = *(int*)i;

  return (void*) e;
}

int int_cmp (const void* num1,const void* num2){
    if (!num1 || !num2) return 0;

    return *(int*)num1 - *(int*)num2;
}


void int_destroy(void *e){
  free(e);
}

void* int_setvalor (void* num, int val) {
	if (!num) return NULL;
	*((int*)num) = val;
	return (int*)num;
}

int int_print(FILE *pf, const void *e) {
    int i;
    if (e == NULL|| pf == NULL) {
        return -1;
    }
    i = fprintf(pf, "[%d]",*(int*) e);
    return i;
}
