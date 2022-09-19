
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>


//ej 2 Leer del teclado y almacenar 12 valores de punto flotante en el arreglo temp_mensuales.
void leerMensuales()
{
    float temp_mensuales[12];
        for (int i = 0; i < 12; i++)
        {
            printf("Ingrese temperatura mensual: ");
            scanf("%f", &temp_mensuales[i]);
        }
        for (int i = 0; i < 12; i++)
        {
            printf("%f\n", temp_mensuales[i]);
        }
}

//ej 3 Sumar un 30% a cada uno de los 5 elementos del arreglo de números salarios
void wageIncrease()
{
    float salaries[5] = {1000,500,300,600,300};
    for (int i = 0; i < 5; i++){
        salaries[i] = salaries[i] * 1.3;
    }
    for (int i = 0;i < 5; i++){
        printf("%f\n", salaries[i]);
    }
}

//4. Escribir un programa que pida al usuario una cantidad  de valores a generar. Luego genere  valores enteros en el intervalo  y cuente la cantidad de 0s, de 1s, de 2s, etc. Al finalizar, imprima las cantidades calculadas en forma absolutas y relativas. Realice las validaciones necesarias.

// Ejemplo

// Ingrese la cantidad de números a generar: 10000
// 0s: 1008 (0.1008)
// 1s: 1023 (0.1023)
// 2s:  967 (0.0967)
// 3s: 1061 (0.1061)
// 4s:  966 (0.0966)
// 5s: 1057 (0.1057)
// 6s:  980 (0.0980)
// 7s: 1010 (0.1010)
// 8s:  951 (0.0951)
// 9s:  977 (0.0977)

//function that generates a random number between 0 and 10
int randomNumber()
{
    int randomNumber = (rand() % 10) +1;
    return randomNumber;
}

void generator(int n){
    int contador[10] = {0,0,0,0,0,0,0,0,0,0};
    int random_array[n];
    srand(time(NULL));
    
    //fill array with random ints between 0 and 10
    for (int i = 0; i < n; i++){
        random_array[i] = randomNumber();
    }

    for(int i = 0; i < n ; i++){
        for(int index=0;index < 10;index++){
            if (random_array[i] == index+1){
                contador[index] += 1;
            }
        }
    }

    //print contador array
    printf("elemento  valor histograma\n");
    for(int i = 0; i<10;i++){
        printf("%2d: %10d ", i+1, contador[i]);
        for(int t=0;t<contador[i]* 100/n;t++){
            printf("*");
        }
        printf("\n");
    }

}


//6. (búsqueda lineal) Implementar una función que reciba un vector, su longitud, un número objetivo a buscar y retorne la posición en la que se encuentra. ¿Qué ocurre en caso que el objetivo no se encuentre y qué se retorna? Un posible prototipo:
int busqueda_lineal(int* vector, int n, int objetivo)
{
    for (int i = 0; i < n; i++){
        if (vector[i] == objetivo){
            printf("%d \n",i);
            return i;
        }
    }
}

bool veccpy(double dest[], size_t ldest, const double orig[], size_t lorig){
    if(ldest != lorig){
        return false;
    }else{
        for(int i=0;i<lorig;i++){
            dest[i] = orig[i];
        }
        return true;
    }
}

void printArr(double a[], size_t size){
    for(int i =0;i<size;i++){
        printf("%f ", a[i]);
    }
    printf("\n");
}


//inicializar matrix con la identidad
void loadMatrix(double a[][10], size_t rows, size_t cols){

    if (rows != cols){
        printf("Error: rows and cols must be equal");
        return;
    }

    for(int i = 0; i < ROWS; i++){
        for(int j = 0; j < COLS; j++){
            if(i == j){
                a[i][j] = 1;
            }else{
                a[i][j] = 0;
            }
        }
    }
}



const int ROWS = 2;
const int COLS = 5;

int main(void) 
{
    //leerMensuales();
    //wageIncrease();
    
    // int vector[1000] = {1,2,40,2,5};
    // int pos = busqueda_lineal(vector,5,40);
    // printf("%d\n", vector[pos] );
    
    //generator(100000);
    
    //int a[6] = {0,0,1,0,0,0};
    // int b[6] = {1,2,3,4,5,6};
    // int** f;
    // f = b;
    // printf("%p\n",f);

    // arrays multidimensionales

    //double a[ROWS][COLS];
    //loadMatrix(a, ROWS, COLS);

    double A[10][10];
    loadMatrix(A, 10, 10);

}

// loadMatrix by reference
