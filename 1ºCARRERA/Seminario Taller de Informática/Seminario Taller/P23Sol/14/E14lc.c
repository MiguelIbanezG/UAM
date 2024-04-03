#include <stdio.h> 
#include <stdlib.h> 

int main(int argc, char** argv) {

    int i, j, array[4][4], counter = 0;

    for (i = 0; i < 4; i++) {
        for (j = 0; j < 4; j++) {
            do {
                printf("Type a value for column %i, row %i: ", i + 1, j + 1);
                scanf("%i", &array[i][j]);
            } while (array[i][j] < 0 || array[i][j] > 9);

        }

    }
    for (i = 0; i < 4; i++) {
        for (j = 0; j < 4; j++) {
            if (array[i][j] == 0) {
                counter++;
            }

        }

    }

    printf("The total count of zeros was %i.\n", counter);
    
    return 0;
}
