#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
Implemente una función que reciba un número y lo cargue en un arreglo de caracteres recibido como argumento. Sugerencia: utilice la función sprintf() de la biblioteca estándar de entrada y salida.
*/
int my_int_to_str(int num, char *str){
    sprintf(str, "%d", num);
}


int main(){
    char a[] = "Fire and blood.";
    my_int_to_str(14506,a);
    puts(a);
}