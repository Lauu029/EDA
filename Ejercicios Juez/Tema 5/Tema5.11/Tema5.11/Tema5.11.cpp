// Nombre del alumno Laura Gómez Bodego
// Usuario del Juez VJ23


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

#include "list_eda.h"

using namespace std;
// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	list<int>listaValores;
	int valor, nElim;
	cin >> valor;
	while (valor != -1) {
		listaValores.push_back(valor);
		cin >> valor;
	}
	cin >> nElim;
	for (list<int>::iterator g = listaValores.begin(); g != listaValores.end(); ++g) {

		cout << *g << " ";
	}
	cout << "\n";
	listaValores.eliminaValor(nElim);
	for (list<int>::iterator g = listaValores.begin(); g != listaValores.end(); ++g) {

		cout << *g << " ";
	}
	// escribir sol
	cout << "\n";
	return true;

}

int main() {
	// Para la entrada por fichero.
	// Comentar para acepta el reto
#ifndef DOMJUDGE
	std::ifstream in("datos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 

	int numCasos;
	cin >> numCasos;
	for (int i = 0; i < numCasos; i++) { resuelveCaso(); }


	// Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}