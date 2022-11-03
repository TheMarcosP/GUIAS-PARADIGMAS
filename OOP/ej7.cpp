// Es Uno u Otro

// Se tienen las clases A, B, C, D donde A es superclase de B y C, y C es superclase de D, y no hay otra relación de herencia entre ellas cuatro. ¿Cómo debe hacerse para conseguir que valga lo siguiente?

// x.esA() debe devolver true para cada instancia x de A o de sus subclases, y false para cada x que no sea instancia de A ni de sus subclases.
// x.esBoC() debe devolver true para cada instancia x de B o de C, o de las subclases de ambas, pero false para cada x que no sea instancia de B ni de C ni de subclases de ellas.
// x.esSoloC() debe
// Realizar los diagramas de objetos, y de clases
#include <vector>
#include <tuple>
#include <cassert>
#include <iostream>
#include <cstdbool>
#include <cassert>

class A{
    public:
    bool esA(){return true;};
    bool esBoC(){return false;};
    bool esSoloC(){return false;};
};

class B : public A{
    public:
        bool esBoC(){return true;};
};

class C : public B{
    public:
        bool esSoloC(){return true;};
};

int main(){
    A x = A();
    assert(x.esA());
    assert(!x.esBoC());
    assert(!x.esSoloC());

    B y = B();
    assert(y.esA());
    assert(y.esBoC());
    assert(!y.esSoloC());

    C z = C();
    assert(z.esA());
    assert(z.esBoC());
    assert(z.esSoloC());
    std::cout << "all test passed" << std::endl;
}


