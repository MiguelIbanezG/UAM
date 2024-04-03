/*
*Título: Main file, práctica 1, ejercicio 1, programación 2
*Grupo: viernes 2113
*Autores: Sergio Hidalgo y Miguel Ibáñez 
*/

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "vertex.h"
#include "types.h"

int main()
{

    Vertex *v1;
    Vertex *v2;
    Vertex *v3;

    v1 = vertex_initFromString("id:10 tag:one state:0");
    v2 = vertex_initFromString("id:20 tag:two state:1"); /*Se crean dos vértices y se inicializan*/

    vertex_print(stdout, v1);
    vertex_print(stdout, v2); /*Se imprimen ambos vértices*/

    printf("\n");

    printf("Equals?");
    if (vertex_cmp(v1, v2) == 0) /*Condición que deben cumplir para ser iguales*/
    {
        printf(" Yes");
    }
    else
        printf(" No");

    printf("\nVertex 2 tag: %s", vertex_getTag(v2)); /*Se imprime el tag del segundo vértice*/

    v3 = vertex_init();   /*Se inicializa el tercer vértice*/
    v3 = vertex_copy(v1); /*Y en el se copia el primer vértice*/

    printf("\nVertex 3 id: %ld", vertex_getId(v3)); /*Se imprime el id del tercer vértice*/

    printf("\n");

    vertex_print(stdout, v1);
    vertex_print(stdout, v3); /*Se imprimen el primer y tercer vértice*/

    printf("\n");

    printf("Equals? "); /*Se comparan*/
    if (vertex_cmp(v3, v1) == 0)
        printf("Yes");
    else
        printf("No");

    /*Y se libera la memoria*/
    vertex_free(v1);
    vertex_free(v2);
    vertex_free(v3);

    printf("\n");

    return 0;
}