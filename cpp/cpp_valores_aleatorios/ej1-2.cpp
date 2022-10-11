#include <iostream>
#include <string>
#include <cmath>
#include <cstdlib>


// Escribir un programa que simule una ruleta con los números del 0 al 35. Esto es donde la rueda tiene los números del 0 al 35. Se debe utilizar un generador de números aleatorios que obtenga uno de estos valores con igual probabilidad. Probar la simulación haciendo girando la rueda 36, 360, 3600 y 36000 veces. Guardar los resultados en una matriz de 36 valores enteros, uno por cada posición de la rueda. Imprimir los resultados.

int play_ruleta() {
    return rand() % 36;
}

void test_ruleta(){
    srand(time(NULL));
    int turns = 36000;
    int results[36] = {0};
    for(int i = 0;i < turns; ++i){
        results[play_ruleta()]++;
    }
    for(int i = 0;i < 36; ++i){
        std::cout << i << " " << results[i] << std::endl;
    }
}

// Reutilizando la función desarrollada en el ejercicio anterior, simular un apostador realizando 1000 apuestas de un morlaco con una cuota de 35/1 (Ganancia neta / cantidad apostada). Notar que la relación justa debiera ser 36/1 (esto es lo que favorece a los casinos y por qué tienen un margen de ganancia).

// El apostador comienza con 1000 morlacos. Imprima con cuánto dinero se queda el apostador al final de sus 1000 apuestas. Considere esto un ensayo. Ahora repita este ensayo mil veces y vea cuál es el balance final promedio luego de realizar las 1000 apuestas. ¿Se ajusta a lo que esperaba?
void test_apostador(){
    srand(time(NULL));
    int turns = 1000;
    int balance = 1000;
    int results[36] = {0};
    for(int i = 0;i < turns; ++i){
        int result = play_ruleta();
        if (result == 0) {
            balance += 35;
        }
        else {
            balance -= 1;
        }
    }
    std::cout << balance << std::endl;
}



int main(){
    test_apostador();
}
