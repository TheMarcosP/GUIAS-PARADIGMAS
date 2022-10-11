#include <iostream>
#include <string>
#include <cmath>



/*
ej4
Escribir un programa que reciba la cantidad de distintas monedas ingresadas (de a un tipo de moneda a la vez), a saber:

5 centavos
10 centavos
25 centavos
50 centavos
1 peso
2 pesos
5 pesos
10 pesos
Y devuelva el monto total con un mensaje por pantalla de la forma:

“Su monto total es de $PP.CC” (donde PP es la cantidad de pesos y CC la cantidad de centavos)
“Su monto total es de PP peso(s) y CC centavo(s). Considere que las palabras pesos y centavos puede tomar la forma singular o plural, según la cantidad en particular. Resuélvalo.
*/

void contador(){
    //get from cin "5 centavos" and store 5 in centavos5
    int centavos5, centavos10, centavos25, centavos50, pesos1, pesos2, pesos5, pesos10;
    std::cout << "ingrese cantidad de monedas de 5 centavos" << std::endl;
    std::cin >> centavos5;
    std::cout << "ingrese cantidad de monedas de 10 centavos" << std::endl;
    std::cin >> centavos10;
    std::cout << "ingrese cantidad de monedas de 25 centavos" << std::endl;
    std::cin >> centavos25;
    std::cout << "ingrese cantidad de monedas de 50 centavos" << std::endl;
    std::cin >> centavos50;
    std::cout << "ingrese cantidad de monedas de 1 peso" << std::endl;
    std::cin >> pesos1;
    std::cout << "ingrese cantidad de monedas de 2 pesos" << std::endl;
    std::cin >> pesos2;
    std::cout << "ingrese cantidad de monedas de 5 pesos" << std::endl;
    std::cin >> pesos5;
    std::cout << "ingrese cantidad de monedas de 10 pesos" << std::endl;
    std::cin >> pesos10;

    double total = centavos5 * 0.05 + centavos10 * 0.1 + centavos25 * 0.25 + centavos50 * 0.5 + pesos1 + pesos2 * 2 + pesos5 * 5 + pesos10 * 10;
    std::cout << "Su monto total es de $" << total << std::endl;
        std::cout << "Su monto total es de " << floor(total) << ((floor(total) == 1) ? " peso":" pesos") << " y " << total - floor(total) << ((total - floor(total) == 0.01) ? " centavo.":" centavos.") << std::endl;

}

