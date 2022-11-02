#include <iostream>

class arreglo{
    int *arr;
    int size;
public:
    arreglo(int size): size(size) {
        arr = new int[size];
        for(int i=0; i<size; i++){
            arr[i] = 0;
        }
    };
    ~arreglo() {delete[] arr;};
    int getSize()const {return size;};
    int get(int i){return arr[i];};
    void set(int i, int val){arr[i] = val;};
    void print();
    int& operator[](int i) {return arr[i];}
    arreglo& operator=(arreglo& rhs); // ??? no pude

};




// Implementar una clase arreglo con las operaciones necesarias para poder ejecutar el siguiente programa:
int main() {
  arreglo a(7);

  a[0] = 3;
  a[1] = 6;
  a[2] = a[0] + a[1];
//   arreglo b = a; // ??? no pude
  std::cout << a[2] << std::endl;
}
