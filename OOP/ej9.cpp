#include <vector>
#include <tuple>
#include <cassert>
#include <iostream>
#include <cstdbool>
#include <map>
// Mars Rover

// Somos parte del equipo que desarrolla los equipos de exploración remota de Marte en la NASA y tenemos que desarrollar el sistema que controle el Mars Rover. Para eso, se asume que la superficie de Marte es un plano y que se usan puntos para posicionar al Mars Rover en dicho plano, más un punto cardinal que indica hacia donde apunta. Debido a que Marte está muy lejos, siempre se le envían al Mars Rover un conjunto de comandos empaquetados en un string, donde cada caracter es un comando.

// Tener en cuenta que:

// La comunicación puede tener problemas y pueden llegar comandos erróneos en cuyo caso se espera que no se sigan procesando los comandos restantes.
// El Mars Rover siempre empieza en un punto inicial (x, y) y apuntando a un punto cardinal (N, S, E, O)
// El rover recibe una secuencia de caracteres que representan comandos sobre como moverse
// Los comandos pueden ser:

// f = mover hacia adelante un punto (forward)
// b = mover hacia atrás un punto (backwards)
// l = rotar 90 grados a la izquierda
// r = rotar 90 grados a la derecha

// Construir esta funcionalidad haciendo TDD

class MarsRover{
    std::map<char,int> pos;
    // ciruclar data structure for cardinal points
    std::vector<char> cardinals = {'N','E','S','O'};;
    
    public:
        MarsRover(int x,int y, char cardinal){
            pos['x'] = x;
            pos['y'] = y;
            pos['c'] = cardinal;
            };

        void moveFoward(){
            if(pos['c'] == 'N'){
                pos['x']++;
            }else if(pos['c'] == 'S'){
                pos['x']--;
            }else if(pos['c'] == 'E'){
                pos['y']++;
            }else if(pos['c'] == 'O'){
                pos['y']--;
            }
        };

        void moveBackwars(){
            if(pos['c'] == 'N'){
                pos['x']--;
            }else if(pos['c'] == 'S'){
                pos['x']++;
            }else if(pos['c'] == 'E'){
                pos['y']++;
            }else if(pos['c'] == 'O'){
                pos['y']--;
            }
        };
        


        void rotateLeft(){
            int index = 0;
            for(int i = 0; i < cardinals.size(); i++){
                if(cardinals[i] == pos['c']){
                    index = i;
                }
            }
            if(index == 0){
                pos['c'] = cardinals[cardinals.size()-1];
            }else{
                pos['c'] = cardinals[index-1];
            }
        };

        void rotateRight(){
            int index = 0;
            for(int i = 0; i < cardinals.size(); i++){
                if(cardinals[i] == pos['c']){
                    index = i;
                }
            }
            if(index == cardinals.size()-1){
                pos['c'] = cardinals[0];
            }else{
                pos['c'] = cardinals[index+1];
            }
        };
        

        std::tuple<int,int, char> getPosition(){
            return std::make_tuple(pos['x'],pos['y'],pos['c']);
        }

        void processCommands(std::string commands){
            for (auto command : commands){
                switch (command){
                    case 'f':
                        moveFoward();
                        break;
                    case 'b':
                        moveBackwars();
                        break;
                    case 'l':
                        rotateLeft();
                        break;
                    case 'r':
                        rotateRight();
                        break;
                    default:
                        return;
                }
            }
        }
};

// Implementar


int main(){

    MarsRover rover(0,0,'N');
    assert(rover.getPosition() == std::make_tuple(0,0,'N'));
    rover.moveFoward();
    assert(rover.getPosition() == std::make_tuple(1,0,'N'));
    rover.moveBackwars();
    assert(rover.getPosition() == std::make_tuple(0,0,'N'));
    rover.rotateLeft();
    assert(rover.getPosition() == std::make_tuple(0,0,'O'));
    rover.rotateRight();
    assert(rover.getPosition() == std::make_tuple(0,0,'N'));
    rover.rotateRight();
    assert(rover.getPosition() == std::make_tuple(0,0,'E'));
    rover.rotateRight();
    assert(rover.getPosition() == std::make_tuple(0,0,'S'));
    rover.rotateRight();
    assert(rover.getPosition() == std::make_tuple(0,0,'O'));

    rover.processCommands("ffrff");
    assert(rover.getPosition() == std::make_tuple(2,-2,'N'));


    std::cout << "all test passed" << std::endl;
}
