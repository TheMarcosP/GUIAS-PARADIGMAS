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


