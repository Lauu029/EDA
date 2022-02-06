// Nombre del alumno Laura Gómez Bodego
// Usuario del Juez VJ23


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

#include <list>

using namespace std;
void solucion(list<int>& alumnos, int saltar) {
	int saltados = 0;
	list<int>::iterator it = alumnos.begin();
	while (alumnos.size() != 1) {
		if (saltados == saltar) {
			it = alumnos.erase(it);
			if (it == alumnos.end()) it = alumnos.begin();
			saltados = 0;
		}
		else {
			if (it == alumnos.end()) {
				it = alumnos.begin();
				saltados++;
			}
			else {
				it++;
				if (it != alumnos.end()) {
					saltados++;
				}
			}

		}

	}
	cout  <<*it<< "\n";
}


// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	int nAlumnos, saltar;
	cin >> nAlumnos >> saltar;
	if (!nAlumnos)
		return false;

	list<int>alumnos;
	for (int i = 1; i <= nAlumnos; i++) alumnos.push_back(i);
	
	
	solucion(alumnos, saltar);
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