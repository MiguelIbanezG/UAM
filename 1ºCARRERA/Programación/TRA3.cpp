/* NOTA: Este programa admite otras posibles soluciones */

#include <stdio.h>

int main () 
{
    int uno, dos, tres;

    printf("Introduce el primer numero: ");
    scanf("%d", &uno);
    printf("Introduce el segundo numero: ");
    scanf("%d", &dos);
    printf("Introduce el tercer numero: ");
    scanf("%d", &tres);

    if ( (uno==dos) && (dos==tres) )
        printf("Los tres numeros son iguales");
    else if ( (uno!=dos) && (dos!=tres) && (uno!=tres) )
        printf("Los tres numeros son diferentes");
    else
        printf("Hay dos numeros iguales y uno diferente");

    return 0;
}
