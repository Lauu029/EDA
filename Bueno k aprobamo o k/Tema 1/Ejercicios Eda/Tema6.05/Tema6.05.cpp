// Nombre del alumno Laura Gómez Bodego
// Usuario del Juez VJ23


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include "bintree_eda.h"
using namespace std;
// función que resuelve el problema
void resolver(bintree<int> familia, bool& esFamilia, int gen, int& generaciones) {
	if (!familia.empty()) {
		int padre = familia.root();
		int hijo1 = -1, hijo2 = -1;
		if (!familia.left().empty()) hijo1 = familia.left().root();
		if (!familia.right().empty()) hijo2 = familia.right().root();
		if (hijo1 != -1) {
			if (padre - 18 >= hijo1) {
				if (hijo2 != -1) {
					if (hijo2 + 2 > hijo1) esFamilia = false;
				}
			}
			else
				esFamilia = false;
		}
		else if (hijo2 != -1) esFamilia = false;
		if (esFamilia) {
			if (gen > generaciones)generaciones = gen;
			resolver(familia.left(), esFamilia, gen + 1, generaciones);
			resolver(familia.right(), esFamilia, gen + 1, generaciones);
		}
	}
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
	bintree<int>familia;
	familia = leerArbol(-1);
	bool esFamilia = true;
	int generaciones = 0;
	resolver(familia, esFamilia, 1, generaciones);
	if (esFamilia) cout << "SI " << generaciones << endl;
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