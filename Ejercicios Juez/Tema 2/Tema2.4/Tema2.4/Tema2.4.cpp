// Nombre del alumno Laura Gómez Bodego
// Usuario del Juez VJ23

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;
//Función que devuelve un número de pares de un vector
int numPares(vector <int> const& datos, int ini, int fin)
{
    int pares=0;
    //recorre la parte que se le indica del vector y va almacenando la cantidad de números pares que encuentra
    for (int i = ini; i <= fin; i++)
    {
        if (datos[i] % 2 == 0)
            pares++;
    }
    return pares;
}
// función que resuelve el problema
bool resolver(vector <int> const& datos, int ini, int fin) 
{
    
    //caso Base, los vectores de 4 o menos elementos son todos caucasicos
    if (ini == fin)
        return true;
    else if (ini + 3 == fin) 
    {
        return true;
    }
    else 
    {
        //Calcula la mitad del vector
        int mitad = (ini + fin) / 2;
        //Calcula la diferencia de la cantidad de pares de ambas mitades
        int difPares =abs( numPares(datos, ini, mitad)- numPares(datos, mitad+1,fin));
        //si la diferencia es menor o igual a 2, llama a la función con la mitad del vector
        if (difPares <= 2)
        {
            return resolver(datos, ini, mitad) && resolver(datos, mitad + 1, fin);
        }
        else
            return false;
    }

}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int nCasos;
    cin >> nCasos;
    if (nCasos==0)
        return false;
    vector<int> datos(nCasos);

    for (int i = 0; i < nCasos; i++) 
    {
        cin >> datos[i];
    }

    bool sol = resolver(datos,0, nCasos-1);

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