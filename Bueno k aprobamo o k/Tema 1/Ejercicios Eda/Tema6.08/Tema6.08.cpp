// Nombre del alumno Laura Gómez Bodego
// Usuario del Juez VJ23


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include "bintree_eda.h"

using namespace std;
// función que resuelve el problema
bool esBusqueda(bintree<int> tree, int min, int max) {
	if (!tree.empty()) {
		if (tree.root() <= min || tree.root() >= max) return false;
		else return esBusqueda(tree.left(), min, tree.root()) && esBusqueda(tree.right(), tree.root(), max);
	}
	else return true;

}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
	bintree<int>tree = leerArbol(-1);

	if (esBusqueda(tree, -1, 10000)) {
		cout << "SI\n";
	}
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
	system("PAUSE");
#endif

	return 0;
}