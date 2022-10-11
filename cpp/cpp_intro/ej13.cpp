#include <iostream>
#include <string>
#include <cmath>
#include "ej11.cpp"
//ej13
//Escribir un programa que acepte grados Celsius y Fahrenheit, y produzca la conversión correspondiente. 
//Por ejemplo, una entrada 0C devuelve 32F, mientras una entrada 212F devuelve 100C. Asuma una opción por defecto cuando no se especifica la unidad de entrada.
void ej13(){
    double celsius = 0.0;
    double fahrenheit = 0.0;
    char unidad;
    std::cout << "Ingrese grados Celsius o Fahrenheit: ";
    std::cin >> celsius >> unidad;
    if (unidad == 'C' || unidad == 'c') {
        std::cout << celsius << " grados Celsius son " << celsiusToFahrenheit(celsius) << " grados Fahrenheit" << std::endl;
    }
    else if (unidad == 'F' || unidad == 'f') {
        std::cout << fahrenheit << " grados Fahrenheit son " << fahrenheitToCelsius(fahrenheit) << " grados Celsius" << std::endl;
    }
    else {
        std::cout << "Unidad no reconocida" << std::endl;
    }
}