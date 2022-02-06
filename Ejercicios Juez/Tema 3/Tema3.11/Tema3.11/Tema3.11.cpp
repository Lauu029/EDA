// Nombre del alumno Laura Gómez Bodego
// Usuario del Juez VJ23


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;


bool esValida(const vector<int>& solucion, const int& k, const int& maxCon, const int& i, const int& conTot, const vector<int>& cant) {
	//Esto no lo entiendo
	if (k + 1 - cant[i] < (k + 1) / 2)return false;
	if (k > 2)
		if (solucion[k] == solucion[k - 1] && solucion[k] == solucion[k - 2])
			return false;
	return  conTot <= maxCon;
}
//consumo, solucion, cant, 0, maxCon, numCol
void resolver(const vector<int>& consumo, vector<int>& solucion, vector<int>& cant, int k,
	const int& maxCon, const int& numCol, int& conTot, const int& longitud, int& numSol) {

	for (int i = 0; i < numCol; i++) {
		solucion[k] = i;
		conTot += consumo[i];
		cant[i]++;
		if (esValida(solucion, k, maxCon, i, conTot, cant)) {
			if (k == longitud - 1) {
				numSol++;
			}
			else {
				resolver(consumo, solucion, cant, k + 1, maxCon, numCol, conTot, longitud, numSol);
			}
		}
		cant[i]--;
		conTot -= consumo[i];
	}

}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	int longitud, numCol, maxCon;
	cin >> longitud >> numCol >> maxCon;
	//Llega al final del documento
	if (longitud == 0)
		return false;
	vector<int>consumo(numCol);
	for (int i = 0; i < numCol; i++)
		cin >> consumo[i];
	//Tupla solucion
	//lo pongo a -1 inicialmente para facilitar la depuración
	vector<int>solucion(longitud, -1);
	//vector de cantidades usadas de cada bombilla
	vector<int>cant(numCol, 0);
	int conTot = 0;
	int numSol = 0;
	resolver(consumo, solucion, cant, 0, maxCon, numCol, conTot, longitud, numSol);

	// escribir sol
	cout << numSol << "\n";
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
