#include <vector>
#include <tuple>
#include <cassert>
#include <iostream>
#include <cstdbool>
#include <map>

// Escribir una función que dado el código de una materia retorne una tupla con el nombre de la materia y el nombre del docente a cargo. Por ejemplo, para el código “I102” la función devuelve la tupla (“Paradigmas de Programación”, “Patricio Moreno”).

std::tuple<std::string, std::string> classInfo(std::string code){
    std::map< std::string, std::tuple<std::string, std::string> > m{{"I102",{"paradigmas","Patricio Moreno"}},{"I103",{"analisis matematico", "marcelo"}}};
    return m[code];
}

int main(){

    assert(classInfo("I102") == std::make_tuple("paradigmas","Patricio Moreno"));
    assert(classInfo("I103") == std::make_tuple("analisis matematico", "marcelo"));

    std::cout << "all test passed" << std::endl;
}


