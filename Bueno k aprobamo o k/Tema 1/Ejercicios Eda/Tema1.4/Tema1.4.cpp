// Nombre del alumno Laura Gómez Bodego
// Usuario del Juez VJ23


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <string>
using namespace std;
// función que resuelve el problema
bool resolver(vector<char>& pal1, vector<char>& pal2) {
	int letras[27] = { 0 };
	int n = 0;
	//recorre el primer vector y almacena en cada letra del abecedario la cantidad de ellas que hay
	for (int i = 0; i < pal1.size(); i++)
	{
		n = pal1[i] - 96;
		letras[n]++;
	}
	n = 0;
	//recorre el segundo vector borrando las letras que tiene la palabra
	for (int i = 0; i < pal2.size(); i++)
	{
		n = pal2[i] - 96;
		letras[n]--;
	}
	//si el array ha quedado a 0 quiere decir que las dos palabras tienen exactamente las mismas letras
	n = 0;
	bool anagrama = true;
	while (anagrama && n < 27) {
		if (letras[n] != 0) anagrama = false;
		n++;
	}
	return anagrama;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
	// leer los datos de la entrada
	string palabra1, palabra2;
	cin >> palabra1 >> palabra2;
	vector <char> pal1, pal2;
	for (int i = 0; i < palabra1.size(); i++)
	{
		pal1.push_back(palabra1[i]);
		pal2.push_back(palabra2[i]);
	}
	bool sol = resolver(pal1, pal2);
	//escribir sol
	if (sol) cout << "SI\n";
	else cout << "NO\n";
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