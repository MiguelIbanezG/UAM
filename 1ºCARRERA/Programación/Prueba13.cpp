#include <stdio.h>
#include <string.h>

int main (){
	
	float nota;
    int calif;
	
	printf("Introduce una calificaci�n num�rica entre 0 y 10: ");
	scanf("%f",&nota);
	calif=nota;
	switch(calif){
	    case 0 ... 4:
		    printf("La calificaci�n es Suspenso.");
		    break;
     	case 5 ... 6:
     	    printf("La calificaci�n esta aprobada.");
     	    break;
     	case 7 ... 8:
     	    printf("La calificaci�n es notable.");
     	    break;
     	case 9 ... 10:
     	    printf("La calificaci�n es sobresaliente.");
     	    break;
        default:
        printf("La calificaci�n es incorrecta.");
 }
return 0;
}
