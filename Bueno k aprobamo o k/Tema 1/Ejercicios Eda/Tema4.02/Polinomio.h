#pragma once
#include <ostream>
#include <istream>
#include <vector>
#include <math.h>

using namespace std;

class Polinomio
{
public:
	Polinomio();
	~Polinomio();

	vector < pair<int, int> > polinomio;
	
	int calculate(int num);

	void add(const pair<int, int>& monomio);
};

