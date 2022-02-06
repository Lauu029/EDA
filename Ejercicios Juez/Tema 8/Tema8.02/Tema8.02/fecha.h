
#ifndef fecha_h
#define fecha_h

#include <iomanip>
#include <stdexcept>
#include <iostream>

using namespace std;

class fecha {
private:
	int dia;
	int hora;
	int minuto;

protected:
public:
	fecha(int d, int h, int m) { dia = d; hora = h; minuto = m;}
	fecha(){}
	~fecha(){}

	bool operator<(fecha f2) const {
		if (dia < f2.dia) return true;
		else if (dia > f2.dia)return false;
		else {
			if (hora < f2.hora)return true;
			else if (hora > f2.hora)return false;
			else {
				if (minuto < f2.minuto) return true;
				else return false;
			}
		}
	}
	int getDia() const { return dia; }
	int getHora() const { return hora; }
	int getMinuto() const { return minuto; }

	void dibujaHora()const {
		cout << setw(2) << setfill('0')<< hora << ':' << setw(2) << setfill('0')<< minuto << "\n";
	}
};
#endif// fecha_h
