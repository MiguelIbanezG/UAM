#include <stdio.h>

#define MAX_STR 128
#define DIM_NOVELAS 4

typedef struct {
    char nombre[MAX_STR];
    char primer_apellido[MAX_STR];
    char segundo_apellido[MAX_STR];
} Escritor;

typedef struct {
    Escritor autor;
    char titulo[MAX_STR];
    int fecha;
} Libro;

int main () {
    Libro novelas[DIM_NOVELAS];

    /* Primer libro */
    printf("Introduce el nombre del autor del primer libro: ");
    gets(novelas[0].autor.nombre);
    printf("Introduce el título del primer libro: ");
    gets(novelas[0].titulo);

    /* Segundo libro */
    printf("Introduce el nombre del autor del segundo libro: ");
    
    printf("Introduce el título del segundo libro: ");
    gets(novelas[1].titulo);

    printf("%s fue escrito por %s.\n", novelas[0].titulo, novelas[0].autor.nombre);
    printf("%s fue escrito por %s.\n", novelas[1].titulo, novelas[1].autor.nombre);
   
    return 0;
}
