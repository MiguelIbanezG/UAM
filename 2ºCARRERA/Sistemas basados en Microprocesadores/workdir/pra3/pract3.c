#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_STR 120

int main(void)
{
    int num = 0, selec = 0, pos = 0;
    char str[MAX_STR], substr[MAX_STR];

    while (selec != 1 && selec != 2 && selec != 3)
    {   
        
        printf(" - imparPositivo: 1\n - calculaDigito: 2\n - siguientePrimo: 3\n - encuentraSubcadena: 4\n - calculaSegundoDC: 5\nIntroduce la opcion: ");
        scanf("%d", &selec);
        printf("\n");

        if (selec == 1)
        {

            printf("Introduce tu numero: ");
            scanf("%d", &num);
            printf("\n");
            if (imparPositivo(num) == 1)
            {
                printf("%d es impar y positivo\n\n", num);
            }
            else
            {
                printf("%d no es impar y/o positivo\n\n", num);
            }
            break;
        }
        else if (selec == 2)
        {
            printf("Introduce tu numero: ");
            scanf("%d", &num);
            printf("\n");
            printf("Introduce la posicion del numero: ");
            scanf("%d", &pos);
            printf("\n");

            printf("El numero en esa posicion es %d\n", calculaDigito(num, pos));
            break;
        }
        else if (selec == 3)
        {
            printf("Introduce tu numero: ");
            scanf("%d", &num);
            printf("\n");
            printf("El siguiente numero primo es %d\n", siguientePrimo(num));
            break;
        }
        else if (selec == 4)
        {
            printf("Introduce tu cadena: ");
            scanf("%s", str);



            printf("Introduce tu subcadena: ");
            scanf("%s", substr);


            num = encuentraSubcadena (str, substr);


            if (num == -1)
            {
                printf("No existe tal sub cadena para la cadena %s", str);
            }  
            else
            {
                printf("La subcadena %s se encuentra a partir de la posicion %d en la cadena %s\n", substr, num, str );
            }
            
            break;
        }
        else if (selec == 5)
        {
            printf("Introduce tu cadena: ");
            scanf("%s", str);


            printf("la funcion devuelve el valor %d\n", calculaSegundoDC(str));
            
            break;
        }


    }

    return 0;
}