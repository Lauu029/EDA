// Nombre del alumno Laura Gómez Bodego
// Usuario del Juez VJ23

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;

// función que resuelve el problema
void resolver(vector<char>& sol, int k, int n, int m) {
	for (char i = 'a' ; i < 'a'+m; i++)
	{
		sol[k] = i;

		if (k == n - 1) {
			for (int j = 0; j <= k; j++)
				cout << sol[j];
			cout << endl;
		}
		else resolver(sol, k + 1, n, m);

	}
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	int n, m;
	cin >> m >> n;
	if (!std::cin)
		return false;
	vector<char>sol(n);
	resolver(sol, 0, n, m);

	// escribir sol
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