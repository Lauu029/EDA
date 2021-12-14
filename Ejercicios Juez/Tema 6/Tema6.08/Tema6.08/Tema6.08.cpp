
#include <iostream>
#include <iomanip>
#include <fstream>
#include "bintree_eda.h"
using namespace std;

struct solucion {
    bool correcto;
    int menor;
    int mayor;
};
solucion arbolBusqueda(bintree<int>tree) {
   
    if (tree.empty()) {
        return{ true,-1,-1 };
    }
    else if (tree.left().empty() && tree.right().empty())
        return { true, tree.root(), tree.root() };
    else {
        if (!tree.left().empty() && !tree.right().empty()) {
            solucion busqueda;
            solucion izq = arbolBusqueda(tree.left());
            solucion der = arbolBusqueda(tree.right());

            busqueda.mayor = max(izq.mayor, der.mayor);
            busqueda.mayor = max(busqueda.mayor, tree.root());
            
            busqueda.menor = min(izq.menor, der.menor);
            busqueda.menor = min(busqueda.menor, tree.root());
            
            if (izq.correcto && der.correcto && izq.mayor < tree.root()&& der.menor >tree.root())
               busqueda.correcto= true;
            else busqueda.correcto= false;
            return busqueda;

        }
        else if(tree.right().empty()) {
            solucion busqueda=arbolBusqueda(tree.left());
            
            if (tree.root() > busqueda.mayor && busqueda.correcto)
                busqueda.correcto= true;
            else busqueda.correcto= false;
            busqueda.mayor = max(busqueda.mayor, tree.root());
            busqueda.menor = min(busqueda.menor, tree.root()); 
            return busqueda;
        }
        else if (tree.left().empty()) {
           solucion busqueda= arbolBusqueda(tree.right());
            if (tree.root() < busqueda.menor && busqueda.correcto)
                busqueda.correcto = true;
            else busqueda.correcto = false;
            busqueda.mayor = max(busqueda.mayor, tree.root());
            busqueda.menor = min(busqueda.menor, tree.root());
            return busqueda;
        }
    }    
}


// configuración, y escribiendo la respuesta
void resuelveCaso() {
   
    bintree<int> tree;
    tree = leerArbol(-1);
    solucion esBusqueda = arbolBusqueda(tree);

    if (esBusqueda.correcto)
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
