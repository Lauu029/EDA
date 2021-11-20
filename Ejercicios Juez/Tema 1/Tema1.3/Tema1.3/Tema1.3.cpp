// Nombre del alumno Laura Gómez Bodego
// Usuario del Juez VJ23


#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;


// función que resuelve el problema
bool resolver(int valores [] , int posiciones, int numValores) {

    int mayor = valores[posiciones];
    int menor=valores[posiciones + 1];

   if (posiciones >= numValores - 1)
        return true;
    
    //Saco el valor mayor de la primera parte
    for (int i = posiciones; i >= 0; i--) {
        
        if (valores[i] > mayor)
            mayor = valores[i];
    }
    
    
    //Saco el valor menor de la primera parte
    for (int i = posiciones + 1 ; i < numValores; i++) {
        
        if (valores[i] < menor)
            menor = valores[i];
    }

    //Comparo mayor y menor
    if (mayor < menor)
        return true;
    else
        return false;
    
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    
    int numValores;
    int posicion;


    cin >> numValores;
    cin >> posicion;

   
   if ((1 <= numValores) && (numValores <= 300000) && (0 <= posicion) && (posicion <= numValores - 1))
   {
        int* valores = new int[numValores];
        
        for (int i = 0; i < numValores; i++) {
            cin >> valores[i];
        }

        if (resolver(valores, posicion, numValores))
            cout << "SI" << endl;
        else
            cout << "NO" << endl;
   }
    return true;
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
    #ifndef DOMJUDGE
    std::ifstream in("datos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
    #endif 

    int nCasos;
    cin >> nCasos;

    for (int i = 0; i < nCasos; i++) {
        resuelveCaso();
    }


    //// Para restablecer entrada. Comentar para acepta el reto
    #ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
    #endif

    return 0;
}