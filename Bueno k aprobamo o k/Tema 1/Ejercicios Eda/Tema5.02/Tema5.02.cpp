// Nombre del alumno Laura Gómez Bodego
// Usuario del Juez VJ23


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include "stack_eda.h"

using namespace std;
struct dat {
	string fecha;
	int muertos;
};
// función que resuelve el problema
void resolver(stack<dat>& analisis, const int& nMuertos) {
	bool encontrado = false;
	while (!encontrado && !analisis.empty()) {

		dat aux = analisis.top();
		if (aux.muertos > nMuertos) {
			cout << aux.fecha << endl;
			encontrado = true;
		}
		else analisis.pop();
	}
	if (analisis.empty()) cout << "NO HAY\n";
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	int nCasos;
	cin >> nCasos;
	if (!cin)return false;
	stack<dat> analisis;
	dat entrada;
	for (int i = 0; i < nCasos; i++)
	{
		cin >> entrada.fecha >> entrada.muertos;

		resolver(analisis, entrada.muertos);

		analisis.push(entrada);
	}
	cout << "---\n";
	// escribir sol

	return true;
}

int main() {
	// Para la entrada por fichero.
	// Comentar para acepta el reto
#ifndef DOMJUDGE
	std::ifstream in("datos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 

	while (resuelveCaso());


	// Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}