#include <stdio.h>

#define TAM 10

int main ()
{
    int i, j;
  
    for (i=1; i<TAM; i++){
        for (j=1; j<TAM; j++){
        printf("%d por %d es igual a %d\n",i,j,i*j);}
    }
    

    return 0;
}

