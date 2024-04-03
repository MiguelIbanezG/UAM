
#include <stdio.h>

int main () 
{
    int uno, dos;

    printf("Introduce el primer numero: ");
    scanf("%d", &uno);
    printf("Introduce el segundo numero: ");
    scanf("%d", &dos);

    if ( (uno%2==0 && dos%2==0) ){
        printf("Los numeros %d y %d son pares", uno, dos);
    }
    
    else if ( uno%2==0 || dos%2==0 ){
    	if ( uno%2==0 && dos%2==1 ){
    	printf("el numero %d es impar y el numero %d es par",dos,uno);
	}
    else{
        printf("el numero %d es impar y el numero %d es par",uno,dos);
        }
   }
   else {
   	    printf("Los numneros %d y %d son impares",uno,dos);
   }
    return 0;
}
