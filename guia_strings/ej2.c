#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
Escriba un programa que lea una cadena de caracteres e imprima por pantalla, para cada elemento de la cadena: su posición dentro de la cadena, el carácter y su código en representación ASCII. Por ejemplo:


$  ./analizar-cadena
Ingrese la cadena: Fire and blood.
 0    F     70
 1    i    105
 2    r    114
 3    e    101
 4          32
 5    a     97
 6    n    110
 7    d    100
 8          32
 9    b     98
10    l    108
11    o    111
12    o    111
13    d    100
14    .     46
15           0
*/

int main(){
    char a[] = "B";
    for(int i = 0; a[i] != '\0' ; i++){
        printf("%d ",a[i]);
    }
    printf("\n");
}