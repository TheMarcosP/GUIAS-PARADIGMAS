#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

/*
Escriba un programa que reciba una cadena de caracteres e imprima su longitud, à la strlen().
*/
int ej2(int argc, char *argv[]){
        if(argc != 2){
        printf("invalid input");
        return 1;
    }
    int len;
    for(len = 0; argv[1][len] != '\0';len++);
    printf("%d",len);
}


//Escriba un programa que reciba dos cadenas de caracteres e imprima el resultado de su comparación lexicográfica, como lo haría la función strcmp()
void ej3(int argc, char* argv[]){
    printf("%d",strcmp(argv[1],argv[2]));
}

//El siguiente programa reemplazará caracteres, recibidos como argumentos, en líneas leídas por stdin. Se debe ejecutar del siguiente modo:
//$ cat archivo.txt | ./reemplazar viejo nuevo
void ej6(int argc, char* argv[]){
    char* viejo = argv[1];
    char* nuevo = argv[2];
    char c;
    while((c = getchar()) != EOF){
        if(c == viejo[0]){
            printf("%s",nuevo);
        }else{
            printf("%c",c);
        }
    }
}

/*
El siguiente programa procesará las líneas por stdin e imprimirá datos de las mismas. Escriba un programa que reciba como parámetros una posición y un ancho e imprima, de cada línea, los datos que comienzan en la posición posición y se componen de ancho caracteres. La ejecución del mismo es:


$ cat archivo.txt | ./extraer posición ancho
*/
// void ej8(int argc, char* argv[]){
//     int pos = atoi(argv[1]);
//     int ancho = atoi(argv[2]);
//     char c;
//     char str[100];
//     int i = 0;
    
//     while((getline(str,100,stdin) != EOF){
//         if(i >= pos && i < pos + ancho){
//             printf("%c",c);
//         }
//         i++;
//     }
// }



//ej10

int search(int argc, char* argv[], char* p, double* value){
    for(int i = 1; i < argc; i++){
        if((strcmp(argv[i],p) == 0) & (i+1 < argc) & value != NULL){
            *value = strtod(argv[i+1],NULL);
            return EXIT_SUCCESS;
        }
        else if ((strcmp(argv[i],p) == 0)){
            return EXIT_SUCCESS;
        }
    }
    return EXIT_FAILURE;

}

float RandomFloat(float min, float max){
   return ((max - min) * ((float)rand() / RAND_MAX)) + min;
}

void ej10(int argc, char *argv[]){


    double start, end, n;
    search(argc,argv,"-a",&start);
    search(argc,argv,"-b",&end);
    search(argc,argv,"-n",&n);
    
    if(search(argc,argv,"-h",NULL) == 0){
        printf("Usage: %s -a start -b end -n elements [-h]",argv[0]);
        return exit(EXIT_SUCCESS);
    }

    printf("start: %f\n",start);
    printf("end: %f\n",end);
    printf("n: %f\n",n);
    //get n random elements from start to end
    srand(time(NULL));
    for(int i = 0; i < 5; i++){
        printf("%f ",RandomFloat(start,end));
    }

}


int main(int argc, char *argv[]){
    ej8(argc,argv);

}