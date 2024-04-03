#include <stdio.h>

/* Texto para los test */
char *mns[2] = {"NOT PASSED", "PASSED"};

/*
    Devuelve 1 si “num” es impar y positivo, cero en caso contrario (num es un número entero de
    16 bits con signo). No está permitido usar las instrucciones IDIV ni DIV.
 */
int imparPositivo(int num);

/*
    Devuelve el dígito que se encuentra en la posición “pos” del número “num” (num y pos son
    números enteros de 16 bits con signo). Por ejemplo, si num=65432 y pos=1, la función debe
    devolver el valor 3. Las posiciones se cuentan empezando por cero por la derecha
 */
int calculaDigito(unsigned int num, unsigned int pos);

/*
    Devuelve el primer número primo que se encuentre a continuación de n (número entero de 16
    bits sin signo). La función debe proporcionar resultados correctos para valores de n entre 2 y
    65520. Por ejemplo, si n=7, la función debe devolver el valor 11.
 */
unsigned int siguientePrimo(unsigned int n);

/*--------------------------------------------- MODULO B -------------------------------------------*/

/*
    Devuelve el índice a partir del cual se encuentra contenida la subcadena “substr” en la cadena
    “str”. Si la subcadena no se encuentra dentro de la cadena, devuelve el valor -1. Por ejemplo, si
    str=”abcdefghijklmn” y substr=”defghijk”, la función debe devolver el valor 3.
 */
int encuentraSubcadena(char *str, char *substr);

/*
    Devuelve como valor de retorno el segundo dígito de control de una cuenta bancaria
    correspondiente al número de cuenta de 10 dígitos dado como cadena de caracteres ASCII
    (por ejemplo: “0438853602”). Para realizar el cálculo, debemos multiplicar cada dígito de la
    cuenta por 1, 2, 4, 8, 5, 10, 9, 7, 3, 6 respectivamente, empezando por la izquierda. Sumando
    las 10 cantidades obtenidas, y efectuando el módulo 11 de la suma, el resultado a devolver por
    la función será igual a 11 menos el módulo 11 de la suma. Con una excepción, si el resultado
    final obtenido es 10, debe retornar el valor 1. Por ejemplo, para numCuenta=“0438853602”, la
    función debe retornar el valor 9 (como número entero de 16 bits sin signo).
 */
unsigned int calculaSegundoDC(char *numCuenta);

void test_imparPositivo();
void test_calculaDigito();
void test_siguientePrimo();
void test_encuentraSubcadena();
void test_calculaSegundoDC();

typedef void (*test)();

test function_test[] = {test_imparPositivo,
                        test_calculaDigito,
                        test_siguientePrimo,
                        test_encuentraSubcadena,
                        test_calculaSegundoDC};

int main()
{
    int modulo;
    int opcion;

    puts("Introduce la opcion que quieres");
    puts("Modulo 1/2 (marca 3 para todos) ? :");
    scanf("%d", &modulo);

    if (modulo != 3)
    {
        puts("Numero de funcion ? \n (1-3 modulo 1 y 1-2 modulo 2):");
        scanf("%d", &opcion);
        printf("Recibido: %d %d\n", modulo, opcion);
        if (modulo == 1){
            function_test[opcion]();
        }else if (opcion <= 2){
            function_test[opcion+2]();
        }
    }else{
        int i = 0;
        while ( i < 5)
        {
            function_test[i]();
            i++;
        }
        
    }

    return 0;
}

void test_imparPositivo()
{
    int resultado;
    int i = 1;
    printf("\n\tTEST imparPositivo\n");

    // Test 1
    resultado = imparPositivo(2);
    printf("Test %i: %s\n", i++, mns[resultado == 0]);

    // Test 2
    resultado = imparPositivo(-2);
    printf("Test %i: %s\n", i++, mns[resultado == 0]);

    // Test 3
    resultado = imparPositivo(1);
    printf("Test %i: %s\n", i++, mns[resultado == 1]);

    // Test 4
    resultado = imparPositivo(-1);
    printf("Test %i: %s\n", i++, mns[resultado == 0]);

    // Test 5
    resultado = imparPositivo(89901);
    printf("Test %i: %s\n", i++, mns[resultado == 1]);

    // Test 5
    resultado = imparPositivo(-89901);
    printf("Test %i: %s\n", i++, mns[resultado == 0]);

    // Test 6
    resultado = imparPositivo(89902);
    printf("Test %i: %s\n", i++, mns[resultado == 0]);

    return;
}

void test_calculaDigito()
{
    int resultado;
    int i = 1;
    printf("\n\tTEST calculaDigito\n");

    // Test 1
    resultado = calculaDigito(6435, 0);
    printf("Test %i: %s\n", i++, mns[resultado == 5]);

    // Test 2
    resultado = calculaDigito(6435, 1);
    printf("Test %i: %s\n", i++, mns[resultado == 3]);

    // Test 3
    resultado = calculaDigito(6435, 2);
    printf("Test %i: %s\n", i++, mns[resultado == 4]);

    // Test 4
    resultado = calculaDigito(6435, 3);
    printf("Test %i: %s\n", i++, mns[resultado == 6]);
    return;
}

void test_siguientePrimo()
{
    unsigned int resultado;
    int i = 1;
    printf("\n\tTEST siguientePrimo\n");

    // Test 1
    resultado = siguientePrimo(7);
    printf("Test %i: %s\n", i++, mns[resultado == 11]);

    // Test 2
    resultado = siguientePrimo(11);
    printf("Test %i: %s\n", i++, mns[resultado == 13]);

    // Test 3
    resultado = siguientePrimo(2);
    printf("Test %i: %s\n", i++, mns[resultado == 3]);

    return;
}

void test_encuentraSubcadena()
{
    int resultado;
    int i = 1;
    printf("\n\tTEST encuentraSubcadena\n");

    // Test 1
    resultado = encuentraSubcadena("abcdefghijklmn", "defghijk");
    printf("Test %i: %s\n", i++, mns[resultado == 3]);

    // Test 2
    resultado = encuentraSubcadena("abcdefghijklmn", "XZC");
    printf("Test %i: %s\n", i++, mns[resultado == -1]);

    // Test 3
    resultado = encuentraSubcadena("a", "XZC");
    printf("Test %i: %s\n", i++, mns[resultado == -1]);

    // Test 4
    resultado = encuentraSubcadena("a", "aZC");
    printf("Test %i: %s\n", i++, mns[resultado == -1]);

    // Test 5
    resultado = encuentraSubcadena("a", "");
    printf("Test %i: %s\n", i++, mns[resultado == -1]);

    // Test 6
    resultado = encuentraSubcadena("", "xyz");
    printf("Test %i: %s\n", i++, mns[resultado == -1]);

    // Test 7
    resultado = encuentraSubcadena("abcdefghijklmn", "abc");
    printf("Test %i: %s\n", i++, mns[resultado == 0]);
}

void test_calculaSegundoDC()
{
    unsigned int resultado;
    int i = 1;
    printf("\n\tTEST calculaSegundoDC\n");

    // Test 1
    resultado = calculaSegundoDC("0438853602");
    printf("Test %i: %s\n", i++, mns[resultado == 9]);

    // Test 2 --  Caso especial de salida 10 -> 1
    resultado = calculaSegundoDC("1000000000");
    printf("Test %i: %s\n", i++, mns[resultado == 1]);
}