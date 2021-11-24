
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <string>
#include "bintree_eda.h"
using namespace std;




// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    string stpreorden, stinorden;
    getline(stpreorden);
    cin >> stpreorden;
    cin >> stinorden;
    if (!cin)
        return false;

    vector<int> preorden;
    vector<int>inorden;
    int aux;
    for (int i = 0; i < stpreorden.length();i++) {
        aux = stoi(stpreorden[i]);
    }
        preorden.push_back(g);
    bintree<char> tree;
    tree = leerArbol('.');
    //cout << nodos(tree) << " " << hojas(tree) << " " << altura(tree) << endl;
}


int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("datos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif

    
    while (resuelveCaso());
        

    // Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    //system("PAUSE");
#endif

    return 0;
}
