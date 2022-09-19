#include <stdio.h>
#include <string.h>
#include <stdlib.h> 


/*
Escriba una función que recibe dos cadenas y un número e inserta una cadena dentro de la otra en la posición dada por el número.

Por ejemplo:

s1 = “Frase corta”, s2 = ” menos”, n = 5 -> s1 = “Frase menos corta”
s1 = “Frase corta”, s2 = ” menos”, n = 23 -> error.
s1 = “Frase corta”, s2 = ” menos”, n = -8 -> error.
*/

int insertar(char *s1, char *s2, int n){
    int len1 = strlen(s1);
    int len2 = strlen(s2);
    if (n < 0 || n > len1){
        return -1;
    }
    for (int i = len1; i >= n; i--){
        s1[i+len2] = s1[i];
    }
    for (int i = 0; i < len2; i++){
        s1[n+i] = s2[i];
    }
    return 0;
}


void testInsertar(){
    char s1[100] = "hola como va xd";
    char s2[100] = "chau cha cha";
    insertar(s1,s2,4);
    printf("%s",s1);
}

int main(){
    testInsertar();
}