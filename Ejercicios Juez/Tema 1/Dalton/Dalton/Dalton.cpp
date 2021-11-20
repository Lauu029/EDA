// Nombre del alumno Laura Gómez Bodego
// Usuario del Juez VJ23


#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;


// función que resuelve el problema
bool resolver(int numCasos) {

    bool dalton = true;
    int i = 0;
    int* v = new int[numCasos];
    

    for (int j = 0; j < numCasos; ++j) {
        cin >> v[j];

    }
        

    if (numCasos >= 2) {

        //Orden descendente
        if (v[0] > v[1]) {
            while (i < (numCasos - 1) && dalton) {
                if (v[i] <= v[i + 1]) {
                    dalton = false;
                }
                ++i;
            }
        }
        //Orden ascendente
        else if (v[0] < v[1]) {
            while (i < (numCasos - 1) && dalton) {
                if (v[i] >= v[i + 1]) {
                    dalton = false;
                }
                ++i;
            }
        }
        else {
            dalton = false;
        }
            
    }
    else {
        dalton = false;
    }
    
    delete v;

    return dalton;
    
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    int numCasos;
    cin >> numCasos;

    if (numCasos == 0)
        return false;

    bool dalton = resolver(numCasos);

    if (dalton) {
        cout << "DALTON" << endl;
    }
    else
        cout << "DESCONOCIDOS" << endl;

    return true;


}

int main() {
    
    // Para la entrada por fichero.
    // Comentar para acepta el reto
    #ifndef DOMJUDGE
    ifstream in("datos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
    #endif 

    while (resuelveCaso());

    //// Para restablecer entrada. Comentar para acepta el reto
     #ifndef DOMJUDGE // para dejar todo como estaba al principio
     cin.rdbuf(cinbuf);
    system("PAUSE");
     #endif
    return 0;
}
