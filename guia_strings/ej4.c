#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>
/*

*/

int isempty(char *s){
    return s[0] == '\0';
}

int main(){
    char a[10] = "sf";
    printf("%d", isempty(a));
}