#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
/*
Implemente una función que reciba una cadena de caracteres, posiblemente representando un número entero, y convierta su contenido al número que representa. Similar a strtol().
*/

int my_strtol(char *str, int* dest ){
    int len = strlen(str);
    int result = 0;
    for(int i =0; i < strlen(str); i++){
        result += (str[i] - '0') * pow(10,len - i - 1);
    }
    *dest = result; 

}
int main(){
    char a[] = "14506";
    int b;
    my_strtol(a,&b);
    printf("%d",b);

}