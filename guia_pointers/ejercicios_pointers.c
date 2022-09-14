#include <stdio.h>
#include <stdlib.h>

//ej2
void ej2(){
    int i = 3, * pint;
    float f = 10.0;

    pint = &i;
    *pint = 10;
    *pint = f;
    //pint = &f;   // error: incompatible types when assigning to type 'int *' from type 'float *'
    //pint = 4321; // error: incompatible types when assigning to type 'int *' from type 'int'
}

void ej3a(){
    float var, set[] = {1.0, 2.0, 3234.0, 4.0, 5.0};
    float *p;

    p = set; // p = &set[0]
    var = *p; // var = set[0]
    *p=10.0; // set[0] = 10.0

    //test

    printf("var = %f\n", var);
    printf("*p = %f\n", *p);
    //*p plus two index
    p++;
    p++;
    printf("*p = %f\n", *p);
}

void ej3b(){
    int conj[5], list[]={5, 4, 3, 2, 1};
    int **punt;

    //punt = &list; // punt = &list[0]
    printf("%d\n", **punt);

}

void ej3c(){
    int *pint, arrayint[5];
float *pfloat, arrayfloat[5];

arrayint[1] = 1340;

pint = arrayint;
pfloat = arrayfloat;
pint += 1;
pfloat += 1;
pint++;
pfloat++;
pint -= 1;
pfloat -=1;

//printf("%d\n", *pint);
}


