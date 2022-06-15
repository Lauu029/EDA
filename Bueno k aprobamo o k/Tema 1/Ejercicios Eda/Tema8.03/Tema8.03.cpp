
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <map>
 
#include <unordered_map>
using namespace std;
using profesor = string;
struct infoAlumno {
	profesor prof;
	int puntos;
};
using alumno = string;
class AutoEscuela {
private:
	map<alumno, infoAlumno>alumnosAutoescuela;
public:
	AutoEscuela() {};

	void alta(alumno a, profesor p) {
		alumnosAutoescuela[a].prof = p;
		if (alumnosAutoescuela.count(a) == 0)
			alumnosAutoescuela[a].puntos = 0;
	}
	bool es_alumno(alumno a, profesor p) {
		return alumnosAutoescuela[a].prof == p;
	}
	int puntuacion(alumno a) {
		if (alumnosAutoescuela.count(a) == 0)throw domain_error("El alumno A no está matriculado");
		return alumnosAutoescuela[a].puntos;
	}
	void actualizar(alumno a, int n) {
		if (alumnosAutoescuela.count(a) == 0)throw domain_error("El alumno A no está matriculado");
		alumnosAutoescuela[a].puntos += n;
	}
	vector<alumno> examen(profesor p, int n) {
		vector<alumno>a;
		for (auto it : alumnosAutoescuela) {
			if (it.second.prof == p && it.second.puntos >= n)
				a.push_back(it.first);
		}
		return a;
	}
	void aprobar(alumno a) {
		if (alumnosAutoescuela.count(a) == 0)throw domain_error("El alumno A no está matriculado");
		alumnosAutoescuela.erase(a);
	}

};
bool resuelveCaso() {
	std::string orden, alum, prof;
	int punt;
	std::cin >> orden;
	if (!std::cin)
		return false;

	AutoEscuela escuela;

	while (orden != "FIN") {
		try {
			if (orden == "alta") {
				cin >> alum >> prof;
				escuela.alta(alum, prof);
			}
			else if (orden == "es_alumno") {
				cin >> alum >> prof;
				if (escuela.es_alumno(alum, prof))
					cout << alum << " es alumno de " << prof << '\n';
				else
					cout << alum << " no es alumno de " << prof << '\n';
			}
			else if (orden == "puntuacion") {
				cin >> alum;
				int puntos = escuela.puntuacion(alum);
				cout << "Puntuacion de " << alum << ": " << puntos << '\n';
			}
			else if (orden == "actualizar") {
				cin >> alum >> punt;
				escuela.actualizar(alum, punt);
			}
			else if (orden == "examen") {
				cin >> prof >> punt;
				cout << "Alumnos de " << prof << " a examen:\n";
				for (auto const& a : escuela.examen(prof, punt)) {
					cout << a << '\n';
				}
			}
			else if (orden == "aprobar") {
				cin >> alum;
				escuela.aprobar(alum);
			}
		}
		catch (std::domain_error e) {
			std::cout << "ERROR\n";
		}
		std::cin >> orden;
	}
	std::cout << "---\n";
	return true;
}

int main() {

	// ajuste para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
   // _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	std::ifstream in("datos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

	while (resuelveCaso());

	// restablecimiento de cin
#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	//system("pause");
#endif
	return 0;
}
