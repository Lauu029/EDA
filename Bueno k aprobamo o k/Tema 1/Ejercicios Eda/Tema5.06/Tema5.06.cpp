// Nombre del alumno Laura Gómez Bodego
// Usuario del Juez VJ23

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <queue>
#include <stack>
#include <string>
#include <ctype.h>

using namespace std;
bool esVocal(const char& a) {
	char b = toupper(a);
	return(b == 'A' || b == 'E' || b == 'I' || b == 'O' || b == 'U');
}
// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	string entrada;
	getline(cin, entrada);
	if (!std::cin)
		return false;

	queue<char> cola;
	stack<char> pila;

	for (int i = 0; i < entrada.size(); i++)
	{
		if (i % 2 == 0) cola.push(entrada[i]);
		else pila.push(entrada[i]);
	}
	//añadir en la cola los caracteres de la pila
	while (!pila.empty()) {
		cola.push(pila.top());
		pila.pop();
	}
	string salida;
	char let;
	while (!cola.empty()) {
		let = cola.front();
		//comprobamos si es vocal
		if (esVocal(let)) {
			while (!pila.empty()) {
				salida.push_back(pila.top());
				pila.pop();
			}
				salida.push_back(let);
		}
		else {
			pila.push(let);
		}
		cola.pop();
	}
	while (!pila.empty()) {
		salida.push_back(pila.top());
		pila.pop();
	}
	cout << salida<<endl;
	
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