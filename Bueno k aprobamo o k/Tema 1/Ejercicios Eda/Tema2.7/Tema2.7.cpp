// Nombre del alumno Laura Gómez Bodego
// Usuario del Juez VJ23

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;
// función que resuelve el problema
int minimo(const vector<int>& datos, int ini, int fin) {
	if (ini == fin) return datos[ini];
	else if (ini + 1 == fin) return min(datos[ini], datos[fin - 1]);
	else {
		int minI, minD;
		int mid = (ini + fin) / 2;

		minI = minimo(datos, ini, mid);
		minD = minimo(datos, mid, fin);

		return min(minI, minD);
	}
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	int n;
	cin >> n;
	if (!std::cin)
		return false;

	vector<int> datos(n);
	for (int i = 0; i < n; i++)
	{
		cin >> datos[i];
	}

	cout << minimo(datos, 0, n) << endl;

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