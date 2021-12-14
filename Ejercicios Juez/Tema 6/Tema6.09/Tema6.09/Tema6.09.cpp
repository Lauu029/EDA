
#include <iostream>
#include <iomanip>
#include <fstream>
#include "bintree_eda.h"
using namespace std;

struct solucion {
    int numNodos;
    int camiz;
    int camdr;
    int camFin;
};

solucion diametro(bintree<char>tree) {
    if (tree.empty())
        return { 0, 0, 0, 0};
    else if (tree.left().empty() && tree.right().empty())
        return { 1, 1, 1, 1};
    else {
        if (tree.left().empty()) {
            solucion sol = diametro(tree.right());
            sol.camdr++;
            sol.numNodos = max(sol.camdr, sol.camiz);
            return sol;
        }
        else if (tree.right().empty()) {
            solucion sol = diametro(tree.left());
            sol.camiz++;
            sol.numNodos = max(sol.camdr, sol.camiz);
            return sol;
        }
        else {
            solucion sol;
            solucion izq = diametro(tree.left());
            solucion der = diametro(tree.right());
            sol.numNodos = max(izq.numNodos, der.numNodos) + 1;
            sol.numNodos = izq.numNodos+ der.numNodos + 1;

            return sol;
        }
    }
}


// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    
    bintree<char> tree;
    tree = leerArbol('.');

    cout << diametro(tree).numNodos << endl;
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
    //system("PAUSE");
#endif

    return 0;
}
