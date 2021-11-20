// Nombre del alumno Laura Gómez Bodego
// Usuario del Juez VJ23


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;

// función que resuelve el problema
int resolver(vector<int> const& v1, vector<int> const& v2, int ini, int fin)
{
    //Es un algoritmo de coste lineal porque solo depende del tamaño de los vectores
    //si tam < 2; T(n)=1c
    //si Tam >=2; T(n)/2=1c
    //si el segundo vector está vacío, solo hay un valor en el primero
    if (fin + 1 == 0)
        return v1[ini];

    else if (ini == fin)
        return v1[fin];

    //si el primer vector tiene dos elementos devuelve el primero si es el distinto y el segundo si no
    else if (ini == fin-1) 
    {
        if (v1[ini] == v2[ini])
            return v1[fin];
        else
            return v1[ini];
    }
    //resto de casos
    else 
    {
        int iniMitad = (ini + fin) / 2;
        int valor;
        //compara los elementos del medio del vector para ver si está en la primera o segunda mitad
        if (v1[iniMitad] == v2[iniMitad])//si coinciden, el número está en la segunda
        {
            valor = resolver(v1, v2,iniMitad, fin);
        }
        else //si no coincide, está en la primera
        {
           valor = resolver(v1, v2, ini, iniMitad);
        }
        return valor;
    }
    
}


// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    long long int numElementos;
    cin >> numElementos;

    vector<int> v1(numElementos);
    vector<int> v2(numElementos - 1);

    for (int& e : v1) cin >> e;
    for (int& e : v2) cin >> e;

    int sol = resolver(v1, v2, 0, v1.size()-1);
    cout << sol << endl;
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    ifstream in("datos.txt");
    auto cinbuf = cin.rdbuf(in.rdbuf()); //save old buf and redirect cin to casos.txt
#endif

    int numCasos;
    cin >> numCasos;
    for (int i = 0; i < numCasos; ++i)
        resuelveCaso();

    // Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    cin.rdbuf(cinbuf);
#endif

    return 0;
}
