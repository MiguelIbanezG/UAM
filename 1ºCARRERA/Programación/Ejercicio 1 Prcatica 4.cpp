#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int * coincidencias(char *cadena1, char *cadena2){	

	int *cad3, j, i;

	 cad3 =(int *)malloc(strlen(cadena2)*sizeof(int));
	 
    if (cad3==NULL)
    {
        printf("La reserva de memoria ha fallado");
        free(cad3);
    
    }
    
    
    for(i=0; cadena2[i]!=0; i++)
    {
        for(j=0; cadena1[i]!=0; j++){
            if (cadena2[i]==cadena1[j]){
			(cad3[i])++;
		}
		}
		
	}
	


}



int main(){
	
	char *cad1, *cad2;
	int i,*cad3;
	
	printf("Introduce una palabra: ");
	scanf("%s", cad1);
	
	printf("Introduce otra palabra: ");
	scanf("%s", cad2);
	
	coincidencias(cad1, cad2);
	
	for(i=0;cad2[i]!=0;i++){
		printf("El carácter %c de la palabra %s aparece %d veces en la palabra %s ", cad2[i], cad2, cad3 , cad1);
	}
	

}
