#include <iostream>
#include <string>
#include <cmath>
#include <cstdlib>
// Escriba una función que devuelve el resultado de tirar una moneda (cara o ceca) sin utilizar el operador '%'.

// Escriba un programa que realice 100 lanzamientos y que imprima la cantidad de caras y cecas obtenidas, junto con los porcentajes. Imprima la cantidad de veces seguida que salió cara.

// Repita incrementando la escala de la cantidad de ensayos ¿Qué valores esperaría encontrar si la moneda se lanzara infinitas veces?
// 50 50

//for positives ints
int calculate_remainder(int dividend, int divisor) {
    return dividend - (dividend / divisor) * divisor;
}




int tossCoin() {
    return calculate_remainder(rand(), 2);
}


void testTostCoin(){
    //srand
    int count_face = 0;
    int count_tail = 0;
    int turns = 10000;
    for(int i = 0;i < turns; ++i){
        if (tossCoin() == 0) {
            count_face++;
        }
        else {
            count_tail++;
        }
    }
    std::cout << "Caras: " << count_face << "   " << (count_face/(double)turns) * 100<< " %" << std::endl;
    std::cout << "Cecas: " << count_tail << "   " << (count_tail/(double)turns) * 100 << " %" << std::endl;
}

int main(){
    srand(time(NULL));
    testTostCoin();
}