// Nombre del alumno Laura Gómez Bodego
// Usuario del Juez VJ23


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;
// función que resuelve el problema
void resolver(const vector<vector<int>>& precios, vector<int>& supermercados, int k, int& precioMin,
	const int& numSupermercados, int& precio, const int& numProductos, const vector<int>& optimista) {
	for (int i = 0; i < numSupermercados; i++) {
		supermercados[i]++;
		//si ya ha usado el supermercado tres veces no continúa
		if (supermercados[i] <= 3) {
			//actualizo precio
			precio += precios[i][k];
			if (precioMin == 0 || precio < precioMin) {
				if (k == numProductos - 1) {
					precioMin = precio;

				}
				//Poda
				else if (precio + optimista[k+1] < precioMin || precioMin == 0) {

					resolver(precios, supermercados, k + 1, precioMin, numSupermercados, precio, numProductos, optimista);
				}
			}
			precio -= precios[i][k];
		}
		supermercados[i]--;
	}

}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
	// leer los datos de la entrada
	int numSupermercados, numProductos;
	cin >> numSupermercados >> numProductos;

	vector<vector<int>> precios;
	vector<int>minimos(numProductos);
	int centimos;
	for (int i = 0; i < numSupermercados; i++) {
		vector<int>productos;
		for (int j = 0; j < numProductos; j++) {
			cin >> centimos;
			productos.push_back(centimos);
		}
		precios.push_back(productos);
	}

	//creacion del vector optimista para la poda
	vector<int>optimista(numProductos);
	int precioOpt=0;
	int min;
	for (int i = numProductos - 1; i >= 0; i--) {
		min = 0;
		for(int j=0;j<numSupermercados;j++)
		{
			if (precios[j][i] < min||min==0) min = precios[j][i];
		}
		precioOpt += min;
		optimista[i] = precioOpt;
	}
	int precioMin = 0;
	int precio = 0;
	vector<int>supermercados(numSupermercados, 0);
	resolver(precios, supermercados, 0, precioMin, numSupermercados, precio, numProductos, optimista);
	// escribir sol
	cout << precioMin << "\n";

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