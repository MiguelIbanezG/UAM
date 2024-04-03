#include <stdio.h>

#define MAX_STR 128
#define INFO 3
#define USERS 5
#define PARTIDAS 3

typedef struct {
    char campeon[MAX_STR];
    int kda[INFO];
} juego;

typedef struct {
    char nombre[MAX_STR];
    int nivel;
    int experiencia;
    juego partida[PARTIDAS];
} invocador;

int main() {    
    invocador usuario[USERS];
    int kda_total[INFO];
    double ratio[PARTIDAS];

    printf("JUGADOR 1\n");
    printf("¿Cual es tu nombre de invocador? ");
    scanf("%s", usuario[0].nombre);
    printf("¿Con que campeon has jugado tu ultima partida? ");
    scanf("%s", usuario[0].partida[0].campeon);
    printf("¿Cuantos asesinatos has hecho? ");
    scanf("%d", &usuario[0].partida[0].kda[0]);
    printf("¿Cuantas veces has muerto? ");
    scanf("%d", &usuario[0].partida[0].kda[1]);
    printf("¿Y cuantas asistencias has hecho? ");
    scanf("%d", &usuario[0].partida[0].kda[2]);

    printf("\n¿Con que campeon has jugado tu penultima partida? ");
    scanf("%s", usuario[0].partida[1].campeon);
    printf("¿Cuantas asesinatos hiciste? ");
    scanf("%d", &usuario[0].partida[1].kda[0]);
    printf("¿Cuantas veces te mataron? ");
    scanf("%d", &usuario[0].partida[1].kda[1]);
    printf("Â¿Y cuantas asistencias hiciste? ");
    scanf("%d", &usuario[0].partida[1].kda[2]);

    printf("\n¿Con que campeon has jugado tu antepenultima partida? ");
    scanf("%s", usuario[0].partida[2].campeon);
    printf("¿Cuantos asesinatos hiciste? ");
    scanf("%d", &usuario[0].partida[2].kda[0]);
    printf("¿Cuantas veces te mataron? ");
    scanf("%d", &usuario[0].partida[2].kda[1]);
    printf("Â¿Y cuantas asistencias hiciste? ");
    scanf("%d", &usuario[0].partida[2].kda[2]);

    ratio[0] = (double) (usuario[0].partida[0].kda[0] + usuario[0].partida[0].kda[2]) / usuario[0].partida[0].kda[1];
    ratio[1] = (double) (usuario[0].partida[1].kda[0] + usuario[0].partida[1].kda[2]) / usuario[0].partida[1].kda[1];
    ratio[2] = (double) (usuario[0].partida[2].kda[0] + usuario[0].partida[2].kda[2]) / usuario[0].partida[2].kda[1];
    printf("\n%s, la media de tu KDA ratio de las 3 Ãºltimas partidas ha sido %.2lf.\n", usuario[0].nombre, (ratio[0]+ratio[1]+ratio[2])/PARTIDAS);  
    
    printf("\nJUGADOR 2\n");
    printf("¿Cual es tu nombre de invocador? ");
    scanf("%s", usuario[1].nombre);
    printf("¿Con quÃ© campeon has jugado tu ultima partida? ");
    scanf("%s", usuario[1].partida[0].campeon);
    printf("¿Cuantos asesinatos has hecho? ");
    scanf("%d", &usuario[1].partida[0].kda[0]);
    printf("¿Cuantas veces has muerto? ");
    scanf("%d", &usuario[1].partida[0].kda[1]);
    printf("¿Y cuantas asistencias has hecho? ");
    scanf("%d", &usuario[1].partida[0].kda[2]);

    printf("\n¿Con que campeon has jugado tu penultima partida? ");
    scanf("%s", usuario[1].partida[1].campeon);
    printf("¿Cuantos asesinatos hiciste? ");
    scanf("%d", &usuario[1].partida[1].kda[0]);
    printf("¿Cuantas veces te mataron? ");
    scanf("%d", &usuario[1].partida[1].kda[1]);
    printf("¿Y cuantas asistencias hiciste? ");
    scanf("%d", &usuario[1].partida[1].kda[2]);

    printf("\n¿Con que campeon has jugado tu antepenultima partida? ");
    scanf("%s", usuario[1].partida[2].campeon);
    printf("¿Cuantos asesinatos hiciste? ");
    scanf("%d", &usuario[1].partida[2].kda[0]);
    printf("¿Cuantas veces te mataron? ");
    scanf("%d", &usuario[1].partida[2].kda[1]);
    printf("¿Y cuantas asistencias hiciste? ");
    scanf("%d", &usuario[1].partida[2].kda[2]);

    ratio[0] = (double) (usuario[1].partida[0].kda[0] + usuario[1].partida[0].kda[2]) / usuario[1].partida[0].kda[1];
    ratio[1] = (double) (usuario[1].partida[1].kda[0] + usuario[1].partida[1].kda[2]) / usuario[1].partida[1].kda[1];
    ratio[2] = (double) (usuario[1].partida[2].kda[0] + usuario[1].partida[2].kda[2]) / usuario[1].partida[2].kda[1];
    printf("\n%s, la media de tu KDA ratio de las 3 uiltimas partidas ha sido %.2lf.\n", usuario[1].nombre, (ratio[0]+ratio[1]+ratio[2])/PARTIDAS);  

    return 0;
}
