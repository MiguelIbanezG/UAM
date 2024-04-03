#include <stdio.h>
#include <string.h>

#define TAM 128

int procesaFichero(char *nombreFichero, char*nombreBuscado)
{
    FILE * fichero;
    int i, encontrado;
    char nombre[TAM];
    
    if (nombreFichero==NULL || nombreBuscado==NULL)
        return 0;
    
    fichero=fopen(nombreFichero, "r");
    if (fichero==NULL)
        return 0;
    
    for (i=encontrado=0; fscanf(fichero, "%s", nombre)==1; i++)
    {
        if(strcmp(nombreBuscado, nombre)==0)
            encontrado=1;
    }
    
    fclose(fichero);
    
    fichero=fopen(nombreFichero, "a");
    if (fichero==NULL)
        return 0;
    
    if (encontrado)
        fprintf(fichero, "El fichero tiene %d nombre(s) y %s se encuentra entre ellos.", i, nombreBuscado);
    else
        fprintf(fichero, "El fichero tiene %d nombre(s) y %s no se encuentra entre ellos", i, nombreBuscado);
                
    fclose(fichero);    
           
    return 1;
}

int main()
{
    char nombreFich[TAM], nombrePer[TAM];
    
    printf("Introduce el nombre del fichero con los nombres: ");
    scanf("%s", nombreFich);
    
    printf("Introduce el nombre de la persona que quieres buscar: ");
    scanf("%s", nombrePer);

    if (!procesaFichero(nombreFich, nombrePer))
    {
        printf("Error en la ejecucion del programa");
        return 1;
    }
    
    printf("Informacion guardada correctamente en el fichero %s. Abrelo para verla.", nombreFich);
            
    return 0;
}
