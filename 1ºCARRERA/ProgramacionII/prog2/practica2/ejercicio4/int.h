#ifndef INT_H
#define INT_H

int* int_ini();

void* int_copy (const void *num);

void int_destroy(void *num);

int int_print (FILE* pf, const void *num);

void* int_SetValue (void* num, int src);

#endif

