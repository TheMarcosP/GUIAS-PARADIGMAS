
// Implementar la clase Pieza y las clases Peon, Torre, Caballo, Alfil, Reina y Rey.

// Todas las piezas tienen una ubicación en un tablero.
// Todas las piezas se pueden mover.
// Escribir el código necesario para poder crear piezas de ajedrez, ubicarlas en una posición del tablero y moverlas.

#include <vector>
#include <tuple>
#include <cassert>
#include <iostream>
#include <cstdbool>

//location 
class pos{
    public:
        int x;
        int y;
        pos(int x, int y): x(x), y(y) {};
};

class Pieza{
    public:
    std::string nombre;
    pos posicion;
        Pieza(std::string nombre, pos posicion): nombre(nombre), posicion(posicion){};
        std::string getName(){return nombre;};
        virtual void moveTo(pos newPos) = 0;
};

class Peon: public Pieza{
    public:
        Peon(pos posicion): Pieza("Peon", posicion){};
        void moveTo(pos newPos){
            if(isValidMove(newPos)){
                posicion.x = newPos.x;
                posicion.y = newPos.y;
            }
            else{
                std::cerr << "invalid move" << std::endl;
            }

        }
        bool isValidMove(pos newPos){
            if (newPos.x -1 == posicion.x and newPos.y == posicion.y) return true;
            return false; 
        }

};

//por seguir

int main(){

    Peon peon(pos(1,1));
    assert(peon.getName() == "Peon");
    assert(peon.isValidMove(pos(2,1)) == true);
    assert(peon.isValidMove(pos(3,1)) == false);

    std::cout << "all test passed" << std::endl;
}
