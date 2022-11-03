#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct empresa {
    char *nombre;
    char *cuit;
    char *direccion;
} empresa_t;

typedef struct empleado {
    char *nombre;
    char *apellido;
    empresa_t *empresa;
    char *cargo;
    double salario;
} empleado_t;

typedef enum{
    ST_OK,
    ST_ERR_NULL_PTR,
    ST_ERR_ENOMEM
}   ;


typedef enum{
    ST_OK,
    ST_NOT_OK,
    ST_ERR_NULL_PTR,
    ST_ERR_ENOMEM
}status_t;

status_t empresa_cargar(empresa_t *empresa, const char *razon_social, const char *cuit, const char *direccion)
{
    if ((NULL == empresa) || (NULL == razon_social) || (NULL == cuit) || (NULL == direccion)) {
        return ST_ERR_NULL_PTR;
    }

    empresa->nombre = strdup(razon_social);
    if (NULL == empresa->nombre) {
        return ST_ERR_ENOMEM;
    }

    empresa->cuit = strdup(cuit);
    if (NULL == empresa->cuit) {
        free(empresa->nombre);
        return ST_ERR_ENOMEM;
    }

    empresa->direccion = strdup(direccion);
    if (NULL == empresa->direccion) {
        free(empresa->cuit);
        free(empresa->nombre);
        return ST_ERR_ENOMEM;
    }

    return ST_OK;
}


status_t cargar_empleado(empleado_t *empleado, const char *nombre, const char *apellido, empresa_t *empresa, const char *cargo, double salario)
{
    if ((NULL == empleado) || (NULL == nombre) || (NULL == apellido) || (NULL == empresa) || (NULL == cargo)) {
        return ST_ERR_NULL_PTR;
    }

    empleado->nombre = strdup(nombre);
    if (NULL == empleado->nombre) {
        return ST_ERR_ENOMEM;
    }

    empleado->apellido = strdup(apellido);
    if (NULL == empleado->apellido) {
        free(empleado->nombre);
        return ST_ERR_ENOMEM;
    }

    empleado->empresa = empresa;
    empleado->cargo = strdup(cargo);
    if (NULL == empleado->cargo) {
        free(empleado->apellido);
        free(empleado->nombre);
        return ST_ERR_ENOMEM;
    }

    empleado->salario = salario;

    return ST_OK;
}

int main(){
    empresa_t empresa;
    status_t st;
    st = empresa_cargar(&empresa, "Empresa 1", "123456789", "Direccion 1");
    (ST_OK != st) ? fprintf(stderr, "Error al cargar la empresa: %d", st) : printf("Empresa cargada correctamente\n");
    return 0;
}