// Escribir una función que dado un vector de enteros, devuelva el vector sin los números primos (suponer números mayores a cero; 1 no es primo). La función debe modificar el vector, no crear uno nuevo.

#include <vector>
#include <cassert>
#include <iostream>
#include <cstdbool>

bool isPrime(int a){
    if(a<=1) return false;
    for(int i = 2; i<a;i++){
        if(a%i == 0){
            return false;
        }
    }
    return true;
}


void removePrimes(std::vector<int>&vec){
    std::vector<int> temp;
    //iterate vector
    // for (unsigned int i = 0; i < vec.size(); i++) {}
    // for (auto i = vec.begin(); i != vec.end(); i++) {}
    for (auto i : vec) {
        if (!isPrime(i)) {
            temp.emplace_back(i);
        }
    }
    vec = temp;
    std::cout << std::endl;
}

int main(){
    assert(!isPrime(-3));
    assert(!isPrime(0));
    assert(!isPrime(1));
    assert(isPrime(2));
    assert(!isPrime(4));
    assert(isPrime(5));
    assert(isPrime(11));

    std::vector<int> vec = {1,2,3,4,5,6,7,8,10,4,5};
    std::vector<int> temp = {1,4,6,8,10,4};
    removePrimes(vec);
    assert(vec == temp);

    std::cout << "all test passed" << std::endl;
}