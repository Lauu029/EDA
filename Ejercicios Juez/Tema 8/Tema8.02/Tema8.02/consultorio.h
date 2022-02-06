 
#ifndef consultorio_h
#define consultorio_h
#include <map>
#include <vector>
#include <string>
#include <stdexcept>
#include "fecha.h"
using namespace std;
struct cita {

};

using paciente = map<fecha, string>;
class Consultorio {
private:
	map <string,paciente> medico;
	
protected:
public:
	void nuevoMedico(string med) {
		//Si el m�dico no existe lo inicializa vac�o
		if (medico.count(med) == 0) medico[med] = paciente();
	}
	void pideConsulta(string pac, string med, fecha f) {
		//el m�dico no existe, lanza error
		if (medico.count(med) == 0) throw invalid_argument("Medico no existente");
		else {
			//si ha encontrado la fecha lanza excepci�n
			if (medico[med].find(f) != medico[med].cend()) throw invalid_argument("Fecha ocupada");
			else medico[med][f] = pac;
		}
	}
	void atiendeConsulta(string med) {
		if (medico.count(med) == 0) throw invalid_argument("Medico no existente");
		else {
			auto g = medico[med];
			//si no encuentra pacientes lanza error
			if (medico[med].empty()) throw invalid_argument("No hay pacientes");
			else medico[med].erase(medico[med].begin());
		}
	}
	string siguientePaciente(string med) {
		if (medico.count(med) == 0) throw invalid_argument("Medico no existente");
		else {
			//si no encuentra pacientes lanza error
			if (medico[med].empty()) throw invalid_argument("No hay pacientes");
			else return  medico[med].begin()->second;
		}
	}
	paciente listaPacientes(string med, fecha f) {
		if (medico.count(med) == 0) throw invalid_argument("Medico no existente");
		else {
			paciente pacDia;
			if (medico[med].empty()) {
				//devuelve el mapa vac�o
				return pacDia;
			}
			else {
				for (auto g : medico[med]) {
					
					if (g.first.getDia() == f.getDia()) {
						//(aqui tengo que meter una condicion y no se cual xd)
						pacDia[g.first] = g.second;
					}
				}
				return pacDia;
			}
		}
	}

};
#endif// consultorio_h
