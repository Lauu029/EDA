// Nombre del alumno Laura Gómez Bodego
// Usuario del Juez VJ23

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;
bool esValida(vector<int>& sol, vector <string>& tipos, vector<int>& disp, const vector<vector<int>>& sat, int k, int satMin) {
	if (disp[sol[k]] >= 0) {
		if (k % 2 == 0)return true;

		else if (tipos[sol[k]] <= tipos[sol[k - 1]])return false;

		else if (sat[k / 2][sol[k]] + sat[k / 2][sol[k - 1]] < satMin)return false;

		else return true;

	}
	else return false;
}

// función que resuelve el problema
void resolver(vector<int>& sol, vector<string>& tipos, vector<int>& disp, const vector<vector<int>>& sat, int k, int m, int n, bool& solucion, int satMin) {
	for (int i = 0; i < m; i++)
	{
		sol[k] = i;
		disp[i]--;
		if (esValida(sol, tipos, disp, sat, k, satMin)) {
			if (k == n - 1) {

				solucion = true;

				for (int j = 0; j <= k; j++)
				{
					cout << sol[j];
					if (j < k)cout << " ";
				}
				cout << endl;
				disp[i]++;
			}
			else {
				resolver(sol, tipos, disp, sat, k + 1, m, n, solucion, satMin);
				disp[i]++;
			}
		}
		else disp[i]++;
	}
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	int numTipos, numNin, minSat;
	cin >> numTipos >> numNin >> minSat;
	if (!cin)
		return false;
	//tipos de juguetes
	vector<string> tipos(numTipos);
	//disponibilidad de cada juguete
	vector<int>disp(numTipos);
	//vector de soluciones
	vector<int>sol(2 * numNin, -1);

	for (int i = 0; i < numTipos; i++) cin >> disp[i];

	for (int i = 0; i < numTipos; i++) cin >> tipos[i];
	//satisfacciones por niño y juguete
	vector<vector<int>>sat(numNin);
	vector<int>aux(numTipos);

	for (int i = 0; i < numNin; i++)
	{
		for (int j = 0; j < numTipos; j++)
		{
			cin >> aux[j];
		}
		sat[i] = aux;
	}
	bool solucion = false;
	resolver(sol, tipos, disp, sat, 0, numTipos, sol.size(), solucion, minSat);

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