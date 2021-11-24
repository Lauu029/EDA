#include "bintree_eda.h"
#include <string>

/*Tema 6
* ARBOLES BINARIOS
int main() {
	bintree<char>d('d');
	bintree<char>c(bintree(), 'c', d);
	bintree<char>b('b');
	bintree<char>a(b, 'a', c);
}*/

/*Como destruir la estructura
* Delegamos cada cosa al izq y al derecho y como es recursiva se delega a los hijos
* 
protected:
libera(Link ra) {
	if (ra != nullptr) {
		libera(ra->left);
		libera(ra->right);
		delete ra;
	}
}

bool operator==(...&other) {
	//compara recibe los comienzos de dos arboles y compara si son iguales
	return compara(this->raiz, other->raiz);
}

bool compara(link r1, link r2) {
	if (r1 == r2) return true;
	else if (r1==nullptr || r2==nullptr) return false;
	else { 
		return compara(r1->left, r2->left) &&
			compara(r1->right, r2->right) &&
			(r1->elem == r2->elem)
	}
}

Link copia(Link ra) {
	if (ra == nullptr) return nullptr;
	return new TreeNode(copia(ra->left), ra->elem,
		copia(ra->right));
}*/

/*
Ejercicio juez hoy

el ejercicio es añadir una operación nueva 
se puede hacer no tocando la clase, clase queue_plus que hereda de queue y le añadimos el método solo para FRIKIS

*/

/*
* Aquí debería haber una clase entera en la que no me enteré de nada y
como soy gilipollas lo que tenía apuntado lo borré :)
*/

/*
* Puede haber varios arboles con el mismo perorden por tanto se representarán los hijos vacíos con -1
* 
* 
* A1
* Preorden: 3 2 1 5(sin representar los vacíos)
* Preorden*:3 2 -1 1 -1 -1 5 -1 -1
* 
* 
* A2
* Preorden: 3 2 1 5(es igual que A1 pero el arbol no es el mismo)
* Preorden*: 3 2 1 -1 -1 -1 5 -1 -1
* 
* Vamos a utilizar el segundo preorden para representar normalmente los árboles
* 
* Función para leer un árbol:
* 
bintree<T> leerArbol(..in) {
	cin >> raiz;
	if (raiz == -1) return bintree();
	hi = leerArbol(in);
	hd = leerArbol(in);
	return bintree(hi, raiz, hd);
}Esto vendría bien depurarlo para entenderlo pero en clase lo has pillado asi que en principio no hay problema
No es el definitivo, pero en principio el código está subido al campus, búscalo ahí
*/

/*
* Reconstrucción de un árbol con el preorden y el inorden
* A1:
* Inorden: 2 1 3 5
* Preorden: 3 2 1 5
* Inorden:(2 1)->inorden hijo izq (3)->raiz (5)->inorden hderecho
* Preorden:(3)->raíz (2 1)->preorden hiz (5)->preorden hderecho 
//Esto es para que lo pensemos en casa el como hacerlo lol xd matenme plz
*/

/*
* Aplicación de los arboles binarios de busqueda::
* 
* Rep. interna para TADs, Set y Map con complejidad O(log(n)) en buscar, insertar, eliminar 
* y recorrido ordenado
*/

/*
* TAD set mediante arbol binario de busqueda
* template <class T>
class set {
	using Link = TreeNode*;

	struct TreeNode {
		T elem;
		Link left;
		Link right;
	};

	Link raiz;
	int nelems;
	
	int count(T const& e) const {
		return pertenece(e, raiz) ? 1 : 0;
	}

	bool insert(T const&) {
		return inserta(e, raiz);
	}

protected:
	bool pertenece(T const& e, Link a) const {
		if (a == nullptr)return false;
		if (e < a->elem) return pertenece(e, a->iz);
		if (a->elem < e) return pertenece(e, a->dr);
		else return true;
	}
	//Pasa por referencia un parámetro de un puntero(link&a)
	bool inserta(T const& e, Link& a) {
		if (a == nullptr) {
			new TreeNode(e);
			nelems++;
			return true;
		}
		else if (e < a->elem) return inserta(e, a->iz);
		else if (a->elem < e) return inserta(e, a->dr);
		else//e==a->elem
			return false;
	}
	bool borra(T const& e, Link& a) {
		if (a == nullptr) return false;
		else if (e < a->elem) return borra(e, a->iz);
		else if (a->elem < e) return borra(e, a->dr);
		else {
			if (a->iz == nullptr || a->dr == nullptr) {
				
				a = (a->iz == nullptr) ? a->dr : a->iz;
				--nelems;
				delete aux;
			}
			else {//Tengo dos hijos
				subirMenorHD(a);
				--nelems;
			}
		}
	}
	void subirMenorHD(Link& a) {
		Link b = a->dr;
		Link padre = nullptr;
		while (b->iz != nullptr) {
			padre = b;
			b = b->iz;
		}
		if (padre != nullptr) {
			padre->iz = b->dr;
			b->dr = a->dr;
		}
		b->iz = a->iz;
		a = b;
		delete a;
	}
};*/

/*
//6.08
bool esOrdenado(..t, int& min, int& max) {
	if (t.empty()) return true;

	//variables locales que almacenan los datos que sse piden
	int minIz, maxIz, minDr, maxDr;
	bool esIz = esOrdenado(t.left(), minIz, maxIz);
	bool esDr = esOrdenado(t.right(), minDr, maxDr);

	//No hacen falta porque hemos hecho un codigo mas secsi
	//bool mayorQueIz = todosMayores(t.left(), t.root());
	//bool mayorQueDr = todosMayores(t.right(), t.root());

	min = min({ minIz, minDr,t.root() });
	max = max(...);

	return esIz && esDr && t.root() > maxIz && t.root() < minDir;
}*/

/*Tema 7 diccionarios
* TAD map*/

//Ejemplo Apariciones palabras
//Aquí metes la plantilla guapa

/*
map <string, int> apariciones;

string pal;
cin >> pal;
while (!cin.fail()) {
	if (apariciones.count(pal)) 
		apariciones[pal]++;
	else apariciones.insert({ pal, 1 });
	cin >> pal;
}

//Listar
for (auto [p,n] : apariciones)
		cout << p << " " << n << endl;*/
