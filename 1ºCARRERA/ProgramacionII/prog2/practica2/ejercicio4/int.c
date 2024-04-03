#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

#include "int.h"

extern int errno;

int* int_ini(){

	int *num = NULL;
	num = (int*)malloc(sizeof(int));

	if(!num){
		fprintf(stderr, "%s\n", strerror(errno));
		return NULL;
	}
	return num;
}

void* int_copy (const void *num){

	int *aux= NULL;
	
	if (!num) return NULL;
	
	aux = int_ini ();
	if (!aux) return NULL;
	
	*aux = *((int*)num);

	return (int*)aux;
}

void int_destroy(void *num){

	free(num);

}

void* int_SetValue (void* num, int src) {
	if (!num) return NULL;
	*((int*)num) = src;
	return (int*)num;
}

int int_print (FILE* pf, const void *num) {
	
	if (!pf || !num) return -1;
	return fprintf (pf, "[%d]", *((int*)num));
}
