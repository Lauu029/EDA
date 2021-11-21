
#include <iostream>
#include <iomanip>
#include <fstream>
#include "bintree_eda.h"
using namespace std;




// Resuelve un caso de prueba, leyendo de la entrada la
void arbolValido(bintree<int> tree, bool& esValido, int prof, int& proFinal) {
    if (!tree.empty()) {
        //almacena los valores de los hijos y el padre
        int pad = tree.root();
        int hi=0, dr=0;
        //si no existen los hijos lo pone a 0
        if (!tree.left().empty()) hi = tree.left().root();
        if (!tree.right().empty()) dr = tree.right().root();
        //Comprueba primero si tiene hijos
       
        if (hi != 0) {
            if (pad >= hi + 18)
            {
                if (dr != 0) {
                    //dos hijos con 2 años de diferencia
                    if (hi >= dr + 2) esValido = true;
                    //dos hijos con menos de 2 años de diferencia
                    else esValido = false;
                }
                //Un hijo con 18 años de diferencia
                else esValido = true;
            }
            //Hijos con menos de 18 años de diferencia
            else esValido = false;
        }
        //Sin hijo izquierdo y con hijo derecho
        else if (dr != 0) esValido = false;
        else esValido = true;

        //Si es válido sigue la búsqueda
        if (esValido) {
            arbolValido(tree.left(), esValido, prof+1, proFinal);
            arbolValido(tree.right(), esValido, prof +1, proFinal);
            if(proFinal<prof) proFinal = prof;
        }
    }


}
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    
    bintree<int> tree;
    tree = leerArbol(-1);
    bool esValido = true;
    int prof = 1;
    int proFinal = 0;
    arbolValido(tree, esValido, prof, proFinal);

    if (esValido)
        cout << "SI" << " " << proFinal << endl;
    else cout << "NO\n";
    
}



int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("datos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif

    int numCasos;
    std::cin >> numCasos;
    for (int i = 0; i < numCasos; ++i)
        resuelveCaso();

    // Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    //system("PAUSE");
#endif

    return 0;
}
