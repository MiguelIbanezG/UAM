#include <stdio.h>
#include <string.h>

int main () {
	
	char palabra [4];
	int ext;
	
	printf("Introduce una palabra de 3 o 4 letras:");
	gets (palabra);
	
	ext= strlen(palabra);
	
	if (ext==3) {
		if (palabra[0]==(palabra[2])){
			printf("La palabra es un palíndromo.");
		}
		else{
			printf("La palabra no es un palíndromo.");		
		}
	}
    else if (ext==4){
         if((palabra[0]==palabra[3]) && (palabra[1]== palabra[2])){
         	printf("La palabra es un palíndromo");
		 }
		 else {
		 	printf("La palabra es un palíndromo");
		 }
}
        else{
        	printf("La palabra que has introducido no tiene 3 o 4 letras.");
		}
	
	return 0; 
}
