#include <stdio.h>

#define MAX_STR 128

typedef struct {
    char autor[MAX_STR];
    char titulo[MAX_STR];
    int anyo;
} ;

int main () {
    Libro novela = {"Mario Vargas Llosa", "El héroe discreto", 2013};
   
    printf("%s fue escrito por %s en %d.\n", novela.titulo, novela.autor, novela.anyo);  

    return 0;
}
