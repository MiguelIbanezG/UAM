#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "graph.h"
#include "vertex.h"

int main(){
	Graph *g=NULL;
	FILE *f=NULL;
	
	g=graph_init();
	
	f=fopen("g1.txt","r");
	if(f == NULL)
        return -1;
	
	
	if(!graph_readFromFile(f, g)) return -1;

	graph_print(stdout,g);
	
	graph_free(g);

	fclose(f);
	
	return 0;
}
