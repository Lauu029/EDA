// Nombre del alumno Laura Gómez Bodego
// Usuario del Juez VJ23


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include "Set.h"

using namespace std;

// función que resuelve el problema
void resolver(vector<int>& datos, int k) 
{
    Set<int> valores;
    //Mete los k primero valores de k en set
    for (int i = 0; i < k; i++) {
        valores.add(datos[i]);
    }

    for (int j = k; j < datos.size(); j++)
    {
        //Si solo hay un elemento en valores (max=min) mete el valor que haya encontrado, sea cual sea
        if (valores.getMin() == valores.getMax()) 
        {
            valores.add(datos[j]);
        }
        //Si encuentra un elemento más pequeño que el minimo de los que ya tiene,
        //lo mete en set y borra el máximo del vector para no variar el número de elementos que tiene
        else if (datos[j] < valores.getMin()) {
            valores.add(datos[j]);
            valores.removeMax();
        }
        //Si encuentra un elemento más pequeño que el máximo de los que ya tiene,
        //lo mete en set y borra el máximo del vector para no variar el número de elementos que tiene
        else if (datos[j] < valores.getMax() && datos[j] != valores.getMin()) {
            valores.add(datos[j]);
            valores.removeMax();
        }
    }
    //escribe la solucion
    for (int i = 0; i < valores.size(); i++)
        cout << valores.toArray()[i] << " ";

}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int numCasos;
    cin >> numCasos;
    if (numCasos==0)
        return false;

    vector<int> datos;
    int numVector;
    cin >> numVector;
    while (numVector != -1)
    {
        datos.push_back(numVector);
        cin >> numVector;
    }

    resolver(datos,numCasos);

    // escribir sol
    
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
