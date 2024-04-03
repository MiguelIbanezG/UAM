/*
*Título: Ejercicio 3, práctica 3, programación 2
*Grupo: viernes 2113
*Autores: Sergio Hidalgo y Miguel Ibáñez 
*/
#include <stdio.h>
#include <string.h>
#include "types.h"
#include "vertex.h"
#include "list.h"

int main(int argc, char *argv[])
{
    FILE *pf;
    char string[50];
    int num, i, par = 0;
    long size;
    Vertex *v[30];
    List *ls = list_new();

    if (argc != 2) /*Si el número de argumentos es distinto de 2 el programa no se ejecuta*/
    {
        fprintf(stdout, "Falta el archivo descriptivo\n");
        return -1;
    }

    pf = fopen(argv[1], "r"); /*Se abre el archivo*/

    if (pf == NULL)
    {
        return -1;
    }
    

    fgets(string, 50, pf);
    sscanf(string, "%d", &num);

    for (i = 1; i <= num; i++)
    {
        fgets(string, 50, pf);

        (v)[i - 1] = vertex_initFromString(string); /*Se inicializa un vertice en la array*/

        if ((v)[i - 1] == NULL)
        {
            return -1;
        }

        if (i % 2 != 0) /*Si es impar se insertará al final*/
        {

            if (list_pushBack(ls, (void *)v[i - 1]) == ERROR)
            {
                return -1;
            }
        }
        else /*Si es par al principio*/
        {

            if (list_pushFront(ls, (void *)v[i - 1]) == ERROR)
            {
                return -1;
            }
            par++; /*Y se contará cuantos pares hay*/
        }
    }

    size = list_size(ls);

    if (size == -1)
    {
        return -1;
    }
    

    fprintf(stdout, "SIZE: %ld\n", size); /*Tamaño de la lista*/

    /*Printeo de la lista*/
    if (list_print(stdout, ls, vertex_print) < 0)
    {
        return -1;
    }

    fprintf(stdout, "Finished inserting. Now we extract from the beginning:\n");

    for (i = 0; i < par; i++)
    {
        /*Extracción y printeo de los elementos que se encuentran al principio*/
        if (vertex_print(stdout, (Vertex *)list_popFront(ls)) < 0)
        {
            return -1;
        }
    }

    fprintf(stdout, "\nNow we extract from the end:\n");

    do
    {
        /*Extracción y printeo de los elementos que se encuentran al final*/
        if (vertex_print(stdout, (Vertex *)list_popBack(ls)) < 0)
        {
            return -1;
        }

    } while (list_isEmpty(ls) == FALSE);

    fprintf(stdout, "\n");

    for (i = 0; i < num; i++) /*Liberación de memoria y cierre del archivo de texto*/
    {
        vertex_free(v[i]);
    }

    list_free(ls);

    fclose(pf);
    return 0;
}
