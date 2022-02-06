// Nombre del alumno Laura Gómez Bodego
// Usuario del Juez VJ23


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <deque>

using namespace std;


// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada

	int tamFila;
	cin >> tamFila;
	if (tamFila==0) return false;

	deque<int>fila;
	int numero;
	for (int i = 0; i < tamFila; i++) {
		cin >> numero;
		//Numero negativo
		if (numero >= 0)  fila.push_back(numero);
		//numero positivo
		else fila.push_front(numero);
	}
	for (int j = 0; j < tamFila; j++) { 
		cout << fila.front()<<" ";
		fila.pop_back();
	}
	cout << "\n";

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