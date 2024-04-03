#include "types.h"
#include "stack_fDoble.h"
#include "file_utils.h"
#include "vertex.h"
#include "graph.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *args[]){
  FILE *f=NULL;
  Vertex **v;
  Graph *g;
  long from=atol(args[2]);
  long to=atol(args[3]);

  if (argc != 4)
  {
    fprintf(stdout, "Wrong format, right format ./p2_e2.c file.txt\n");
  }
  
  g=graph_init();
  
  if(!g)
  {
  return -1;
  }
  f=fopen(args[1],"r");
  graph_readFromFile(f,g);
  fclose(f);
  fprintf(stdout,"Input graph: \n");

  graph_print(stdout,g);

  fprintf(stdout,"From Vertex id: %ld\n",from);
  fprintf(stdout,"To Vertex id: %ld\n",to);
  
  graph_depthSearch(g, from, to);

  fprintf(stdout,"Output: \n");
  
  v=graph_Vertex(g);
  
  for(int i=0;i<graph_getNumberOfVertices(g);i++)
  {     
	  if(vertex_getState(v[i])==1){
		  vertex_print(stdout,v[i]);
		  printf("\n");  
	  }
  }
  printf("\n");
  graph_free(g);
  return 0;
}
