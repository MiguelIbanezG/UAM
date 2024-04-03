#include <stdio.h>

int  main(){


int edad;
double altura, peso;
char nombre;

printf("Por favor, introduce la altura en cm: ");
scanf("\n%lf", &altura);

printf("A continuación, introduce la edad en años: ");
scanf("\n%d", &edad);

printf("Por último, introduce la inicial del nombre: ");
scanf("\n%c", &nombre);

peso = altura - 100 + (9*edad)/100;

printf("El peso ideal de %c, que mide %.1lf cm y tiene %d años es de %.3lf kg. ", nombre, altura, edad, peso);

return 0;
}




