// Nombre del alumno Laura Gómez Bodego
// Usuario del Juez VJ23


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;

// función que resuelve el problema
int posicion(vector<int> const& datos, int ini, int fin)
{
    //si solo hay un elemento, devuelve esa posición
    if (ini == fin)
        return ini;
    else if (ini + 1 == fin) {
        if (ini % 2 == 0)
            return ini;
        else
            return fin;
    }
    else {
        //elemento de la mitad del vector
        int mitad = ((ini + fin) / 2) ;
        //si es distinto que el de alante y el de atrás, ese es el elemento buscado
        if ((datos[mitad] != datos[mitad + 1]) && (datos[mitad] != datos[mitad - 1]))
            return mitad;
        //si el que es igual al del medio es el de la derecha, el elemento está a la izquierda
        else if ((datos[mitad] == datos[mitad - 1]) && mitad % 2 != 0)
        {
            return posicion(datos, mitad + 1, fin);
        }
        else if ((datos[mitad] != datos[mitad - 1]) && mitad % 2 != 0)
        {
            return posicion(datos, ini, mitad-1);
        }
        else if ((datos[mitad] == datos[mitad - 1]) && mitad % 2 == 0)
        {
            return posicion(datos,ini, mitad-1);
        }
        //si no, está a la izq
        else 
        {
            return posicion(datos, mitad+1, fin);
        }
    }

}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    int nCasos;
    cin >> nCasos;
    vector <int> datos(nCasos);
    for (int i = 0; i < nCasos; i++) {
        cin >> datos[i];
    }
    
    cout << posicion(datos, 0, nCasos - 1)<< endl;
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("datos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 


    int numCasos;
    cin >> numCasos;
    for (int i = 0; i < numCasos; ++i)
        resuelveCaso();


    // Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    //system("PAUSE");
#endif

    return 0;
}