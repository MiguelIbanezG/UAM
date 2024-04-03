#include <stdio.h>
#include <stdlib.h>

#include "stack_fp.h"
#include "graph.h"

void main_free (Graph *g, FILE *f, int flag);

int main (int argc, char ** argv) {

	Graph *g = NULL;
	FILE *f = NULL;
	
	f = fopen (argv[1], "r");
	if (!f) main_free (g, f, EXIT_FAILURE);
	
	g = graph_ini ();
	
	if (!g) main_free (g, f, EXIT_FAILURE);
	
	if (graph_readFromFile (f, g) == ERROR) main_free (g, f, EXIT_FAILURE);
	
	if (graph_findDeepSearch (g, atoi(argv[2]), atoi(argv[3])) == NULL) {
	
	    fprintf (stdout, "\nNo es posible encontrar un camino\n");
	    main_free (g, f, EXIT_FAILURE);
	    
	} else {
	
	    fprintf (stdout, "\nEs posible encontrar un camino\n");
	    main_free (g, f, EXIT_SUCCESS);
	}
	
	return 0;
}

void main_free (Graph *g, FILE *f, int flag) {
	
	graph_destroy (g);
	fclose (f);
	exit(flag);
}
