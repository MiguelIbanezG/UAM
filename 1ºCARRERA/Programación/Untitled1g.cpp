#include <stdio.h>
#include <string.h>

#define TAM 64

int main() {
    char cadena[TAM];
    int posicion;
    
    printf("Escribe una palabra: ");
    scanf("%s", cadena);
    
    printf("La longitud de la palabra es: %d.\n", strlen(cadena));
    
    printf("Indica un número menor a dicha longitud: ");
    scanf("%d", &posicion);

   
    printf("La palabra cortada en la letra %d es: %s.\n", posicion, cadena);
    
    return 0;
}
