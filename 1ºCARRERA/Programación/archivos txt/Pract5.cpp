#include <stdio.h>
#include <stdlib.h>

#define TAM 128

typedef struct 
{
    char nombre[TAM]; //Nombre del artÃ­culo comprado
    int cantidad; //Cantidad de artÃ­culos comprados
    float precio; //Precio por unidad
} Compra;

typedef struct
{
    Compra *articulos; //Puntero a tabla de artÃ­culos comprados
    int cantidadArticulos; //Cantidad de elementos guardados en la tabla
} ListaCompra;

int leeListaCompra(char *nombreFichero, ListaCompra * pListaCompra)
{
    FILE * fichero;
    int i;
    
    if (nombreFichero==NULL || pListaCompra==NULL)
        return 0;
    
    fichero=fopen(nombreFichero, "r");
    if (fichero==NULL)
        return 0;
    
    fscanf(fichero, "%d", &pListaCompra->cantidadArticulos);
    
    pListaCompra->articulos=(Compra *)malloc(pListaCompra->cantidadArticulos*sizeof(Compra));
    if (pListaCompra->articulos == NULL)
        return 0;
    
    for(i=0; i<pListaCompra->cantidadArticulos; i++)
        fscanf(fichero, "%s %d %f", pListaCompra->articulos[i].nombre, &pListaCompra->articulos[i].cantidad, &pListaCompra->articulos[i].precio);
    
    return 1;
}

int calculaListaCompra(ListaCompra lista, float *precioTotal, int * numArticulos, float *barato, float *caro)
{
 
    if (lista.cantidadArticulos<0 || precioTotal==NULL || numArticulos==NULL || barato==NULL || caro==NULL)
        return 0;
    
    for(*numArticulos=*precioTotal=*barato=*caro=0; *numArticulos<lista.cantidadArticulos; (*numArticulos)++)
    {
        *precioTotal+=lista.articulos[*numArticulos].cantidad * lista.articulos[*numArticulos].precio;
        
        if (*numArticulos==0)
            *barato=*caro=lista.articulos[*numArticulos].precio;
        else
        {
            if (lista.articulos[*numArticulos].precio < *barato)
                *barato = lista.articulos[*numArticulos].precio;
            
            if (lista.articulos[*numArticulos].precio > *caro)
                *caro = lista.articulos[*numArticulos].precio;
        }
    }
        
    return 1;
}

int main()
{
    char nombre[TAM];
    ListaCompra lista;
    float precTotal, masBarato, masCaro;
    int i, numArt;
    
    printf("Introduce el nombre del fichero con la lista de la compra: ");
    scanf("%s", nombre);
    
    if (!leeListaCompra(nombre, &lista))
    {
        printf("Error en la ejecucion del programa");
        return 1;
    }
    
    if (!calculaListaCompra(lista, &precTotal, &numArt, &masBarato, &masCaro))
    {
        printf("Error en la ejecucion del programa");
        free(lista.articulos);
        return 1;
    }
    
    printf("La lista de la compra está compuesta por:\n");
    for(i=0; i<lista.cantidadArticulos; i++)
        printf("Articulo %d: %s, con %d unidad(es), a %.2f€ la unidad\n", i+1, lista.articulos[i].nombre, lista.articulos[i].cantidad, lista.articulos[i].precio);
    
    printf("El precio total de los %d articulos diferentes de la lista de la compra es %.2f€\n", numArt, precTotal);
    printf("El articulo mas barato cuesta %.2f€ y el articulo mas caro cuesta %.2f€", masBarato, masCaro);
    
    free(lista.articulos);
    
    return 0;
}
