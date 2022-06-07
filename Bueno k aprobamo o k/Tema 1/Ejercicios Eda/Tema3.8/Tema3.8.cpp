// Nombre del alumno Laura Gómez Bodego
// Usuario del Juez VJ23

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;
bool esValida(vector<int>& sol, vector <string>& tipos, int k) {

	if ( tipos[sol[k]] <= tipos[sol[k - 1]])return false;
	else return true;
}

// función que resuelve el problema
void resolver(vector<int>& sol, vector<string>& tipos, int k, int m, int n, bool& solucion) {
	for (int i = 0; i < m; i++)
	{
		sol[k] = i;

		if (k%2 == 0 || esValida(sol, tipos, k)) {
			if (k == n - 1) {

				solucion = true;

				for (int j = 0; j <= k; j++)
				{
					cout << sol[j];
					if (j < k)cout << " ";
				}
				cout << endl;
			}
			else resolver(sol, tipos, k + 1, m, n, solucion);
		}
	}
}



// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	int numTipos, numNin;
	cin >> numTipos >> numNin;
	if (!cin)
		return false;
	vector<string> tipos(numTipos);
	for (int i = 0; i < numTipos; i++)
	{
		cin >> tipos[i];
	}
	vector<int>sol(2 * numNin);
	bool solucion = false;
	resolver(sol, tipos, 0, numTipos, sol.size(), solucion);

	// escribir sol
	if (!solucion)cout << "SIN SOLUCION\n";
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