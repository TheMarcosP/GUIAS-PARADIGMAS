#include <iostream>


void incrementarValor(int acc)
{
    acc += 14;
    std::cout << "acc en incrementarValor " << acc << std::endl;
}


void incrementarReferencia(int& acc)
{
    acc += 14;
    std::cout << "acc en incrementarReferencia " << acc << std::endl;
}


int main(void)
{
    int var = 28;

    incrementarValor(var);
    std::cout << "var en main " << var << std::endl;

    incrementarReferencia(var);
    std::cout << "var en main " << var << std::endl;

    return 0;
}
