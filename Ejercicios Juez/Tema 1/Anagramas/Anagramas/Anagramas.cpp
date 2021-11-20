//Laura Gómez Bodego
//Usuario VJ23

#include <iostream>
#include <fstream>
#include <vector>
using namespace std;


//La complejidad del algoritmo es lineal ya que depende solamente del número de casos (caracteres) dados
bool anagramas(const string& cad1, const string& cad2) {
    char abc[27] = { 0 };
    int numLet = 0;
    //Analiza la primera palabra para ver que letras están en el abecedario
    for (int i = 0; i < cad1.length(); ++i) {
        
        numLet = cad1[i] - 96;
        abc[numLet]++;
    }
    numLet = 0;
    //Analiza la segunda palabra
    for (int i = 0; i < cad2.length(); ++i) {

        numLet = cad2[i] - 96;
        abc[numLet] -- ;
    }
    //Recorre el array de las letras del abecedario para ver si se han quedado todas a 0
    //Si es así, es anagrama, si no, no lo es
    for (int i = 0; i < 27; ++i) {
        if (abc[i] != 0)
            return false;
    }
    return true;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    string word1, word2;
    cin >> word1 >> word2;
    cout << (anagramas(word1, word2) ? "SI" : "NO") << endl;
}

//#define DOMJUDGE
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