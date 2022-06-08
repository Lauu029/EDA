#pragma once
#include <istream>
#include <ostream>
#include <string>
#include "Hora.h"
using namespace std;
class Pelicula
{
public:

		Hora h;
		string nombre;

	Pelicula();
	~Pelicula();

	friend istream& operator>>(istream& input, Pelicula& p);
	bool operator< (const Pelicula& p) const;


};

