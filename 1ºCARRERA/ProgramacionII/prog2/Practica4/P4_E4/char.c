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
#include "char.h"
extern int errno;

char* char_ini(int tam){
  char *p = NULL;
  p = (char*)malloc(tam*sizeof(char));
  if(p == NULL){
    fprintf(stderr, "%s\n", strerror(errno));
    return NULL;
  }
  return p;
}

void* char_copy(const void *cad){
  char *cadcpy= NULL;

  if (!cad) return NULL;

  cadcpy=char_ini(1+strlen((char*)cad));

  strncpy(cadcpy, (char*)cad, (1+strlen((char*)cad)));

  return (void*) cadcpy;
}

int char_cmp (const void* cad1,const void* cad2){
    if (!cad1 || !cad2) return 0;

    return strcmp((char*)cad1, (char*)cad2);
}


void char_destroy(void *e){
  free(e);
}

void* char_setvalor (void* cad, char* cad2) {
	if (!cad||!cad2) return NULL;
  strncpy((char*)cad, cad2, (1+strlen(cad2)));
	return (char*)cad;
}

int char_print(FILE *pf, const void *cad) {
    int i;
    if (cad == NULL|| pf == NULL) {
        return -1;
    }
    i = fprintf(pf, " [%s] ",(char*) cad);
    return i;
}
