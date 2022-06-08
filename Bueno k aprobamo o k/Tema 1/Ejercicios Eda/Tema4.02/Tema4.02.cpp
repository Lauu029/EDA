// Nombre del alumno Laura Gómez Bodego
// Usuario del Juez VJ23

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include "Polinomio.h"

using namespace std;


// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	int coef, exp;
	cin >> coef >> exp;

	if (!std::cin)
		return false;

	bool finLectura = false;
	Polinomio p;
	while (!finLectura) {
		if (coef == 0 && exp==0) {
			finLectura = true;
			continue;
		}
		p.add({ exp,coef });
		cin >> coef >> exp;
	}

	int numVal;
	cin >> numVal;
	int v;
	for (int i = 0; i < numVal; i++)
	{
		cin >> v;
		cout << p.calculate(v);
		if (i < numVal - 1)cout << " ";
	}
	cout << endl;
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