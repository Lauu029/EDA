// Nombre del alumno Laura Gómez Bodego
// Usuario del Juez VJ23


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include "bintree_eda.h"
using namespace std;
// función que resuelve el problema
int resolver(bintree<int>arbol, int& max, int nExc) {
	int nEquip = 0;
	if (!arbol.empty()) {
		nExc += arbol.root();

		nEquip += resolver(arbol.left(), max, nExc);
		nEquip += resolver(arbol.right(), max, nExc);

		if (nExc > max) max = nExc;

		if (arbol.root() != 0 && nEquip == 0)  nEquip++;

	}
	return nEquip;

}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
	bintree<int> tree = leerArbol(-1);
	int max = 0;
	int salida = resolver(tree, max,0);
	cout <<salida << " " << max << endl;
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