// Nombre del alumno Laura Gómez Bodego
// Usuario del Juez VJ23

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;

//Función que determina si el color es válido

bool esValida(vector<int>& solucion, int k) {
    //si es verde y ademas el anterior es verde no es válida
    return !((solucion[k] == 2) && (solucion[k - 1] == solucion[k]));
}


// función que resuelve el problema
void palabrasPos(vector<int>& solucion, int k, int n, int m)
{
    for (int i = 0; i < n; i++)
    {
        solucion[k] = i;
        if (esValida(solucion, k)) {

            //si no ha llegado al total de las letras hace backtracking
            if (k == m - 1)
            {
                for (int j = 0; j <= k; j++) {
                    switch (solucion[j])
                    {
                    case 0: cout << "azul ";
                        break;
                    case 1: cout << "rojo ";
                        break;
                    case 2: cout << "verde ";
                    default:
                        break;
                    }
                }
                cout << endl;
            }

            else
            {
                palabrasPos(solucion, k + 1, n, m);
            }
        }
    }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int alturaTorre;
    cin >> alturaTorre;

    if (alturaTorre == 0)
        return false;

    int numColores = 3;
    vector<int> solucion(alturaTorre);
    //el primer color es rojo
    solucion[0] = 1;
    if (alturaTorre > 1) {

        palabrasPos(solucion, 1, numColores, alturaTorre);
    }
    else
        cout << "rojo\n";

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