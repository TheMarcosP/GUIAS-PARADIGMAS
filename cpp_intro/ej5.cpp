#include <iostream>

int gcd(int m, int n){
    int r; 
    while (n != 0) { 
        r = m % n; 
        m = n; 
        n = r;
    }
    return m; 
}

int main(void){
    int x, y, how_many;
    std::cout << "\nPROGRAM GCD C++";
    std::cout << "\nEnter how many GCD computations? ";
    std::cin >> how_many;
    for (int i = 0; i < how_many; ++i) {
        std::cout << "\nEnter two integers: ";
        std::cin >> x >> y;
        std::cout << "\nGCD(" << x << ", " << y << ") = " << gcd(x, y) << std::endl;
}
}