// Nombre del alumno Laura Gómez Bodego
// Usuario del Juez VJ23


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;


// función que resuelve el problema
bool resolver(const vector < int >& datos, int ini, int fin) {
	if (fin < ini) return false;

	int mitad = (ini + fin) / 2;
	if (datos[mitad] == mitad) return true;
	else if (datos[mitad] < mitad) return resolver(datos, mitad + 1, fin);
	else return resolver(datos, ini, mitad - 1);

}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
	// leer los datos de la entrada
	int val;
	cin >> val;
	if (val != 0) {

		vector<int>datos(val);
		for (int i = 0; i < val; i++)
		{
			cin >> datos[i];
		}
		// escribir sol
		if (resolver(datos, 0, val - 1))cout << "SI\n";
		else cout << "NO\n";
	}
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
	//system("PAUSE");
#endif

	return 0;
}