/*
* Funciones editadas: library_addBook (línea 112) y library_removeBook (línea 140)
* Autor: Sergio Hidalgo Gamborino, programación 2 grupo 113
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "library.h"

/* START [defines] */
#define MAX_BOOKS 1064
/* END [defines] */

/* START [_Library] */
struct _Library {
  Book *catalog[MAX_BOOKS];
  int num_books;
};
/* END  [_Library] */

/*------------------------------------------------------------------------*/
/* Private functions                                                      */
/*------------------------------------------------------------------------*/
Boolean _library_isFull(const Library *p);
int _library_findBookByISBN(const Library *l, const char *isbn);

/*------------------------------------------------------------------------*/
/* START [_library_isFull] */
Boolean _library_isFull(const Library *p) {
  if (p == NULL) return TRUE;
  if (p->num_books == MAX_BOOKS) return TRUE;
  return FALSE;
}
/* END [_library_isFull] */

/*------------------------------------------------------------------------*/
/* START [_library_findBookByISBN] */
int _library_findBookByISBN(const Library *l, const char *isbn) {
  int i;
  const char *buff; 
  Boolean bool = FALSE;

  if (!l || !isbn || library_isEmpty (l) == TRUE)
    return -1;
  
  for (i=0; i<l->num_books && bool==FALSE; i++) {
    buff = book_getISBN(l->catalog[i]);
    if (strcmp(buff, isbn) == 0)
      bool = TRUE;
  }
  
  if (bool == TRUE)
    return (i-1);
  else 
    return -1;
}
/* END [_library_findBookByISBN] */

/*------------------------------------------------------------------------*/
/* Public functions                                                       */
/*------------------------------------------------------------------------*/
/* START [library_new] */
Library *library_new() {
  Library *l = NULL;
  int i;
  
  l = (Library *) malloc(sizeof(Library));
  if (l == NULL) return NULL;
  
  l->num_books = 0;
  
  for(i=0; i<MAX_BOOKS; i++) 
    l->catalog[i]=NULL;
  
  return l;
}
/* END [library_new] */

/*------------------------------------------------------------------------*/
/* START [library_free] */
void library_free(Library *l) {
  int i;
  if (l==NULL) return;
  
  for (i=0; i<l->num_books; i++) {
    book_free(l->catalog[i]);
  }
  
  free(l);
}
/* END [library_free] */

/*------------------------------------------------------------------------*/
/* START [library_isEmpty] */
Boolean library_isEmpty(const Library *l){
  if (l == NULL) return TRUE; 
  if (l->num_books == 0) return TRUE;
  return FALSE;
}
/* END [library_isEmpty] */

/*------------------------------------------------------------------------*/
/* START [library_hasBook] */
Boolean library_hasBook(const Library *l, const char *isbn) {
  return _library_findBookByISBN(l, isbn) > -1 ? TRUE : FALSE;
} 
/* END [library_hasBook] */

/*------------------------------------------------------------------------*/
/* START [library_addBook] */
Status library_addBook(Library *l, const char *descr) {
  int buff;
  Book *descr2; /*Se declara un variable para poder modificar su valor
                  con la función "book_new" a partir de los datos del libro en el main*/

  descr2 = book_new(descr); /*Creación del libro*/

  for (int j = 0; j < l->num_books; j++) /*Bucle que comprobará si el libro ya están la librería 
                                    y si es cierto, sumará el número de copias al que estaba ahí previamente*/
  {
    if (book_cmp(descr2, l->catalog[j]) == 0)
    {
      buff = book_getNumCopies(descr2) + book_getNumCopies(l->catalog[j]);
      book_setNumCopies(l->catalog[j], buff);
      
      return OK;
    }
  }
    
  l->catalog[l->num_books] = descr2; /*El libro se añadirá al catálogo de la librería*/
  l->num_books = l->num_books + 1; /*Aumentará en 1 el número de libros 
                                    (refiriendose a el número de libros que no son idénticos)*/
  return OK;                        
}
/* END [library_addBook] */

/*------------------------------------------------------------------------*/
/* START [library_removeBook] */
Status library_removeBook(Library *l, const char *isbn) {
  
  /*Bucle que comprobará si hay un libro con ese isbn*/
  for (int j = 0; j < l->num_books; j++)
  {
    if ((strcmp(isbn, book_getISBN(l->catalog[j])) == 0))
    {
      l->catalog[j] = NULL; /*Si lo hay, se borra*/
    }
  }
  
  return OK;
}
/* END [library_removeBook] */
/*------------------------------------------------------------------------*/
/* START [library_print] */
int library_print(FILE *pf, const Library *l){
  int i, n=0;
  
  if (!pf || !l) return -1;

  for (i=0; i<l->num_books; i++)
    n += book_print(pf, l->catalog[i]);
  
  return n;
}
/* END [library_print] */
