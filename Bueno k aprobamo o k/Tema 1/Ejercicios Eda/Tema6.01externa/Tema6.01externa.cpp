// Nombre del alumno Laura Gómez Bodego
// Usuario del Juez VJ23


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include "bintree_eda.h"

using namespace std;
void calculaArbol(bintree<char> datos, int& nod, int& hojas, int alt, int& max) {
	if (!datos.empty()) {
		nod++;
		if (datos.left().empty() && datos.right().empty()) { 
			hojas++; 

		}


		calculaArbol(datos.left(), nod, hojas, alt + 1, max);
		calculaArbol(datos.right(), nod, hojas, alt + 1, max);

	}
	else {
		if (max <= alt)max = alt;
		alt--;
	}
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
	// leer los datos de la entrada


	bintree<char> datos = leerArbol('.');
	// escribir sol
	int nod = 0, hojas = 0, max = 0;
	calculaArbol(datos, nod, hojas, 0, max);

	cout << nod << " " << hojas << " " << max;

	cout << endl;


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