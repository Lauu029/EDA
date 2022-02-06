// Nombre del alumno Laura Gómez Bodego
// Usuario del Juez VJ23

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;

//Función que determina si el color es válido
bool esValida(const vector<string>& tipos, int k, const vector<int>& solucion) {

	return tipos[solucion[k]] > tipos[solucion[k - 1]] && solucion[k] > solucion[k - 1];
}


// función que resuelve el problema
void regalos(const vector<string>& tipos, int k, vector<int>& solucion, const int& numTipos,
	const int& numRegalos, bool& flag)
{
	for (int i = 0; i < numTipos; i++)
	{
		solucion[k] = i;

		if (k % 2 == 0 || esValida(tipos, k, solucion)) {

			if (k == numRegalos - 1)
			{
				for (int j = 0; j <= k; j++) {
					cout << solucion[j] << " ";
					flag = false;
				}
				cout << endl;
			}
			else
			{
				regalos(tipos, k + 1, solucion, numTipos, numRegalos, flag);
			}
		}
	}

}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	int numTipos, numKids;
	cin >> numTipos >> numKids;
	//Tipos de los juguetes
	vector<string>tipos;
	string tipo;
	for (int i = 0; i < numTipos; i++) {
		cin >> tipo;
		tipos.push_back(tipo);
	}

	if (!cin)
		return false;

	bool flag = true;
	int numRegalos = numKids * 2;
	vector<int> solucion(numRegalos, -1);

	regalos(tipos, 0, solucion, numTipos, numRegalos, flag);

	if (flag)
		cout << "SIN SOLUCION\n";

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