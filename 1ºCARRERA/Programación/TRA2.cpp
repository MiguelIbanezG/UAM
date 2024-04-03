/* NOTA: Este programa admite otras posibles soluciones */

#include <stdio.h>

int main () 
{
    int num1, num2;

    printf("Introduce un numero: ");
    scanf("%d", &num1);
    printf("Introduce otro numero: ");
    scanf("%d", &num2);

    if ( (num1%2 == 0) && (num2%2 == 0) )
        printf("Los numeros %d y %d son pares", num1, num2);
    else if ( (num1%2 == 0) && (num2%2 != 0) )
        printf("El numero %d es par y el numero %d es impar", num1, num2);
    else if ( (num1%2 != 0) && (num2%2 == 0) )
        printf("El numero %d es impar y el numero %d es par", num1, num2);
    else
        printf("Los numeros %d y %d son impares", num1, num2);

    return 0;
}
