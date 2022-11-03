// Complex

// Definir una clase Complex que implemente la clase de los números complejos. Definir los siguientes mensajes.

// re() e im() que devuelvan la parte real e imaginaria, respectivamente, del receptor.
// Complex(re, im) tal que defina un nuevo complex con re e im.
// sum(otroComplex) tal que el efecto de c.sum(d) sea actualizar c con la suma compleja entre él y d.
// abs() que devuelva el valor absoluto del receptor.
// +(infijo) que devuelva la suma compleja de sus dos argumentos.
// Implementar la clase.


#include <vector>
#include <tuple>
#include <cassert>
#include <iostream>
#include <cstdbool>
#include <cmath>

class complex{
    public:
        int re_;
        int im_;
        complex(int re, int im): re_(re), im_(im){};
        void sum(complex& other){
            re_ += other.re_;
            im_ += other.im_;
        };
        double abs(){
            return sqrt(pow(re_,2)+ pow(im_,2));
        };
        complex operator+(complex& complex2){
            return complex(re_+ complex2.re_,im_+complex2.im_);
        };
        void print(){
            std::cout << "re: " << re_ << "\nim: " << im_ << std::endl;
        }
};





int main(){

    //TEST operator+
    complex a(1,2);
    complex b(2,3);
    complex c = a + b;
    c.print();
    std::cout << "all test passed" << std::endl;
}
