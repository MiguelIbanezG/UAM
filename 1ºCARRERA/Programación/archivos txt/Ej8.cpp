
#include <stdio.h>
#include "agenda.h"

int main ()
{

  Agenda ag;
  Contacto con;
  int codigo;
  char nombre[TAM];
  
  printf("Introduzca el nombre del archivo con los datos de la agenda: ");
  scanf("%s", ag.archivo);

  codigo = cargar_agenda (&ag);
  if (codigo == 1)
  {
    printf ("Error de apertura\n");
    return 2;
  }
  else if (codigo == 2)
  {

    printf ("Error de lectura\n");
    return 2;
  }

  printf ("Introduzca un nuevo usuario\n");
  printf ("Introduzca nombre: ");
  scanf ("%s", con.nombre);

  printf ("Introduzca apellido: ");
  scanf ("%s", con.apellido);

  printf ("Introduzca telefono: ");
  scanf ("%d", &con.telefono);

  agregarContacto(&ag, con);

  printf ("Introduzca un nombre para buscar en la agenda: ");
  scanf ("%s", nombre);

  codigo = buscar (ag, nombre);

  if (codigo == 0)
    printf ("%s no se encuentra en la agenda\n", nombre);
  else
    printf ("El telefono de %s es %d\n", nombre, codigo);

  return 0;

}

 



