#include <iostream>
#include <fstream>
#include "bintree_eda.h"
using namespace std;

struct nav {
    int cd;
    int trNav;
};

//Orden lineal 
nav tramosNavegables(bintree<int> arb) {
    //si el arbol no tiene hijos, su caudal es 1 y no hay tramos navegables
    if (arb.left().empty() && arb.right().empty()) {
        return{ 1,0 };
    }
    
    if (!arb.empty()) {
        nav aux;
        //si no hay hijo izq y si dcho
        if (!arb.left().empty() && !arb.right().empty()) {
            nav izq = tramosNavegables(arb.left());
            nav dch = tramosNavegables(arb.right());
            aux.cd = izq.cd + dch.cd - arb.root();
            aux.trNav = izq.trNav + dch.trNav;
            
        }
        //si solo hay hijo izq
        else if (arb.right().empty()) {
            aux = tramosNavegables(arb.left());
            //le resta la posible presa(si no hay es 0 y no se resta nada)
            aux.cd = aux.cd-arb.root();
        }
        //si existen los dos hijos
        else if(arb.left().empty())
        {
            aux = tramosNavegables(arb.right());
            aux.cd = aux.cd - arb.root();
        }
        //ahora compruebo si el caudal es suficiente para que sea navegable y si es negativo lo ajusto
        if (aux.cd < 0)aux.cd = 0;
        if (aux.cd >= 3)aux.trNav++;
        return aux;

    }

}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso(){
	bintree<int> arb;
	arb = leerArbol(-1); // -1 es la repr. de arbol vacio
    nav solucion = tramosNavegables(arb);

    //escribo la solución
    //si el caudal es mayor que tres le resta uno que se ha sumado extra y no corresponde a ningun afluente pporque es el nodo raiz
    if (solucion.cd >= 3)
        cout << solucion.trNav - 1 << endl;
    else
        cout << solucion.trNav << endl;
	
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

