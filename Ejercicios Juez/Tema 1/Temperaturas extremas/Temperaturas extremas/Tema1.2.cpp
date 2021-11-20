// Nombre del alumno Laura Gómez Bodego
// Usuario del Juez VJ23


#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;


// función que resuelve el problema
int resolver(int datos) {

    int* valoresTemp = new int[datos];
    
    int valor;

    int extremos=0;
    //Meto los valores de la temperatura en un array
    for (int i = 0; i < datos; i++) {
        cin >> valor;
        valoresTemp[i] = valor;
    }

    //Primero analizo los datos para ver los picos
    for (int i = 1; i < (datos-1); i++) {
        if (valoresTemp[i] > valoresTemp[i - 1] && valoresTemp[i] > valoresTemp[i + 1]) {

            extremos++;
        }
    }

    // escribo los valores y reseteo la variable de los extremos
    cout << extremos<<" ";

    extremos = 0;

    //Analizo los datos para ver los valles
    for (int i = 1; i < (datos - 1); i++) {
        if (valoresTemp[i] < valoresTemp[i - 1] && valoresTemp[i] < valoresTemp[i + 1]) {

            extremos++;
        }
    }

    //Escribo los picos

    cout << extremos << endl;
    extremos = 0;

    return 0;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    int numCasos;
    cin >> numCasos;

    int numValores;
    
    for (int i = 0; i < numCasos; i++) {
        cin >> numValores;
        resolver(numValores);
    }


    return false;

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


    //// Para restablecer entrada. Comentar para acepta el reto
     #ifndef DOMJUDGE // para dejar todo como estaba al principio
     std::cin.rdbuf(cinbuf);
    system("PAUSE");
     #endif

    return 0;
}
