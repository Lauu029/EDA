// Nombre del alumno Laura Gómez Bodego
// Usuario del Juez VJ23

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;
//evalúa si la suma de los juguetes provoca la satisfacción suficiente
bool satSuf(const vector<vector<int>>& satisfacciones, const vector<int>& solucion, int k, int minSat) {
	int sat;
	sat = satisfacciones[k / 2][solucion[k]] + satisfacciones[k / 2][solucion[k - 1]];
	return sat >= minSat;

}
//Función que determina si el color es válido
bool esValida(const vector<string>& tipos, const vector<int>& fabricados, int k,
	const vector<int>& solucion, const vector<vector<int>>& satisfacciones, int minSat) {
	if (fabricados[solucion[k]] >= 0) {
		if (k % 2 == 0)
			return true;
		else
			return ((fabricados[solucion[k]] >= 0) && (tipos[solucion[k]] > tipos[solucion[k - 1]])
				&& (solucion[k] > solucion[k - 1])) && satSuf(satisfacciones, solucion, k, minSat);
	}
	else
		return false;
}


// función que resuelve el problema
void regalos(const vector<string>& tipos, vector<int>& fabricados, int k, vector<int>& solucion,
	const vector<vector<int>>& satisfacciones, const int& numTipos,
	const int& numRegalos, int minSat, bool& flag)
{
	for (int i = 0; i < numTipos; i++)
	{
		solucion[k] = i;
		//se resta uno a los juguetes del tipo que quedan
		fabricados[i]--;
		if (esValida(tipos, fabricados, k, solucion, satisfacciones, minSat)) {

			if (k == numRegalos - 1)
			{
				for (int j = 0; j <= k; j++) {
					cout << solucion[j] << " ";
					flag = false;
				}
				cout << endl;
				fabricados[i]++;
			}
			else
			{
				regalos(tipos, fabricados, k + 1, solucion, satisfacciones, numTipos, numRegalos, minSat, flag);
				fabricados[i]++;
			}
		}
		else {
			fabricados[i]++;
		}
	}
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	int numTipos, numKids, minSat;
	cin >> numTipos >> numKids >> minSat;
	if (!cin)
		return false;
	//Cantidades disponibles
	vector<int>fabricados;
	int cantidad;
	for (int i = 0; i < numTipos; i++) {
		cin >> cantidad;
		fabricados.push_back(cantidad);
	}
	//Tipos de los juguetes
	vector<string>tipos;
	string tipo;
	for (int i = 0; i < numTipos; i++) {
		cin >> tipo;
		tipos.push_back(tipo);
	}

	vector<vector<int>>satisfacciones(numKids, vector<int>(numTipos));

	for (int i = 0; i < numKids; i++) {
		for (int j = 0; j < numTipos; j++) {
			//Reutilizo la variable ya creada para las cantidades
			cin >> cantidad;
			satisfacciones[i][j] = cantidad;
		}
	}


	bool flag = true;
	int numRegalos = numKids * 2;
	vector<int> solucion(numRegalos, -1);


	regalos(tipos, fabricados, 0, solucion,satisfacciones, numTipos, numRegalos, minSat, flag);

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