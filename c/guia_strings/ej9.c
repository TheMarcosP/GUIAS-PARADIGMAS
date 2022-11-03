#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
Implemente una función que reciba una cadena y:

la convierta a mayúsculas: char *strupper(char *);
la convierta a minúsculas: char *strlower(char *);
invierta el casing: char *strinvertcase(char *);

Los caracteres que se encuentren en mayúsculas los convierta a minúsculas y los que están en minúsculas a mayúsculas.

Observación: la cadena puede contener caracteres que no sean letras.

la convierta a Title Case: char *titlecase(char *);

la convierta a snake_case: char *snake_case(char *);
la convierta al horrible CamelCase: char *puaj(char *);
borre todos los espacios a izquierda: char *left_trim(char *);
borre todos los espacios a derecha: char *right_trim(char *);
borre todos los espacios a izquierda y derecha: char *full_trim(char *);
la ajuste a n caracteres por línea: char *justify(char *, size_t n);
la centre agregando caracteres a izquierda y derecha: char *center(char *, size_t n);
*/

char *strupper(char *str){
    char* result = malloc(strlen(str));
    for(int i = 0;i < strlen(str);i++ ){
        result[i] = str[i] - 32;
    }
    return result;
}


int main(){
    char a[] = "a";
    char *b = strupper(a);
    printf("%s",b);
}