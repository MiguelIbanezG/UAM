#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define DIM 1000

typedef struct
{
    int edad;
    float nota;
}Registro;

typedef struct
{
    Registro * tablaDatos;
    int numDatos;
}Datos;

int leeFichero(char *nombreFichero, Datos * x){
	FILE *f;
	
    f = fopen(nombreFichero, "r");
    if (f==NULL)
    {
    	return 1;
    }
    
    for(x->numDatos=0;fscanf(f, "%d %f", &x->tablaDatos->edad, x->tablaDatos->nota) == 2;x->numDatos++)
    
    x->tablaDatos = (Registro*)malloc(x->numDatos*sizeof(Registro));
    
    if (x==NULL)
    {
    	return -1;
    }
    
    fclose(f);
    free(x);
    return 0;
}

float notaMedia(Datos dat, int edad){
	int i,aa,calc;
	
	for(i=0; i<dat.numDatos; i++)
	{
		if(edad=dat.tablaDatos->edad)
		{
		aa+=dat.tablaDatos->nota;
		calc++;
		}
	}
	
	if(calc==0)
	{
		return -1;
	}
	
	return aa/calc;
}

int main(){
	int eda;
	Registro R;
	Datos D;
	char c[DIM];
	
	printf("Introduce el nombre del fichero de datos: ");
	scanf("%s",c);
	
	
	leeFichero(c,&D);
	
	 if (leeFichero(c,&D)==0)
    {
    	printf("Se han leído 6 registros del fichero");
    	return 0;
    }
    if (leeFichero(c,&D)==1)
    {
    	printf("Error leyendo los registros del fichero");
	}
	if (leeFichero(c,&D)==-1)
    {
    	printf("Error almacenando espacio a la memoria");
	}
    
     printf("Introduce la edad sobre la que quieres calcular la nota media: ");
	scanf("%d", &eda);

	notaMedia(D, eda);
	
	if(notaMedia(D,eda) == -1)
	{
	printf ("No hay nadie de %d años registradas en el fichero", eda);
	}
	else{
	printf("La nota media de las personas con %d años es %f", eda, notaMedia);
     }
     
     return 0;
	
}
