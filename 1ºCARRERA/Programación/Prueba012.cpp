#include <stdio.h>

int  main(){


int n1;
char c1;

printf("Por favor, introduce un n�mero (entre 1 y 5): ");
scanf("\n%d", &n1);

printf("Por favor, introduce un car�cter: ");
scanf("\n%c", &c1);

printf("El car�cter %c con c�digo ASCII %d, si se cifra con el n�mero %d se convertir�a en el car�cter %c con el c�digo ASCII: %d ", c1, c1, n1,c1+n1, c1+n1);

return 0;
}

