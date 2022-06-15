// Nombre del alumno Laura Gómez Bodego
// Usuario del Juez VJ23


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;
// función que resuelve el problema
void resolver(const vector<vector<int>>& productos, vector<vector<bool>>& marcas, vector<int>& sol, vector<int>& super, int& minPrecio, int k, int precio) {
	for (int i = 0; i < super.size(); i++)
	{
		super[i]++;
		if (super[i] <= 3) {

			precio += productos[i][k];
			if (minPrecio == -1 || minPrecio > precio) {
				if (k == sol.size() - 1)
					minPrecio = precio;
				else {

					resolver(productos, marcas, sol, super, minPrecio, k + 1, precio);

				}
			}
			precio -= productos[i][k];


		}
		super[i]--;
	}

}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
	int nSuper, nProd;
	cin >> nSuper >> nProd;
	vector<vector<int>>productos;
	vector<vector<bool>>marcas;
	for (int i = 0; i < nSuper; i++)
	{
		vector<int>supermercado;
		vector<bool>s;
		int k;
		for (int j = 0; j < nProd; j++)
		{
			s.push_back(false);
			cin >> k;
			supermercado.push_back(k);
		}
		marcas.push_back(s);
		productos.push_back(supermercado);
	}
	vector<int> sol(nProd);
	vector<int> super(nSuper, 0);
	int minPrecio = -1;
	resolver(productos, marcas, sol, super, minPrecio, 0, 0);
	cout << minPrecio << endl;
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