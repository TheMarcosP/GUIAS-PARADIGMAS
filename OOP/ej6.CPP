#include <vector>
#include <tuple>
#include <cassert>
#include <iostream>
#include <cstdbool>

// Que soy ??

// Se tienen definidas las clases A, B y C. Todos los métodos presentados son de instancia.

// class A	class B	class C
// super: A	super: B
//  void print() {
//    cout << “Soy una A\n”;
// }
// void doSomething() {
//    this->print();
// }
// void print() {
//    cout << “Soy una B\n”;
// }
// void print() {
//    cout << “Soy una C\n”;
// }
// void doSomething() {
//    this->B::print();
// }
    
// ¿Qué se imprime por consola, si dentro de un main usamos las siguientes expresiones por separado?

// new B().doSomething(); 
    //R: imprime "Soy una A" 
// new C().doSomething();
    //R: imprime "Soy una B"
// ¿Qué mensajes se envían? ¿A qué objetos? ¿Cómo se comprueba?
    //R: en la primera linea se envia doSomething() a B  y esa funcion llama a print de la funcion madre
    //R: en la segunda doSomething() tambien llama a print de la funcion madre


// LO INTERESANTE DE ESTO ES QUE POR MAS QUE SE SOBRESCRIBA UN METODO DE UNA CLASE MADRE TODAVIA SE PUEDE ACCEDER A ESTA

// Realizar los diagramas de objetos, de clases y de secuencia.

// Implementar

class A{
    public:
        void print() {
        std::cout << "Soy una A\n" << std::endl;
        }
        void doSomething() {
        this->print();
        }
};

class B : public A{
    public:
        void print(){
            std::cout << "Soy una B\n" << std::endl;
        }
        
};

class C : public B{
    public:
        void print(){
            std::cout << "Soy una B\n" << std::endl;
        }
        void doSomething(){
            this->B::print();
        }
        
};




int main(){
    B().doSomething();
    C().doSomething();

    std::cout << "all test passed" << std::endl;
}

