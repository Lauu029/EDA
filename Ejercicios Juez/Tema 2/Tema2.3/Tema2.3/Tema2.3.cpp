// Nombre del alumno Laura Gómez Bodego
// Usuario del Juez VJ23


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;

// función que resuelve el problema
bool resolver(vector <int> const& datos, int ini, int fin)
{
    if (ini == fin)
        return true;
    else if (ini + 1 != fin)
    {
        int medio = ini + (fin - ini) / 2;

        return datos[ini] <= datos[medio + 1] && datos[fin] >= datos[medio] && resolver(datos, ini, (ini + fin) / 2)
            && resolver(datos, ((ini + fin) / 2) + 1, fin);
    }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int valor;
    int i=0;
    vector<int> datos;
    cin >> valor;
    if (valor==0)
        return false;
    
    while(valor!=0)
    {
        datos.push_back(valor);
        cin >> valor;
    }
        
   bool sol = resolver(datos, 0, datos.size()-1);

    // escribir sol
   if (sol)
       cout << "SI\n";
   else
       cout << "NO\n";

    return true;

}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    ifstream in("datos.txt");
    auto cinbuf = cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 


    while (resuelveCaso())
        ;


    // Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    cin.rdbuf(cinbuf);
    system("PAUSE");
#endif

    return 0;
}
