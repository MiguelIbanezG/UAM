#include <stdio.h>

#define TAB 5

int main () 
{
	int tabla [TAB],i;
	
	i=0;
	do{
	    printf("Introduce un n�mero par (%d de 5): ",i+1);
	    scanf("%d", &tabla[i]);
	    if(i<5 && tabla[i]%2!=0){
	        printf("Error, debes introducir un n�mero par. Vuelve a intentarlo\n");
	        printf("Introduce un n�mero par (%d de 5): ",i+1);
	        scanf("%d", &tabla[i]);
			}
	        i++;
	    	
	}while(i<5);
	
	printf("Los n�meros introducidos menores que el �ltimo (%d) y mostrados en orden inverso son: \n ", tabla[4]);
	i=3;
	while(i>-1){
		if(tabla[4]>tabla[i]){
	    printf(" %d ",tabla[i]);
	    }
	    i--;	
	}
	
    return 0;
}
