// Nombre del alumno Laura Gómez Bodego
// Usuario del Juez VJ23


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;

// función que resuelve el problema
int impar(const vector<int>& datos, int ini, int fin) {

	if (ini + 1 == fin) return datos[ini];
	else {
		int mid = (ini + fin-1) / 2;
		if (datos[mid] % 2 != 0) return datos[mid];
		else if ((datos[mid] - datos[ini]) != ((mid - ini) * 2)) return impar(datos, ini, mid);
		else return impar(datos, mid + 1, fin);
	}
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	int n;
	cin >> n;
	if (n == 0)
		return false;
	vector<int>datos(n);
	for (int i = 0; i < n; i++)
	{
		cin >> datos[i];
	}
	cout << impar(datos, 0, n) << endl;

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
	//system("PAUSE");
#endif

	return 0;
}
