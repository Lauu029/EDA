#include <iostream>
#include <fstream>
#include <cctype>
#include <map>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;
using Lista = map<string, int>;
using OrdenSalida = unordered_map<string, int>;

void resolver(string const& primerDeporte, Lista& deportes){
    string deporte, alumno;
    deporte = primerDeporte;
    map<string, string> alumnos;
    while (deporte != "_FIN_") {
       
        cin >> alumno;
        deportes[deporte] = 0;
        //isupper(comprueba si la primera letra es mayúscula)
        while (!isupper(alumno[0]) && alumno != "_FIN_") {
            
            //pone a 0 la lista de alumnos en el deporte
            //si no estaba ya en el alumno lo añade
            if (alumnos.count(alumno) == 0) {
                alumnos[alumno] = deporte;
                deportes[deporte]++;
            }
            else {
                //El alumno ya tiene un deporte asi que lo borra de los dos
                //Comprueba que no sea el deporte actual y que no esté mas de dos veces el alumno para borrar solo una vez
                if (alumnos[alumno] != deporte && alumnos[alumno] != "borrado") {
                    deportes[alumnos[alumno]]--;
                    alumnos[alumno] = "borrado";
                }
            }
            cin >> alumno;
        }

        //El último que ha leido(si no es fin) es el siguiente deporte
        deporte = alumno;
    }
}
void ordenaLista(Lista& deportes, OrdenSalida& depOrden) {
    string deporte;
   
    //guarda el primer deporte de la lista y su valor
    string aux1 = deportes.begin()->first;
    int valDep1 = deportes[aux1];
    string aux2;
    int valDep2;
    for (auto& s : deportes) {
        //coge los dos valores que le toca
        aux2 = s.first;
        valDep2 = s.second;
         //los compara con el resto del vector
         for (auto& g : deportes) {
             if (g.second > valDep1) {
                 valDep1 = g.second;
                 aux1 = g.first;
             }
             else {
                 
             }
         }

        //de aqui sale un valor de deportes y uno del numero que tienen que ser los mas grandes
        //si no está ya, lo mete
         if (depOrden.count(aux1) == 0) {
             depOrden[aux1] = valDep1;
         }
         else {
             depOrden[aux2] = valDep2;
         }
    }
    
    
    //cojo el primer valor de la lista de deportes
}
// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    string primerDeporte;
    cin >> primerDeporte;
    if (!cin) return false;

    Lista deportes;
    OrdenSalida depOrden;
    resolver(primerDeporte, deportes);
    ordenaLista(deportes, depOrden);
    for (auto& g : depOrden) {

        cout << g.first << " " << g.second << endl;
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