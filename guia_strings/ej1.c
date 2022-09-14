#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
Escriba un programa que lea una cadena de caracteres ingresada por el flujo de entrada estándar y la imprima por pantalla. Almacena la cadena en un arreglo de no más de 100 caracteres. Utilice los siguientes métodos:

Itere hasta leer el carácter '\n' inclusive,
Lea utilizando fgets().
*/

int main(){
    char cadena[100];
    printf("Ingrese una cadena de caracteres: ");
    fgets(cadena, 100, stdin);
    printf("La cadena ingresada es: %s", cadena);
}