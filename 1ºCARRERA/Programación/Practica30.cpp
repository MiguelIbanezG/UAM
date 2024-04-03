#include <stdio.h>

#define TAB 3
#define TAl 4



typedef struct {
    int tabla[TAB];
    int suma;
} Suma;

typedef struct {
    Suma tabla1[TAl];
    int division;
} Resto;

int main() {
    Resto num;
    int suma;
	int suma1;
    
    printf("Introduce el primer entero de la primera tabla: ");
    scanf("%d", &num.tabla1[TAl].tabla[0]);
    printf("Introduce el segundo entero de la primera tabla: ");
    scanf("%d", &num.tabla1[TAl].tabla[1]);
    printf("Introduce el tercer entero de la primera tabla: ");
    scanf("%d",&num.tabla1[TAl].tabla[2]);
    
    suma=( num.tabla1[TAl].tabla[0] + num.tabla1[TAl].tabla[1] + num.tabla1[TAl].tabla[2]);
    
    printf("Introduce el primer entero de la segunda tabla: ");
    scanf("%d",&num.tabla1[0].suma);
    printf("Introduce el segundo entero de la segunda tabla:");
    scanf("%d",&num.tabla1[1].suma);
    printf("Introduce el tercer entero de la segunda tabla:");
    scanf("%d",&num.tabla1[2].suma);
    
    suma1= (num.tabla1[0].suma + num.tabla1[1].suma + num.tabla1[2].suma);
    
    num.division= (suma1%suma);
    
    printf("La suma de los elementos de la primera tabla es %d", suma);
    printf("La suma de los elementos de la segunda tabla es %d", suma1);
    printf("El resto de la división de ambas sumas es %d.", num.division);
    
    return 0;
	 }
    
    
    
    
    
    
    
