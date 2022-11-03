#include <vector>
#include <tuple>
#include <cassert>
#include <iostream>
#include <cstdbool>

// Escribir una función que dada una cadena y un vector de tuplas que contienen una cadena y un arreglo de enteros, devuelva un nuevo vector de tuplas que contenga únicamente las tuplas cuyo primer elemento concuerda con la cadena pasada como argumento de la función.

std::vector<std::tuple<std::string, std::vector<int>>> ej2(std::string a, std::vector<std::tuple<std::string, std::vector<int>>>& b){
    std::vector<std::tuple<std::string, std::vector<int>>> result;
    for (auto i : b){
        if(std::get<0>(i) == a){
            result.emplace_back(i);
        }
    }
    return result;
}


int main(){
    std::vector<std::tuple<std::string, std::vector<int>>>expected{{"a",{1,2,3}},{"a",{7,8,9}}};
    std::vector<std::tuple<std::string, std::vector<int>>>actual{{"a",{1,2,3}},{"b",{4,5,6}},{"a",{7,8,9}}};
    assert(ej2("a",actual) == expected);

    std::cout << "all test passed" << std::endl;
}


