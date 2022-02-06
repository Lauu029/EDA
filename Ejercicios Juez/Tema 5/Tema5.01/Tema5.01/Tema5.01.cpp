// Nombre del alumno Laura Gómez Bodego
// Usuario del Juez VJ23

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
//Inclusión de la pila
#include <stack>

using namespace std;
// función que resuelve el problema
bool resolver(stack<char>& pila, const char& fin) {
    if (pila.empty()) return false;
    char ini = pila.top();
    if (ini == '('&&fin==')') pila.pop();
    else if (ini == '['&&fin==']') pila.pop();
    else if (ini == '{'&&fin=='}') pila.pop();
    else return false;
    return true;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    string caso;
    getline(cin, caso);
    if (!std::cin)
        return false;
    bool resuelto = true;
    stack<char>pila;
    //vamos a meter solo los casos que nos interesan
    for (int i = 0; i < caso.size() && resuelto; i++) {
        if (caso[i] == '[' || caso[i] == '{' || caso[i] == '(') {
            //si son los de apertura se meten en la pila
            pila.push(caso[i]);
        }
        else if (caso[i] == ']' || caso[i] == '}' || caso[i] == ')') {
            //si son los de cerrar se resuelve el caso
           resuelto= resolver(pila, caso[i]);
        }
    }
    // escribir sol
    if (resuelto&&pila.empty()) cout << "SI\n";
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