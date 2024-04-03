#include <stdio.h>

#define DIM 80

int leer(char * nombre, double * resultado, int limite) 
{
    FILE * f;
    int numero;
    int primero, segundo, cuarto, quinto;
    double tercero;

    f = fopen(nombre, "r");

    if (f == NULL)
        return 1;

    for (*resultado = 0.0, numero = 0; fscanf(f, "%d %d %lf %d %d", &primero, &segundo, &tercero, &cuarto, &quinto) == 5;) 
    {
        if (cuarto > limite) 
        {
            *resultado += segundo;
            numero++;
        }
    }

    if (numero)
        *resultado /= numero;
    else
        *resultado = 0.0;

    fclose(f);

    return 0;
}

int main() 
{
    char nombre [DIM];
    int limite;
    double media;

    printf("Teclea el nombre del archivo: ");
    scanf("%s", nombre);

    printf("Teclea un número entero: ");
    scanf("%d", &limite);

    if (leer(nombre, &media, limite) == 1) 
    {
        printf("Error: no se pudo abrir el fichero %s.", nombre);
        return 1;
    }

    printf("La media de la segunda columna con el límite igual a %d es %.2lf\n", limite, media);

    return 0;

}
