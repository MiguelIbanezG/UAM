#include <stdio.h>

#define DIM 50

int contar_caracter (char * nombreFichero, char car)
{
  FILE * entrada;
  int numero=0;
  char caracter;

  entrada = fopen (nombreFichero, "r");
  if (entrada == NULL)
    return -1;

  while (fscanf (entrada, "%c", &caracter) == 1)
  {
    if (car==caracter)
      numero++;
  }

  fclose (entrada);

  return numero;
 }

int contar_palabras (char * nombreFichero)
{
  FILE * entrada;
  char palabra [DIM];
  int numero;

  entrada = fopen (nombreFichero, "r");
  if (entrada == NULL)
    return -1;

  /* Observa el ; al final del bucle for. Todo el cuerpo del bucle
     se encuentra dentro de la instrucciÃ³n */
  for (numero=0; fscanf (entrada, "%s", palabra) == 1; numero++);

  fclose (entrada);

  return numero;

}

int main ()
{
  char caracter, nombre [DIM];
  int numero;

  printf ("Introduzca el nombre del archivo de entrada: ");
  scanf ("%s", nombre);

  printf ("Introduce el caracter que quieres buscar: ");
  scanf ("\n%c", &caracter);

  numero = contar_palabras(nombre);
  if (numero == -1)
  {
    printf ("Error abriendo %s\n", nombre);
    return 1;
  }

  printf ("El numero de palabras de %s es %d\n", nombre, numero);

  numero = contar_caracter(nombre, caracter);
  if (numero == -1)
  {
    printf ("Error abriendo %s\n", nombre);
    return 1;
  }

  printf ("El caracter %c aparece %d veces en el fichero %s\n", caracter, numero, nombre);

  return 0;
}
