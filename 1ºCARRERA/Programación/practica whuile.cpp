#include <stdio.h>

#define DIM 25

int main() {
    int i=0;
    int n,n1;
    
    printf("Escribe un numero de 1 a 99: ");
    scanf("%d", &n);
    
    while(i<DIM) {
    printf("\n");  
    i++;
    }
   printf("Intenta adivinar el numero escrito de 1 a 99: ");
   scanf("%d", &n1);
   
   if (n=n1){
       printf("Has acertado");
   }
       else {
       printf("Prueba otra vez: ");
       scanf("%d", &n1);
   }
   

    return 0;
}
