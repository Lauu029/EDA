// Nombre del alumno Laura Gomez Bodego
// Usuario del juez VJ23

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;

//Método que devuelve si un artista puede actuar después de otro
bool actua(vector<vector<bool>>consentimientos, int cant1, int cant2,vector<bool>yaExiste)
{
    //Comprueba si la posición de cant2 está a 1 en la fila correspondiente a cant1, si es así , devuelve true
    if (consentimientos[cant1][cant2] && !yaExiste[cant1])
        return true;
    else return false;
}


// función que resuelve el problema
//La tupla solución es el vector actuado, que almacena los artistas que han actuado en el orden que actuan
//el marcador es el vector yaExiste de booleanos que pone a true la posición de el grupo si el grupo ya ha actuado
void resolver(vector<vector<int>> beneficios, vector<vector<bool>> consentimientos, vector<int>& actuado, vector<bool>& yaExiste, int& maxBeneficios, int& ganado, int k, int n)
{
    //Recorre las filas que corresponderían a cada artista
    for (int i = 0; i < n; i++)
    {
        int h = 0;
             
        //Al primer artista no le pide el anterior
        if (k==0 || actua(consentimientos, i, actuado[k-1],yaExiste))
        {
            
            //Añade en un vector al artista que ha actuado
            actuado[k] = i;

            //guardo los beneficios de la actuación en la posición indicada
            h = beneficios[i][k];
            ganado += h;
            //Comprueba si el máximo del beneficio es mayor que el nuevo valor, si es así y ha llegado al final de los datos, actualiza el máximo
            
            if (k == n - 1) 
            {
                if (maxBeneficios == 0 || ganado > maxBeneficios) 
                {
                        maxBeneficios = ganado;
                }
            }
            else {
                
                yaExiste[i] = true;
                resolver(beneficios, consentimientos, actuado, yaExiste, maxBeneficios, ganado, k + 1, n);
                yaExiste[i] = false;
            }
        }
        ganado -= h;
    }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    int n;
    cin >> n;
    vector<vector<int>> beneficios(n, vector<int>(n));
    vector<vector<bool>> consentimientos(n, vector<bool>(n));
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            cin >> beneficios[i][j];

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j) {
            int b;
            cin >> b;
            consentimientos[i][j] = b;
        }
    int maxBeneficios = 0;
    int ganado = 0;
    vector<int>actuado(n);
    vector<bool>yaExiste(n,false);
    
    resolver(beneficios,consentimientos,actuado,yaExiste,maxBeneficios,ganado,0,n);
    // salida
    //Si ha conseguido beneficios es que ha habido acuerdo
    if (maxBeneficios!=0)
        cout << maxBeneficios << endl;
    else
        cout << "NEGOCIA CON LOS ARTISTAS\n";
    
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