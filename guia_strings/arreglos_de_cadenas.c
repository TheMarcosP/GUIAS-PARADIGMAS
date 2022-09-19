#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "arreglos_de_cadenas.h"
/*
Defina un arreglo de cadenas que contenga 10 frutas. Defina un tipo enumerativo fruta_t que contenga las 10 frutas mencionadas en el arreglo, en el mismo orden. Luego implemente un programa o función que imprima un elemento del arreglo, dado por una variable del tipo fruta_t.
*/

char frutas[10][20] = {"manzana","banana","pera","naranja","mandarina","limon","uva","durazno","sandia","melon"};

void printFruta(fruta_t fruta){
    printf("%s",frutas[fruta]);
}

void testPrintFruta(){
    printFruta(manzana);
}

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


void printDia(dia_t dia){

    char dias[3][7][20] = {
        [ESP] = {"lunes","martes","miercoles","jueves","viernes","sabado","domingo"},
        [ENG] = {"monday","tuesday","wednesday","thursday","friday","saturday","sunday"},
        [ITA] = {"lunedi","martedi","mercoledi","giovedi","venerdi","sabato","domenica"}
    };

    printf("%s",dias[idioma][dia]);
}

void testPrintDia(){
    printDia(DIA_JUEVES);
}


/*
La clasificación espectral de estrellas (cuerpos celestes) permite agruparlas en función de su temperatura, como se muestra en la tabla siguiente

Clase	Temperatura	Color
O	28000 - 50000 K	Azul
B	9600 - 28000 K	Blanco azulado
A	7100 - 9600 K	Blanco
F	5700 - 7100 K	Blanco amarillento
G	4600 - 5700 K	Amarillo
K	3200 - 4600 K	Naranja
M	1700 - 3200 K	Rojo
Defina el tipo enumerativo espectral_t con los símbolos correspondientes a las clases espectrales.
Declare un arreglo de cadenas con los colores de cada tipo de estrella.
Escriba un programa que le pida al usuario la temperatura de un cuerpo celeste y almacene la clase del mismo en una variable del tipo espectral_t.
Imprima el color de la estrella.
*/

typedef enum espectral_t{
    O,
    B,
    A,
    F,
    G,
    K,
    M
}espectral_t;

void printColor(espectral_t espectral){
    char colores[7][20] = {"Azul","Blanco azulado","Blanco","Blanco amarillento","Amarillo","Naranja","Rojo"};
    printf("%s",colores[espectral]);
}

void testPrintColor(){
    printColor(O);
}

// assign temp to spectral
espectral_t tempToSpectral(int temp){
    if(temp >= 28000 && temp <= 50000){
        return O;
    }else if(temp >= 9600 && temp <= 28000){
        return B;
    }else if(temp >= 7100 && temp <= 9600){
        return A;
    }else if(temp >= 5700 && temp <= 7100){
        return F;
    }else if(temp >= 4600 && temp <= 5700){
        return G;
    }else if(temp >= 3200 && temp <= 4600){
        return K;
    }else if(temp >= 1700 && temp <= 3200){
        return M;
    }else{
        return -1;
    }
}

void testTempToSpectral(){

    // get valid input
    //fgets
    char temp[20];
    fgets(temp,20,stdin);

    //strtol 
    char *endptr = NULL;
    int tempInt = strtol(temp,&endptr,10);
    if(*endptr != '\n' || *endptr == temp[0] || tempInt < 1700 || tempInt > 50000){
        printf("Error");
        return;
    }

    // assign temp to spectral
    espectral_t estrella = tempToSpectral(tempInt);
    printColor(estrella);
}


/*
Escriba una función que reciba y ordene un arreglo de cadenas de caracteres. Fuera de la función, imprima el vector ordenado.
*/

int OrdenarArreglo(char *arreglo[], int n){
    int i,j;
    char *aux;
    for(i=0;i<n;i++){
        for(j=i+1;j<n;j++){
            if(strcmp(arreglo[i],arreglo[j]) > 0){
                aux = arreglo[i];
                arreglo[i] = arreglo[j];
                arreglo[j] = aux;
            }
        }
    }
    return 0;
}

void testOrdenarArreglo(){
    char *arreglo[] = {"hola","chau","adios","hasta luego"};
    OrdenarArreglo(arreglo,4);
    for(int i = 0; i < 4; i++){
        printf("'%s' ",arreglo[i]);
    }
}

int main(){
    //testTempToSpectral();
    testOrdenarArreglo();
}
