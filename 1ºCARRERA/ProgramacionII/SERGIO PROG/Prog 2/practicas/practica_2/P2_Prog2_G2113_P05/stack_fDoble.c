/*
*Título: Funciones vértices, práctica 1, programación 2
*Grupo: viernes 2113
*Autores: Sergio Hidalgo y Miguel Ibáñez 
*/
#include "stack_fDoble.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#define INIT_CAPACITY 2 /*init stack capacity*/
#define FCT_CAPACITY 2 /*multiply the stack capacity*/

struct _Stack {
void **item; /*!<Static array of elements*/
int top; /*!<index of the top element in the stack*/
int capacity; /*!<xcapacity of the stack*/
};


Stack * stack_init ()
{
    Stack *s = NULL;
    int i;

    s = (Stack *) malloc (sizeof(Stack));
    if (s == NULL) {
        return NULL;
    }

    s->capacity = INIT_CAPACITY; 
    
    s->item = (void **) malloc (INIT_CAPACITY*sizeof(Stack));;

    for (i = 0; i < INIT_CAPACITY; i++)
    {
        s->item[i] = NULL;
    }
    
    s->top = -1;
    
    return s;
}

void stack_free (Stack *s)
{
    if (s == NULL)
    {
        return;
    }

    free(s->item);
    
    free (s);
}

Status stack_push (Stack *s, const void *ele)
{

    if (s == NULL || ele == NULL) 
    {
        return ERROR;
    } 

    if (stack_isFull (s) == TRUE)
    {
        s->capacity = s->capacity * FCT_CAPACITY;

        s->item = (void *) realloc (s->item, ((s->capacity)*sizeof(Stack)));
        
        if (s->item == NULL)
        {
            return ERROR;
        }
    }  
   
    (s->top)++;
    s->item[s->top] = (void *)ele;
    return OK;
}

void * stack_pop (Stack *s)
{
    void *e = NULL;
    if (s == NULL || stack_isEmpty(s) == TRUE) 
    {
        return NULL;
    }
    
    e = s->item[s->top];
    s->item[s->top] = NULL;
    s->top--;

    return e;
}

void * stack_top (const Stack *s)
{
    if (s == NULL || stack_isEmpty(s) == TRUE) 
    {
        return NULL;
    }
       
    return s->item[s->top];
}

Bool stack_isEmpty (const Stack *s)
{
    if (s == NULL) 
    {
        return TRUE;
    }

    if (s->top == -1) 
    {
        return TRUE;
    }

    return FALSE;
}

Bool stack_isFull (const Stack *s)
{
    if (s == NULL) 
    {
        return TRUE;
    }
    
    if (s->top == s->capacity-1) 
    {
        return TRUE;
    }
    
    return FALSE;
}

size_t stack_size (const Stack *s)
{
    if (s == NULL) 
    {
        return TRUE;
    }

    return s->top+1;
}

int stack_print(FILE* fp, const Stack *s,  P_stack_ele_print f)
{
    int a = 0, i = 0;
    long s_size = stack_size (s);
    
    if (fp == NULL || s == NULL || f == NULL)
    {
        return 0;
    }


    for ( i = 0; i < s_size; i++)
    {

        if (s->item[i] == NULL)
        {
            return 0;
        }

        a = a + f(fp, s->item[s_size-i-1]);
        fprintf (fp, "\n");
    }

    return a;
}


