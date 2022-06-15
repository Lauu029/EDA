// Nombre del alumno Laura Gómez Bodego
// Usuario del Juez VJ23


#include <iostream>
#include <iomanip>
#include <fstream>
#include <list>
using namespace std;

void resolve(int posFinal, list<char>& lista, int pos, int lon) {
	if (!lista.empty()) {
		auto a = lista.begin();
		auto b = lista.begin();

		for (int cont = 0; cont < posFinal; ++cont) {
			if (b == lista.end()) return;
			++b;
			if (a == lista.end()) return;
			++a;


		}
		for (int cont = posFinal; cont < pos; ++cont) {
			if (b == lista.end()) return;
			++b;

		}
		for (int i = 0; i < lon; ++i)
		{
			if (b != lista.cend())
				lista.insert(a, *b);
			if (b != lista.cend())
				b = lista.erase(b);
		}
	}
}
void resuelveCaso() {
	int n, pos, lon, k;
	cin >> n >> pos >> lon >> k;
	//caso de que los elementos para colar se pasen de tamaño
	if (pos + lon > n) {
		lon = n - pos;
	}
	//valora si se va a poder hacer el ejercicio
	bool val = true;
	if (k > pos) val = false;
	list<char>lista;
	char c;
	for (int i = 0; i < n; ++i)
	{
		cin >> c;
		lista.push_back(c);

	}
	int posFinal = pos - k;
	if (!lista.empty()) {
		if (val) resolve(posFinal, lista, pos, lon);

		auto it = lista.begin();
		while (it != lista.end())
		{
			cout << *it << " ";
			++it;
			lista.pop_front();
		}
		lista.clear();
	}
	cout << "\n";

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