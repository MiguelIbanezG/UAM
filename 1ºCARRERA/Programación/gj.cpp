#include <stdio.h>

#define DIM 10


typedef struct {
	int dia, mes, anyo;
}datos;
int main() 
{
   datos fecha;

   printf("Introduzca dia de nacimiento:");
   scanf("\n%d", &fecha.dia); 
   
   printf("ntroduzca mes de nacimiento:");
   scanf("\n%d", &fecha.mes); 
   
   printf("Introduzca anyo de nacimiento:");
   scanf("\n%d", &fecha.anyo); 
  

 if((fecha.anyo%4==0) && (fecha.anyo%100!=0) && (fecha.anyo>=1900)){
 	printf("La fecha %d/%d/%d no es valida", fecha.dia, fecha.mes, fecha.anyo);
 }
 else if((fecha.anyo%100==0) && (fecha.anyo%400==0) && (fecha.anyo>=1900)){
    printf("La fecha %d/%d/%d es valida", fecha.dia, fecha.mes, fecha.anyo);
 }
  else {
  	printf("La fecha %d/%d/%d no es valida", fecha.dia, fecha.mes, fecha.anyo);
  }
    return 0;
}
