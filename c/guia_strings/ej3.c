#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
/*
(ctype.h) Escriba un programa que lea una cadena de caracteres e imprima una tabla como la siguiente:


$ ./g06e10
Ingrese la cadena: 1. Usen ctype.h!
                i
    i   i   i   s   i   i   i   i   i   i   i
    s   s   s   x   s   s   s   s   s   s   s
    d   a   a   d   l   u   s   c   p   p   g
    i   l   l   i   o   p   p   n   u   r   r
    g   p   n   g   w   p   a   t   n   i   a
    i   h   u   i   e   e   c   r   c   n   p
    t   a   m   t   r   r   e   l   t   t   h
 1  *       *   *                       *   *
 .                                  *   *   *
                            *           *
 U      *   *           *               *   *
 s      *   *       *                   *   *
 e      *   *   *   *                   *   *
 n      *   *       *                   *   *
                            *           *
 c      *   *   *   *                   *   *
 t      *   *       *                   *   *
 y      *   *       *                   *   *
 p      *   *       *                   *   *
 e      *   *   *   *                   *   *
 .                                  *   *   *
 h      *   *       *                   *   *
 !                                  *   *   *
 ?                          *   *
*/

int main(){

    char c[] = "Usen ctype.h!";
    for(int i = 0; i < strlen(c); i++){
        printf("%c ", c[i]);
        if (isdigit(c[i])){
            printf("*   ");
        }else{
            printf("    ");
        }
        if (isalpha(c[i])){
            printf("*   ");
        }else{
            printf("    ");
        }
        if (isalnum(c[i])){
            printf("*   ");
        }else{
            printf("    ");
        }
        if (isxdigit(c[i])){
            printf("*   ");
        }else{
            printf("    ");
        }
        if (islower(c[i])){
            printf("*   ");
        }else{
            printf("    ");
        }
        if (isupper(c[i])){
            printf("*   ");
        }else{
            printf("    ");
        }
        if (isprint(c[i])){
            printf("*   ");
        }else{
            printf("    ");
        }
        if (ispunct(c[i])){
            printf("*   ");
        }else{
            printf("    ");
        }
        if (isspace(c[i])){
            printf("*   ");
        }else{
            printf("    ");
        }
        if (iscntrl(c[i])){
            printf("*   ");
        }else{
            printf("    ");
        }
        if (isgraph(c[i])){
            printf("*   ");
        }else{
            printf("    ");
        }
    printf("\n");
    }
    
}