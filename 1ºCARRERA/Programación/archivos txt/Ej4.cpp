#include <stdio.h>
 

int main ()
{

  FILE   *entrada, *salida;
  char   DNI [10];
  double nota;
  int    modelo, nac, nfa, nbl; 

  /* Se abre el primer fichero en modo lectura */
  entrada = fopen ("notas.txt", "r");
  if (entrada == NULL)
  {
    printf ("Error abriendo el archivo notas.txt\n");
    return 1;
  }

  /* Se abre el segundo fichero en modo escritura (si existe se vacía y si no existe se crea) */
  salida = fopen ("listado.txt", "w");
  if (salida == NULL)
  {
    printf ("Error abriendo el archivo listado.txt\n");
    fclose(entrada);
    return 1;
  }

  /* Se lee de golpe cada línea del fichero de entrada */
  while (fscanf(entrada, "%s %d %d %d %d %lf", DNI, &modelo, &nac, &nfa, &nbl, &nota) == 6)
  {
      if (nota < 5)
          fprintf(salida, "%s %.3lf suspenso\n", DNI, nota);
      else if (nota < 7)
          fprintf(salida, "%s %.3lf aprobado\n", DNI, nota);
      else if (nota < 9)
          fprintf(salida, "%s %.3lf notable\n", DNI, nota);
      else if (nota < 10)
          fprintf(salida, "%s %.3lf sobresaliente\n", DNI, nota);
      else
          fprintf(salida, "%s %.3lf matrícula\n", DNI, nota);
  }

  fclose (entrada);
  fclose (salida);

  return 0;

}
