#include <vector>
#include <tuple>
#include <cassert>
#include <iostream>
#include <cstdbool>

// Escribir una función que dado una tupla de pares de strings representando el nombre de una persona y el nombre de alguno de sus ancestros (padre, madre, abuelo, bisabuelo) y una tupla con dos nombres que aparecen en el vector, devuelva verdadero solamente si el primer nombre es ancestro del segundo (tener encuenta que si A es ancestro de B y B es ancestro de C, necesariamente A es ancestro de C).

// Asumir que la entrada está “bien formada”, es decir, si A es ancestro de B y B es ancestro de C, C no puede tener un “camino de ancestros” hasta A (ej, una persona no puede ser nieto de su padre).

// Ejemplo: {pares}, {persona1}, {persona2} –> {respuesta}


// [<"Abraham", "Homero">, <"Homero", "Bart">, <"Marge", "Lisa">], "Homero", "Bart" --> _verdadero_
// [<"Abraham", "Homero">, <"Homero", "Bart">, <"Krusty", "Sophie">], "Krusty", "Bart" --> _falso_
// [<"Abraham", "Homero">, <"Homero", "Bart">, <"Homero", "Lisa">], "Lisa", "Bart" --> _falso_

bool isAncestor(std::)


int main(){


    std::cout << "all test passed" << std::endl;
}

