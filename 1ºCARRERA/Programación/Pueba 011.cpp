#include <stdio.h>

int  main(){


int edad;
double altura, peso;
char nombre;

printf("Por favor, introduce la altura en cm: ");
scanf("\n%lf", &altura);

printf("A continuaci�n, introduce la edad en a�os: ");
scanf("\n%d", &edad);

printf("Por �ltimo, introduce la inicial del nombre: ");
scanf("\n%c", &nombre);

peso = altura - 100 + (9*edad)/100;

printf("El peso ideal de %c, que mide %.1lf cm y tiene %d a�os es de %.3lf kg. ", nombre, altura, edad, peso);

return 0;
}




