#include <iostream>
#include <fstream>
#include <string>
#include <string>
#include <map> 
#include <vector>
using namespace std;

using Diccionario = map<string, int>;

void leerDiccionario(Diccionario& diccionario){
    char c;
    string clave;
    int valor;
    cin.get(c);
    while (c != '\n'){
        cin.unget();
        cin >> clave >> valor;
        diccionario[clave] = valor;
        cin.get(c);
    }
}
struct cambios {
    bool insertado;
    vector<string> insertados;
    bool quitado;
    vector<string> quitados;
    bool modificado;
    vector<string> modificados;
};
cambios comparaDiccionarios(Diccionario& antiguo, Diccionario& nuevo) {
    
    cambios elCamb;
    //los inicializo todos a false para que solo se pongan a true si los encuentra
    elCamb.insertado = false;
    elCamb.modificado = false;
    elCamb.quitado = false;
    //recorro el nuevo para comprobar los modificados y añadidos
    for (auto& g: nuevo) {
        if (antiguo.count(g.first) == 1 && antiguo[g.first]!=g.second) {
            elCamb.modificado = true;
            elCamb.modificados.push_back(g.first);
        }
        else if (antiguo.count(g.first)==0) {
            elCamb.insertado = true;
            elCamb.insertados.push_back(g.first);
        }
    }
    //recorro el viejo para ver los eliminados
    for (auto& s : antiguo) {
        if (nuevo.count(s.first) == 0) {
            elCamb.quitado = true;
            elCamb.quitados.push_back(s.first);
        }
    }
    return elCamb;
    
}

void resuelveCaso(){
    Diccionario antiguo;
    Diccionario nuevo;
    leerDiccionario(antiguo);
    leerDiccionario(nuevo);
    cambios a = comparaDiccionarios(antiguo, nuevo);
    if (!a.insertado && !a.modificado && !a.quitado)
        cout << "Sin cambios\n";
    else {
        if (a.insertado) {
            cout << "+";
            for (auto i : a.insertados) {

                cout << " " << i;
            }
            cout << endl;
        }
        if (a.quitado) {
            cout << "-";
            for (auto j : a.quitados) {

                cout << " " << j;
            }
            cout << endl;
        }
        if (a.modificado) {
            cout << "*";
            for (auto k : a.modificados) {

                cout << " " << k;
            }
            cout << endl;
        }
    }
    cout << "---\n";
}


int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("datos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif

    int numCasos; char c;
    std::cin >> numCasos;
    cin.get(c);
    for (int i = 0; i < numCasos; ++i)
        resuelveCaso();

    // Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    //system("PAUSE");
#endif

    return 0;
}
