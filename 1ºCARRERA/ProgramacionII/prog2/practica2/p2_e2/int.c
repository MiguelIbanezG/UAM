#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

#include "int.h"

int* int_ini(){
  int *p = NULL;
  p = (int*)malloc(sizeof(int));
  if(p == NULL){
    fprintf(stderr, "%s\n", strerror(errno));
    return NULL;
  }
  return p;
}

int* int_copy(int *i){
  int *e = NULL;

  if (i == NULL) {
      fprintf(stderr, "%s\n", strerror(errno));
      return NULL;
  }
  e = (int*)malloc(sizeof(int));
  if (e == NULL) {
      fprintf(stderr, "%s\n", strerror(errno));
      return NULL;
  }
  *e = *i;

  return e;
}

void int_destroy(int *e){
  /*free(e);*/
  return;
}
