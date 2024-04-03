/*
*Título: Funciones vértices, práctica 1, programación 2
*Grupo: viernes 2113
*Autores: Sergio Hidalgo y Miguel Ibáñez 
*/
#include "vertex.h"
#include <string.h>
#define TAG_LENGTH 64

typedef struct _Vertex {
long id;
char tag[TAG_LENGTH];
Label state;

int index;
}vertex;


/*----------------------------------------------------------------------------------------*/
/*
Private function:
*/
Status vertex_setField (Vertex *v, char *key, char *value);

Status vertex_setField (Vertex *v, char *key, char *value) {
  if (!key || !value) return ERROR;

  if (strcmp(key, "id") == 0) {
    return vertex_setId(v, atol(value));
  } else if (strcmp(key, "tag") == 0) {
    return vertex_setTag(v, value);
  } else if (strcmp(key, "state") == 0) {
    return vertex_setState(v, (Label)atoi(value));
  }

  return ERROR;
}

/*----------------------------------------------------------------------------------------*/
Vertex *vertex_initFromString(char *descr){
  char buffer[1024];
  char *token;
  char *key;
  char *value;
  char *p;
  Vertex *v;

  /* Check args: */
  if (!descr) return NULL;

  /* Allocate memory for vertex: */
  v = vertex_init();
  if (!v) return NULL;

  /* Read and tokenize description: */
  sprintf(buffer, "%s", descr);
  token = strtok(buffer, " \t\n");
  while (token) {
    p = strchr(token, ':');
    if (!p) continue;

    *p = '\0';
    key = token;
    value = p+1;

    vertex_setField(v, key, value);

    token = strtok(NULL, " \t\n");
  }

  return v;
}



Vertex * vertex_init (){
  

  Vertex *v; /*Se inicializa un puntero a v como tipo Vertex*/

  v = (Vertex*)malloc(sizeof(Vertex));
  if (v == NULL)  /*Se hace la reserva de memoria*/
  {
    return ERROR; /*Si falla dará error*/
  }

  /*Las distintas características del vértice 
  estarán a 0 todas (valor inical)*/
  v->id = 0;
  v->tag[0] = '\0';
  v->state = WHITE;
  v->index = 0;
  
  return v;/*Se devuelve v*/
}

void vertex_free (void * v){

  free (v); /*Se libera la memoria*/
}

long vertex_getId (const Vertex * v){

  if (v == NULL) 
  {
    return -1;
  }
  
  return v->id; 
}

const char* vertex_getTag (const Vertex * v){
  
  if (v == NULL)
  {
    return NULL;
  }
  else
    return v->tag; 
 
}

Label vertex_getState (const Vertex * v){
 
  if (v == NULL)
  {
    return ERROR_VERTEX;
  }
  else{
    
    return v->state;
  }
}

Status vertex_setId (Vertex * v, const long id){

  if (v == NULL || id < 0) 
  {
    return ERROR;
  }
  
    v->id = id; 
    return OK;
}

Status vertex_setTag (Vertex * v, const char * tag){  
   
  if ((v == NULL) || (tag == NULL))
  {
    
    return ERROR;
  }
  else if (strlen(tag) < TAG_LENGTH)
  {

    strcpy (v->tag, tag); /*se cambia el valor del tag del vértice si esta es menor*/
    return OK;
  }
  
  return ERROR;
}

Status vertex_setState (Vertex * v, const Label state){

  if (v == NULL) /*Si es distinto de 1 o 0 no es válido*/
  {
    return ERROR;
  }
  else
  {
    v->state = state; /*Cambia el valor del state del vértice si este es válido*/
    return OK;
  }  
}

int vertex_cmp (const void * v1, const void * v2){

  if (v1 == NULL || v2 == NULL)
  {
    return 0;
  }
  
  if (vertex_getId(v1) > vertex_getId(v2))  /*Si el primero es mayor que el segundo devuelve 1*/
  {
    return 1;
  }
  else if (vertex_getId(v1) < vertex_getId(v2)) /*Si es al revés devuelve -1*/
  {
    return -1;
  }
  else 
  {
    if (strcmp (vertex_getTag(v1), vertex_getTag(v2)) > 0) /*Si son iguales compara los tags y si el tag de v1 es*/
  {                                           /*mayor que el de v2, devolverá 1*/
     return 1;
  }
    else if (strcmp (vertex_getTag(v1), vertex_getTag(v2)) < 0) /*Sino, -1 y hay algún error, 0*/
    {
      return -1;
    }
    else
      return 0;
  }  
}

void * vertex_copy (const void * src){

Vertex *v;

v = vertex_init(); /*Se inicializa el vértice. */

if (vertex_setId(v, vertex_getId (src)) == ERROR || vertex_setTag(v, vertex_getTag (src)) == ERROR || vertex_setState(v, vertex_getState (src)) == ERROR)
{                     /*Para poder copiar en el las características de src, si algo falla devuelve NULL*/
  return NULL;
}
else if (v == NULL)
{
  return NULL;
}
else

  return v;
}

int vertex_print(FILE *pf, const void *v)
{
  
	int a = 0; /*Variable que almacena el número de carácteres copiados correctamente*/

  if (v == NULL)
  {
    return 0;
  }
  
  
	a = fprintf(pf, "[%ld, %s, %d, %d]", vertex_getId(v), vertex_getTag(v), vertex_getState(v), vertex_getIndex(v));
  /*Se imprimen el id, el tag y el state del vértice*/

	return a;

}

Status vertex_setIndex (Vertex *v, int index)
{
  if (!v)
  {
    return ERROR;
  }
  

  v->index = index;

  return OK;
}

int vertex_getIndex (const Vertex* v)
{
  if (!(v))
  {
    return -1;
  }

  return v->index;
}