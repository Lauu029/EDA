// Nombre del alumno Laura Gómez Bodego
// Usuario del Juez VJ23


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include "bintree_eda.h"

using namespace std;
// función que resuelve el problema
int nodoSingular(bintree<int>tree, int anteriores, int& singulares) {
    if (!tree.empty()) {
        anteriores += tree.root();
        int izq = nodoSingular(tree.left(), anteriores, singulares);
        int der = nodoSingular(tree.right(), anteriores, singulares);

        if (izq + der == anteriores - tree.root()) singulares++;
        return izq + der + tree.root();
    }
    else return 0;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    bintree<int>tree = leerArbol(-1);
    int sing = 0;
    int a = nodoSingular(tree, 0, sing);
    cout << sing << endl;
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("datos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 


    int numCasos;
    std::cin >> numCasos;
    for (int i = 0; i < numCasos; ++i)
        resuelveCaso();


    // Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif

    return 0;
}