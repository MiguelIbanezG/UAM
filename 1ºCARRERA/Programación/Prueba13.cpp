#include <stdio.h>
#include <string.h>

int main (){
	
	float nota;
    int calif;
	
	printf("Introduce una calificación numérica entre 0 y 10: ");
	scanf("%f",&nota);
	calif=nota;
	switch(calif){
	    case 0 ... 4:
		    printf("La calificación es Suspenso.");
		    break;
     	case 5 ... 6:
     	    printf("La calificación esta aprobada.");
     	    break;
     	case 7 ... 8:
     	    printf("La calificación es notable.");
     	    break;
     	case 9 ... 10:
     	    printf("La calificación es sobresaliente.");
     	    break;
        default:
        printf("La calificación es incorrecta.");
 }
return 0;
}
