# include <stdio.h>

int main () {
	
	int num1;
	char c1, c2;
	
	printf ("Por favor, introduce un número (entre 1 y 5): ");
	scanf ("%d", &num1);
	printf ("Por favor, introduce un carácter: ");
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
	printf ("El carácter %c con código ASCII %d, si se cifra con el número %d se convertiría en el carácter %c con el código ASCII %d", c1, c1, num1, c2, c2);
	
}
