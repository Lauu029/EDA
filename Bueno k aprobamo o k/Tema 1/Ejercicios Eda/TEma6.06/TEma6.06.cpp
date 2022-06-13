// Nombre del alumno Laura Gómez Bodego
// Usuario del Juez VJ23

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <string>
#include "bintree_eda.h"
using namespace std;
// función que resuelve el problema
bintree<int> creaArbol(vector<int>& preorden, vector<int>& inorden) {
	if (!preorden.empty()) {

		vector<int>hiIn, hiPre, hdIn, hdPre;
		int i = 0, j = 1;
		while (inorden[i] != preorden[0]) {
			hiIn.push_back(inorden[i]);
			hiPre.push_back(preorden[j]);
			i++;
			j++;
		}
		i++;
		while (i < inorden.size()) {
			hdIn.push_back(inorden[i]);
			hdPre.push_back(preorden[j]);
			i++;
			j++;
		}
		bintree<int>aIz = creaArbol(hiPre, hiIn);
		bintree<int>aDr = creaArbol(hdPre, hdIn);
		bintree<int> arbol(aIz, preorden[0], aDr);
		return arbol;
	}
	else {
		bintree<int> a;
		return a;
	}
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	string pre, in;
	getline(cin, pre);
	getline(cin, in);
	if (!std::cin)
		return false;

	vector<int>preorden, inorden;

	for (int i = 0; i < pre.size(); i = i + 2)
	{
		int pr = pre[i] - '0';
		int inor = in[i] - '0';
		preorden.push_back(pr);
		inorden.push_back(inor);
	}
	bintree<int>tree = creaArbol(preorden, inorden);
	if (!tree.empty()) {
		vector<int> postorden = tree.postorder();
		for (int i = 0; i < postorden.size(); i++)
		{
			cout << postorden[i] << " ";
		}
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