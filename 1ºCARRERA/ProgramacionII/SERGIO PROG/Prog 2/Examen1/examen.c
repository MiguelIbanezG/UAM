// 1.
// a) Empresa, Clientes, Vehiculo, Poliza. 4
#include <stdio.h>
#include <string.h>
#define MAX_CLIENTES 1000000
#define MAX_NOMBRE 80
#define MAX_VEHICULO 10
#define MAX_DIRECCION 100
#define MAX_VEHICULOS 2000000
#define MAX_POLIZA 1
#define MAX_MATRCULA 10


typedef struct _Clientes{
    Cliente c[MAX_CLIENTES];
    int numClientes;
    int numVehicAseg[MAX_VEHICULOS];
}Clientes;

typedef struct _Cliente{
    Vehiculo *v[MAX_VEHICULO];
    char nombre[MAX_NOMBRE];
    Poliza *p[MAX_POLIZA];
    long int ID;
}Cliente;

typedef struct _Vehiculo{
    char Matricula[MAX_MATRCULA];
    long int id;
}Vehiculo;

typedef struct _Poliza{
    long int ID;
    char dirección[MAX_DIRECCION];
}Poliza;

Status altaCliente(Clientes *pcs, const char *nombre)
{
    Cliente *e;
    int i;
    

    if (pcs == NULL || nombre == NULL || strlen (nombre) > 80 )
    {
        return ERROR;
    }

    for (i = 0; i < MAX_CLIENTES; i++)
    {
        if (strcmp (get_namecliente (pcs->c[i]), nombre) == 0)
        {
            
            return ERROR; 
        }
    }
    
    e = init_cliente ();

    (pcs->numClientes)++;
    strcpy (e->nombre, nombre);

    return OK;
}

imprimeVehiculosCliente (const Clientes *pa, const char *nombre, FILE *f)
{
    int i, j;

    if (pa == NULL || nombre == NULL || strlen (nombre) > 80 || f == NULL)
    {
        return ERROR;
    }



    for (i = 0; i < MAX_CLIENTES; i++)
    {
        if (strcmp (get_namecliente (pa->c[i]), nombre) == 0)
        {
            
            break;
        }
    }

    for (j = 0; j < MAX_VEHICULO; j++)
    {
        
        if (get_vehicleID (pa->c[i], j) != NO_ID)
        {
            fprintf (f, "%d %s", get_vehicleID (pa->c[i], j), get_vehicleMatricula (pa->c[i], j));
        }

    }
    




}