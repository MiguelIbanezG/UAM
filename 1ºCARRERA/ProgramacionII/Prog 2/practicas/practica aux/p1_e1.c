#include "vertex.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(){
Vertex* vertex1=NULL;
Vertex* vertex2=NULL;
Vertex* vertex3=NULL;

vertex1=vertex_initFromString("id:10 tag:one state:0");

if(vertex1==NULL){ 
		return -1;
		}



vertex2=vertex_initFromString("id:20 tag:two state:1");

	if(vertex2==NULL){ 
		return -1;
		}

if(vertex_print(stdout, vertex1)==-1){ 
	return -1;
	}
if(vertex_print(stdout, vertex2)==-1) {
	return -1;
	}

printf("\nEquals?");
if(vertex_cmp(vertex1,vertex2)!=0){ 
	printf(" No");
	}else{ 
		printf(" Yes");
		}

printf("\nVertex 2 tag: %s",vertex_getTag(vertex2));

vertex3=vertex_copy(vertex1);

printf("\nVertex 3 id: %ld\n",vertex_getId(vertex3));

if(vertex_print(stdout, vertex1)==-1) return -1;
if(vertex_print(stdout, vertex3)==-1) return -1;

printf("\nEquals?");
if(vertex_cmp(vertex1,vertex3)!=0) printf(" No");
else printf(" Yes\n");

vertex_free(vertex1);
vertex_free(vertex2);
vertex_free(vertex3);

return 0;
}
