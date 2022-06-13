// Nombre del alumno Laura Gómez Bodego
// Usuario del Juez VJ23


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include "bintree_eda.h"

using namespace std;
bool simetrico(bintree<char> hi, bintree<char>hd) {
    if (hi.empty() && hd.empty())return true;
    else if (!hi.empty() && !hd.empty())
        return simetrico(hi.left(), hd.right()) && simetrico(hi.right(), hd.left());
    else return false;
}
// función que resuelve el problema
bool resolver(bintree<char> tree) {
    if (tree.empty()) return true;
    else return simetrico(tree.left(), tree.right());

}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada

    bintree<char> tree = leerArbol('.');

    bool esSimetrico = resolver(tree);
    if(resolver(tree))cout << "SI\n";
    else cout<<"NO\n";
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