#ifndef autoescuela_h
#define autoescuela_h

#include <map>
#include <vector>
#include <string>
#include <stdexcept>
struct infoAlumno {
	int puntos;
	string profesor;
};
class AutoEscuela {
private:
	map<string, infoAlumno> alumnos;
	map<string, map<string, int>> profesores;
public:
	AutoEscuela() {	};

	void alta(string alumno, string profesor) {
		if()
		profesores[profesor].insert({ alumno,0 });
	}
	bool es_alumno(string alumno, string profesor) {

	}
};
#endif