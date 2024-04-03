/*
*Título: Ejercicio 2b, práctica 3, programación 2
*Grupo: viernes 2113
*Autores: Sergio Hidalgo y Miguel Ibáñez 
*/
#include <stdio.h>
#include <string.h>
#include "types.h"
#include "delivery.h"
#include "vertex.h"
#include "product.h"

Delivery *build_delivery(FILE *pf);

Status delivery_add(Delivery *d, Product *p);

Status delivery_run_plan(FILE *pf, Delivery *d);

int main(int argc, char *argv[])
{
    FILE *pf;
    Delivery *d;

    if (argc != 2) /*Si el número de argumentos es distinto de 2 el programa no se ejecuta*/
    {
        fprintf(stdout, "Falta el archivo descriptivo");
        return -1;
    }

    pf = fopen(argv[1], "r"); /*Se abre el archivo*/

    if (pf == NULL)
    {
        return -1;
    }

    d = build_delivery(pf); /*Se crea el delivery a partir de un archivo*/

    if (d == NULL)
    {
        fprintf(stdout, "Error creating delivery");
        return -1;
    }

    /*Se ejecuta el plan*/

    if (delivery_run_plan(stdout, d) == ERROR)
    {
        return -1;
    }

    fclose(pf); /*Se cierra el archivo*/

    delivery_free(d); /*Se libera el delivery*/

    return 0;
}

Status delivery_add(Delivery *d, Product *p)
{
    if (d == NULL || p == NULL)
    {
        return ERROR;
    }

    fprintf(stdout, "      Adding the following product:\n"); /*Se printea la información del producto y la entrega*/

    if (product_print(stdout, p) == -1)
    {
        return ERROR;
    }

    fprintf(stdout, "\n      to delivery:\n");

    if (delivery_print(stdout, d, product_print) == -1)
    {
        return ERROR;
    }

    if (queue_push(delivery_getPlan(d), p) == ERROR) /*Se introduce el producto en la cola*/
    {
        return ERROR;
    }

    return OK;
}

Delivery *build_delivery(FILE *pf)
{
    Delivery *d;
    Product *p;
    char string[50];
    char sitio[50], nombre_producto[50];
    int cantidad, num, i, capacidad;

    fgets(string, 50, pf);
    sscanf(string, "%s %s %d", sitio, nombre_producto, &capacidad); /*Se leen las variables del nombre del sitio, el producto y la capacidad*/

    d = delivery_init(sitio, nombre_producto); /*Se inicializa el delivery a través de las variables anteriormente leidas*/

    if (d == NULL || pf == NULL)
    {

        return NULL;
    }

    delivery_setCapacity(d, capacidad); /*Se edita la capacidad*/

    fgets(string, 50, pf);
    sscanf(string, "%d", &num); /*"num" indica el numero de peticiones*/

    for (i = 0; i < num; i++)
    {

        fgets(string, 50, pf);

        sscanf(string, "%d", &cantidad); /*Se lee la cantidad de producto solicitado*/

        fgets(string, 50, pf);

        p = product_init(vertex_initFromString(string)); /*Inicialización del producto y del vertex que lo forma*/

        if (p == NULL)
        {

            return NULL;
        }

        if (product_setAmount(p, cantidad) == ERROR) /*Se edita esa cantidad*/
        {
            return NULL;
        }

        if (delivery_add(d, p) == OK) /*Si se añade correctamente el producto*/
        {

            fprintf(stdout, "      Status = 1\n"); /*el status será igual a 1*/
        }
        else
        {

            fprintf(stdout, "      Status = 0\n"); /*y sino 0*/
        }
    }

    return d;
}

Status delivery_run_plan(FILE *pf, Delivery *d)
{
    int i = 0, tam, cont = 0;
    char sitio[50], nombre_producto[50];
    Product *p[30];
    Queue *q;

    if (pf == NULL || d == NULL)
    {
        return ERROR;
    }

    q = delivery_getPlan(d);

    if (q == NULL)
    {
        return ERROR;
    }

    tam = queue_size(q); /*Tamaño de la cola del plan*/

    if (tam == 0)
    {
        return ERROR;
    }

    fprintf(pf, "\nRunning delivery plan for queue:\n");

    strcpy(sitio, delivery_getName(d)); /*Obtención del nombre del lugar*/

    strcpy(nombre_producto, delivery_getProductName(d)); /*Y del producto*/

    while (queue_isEmpty(q) == FALSE) /*Mientras la cola del plan no esté vacia*/
    {
        p[i] = queue_pop(q); /*Se sacará una petición y se printeará por pantalla*/

        if (p[i] == NULL)
        {
            return ERROR;
        }

        if (product_print(pf, p[i]) == -1)
        {
            return -1;
        }

        i++;
    }

    fprintf(pf, "\n");

    for (i = 0; i < tam; i++)
    {
        if (cont > delivery_getCapacity(d)) /*Si se ha superado la cantidad máxima de producto saldrá un mensaje que informa de que no se realizará la entrega*/
        {
            fprintf(pf, "Not Delivering %s requested by %s to %s: wanted %d, max capacity: %d\n", sitio, nombre_producto, vertex_getTag(product_getVertex(p[i])), product_getAmount(p[i]), delivery_getCapacity(d));
        }
        else
        {
            fprintf(pf, "Delivering %s requested by %s to %s: wanted %d", sitio, nombre_producto, vertex_getTag(product_getVertex(p[i])), product_getAmount(p[i]));
            cont = cont + product_getAmount(p[i]); /*Se suma la cantidad total de entregas del producto que se van a realizar*/

            if (cont > delivery_getCapacity(d)) /*Si una vez planificado, el programa detecta que no hay suficientes productos para la entrega*/
            {
                fprintf(pf, ", obtained %d", delivery_getCapacity(d) - cont + product_getAmount(p[i])); /*Se printeara cuantos productos se pueden entregar*/
            }
            fprintf(pf, "\n");
        }
    }

    for (i = 0; i < tam; i++)
    {
        product_free(p[i]); /*Se libera la memoria*/
    }

    return OK;
}
