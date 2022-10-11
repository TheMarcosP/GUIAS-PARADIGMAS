#include <iostream>
#include <string>
#include <cmath>

/*
ej1
Escribir la siguiente frase por pantalla “She sells sea shells by the seashore.”

Todo en una sola línea.
En siete líneas.
Dentro de un recuadro.
*/
void printnormal(std::string frase) {
    std::cout << frase << std::endl;
}

void printline(std::string frase) {
    //en 7 lineas
    std::cout << "subtring    " << frase.substr(0, 4) << std::endl;
    //print str replacing spaces with newlines
    for (int i = 0; i < frase.length(); i++) {
        if (frase[i] == ' ') {
            std::cout << std::endl;
        } else {
            std::cout << frase[i];
        }
    }
    std::cout << std::endl;
}

void printbox(std::string frase) {
    //dentro de un recuadro
    for(int i= 0; i<frase.length() + 4; i++){
    std::cout << "-";
    }
    std::cout << std::endl;
    std::cout << "| " << frase << " |" << std::endl;

    for(int i= 0; i<frase.length() + 4; i++){
    std::cout <<"-";
    }
    std::cout << std::endl;
}

