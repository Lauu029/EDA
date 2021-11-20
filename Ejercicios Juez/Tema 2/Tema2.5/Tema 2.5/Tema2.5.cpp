// Nombre del alumno Laura Gómez Bodego
// Usuario del juez VJ23


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;

// función que resuelve el problema
bool resolver(const vector<int>& datos, int ini, int fin,int nCasos) 
{
    //Caso base, vector vacío
    if (nCasos==0)
    {
        return false;
    }
    else if (fin < ini) 
    {
        return false;
    }
    else 
    {
        int mitad = (ini + fin) / 2;
        //compruebo el valor del medio para ver que mitad tengo que comprobar
        if (datos[mitad] == mitad) {
            return true;
        }
        /*si el elemento del medio es mayor que su posición, el resto de elementos que están
        por delante van a ser siempre mayores que el valor de su posición, solo habria que mirar
        en la primera mitad del vector*/
        else if (datos[mitad] > mitad) 
        {
            return resolver (datos, ini, mitad - 1,nCasos);
        }
        else {
            return resolver (datos, mitad + 1, fin,nCasos);
        }
    }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    int numCasos;
    cin >> numCasos;
    vector<int> datos(numCasos);
    for (int i = 0; i < numCasos; i++) {
        cin >> datos[i];
    }
    if (resolver(datos, 0, numCasos - 1, numCasos))
        cout << "SI\n";
    else
        cout << "NO\n";
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    ifstream in("datos.txt");
    auto cinbuf = cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif

    int numCasos;
    cin >> numCasos;
    for (int i = 0; i < numCasos; ++i)
        resuelveCaso();


    // Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    cin.rdbuf(cinbuf);
    //system("PAUSE");
#endif

    return 0;
}
