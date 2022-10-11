// Consigna:
// permitir que la computadora elija un nro al azar entre 1 y 100
// y nos interrogue hasta que acertemos
// la respuesta de la computador en cada cas es Muy alto o Muy bajo
#include <iostream>


int main(void){
    int nro = 0;
    int nro_aleatorio = 0;
    srand(time(NULL));
    nro_aleatorio = rand() % 100 + 1;
    std::cout << "Ingrese un nro entre 1 y 100" << std::endl;
    std::cin >> nro;
    while (nro != nro_aleatorio){
        if (nro > nro_aleatorio){
            std::cout << "Muy alto" << std::endl;
        }
        else{
            std::cout << "Muy bajo" << std::endl;
        }
        std::cout << "Ingrese un nro entre 1 y 100" << std::endl;
        std::cin >> nro;
    }
    std::cout << "Acertaste" << std::endl;
    return 0;
}