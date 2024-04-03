#include <stdio.h>
#include <stdlib.h>
 
typedef struct
{
    char   DNI [10];
    int    modelo;
    int    nac;
    int    nfa;
    int    nbl;
    double nota;
} Estudiante;
 
int contar_estudiantes (char * archivo)
{
    Estudiante uno;
    FILE       * f;
    int        numero;
 
    f = fopen (archivo, "r");
 
    /* Si no se ha podido abrir el fichero */
    if (f == NULL)
        return -1; /* La función termina devolviendo -1 */
    
    /* Se leen todos los datos de forma secuencial empezando por el DNI */
    for (numero=0; fscanf (f, "%s", uno.DNI) == 1; numero++)
    {
        fscanf (f, "%d", &uno.modelo);
        fscanf (f, "%d", &uno.nac);
        fscanf (f, "%d", &uno.nfa);
        fscanf (f, "%d", &uno.nbl);
        fscanf (f, "%lf", &uno.nota);
    }
    
    /* Se cierra el fichero antes de salir de la función */
   fclose (f);
 
   return numero;
}
 
int main ()
{
  Estudiante * clase;
  FILE       * f;
  int        i, numero, aprobados;
  double     media;
 
  numero = contar_estudiantes ("notas.txt");
  /* Si la función devuelve -1 es porque no se ha podido abrir el fichero */
  if (numero == -1)
  {
     printf ("Error abriendo el archivo notas.txt\n");
     return 1;
  }
 
  clase = (Estudiante *) malloc (numero * sizeof (Estudiante));
  if (clase == NULL)
  {
     printf ("Error de reserva de memoria\n");
     return 1;
  }
 
  /* Se abre el fichero de notas.txt esta vez desde main */
  f = fopen ("notas.txt", "r");
  if (f == NULL)
  {
    printf ("Error abriendo el archivo notas.txt\n");   
    return 1;
  }
 
  for (i=0, aprobados=0, media=0.0;  i<numero; i++)
  {
    fscanf (f, "%s", clase[i].DNI);
    fscanf (f, "%d", &clase[i].modelo);
    fscanf (f, "%d", &clase[i].nac);
    fscanf (f, "%d", &clase[i].nfa);
    fscanf (f, "%d", &clase[i].nbl);
    fscanf (f, "%lf", &clase[i].nota);
    if (clase[i].nota >=5)
    {
        media += clase[i].nota;
        aprobados++;
    }
  }
 
  printf ("La nota media de los aprobados es = %.3lf\n", media/aprobados);
 
  free (clase);
 
  fclose (f);
 
  return 0;
}
/* La función es genérica y funciona para cualquier nombre de archivo de notas que reciba */
/* Si se quisiera trabajar con un archivo de notas con nombre distinto sólo habría que
    cambiar la llamada a la función en main. Por lo tanto, es una función genérica que se
    podría utilizar en diferentes programas, lo que es uno de los objetivos de las funciones  */
