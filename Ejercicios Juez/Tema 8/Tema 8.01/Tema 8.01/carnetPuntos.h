#ifndef carnet_puntos_h
#define carnet_puntos_h
#include <unordered_map>
#include <vector>
#include <string>
#include <stdexcept>

using namespace std;
class carnet_puntos {
private:
	//Variable de máximo de puntos que puede tener un carnet
	const int MAXPUNTOS = 15;
	//el map guarda cada carnet y el numero de puntos que tiene
	unordered_map <string, int> carnets;
	//vector que guarda en cada posicion los dni que tienen ese numero de puntos
	vector<int> numCar;
protected:
public:
	//constructora
	//inicializo el vector de los puntos con la cantidad de puntos máximos y pongo a 0 todo 
	carnet_puntos(): numCar(MAXPUNTOS + 1,0) {};
	void nuevo(string dni) {
		//primero comprueba que no está ya añadido
		if (carnets.count(dni) == 1) {
			throw domain_error ("Conductor duplicado");
		}
		else {
			//lo añade con el máximo de puntos
			carnets[dni] = MAXPUNTOS;
			numCar[MAXPUNTOS]++;
		}
	}
	void quitar(string dni, int puntos) {
		//el conductor no existe
		if (carnets.count(dni) == 0) {
			throw domain_error("Conductor inexistente");
		}
		else
		{
			numCar[carnets[dni]]--;

			carnets[dni] -= puntos;

			if (carnets[dni] < 0) carnets[dni] = 0;

			numCar[carnets[dni]]++;
		}
	}
	int consultar(string dni) {
		if (carnets.count(dni) == 0)
			throw domain_error("Conductor inexistente");
		return carnets[dni];
	}
	int cuantos_con_puntos(int puntos) {
		if (puntos < 0 || puntos>15) 
			throw domain_error("Puntos no validos");
		return numCar[puntos];
	}

};
#endif// carnetPuntos_h
