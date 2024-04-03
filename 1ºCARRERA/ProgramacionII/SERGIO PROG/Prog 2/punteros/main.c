#include <stdio.h>
#include <stdlib.h>

int main (){

int a, *pa , **ppa;
a= 3;
ppa= &pa;
*ppa= &a;
*pa= 4;
printf("%d", a);

}