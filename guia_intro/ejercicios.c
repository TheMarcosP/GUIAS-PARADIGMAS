#include <stdio.h>
#include <math.h>

void pr(){
    printf("Hello3, World!\n");
}

// float pwr(int base, int exponent){
//     int result = base;
//     for (int i = 1; i<exponent; i++){
//         int temp = result * base;
//         result = temp;
//     }
//     return result;
// }


//ej1
double interes(int capital, float interes, int years){
 float a = capital * pow((1 +(interes/100)), years);
 printf("%f\n",a);
    return a;
}

//ej2
float f_to_c(float f){
    float c = (f - 32) * (5.0 / 9.0);
    printf("%f\n", c);
    return c;
}
//ej3
float c_to_f(float c){
    float f = c * (9.0 / 5.0) + 32;
    printf("%f\n", f);
    return f;
}

//ej 4
int time_to_secs(float hours, float minutes, int seconds){
    float result = 3600 * hours + 60 * minutes + seconds;
    //printf("%f\n", result);
    return result;
}
//ej 5
float norma(float x, float y, float z){
    float result = sqrt(pow(x,2)+ pow(y,2) + pow(x,2));
    printf("%f\n", result);
    return result;
}

//ej 8
float m(int number){
    while (number % 10 != 0){
        --number;
    }
    printf("%d\n", number);
    return number;
}


//Programas sencillos: Decisiones

//Programa sencillo: Ciclos

void tabla(){
    float c_temp;
    for (c_temp = 0; c_temp < 100;c_temp += 10){
        printf("| %7.2f  | %7.2f  |\n", c_temp, c_to_f(c_temp));
    }
}

void test_time_to_secs(float objetivo, float function, char * msg){
    if (function == objetivo){
        printf(".");
    }else{
        printf(" (%s)", msg);
    }
}

int main(void) {
    //interes(100, 10, 5); 
    
    //ej2

    //ej4
    //time_to_secs(2,30,10);
    test_time_to_secs(3600, time_to_secs(1,0,0), "error 1 ");
    test_time_to_secs(60, time_to_secs(0,1,0), "error 0, 1, 0");
    test_time_to_secs(1, time_to_secs(0,0,1), "error 0, 0, 1");
    test_time_to_secs(0, time_to_secs(0,0,0), "error 0, 0, 0");

    //ej5
    //norma(5,10,2);

    //ej8
    //m(12345);

    //ej ciclos
    //tabla();
}
// imperativo hace lo q le pidas, incluso si le pedis algo mal

