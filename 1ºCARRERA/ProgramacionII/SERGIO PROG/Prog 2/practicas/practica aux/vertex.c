//Authors Florentino García Aznar and Sergio Fraile Sánchez
//Date 23/02/2021
//Version 1.3


#include "vertex.h"
#include "types.h"
#include "graph.h"
#include <string.h>
#include <stdio.h>
#define TAG_LENGTH 64

typedef int(*P_vertex_cmp)(const void*, const void*);

struct _Vertex
{
	long id;
	char tag[TAG_LENGTH];
	Label state;
	
	int index;
};

Status vertex_setField(Vertex *v, char *key, char *value)
{
	if (!key || !value)
		return ERROR;

	if (strcmp(key, "id") == 0)
	{
		return vertex_setId(v, atol(value));
	}
	else if (strcmp(key, "tag") == 0)
	{
		return vertex_setTag(v, value);
	}
	else if (strcmp(key, "state") == 0)
	{
		return vertex_setState(v, (Label)atoi(value));
	}

	return ERROR;
}

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

	Vertex *v = NULL;

	v=(Vertex*)malloc(sizeof(Vertex));
	if(v == NULL)
		return NULL;
	strcpy(v->tag,"");
	v->id=0;
	v->state=0;
	v->index=0;

	return v;

}

void vertex_free(void *v)
{
	free(v);
}

long vertex_getId(const Vertex *v)
{
	if (v==NULL)
	{
		return -1;
	}
	else
	{
		return v->id;
	}
}

const char *vertex_getTag(const Vertex *v)
{
	if (v==NULL)
	{
		return NULL;
	}
	else
	{
		return v->tag;
	}
}

Label vertex_getState(const Vertex *v)
{
	if (v==NULL)
	{
		return ERROR_VERTEX;
	}
	else
	{
		return v->state;
	}
}

int vertex_getIndex(const Vertex *v)
{
	if (v==NULL)
	{
		return -1;
	}
	else
	{
		return v->index;
	}
}

Status vertex_setId(Vertex *v, const long id)
{
	
	if (v==NULL||id<0)
	{
		return ERROR;
	}
	else
	{
		v->id = id;
	}
	return OK;
}

Status vertex_setTag(Vertex *v, const char *tag)
{
	
	if (v==NULL||tag==NULL||strlen(tag)>TAG_LENGTH)
	{
		return ERROR;
	}
	else
	{
		strcpy(v->tag, tag);
	}
	return OK;
}

Status vertex_setState(Vertex *v, const Label state)
{
	
	if (v==NULL)
	{
		return ERROR;
	}
	else
	{	
		v->state = state;
	}
	return OK;
}

Status vertex_setIndex (Vertex * v, const int ix)
{
	if (v==NULL||ix<0||!ix)
	{
		return ERROR;
	}
    else
	{	
		v->index=ix;
	}
	return OK;

}

int vertex_cmp(const void *v1, const void *v2)
{

	if(!v1||!v2){
		return 0;
	}	
	
	if (vertex_getId(v1) == vertex_getId(v2))
	{
			return strcmp(vertex_getTag(v1), vertex_getTag(v2));
		
	}
	else if (vertex_getId(v1) > vertex_getId(v2))
	{
		return 2;
	}
	else
	{
		return -2;
	}
	return 0;
}

void *vertex_copy(const void *src)
{
	Vertex *trg;
	trg = vertex_init();
	
	if(!src){
		return NULL;
	}
	
	if (!vertex_setId(trg, vertex_getId(src)) || !vertex_setTag(trg, vertex_getTag(src)) || !vertex_setState(trg, vertex_getState(src)))
	{
		return NULL;
	}
	else
	{
		return trg;
	}
}

int vertex_print (FILE * pf, const void * v){
    int count=0;
    if (v==NULL || pf==NULL)
    {
        return -1;
    }
    else{
        count += fprintf(pf, "[%ld, %s, %d, %d]", vertex_getId(v),vertex_getTag(v),vertex_getState(v),vertex_getIndex(v));
    }
    return count;
}
