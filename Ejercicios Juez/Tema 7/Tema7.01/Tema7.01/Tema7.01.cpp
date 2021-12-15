#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <list>
#include <vector>

using namespace std;

using TablaRefs = map<string,vector<int>>;

void referencias(int numLineas, TablaRefs& refs){
    string palabra;
    char c;
    for (int numLinea = 1; numLinea <= numLineas; numLinea++) {//recorre todas las lineas
        cin.get(c);
        while (c != '\n'){//va leyendo las palabras hasta que encuentre el final de linea
            cin.unget(); // Se vuelve a dejar c en cin (por si era la 1ª letra de la linea)
            cin >> palabra; //le cada palabra
            if (palabra.size() > 2) {
                //pone todas las letras en minusculas
                for (int i=0;i<palabra.size();i++)
                    palabra[i] = tolower(palabra[i]);
                //refs[palabra].size() > 0 comprueba si ya ha registrado la palabra y si no está la mete en el diccionario
                //refs[palabra][refs[palabra].size() - 1] != numLinea comprueba que la palabra no salga dos veces en la misma linea
                if (refs[palabra].size() > 0 && refs[palabra][refs[palabra].size() - 1] != numLinea)
                    refs[palabra].push_back(numLinea);
                else if (refs[palabra].size() == 0)
                    refs[palabra].push_back(numLinea);

            }
            cin.get(c);
        }
        
    }
}


// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int n;
    char c;
    cin >> n;
    cin.get(c); // Me salto el \n de detrás del N
    if (n == 0)
        return false;

    TablaRefs refs;
    referencias(n,refs);

    // escribir sol
    for (auto g : refs) {
        cout << g.first;
        for (int i = 0; i < g.second.size(); i++)
            cout << " " << g.second[i];
        cout << endl;
    }
    
    cout << "---\n";
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
#endif

    return 0;
}