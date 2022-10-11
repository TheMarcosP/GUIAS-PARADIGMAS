#include <iostream>
#include <string>
#include <cmath>


/*
11. Escriba un programa para convertir grados Celsius a grados Fahrenheit, y otra para convertir grados Fahrenheit a Celsius. Escriba un programa (main) que permita validar distintas conversiones. Si las funciones se llaman  y  respectivamente, verifique que se cumpla que
*/
double celsiusToFahrenheit(double celsius) {
    return celsius * 9 / 5 + 32;
}

double fahrenheitToCelsius(double fahrenheit) {
    return (fahrenheit - 32) * 5 / 9;
}

void ej11(){
    double celsius = 0.0;
    double fahrenheit = 0.0;
    std::cout << "Ingrese grados Celsius: ";
    std::cin >> celsius;
    std::cout << celsius << " grados Celsius son " << celsiusToFahrenheit(celsius) << " grados Fahrenheit" << std::endl;
    std::cout << "Ingrese grados Fahrenheit: ";
    std::cin >> fahrenheit;
    std::cout << fahrenheit << " grados Fahrenheit son " << fahrenheitToCelsius(fahrenheit) << " grados Celsius" << std::endl;
    return;
}

