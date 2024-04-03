#include <stdio.h>
#include <stdlib.h>

#define MINI 1
#define MAXIM 12

void ParesImpares(int *tabla, int tamano, int *pares, int *Npares, int *Nimpares, int *impares){
	
	int i;
	
	for(i=0,*Npares=0;i<tamano ;i++){
		if(tabla[i]%2==0){
		pares[i]=tabla[i];
		Npares++;
		}
	}
	
	for(i=0,*Nimpares=0;i<tamano; i++){
		if(tabla[i]%2!=0){
		impares[i]=tabla[i];
		Nimpares++;
		}
	}
	
}


int main(){
	
	int *pares,*impares,tamano,tabP[MAXIM], tabIM[MAXIM], tab[MAXIM];
	int *b,i;
	int Npares, Nimpares;
	
	b=tab;
	pares=tabP;
	impares=tabIM;
	
	do{
	printf("¿Cuantos numeros quieres leer (maximo 12): ");
	scanf("%d", &tamano);
	if(tamano<MINI || tamano>MAXIM){
		printf("Error, has de introducir un número entre 1 y 12\n");
	}
	}while(tamano<MINI || tamano>MAXIM);
	
	
	for(i=0;i<tamano;i++){
		printf("Introduce el número %d de %d: ", i+1, tamano);
		scanf("%d", &b[i]);
	}
		
		ParesImpares(b, tamano, &pares[0], &Npares, &Nimpares, &impares[0]);
		
		if(Npares==0){
			printf("No hay numeros pares\n");
		}
		else{
			printf("Los numeros pares son: ");
			for(i=0;i<Npares;i++){
				printf("%d", pares[i]);
			}
		}
		
		if(Nimpares==0){
			printf("No hay numeros impares\n");
		}
		else{
			printf("Los numeros impares son: ");
			for(i=0;i<Nimpares;i++){
				printf("%d", impares[i]);
			}
		}
		
		return 0;
	
}