void ej3d(){
    
int *p, a[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

int var;
p = a;
*p = 33;
// var = *p;
// var = *(p+1);
// var = *(p+3);
//var = *(p++);
//var = *p++;
//var = *(++p);
//var = *p;
//var = *++p;
var = ++*(++p);
// var = (*p)++;
//var = ++(*p);
//var = *p+1;
printf("%d\n", var);

}

//??? a+1 != a++ != ++a
void ej3e(){
    int *p, a[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
int var;
var = *(a+3);
//var = *(a++);
printf("%d\n", var);
}

void ej4(){
    int *ip, **ipp, (*ip16)[16], i, j;
    int matriz[5][16];

    for (i = 0; i < 5; i++)
        for (j = 0; j < 16; j++)
            matriz[i][j] = i * 16 + j;

ip16 = matriz;
ip = (int *)matriz;
ipp = (int **) matriz;

printf("%p \n", ipp);
printf("%p \n", ip);
for (i = 0; i < 5; i++){
    for (j = 0; j < 16; j++){
        printf("%d ", *(ip+74));
    }

//???
//*(*(ip16 + i) + j)
//*(*(matriz + i ) + j)
}
}


void ej5(){
    int matriz[3][4] = { { 1, 2, 3, 40}, { 5, 6, 7, 8}, { 9,10,11,12} };
    int * ptr;
    int (*ptr2vector)[4];
    int fila, col;

    ptr = matriz[0];
    ptr2vector = matriz;
    for (fila = 0; fila < 3; fila++){
        for (col = 0; col < 4; col++){
            //printf("%d ", *(ptr+fila*4+col));
            //printf("%d ", *(ptr2vector[fila]+col));
            printf("%d ", *(*(ptr2vector+fila)+col)); // ???
        }
    }
}


// funciones con punteros

void swap(int* a, int* b){
    int aux;
    aux = *a;
    *a = *b;
    *b = aux;
}

void suma(int a, int b, long int *suma){
    *suma = a + b;
}
void resta(int a, int b, long int *resta){
    *resta = a - b;
}
void producto(int multiplicando, int multiplicador, float *producto){
    *producto = multiplicando * multiplicador;
}
void division(int dividendo, int divisor, double * cociente){
    *cociente = dividendo / divisor;
}
void mod(int dividendo, int divisor, double* resto){
    *resto = dividendo % divisor;
}

//ej3
#include <stdbool.h>

bool secsToTime(int secs,double* hours,double*minutes,double*seconds){
    if(secs){
        *hours = secs/3600;
    }
    if(secs%3600){
        *minutes = (secs%3600) / 60;
    }
    *seconds = (secs%3600) % 60;
}



/*
ej4
(matemática) Implementar funciones que reciban un arreglo de números y su longitud y realicen las operaciones detalladas abajo. Utilice notación de punteros exclusivamente.

completar el vector con ceros,
completar el vector con unos,
calcular y retornar la suma por la interfaz,
calcular y retornar la media por la interfaz,
calcular y retornar la varianza por la interfaz,
retornar el valor máximo del arreglo por la interfaz,
retornar el valor mínimo del arreglo por la interfaz,
modificar los elementos del vector reemplazándolos por sus valores al cuadrado,
modificar los elementos del arreglo reemplazando cada elemento por su signo. Considere  
modificar los elementos del arreglo reemplazándolos por las diferencias finitas de primer orden. Para hacer esto, usando como caso de ejemplo el primer y segundo elemento:
*/

void fillVector(double *v, size_t n){
    for(int i = 0;i<n;i++){
        v[i] = 1;
    }
}

void signo(double *v, size_t n){
    for(int i=0;i<n;i++){
        if(v[i]>=0){
            v[i] = 1;
        }else{
            v[i] = -1;
        }
    }
}

void Max(double *v,size_t n, double *max){
    *max = v[0];
    for(int i = 1;i<n;i++){
        if(v[i] > *max){
            *max = v[i];
        }
    }
}


//ej 5

bool veccpy(double *dest, size_t ldest, const double *orig, size_t lorig){
    if (ldest < lorig){
        return -1;
    }
    for(int i= 0;i<lorig;i++){
        dest[i] = orig[i];
    }
}


//ej 7

const int * busqueda_lineal(const int *v, size_t n, int objetivo){
    if(!v || !objetivo || !n){
        return NULL;
    }

    for(int i= 0;i<n;i++){
        if(v[i] == objetivo){
            return &v[i];
        }
    }
    return NULL;

}
bool busqueda_lineal2(int *v, size_t n, int objetivo, int *resultado){
     if(!v || !objetivo || !n){
        return false;
    }

    for(int i= 0;i<n;i++){
        if(v[i] == objetivo){
            *resultado = v[i];
            return true;
        }
    }
    return false;

}

//ej8 
const int * busqueda_binaria(const int *v,  /* vector donde buscar */
                             size_t n,      /* largo del vector */
                             int objetivo,  /* elemento a buscar */
                             size_t izq,    /* franja del vector donde buscar, */
                             size_t der){   /* delimitada por izq y der */
int _medio = 0;
while (v[_medio] != objetivo){   
_medio = (der + izq)/2;
    if(v[_medio] > objetivo){
        der = _medio - 1 ;
    }else{
        izq = _medio;
    }
}
return &v[_medio];
}   

void compare(int expected,int got){
    if(expected == got){
        printf(".");
    }else{
        printf("%d",expected);
    }
}



bool busqueda_binaria2(int *v,        /* vector donde buscar */
                      size_t n,      /* largo del vector */
                      int objetivo,  /* elemento a buscar */
                      size_t izq,    /* franja del vector donde buscar, */
                      size_t der,    /* delimitada por izq y der */
                      int *resultado){
    if(!v || !objetivo || !n){
        return false;
    }
    if(izq > der){
        return false;
    }
    size_t medio = (izq + der) / 2;
    if(v[medio] == objetivo){
        resultado = &v[medio];
        return true;
    }
    if(v[medio] > objetivo){
        return busqueda_binaria2(v,n,objetivo,izq,medio-1,resultado);
    }
    return busqueda_binaria2(v,n,objetivo,medio,der,resultado);

}


int main(){
    int or[10] = {0,12,23,34,44,53,62,70,89,100};

    //ej1 funciones
    // int a = 1, b = 2;
    // swap(&a, &b);
    // printf("%d %d", a, b);
    // return 0;

    //ej2

    // long int s;
    // suma(1, 1232, &s);
    // printf("%ld", s);

    //ej3
    // double h,m,s;
    // secsToTime(1000,&h,&m,&s);
    // printf("%f,%f,%f",h,m,s);

    //ej4 y 5
    // double v[10] = {1,-23,5,67,-8,234,-9,9,2,5};
    // double d[10];
    // double a;
    //fillVector(d,10)
    //Max(v,10,&a);
    //signo(v,10)
    // veccpy(d,10,v,10);
    // printf("%f",d[4]);

    //ej7
    int v[10] = {1,-23,5,67,-8,234,-9,9,2,5};
    int f[10];
    int r;
    const int* b;
    // b = busqueda_lineal(v,10,r);
    // if(!b){
    //     printf("NO B");
    // }else{
    // printf("%p",b);
    // }
    // int zz;
    // busqueda_lineal2(v,10,-23,&zz);
    // printf("%d",zz);
    
    //EJ8
    // b = busqueda_binaria(or,10,34,0,9);
    // printf("%d",*b);
    int* result;
    busqueda_binaria2(or,10,34,0,9,result);
}
