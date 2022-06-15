
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <unordered_map>

using namespace std;

class carnet_puntos {
private:
	unordered_map <string, int> carnets;
	const int PUNTOS = 15;
	//almacena cuantos conductores tienen los puntos indicados
	vector<int>cantPuntos;
public:
	carnet_puntos() :cantPuntos(PUNTOS + 1, 0) {};
	void nuevo(string dni) {
		//cuenta si hay mas elementos en la lista con ese dni
		if (carnets.count(dni) == 1) {
			throw domain_error("Conductor duplicado");
		}
		else {
			carnets[dni] = PUNTOS;
			cantPuntos[PUNTOS]++;
		}
	}
	void quitar(string dni, int puntos) {
		if (carnets.count(dni) == 0) {
			throw domain_error("Conductor inexistente");
		}
		else {
			int nuevPuntos = carnets[dni];
			cantPuntos[nuevPuntos]--;
			nuevPuntos -= puntos;
			if (nuevPuntos < 0)	nuevPuntos = 0;

			cantPuntos[nuevPuntos]++;
			carnets[dni] = nuevPuntos;
		}
	}
	int consultar(string dni) {
		if (carnets.count(dni) == 0) {
			throw domain_error("Conductor inexistente");
		}
		return carnets[dni];

	}
	int cuantos_con_puntos(int puntos) {
		if (puntos < 0 || puntos>15) {
			throw domain_error("Puntos no validos");
		}

		return cantPuntos[puntos];

	}
};

bool resuelveCaso() {
	std::string orden, dni;
	int punt;
	std::cin >> orden;
	if (!std::cin)
		return false;

	carnet_puntos dgt;

	while (orden != "FIN") {
		try {
			if (orden == "nuevo") {
				cin >> dni;
				dgt.nuevo(dni);
			}
			else if (orden == "quitar") {
				cin >> dni >> punt;
				dgt.quitar(dni, punt);
			}
			else if (orden == "consultar") {
				cin >> dni;
				punt = dgt.consultar(dni);
				cout << "Puntos de " << dni << ": " << punt << '\n';
			}
			else if (orden == "cuantos_con_puntos") {
				cin >> punt;
				int cuantos = dgt.cuantos_con_puntos(punt);
				cout << "Con " << punt << " puntos hay " << cuantos << '\n';
			}
			else
				cout << "OPERACION DESCONOCIDA\n";
		}
		catch (std::domain_error e) {
			std::cout << "ERROR: " << e.what() << '\n';
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
