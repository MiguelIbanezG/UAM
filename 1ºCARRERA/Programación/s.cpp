#include <stdio.h>

#define FIL 3
#define COL 3

int main() {
    int i, j,suma, suma1,suma2, matriz[FIL][COL]={{1,4,2},{3,5,9}, {2,3,4}};

    for (i=0; i<FIL; i++) {
        for (j=0; j<COL; j++)
            printf("%d ", matriz[i][j]);
        printf("\n");
    }
    suma= matriz[0][0]+matriz[1][0]+matriz[2][0];
    suma1= matriz[0][1]+matriz[1][1]+matriz[2][1];
    suma2= matriz[0][2]+matriz[1][2]+matriz[2][2];
    
    printf("La suma de la matriz 3x3 es (%d,%d,%d)", suma, suma1,suma2);

    return 0;
}
