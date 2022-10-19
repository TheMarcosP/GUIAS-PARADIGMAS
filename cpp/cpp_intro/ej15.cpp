#include <iostream>
#include <string>
#include <cmath>

//ej15
// Agregue el código necesario para determinar el valor medio, máximo y mínimo de los valores generados.
int ej15()
{
    int how_many = 100;

    std::cout << "Print "
              << how_many
              << " random integers."
              << std::endl;

    for (int i = 0; i < how_many; ++i) {
        std::cout << std::rand() << '\t';
        
    }
    std::cout << std::endl;
}
