#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>


/*
bool_t es_palindroma(const char *);
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


bool es_palindroma(char* str){
    char *str2 = malloc(strlen(str));
    strcpy(str2,str);
    invertir(str2);
    if(strcmp(str,str2)==0){
        return EXIT_SUCCESS;
    }
    return EXIT_FAILURE;
}

int main(){
    printf("start ej8\n");
    char a[5];
    char b[5] = "hola";
    fgets(a,5,stdin);

    //compare a and b
    printf("%d",strcmp(a,b));
    
    //printf("%d",es_palindroma(a));

}