// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;

bool compsuper(int h) {
    return h<=3;
}
bool primercaso(int precio,int menoprecio,bool hey) {
    if (hey == false)return true;
    else return precio < menoprecio;
}
// función que resuelve el problema
void resolver(int& precio,const vector<vector<int>>&m,int k,int nsuper,int product,vector<int>&super,int &minprecio,bool &hey) {
    for (int i = 0; i < nsuper; i++) {
        int h = m[i][k];
        super[i]++;
        if (compsuper(super[i])) {
             precio = precio + h;
             if (primercaso( precio, minprecio, hey)) {
                 if (k == product - 1) {
                     if (!hey) {
                         minprecio = precio;
                         hey = true;
                      }
                     if (precio < minprecio)minprecio = precio;
                 }
                 else resolver(precio, m, k + 1, nsuper, product, super, minprecio,hey);
             }
            precio = precio - h;
        }
        super[i]--;
    }

}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    int nsuper, products;
    cin >> nsuper >> products;
    vector<vector<int>>m(nsuper,vector<int>(products));
    for (int i = 0; i < nsuper; i++) {
        for (int j = 0; j < products; j++) {
            cin >> m[i][j];
        }
    }
    int precio=0,minprecio=0;
    bool hey = false;
    vector<int>supers(nsuper);
    resolver(precio, m, 0, nsuper, products, supers, minprecio,hey);
    cout << minprecio << endl;



    // escribir sol


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
    system("PAUSE");
#endif

    return 0;
}