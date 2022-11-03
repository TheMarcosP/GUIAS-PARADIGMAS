// Escribir una función que dado un vector de enteros, devuelva un nuevo vector duplicando cada elemento. El programa debe imprimir lo que se ve en el ejemplo.

// Ejemplo: {entrada} –> {salida}


// [1, 2, 3, 4] --> [1, 1, 2, 2, 3, 3, 4, 4]
// [1, 1, 2, 2] --> [1, 1, 1, 1, 2, 2, 2, 2]

#include <vector>
#include <cassert>
#include <iostream>

std::vector<int> duplicate(std::vector<int> a){
    std::vector<int> result;
    result.reserve(2*a.size()); //como ya se el size lo reservo asi no tiene que estar realocando memoria todo el tiempo

    for(unsigned int i = 0;i<a.size();i++){
        result.emplace_back(a[i]);
        result.emplace_back(a[i]);
    }
    return result;
}

int main(){
    std::vector<int> vector = {-1,1,2,3,4,8};
    std::vector<int> temp = {-1,-1,1,1,2,2,3,3,4,4,8,8};

    assert(duplicate(vector) == temp); // ??? como verificar el resultado sin usar temp?

    std::cout << "all test passed" << std::endl;
    return 0;
}
