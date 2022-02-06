// Nombre del alumno Laura Gómez Bodego
// Usuario del Juez VJ23


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;
// función que dado un entero devuelve el inverso del número formado por sus complementarios
int invComplementarios(int entrada, int& sol) {
	if (entrada < 10) {
		return sol * 10 + (9 - entrada);
	}
	else {
		sol = (sol * 10) + 9 - (entrada % 10);
		return invComplementarios(entrada / 10, sol);
	}
}
int numComplementarios(int entrada) {
	if (entrada < 10)return 9 - entrada;
	return (9 - entrada % 10) + numComplementarios(entrada / 10) * 10;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
	// leer los datos de la entrada
	int num;
	cin >> num;
	//auxiliar para la solucion
	int solucion = 0;
	//auxiliar de la entrada
	int entrada = num;
	int comp = numComplementarios(entrada);
	//resteteo la entrada para utilizarla de nuevo con los inversos
	entrada = num;
	int inv = invComplementarios(entrada, solucion);

	cout << comp << " " << inv << "\n";
}

int main() {
	// Para la entrada por fichero.
	// Comentar para acepta el reto
#ifndef DOMJUDGE
	std::ifstream in("datos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 


	int numCasos;
	std::cin >> numCasos;
	for (int i = 0; i < numCasos; ++i)
		resuelveCaso();


	// Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}