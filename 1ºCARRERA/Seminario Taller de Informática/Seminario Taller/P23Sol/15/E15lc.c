#include <stdio.h> 
#include <stdlib.h> 

int main(int argc, char** argv) {

    int columns = 0, rows = 0, i, j;

    printf("Type a number of columns (greater than 0): ");
    scanf("%i", &columns);
    printf("Type a number of rows (greater than 0): ");
    scanf("%i", &rows);

    int matrix1[columns][rows], matrix2[columns][rows], matrix3[columns][rows];
    printf("Matrix 1:\n");
    for (i = 0; i < rows; i++) {
        for (j = 0; j < columns; j++) {
            printf("Type a value for row %i, column %i: ", i + 1, j + 1);
            scanf("%i", &matrix1[i][j]);
        }
    }
    printf("Matrix 2:\n");
    for (i = 0; i < rows; i++) {
        for (j = 0; j < columns; j++) {
            printf("Type a value for row %i, column %i: ", i + 1, j + 1);
            scanf("%i", &matrix2[i][j]);
        }
    }
    printf("Matrix 3:\n");
    for (i = 0; i < rows; i++) {
        for (j = 0; j < columns; j++) {
            matrix3[i][j]=matrix1[i][j]+matrix2[i][j];
            printf("\t%i", matrix3[i][j]);
        }
        printf("\n");
    }
    return 0;
}
