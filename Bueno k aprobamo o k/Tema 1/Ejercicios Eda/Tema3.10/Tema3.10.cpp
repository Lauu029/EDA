// Nombre del alumno Laura Gómez Bodego
// Usuario del Juez VJ23

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;


// función que resuelve el problema
void resolver(vector<int>& sol, vector<bool>& disp, const vector<vector<int>>& sat, int k, int m, int n, int satTotal, int& satMax) {
	for (int i = 0; i < m; i++)
	{
		sol[k] = i;
		if (!disp[i]) {
			satTotal += sat[k][i];

			if (k == n - 1) {
				if (satMax < satTotal)
					satMax = satTotal;
			}
			else {
				disp[i] = true;
				resolver(sol, disp, sat, k + 1, m, n, satTotal, satMax);
				disp[i] = false;
			}
			satTotal -= sat[k][i];

		}
	}
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	int numJug, numNin;
	cin >> numJug >> numNin;
	if (!cin)
		return false;

	//disponibilidad de cada juguete
	vector<bool>disp(numJug, false);
	//vector de soluciones
	vector<int>sol(numNin, -1);

	//satisfacciones por niño y juguete
	vector<vector<int>>sat(numNin);

	vector<int>aux(numJug);
	for (int i = 0; i < numNin; i++)
	{
		for (int j = 0; j < numJug; j++)
		{
			cin >> aux[j];
		}
		sat[i] = aux;
	}
	int satMax = -1;
	resolver(sol, disp, sat, 0, numJug, sol.size(), 0, satMax);

	cout << satMax;
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