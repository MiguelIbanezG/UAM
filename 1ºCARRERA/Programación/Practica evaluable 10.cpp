#include <stdio.h>

#define TAB 5

int main () 
{
	int tabla [TAB],i=0,j=0;;
	
	while(i<5){
	    printf("Introduce un n�mero par (%d de 5): ",j+1);
	    scanf("%d", &tabla[i]);
	    j++;
	    if(tabla[i]%2!=0){
	    	j--;
	        printf("Error, debes introducir un n�mero par. Vuelve a intentarlo\n");
	        printf("Introduce un n�mero par (%d de 5): ",j+1);
	        scanf("%d", &tabla[i]);
	        i++;
	    }	
	}
	
	i=3;
	while(tabla[4]>tabla[i]){
	    printf("Los n�meros introducidos menores que el �ltimo (%d) y mostrados en orden inverso son: ", tabla[4],tabla[i]);
	    i--;	
	}
	
    return 0;
}
