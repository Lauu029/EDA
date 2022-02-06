// Nombre del alumno Laura Gómez Bodego
// Usuario del Juez VJ23

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;

// función que resuelve el problema
void resolver(vector<int>& solucion, int k, const vector<int>& valores, vector<bool>& marcas,
	const int& sumFinal, const int& nElem, int& sumaTemp, int& sol) {

	sumaTemp += valores[k];
	if (sumaTemp <= sumFinal) {
		if (k <= nElem - 1) {
			if (k < nElem - 1)
				resolver(solucion, k + 1, valores, marcas, sumFinal, nElem, sumaTemp, sol);
			else if (sumaTemp == sumFinal)
				sol++;
		}
	}
	sumaTemp -= valores[k];
	if (k <= nElem - 1) {
		if (k < nElem - 1)
			resolver(solucion, k + 1, valores, marcas, sumFinal, nElem, sumaTemp, sol);
		else if (sumaTemp == sumFinal)
			sol++;
	}
}





// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	int nElem, sumFinal;
	cin >> nElem >> sumFinal;
	if (!cin)
		return false;
	vector<int>valores(nElem);
	for (int i = 0; i < nElem; ++i)
		cin >> valores[i];
	vector<bool>marcas(nElem, false);
	int sumaTemp = 0, sol = 0;
	vector<int>solucion(nElem, -1);
	resolver(solucion, 0, valores, marcas, sumFinal, nElem, sumaTemp, sol);

	// escribir sol
	cout << sol << "\n";

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