// Nombre del alumno Laura Gómez Bodego
// Usuario del Juez VJ23


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <list>
using namespace std;

void resolve(int posFinal, list<char>& lista, list<char>& cuela) {
	list<char>::iterator a = lista.begin();
	int cont = 0;
	while (cont < posFinal) {
		++cont;
		a++;
	}
	for(auto b:cuela){
		a = lista.insert(a, b);
		++a;
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
	list<char>lista, cuela;
	char c;
	for (int i = 0; i < n; i++)
	{
		cin >> c;

		if (val && i >= pos && i < pos + lon) {
			cuela.push_back(c);
		}
		else {
			lista.push_back(c);
		}
	}
	int posFinal = pos - k;
	if (val) resolve(posFinal, lista, cuela);
	for (auto& it : lista)
	{
		cout << it << " ";
	}
	cout<< endl;

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