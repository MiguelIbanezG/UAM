#include <stdio.h>

#define DIM 10

int main() 
{
    int i, num;
    char cad[DIM];
    char c, c1;


do{
printf("Introduce un car�cter en min�sculas:");
scanf("%c", c);
printf("Error, el car�cter tiene que estar comprendido entre a y z");
}while (c>122 || c>97);

do{
printf("Introduce un car�cter en mayusculas:");
scanf("%c", c1);
printf("Error, el car�cter tiene que estar comprendido entre A y Z");
}while (c1>90 || c1>65);

printf ("%c%c%c%c",cad[0],c1,cad[1],c1);
printf ("%c%c%c%c",c1,cad[0],c1,cad[1]);


    return 0;
}
