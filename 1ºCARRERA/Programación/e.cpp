#include <stdio.h>

#define TAB 10000

int main (){
	
	int i, tab[TAB],j;
	
	for(i=0;i<1000;i++){
	
	printf("Introduce el número (%d):",i+1);
	scanf("%d", &tab[i]);
	
	for(j=0;j<i;j++){
		if(tab[j]==tab[i+1]){
		printf("Hasta aquí hemos llegado. Has repetido el número %d", tab[j]);
		break;
	}
	}
	}
	return 0;
}

