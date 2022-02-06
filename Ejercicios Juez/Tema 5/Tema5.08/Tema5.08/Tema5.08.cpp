// Nombre del alumno Laura Gómez Bodego
// Usuario del Juez VJ23


#include <iostream>
#include <iomanip>
#include <fstream>
#include "queue_eda.h"

using namespace std;

// función que resuelve el problema
void leeDatos(queue<int>& fila) {
	int pers;
	cin >> pers;
	while (pers != -1) {
		fila.push(pers);
		cin >> pers;
	}

}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
	// leer los datos de la entrada

	queue<int> fila;
	leeDatos(fila);

	int pringao;
	cin >> pringao;

	queue<int> colegas;
	leeDatos(colegas);

	fila.escribeCola();
	cout << "\n";
	fila.cuela(pringao, colegas);
	fila.escribeCola();
	cout << "\n";
	// escribir sol


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