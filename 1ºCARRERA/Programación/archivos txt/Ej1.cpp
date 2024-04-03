#include <stdio.h>
 
#define TAM 10

typedef struct
{
    char   DNI [TAM];
    int    modelo;
    int    nac;
    int    nfa;
    int    nbl;
    double nota;
} Estudiante;
 
int main ()
{
    Estudiante uno;
    FILE       * f;
    int        numero1, numero2;
    double     media1, media2;
 
    f = fopen ("notas.txt", "r");
    if (f == NULL)
    {
        printf ("Error abriendo el archivo\n");   
        return 1;
    }
 
    for (numero1=0, numero2=0, media1=0.0, media2=0.0; fscanf (f, "%s", uno.DNI) == 1; )
    {
        /* Se han de leer todos los datos en orden secuecial aunque luego sólo se vayan a utilizar el modelo y la nota */
        fscanf (f, "%d", &uno.modelo);
        fscanf (f, "%d", &uno.nac);
        fscanf (f, "%d", &uno.nfa);
        fscanf (f, "%d", &uno.nbl);
        fscanf (f, "%lf", &uno.nota);
        
        if (uno.modelo == 1)
        {
            media1 += uno.nota;
            numero1++;
        }
        else
        {
            media2 += uno.nota;
            numero2++;
        }
    }
 
    printf ("La nota media del modelo 1 es = %.3lf\n", media1/numero1);
    printf ("La nota media del modelo 2 es = %.3lf\n", media2/numero2);
 
    fclose (f);
 
    return 0;
 }
