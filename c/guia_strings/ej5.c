#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
Implemente sus propias versiones de las funciones de la biblioteca string.h que se detallan:

size_t strlen(const char *);
char * strcpy(char *dest, const char *orig);
char * strncpy(char *dest, const char *orig, size_t n);
int strcmp(const char *s1, const char *s2);
int strncmp(const char *s1, const char *s2, size_t n);
char * strcat(char *dest, const char *orig);
void * memmove(void *dest, const void *src, size_t n);
void * memcpy(void *dest, const void *src, size_t n);
int memcmp(const void *s1, const void *s2, size_t n);
Si bien no pertenecen al estándar ISO sino al BSD:

int strcasecmp(const char *s1, const char *s2); que funciona como strcmp() pero es case insensitive.
int strncasecmp(const char *s1, const char *s2, size_t n);
*/

size_t my_strlen(const char * str){
    int i;
    for(i = 0; str[i] != '\0'; i++);
    return i;
}

int my_strcmp(const char *s1, const char *s2){
    if(my_strlen(s1) != my_strlen(s2)){
        return EXIT_FAILURE;
    }

    for(int i =0;i<my_strlen(s1);i++){
        if(s1[i]!=s2[i]){
            return EXIT_FAILURE;
        }
    }
    return EXIT_SUCCESS;
}



char * my_strncpy(char *dest, const char *orig, size_t n){
    //check inputs
    if (my_strlen(orig) < n || my_strlen(dest) < n){
        printf("invalid input\n");
        return NULL;
    }

    for(int i =0;i<n;i++){
        dest[i] = orig[i];
    }
    return dest;
}





int main(){
    char a[] = "Fire and blood";
    char b[] = "Fire and blood";

    //printf("%d",strcmp(a,b));
    
    // if(my_strncpy(a, "Winter is coming.", 200)){
    //     printf("%s",a);
    // }

    // if(!my_strcmp(a,b)){
    //     printf("\nstrs are equal\n");
    // }


}