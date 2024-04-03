
#include "stack_fDoble.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "file_utils.h"



char *string_invert(char *str) {

  Stack  *st;
  char *str2, *str3;
  int i;
  void *e;

  if (str == NULL)
  {

    return NULL;

  }

  st = stack_init();
  
  for( i=0 ; i<strlen(str) ; i++ )
  {
    if (str[i] != '\0')
    {
      str2 = char_copy(char_init (str[i]));
      stack_push(st,str2);
    }

  }
 
  str3 = (char *)calloc (strlen(str)+1, sizeof(char));
  
  while (stack_isEmpty(st) == FALSE)
  {
    e = stack_pop(st);
    strcat(str3 ,e);
  }

  stack_free(st);

  return str3;
}


Status reverseWords(char *strout, char *strin) {

  Stack *st;
  void *e;
  int i;

  if (strin == NULL || strout == NULL)
  {
    return ERROR;
  }
  
 
  st = stack_init();

  for ( i = 0; i < strlen(strin); i++)
  {

    if ( strin[i] != ' ')
    {

      stack_push(st,&strin[i]);

    }

    else
    {

      while (stack_isEmpty(st) == FALSE)
      {
        e = char_copy(stack_pop(st));
        strcat( strout, e);

      }

    strcat(strout , char_copy(" "));
      
    }
    
  }

  while (stack_isEmpty(st) == FALSE)
  {

    e = char_copy(stack_pop(st));
    strcat(strout ,e);
    
  }

  stack_free(st);

  return OK;

}

  
  

  







  

