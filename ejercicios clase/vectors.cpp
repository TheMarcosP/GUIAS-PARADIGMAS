#include <vector>
#include <iostream>
#include <cstdlib>

using namespace std;
int main(void){
    vector<string> names;

    //names.reserve(3); sirve para reservar espacio en memoria para 3 elementos. si no se reserva espacio, el vector se va a ir agrandando a medida que se agregan elementos. reservar entonces es mas eficiente si ya se sabe cuantos elementos 

    names.push_back( "Adam");
    names.push_back( "Eve");
    names.push_back( "Seth");
    names.push_back( "William");
    

    //no es optimo
    // int i = 0;
    // for (i; i < names.size(); i++){
    //     cout << names[i] << endl;
    // }

    auto it = names.begin();
    //names.erase(each);
    //names.pop_back();
    names.insert(it, "hola");
    // cout << "it vale :" << *it << endl;

    for (auto each = names.begin(); each != names.end(); each++){
        cout << *each << endl;
    }
}