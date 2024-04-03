#include "types.h"
#include "stack_fDoble.h"
#include "file_utils.h"
#include <stdio.h>
#include <stdlib.h>

/* PROTOYPES */
Status mergeStacks(Stack *sin1, Stack *sin2, Stack *sout);
Status read_StackFromFile(FILE *f,Stack *s);
/* END PROTOYPES */

/* MAIN */
int main(int argc, char *args[])
{
    Stack *s1=stack_init(),*s2=stack_init(),*stout=stack_init();
    FILE *f=NULL;

    /* Check inputs */
    if(argc != 3){
        fprintf(stdout, "Input format should be: ./p2_e1a.c file1.txt file2.txt");
        return 1;
    }

    /* Check stacks existance */
    if(!s1 || !s2 || !stout)
        return 1;

    /* S1 */
    f=fopen(args[1],"r");

    if(!f)
        return 1;

    if(read_StackFromFile(f, s1) == -1)
        return 1;
        
    fprintf(stdout,"Ranking: 0\n");
    stack_print(stdout,s1,float_print);
    printf("\n");

    fclose(f);
	
    /* S2 */
    f=fopen(args[2],"r");

    if(!f)
        return 1;
    
    if(read_StackFromFile(f, s2) == -1)
        return 1;

    fprintf(stdout,"Ranking: 1\n");
    stack_print(stdout,s2,float_print);
    printf("\n");

    fclose(f);

    /* Merge both stacks*/
    if(!(mergeStacks(s1,s2,stout)))
        return 1;

    /* Merged stack */
    fprintf(stdout,"Joint Ranking:\n");
    stack_print(stdout,stout,float_print);
    
    /*Frees stack*/
    stack_free(stout);
    
    return 0;
}
/* END MAIN */

/* PRIVATE FUNCTIONS */

/**
* @brief: sorts a stack from highest to lowest
*
* @param s, stack to be sorted from highest to lowest
* @return The function returns stack size, or -1 in case of error
**/
Status read_StackFromFile(FILE *f,Stack *s){
    int size = 0, i=0;
    
    if(!f || !s)
        return ERROR;
    
    fscanf(f,"%d",&size);
    for (i = 0; i < size; i++)
    {
    	float *a=malloc(sizeof(float));
        fscanf(f,"%f",a);
        stack_push(s,a);
       
    }
    return OK;
}

/**
* @brief: Merges two stacks
*
* @param sin1, first input stack
* @param sin2, second input stack
* @param sout, result stack
* @return The function returns OK or ERROR
**/
Status mergeStacks(Stack *sin1, Stack *sin2, Stack *sout)
{
    float *e=NULL;
    Stack *ps = stack_init();
    if (stack_isEmpty(sin1) || stack_isEmpty(sin2) || !stack_isEmpty(sout))
    {
        return ERROR;
    }

    while (!stack_isEmpty(sin1) && !stack_isEmpty(sin2))
    {
        if (float_cmp (stack_top(sin1), stack_top(sin2))==1)
        {
            e = stack_pop(sin1);
        }
        else
        {
            e = stack_pop(sin2);
        }
        stack_push(sout, e);
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
        e = stack_pop(ps);
        stack_push(sout, e);
    }
    stack_free (ps);

    return OK;
}
    /* END PRIVATE FUNCTIONS */
    
