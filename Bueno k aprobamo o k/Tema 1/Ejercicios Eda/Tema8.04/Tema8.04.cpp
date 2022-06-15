
#include <iostream>
#include <string>
#include <cassert>
#include <fstream>
#include <stdexcept>
#include <list>
#include <vector>
#include <unordered_map>
using namespace std;

using cancion = std::string;
using artista = std::string;
struct infoCancion {
	artista art;
	int duracion;
};
class iPud {
private:
	unordered_map<cancion, infoCancion> cancionesIpud;
	list <cancion> listaRep;
	list <cancion> reproducidas;
public:
	void addSong(cancion s, artista a, int d) {
		if (cancionesIpud.count(s) == 1) throw invalid_argument("");
		cancionesIpud[s].art = a;
		cancionesIpud[s].duracion = d;
	}
	void addToPlaylist(cancion s) {
		if (cancionesIpud.count(s) == 1) {
			auto it = listaRep.begin();
			bool add = true;
			while (it != listaRep.end() && add) {
				if (*it == s) add = false;
				++it;
			}
			if (add) listaRep.push_back(s);
		}
		else throw domain_error("");
	}
	cancion current() {
		if (listaRep.empty())throw invalid_argument("current");
		return listaRep.front();
	}
	void play() {
		if (!listaRep.empty()) {
			auto it = reproducidas.begin();
			while (it != reproducidas.end()) {
				if (*it == listaRep.front())
					it = reproducidas.erase(it);
				else
					++it;
			}
			reproducidas.push_front(listaRep.front());
			listaRep.pop_front();
		}
	}
	int totalTime() {
		int total = 0;
		if (!listaRep.empty()) {
			for (auto it : listaRep)
				total += cancionesIpud[it].duracion;
		}
		return total;
	}
	vector<cancion> recent(int n) {
		if (n > reproducidas.size())n = reproducidas.size();
		vector<cancion>salida;
		int i = 0;
		auto it = reproducidas.begin();
		for (int i = 0; i < n; i++)
		{
			salida.push_back(*it);
			++it;
		}
		return salida;
	}
	void deleteSong(cancion s) {
		if (cancionesIpud.count(s) == 0) {

			cancionesIpud.erase(s);
			auto it = reproducidas.begin();
			while (it != reproducidas.end()) {
				if (*it == s)
					it = reproducidas.erase(it);
				else
					++it;
			}
			it = listaRep.begin();
			while (it != listaRep.end()) {
				if (*it == s)
					it = listaRep.erase(it);
				else
					++it;
			}
		}
	}
};

bool resuelve() {
	string operacion;
	cin >> operacion;
	if (!cin)
		return false;
	cancion tit; artista aut; int dur;
	iPud ipud;
	while (operacion != "FIN") {
		try {
			if (operacion == "addSong") {
				cin >> tit >> aut >> dur;
				ipud.addSong(tit, aut, dur);
			}
			else if (operacion == "addToPlaylist") {
				cin >> tit;
				ipud.addToPlaylist(tit);
			}
			else if (operacion == "current") {
				tit = ipud.current(); // aunque no se hace nada, puede producir error
			}
			else if (operacion == "play") {
				try {
					string tocando = ipud.current(); // para saber si la lista es vacía
					ipud.play();
					cout << "Sonando " << tocando << '\n';
				}
				catch (invalid_argument e) {
					cout << "No hay canciones en la lista\n";
				}
			}
			else if (operacion == "totalTime") {
				cout << "Tiempo total " << ipud.totalTime() << '\n';
			}
			else if (operacion == "recent") {
				int N;
				cin >> N;
				auto lista = ipud.recent(N);
				if (lista.empty())
					cout << "No hay canciones recientes\n";
				else {
					cout << "Las " << lista.size() << " mas recientes\n";
					for (auto const& s : lista)
						cout << "    " << s << '\n';
				}
			}
			else if (operacion == "deleteSong") {
				cin >> tit;
				ipud.deleteSong(tit);
			}
			else { // operacion desconocida
				assert(false);
			}
		}
		catch (invalid_argument e) {
			cout << "ERROR " << e.what() << '\n';
		}
		cin >> operacion;
	}
	cout << "---\n";
	return true;
}

int main() {

	// ajuste para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
   // _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	std::ifstream in("datos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

	while (resuelve());

	// restablecimiento de cin
#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	//system("pause");
#endif
	return 0;
}
