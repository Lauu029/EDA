// Nombre del alumno Laura Gómez Bodego
// Usuario del Juez VJ23

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;

//Función que determina si el color es válido
bool esValida(vector<int> solucion, int k, vector<int> numPiezas, vector<int> maxPiezas) {
	bool valida;
	//primero compruebo que no me he pasado con las piezas del color en el que estoy
	if (numPiezas[solucion[k]] <= maxPiezas[solucion[k]] && numPiezas[0] >= numPiezas[2]) {
		//Compruebo si la ficha es verde y la ficha anterior no
		if (((solucion[k] == 2) && (solucion[k - 1] != solucion[k])) || solucion[k] != 2) {
			valida = true;
		}
		else
			valida = false;
	}
	else
		valida = false;
	//si es verde y ademas el anterior es verde no es válida
	return valida;
}


// función que resuelve el problema
void palabrasPos(vector<int>& solucion, int k, const int& numColores, const int& alturaTorre,
	vector<int>& numPiezas, const vector<int>& maxPiezas, bool& flag)
{
	for (int i = 0; i < numColores; i++)
	{
		solucion[k] = i;
		numPiezas[i]++;
		if (esValida(solucion, k, numPiezas, maxPiezas)) {

			//si no ha llegado al total de las letras hace backtracking
			if (k == alturaTorre - 1)
			{
				if (numPiezas[1] > numPiezas[0] + numPiezas[2]) {
					for (int j = 0; j <= k; j++) {
						switch (solucion[j])
						{
						case 0: cout << "azul ";
							break;
						case 1: cout << "rojo ";
							break;
						case 2: cout << "verde ";
						default:
							break;
						}
					}
					flag = true;
					cout << endl;
				}
				numPiezas[i]--;
			}
			else
			{
				palabrasPos(solucion, k + 1, numColores, alturaTorre, numPiezas, maxPiezas,flag);
				numPiezas[i]--;
			}
		}
		else {
			numPiezas[i]--;
		}
	}

}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	int alturaTorre, numAzules, numRojas, numVerdes;
	cin >> alturaTorre >> numAzules >> numRojas >> numVerdes;

	if (alturaTorre == 0)
		return false;

	int numColores = 3;
	bool flag = false;
	vector<int> solucion(alturaTorre, -1);
	vector<int> numPiezas(numColores, 0);
	vector<int> maxPiezas{ numAzules,numRojas,numVerdes };
	//el primer color es rojo
	solucion[0] = 1;
	numPiezas[1] = 1;
	if (alturaTorre > 1) {
		palabrasPos(solucion, 1, numColores, alturaTorre, numPiezas, maxPiezas, flag);
	}
	else
		cout << "rojo\n";
	if (!flag)
		cout << "SIN SOLUCION\n";

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