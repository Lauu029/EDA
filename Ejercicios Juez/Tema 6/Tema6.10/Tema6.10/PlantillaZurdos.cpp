
#include <iostream>
#include <iomanip>
#include <fstream>
#include "bintree_eda.h"
using namespace std;
//Almacena si es válido y guarda también el numero de nodos para comparar izq y dch
struct zurdo {
    bool esZ;
    int nNod;

};
template <class T>

//Complejidad lineal
zurdo esZurdo(const bintree<T>& tree) {

    if (tree.empty())
        return { true,0 };
    else if (tree.left().empty() && tree.right().empty())
        return { true,1 };
    else {
        zurdo aux, dch, iz;
        //almacena el numero de nodos de la izquierda y derecha
        iz = esZurdo(tree.left());
        dch = esZurdo(tree.right());

        //Si hay mas en izq que en dch y son todos zurdos da true
        aux.nNod = dch.nNod + iz.nNod + 1;//se le suma tambien la raiz
        aux.esZ = dch.esZ && iz.esZ && iz.nNod > dch.nNod;

        return aux;
    }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    bintree<char> tree;
    tree = leerArbol('.');

    if (esZurdo(tree).esZ)
        cout << "SI\n";
    else
        cout << "NO\n";
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
