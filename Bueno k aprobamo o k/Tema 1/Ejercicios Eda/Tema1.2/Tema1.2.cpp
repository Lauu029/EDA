// Nombre del alumno Laura Gómez Bodego
// Usuario del Juez VJ23


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;
// función que resuelve el problema
void resolver(int& numPicos, int& numValles, const vector<int>& temperaturas) {
	if (temperaturas.size() >= 3) {
		for (int i = 1; i < temperaturas.size()-1; i++)
		{
			if (temperaturas[i - 1] < temperaturas[i] && temperaturas[i + 1] < temperaturas[i]) {
				numPicos++;
			}
			else if (temperaturas[i - 1] > temperaturas[i] && temperaturas[i + 1] > temperaturas[i]) {
				numValles++;
			}
		}
	}
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
	// leer los datos de la entrada
	int numDatos;
	cin >> numDatos;

	vector<int> temperaturas;
	int aux;
	for (int i = 0; i < numDatos; i++)
	{
		cin >> aux;
		temperaturas.push_back(aux);
	}
	int numPicos = 0;
	int numValles = 0;

	resolver(numPicos, numValles, temperaturas);
	// escribir sol

	cout << numPicos << " " << numValles << "\n";
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