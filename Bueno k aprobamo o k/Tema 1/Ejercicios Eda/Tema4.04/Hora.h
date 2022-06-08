#pragma once
#include <istream>
#include <ostream>
#include <string>
using namespace std;
class Hora
{
public:
	Hora();
	~Hora();

	int hora;
	int min;
	int sec;

	bool esValida()const;
	//sobrecarga de operadores
	friend ostream& operator<<(ostream& out, const Hora& h);
	friend istream& operator>>(istream& input, Hora& h);
	bool operator<(const Hora& h) const;
	bool operator==(const Hora& h) const;
	void operator+=(const Hora& h);
};

