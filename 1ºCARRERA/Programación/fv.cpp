#include <stdio.h>

#define UNO 10

int main (){
	
	int n,i=0;
	int tabla[UNO];
	
	printf("Introduzca un número entero (0 para terminar): ");
	scanf("%d", n);
	
	if (n=0){
		printf("No se ha introducido ningún número. ");
	}

    i=0;
    while (n!=0 && i<10) 
    {
        printf("Introduzca un número entero (0 para terminar): ");
        scanf("%d", &tabla[i]);
        i++;
    }
    printf("Número máximo de números alcanzado. Continuando...: ");
    
    i=0;
    while (i<n){
    printf("Los números tecleados son: ", tabla[i]);
    i++;
}
return 0;
}
