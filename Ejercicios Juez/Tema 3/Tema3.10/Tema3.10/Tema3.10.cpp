// Nombre del alumno Laura Gómez Bodego
// Usuario del Juez VJ23

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;

// función que resuelve el problema
void regalos(const vector<vector<int>>& satisfacciones, int numKids, int k, const int& numJug, int& maxSat, int& sat,
	vector<int>& solucion, const vector<int>& maximos, vector<bool>& usados)
{
	for (int i = 0; i < numJug; i++)
	{
		solucion[k] = i;
		//si la satisfacción no es el máximo se prueba con el siguiente juguete
		if (!usados[i]) {

			sat += satisfacciones[k][i];

			if (k == numKids - 1) {

				if (maxSat == 0 || maxSat < sat)
				{
					maxSat = sat;
				}
			}
			else {
				usados[i] = true;
				regalos(satisfacciones, numKids, k + 1, numJug, maxSat, sat, solucion, maximos, usados);
				usados[i] = false;

			}
			sat -= satisfacciones[k][i];

		}
	}
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	int numJug, numKids;
	cin >> numJug >> numKids;
	if (!cin)
		return false;
	int cantidad;
	int numMax;
	vector<vector<int>>satisfacciones(numKids, vector<int>(numJug));

	//Creo un vector con las satisfacciones máximas
	vector<int>maximos(numKids);
	for (int i = 0; i < numKids; i++) {
		numMax = 0;
		for (int j = 0; j < numJug; j++) {
			cin >> cantidad;
			//Establezco el máximo
			if (numMax < cantidad)
				numMax = cantidad;
			satisfacciones[i][j] = cantidad;
		}
		maximos[i] = numMax;
	}

	int maxSat = 0;
	int sat = 0;
	vector<int>solucion(numKids, -1);
	vector<bool> usados(numJug, false);
	regalos(satisfacciones, numKids, 0, numJug, maxSat, sat, solucion, maximos, usados);

	cout << maxSat;

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