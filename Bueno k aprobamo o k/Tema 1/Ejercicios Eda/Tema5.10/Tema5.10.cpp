// Nombre del alumno Laura Gómez Bodego
// Usuario del Juez VJ23


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <list>

using namespace std;
// función que resuelve el problema
void resolver(list<int>& datos) {
	list<int>::iterator it1 = datos.begin();
	list<int>::iterator it2 = datos.begin();
	++it2;
	while (it2 != datos.end())
	{
		if (*it1 > *it2) {
			it2 = datos.erase(it2);
		}
		else {
			it2++;
			//it2++;
			it1++;
		}
	}

}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
	list<int> valores;
	int i;
	cin >> i;
	while (i != -1) {
		valores.push_back(i);
		cin >> i;
	}
	if (!valores.empty())
		resolver(valores);

	while (!valores.empty())
	{
		cout << valores.front() << " ";
		valores.pop_front();
	}
	cout << endl;
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