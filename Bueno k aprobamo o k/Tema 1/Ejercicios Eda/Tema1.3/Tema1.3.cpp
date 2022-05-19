// Nombre del alumno Laura Gómez Bodego
// Usuario del Juez VJ23


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;
// función que resuelve el problema
bool resolver(const int& p, const vector<int>& datos) {
	if (p == datos.size() - 1) return true;
	int max, min;
	min = datos[p+1];
	max = datos[0];
	for (int i = 0; i < datos.size(); i++)
	{
		if (i <= p) {
			if (datos[i] > max) max = datos[i];
		}
		else {
			if (datos[i] < min) min = datos[i];
		}
	}
	if (max < min) return true;
	else return false;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
	// leer los datos de la entrada
	int tamVec, p;
	cin >> tamVec >> p;
	vector <int> datos;
	int aux;
	for (int i = 0; i < tamVec; i++)
	{
		cin >> aux;
		datos.push_back(aux);
	}

	bool sol = resolver(p, datos);
	// escribir sol
	if (sol) cout << "SI\n";
	else cout << "NO\n";

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