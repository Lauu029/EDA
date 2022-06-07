// Nombre del alumno Laura Gómez Bodego
// Usuario del Juez VJ23

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;

bool esValida(vector <int>& solucion, int k) {
	bool correcto = true;
	int i = 0;
	while (i < k && correcto) {
		if ((solucion[i] == solucion[k]) || abs(solucion[k] - solucion[i]) == k - i)
			correcto = false;
		else
			i++;
	}
	return correcto;
}
void nReinas(vector <int>& solucion, int k, int n) {
	for (int i = 0; i < n; i++) {
		solucion[k] = i;
		if (esValida(solucion, k)) {
			if (k == n - 1) {
				cout << "Solucion: ";
				for (int i = 0; i < n; i++)
					cout << solucion[i] << " ";
				cout << endl;
			}
			else {
				nReinas(solucion, k + 1, n);
			}
		}
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
	vector<int>sol(n);
	
	nReinas(sol, 0, n);

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