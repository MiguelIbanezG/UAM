# include <stdio.h>

int main () {
	
	int num1;
	char c1, c2;
	
	printf ("Por favor, introduce un n�mero (entre 1 y 5): ");
	scanf ("%d", &num1);
	printf ("Por favor, introduce un car�cter: ");
	scanf ("\n%c", &c1);
	
	if ( c1>=97 && c1<=122){
		if( (num1 + c1) > 122){
			c2 = (c1 + num1 - 26);
		} else{
		c2= c1 + num1;
	}
	}else{
		if (c1>=65 && c1<=90){
		   if((c1 + num1) > 90){
		     c2 = (c1 + num1 - 26);
		}else {
			c2 = c1 + num1;
		}
	}
    else{
	if (c1>=48 && c1<=57){
		if ((c1 + num1) > 57){
			c2 = c1 + num1 - 10;
		}else{
			c2= num1 + c1;
		}	
	}else{
	c1 = c2;
    }
}
}
	printf ("El car�cter %c con c�digo ASCII %d, si se cifra con el n�mero %d se convertir�a en el car�cter %c con el c�digo ASCII %d", c1, c1, num1, c2, c2);
	
}
