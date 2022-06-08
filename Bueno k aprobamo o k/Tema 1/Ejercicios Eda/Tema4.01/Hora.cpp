#include "Hora.h"

Hora::Hora() {}

Hora::~Hora() {}

bool Hora::esValida() const
{
	if ((hora >= 0 && hora < 24) && (min >= 0 && min < 60) && (sec >= 0 && sec < 60)) return true;
	else return false;
}

bool Hora::operator<(const Hora& h) const
{
	if (hora <= h.hora) {
		if (hora < h.hora) return true;
		else if (min <= h.min) {
			if (min < h.min) return true;
			else if (sec < h.sec) return true;
			else return false;
		}
		else return false;
	}
	else
		return false;
}

ostream& operator<<(ostream& out, const Hora& h)
{
	if (h.hora < 10)
		out << "0";
	out << h.hora << ":";
	if (h.min < 10)
		out << "0";
	out << h.min << ":";
	if (h.sec < 10)
		out << "0";
	out << h.sec << endl;

	return out;
	// TODO: Insertar una instrucci�n "return" aqu�
}

istream& operator>>(istream& input, Hora& h)
{
	char c = ':';
	input >> h.hora >> c >> h.min >> c >> h.sec;
	return input;
}


