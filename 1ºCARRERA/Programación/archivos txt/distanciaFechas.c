#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define YYYY_REFERENCIA 1900
#define TAM 128

typedef struct {
  int yyyy,mm,dd;
} Fecha;

typedef struct {
    Fecha * fechasInicio;
    Fecha * fechasFin;
    int * distancias;
    int numFechas;
}Fechas;

int contarFechas(char * nomFichero)
{
    FILE * fichero;
    int i, dato;
    
    if (nomFichero==NULL)
        return -1;
    
    fichero=fopen(nomFichero, "r");
    if (fichero==NULL)
        return -2;
    
    for(i=0; fscanf(fichero, "%d", &dato)==1; i++);
    
    return i/6;
}

int leerFechas(char * nomFichero, Fechas * fechas)
{
    FILE * fichero;
    int i;
    
    if (nomFichero == NULL || fechas==NULL || fechas->fechasInicio==NULL || fechas->fechasFin==NULL || fechas->distancias==NULL || fechas->numFechas < 1)
        return -1;
    
    fichero=fopen(nomFichero, "r");
    if (fichero==NULL)
        return -2;
    
    for(i=0; i<fechas->numFechas; i++)
    {
        fscanf(fichero, "%d %d %d", &fechas->fechasInicio[i].dd, &fechas->fechasInicio[i].mm, &fechas->fechasInicio[i].yyyy);
        fscanf(fichero, "%d %d %d", &fechas->fechasFin[i].dd, &fechas->fechasFin[i].mm, &fechas->fechasFin[i].yyyy);
    }
    
    fclose(fichero);
    
    return 1;
}


int esBisiesto(int anyo)
{
    if (!(anyo%400))
        return 1;
    
    if (!(anyo%4) && anyo%100)
        return 1;
    
    return 0;
}

int numeroDias(Fecha *f)
{
    const int diasMes[2][12]={{31,28,31,30,31,30,31,31,30,31,30,31}, {31,29,31,30,31,30,31,31,30,31,30,31}};
    const int diasAnho[2]={365,366};
    int i,nDias;
    int bisiesto;
    
    if (f==NULL)
        return -1;
    
    if (f->yyyy>=YYYY_REFERENCIA) 
    {
        /* cuenta los dias de los anhos anteriores */
        for (i=YYYY_REFERENCIA, nDias=0;i<f->yyyy;i++)
            nDias+=diasAnho[esBisiesto(i)];
    
        /* identifica si el anho actual es bisiesto  o no */
        bisiesto=esBisiesto(f->yyyy);

        /* cuenta los dias de los meses anteriores del anho actual */
        for (i=0;i<f->mm-1;i++)
            nDias+=diasMes[bisiesto][i];
    
        /* suma los dias del mes y anho actual*/
        nDias+=f->dd;
    }
    else 
        nDias=-1;
    
    return nDias;
}

int diasEntreFechas(Fecha *f1, Fecha *f2, int *nDias)
{
    int nDias1,nDias2;
    
    if (f1==NULL || f2==NULL || nDias==NULL)
        return 1;
  
    /* calcula los dias de cada una de las fechas */
    if ((nDias1=numeroDias(f1))<0) 
        return 1;
  
    if ((nDias2=numeroDias(f2))<0)
        return 1;
    
    (*nDias)=nDias1-nDias2;
  
    /* salida correcta */
    return 0;
}

int calcularDistancias(Fechas * f)
{
    int i;
    
    if (f->numFechas<1 || f->distancias==NULL || f->fechasFin==NULL || f->fechasInicio==NULL || f->distancias==NULL)
        return 0;
    
    for(i=0; i<f->numFechas; i++)
        if (diasEntreFechas(&f->fechasFin[i],&f->fechasInicio[i],&f->distancias[i]))
            return 0;
    
    return 1;    
}

int escribirFechasYDistancias(char* nombre, Fechas f)
{
    FILE * fichero;
    int i;
    
    if (nombre == NULL || f.fechasInicio==NULL || f.fechasFin==NULL || f.distancias==NULL || f.numFechas<1)
        return -1;
    
    fichero=fopen(nombre, "w");
    if (fichero==NULL)
        return -2;
    
    for(i=0; i<f.numFechas; i++)
    {
        fprintf(fichero, "Entre el %d/%d/%d y el %d/%d/%d hay %d días\n", f.fechasInicio[i].dd, f.fechasInicio[i].mm, f.fechasInicio[i].yyyy, f.fechasFin[i].dd, f.fechasFin[i].mm, f.fechasFin[i].yyyy, f.distancias[i]);
    }
    
    fclose(fichero);
    
    return 1;
}

/*******************************************************/
/*                programa principal                   */
/*******************************************************/

int main()
{
    Fechas fechas;
    char nombre[TAM];
    
    printf("Introduce el nombre del fichero con las fechas: ");
    scanf("%s", nombre);
    
    fechas.numFechas=contarFechas(nombre);
    if (fechas.numFechas<1)
    {
        printf("Error al ejecutar el programa");
        return 1;
    }
    
    fechas.fechasInicio=(Fecha *)malloc(fechas.numFechas*sizeof(Fecha));
    if (fechas.fechasInicio==NULL)
    {
        printf("Error al ejecutar el programa");
        return 1;
    }
    
    fechas.fechasFin=(Fecha *)malloc(fechas.numFechas*sizeof(Fecha));
    if (fechas.fechasFin==NULL)
    {
        free(fechas.fechasInicio);
        printf("Error al ejecutar el programa");
        return 1;
    }
    
    fechas.distancias=(int *)malloc(fechas.numFechas*sizeof(int));
    if (fechas.distancias==NULL)
    {
        free(fechas.fechasInicio);
        free(fechas.fechasFin);
        printf("Error al ejecutar el programa");
        return 1;
    }
    
    if (leerFechas(nombre, &fechas) != 1)
    {
        free(fechas.fechasInicio);
        free(fechas.fechasFin);
        free(fechas.distancias);
        printf("Error al ejecutar el programa");
        return 1;
    }
    
    if (calcularDistancias(&fechas) != 1)
    {
        free(fechas.fechasInicio);
        free(fechas.fechasFin);
        free(fechas.distancias);
        printf("Error al ejecutar el programa");
        return 1;
    }
    
    printf("Introduce el nombre del fichero donde vas a guardar las distancias: ");
    scanf("%s", nombre);
    
    if (escribirFechasYDistancias(nombre, fechas) != 1)
    {
        printf("Error al ejecutar el programa");
        return 1;
    }
    
    printf("Información guardada correctamente en el fichero. Gracias por usar este programa.");
    
    free(fechas.fechasInicio);
    free(fechas.fechasFin);
    free(fechas.distancias);
    
    return 0;
}
