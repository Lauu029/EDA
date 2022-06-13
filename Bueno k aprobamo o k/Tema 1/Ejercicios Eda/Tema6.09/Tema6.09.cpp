// Nombre del alumno Laura Gómez Bodego
// Usuario del Juez VJ23


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include "bintree_eda.h"
using namespace std;
// función que resuelve el problema
int resolver(bintree<char> tree, int& diam) {
	if (!tree.empty()) {
		int diamIzq = resolver(tree.left(), diam);
		int diamDer = resolver(tree.right(), diam);

		if (diam <= diamIzq + diamDer) diam = 1+ diamIzq + diamDer;

		if (diamIzq > diamDer)return diamIzq + 1;
		else return diamDer + 1;
	}
	else return 0;

}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
	bintree<char>arbol = leerArbol('.');
	int diam = 0;
	int a = resolver(arbol, diam);
	cout << diam << endl;
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