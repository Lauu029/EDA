// Nombre del alumno Laura Gómez Bodego
// Usuario del Juez VJ23


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;
// función que resuelve el problema
int resolver(const vector<int>& datos, int ini, int fin) {
	if (ini == fin) return ini;
	else if (ini + 1 == fin) {
		if (ini % 2 == 0)
			return ini;
		else
			return fin;
	}
	int mid = (ini + fin) / 2;
	if (datos[mid] != datos[mid - 1] && datos[mid] != datos[mid + 1]) return mid;
	else if (datos[mid] == datos[mid - 1] && mid % 2 != 0 )return resolver(datos, mid + 1, fin);
	else if (datos[mid] == datos[mid - 1] && mid % 2 == 0 )return resolver(datos, ini, mid - 1);
	else if (datos[mid] != datos[mid - 1] && mid % 2 == 0 )return resolver(datos, mid + 1, fin);
	else return resolver(datos, ini, mid - 1);
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
	// leer los datos de la entrada
	int n;
	cin >> n;

	vector<int>datos(n);

	for (int i = 0; i < n; i++) cin >> datos[i];


	cout << resolver(datos, 0, n - 1) << endl;
	// escribir sol


}

int main() {
	// Para la entrada por fichero.
	// Comentar para acepta el reto
#ifndef DOMJUDGE
	std::ifstream in("datos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 


	int numCasos;
	std::cin >> numCasos;
	for (int i = 0; i < numCasos; ++i)
		resuelveCaso();


	// Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}