#include <algorithm>
#include <iostream>
#include <map> 
#include <string>
#include <vector> 

using namespace std; 

class Producto{
    string tipo_; 
    string valorNut_; 
    int id_; 

    public: 
        Producto(string t, string v, int i): tipo_(t), valorNut_(v), id_(i){}
        ~Producto(){}


};


class Stock{
   Producto *item_; 
   int disponible_; 
   Producto *sustituto_;  
   int minStock_; 

   public: 
    Stock(Producto *i, int d, Producto *s, int m): item_(i), disponible_(d), sustituto_(s), minStock_(m){}
    ~Stock(){}

    void modificarDisponible(int n){
        disponible_ += n; 
    }

    void sustituto(Producto *p){
        sustituto_ = p; 
    }

    Producto* getSustituto(){return sustituto_; }

    bool isBelowMin(){
        if(disponible_ < minStock_){
            return true; 
        }return false; 
    }

    int getMinStock(){return minStock_;}

    int getDisponible(){return disponible_;}




}; 


class Operacion{
    Producto *item_; 
    int cantidad_; 
    string tipo_; 

    public: 
        Operacion(Producto *i, int c, string t): item_(i), cantidad_(c), tipo_(t){}
        ~Operacion(){}
}; 


class Almacen{
    map<Producto*, Stock*> stocks_; 
    vector<Operacion*> libroContable_; 


    public: 
        Almacen(){}
        ~Almacen(){}

        void addProducto(Producto *producto, int cantidad, int min){
            Stock *s = new Stock(producto, cantidad, NULL, min); 
            
            stocks_[producto] = s; 
        }

        void sell(Producto *producto, int cantidad){
            Operacion *o = new Operacion(producto, cantidad, "vender"); 
            stocks_[producto]-> modificarDisponible(-cantidad);
            libroContable_.emplace_back(o);
        }

         void buy(Producto *producto, int cantidad){
            Operacion *p = new Operacion(producto, cantidad, "comprar"); 
            stocks_[producto]-> modificarDisponible(cantidad);
            libroContable_.emplace_back(p);
        }

        void setSustituto(Producto *producto, Producto *p){
            stocks_[producto]-> sustituto(p); 
        }

        vector<Producto*> getLowStock(){
            vector<Producto*> resultado; 
            for(auto const &[key, value]: stocks_){
                if(value->getSustituto() == NULL ){
                    if(value-> isBelowMin()){
                        resultado.emplace_back(key); 
                    }
                }if(value->getSustituto() != NULL ){
                    Producto *productoSustituto= value-> getSustituto(); 
                    int a = (stocks_[productoSustituto]-> getDisponible()) + (value-> getDisponible());
                    if(a< value-> getMinStock()){
                        resultado.emplace_back(key); 
                    }
                } 
            }
            return resultado; 
        }
}; 

int main(){
    Almacen *almacen = new Almacen(); 

    Producto *coca = new Producto("bebida", "aaa", 123); 
    Producto *pepsi = new Producto("bebida","bbb", 124 ); 

    almacen-> addProducto(coca, 20, 10);
    almacen-> addProducto(pepsi, 8, 4); 
    almacen-> sell(coca, 5); 
    almacen-> buy(coca, 5); 
    almacen-> setSustituto(coca, pepsi); 

     


    return 0; 
}
