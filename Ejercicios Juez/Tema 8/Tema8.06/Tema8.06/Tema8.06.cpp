// Plantilla para el ejercicio de Venta de libros

#include <iostream>
#include <stdexcept>
#include <string>
#include <fstream>
#include <map>
#include <unordered_map>
#include <utility>
#include <list>

using namespace std;
using libro = string;
struct libVendidos {
	int numVentas;
	int numEjemplares;
	string libro;
};
bool operator < (const libVendidos& l1, const libVendidos& l2) {
	return l1.numVentas <= l2.numVentas;
}
class VentaLibros {
private:
	map<libro, int> libros;
	map<int, int> ventas;
	list<libVendidos> listaVentas;
public:
	VentaLibros() {};
	~VentaLibros() {};
	void nuevoLibro(libro lib, int num) {
		//si no existe el libro lo inicializa con la cantidad que se le pide
		if (libros.count(lib) == 0) {
			libros[lib] = num;
		}
		//si ya existia suma el numero de ejemplares
		else libros[lib] += num;
	}
	void comprar(libro lib) {
		if (libros.count(lib) == 0) throw invalid_argument("Libro no existente");
		else if (libros[lib] == 0) throw out_of_range("No hay ejemplares");
		else {
			libros[lib]--;
		}
		//Hay que añadir lo de las compras
	}
	bool estaLibro(libro lib) {
		return libros.count(lib);
	}
	void elimLibro(libro lib) {
		libros.erase(lib);
	}
	int numEjemplares(libro lib) {
		if (libros.count(lib) == 0) throw invalid_argument("Libro no existente");
		else return libros[lib];
	}
	/*list<libVentas> top10(){
		int i = 0;
		auto g = ventas.begin();
		while (g != ventas.end() && i<=10) {
			if (g.second != 0)
				listaVentas.push_back({ g.second,g.first });
			i++;
		}
		listaVentas.sort();
		return listaVentas;
	}*/
};
// Muestra el contenido de una lista

//void mostrar(list<libVentas> l) {
//
//	for (auto e : l) {
//		cout << "    " << e.libro << '\n';
//	}
//}

bool resuelveCaso() {
	int numOp;

	cin >> numOp;
	if (!cin) return false;

	VentaLibros amazon;

	string operacion, titulo;

	for (int i = 0; i < numOp; ++i) {
		cin >> operacion;
		cin.ignore(1); // saltar blanco
		if (operacion == "nuevoLibro") {
			int unidades;
			cin >> unidades;
			cin.ignore(1);
			getline(cin, titulo);
			amazon.nuevoLibro(titulo, unidades);
		}
		else if (operacion == "comprar") {
			getline(cin, titulo);
			try {
				amazon.comprar(titulo);
			}
			catch (out_of_range const& e) {
				cout << e.what() << '\n';
			}
			catch (invalid_argument const& e) {
				cout << e.what() << '\n';
			}
		}
		else if (operacion == "estaLibro") {
			getline(cin, titulo);
			if (amazon.estaLibro(titulo)) {
				cout << "El libro " << titulo << " esta en el sistema\n";
			}
			else {
				cout << "No existe el libro " << titulo << " en el sistema\n";
			}
		}
		else if (operacion == "elimLibro") {
			getline(cin, titulo);
			amazon.elimLibro(titulo);
		}
		else if (operacion == "numEjemplares") {
			getline(cin, titulo);
			if (amazon.estaLibro(titulo)) {
				cout << "Existen " << amazon.numEjemplares(titulo) << " ejemplares del libro " << titulo << '\n';
			}
			else {
				cout << "No existe el libro " << titulo << " en el sistema\n";
			}
		}
		else if (operacion == "top10") {
			cout << "TOP10\n";
			//mostrar(amazon.top10());
		}
	}
	// fin del caso
	cout << "---\n";
	return true;

}

int main() {
#ifndef DOMJUDGE
	ifstream in("datos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

	while (resuelveCaso()) {}

#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif
	return 0;
}