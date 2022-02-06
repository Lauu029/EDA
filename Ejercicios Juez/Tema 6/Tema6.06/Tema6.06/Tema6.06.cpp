
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <string>
#include "bintree_eda.h"
using namespace std;

//void creaArbol(const vector<int>& preorden,const vector<int>& inorden) {
//	int raiz = preorden[0];
//	vector<int> hi;
//	int aux = inorden[0];
//	int i = 0;
//	while (aux != raiz&&i<inorden.size()) {
//		hi.push_back(aux);
//		i++;
//		aux = inorden[i];
//	}
//	vector<int> dr;
//	for (int j = i+1; j < inorden.size(); j++) {
//		dr.push_back(inorden[j]);
//	}
//}

bintree<int> mevoyapegaruntiroenunateta(const vector<int>& preorden, const vector<int>& inorden,
	int ini, int fin, int& i) {
	if (fin < ini)return NULL;
	else if (ini == fin) {
		bintree<int> tree(preorden[i]);
		i++;
		return tree;
	}
	int j = 0;
	while (j < inorden.size() && inorden[j] != preorden[i])j++;
	int socorro = i;
	i++;
	if (i >= preorden.size())return NULL;
	bintree<int>left(mevoyapegaruntiroenunateta(preorden, inorden, ini, j-1, i));
	if (i >= preorden.size()) bintree<int>right;
	else bintree<int>right(mevoyapegaruntiroenunateta(preorden, inorden, j + 1, fin, i));
	bintree<int> tree(left, preorden[socorro], right);
	

	return tree;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	string stpreorden, stinorden;
	getline(cin, stpreorden);
	getline(cin, stinorden);
	if (!cin)
		return false;

	vector<int> preorden;
	vector<int>inorden;
	int aux;
	for (int i = 0; i < stpreorden.length(); i += 2) {
		preorden.push_back((stpreorden[i]) - '0');
		inorden.push_back(stinorden[i] - '0');
	}
	int i = 0;
	bintree<int> tree = mevoyapegaruntiroenunateta(preorden, inorden, 0, inorden.size() - 1, i);

	//cout << nodos(tree) << " " << hojas(tree) << " " << altura(tree) << endl;
}


int main() {
	// Para la entrada por fichero.
	// Comentar para acepta el reto
#ifndef DOMJUDGE
	std::ifstream in("datos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif


	while (resuelveCaso());


	// Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	//system("PAUSE");
#endif

	return 0;
}
