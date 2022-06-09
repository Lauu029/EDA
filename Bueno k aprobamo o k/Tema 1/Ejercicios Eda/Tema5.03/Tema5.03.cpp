// Nombre del alumno Laura Gómez Bodego
// Usuario del Juez VJ23


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include "deque_eda.h"
using namespace std;



// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	int tamCola;
	cin >> tamCola;
	if (tamCola == 0)
		return false;
	deque<int>valores;
	int valor;
	for (int i = 0; i < tamCola; i++)
	{
		cin >> valor;
		if (valor < 0) valores.push_front(valor);
		else valores.push_back(valor);
	}
	
	for (int i = 0; i < tamCola; i++)
	{
		cout << valores.front();
		valores.pop_front();
		if (i < tamCola - 1) cout << " ";
	}
	cout << endl;
	// escribir sol

	return true;

}

int main() {
	// Para la entrada por fichero.
	// Comentar para acepta el reto
#ifndef DOMJUDGE
	std::ifstream in("datos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 


	while (resuelveCaso())
		;


	// Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}
