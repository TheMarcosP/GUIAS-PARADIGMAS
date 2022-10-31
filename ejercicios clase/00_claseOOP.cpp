#include <iostream>
#include <cstdlib>

class Point
{
    double x_ , y_;

    public:
        Point(double x, double y) : x_(x), y_(y) { // usar lista de inicializadores es mas eficiente
            std::cout << "point() " << std::endl;
        }
        ~Point(){
            std::cout << "~point()" << std::endl;
        }
};


//getters
// si lo unico que hacen es devolver el valor del atributo, directamente hacerlo publico

class Vector
{
    Point start;
    Point end;
    public:
        Vector(double x1,double y1,double x2, double y2) : start{x1,y1}, end{x2,y2}{ // en la lista de inicializadores llamo a los constructores de start y end
            std::cout << "~vector()" << std::endl;
        }
        Vector(Point start, Point end) : start(start), end(end){ //se puede hacer overloading, ahora puedo crear un vector con un cordenadas o con dos objetos Point
            std::cout << "~vector()" << std::endl;
        }
        ~Vector(){
            std::cout << "~vector()" << std::endl;
        }
};


//destructores
// por regla general se destruye en el orden inverso al que se construye


// herencia

// si un objeto no tiene constructor no la podes instanciar, solo lo podes heredar

class Printable{
    public:
        virtual void Print() const = 0; // (virtual tables) es un virtual puro, esta linea te obliga a implementar la funcion Print() en los hijos de esta clase

};

//virtual puro = 0 , o virtual implementado

//los destructores siempre tienen que ser virtuales,
//ej vehiculos f2500 fitito
class vehiculo{};
class f2500: public vehiculo {};

vehiculo* v = new f2500();
delete v;

// f2500 fitito son hijos de la clase vehiculo
// si el destructor de vehiculo no es virtual cuando hagas delete v, solo va a llamar al destructor de vehiculo y todo el resto no se destruye


int main(){
    return 0;
}