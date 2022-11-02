#include <vector>
#include <tuple>
#include <cassert>
#include <iostream>
#include <cstdbool>

// Implementar la clase Persona. Implementar las clases Estudiante, Profesor y Staff.

// Todas las personas tienen nombre y apellido como atributos y un método que devuelve su nombre como string (se puede sobrecargar el operador << —friend ostream& operator<<(ostream& os, const Persona& p);—para enviar una persona a stdout).
// Todos los estudiantes tienen una carrera asociada y un año de ingreso a dicha carrera.
// Todos los profesores tienen al menos departamento asociado y al menos una materia que dictar.

class Persona{
    std::string nombre;
    std::string apellido;
public:
    Persona(std::string nombre, std::string apellido): nombre(nombre), apellido(apellido) {};
    ~Persona() {};
    std::string getNombre(){return nombre;};
    std::string getApellido(){return apellido;};
    std::string getNombreCompleto(){return nombre + " " + apellido;};
    std::ostream& operator<<( Persona& p);
};


// Implementar la clase Persona. Implementar las clases Estudiante, Profesor y Staff.

class Estudiante: public Persona{
    std::string carrera;
    int ingreso;
public:
    Estudiante(std::string nombre, std::string apellido, std::string carrera, int anio_ingreso): Persona(nombre, apellido), carrera(carrera), ingreso(anio_ingreso) {};
    ~Estudiante() {};
    std::string getCarrera(){return carrera;};
    int getIngreso(){return ingreso;};
};

class Profesor: public Persona{
    std::string departamento;
    std::string materia;
public:
    Profesor(std::string nombre, std::string apellido, std::string departamento, std::string materia): Persona(nombre, apellido), departamento(departamento), materia(materia) {};
    ~Profesor() {};
    std::string getDepartamento(){return departamento;};
    std::string getMateria(){return materia;};
};


int main(){
    Persona *p1 = new Persona("Juan", "Perez");

    Estudiante *e1 = new Estudiante("Maria", "Gomez", "Ingenieria", 2015);
    Estudiante *e2 = new Estudiante("Pedro", "Gomez", "Ingenieria", 2015);

    Profesor *pr1 = new Profesor("Juan", "Perez", "Ingenieria", "Algoritmos");
    Profesor *pr2 = new Profesor("Juan", "Perez", "Ingenieria", "Algoritmos");

    std::cout << "all test passed" << std::endl;
}
