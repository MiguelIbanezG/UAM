#include <stdio.h>

#define NOM 128
#define TAB 2


typedef struct {
    char nombre[NOM];
    int edad;
} Persona;

typedef struct {
    Persona tabla[TAB];
    double media;
} Gente;

int main () {
    Gente valor;
   
    printf("Introduce un nombre: ");
    gets(valor.tabla[0].nombre);
    printf("Introduce una edad:  ");
    scanf("%d", valor.tabla[0].edad);
    
    printf("Introduce otro nombre: ");
    gets(valor.tabla[1].nombre);
    printf("Introduce otra edad:   ");
    scanf("%d", valor.tabla[1].edad);
    
     printf("%s tiene %s años y %s tiene %s años. ",valor.tabla[0].nombre,valor.tabla[0].edad,valor.tabla[1].nombre, valor.tabla[1].edad );
     
     valor.media = (valor.tabla[0].edad + valor.tabla[1].edad)/2;
     
      printf("La media de sus edades es de %2.lf años. ", valor.media);
     
   

   
    return 0;
}
