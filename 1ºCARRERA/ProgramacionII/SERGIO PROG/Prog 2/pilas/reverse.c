/*Creado por Sergio Hidalgo, Programación 2, 213*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stack_fDoble.h"
#include "file_utils.h"
/* Include here any other headers you need */

/**
 * @brief: Reverses a string
 * @param str, String to reverse
 * @return A newly allocated string with the reversed string
 **/

char *string_invert(char *str)
{
  /* It is MANDATORY that you use a stack to implement this function */
  /* Failure to do so will result in a FAIL grade */

  /* Es OBLIGATORIO usar una pila para implementar esta función */
  /* No hacerlo implica un NO APTO */

  Stack *s; /*Variables*/
  int i;
  char *aux, *aux2;

  if (str == NULL ) /*Control de errores*/
  {
    return NULL;
  }

  s = stack_init (); /*Inicialización de la pila*/

  for (i = 0; i <= strlen (str); i++) /*Bucle para pasar la cadena a la pila*/
  {

    if (str[i] != '\0')
    {
      aux = char_init (str[i]); /*Se utiliza la cadena auxiliar para meter en la pila la cadena inicial letra por letra*/
      stack_push (s, aux);
    }
    
  }
  
  aux2 = (char *)calloc (strlen(str)+1, sizeof(char)); /*Se reserva la memoria de una segunda cadena auxiliar*/
  if (aux2 == NULL)
  {
    return NULL;
  }
  

  while (stack_isEmpty (s) == FALSE) /*Mientras este vacia la pila*/
  {
    
    strcat (aux2, stack_pop (s));  /*Se saca el elemento de arriba y se añade a la cadena*/
  }  
  
  stack_free (s);

  return aux2;
}

/**
 * @brief: Reverse the words of an input string to an output string.
 *
 * @example: "Hello World" => "olleH dlroW"
 * The words in the input string are separated by a space character.
 * The strings may not overlap, and the destination string strout
 * must be large enough to receive the inverted expression.
 *
 * @param strout, Pointer to the output buffer
 * @param strin, Pointer to the input expression
 * @return The function returns OK or ERROR
 **/

Status reverseWords(char *strout, char *strin)
{
  /* It is MANDATORY that you use a stack to implement this function */
  /* Failure to do so will result in a FAIL grade */

  /* Es OBLIGATORIO usar una pila para implementar esta función */
  /* No hacerlo implica un NO APTO */

  int i;
  Stack *s;

  if (strin == NULL || strout == NULL)
  {
    return ERROR;
  }
  
  s = stack_init ();

  for (i = 0; i < strlen (strin); i++)
  {
    if (strin[i] != ' ') /*Mientras el carácter de la cadena inicial sea distinto de espacio se pasa a la pila*/
    {
      stack_push (s, &strin[i]);
    }
    else
    {
      while (stack_isEmpty (s) == FALSE) /*Si el stack esta lleno se saca un elemento y se mete en la cadena de salida*/
      {

        strcat (strout, char_copy(stack_pop (s)));
      }

      strcat (strout, char_copy(" ")); /*Después añade un espacio*/
    }
   }
    while (stack_isEmpty (s) == FALSE)  /*Sigue sacando carácteres mientras este llena*/
    {
      
      strcat (strout, char_copy(stack_pop (s)));
    }  
 
  
  stack_free (s);

  return OK; 
}