// Nombre del alumno Laura Gómez Bodego
// Usuario del Juez VJ23

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include "stack_eda.h"
#include <string>

using namespace std;
// función que resuelve el problema
bool resolver(stack<char>& q, char a) {
	if (q.empty())return false;
	char i = q.top();
	if (i == '(' && a == ')')q.pop();
	else if (i == '[' && a == ']')q.pop();
	else if (i == '{' && a == '}')q.pop();
	else return false;
	return true;

}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	string texto;
	getline(cin, texto);
	if (!std::cin)
		return false;
	stack<char> q;
	bool equilibrada = true;
	for (int i = 0; i < texto.size() && equilibrada; i++)
	{
		if (texto[i] == '(' || texto[i] == '[' || texto[i] == '{') {
			q.push(texto[i]);
		}
		else if (texto[i] == ')' || texto[i] == ']' || texto[i] == '}') {
			equilibrada = resolver(q, texto[i]);
		}
	}
	if (equilibrada && q.empty()) cout << "SI\n";
	else cout << "NO\n";

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


	while (resuelveCaso())
		;


	// Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}