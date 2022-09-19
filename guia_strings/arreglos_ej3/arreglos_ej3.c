/*
ej3
De forma similar, defina el tipo enumerativo dia_t con los valores

DIA_LUNES
DIA_MARTES
DIA_MIERCOLES
DIA_JUEVES
DIA_VIERNES
DIA_SABADO
DIA_DOMINGO
Defina un arreglo de cadena con los 7 días de la semana, de manera similar al ejercicio anterior. Modularice el programa de forma tal que sea sencillo cambiar el idioma en el que se muestran los días, agregando únicamente archivos .h.
*/
#include <stdio.h>


#if defined(LANG_ENGLISH)
#  include "ENG.h"
#elif defined(LANG_SPANISH)
#  include "ESP.h"
#else
#  include "ESP.h"
#endif

typedef enum{
    DIA_LUNES,
    DIA_MARTES,
    DIA_MIERCOLES,
    DIA_JUEVES,
    DIA_VIERNES,
    DIA_SABADO,
    DIA_DOMINGO
}dia_t;


void printDia(dia_t dia){

const char *day_to_str[] = {STR_LUNES,STR_MARTES,STR_MIERCOLES,STR_JUEVES,STR_VIERNES,STR_SABADO,STR_DOMINGO};

printf("%s",day_to_str[dia]);

}


int main(){
    printDia(DIA_LUNES);
    return 0;
}