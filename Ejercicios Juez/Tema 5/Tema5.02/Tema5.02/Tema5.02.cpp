// Nombre del alumno Laura Gómez Bodego
// Usuario del Juez VJ23


#include <iostream>
#include <iomanip>
#include <fstream>
#include <stack>
#include <string>

using namespace std;

struct sol {
	string fecha;
	int muertos;
};
// función que resuelve el problema
void resolver(stack<sol>& pila, int nuevoAcc) {
	bool sigue = true;
	while (sigue && !pila.empty()) {
		sol aux = pila.top();
		if (aux.muertos > nuevoAcc) {
			cout << aux.fecha << "\n";
			sigue = false;
		}
		else {
			pila.pop();
		}
	}

	if (pila.empty()) {
		cout << "NO HAY\n";
	}
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	int numAccidentes;
	cin >> numAccidentes;
	if (!cin) return false;

	stack<sol>pila;
	sol datos;
	for (int i = 0; i < numAccidentes; i++) {

		cin >> datos.fecha >> datos.muertos;
		resolver(pila, datos.muertos);
		pila.push(datos);
	}
	cout << "---\n";
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