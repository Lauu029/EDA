//Nombre del alumno Laura Gómez Bodego
//Usuario del juez VJ23

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;



// función que resuelve el problema
/*Para hallar el mínimo la función buscará el máximo, como los vectores son rotaciones de vectores
odenados de forma decreciente, el mínimo será el anterior al máximo, salvo que el máximo sea el
primero, entonces el mínimo será el último*/
int impar(const vector<int>& sec, int ini, int fin)
{
    //Caso base, solo hay un elemento en el vector
    if (ini == fin)
        return sec[ini];
    //Comprueba si el impar es el primer elemento
    else if (sec[ini] % 2 != 0)
        return sec[ini];
    //solo dos elementos en el vector
    else if (ini + 1 == fin) 
        return sec[fin];
    else
    {
        int mitad = ((ini + fin) / 2) ;

        if (sec[mitad] % 2 != 0)
            return sec[mitad];
        else if (((sec[ini] / 2 + mitad) * 2) == sec[mitad]) {
            return impar(sec, mitad + 1, fin);
        }
        else {
            return impar(sec, ini, mitad + 1);
        }
    }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int n;
    cin >> n;
    if (n==0) return false;
    vector<int> sec(n);
    for (int& e : sec) cin >> e;
    cout << impar(sec, 0, n - 1) << endl;
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