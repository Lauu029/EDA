// Nombre del alumno Laura Gómez Bodego
// Usuario del Juez VJ23

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;
// función que resuelve el problema
void resolver(vector<int>& sol, const vector<int>& numDisp, int k, const int& s, int suma, int& nSol) {

	suma += numDisp[k];

	if (suma <= s) {
		if (k == numDisp.size() - 1) {
			if (suma == s) nSol++;
		}
		else resolver(sol, numDisp, k + 1, s, suma, nSol);
	}
	suma -= numDisp[k];
	if (k <= numDisp.size() - 1) {
		if (k == numDisp.size() - 1) {
			if (suma == s) nSol++;
		}
		else
			resolver(sol, numDisp, k + 1, s, suma, nSol);
	}
}


// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	int n, s;
	cin >> n >> s;
	if (!std::cin)
		return false;
	vector<int> sol;
	vector<int>numDisp(n);
	vector<bool>marcas(n, false);
	for (int i = 0; i < n; i++)
	{
		cin >> numDisp[i];
	}
	int nSol = 0;
	resolver(sol, numDisp, 0, s, 0, nSol);

	cout << nSol << endl;
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