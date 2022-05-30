// Nombre del alumno Laura Gómez Bodego
// Usuario del Juez VJ23


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;
// función que resuelve el problema
int complementario(long int numero) {
	if (numero < 10) {
		return 9 - numero;
	}
	int nuevoDigito = 9 - numero % 10;
	numero /= 10;

	return nuevoDigito + complementario(numero) * 10;
}


int inversoComplementario(long int numero, long int ant) {
	if (numero < 10) {
		return (9 - numero) + ant * 10;
	}
	else {
		ant = ant * 10 + (9 - numero % 10);
		return inversoComplementario(numero / 10, ant);
	}
	return ant;


}
// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
	// leer los datos de la entrada
	long int numero;
	cin >> numero;

	int ant = 0;
	int comp = complementario(numero);
	int inv = inversoComplementario(numero, ant);
	// escribir sol 
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