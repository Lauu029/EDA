// Nombre del alumno Laura Gómez Bodego
// Usuario del Juez VJ23


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include "bintree_eda.h"

using namespace std;
// función que resuelve el problema
int resolver(bintree<int> tree, int& nTramos) {
	if (tree.empty()) return 0;
	else {
		int caudal, cIz, zDr;
		cIz = resolver(tree.left(), nTramos);
		zDr = resolver(tree.right(), nTramos);
		if (tree.left().empty() && tree.right().empty())return 1;
		caudal = cIz + zDr;
		if (caudal- tree.root() >= 3)
			nTramos++;
		if (caudal - tree.root() < 0)
			return 0;
		else return caudal - tree.root() ;
	}
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
	bintree<int>tree = leerArbol(-1);
	int nTramos = 0;
	int sol = resolver(tree, nTramos);

	if (sol >= 3)nTramos--;
	cout << nTramos << endl;
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