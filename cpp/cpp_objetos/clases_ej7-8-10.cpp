#include <cassert>
#include <iostream>
#include <cstdbool>
#include <cmath>
// Desarrollar una clase vector que contenga lo siguiente:

// Sus coordenadas (, ), como fin del vector, suponiendo que siempre el inicio está en el par (0, 0).
// Un constructor que recibe estos dos valores y los almacena en los miembros correspondientes.
// Una función que imprime por pantalla el valor de las coordenadas del vector.
// Una función que devuelve la norma del vector.
// Una función que devuelve el cuadrante donde se encuentra el vector.
// Escribir un programa que permita tomar coordenadas introducidas por el usuario, y que imprima por pantalla la norma del vector y el cuadrante donde se encuentra.


class Vector{
    public:
        const int x_;
        const int y_;
        Vector(int x, int y): x_(x), y_(y) {std::cout << "Vector created" << std::endl;};
        ~Vector() {std::cout << "Vector destroyed" << std::endl;};
        int getX(){return x_;};
        int getY(){return y_;};
        void getVector();
        double getNorm();
        int getCuadrante();
        //ej 8 Tomar la clase vector desarrollada en el ejercicio anterior, y agregar una función constructora de copia que copie todos sus miembros.
        Vector(Vector* vec): x_(vec->x_), y_(vec->y_) {std::cout << "Vector created" << std::endl;};
        //ej 10 Escribir un programa que sobrecargue el operador aritmético - para poder restar vectores (clase definida en el ejercicio 7). Implementar el siguiente código para comprobar la correcta implementación del ejercicio:
        // define operator-
        Vector operator-(const Vector& rhs) const
        {
            return Vector(x_ - rhs.x_, y_ - rhs.y_);
        }
};

double Vector::getNorm(){
    return sqrt(pow(x_, 2) + pow(y_, 2));
}

int Vector::getCuadrante(){
    if(x_>0 and y_>0) return 1;
    if(x_<0 and y_<0) return 2;
    if(x_<0 and y_>0) return 3;
    if(x_>0 and y_<0) return 4;
    return 0;
}


int main(){
    Vector *v1 = new Vector(1, 1);
    assert(v1->getNorm() == sqrt(2));
    assert(v1->getCuadrante() == 1);

    //ej 8
    Vector *v2 = new Vector(v1);
    assert(v2->getX() == 1);
    assert(v2->getY() == 1);

    //ej10
    Vector v3 = *v2 - *v1;
    assert(v3.getX() == 0);
    assert(v3.getY() == 0);

    delete v2;
    delete v1;
    std::cout << "all test passed" << std::endl;
}


// sin punteros

// int main(){
//     Vector v1(1, 1);
//     assert(v1.getNorm() == sqrt(2));
//     assert(v1.getCuadrante() == 1);

//     //ej 8
//     Vector v2(v1);
//     assert(v2.getX() == 1);
//     assert(v2.getY() == 1);

//     //ej10
//     Vector v3 = v2 - v1;
//     assert(v3.getX() == 0);
//     assert(v3.getY() == 0);

//     std::cout << "all test passed" << std::endl;
// }
