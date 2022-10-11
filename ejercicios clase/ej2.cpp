#include <iostream>

// memorizar un nro en nuestra mente y hacer que la computadora adivine con la misma logica anterio
// nostros respondemos muy bajo, muy alto o acertaste

int main(){

    std::string guess = "";
    int intento = 0;
    int min = 0;
    int max = 100;
    do{
        intento++;
        srand(time(NULL));
        int nro_aleatorio = rand() % (max - min) + min;
        std::cout << "intento "<< intento << ", la compu elegio " << nro_aleatorio << ", es correcto?\n+ -> muy alto\n- -> muy bajo\nx -> correcto" << std::endl;
        std::cin >> guess;
        if (guess == "+"){
            max = nro_aleatorio;
        }else if (guess == "-"){
            min = nro_aleatorio;
        }else if (guess == "x"){
            std::cout << "el 🤖 adivino en " << intento << " intentos" << std::endl;
            break;
        }

    }while (true);
    

}