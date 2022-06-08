// Nombre del alumno Laura Gómez Bodego
// Usuario del Juez VJ23


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <algorithm>
#include "Hora.h"
#include "Pelicula.h"

using namespace std;



// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	int numPelis;
	cin >> numPelis;
	if (numPelis == 0)
		return false;
	vector<Pelicula> pelis (numPelis);
	for (int i = 0; i < numPelis; i++)
	{
		cin >> pelis[i];
	}
	sort(pelis.begin(), pelis.end());
	for (int i = 0; i < numPelis; i++)
	{
		cout << pelis[i].h<<" "<<pelis[i].nombre<< endl;
	}
	cout << "---\n";
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
