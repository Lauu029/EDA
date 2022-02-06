// Plantilla para el ejercicio de Venta de libros

#include <iostream>
#include <stdexcept>
#include <string>
#include <fstream>
#include <map>
#include <unordered_map>
#include <utility>
#include <list>
#include <algorithm>

using namespace std;


using libro = string; 
using datos = map<libro, pair<int, int>>;
//primero ventas segundo cuando
using ventasLibros = map<libro, pair<int, int>>;
//primero: ventas / id, segundo nombre
using ventasLibrosDatos = map<pair<int, int>, libro, greater<pair<int, int>>>;

class VentaLibros
{
private:

    //primero unidades disponibles, segundo ventas
    datos listado;
  
     ventasLibros topVentas;
     ventasLibrosDatos topVentasDatos;

    int venta = 0, topMenor = 0;
    //map.rbegin()->first
public:

    void nuevoLibro(libro x, int n)
    {
        auto it = listado.emplace(x, make_pair(n, 0));

        if (!it.second) it.first->second.first += n;
    }
    void comprar(libro x)
    {
        auto it = listado.find(x);

        if (it != listado.end())
        {
            if (it->second.first > 0)
            {
                venta++;

                it->second.first--;
                it->second.second++;

                //lo busca en el top ventas
                auto it2 = topVentas.find(x);
               //si no existe
                if (it2 == topVentas.end())
                {                    
                    //si el top ventas esta vacio o tiene las suficientes ventas
                    if (topVentas.size() < 10 || it->second.first >= topMenor)
                    {
                        ////buscamos el menor de todos partiendo la n a las ventas del libro a añadir al top
                        //int n = it->second.first;
                        //   
                        ////buscamos dentro de todo el top cual es el libro con menores ventas
                        //for (auto i = topVentas.begin(); i != topVentas.end(); i++)
                        //{
                        //    //si el numero de ventas es menor al actual se cambia
                        //    if (i->second.first < n)
                        //    {
                        //        //colocamso en n las menroes venta sy guardamos el iterador del libro con  menores ventas
                        //        n = i->second.first;
                        //        it2 = i;
                        //    }
                        //    //si es igual, pero seguimos sin haber encontrado uno menor, o su momento de venta es anteiro, se cambia
                        //    else if (i->second.first == n)
                        //    {
                        //        if (it2 == topVentas.end() || it2->second.second < i->second.second) it2 = i;
                        //    }
                        //}
                        ////si es menor que 10 el tamaño del top ventas y no existe lo insertamos
                        //if (topVentas.size() < 10)
                        //{
                        //    topVentas.emplace(it->first, make_pair(it->second.second, venta));
                        //    //actualizamos el valor menor
                        //    topMenor = n;
                        //}
                        ////si se encontro uno menor que el nuevo
                        //else if (it2 != topVentas.end())
                        //{
                        //    //eliminamos del top el más bajo y añadimso el nuevo
                        //    topVentas.erase(it2);
                        //    topVentas.emplace(it->first, make_pair(it->second.second, venta));
                        //    //actualizamos el valor menor
                        //    topMenor = n;
                        //}
                        topMenor = it->second.second++;
                        
                        if (topVentas.size() >= 10)
                        {
                            //nos situamos en el que esta abajo del top
                            auto it3 = topVentasDatos.end(); --it3;
                            //lo eliminamos del to ventas de libros
                            topVentas.erase(it3->second);
                            //lo eliminamos de los datos de las ventas de libros
                            topVentasDatos.erase(it3);
                        }
                        //añadimos el nuevo
                        topVentas.emplace(x, make_pair(it->second.second, venta));
                        topVentasDatos.emplace(make_pair(it->second.second, venta), x);
                    }
                }
                //si existe se actualiza el indice de ultima compra 
                else
                {
                    //eliminamos de los datos de ventas los anteriores resultados
                    topVentasDatos.erase(it2->second);
                    //aumentamos los valores
                    it2->second.first++;
                    it2->second.second = venta;
                   //guardamos los nuevos resultados
                    topVentasDatos.emplace(it->second, it->first);
                }
            }
            else
                throw out_of_range("No hay ejemplares");
        }
        else
            throw invalid_argument("Libro no existente");
    }

    bool estaLibro(libro x)
    {
        return listado.find(x) != listado.end();
    }

    void elimLibro(libro x)
    {
        listado.erase(x);
        topVentas.erase(x);
    }

    int numEjemplares(libro x)
    {
        auto it = listado.find(x);
        if (it != listado.end())
            return it->second.first;
        else throw invalid_argument("Libro no existente");
    }
    
   

    list<libro> top10()
    {
        list<libro> l;
        for (ventasLibrosDatos::iterator it = topVentasDatos.begin(); it != topVentasDatos.end(); ++it)
        {
            l.push_back(it->second);
        }

        return l;
    }



};





// Muestra el contenido de una lista
template <class T>
void mostrar(list<T> const& l) {
    for (auto const& e : l) {
        cout << "   " << e << '\n';
    }
}

bool resuelveCaso() {
    int numOp;

    cin >> numOp;
    if (!cin) return false;

    VentaLibros amazon;

    string operacion, titulo;

    for (int i = 0; i < numOp; ++i) {
        cin >> operacion;
        cin.ignore(1); // saltar blanco
        if (operacion == "nuevoLibro") {
            int unidades;
            cin >> unidades;
            cin.ignore(1);
            getline(cin, titulo);
            amazon.nuevoLibro(titulo, unidades);
        }
        else if (operacion == "comprar") {
            getline(cin, titulo);
            try {
                amazon.comprar(titulo);
            }
            catch (out_of_range const& e) {
                cout << e.what() << '\n';
            }
            catch (invalid_argument const& e) {
                cout << e.what() << '\n';
            }
        }
        else if (operacion == "estaLibro") {
            getline(cin, titulo);
            if (amazon.estaLibro(titulo)) {
                cout << "El libro " << titulo << " esta en el sistema\n";
            }
            else {
                cout << "No existe el libro " << titulo << " en el sistema\n";
            }
        }
        else if (operacion == "elimLibro") {
            getline(cin, titulo);
            amazon.elimLibro(titulo);
        }
        else if (operacion == "numEjemplares") {
            getline(cin, titulo);
            if (amazon.estaLibro(titulo)) {
                cout << "Existen " << amazon.numEjemplares(titulo) << " ejemplares del libro " << titulo << '\n';
            }
            else {
                cout << "No existe el libro " << titulo << " en el sistema\n";
            }
        }
        else if (operacion == "top10") {
            cout << "TOP10\n";
            mostrar(amazon.top10());
        }
    }
    // fin del caso
    cout << "---\n";
    return true;

}

int main() {

    while (resuelveCaso());

    return 0;
}
