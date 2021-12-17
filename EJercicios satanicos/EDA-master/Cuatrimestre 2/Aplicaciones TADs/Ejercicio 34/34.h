#ifndef carnet_h
#define carnet_h

#include <unordered_map>
#include <stdexcept>
#include <string>
#include <vector>

class carnet_puntos {
	const int MAXPUNTOS = 15;
	std::unordered_map<std::string, int> map;
	std::vector<int> cuantosConPuntos;

public:
	//Por que le pasa dos argumentos a cuantosConPuntos si es un vector??
	//en principio por lo que veo puede ser que esta guardando 
	//inicializa un map con 15 casillas, todas vacías(son de 00 a 16)
	carnet_puntos(): cuantosConPuntos(MAXPUNTOS + 1, 0) {}

	void nuevo(const std::string &dni) {
		if (map.count(dni) == 1)
			throw std::domain_error("Conductor duplicado");
		map[dni] = MAXPUNTOS;
		//añade uno al máximo porque entra con todos los puntos
		cuantosConPuntos[MAXPUNTOS]++;
	}

	void quitar(const std::string &dni, int puntos) {
		if (map.count(dni) == 0)
			throw std::domain_error("Conductor inexistente");
		//at consulta la clave,si no tiene puntos lo deja así porque no puede tener negativos
		if (map.at(dni) == 0)
			map[dni] = 0;
		//si tiene menos puntos de los que se le quitan lo deja a 0
		else if (map.at(dni) < puntos) {
			cuantosConPuntos[map[dni]]--;
			map[dni] = 0;
			cuantosConPuntos[0]++;
		} 
		//si no , resta los necesarios
		else {
			cuantosConPuntos[map[dni]]--;
			map[dni] -= puntos;
			cuantosConPuntos[map[dni]]++;
		}
	}

	int consultar(const std::string &dni) const {
		if (map.count(dni) == 0)
			throw std::domain_error("Conductor inexistente");
		return map.at(dni);
	}

	int cuantos_con_puntos(int puntos) const {
		if (puntos < 0 || puntos > MAXPUNTOS)
			throw std::domain_error("Puntos no validos");
		
		return cuantosConPuntos[puntos];
	}
};

#endif