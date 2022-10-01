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


/*
Implementar una función que reciba una cadena de caracteres, un carácter y una longitud. La misma retorna una copia dinámica de la cadena original, centrada en la longitud especificada y rellenando con el carácter pedido.
                          _________
                         |         |
(" cadena ", '*', 12) -->| centrar |--> "** cadena **"
                         |_________|

*/

char* ej5(const char* str, const char c, const int len){
    int i;
    int j;
    int k;
    int str_len;
    str_len = strlen(str);
    char* newstr = malloc(len+1);
    for(i=0;i<len;i++){
        newstr[i] = c;
    }
    newstr[i] = '\0';
    for(j = (len-str_len)/2,k=0;j<(len+str_len)/2;j++,k++){
        newstr[j] = str[k];
    }
    return newstr;
}

void ej5_test(){
    char * str = "cadena";
    char c = '*';
    int len = 12;
    char * newstr = ej5(str,c,len);
    printf("%s",newstr);
}

//ej9
//Implementar una función que reciba un vector de cadenas, su longitud y una cadena delimitadora y retorne una cadena uniendo todas las cadenas del vector, agregando la delimitadora entre ellas.
char * ej9(char ** arr, int len, char * delim) {
    int delim_len = strlen(delim);
    int total_len = 0;
    for (int i = 0; i < len; i++) {
        total_len += strlen(arr[i]);
    }
    total_len += delim_len * (len - 1);
    char * newstr = malloc(total_len + 1);
    if (newstr == NULL) {
        return NULL;
    }

    int pos = 0;
    for (int i = 0; i < len; i++) {
        strcpy(newstr + pos, arr[i]);
        pos += strlen(arr[i]);
        if (i != len - 1) {
            strcpy(newstr + pos, delim);
            pos += delim_len;
        }
    }
    newstr[total_len] = '\0';
    return newstr;
}

void ej9_test() {
    char * arr[] = {"hola", "como", "estas"};
    int len = 3;
    char * delim = "?";
    char * newstr = ej9(arr, len, delim);
    printf("%s", newstr);
}


/*
Funciones con vectores y matrices
Implementar una función que reciba el inicio de un intervalo, el final y la cantidad de puntos y retorne un arreglo de números linealmente espaciados entre el inicio y el final.


*/
double * linspace(double inicio, double fin, size_t nelems){
    double *arr = malloc(nelems * sizeof(double));
    double step = (fin - inicio) / (nelems - 1);
    for (int i = 0; i < nelems; i++) {
        arr[i] = inicio + step * i;
    }
    return arr;
}



bool linspace2(double inicio, double fin, size_t nelemes, double **valores){
    double *arr = malloc(nelemes * sizeof(double));
    double step = (fin - inicio) / (nelemes - 1);
    for (int i = 0; i < nelemes; i++) {
        arr[i] = inicio + step * i;
    }
    *valores = arr;
    return true;
}


//Implementar una función que retorne una matriz dinámica, de un tamaño pasado como argumento:
// ceros,

double ** zeros(size_t n, size_t m){
    double **mat = malloc(n * sizeof(double *));
    for (int i = 0; i < n; i++) {
        mat[i] = malloc(m * sizeof(double));
        for (int j = 0; j < m; j++) {
            mat[i][j] = 0;
        }
    }
    return mat;
}

// por interfaz 
bool zeros2(size_t n, size_t m, double ***mat){
    double **mat2 = malloc(n * sizeof(double *));
    for (int i = 0; i < n; i++) {
        mat2[i] = malloc(m * sizeof(double));
        for (int j = 0; j < m; j++) {
            mat2[i][j] = 0;
        }
    }
    *mat = mat2;
    return true;
}


int main(){
    //ej4_test();
    //ej5_test();
    ej9_test();

}