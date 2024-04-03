typedef struct
{
    Cola *colaConexiones;
    char *nombre;
} BaseDatos;

typedef struct
{
    BaseDatos *basesDatos;
    int numBasesDatos;
} GestorBasesDatos;

typedef struct
{
    char *nombre;
} Conexion;

status gestorBaseDatos_solicitarConexion(GestorBasesDatos *gestor, Conexion *conexion)
{
    if (gestor == NULL || conexion == NULL)
    {
        return ERROR_ARGUMENTOS;
    }

    if (strcmp(BaseDatos_getname(gestor->basesDatos), conexion_getNombreBaseDatos(conexion)) != 0 || BaseDatos_getname(gestor->basesDatos) == NULL)
    {
        return ERROR_INTERNO;
    }

    if (cola_llena(BaseDatos_getcola(gestor->basesDatos)) == TRUE)
    {
        return ERROR_SOBRECARGA;
    }

    if (cola_insertar(BaseDatos_getcola(gestor->basesDatos), elemento_crear(conexion)) == ERROR)
    {
        return ERROR_INTERNO;
    }

    return OK;
}

