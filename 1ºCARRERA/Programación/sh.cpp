#include <stdio.h>

#define TAB 5

int main(){
	
	int num;
	int tabla[TAB];
	int i=0;
	
	printf("�Cu�ntos n�meros quieres teclear? (entre 2 y 10): ");
	scanf("%d",&num);
	
	while (num<2 || num>10){
		
		printf("Error, debes introducir un n�mero entre 2 y 10: ");
		scanf("%d",&num);
	}
	
		while (num>i){
		
		printf("Introduce el n�mero %d de %d: ", i + 1, num);
		scanf("%d",&tabla[i]);
		i++;
	}
	    printf("Los numeros pares son: ");
	    
    i = num-1;
    while (i>=0) 
    {
        if (tabla[i] % 2 == 0)
            printf("%d ", tabla[i]);
        i--;
    }

    printf("\nLos números impares son: ");

    i = num-1;
    while (i>=0) 
    {
        if (tabla[i] % 2 != 0)
            printf("%d ", tabla[i]);
        i--;
    }

    return 0;
}

