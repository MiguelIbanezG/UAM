#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <errno.h>
#include "int.h"
#include "tree.h"

extern int errno;

void main_free (Tree *g, FILE *f);

int main (int argc, char ** argv) {

	Tree *t = NULL;
	FILE *f = NULL;
        int num;
                
	f = fopen (argv[1], "r");
	if (!f) {
		fprintf(stderr, "%s", strerror(errno));
		main_free (t, f);
	}
        t = tree_ini (int_destroy, int_copy, int_print, int_cmp);

	if (!t) {
		fprintf(stderr, "%s", strerror(errno));
		main_free (t, f);
	}
        
        while (fscanf(f, "%d", &num ) == 1){
            
            tree_insert (t, &num);
        }
        
        printf("Numero de nodos: %d", tree_numNodes(t));
        printf("\nProfundidad: %d\n", tree_depth(t));
        printf("Introduzca un numero: ");
        scanf("%d", &num);
        if(tree_find(t, &num) == TRUE)
            printf("El dato %d se encuentra dentro del Arbol", num);
        else
            printf("El dato %d no se encuentra dentro del Arbol", num);
}

