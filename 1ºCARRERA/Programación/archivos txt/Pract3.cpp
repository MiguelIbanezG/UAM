#include <stdio.h>

#define DIM 80

int leer (char * nombre, double * resultado, int limite)
{
    FILE * f;
    int pr,se,cuar,quin,numero=0;
    double ter,media;
    

    f = fopen(nombre, "r");
    if (f == NULL)
	{
    fclose(f);
    return 1;
	}	

    while (fscanf(f, "%d %d %lf %d %d", &pr, &se, &ter,&cuar,&quin) == 5)
        if ((cuar) > limite)
        {
        	
            *resultado+=se;
            numero++;
            
        }
        if(numero!=0){
        *resultado/=numero;
        }
        if(numero=0){
        *resultado=0.0;
        }

    fclose(f);
    return 0;
}

int main() 
{
    char nombre[DIM];
    int limite;
    double resultado;

    printf("Teclea el nombre del archivo  ");
    scanf("%s", nombre);
    
    printf("Teclea el valor limite: ");
    scanf("%d", &limite);
    
    leer (nombre,&resultado,limite);

    if ( leer (nombre,&resultado,limite) == 1) 
    {
        printf("Error: no se pudo abrir el fichero %s", nombre);
        return 1;
    }
    
    printf("La media de la segunda columna con el limite igual a %d es: %2.lf", limite,resultado);

    return 0;
}
