#include <vector>
#include <cassert>
#include <iostream>
#include <cstdbool>

// Escribir una función que dado un vector ordenado y uno desordenado devuelva un vector ordenado con los elementos de ambos.

// Sugerencia: Aplicar el algoritmo de ordenamiento por inserción (insertion sort). Una alternativa un poco más desafiante (y eficiente) es ordenar el segundo arreglo utilizando ordenamiento por mezcla (merge sort) y luego hacer la mezcla (merge) de ambos arreglos ordenados.

// Ejemplo: {arreglo1}, {arreglo2} –> {resultado}


// [1,2,3,4,5] , [2,3,8] --> [1,2,2,3,4,5,8]
// [4,15,21,52], [17,14,5,15] --> [4,14,15,15,17,21,52]

std::vector<int> joinAndSort(std::vector<int>& sortedVec, std::vector<int>& UnsortedVec){
    for(auto elem : UnsortedVec){
        auto it = sortedVec.begin();
        while(it != sortedVec.end() && *it < elem){
            it++;
        }
        sortedVec.insert(it, elem);
    }
    return sortedVec;
}


int main(){

    std::vector<int> vec1 = {1,2,3,4,50};
    std::vector<int> vec2 = {2,3,8,0,10,100};
    std::vector<int> temp = {0,1,2,2,3,3,4,8,10,50,100};
    joinAndSort(vec1, vec2);
    assert(vec1 == temp);

    std::cout << "all test passed" << std::endl;
}