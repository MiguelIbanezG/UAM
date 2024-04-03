#ifndef INT_H
#define INT_H

#include <stdio.h>
#include "types.h"

int* int_ini();

void* char_copy(const void *i);

void char_destroy(void *e);

void* char_setvalor (void* cad, char* cad2);

int char_print(FILE *pf, const void *e);

int char_cmp (const void* cad1, const void* cad2);

#endif
