// Nombre del alumno Laura Gómez Bodego
// Usuario del Juez VJ23

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;



// función que resuelve el problema
void palabrasPos(vector<char>& solucion, int k, int n, int m, vector<bool>& usadas)
{
    //va recorriendo todas las letras que se piden y las almacena
    for (char c = 'a'; c < 'a' + m; c++)
    {
        //almacena la letra en el vector solucion
        solucion[k] = c;
        //Comprobamos si la letra ha sido usada ya
        if (!usadas[c-'a']) 
        {
            //si no ha llegado al total de las letras hace backtracking
            if (k == n - 1)
            {
                for (int i = 0; i <= k; i++)
                    cout << solucion[i];
                cout << endl;
            }

            else 
            {
                //Marcamos y desmarcamos la letra usada
                usadas[c-'a'] = true;
                palabrasPos(solucion, k + 1, n, m,usadas);
                usadas[c-'a'] = false;
            }

        }
    }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int numLetras, tamPalabra;
    cin >> numLetras >> tamPalabra;

    if (!cin)
        return false;

    vector<char> solucion(tamPalabra);
    vector<bool>usadas(numLetras, false);

    palabrasPos(solucion, 0, tamPalabra, numLetras, usadas);

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