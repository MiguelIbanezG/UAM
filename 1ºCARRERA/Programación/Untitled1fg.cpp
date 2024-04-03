#include <stdio.h>

#define MAX_STR 128

typedef struct {
    int divisor;
    int dividendo;
    
} Calculo;

int main () {
	Calculo operacion;
	
    printf("Escriba el divisor: ");
    scanf("%d", &operacion.divisor);
    
    printf("Escriba el dividendo: ");
    scanf("%d", &operacion.dividendo);
    
   

        printf("El cociente es %d y el resto es %d", operacion.divisor/operacion.dividendo, operacion.divisor%operacion.dividendo);   
    return 0;
}
