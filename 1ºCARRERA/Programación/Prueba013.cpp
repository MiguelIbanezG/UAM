#include <stdio.h>

int  main(){


int n1;
char c1;

printf("Por favor, introduce una letra: ");
scanf("\n%c", &c1);

printf("Por favor, introduce un número: ");
scanf("\n%d", &n1);

if (n1%2==0){
	printf("La nueva letra es %c ", c1);
}
else{
	printf("La nueva letra es %c ",c1+1 );
}
return 0;
}

