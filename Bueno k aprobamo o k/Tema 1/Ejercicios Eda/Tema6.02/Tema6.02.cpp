
#include <iostream>
#include <iomanip>
#include <fstream>
#include "bintree_eda.h"
using namespace std;

void resolver(bintree<int> tree,vector<int>& barrera) {
    if (!tree.empty()) {
        if (tree.left().empty() && tree.right().empty()) {
            barrera.push_back(*tree.begin());
        }
        else {
            resolver(tree.left(), barrera);
            resolver(tree.right(), barrera);
        }
    }
}
void resuelveCaso() {

    bintree<int> tree;
    vector<int>barrera;
    tree = leerArbol(-1);
    resolver(tree, barrera);
    for (int i = 0; i < barrera.size(); i++)
    {
        cout << barrera[i] << " ";
    }
    cout << endl;
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
