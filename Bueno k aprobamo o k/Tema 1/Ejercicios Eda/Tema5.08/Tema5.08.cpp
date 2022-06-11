// Nombre del alumno Laura Gómez Bodego
// Usuario del Juez VJ23


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include "queue_eda.h"

using namespace std;


// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
	int dato, pringado;
	cin >> dato;

	queue<int> cola, amigos;
	while (dato != -1) {
		cola.push(dato);
		cin >> dato;
	}
	cin >> pringado;
	cin >> dato;
	while (dato != -1) {
		amigos.push(dato);
		cin >> dato;
	}
	for (int i = 0; i < cola.size(); i++)
	{
		cout << cola.front() << " ";
		cola.push(cola.front());
		cola.pop();
	}
	cout << endl;
	cola.cuela(pringado, amigos);
	while(!cola.empty())
	{
		cout << cola.front() << " ";
		cola.pop();
	}
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