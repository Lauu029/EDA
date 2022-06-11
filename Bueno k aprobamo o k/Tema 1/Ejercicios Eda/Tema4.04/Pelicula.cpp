#include "Pelicula.h"


istream& operator>>(istream& input, Pelicula& p)
{

	Hora duracion;
	input >> p.h >> duracion ;
	getline(input, p.nombre);
	p.h += duracion; 
	return input;
}



Pelicula::Pelicula() {}

Pelicula::~Pelicula() {}

bool Pelicula::operator<(const Pelicula& p) const
{
	if (h < p.h) return true;
	else if (h == p.h) {
		if (nombre < p.nombre) return true;
		else return false;
	}
	else return false;
}

