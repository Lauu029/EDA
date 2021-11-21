
#include <iostream>
#include <iomanip>
#include <fstream>
#include "bintree_eda.h"
using namespace std;




// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    
    bintree<int> tree;
    tree = leerArbol(-1);
    int nod = 0;
    int prof = 1;
    //Inicializo el maximo a un valor suficientemente grande para que la primera vez que encuentre
    //un multiplo, la prof sea mayor
    int proFinal = 100;
    tree.nodoValido(nod, prof, proFinal);
    if (nod==0)
        cout << "NO HAY\n";
    else {
        cout << nod << " " << proFinal << endl;
    }
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
