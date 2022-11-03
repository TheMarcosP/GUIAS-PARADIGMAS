class Engine{
    private:
        vector<Oxigen*> o_;
        vector<Hidracina*> h_;
    public:
        Engine(vector<Oxigeno*>& o, vector<Oxigeno*>& h) : o_(o) , h_(h){

        };    
}

// esto no esta muy bueno

class Engine{
    private:
        Combustible c_;
    public:
        Engine( Combustible& c) : c_(c){

        }
}





int main(){
    return 0;
}


// In C++, there are three access specifiers:

// public - members are accessible from outside the class
// private - members cannot be accessed (or viewed) from outside the class
// protected - members cannot be accessed from outside the class, however, they can be accessed in inherited classes. 
//https://www.w3schools.com/cpp/cpp_access_specifiers.asp#:~:text=In%20C%2B%2B%2C%20there%20are,be%20accessed%20in%20inherited%20classes.

// las interfaces son clases que definen comportamiento. se crean con clases con metodos virtuales puros
// Cantor Volar
// pajaro hereda comportamiento de ambas
// avion solo de volar



// usando unique_pointers no hace falta usar delete 