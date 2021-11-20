#include <iostream>
#include <iomanip>
#include <fstream>
#include "queue_eda.h"
using namespace std;


template <class T>
class queue_plus : public queue<T> {
    using Nodo = typename queue<T>::Nodo;

public:
    //Algoritmo de orden O(n) tiene una búsqueda lineal(dividida en dos buscadores) la búsqueda deppende solamente del tamaño de la lista(n)
    void cuela(const T& a, const T& b){
        // Ojo que para acceder a prim o ult hay que escribir this->prim o this->ult

        //busco las posiciones de a y b
        Nodo* auxA = this->prim;
        //Busco a
        while (auxA != nullptr && !(a == auxA->elem)) {
            auxA = auxA->sig;
        }
        //Si no ha encontrado a no hace nada más
        if (auxA != nullptr) {
            //Busco b a partir de a
            Nodo* auxB = auxA->sig;
            Nodo* antB = auxA;

            while (auxB != nullptr && !(b == auxB->elem)) {
                antB = auxB;
                auxB = auxB->sig;
            }
            //si no ha encontrado b no hace nada más
            if (auxB != nullptr) {
                //Si b es el último
                if (auxB->sig == nullptr) {
                    antB->sig = nullptr;
                    auxB->sig = auxA->sig;
                    auxA->sig = auxB;
                    this->ult = antB;
                }
                else {
                    antB->sig = auxB->sig;
                    auxB->sig = auxA->sig;
                    auxA->sig = auxB;

                }
            }
        }
    }
};


// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int n, a, b;
    queue_plus<int> q;
    cin >> n;
    if (n == -1) return false;
    while (n != -1){
        q.push(n);
        cin >> n;
    }
    cin >> a >> b;

    // llamada a metodo
    q.cuela(a,b);

    // escribir sol (pero antes dar una vuelta para comprobar que la cola está bien formada)
    for (int i = 0; i < q.size(); ++i){
        n = q.front();
        q.pop();
        q.push(n);
    }
    // Ahora imprimimos la cola y de paso la dejamos vacía
    while (!q.empty()){
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;
    return true;
}

//#define DOMJUDGE
int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("datos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif

    while (resuelveCaso())
        ;

    // Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    //system("PAUSE");
#endif

    return 0;
}
