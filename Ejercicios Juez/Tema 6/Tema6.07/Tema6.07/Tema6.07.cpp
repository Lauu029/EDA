
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include "bintree_eda.h"
using namespace std;
bool arbolSimetrico(bintree<char> izq, bintree<char> dr)
{
    //los dos son vacíos
    if (izq.empty() && dr.empty())
        return true;
    else if ((izq.empty() && !dr.empty()) || (dr.empty() && !izq.empty()))
        return false;
    else
        return arbolSimetrico(izq.left(), dr.right()) && arbolSimetrico(izq.right(), dr.left());
}
bool simetrico(bintree<char>tree) {
    if (tree.empty())
        return true;
    else
        return arbolSimetrico(tree.left(), tree.right());
}



// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    int n;
    bintree<char> tree;
    tree = leerArbol('.');
    bool aSimetrico = simetrico(tree);
    if (aSimetrico)cout << "SI\n";
    else cout << "NO\n";
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
