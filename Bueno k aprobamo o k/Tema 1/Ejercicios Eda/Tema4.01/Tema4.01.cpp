// Nombre del alumno Laura Gómez Bodego
// Usuario del Juez VJ23


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include "Hora.h"

using namespace std;

// función que resuelve el problema
void resolver(const vector<Hora>& horarios, const vector<Hora>& consulta, const int& nTrenes, const int& nHoras) {
	for (int i = 0; i < nHoras; i++)
	{
		if (consulta[i].esValida()) {

			int j = 0;
			bool encontrado = false;
			while (j < nTrenes && !encontrado) {
				if (!(horarios[j] < consulta[i])) {
					cout << horarios[j];
					encontrado = true;
				}
					j++;
			}
			if (!encontrado) cout << "NO\n";
		}
		else {
			cout << "ERROR\n";
		}
	}
	cout << "---\n";

}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	int nTrenes, nHoras;
	cin >> nTrenes >> nHoras;
	if (nTrenes == 0)
		return false;
	vector<Hora> horarios(nTrenes);
	vector<Hora>consulta(nHoras);
	for (int i = 0; i < nTrenes; i++)
	{
		cin >> horarios[i];
	}
	for (int i = 0; i < nHoras; i++)
	{
		cin >> consulta[i];
	}
	resolver(horarios, consulta, nTrenes, nHoras);

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