#include <stdio.h>


int main(){
	FILE *f;
	double nota, media;
	char DNI[9], cad[15];
	int num;
	
	
	  f = fopen ("listado.txt", "r");
    if (f == NULL)
    {
        printf ("Error abriendo el archivo\n");   
         return 1;
    }
    for (num=0, media=0.0; fscanf (f, "%s %lf %s", DNI, &nota, cad) == 3; num ++)
    {
        media += nota;
    }
   
    
    f = fopen ("listado.txt", "a");
    if (f == NULL)
    {
        printf ("Error abriendo el archivo\n");
		fclose(f);  
        return 1;
    }
       
    fprintf(f, "La nota media es %lf \n", media/num);
	
	fclose(f);
	return 0;
	
}
