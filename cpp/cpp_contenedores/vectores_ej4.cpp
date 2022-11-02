#include <vector>
#include <cassert>
#include <iostream>
#include <cstdbool>

// Escribir una función que dado un vector de enteros y un número entero devuelva true solamente si en el vector hay al menos 3 de sus primeros 5 múltiplos (un número es múltiplo de si mismo).

// Ejemplo: {arreglo}, {numero} –> {resultado}


// [1,2,3,4,5], 2 --> _false_
// [1,2,3,4,5,6], 2 --> _true_

bool ej4(std::vector<int>& vec, int a){
    int count = 0;
    for (auto i : vec){
        if(i%a == 0){
            count++;
        }
    }
    if(count >= 3) {
        return true;
    }else{
        return false;
    }


}

int main(){
    std::vector<int> vec1 = {1,2,3,4,5,6};
    std::vector<int> vec2 = {1,2,3,4,5};
    assert(ej4(vec1,2));
    assert(!ej4(vec2,2));
    std::cout << "all test passed" << std::endl;
}

