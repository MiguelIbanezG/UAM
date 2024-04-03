#ifndef INT_H
#define INT_H

#include <stdio.h>
#include "types.h"

int* int_ini();

void* int_copy(const void *i);

void int_destroy(void *e);

void* int_setvalor (void* num, int val);

int int_print(FILE *pf, const void *e);

int int_cmp (const void* num1, const void* num2);

#endif
