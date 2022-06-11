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

bool Hora::operator==(const Hora& h) const
{
	return (hora == h.hora && min == h.min && sec == h.sec);
}

void Hora::operator+=(const Hora& h) 
{
	sec += h.sec;
	if (sec > 59) {
		int extra= sec / 60;
		sec -= 60 * extra;
		min += extra;
	}
	min += h.min;
	if (min > 59) {
		int extra = min / 60;
		min -= 60 * extra;
		hora += extra;
	}
	hora += h.hora;
	if (hora > 23) throw new exception();
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
	out << h.sec;

	return out;
	// TODO: Insertar una instrucción "return" aquí
}

istream& operator>>(istream& input, Hora& h)
{
	char c = ':';
	input >> h.hora >> c >> h.min >> c >> h.sec;
	return input;
}


