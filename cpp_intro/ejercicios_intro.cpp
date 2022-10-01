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


/*
ej2
Escribir un programa que reciba tres enteros y devuelva el resultado de la siguiente fórmula: sum = (a+b+c)*2 + c

*/

void valores(int a, int b, int c) {
    int sum = (a + b + c) * 2 + c;
    std::cout << sum << std::endl;
}

/*
ej3
#include <iostreem.h>

using namespace standard;

int main()
{
int a = 1, b = 2, c = 3,
cout << a + b * << " = a + b";
cout <<"\nc = " << c;
}


#include <iostream>

using namespace std;

int main()
{
int a = 1, b = 2, c = 3;
cout << a + b  << " = a + b";
cout <<"\nc = " << c;
}

*/
void corregido(){
    int a = 1, b = 2, c = 3;
    std::cout << a + b  << " = a + b";
    std::cout <<"\nc = " << c << std::endl;
}
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


int main(){
    //ej1
    // printnormal("She sells sea shells by the seashore.");
    // printline("shess sells sea shells by the seashore.");
    // printbox("She sells sea shells by the seashore.");

    //ej2
    // valores(1, 2, 3);

    //ej3
    //corregido();
    
    //ej4
    //contador();

    //ej13
    ej15();

}