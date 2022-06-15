// Nombre del alumno Laura Gómez Bodego
// Usuario del Juez VJ23


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include "bintree_eda.h"

using namespace std;

struct sol {
	bool esZurdo;
	int hijos;
};
// función que resuelve el problema
sol resolver(bintree<char>tree, int h) {

	if (tree.empty())
		return { true,0 };
	else if (tree.left().empty() && tree.right().empty())return { true,1 };
	else {
		sol dev;
		sol izq = resolver(tree.left(), h + 1);
		sol der = resolver(tree.right(), h + 1);

		dev.hijos = der.hijos + izq.hijos + 1;


		dev.esZurdo = izq.hijos > der.hijos && der.esZurdo && izq.esZurdo;
		return dev;
	}
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
	bintree<char> tree = leerArbol('.');

	sol a = resolver(tree, 0);
	if (a.esZurdo)cout << "SI\n";
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