#include "types.h"
#include "stack_fDoble.h"
#include "file_utils.h"
#include "vertex.h"
#include "graph.h"
#include <stdio.h>
#include <stdlib.h>

/* PROTOYPES */
Status mergeStacks(Stack *sin1, Stack *sin2, Stack *sout, P_vertex_cmp cmp);
Status read_StackFromFile(FILE *f, Stack *s);
/* END PROTOYPES */

/* MAIN */
int main(int argc, char *args[]){
  FILE *f=NULL;
  int vert1=0, vert2=0;
  Stack *s1=NULL, *s2=NULL , *stout=NULL;
  Graph *g1=NULL, *g2=NULL;
  
  g1=graph_init();
  g2=graph_init();
  s1=stack_init();
  s2=stack_init();
  stout=stack_init();
  
  if (!s1||!s2||!stout)
  {
    return 1;
  }
  if (argc != 3)
  {
    fprintf(stdout, "Wrong format, right format ./p2_e1a.c file1.txt file2.txt ");
  }
  f=fopen(args[1],"r");
  graph_readFromFile(f,g1);
  vert1=graph_getNumberOfVertices(g1);
  for (int i = 0; i < vert1; i++)
  {
    stack_push(s1,graph_Vertex(g1)[i]);
  }
  fclose(f);
  fprintf(stdout, "Ranking 0:\n");

  stack_print(stdout,s1,vertex_print);
  
  fprintf(stdout, "Ranking 1:\n");
  f=fopen(args[2],"r");
  graph_readFromFile(f,g2);
  vert2=graph_getNumberOfVertices(g2);
  for (int i = 0; i < vert2; i++)
  {
    stack_push(s2,graph_Vertex(g2)[i]);
  }
  fclose(f);
  stack_print(stdout,s2,vertex_print);
  
  fprintf(stdout, "Joined ranking ;");
  mergeStacks(s1,s2,stout,vertex_cmp);
  stack_print(stdout,stout,vertex_print);
  
  graph_free(g1);
  graph_free(g2);
  stack_free(stout);
  return 0;

}
/* END MAIN */

/* PRIVATE FUNCTIONS */

/**
* @brief: Merges two stacks
*
* @param sin1, first input stack
* @param sin2, second input stack
* @param sout, result stack
* @return The function returns OK or ERROR
**/
Status mergeStacks(Stack *sin1, Stack *sin2, Stack *sout, P_vertex_cmp cmp)
{
    Stack *ps = stack_init();
    if (stack_isEmpty(sin1) || stack_isEmpty(sin2) || !stack_isEmpty(sout))
    {
        return ERROR;
    }

    while (!stack_isEmpty(sin1) && !stack_isEmpty(sin2))
    {
        if (cmp(stack_top(sin1), stack_top(sin2))==2)
        {
            stack_push(sout, stack_pop(sin1));
        }
        else
        {
            stack_push(sout, stack_pop(sin2));
        }
    }

    if (stack_isEmpty(sin1))
    {
        ps = sin2;
    }
    else if (stack_isEmpty(sin2))
    {
        ps = sin1;
    }

    while (!stack_isEmpty(ps))
    {
        stack_push(sout, stack_pop(ps));
    }
    stack_free (ps);

    return OK;
}
/* END PRIVATE FUNCTIONS */
