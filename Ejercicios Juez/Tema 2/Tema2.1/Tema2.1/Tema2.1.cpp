// Nombre del alumno Laura Gómez Bodego
// Usuario del Juez VJ23


#include <iostream>
#include <iomanip>
#include <fstream>
#include <cmath>

using namespace std;

// función que resuelve el problema
long long complementarios(long long numero, long long compAux) 
{
    if (numero < 10)  
    {
        return compAux * 10 +( 9 - numero);
    }
    else 
    {
        long long complementario;
   
        complementario = 9 - (numero % 10);

        compAux = compAux * 10 + complementario;

        return complementarios(numero/10, compAux);
    }

    return compAux;
}

long long inversoComplementarios(long long numero, long long numAnt)
{
    
    if (numero < 10) 
    {
        return numAnt * 10 + numero;
    }

    long long inverso = (numAnt * 10) + (numero % 10);

    return inversoComplementarios(numero/10, inverso);
}


bool resuelveCaso() 
{
    int nCasos;
    long long caso;
    long long complementarioCaso;
    
    cin >> nCasos;
    
    for (int i = 0; i < nCasos; i++) 
    {
        cin >> caso;
        
        complementarioCaso = complementarios(caso,0);

        cout << caso<< " " << inversoComplementarios(complementarioCaso,0) << " " << complementarioCaso  << endl;
    }
    return false;

}

int main() 
{
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