#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
Implemente una función que reciba una cadena y la invierta.

char * invertir(char *);
*/

void invertir(char *str)  
{  
    int temp;
    for(int i=0;i < strlen(str)/2; i++){
        temp = str[i];
        str[i] = str[strlen(str)-1 -i];
        str[strlen(str)-1 -i] = temp;
    }
}  

int main(){
    printf("start ej7\n");
    char a[] = "hola";
    invertir(a);
    printf("%s",a);
}