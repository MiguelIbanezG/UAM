#include <stdio.h>

#define MAX_STR 128
#define MAX_EDICIONES 10

typedef struct {
    char autor[MAX_STR];
    char titulo[MAX_STR];
    int fechas_ediciones[MAX_EDICIONES];
} Libro;

int main () {
    Libro novela = {"Mario Vargas Llosa", "El h�roe discreto", {2013, 2014, 2016}};

    novela.fechas_ediciones[1] = 2015;
   
    printf("%s fue escrito por %s y publicado en %d, %d y %d.\n", novela.titulo, novela.autor, novela.fechas_ediciones[0], novela.fechas_ediciones[1], novela.fechas_ediciones[2]);
    
    return 0;
}
