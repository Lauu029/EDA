// Elisa Todd Rodríguez
// Usuario del Juez: VJ59


#include <iostream>
#include <iomanip>
#include <fstream>
#include "list_eda.h"
using namespace std;


template <class T>
class list_plus : public list<T> {
    using iterator = typename list<T>::iterator;

public:
    // elimina todas las repeticiones de un elemento
    void borraNum(const int n, list<T>& l) {
        list<int>::iterator it = l.begin();

        while (it != l.end()) {
            if ((*it) == n)
                it = l.erase(it);
            else
                ++it;
        }
    }
};


// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    int n;
    list_plus<int> lista;

    cin >> n;
    while (n != -1) {
        lista.insert(lista.end(),n); // Insertar al final
        cin >> n;
    }

    cin >> n; // elemento a eliminar

    for (auto const& v : lista)
        cout << v << " ";

    cout << endl;

    lista.borraNum(n, lista);

    for (auto const& v : lista)
        cout << v << " ";

    cout << endl;
    //list<int> listaNueva(lista.eraseElement(lista.begin(), n));

    // escribir sol


}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("datos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 


    int numCasos;
    std::cin >> numCasos;
    for (int i = 0; i < numCasos; ++i)
        resuelveCaso();


    // Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif

    return 0;
}