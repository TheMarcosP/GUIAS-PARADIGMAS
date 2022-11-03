#include <vector>
#include <tuple>
#include <cassert>
#include <iostream>
#include <cstdbool>

// Explicar, desde el punto de vista de C++, las diferencias entre estructuras y clases.

// la diferencia entre una estructura y una clase es que la estructura es publica por defecto y la clase es privada por defecto

// Explicar las diferencias entre la estructura


struct a {
  int i, j, k;
};
// y la clase
class a {
  int i, j, k;
};


// Explicar por qué la declaración de la clase no es útil.
// no es util porque no se puede instanciar y no se puede acceder a sus atributos

// ¿Cómo puede utilizarse la palabra clave public para cambiar la declaración de la clase en una declaración equivalente a struct a?
// se puede utilizar la palabra clave public para cambiar la declaracion de la clase en una declaracion equivalente a struct a

class a {
  public:
    int i, j, k;
};


int main(){


    std::cout << "all test passed" << std::endl;
}
