#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
Escriba un programa que lea una cadena de caracteres e imprima su longitud. Considere los siguientes casos de ejecución:

Usos con entrada correctamente formada

$ ./g06e08
Fire and blood.
16
$ ./g06e08
~!@#$%*()_+|]{:,<z
19
$ ./g06e08

1
$ ./g06e08
0
$ ./g06e08
Fire and blood.15
*/
int main(){
    char str[100];
    if(fgets(str,100,stdin) == NULL){
        printf("invalid input");
    }
    printf("%ld",strlen(str));
}