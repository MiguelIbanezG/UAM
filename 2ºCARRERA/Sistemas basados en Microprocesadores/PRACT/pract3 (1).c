#include <stdio.h>
#include <stdlib.h>


int main(void){

    int num;

    printf("Introduce un numero");
    scanf("%d", &num);

    if (imparPositivo (num) == 1 ){
        printf("el numero %d es impar y positivo", num);

    }
    else{
        printf("el numero %d no es impar o no es positivo", num);
    }
    


}