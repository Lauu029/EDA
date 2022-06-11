#include <ostream>

#include "queue_eda.h"

	using namespace std;
template <class T>
class queueIntrod : public queue<T>
{
	using Nodo = typename queue<T>::Nodo;
public:
	void mezclaColas(queueIntrod<T>& nuevo) {
		this->prim = mezcla(this->prim, nuevo.prim, nuevo.ult);
		this->nelems += nuevo.nelems;
		nuevo.prim = nullptr;
		nuevo.ult = nullptr;
		nuevo.nelems = 0;
	}
private:

	//sois unos pedazo de putos wuarros askerosos de mierda los dos os odio <3
	Nodo* mezcla(Nodo* a, Nodo* b, Nodo* c) {
		Nodo* aux = nullptr;
		if (a == nullptr) {
			this->ult = c;
			return b;
		}
		else if (b == nullptr)
			return a;

		if (a->elem <= b->elem) {
			aux = a;
			aux->sig = mezcla(a->sig, b, c);
		}
		else {
			aux = b;
			aux->sig = mezcla(a, b->sig, c);
		}
		return aux;
	}
};

template <class T>
inline ostream& operator<<(ostream& out,  queueIntrod<T>& cola) {
	for (int i = 0; i < cola.size(); i++)
	{
		out << cola.front() << " ";
		cola.push(cola.front());
		cola.pop();
	}
	return out;
}

