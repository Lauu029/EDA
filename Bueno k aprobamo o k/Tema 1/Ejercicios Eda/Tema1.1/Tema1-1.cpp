// Nombre del alumno Laura Gómez Bodego
// Usuario del Juez VJ23


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;

// función que resuelve el problema
bool resolver(vector <int>& casos, int numCasos) {
	if (numCasos < 2)
		return false;
	int aux = casos[0];
	bool asc = true;
	
	if (casos[0] > casos[1]) asc = false;
	
	int i = 1;
	bool valido = true;

	while (valido && i < casos.size())
	{

		if (asc && casos[i] > aux) {
			aux = casos[i];
			i++;
		}
		else if (!asc && casos[i] < aux) {
			aux = casos[i];
			i++;
		}
		else valido = false;
	}
	return valido;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	int numCasos;
	cin >> numCasos;
	if (numCasos == 0)
		return false;
	vector <int> casos;
	int numAux;
	for (int i = 0; i < numCasos; i++)
	{
		cin >> numAux;
		casos.push_back(numAux);
	}

	bool sol = resolver(casos, numCasos);


	// escribir sol
	if (sol)
		cout << "DALTON\n";
	else cout << "DESCONOCIDOS\n";

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