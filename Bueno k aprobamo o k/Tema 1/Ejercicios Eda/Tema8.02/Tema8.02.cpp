// Plantilla para el ejercicio del Consultorio Médico

#include <iomanip>
#include <iostream>
#include <fstream>
#include <string>
#include <stdexcept>
#include <cassert>
#include <unordered_map>
#include <map>
using namespace std;
class fecha {
private:
	int dia, hora, minuto;
public:
	fecha() {};
	fecha(int d, int h, int m) :dia(d), hora(h), minuto(m) {};
	bool operator<(fecha f)const {
		if (dia <= f.dia) {
			if (dia == f.dia) {
				if (hora <= f.hora) {
					if (hora == f.hora) {
						return minuto < f.minuto;
					}
					else return true;
				}
				else return false;
			}
			else return true;
		}
		return false;
	}
	friend ostream& operator<<(ostream& out, const fecha& f){
		if (f.hora < 10)out << "0";
		out << f.hora << ":";
		if (f.minuto < 10)out << "0";
		out	<< f.minuto;
		return out;
	}
	int d()const { return dia; }
	int h() const{ return hora; }
	int m()const { return minuto; }
};
using medico = string;
using paciente = string;
using pacMedico = map<fecha, paciente>;
class Consultorio {
private:

	unordered_map<medico, pacMedico> medicosConsulta;
public:
	void nuevoMedico(medico m) {
		if (medicosConsulta.count(m) == 0)
			medicosConsulta[m] = pacMedico();
	}
	void pideConsulta(paciente p, medico m, fecha f) {
		if (medicosConsulta.count(m) == 0) throw invalid_argument("Medico no existente");
		else {
			if (medicosConsulta[m].count(f) == 1) throw invalid_argument("Fecha ocupada");
			else medicosConsulta[m][f] = p;
		}
	}
	paciente siguientePaciente(medico m) {
		if (medicosConsulta.count(m) == 0) throw invalid_argument("Medico no existente");
		else {
			if (medicosConsulta[m].size() == 0) throw invalid_argument("No hay pacientes");
			else return medicosConsulta[m].begin()->second;
		}
	}
	void atiendeConsulta(medico m) {
		if (medicosConsulta.count(m)==0)throw invalid_argument("Medico no existente");
		else {
			if (medicosConsulta[m].size() == 0) throw invalid_argument("No hay pacientes");
			else 
				medicosConsulta[m].erase(medicosConsulta[m].begin());
		}
	}
	pacMedico listaPacientes(medico m,fecha  f) {
		if (medicosConsulta.count(m) == 0)throw invalid_argument("Medico no existente");
		else {
			pacMedico::iterator it = medicosConsulta[m].begin();
			pacMedico salida;
			
			for (auto it:medicosConsulta[m]) {
				if (it.first.d() == f.d()) salida[it.first] = it.second;
			}
			return salida;	
		}
	}

};

int casos = 0;
bool resuelve() {

	int N;
	cin >> N;
	if (!cin) return false;

	string inst; medico med; paciente pac; int d, h, m; char c;
	Consultorio con;

	for (int i = 0; i < N; ++i) {
		try {
			cin >> inst;
			if (inst == "nuevoMedico") {
				cin >> med;
				con.nuevoMedico(med);
			}
			else if (inst == "pideConsulta") {
				cin >> pac >> med >> d >> h >> c >> m;
				con.pideConsulta(pac, med, fecha(d, h, m));
			}
			else if (inst == "siguientePaciente") {
				cin >> med;
				pac = con.siguientePaciente(med);
				cout << "Siguiente paciente doctor " << med << '\n';
				cout << pac << '\n';
			}
			else if (inst == "atiendeConsulta") {
				cin >> med;
				con.atiendeConsulta(med);
			}
			else if (inst == "listaPacientes") {
				cin >> med >> d;
				auto vec = con.listaPacientes(med, fecha(d, 0, 0));
				cout << "Doctor " << med << " dia " << d << '\n';
				for (auto p : vec) {
					cout << p.second << ' ' << p.first << '\n';
				}
			}
			else
				assert(false);
		}
		catch (invalid_argument e) { cout << e.what() << '\n'; }
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
