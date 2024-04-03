#include <stdio.h>

#define TAM 128

int leerCadenas(char * nombre, char *cadena1, char *cadena2)
{
    FILE *f;
    
    f=fopen(nombre, "r");
    if (!f)
        return 0;
    
    fscanf(f, "%s", cadena1);
    fscanf(f, "%s", cadena2);
    
    fclose(f);
    
    return 1;
   
}

int comparaCadenas(char * nombre, char *cadena1, char *cadena2)
{
    int i, j, flag, veces;
    FILE * fichero;
    
    fichero=fopen(nombre, "a");
    if (!fichero)
        return 0;

    for(i=0; cadena1[i]!=0; i++)
    {
        for(j=flag=0; j<i; j++)
            if (cadena1[i] == cadena1[j])
                flag=1;
        
        if (!flag)
        {
            for(j=veces=0; cadena2[j]!=0; j++)
                if (cadena1[i]==cadena2[j])
                    veces++;

            if (veces)
                fprintf(fichero, "\nEl carÃ¡cter %c aparece %d veces en la cadena %s", cadena1[i], veces, cadena2);
            else
                fprintf(fichero, "\nEl carÃ¡cter %c NO aparece en la cadena %s", cadena1[i], cadena2);
        }
    }
    
    fclose(fichero);
    
    return 1;

}

int main()
{
    char c1[TAM], c2[TAM], nombre[TAM];
    
        
    printf("Introduce el nombre del fichero que contiene las cadenas: ");
    scanf("%s", nombre);
    
    if (!leerCadenas(nombre, c1, c2))
    {
        printf("Error al leer los datos del fichero");
        return 1;
    }
    
    if (!comparaCadenas(nombre, c1, c2))
    {
        printf("Error al guardar los datos del fichero");
        return 1;
    }
    
    printf("La informaciÃ³n se ha guardado correctamente en el fichero %s", nombre);

    return 0;

}
