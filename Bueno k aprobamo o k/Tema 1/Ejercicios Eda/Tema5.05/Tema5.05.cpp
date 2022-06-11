// Nombre del alumno Laura Gómez Bodego
// Usuario del Juez VJ23

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include "queue_eda.h"

using namespace std;

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int entrada;
    cin >> entrada;
    queue<int>datos;
    if (!std::cin)
        return false;
    while (entrada != 0) {
        datos.push(entrada);
        cin >> entrada;
    }
    datos.invierte();
    while (!datos.empty()) {
        cout << datos.front() << " ";
        datos.pop();
    }
    cout << endl;
    return true;

}

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
    system("PAUSE");
#endif

    return 0;
}