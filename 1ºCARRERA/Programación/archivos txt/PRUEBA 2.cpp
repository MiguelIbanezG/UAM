#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define DIM 1000

int buscaCoincidencias (char * nFichero1, char * nFichero2, char * nFicheroSalida){
	FILE *f, *f2, *s;
	int numero,numero2,i,j,c;
	
	f = fopen(nFichero1, "r");
	if (f==NULL)
    {
    	return 1;
    }
    
	f2 = fopen(nFichero2, "r");
	if (f2==NULL)
    {
    	return 1;
    	fclose(f);
    }
    
    s = fopen(nFicheroSalida, "w");
	if (s==NULL)
    {
    	return 1;
    	fclose(f);
    	fclose(f2);
    }
    
    for(i=0,c=0;fscanf(f,"%d",&numero)==1;i++){
    	for(j=0;fscanf(f2,"%d",&numero2)==1;j++){
    		if(numero2==numero){
    			fprintf(s,"%d\n",numero2);
    			c++;
			}
		}
	}

	if(c==0)
	{
		fprintf(s,"No hay ninguna coincidencia en los ficheros");
	}
	
	fclose(f);
	fclose(f2);
	fclose(s);
	return 0;
}

int main(){
	char f[DIM], f2[DIM],s[DIM];
	
	printf("Introduce el nombre de un fichero con los números: ");
	scanf("%s", f);
	printf("Introduce el nombre de otro fichero con los números: ");
	scanf("%s", f2);
	printf("Introduce el nombre del fichero donde guardar las coincidencias: ");
	scanf("%s", s);
	
	 
	if(buscaCoincidencias (f, f2, s)==1){
		printf("Error ejecutando el programa");
		return 1;
	}
	
	if(buscaCoincidencias (f, f2, s)==0){
		printf("Información guardada en el fichero %s", s);
		return 0;
	}

}
