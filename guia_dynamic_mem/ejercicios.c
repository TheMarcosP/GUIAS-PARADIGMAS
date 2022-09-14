#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

//Implementar una función que reciba una cadena y retorne una copia de la misma, utilizando memoria dinámica, por el nombre. Si por algún motivo no se puede, retornar NULL.
char * ej1(char * str) {
    char * newstr = malloc(strlen(str) + 1);
    if (newstr == NULL) {
        return NULL;
    }
    strcpy(newstr, str);
    return newstr;
}

void ej1_test() {
    char * str = "Hola";
    char * newstr = ej1(str);
    printf("%s", newstr);
}


//Implementar una funcion que copie un arreglo de números.
int * ej2(int * arr, int len) {
    int * newarr = malloc(len * sizeof(int));
    if (newarr == NULL) {
        return NULL;
    }
    for (int i = 0; i < len; i++) {
        newarr[i] = arr[i];
    }
    return newarr;
}

//Implementar una funcion que copie un arreglo de números. y lo devuelva por referencia.
void ej2_b(int * arr, int len, int ** newarr) {
    *newarr = malloc(len * sizeof(int));
    if (*newarr == NULL) {
        return;
    }
    for (int i = 0; i < len; i++) {
        (*newarr)[i] = arr[i];
    }
}


void ej2_test() {
    int arr[] = {1, 2, 3, 4, 5};
    int len = 5;
    int * newarr = ej2(arr, len);
    for (int i = 0; i < len; i++) {
        printf("%d ", newarr[i]);
    }
}

void ej2_b_test() {
    int arr[] = {1, 2, 3, 4, 5};
    int len = 5;
    int * newarr;
    ej2_b(arr, len, &newarr);
    for (int i = 0; i < len; i++) {
        printf("%d ", newarr[i]);
    }
}



/*
Implementar una función que reciba una cadena de caracteres y un carácter. La función retorna una copia de la cadena, pero elimina todo lo que esté después del carácter recibido. Utilizar memoria dinámica. Ejemplo

                                  _______________
                                 |               |
("Esto va ; esto no va", ';') -->| strip_comment |--> "Esto va "
                                 |_______________|

*/
char * ej3(char* str,char c){
    int i;
    for (i = 0;str[i]!=c;i++);
    char *newstr = malloc(i + 1);

    if (newstr == NULL) {
        return NULL;
    }

    int j;
    for(j=0;j<=i;j++){
        newstr[j] = str[j]; 
    }
    newstr[j+1] = '\0';
    return newstr;
}

void ej3_test(){
    char * str = "Esto va ; esto no va";
    char c = ';';
    char * newstr = ej3(str,c);
    printf("%s",newstr);
}


/*
Implementar una función que reciba una cadena de caracteres que comienza con espacios y retorna, por la interfaz, una copia de la cadena sin los espacios del comienzo y final. Realizar las validaciones necesarias.
*/
void ej4(char* str){

    int len;
    len = strlen(str);

    int i;
    int j;
    for(i=0;str[i]==' ';i++);
    for(j = len -1 ;str[j]==' ';j--);


    printf("%d %d", i, j);
    //char* newstr = malloc(j-i+1);
    // for(i;i<=j;i++){
    //     newstr[i] = str[i];
    // }
    //return newstr;
}

void ej4_test(){
    char * str = " 123456  ";
    ej4(str);
}

int main(){
    ej4_test();
    return 0;
}