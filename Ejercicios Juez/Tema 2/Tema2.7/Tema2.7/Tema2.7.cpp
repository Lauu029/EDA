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
        int menorD, menorI,menorT;

        //calculo la mitad del vector
        int mitad = (ini + fin) / 2;
        menorD = minimo(sec, ini, mitad);
        menorI = minimo(sec, mitad + 1, fin);

        if (menorD < menorI)
            menorT = menorD;
        else
            menorT = menorI;
        return menorT;
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
    cout << minimo(sec, 0, n - 1) << endl;
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