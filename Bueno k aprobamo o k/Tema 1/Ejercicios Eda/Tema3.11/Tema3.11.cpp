// Nombre del alumno Laura Gómez Bodego
// Usuario del Juez VJ23


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;
bool esValida(vector<int>& sol, int k, vector<int>& cant) {
	if (k == 0)return true;
	if (sol[k] == sol[k - 1]) return false;
	int sum = 0;
	for (int i = 0; i < cant.size(); i++)
	{
		if (i != sol[k]) {
			sum += cant[i];
		}
	}
	if (cant[sol[k]] + 1 >= sum)return false;
	else return true;
}
// función que resuelve el problema
void resolver(vector<int>& sol, const vector<int>& consumo, vector<int>& cant, int k, int numCol, int longSol, int consMax, int& nSol, int consumido) {

	for (int i = 0; i < numCol; i++)
	{
		sol[k] = i;
		cant[i]++;
		consumido += consumo[i];
		if (esValida(sol, k, cant)) {
			if (k == longSol - 1) {
				if (consumido <= consMax) {
					nSol++;
				}

			}
			else {
				resolver(sol, consumo, cant, k + 1, numCol, longSol, consMax, nSol, consumido);

			}
		}
		consumido -= consumo[i];
		cant[i]--;

	}
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	int longSol, numCol, consMax;
	cin >> longSol >> numCol >> consMax;
	if (longSol == 0)
		return false;
	vector<int>consumo(numCol);
	vector<int>cant(numCol);
	for (int i = 0; i < numCol; i++)
	{
		cin >> consumo[i];
	}
	int nSol = 0;
	vector<int>sol(longSol, -1);
	resolver(sol, consumo, cant, 0, numCol, longSol, consMax, nSol, 0);

	// escribir sol
	cout << nSol << endl;
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
