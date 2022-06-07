// Nombre del alumno Laura Gómez Bodego
// Usuario del Juez VJ23


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;
bool esValida(vector<int>& sol, vector<int>& disp, vector<int>& total, int k) {

	if (disp[sol[k]] > total[sol[k]]) return false;
	else if (disp[0] < disp[2])return false;
	else if (sol[k] == 2) {

		if (sol[k] == sol[k - 1])return false;
		else return true;
	}
	else return true;
}
// función que resuelve el problema
void resolver(vector<int>& sol, vector<int>& disp, vector<int>& total, int k, int n, int& numSol) {
	for (int i = 0; i < 3; i++)
	{
		sol[k] = i;
		disp[i]++;
		if (esValida(sol, disp, total, k)) {

			if (k == n - 1) {
				if (disp[1] > disp[0] + disp[2]) {

					for (int j = 0; j <= k; j++)
					{
						switch (sol[j])
						{
						case 0:
							cout << "azul";
							break;
						case 1:
							cout << "rojo";
							break;
						case 2:
							cout << "verde";
							break;
						default:
							break;
						}
						if (j < k)cout << " ";
					}
					cout << endl;
					//para comprobar despues si ha tenido soluciones o no
					numSol++;
				}
					disp[i]--;
			}
			else {
				resolver(sol, disp, total, k + 1, n,numSol);
				disp[i]--;
			}
		}
		else
			disp[i]--;
	}
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	int n, a, r, v;
	cin >> n >> a >> r >> v;
	if (n == 0)
		return false;
	vector<int>sol(n,-1);
	vector<int>disp(3, 0);
	vector<int>total{ a,r,v };
	disp[1]++;
	sol[0] = 1;
	int numSol = 0;
	if (n > 1) {
		resolver(sol, disp, total, 1, n,numSol);
	}
	else cout << "rojo\n";

	if (numSol == 0)cout << "SIN SOLUCION\n";
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
