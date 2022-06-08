// Nombre del alumno Laura Gómez Bodego
// Usuario del Juez VJ23

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <math.h>
#include "Set1.h"

using namespace std;
// función que resuelve el problemavo
vector <int> cif(int num) {
	vector<int> cifras;

	while (num > 9) {
		cifras.push_back(num % 10);
		num /= 10;
	}
	cifras.push_back(num);
	return cifras;
}

void resolve(const vector<int>& cifras, Set1<int>& numeros) {
	int cuadrado = 0;

	for (int i = 0; i < cifras.size(); i++)
	{
		cuadrado += pow(cifras[i], 2);
	}
	if (!numeros.contains(cuadrado) && cuadrado != 1) {
		numeros.add(cuadrado);

		vector<int>cifras = cif(cuadrado);

		resolve(cifras, numeros);
	}
	else if (cuadrado == 1) {
		if (!numeros.contains(1)) numeros.add(cuadrado);

		numeros.add(1);
	}
	else {
		numeros.add(cuadrado);
		numeros.add(0);
	}

}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	int num;
	cin >> num;
	if (!std::cin)
		return false;

	vector<int> cifras = cif(num);

	Set1<int>numeros;
	numeros.add(num);


	resolve(cifras, numeros);

	for (int i = 0; i < numeros.size(); i++) {
		cout << numeros.toArray()[i] << " ";
	}
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