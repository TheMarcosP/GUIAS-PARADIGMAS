#include <vector>
#include <tuple>
#include <cassert>
#include <iostream>
#include <cstdbool>
#include <map>
// Escribir una función reciba un vector de triplas donde cada tripla (tupla con 3 elementos) tiene la forma (string, string, int) representando que una persona le debe a otra un monto de dinero (ej: <”Juan”, “Ilaria”, 200> indica que Juan le debe a Ilaria 200 pesos). La función debe devolver un vector con los nombres de las personas que deben mas de lo que les deben.

// Ejemplo: {operaciones} –> {deudores}

//[<"Juan", "Ilaria", 200>, <"Mauricio", "Juan", 100>,<"Ilaria", "Ignacio",100>] --> ["Juan", "Mauricio"]

std::vector<std::string> Positives(std::vector<std::tuple<std::string,std::string,int>>vec){
    std::map<std::string,int>balances;
    std::vector<std::string>result;

    for(auto tupla: vec){
        auto search = balances.find( std::get<0>(tupla) );
        if( search != balances.end()){
            balances[ std::get<0>(tupla) ] -= std::get<2>(tupla);
        }else{
            balances[std::get<0>(tupla) ] = -std::get<2>(tupla);
        }

        auto search2 = balances.find( std::get<1>(tupla) );
        if( search2 != balances.end()){
            balances[ std::get<1>(tupla) ] += std::get<2>(tupla);
        }else{
            balances[std::get<1>(tupla) ] = std::get<2>(tupla);
        }
    }

    for (const auto& [key, value] : balances){
        if(value < 0){
            result.emplace_back(key);
        }
    }
    return result;
}

int main(){

    //test function
    std::vector<std::tuple<std::string,std::string,int>> input;
    input = {{"Juan", "Ilaria", 200}, {"Mauricio", "Juan", 100},{"Ilaria", "Ignacio",100}};
    auto result = Positives(input);

    std::vector<std::string> expected = {"Juan","Mauricio"};
    assert(result == expected);

    std::cout << "all test passed" << std::endl;
}

