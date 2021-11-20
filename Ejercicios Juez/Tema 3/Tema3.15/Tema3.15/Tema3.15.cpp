// Nombre del alumno Laura Gómez Bodego
// Usuario del Juez VJ23


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;


// función que resuelve el problema
void resolver(vector<vector<int>>& datos, int nSuper, int nProductos,vector<int>& supermercados, int& precioMin, int k,int& precio)
{
    for (int i = 0; i < nSuper; i++) {
        int h = datos[i][k];
        supermercados[i]++;
        if (supermercados[i]<=3)
        {
            precio = precio + h;
            if (precioMin==0||precio<precioMin) 
            {
                if (k == nProductos - 1) 
                {
                    precioMin = precio;
                }
                else resolver(datos, nSuper,nProductos,supermercados,precioMin, k + 1,precio);
            }
            precio = precio - h;
        }
        supermercados[i]--;
    }

}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {

    //Lectura de datos
    int nSuper, nProductos;
    cin >> nSuper >> nProductos;

    vector<vector<int>> precios(nSuper, vector<int>(nProductos));
    for (int i = 0; i < nSuper; ++i) {
        for (int j = 0; j < nProductos; ++j) {
            cin >> precios[i][j];
        }
    }
    int precio = 0, precioMin = 0;
    vector<int>supermercados(nSuper);
    resolver(precios, nSuper, nProductos, supermercados, precioMin, 0, precio);
    cout << precioMin << endl;

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