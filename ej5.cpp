// Futbol

// En una memorable publicidad, el fútbol se definía como «un grupo de hombres en paños menores corriendo detrás de una pelota». Siguiendo con el agudo análisis publicista del arte del balonpié, se pueden distinguir tres tipos de jugadores: los que antes de correr protestan y corren sólo para quitar la pelota (a los que llamaremos defensores), los que sólo corren para patear al arco (a los que llamaremos delanteros) y la extraña especie de aquellos pocos privilegiados que pueden tomar el esférico con sus manos (arqueros).

// class Jugador	class Defensor
// super: Jugador
// void jugar() {
//    this->correrLaPelota();
// }
// void jugarrCon(Jugador& unJugador ) {
//    unJugador.jugar();
//    this->jugar();
// }
// void jugar() {
//   this->protestar();
//   this->Jugador::jugar();
//   this->quitarPelota();
// }
// class Delantero	class Arquero
// super: Jugador	super: Jugador
// void jugar() {
//  this->Jugador::jugar();
//  this->patearAlArco();
// }
// void jugar() {
//    this->atajar;
// }
// Si asumimos que todos los métodos que no aparecen en la tabla están implementados en la misma clase donde son invocados y contamos con las siguientes ya mı́ticas instancias en aquella publicidad:


// palermo = new Delantero();
// ibarra = new Defensor();
// garcia = new Arquero();
// Responder las siguientes preguntas respecto de la ejecución de las expresiones:

// garcı́a.jugarCon(palermo); 
// ibarra.jugar();           

// ¿Cuántas veces se manda el mensaje jugar() y a qué objetos?
    // el mensaje jugar() se manda 4 veces en total:
    // en la primera linea se lo llama dos veces una a palermo.jugar() y otra a garcia.jugar()
    // en la segunda linea se lo llama una vez a ibarra.jugar() que adentro tiene otro jugar()


// ¿Cuántas veces se manda el mensaje correrLaPelota() y a qué objetos?
    // dos veces palermo.jugar() y en el jugar() de adentro de ibarra.jugar()

// Realizar los diagramas de objetos, de clases y de secuencia.
    //en hoja

// Implementar

#include <iostream>

class Jugador {
    public:
        Jugador(){};
        virtual void jugar();
        void jugarCon(Jugador& unJugador);
        void correrLaPelota();
};

void Jugador::jugar() {
    std::cout << "Jugador::jugar()" << std::endl;
    correrLaPelota();
}

void Jugador::jugarCon(Jugador& unJugador) {
    unJugador.jugar();
    this->jugar();
}

void Jugador::correrLaPelota() {
   std::cout << "correr la pelota" << std::endl;
}


class Arquero : public Jugador {
    public:
    Arquero(){};
    void atajar() {
        std::cout << "atajar" << std::endl;
    };
    void jugar() {
        std::cout << "Arquero::jugar()" << std::endl;
        atajar();
    }

};

class Delantero: public Jugador {
    public:
    Delantero(){};
    void patearAlArco() {
        std::cout << "patear al arco" << std::endl;
    };
};

class Defensor: public Jugador {
    public:
    Defensor(){};
    void protestar() {
        std::cout << "protestar" << std::endl;
    };
    void quitarPelota() {
        std::cout << "quitar pelota" << std::endl;
    };
    void jugar() {
        std::cout << "Defensor::jugar()" << std::endl;
        protestar();
        Jugador::jugar();
        quitarPelota();
    }
};

int main(){
    Arquero garcia = Arquero();
    Delantero palermo = Delantero();
    Defensor ibarra = Defensor();
    
    garcia.jugarCon(palermo);
    ibarra.jugar();

    //se vefirican las respuestas
}