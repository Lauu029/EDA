#include "Polinomio.h"
#include <algorithm>

Polinomio::Polinomio() {}

Polinomio::~Polinomio() {}


int Polinomio::calculate(int num)
{
	int n=0;
	for (int i = 0; i < polinomio.size(); i++)
	{
		n += pow(num, polinomio[i].first) * polinomio[i].second;
	}
	return n;
}

void Polinomio::add(const pair<int, int>& monomio)
{
	if (monomio.second == 0) return;
	if (polinomio.empty()) {
		polinomio.push_back(monomio);
		return;
	}
	
	int i = 0;
	bool encontrado = false;

	while (i < polinomio.size() && !encontrado)
	{
		if (monomio.first == polinomio[i].first) {
			polinomio[i].second += monomio.second;
			return;
		}
		else if (monomio.first < polinomio[i].first) encontrado = true;
		else i++;
	}

	polinomio.push_back(monomio);
	if (encontrado) sort(polinomio.begin() + i , polinomio.end());

}
