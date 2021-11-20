// Nombre del alumno Laura Gómez Bodego
// Usuario del Juez VJ23

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;



// función que resuelve el problema
bool resolver(vector <int> const& datos, int k, int ini, int fin) 
{
    if (ini == fin - 1)
    {
        return true;
    }

    bool disp = (abs(datos[ini] - datos[fin-1]) >= k);

    
    if(disp)
    {
        disp = resolver(datos, k, ini, ((ini + fin ) / 2)) && resolver(datos, k, ((ini + fin) / 2), fin);
    }
    

    return disp;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int numCasos;
    int k;

    cin >> numCasos >> k;

    if (!cin)
        return false;
    else 
    {

        //vector con los valores
        vector <int> datos(numCasos);

        for (int i = 0; i < numCasos; i++)
        {
            cin >> datos[i];
        }
        bool sol = resolver(datos, k, 0,numCasos);

        // escribir sol
        if (sol)
            cout << "SI\n";
        else
            cout << "NO\n";

        return true;
    }
    
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