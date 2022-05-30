// Nombre del alumno Laura Gómez Bodego
// Usuario del Juez VJ23

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;
// función que resuelve el problema
bool resolver(const vector<int>& valores, const int & k, int ini, int fin) {
    if (ini == fin) {
        return true;
    }
  
    if (abs(valores[ini] - valores[fin]) >= k) {
        return resolver(valores, k, ini, ((ini + fin) / 2)) && resolver(valores, k, ((ini + fin) / 2) + 1, fin);
    }
    else return false;
    
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int n, k;
    cin >> n >> k;
    if (!cin)
        return false;
    vector<int>valores;
    int val;
    for (int i = 0; i < n; i++)
    {
        cin >> val;
        valores.push_back(val);
    }
    
    bool sol = resolver(valores, k,0,n-1);

    // escribir sol
    if (sol) cout << "SI\n";
    else cout << "NO\n";
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