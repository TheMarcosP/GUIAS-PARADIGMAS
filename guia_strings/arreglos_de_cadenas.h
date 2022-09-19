#pragma once
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
Defina un arreglo de cadenas que contenga 10 frutas. Defina un tipo enumerativo fruta_t que contenga las 10 frutas mencionadas en el arreglo, en el mismo orden. Luego implemente un programa o función que imprima un elemento del arreglo, dado por una variable del tipo fruta_t.
*/

typedef enum fruta_t{
    manzana,
    banana,
    pera,
    naranja,
    mandarina,
    limon,
    uva,
    durazno,
    sandia,
    melon
}fruta_t;

void printFruta(fruta_t fruta);

void testPrintFruta();

/*
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
typedef enum dia_t{
    DIA_LUNES,
    DIA_MARTES,
    DIA_MIERCOLES,
    DIA_JUEVES,
    DIA_VIERNES,
    DIA_SABADO,
    DIA_DOMINGO
}dia_t;

typedef enum idioma_t{
    ESP,
    ENG,
    ITA
}idioma_t;

#define idioma ENG


void printDia(dia_t dia);

void testPrintDia();

