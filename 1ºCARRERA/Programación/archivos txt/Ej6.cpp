#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM 128

typedef struct
{
    char asignatura[TAM];
    float nota;
}Calificacion;

typedef struct
{
    int num_calificaciones;
    Calificacion *notas;
}Calificaciones;

/* Función que lee de un fichero y devuelve las calificaciones leídas
   La función también podría devolver Calificaciones (sin puntero),
   sin embargo devuelve un puntero porque así se utiliza menos memoria */ 
Calificaciones * leerCalificaciones(char * nombre_fichero)
{
    FILE *f;
    Calificaciones *cal;
    char nombre[TAM], asignatura[TAM];
    float nota;
    int i;
    
    if (nombre_fichero==NULL)
        return NULL;
    
    /* Reserva memoria para un sola variable de tipo Calificaciones */
    cal=(Calificaciones *)malloc(1*sizeof(Calificaciones));
    if (cal==NULL)
        return NULL;

    /* Abre el fichero */
	 f=fopen(nombre_fichero, "r");
    if (f==NULL)
        return NULL;
    
    /* Lee los datos del fichero para saber cuántas calificaciones contiene 
       Fíjate en varios aspectos importantes:
       La lectura se hace en variables locales que se han definido y que luego no se utilizarán, pero es necesario guardar los datos que se leen en algún sitio.
       Los datos no se pueden guardar todavía en cal->notas pues sigue siendo un puntero en el que todavía no se ha reservado memoria.
       El for termina con un ; Esto significa que no tiene un cuerpo de instrucciones, todo está contenido en el propio for */
    for(cal->num_calificaciones=0; fscanf(f, "%s %s %f", nombre, asignatura, &nota)==3; cal->num_calificaciones++);
    
    /* Una vez que se sabe cuántas calificaciones hay, puede reservar memoria para las notas */
    cal->notas=(Calificacion *)malloc(cal->num_calificaciones*sizeof(Calificacion));
    if (cal->notas==NULL)
        return NULL;

    /* Cierra el fichero para poder volver a abrirlo y volver a leerlo desde el principio */
    fclose(f);
    
    /* Abre nuevamente el fichero */
    f=fopen(nombre_fichero, "r");
    if (f==NULL)
        return NULL;
    
    /* Lee los datos y esta vez los guarda en cal->notas 
       Fíjate en que el nombre no queremos guardarlo, pero es necesario leerlo igualmente así que lo hacemos en una variable local que luego no utilizaremos 
       Fíjate también en que como ya sabemos cuántos datos tiene el fichero podemos utilizar una condición diferente en el for a la de la lectura anterior (aunque también podríamos haber utilizado la misma condición del for anterior) */
    for(i=0; i<cal->num_calificaciones; i++)
        fscanf(f, "%s %s %f", nombre, cal->notas[i].asignatura, &cal->notas[i].nota);
    
    /* Cerramos el fichero */
    fclose(f);
    
    /* Devolvemos el puntero a la estructura */
    return cal;
}


int main()
{
    Calificaciones * cali;
    char nombre[TAM], asignatura[TAM];
    int i, num_coincidencias;
    float media;
    
    printf("Introduce el nombre del fichero con las notas: ");
    scanf("%s", nombre);
    
    /* Llamamos a la función para que cali tenga la información de las asignaturas y notas del fichero */
    cali=leerCalificaciones(nombre);
    
    if (cali==NULL)
    {
        printf("Error ejecutando el programa");
        return 1;
    }
    
    printf("Introduce la asignatura que quieres buscar: ");
    scanf("%s", asignatura);
    
    /* Buscamos las coincidencias y obtenemos la nota total y número de coincidencias */
    for(i=media=num_coincidencias=0; i<cali->num_calificaciones; i++)
    {
        if(strcmp(cali->notas[i].asignatura, asignatura) == 0)
        {
            media+=cali->notas[i].nota;
            num_coincidencias++;
        }
    }
    
    /* Hacemos esta comprobación no solo para mostrar un mensaje diferente, sino para evitar dividir por cero, que produciría un error de ejecución */
    if (num_coincidencias==0)
        printf("No se ha encontrado ninguna nota para la asignatura %s", asignatura);
    else
        printf("La nota media de la asignatura %s es %.2f", asignatura, media/num_coincidencias);
      
    /* Liberamos la memoria: Ojo, el orden de liberación es importante en este caso */
    free(cali->notas);
    free(cali);

    return 0;
    
}
