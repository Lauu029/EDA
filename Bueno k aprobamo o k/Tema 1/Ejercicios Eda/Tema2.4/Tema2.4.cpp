// Nombre del alumno Laura Gómez Bodego
// Usuario del Juez VJ23


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;
int numPares(const vector<int>& valores, int ini, int fin) {
	int numPares = 0;
	for (int i = ini; i <= fin; i++) {
		if (valores[i] % 2 == 0) numPares++;
	}
	return numPares;
}
// función que resuelve el problema
bool resolver(const vector <int>& valores, int ini, int fin) {
	if (ini == fin)return true;
	if (abs(numPares(valores, ini, (ini + fin) / 2) - numPares(valores, (ini + fin) / 2 + 1, fin)) <= 2) {
		return resolver(valores, ini, (ini + fin) / 2) && resolver(valores, (ini + fin) / 2 + 1, fin);
	}
	else return false;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	int n;
	cin >> n;
	if (n == 0)
		return false;
	vector<int>valores;
	int aux;
	for (int i = 0; i < n; i++)
	{
		cin >> aux;
		valores.push_back(aux);
	}
	bool sol = resolver(valores, 0, n - 1);

	// escribir sol
	if (sol)cout << "SI\n";
	else cout << "NO\n";

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