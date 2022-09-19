#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
Escriba una función que reciba un número entero positivo y un arreglo de caracteres y cargue en este último la representación en binario del primero. Implemente además la función inversa, que recibe una representación de un número en binario y carga un número con el valor que ésta representa.
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

int DecimalToBinary(int n, char *str){
    int i = 0;
    while (n > 0) {
        str[i] = n % 2 + '0';
        n = n / 2;
        i++;
    }
    str[i] = '\0';
    invertir(str);
    return i;
}

int BinaryToDecimal(char *str){
    int n = 0;
    int i = 0;
    while (str[i] != '\0') {
        n = n * 2 + (str[i] - '0');
        i++;
    }
    return n;
}



int test_binario(){
    printf("start ej12\n");
    char a[100];
    int n = 10;
    DecimalToBinary(n,a);
    printf("\nDECIMAL TO BINARY: %s\n",a);
    printf("\nBINARY TO DECIMAL: %d\n",BinaryToDecimal(a));
    return 0;
}

int main(){
    test_binario();
}