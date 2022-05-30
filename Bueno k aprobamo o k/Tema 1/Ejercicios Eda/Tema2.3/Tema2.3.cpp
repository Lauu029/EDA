// Nombre del alumno Laura Gómez Bodego
// Usuario del Juez VJ23


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;

// función que resuelve el problema
 bool parcialmenteOrdenado(const vector<int>& valores, int ini, int fin) {
	if (ini == fin) return true;
	else if (ini == fin - 1) return valores[ini] <= valores[fin];
	int minD, minI, maxD, maxI;
	minI = maxI = valores[ini];
	maxD = minD = valores[fin];
	int med = (ini + fin) / 2;
	for (int i = ini; i < fin; i++)
	{
		if (i <= med) {
			if (minI > valores[i])minI = valores[i];
			if (maxI < valores[i])maxI = valores[i];
		}
		else {
			if (minD > valores[i])minD = valores[i];
			if (maxD < valores[i])maxD = valores[i];
		}
	}
	if (minI <= minD && maxD >= maxI) {
		return parcialmenteOrdenado(valores, ini, med) && parcialmenteOrdenado(valores, med + 1, fin);
	}
	else return false;
	//Se puede hacer de otra forma(es más eficiente pero no la entiendo del todo): 
	/*if (ini == fin)
		return true;
	else if (ini + 1 != fin)
	{
		int medio = ini + (fin - ini) / 2;

		return datos[ini] <= datos[medio + 1] && datos[fin] >= datos[medio] && resolver(datos, ini, (ini + fin) / 2)
			&& resolver(datos, ((ini + fin) / 2) + 1, fin);
	}*/

}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	int val;
	cin >> val;
	if (val == 0)
		return false;
	vector<int>valores;
	while (val != 0) {
		valores.push_back(val);
		cin >> val;
	}
	bool sol = parcialmenteOrdenado(valores, 0, valores.size() - 1);

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