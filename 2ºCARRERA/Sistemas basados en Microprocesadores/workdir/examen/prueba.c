/*Sergio Hidalgo Gamborino, 05964532B*/
#include <stdio.h>
#include <stdlib.h>


unsigned int esTriangular(unsigned int numero);


int main(){
    int numero;


    printf("Introduzca numero: "); /*Se pide al usuario que introduzca el numero*/
    scanf("%d", &numero);


    printf("\nEl numero %d "); 

    if (esTriangular(numero) == 0) /*Si el numero no es triangular, imprimira "NO"*/
    {
        printf("NO");
    }
    
    printf("es triangular\n");



    return 0;
}