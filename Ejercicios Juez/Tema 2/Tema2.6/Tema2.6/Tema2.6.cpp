//Nombre del alumno Laura Gómez Bodego
//Usuario del juez VJ23

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;



// función que resuelve el problema
int minimo(const vector<int>& sec, int ini, int fin) 
{
    //Caso base 
    if (ini == fin)
    {
        return sec[ini];
    }
    // solo hay dos números en el vector
    else if (ini + 1 == fin)
    {
        if (sec[ini] < sec[fin])
            return sec[ini];
        else
            return  sec[fin];
    }
    else
    {
        int menor;
        //calculo la mitad del vector
        int mitad = (ini + fin) / 2;
        //Comparo el elemento del medio del vector con el anterior
        if (sec[mitad] < sec[mitad - 1])
        {
            //si es más pequeño, el menor tendrá que estar hacia la derecha
            menor = minimo(sec, mitad, fin);
        }
        else 
        {
            menor = minimo(sec, ini, mitad);
        }
        return menor;
    }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int n;
    cin >> n;
    if (!cin) return false;
    vector<int> sec(n);
    for (int& e : sec) cin >> e;
    cout << minimo(sec, 0, n-1) << endl;
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
    //system("PAUSE");
#endif

    return 0;
}