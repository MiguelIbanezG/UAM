#include <stdio.h>

#define DIM 9

int main() {
    int i,a,num;
    
    printf("Introduce un numero (entre 1 y 9): ");
    scanf("%d", &num);
    
    while (num>9 && num<1){
    	printf("El numero debe estar entre 1 y 9): ");
    scanf("%d", &num);
}
    for (i=0; i<9; i++); {
    	a= num*i;
        printf("%d ", a);
    }


    return 0;
}
