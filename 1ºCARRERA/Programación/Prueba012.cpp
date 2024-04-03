#include <stdio.h>

int  main(){


int n1;
char c1;

printf("Por favor, introduce un número (entre 1 y 5): ");
scanf("\n%d", &n1);

printf("Por favor, introduce un carácter: ");
scanf("\n%c", &c1);

printf("El carácter %c con código ASCII %d, si se cifra con el número %d se convertiría en el carácter %c con el código ASCII: %d ", c1, c1, n1,c1+n1, c1+n1);

return 0;
}

