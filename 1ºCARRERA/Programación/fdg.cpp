#include <stdio.h>

#define NOM 100
#define TAB 2

typedef struct{
    int dia,mes,anyo;
}Fecha;

typedef struct{
	char nombre[NOM];
	Fecha tabla[TAB];
}Citas;

int main(){
	
	Citas cita;
	
	printf("Introduce tu nombre: ");
	gets(cita.nombre);
	
	printf("Introduce un día: ");
	scanf("%d",&cita.tabla[0].dia);
	
	printf("Introduce un mes: ");
	scanf("%d",&cita.tabla[0].mes);
	
	printf("Introduce un anyo: ");
	scanf("%d",&cita.tabla[0].anyo);
	
	printf("Introduce un día: ");
	scanf("%d",&cita.tabla[1].dia);
	
	printf("Introduce un mes: ");
	scanf("%d",&cita.tabla[1].mes);
	
	printf("Introduce un anyo: ");
	scanf("%d",&cita.tabla[1].anyo);
	
	printf("Tienes una cita el %d/%d/%d y otra el %d/%d/%d ",cita.tabla[0].dia,cita.tabla[0].mes,cita.tabla[0].anyo,cita.tabla[1].dia,cita.tabla[1].mes,cita.tabla[1].anyo );
	
	return 0;
}
 


