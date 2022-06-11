// Nombre del alumno Laura Gómez Bodego
// Usuario del Juez VJ23


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <list>

using namespace std;

// función que resuelve el problema
int resolver(list<int>& alumnos, const int& salta) {
	list<int>::iterator it = alumnos.begin();
	int cont = 0;
	while (alumnos.size()>1) {
		if (cont == salta) {
			cont = 0;
			it = alumnos.erase(it);
		}
		else {
			cont++;
			++it;
		}
		if (it == alumnos.end())
			it = alumnos.begin();
	}
	return *alumnos.begin();
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	int nAlumnos, salta;
	cin >> nAlumnos >> salta;
	if (nAlumnos == 0)
		return false;
	list<int>alumnos;
	for (int i = 1; i <= nAlumnos; i++)
	{
		alumnos.push_back(i);
	}
	int afortunado = resolver(alumnos, salta);

	cout << afortunado << endl;
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
