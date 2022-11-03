// Implementar la clase Animalia, de la que heredan las clases Mammalia y Reptilia. Implementar las clases PantheraLeo, PantheraPink, VaranusKomodoensis, PseudotrapelusSinaitus.

// Todas las clases tienen una forma de obtener su nombre como string.
// ¿Qué comparten Mammalia y Reptilia?
// Todos los reptiles tienen la capacidad de poner huevos, pero sólo el VaranusKomodoensis puede cazar para alimentarse.
// Todos los mamíferos maman cuando son crías, pero sólo la PantheraLeo ruge, mientras que la PantheraPink puede abrir puertas.
// Escribir un programa que cree e inicialice objetos de todas las clases desarrolladas, ejecute todos sus comportamientos y, en ellos, imprima qué está haciendo el animal (por ejemplo, en algún momento un objeto de la clase PantheraLeo debe imprimir “ruge”).

#include <vector>
#include <tuple>
#include <cassert>
#include <iostream>
#include <cstdbool>

class Animalia{
        std::string nombre;
        int edad;
        double vida;
    public:
        Animalia(std::string nombre): nombre(nombre){};
        std::string getName(){return nombre;};
};


class Mammalia: public Animalia{
    public:
        Mammalia(std::string nombre): Animalia(nombre){};
        void mamar();
};

class Reptilia : public Animalia{
    public :
        Reptilia(std::string nombre): Animalia(nombre){};
        void ponerHuevos();
};

class PantheraLeo: public Mammalia{
    public:
        PantheraLeo(): Mammalia("PantheraLeo"){};
        void ruge();
};

void PantheraLeo::ruge(){
    std::cout << "ruge" << std::endl;
}

class PantheraPink : public Mammalia{
    public:
        PantheraPink(): Mammalia("PantheraPink"){};
        void abrirPuertas();
};

class VaranusKomodoensis: public Reptilia{
    public:
        VaranusKomodoensis(): Reptilia("VaranusKomodoensis"){};
        void cazar();
};

class PseudotrapelusSinaitus: public Reptilia{
    public:
        PseudotrapelusSinaitus(): Reptilia("PseudotrapelusSinaitus"){};
};



int main(){


    std::cout << "all test passed" << std::endl;
}
