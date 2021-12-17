#include <iostream>
#include <stdexcept>
#include <fstream>
#include <algorithm>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;
using Partido = unordered_map<string, int>;

struct infoEstados {
    int numComp;
    int numVotos;
    Partido partidos;
    string partidoGanador;
};
using Estado = unordered_map <string, infoEstados>;

class ConteoVotos {

private:
    Estado estados;
   // Partido partidos;
public:

    void nuevo_estado(const string& nombre, int num_compromisarios) 
    {
        if (estados.count(nombre) == 1) {
            throw domain_error("Estado ya existente");
        }
        else {
            estados[nombre].numComp = num_compromisarios;
        }
    }

    void sumar_votos(const string& partido, const string& estado, int num_votos) 
    {
        if (estados.count(estado) == 0) {
            throw domain_error("Estado no encontrado");
        }
        else {
            estados[estado].partidos[partido] += num_votos;
            if (estados[estado].partidoGanador == "") {
                estados[estado].partidoGanador = partido;
            }
            else if (estados[estado].partidos[estados[estado].partidoGanador] < estados[estado].partidos[partido]) {
                estados[estado].partidoGanador = partido;
            }
        }
    }

    string ganador_en(const string& estado) 
    {
        if (estados.count(estado) == 0)
            throw domain_error("Estado no encontrado");
        return estados[estado].partidoGanador;
    }

    vector<pair<string, int>> resultados()
    {
        vector<pair<string, int>> partComp;

        for (auto& g : estados) 
        {
            bool aux=false;
            for (int i = 0; i < partComp.size(); i++) {
                if (g.second.partidoGanador == partComp[i].first) {
                    partComp[i].second += g.second.numComp;
                    aux = true;
                    break;
                }
            }
               if(!aux)
                   partComp.push_back(pair<string, int>(g.second.partidoGanador, g.second.numComp));
        }
        sort(partComp.begin(),partComp.end());
        return partComp;
    }

};

bool resuelveCaso() {
    string comando;
    cin >> comando;
    if (!cin) return false;

    ConteoVotos elecciones;

    while (comando != "FIN") {
        try {
            if (comando == "nuevo_estado") {
                string estado;
                int num_compromisarios;
                cin >> estado >> num_compromisarios;
                elecciones.nuevo_estado(estado, num_compromisarios);
            } else if (comando == "sumar_votos") {
                string estado;
                string partido;
                int num_votos;
                cin >> estado >> partido >> num_votos;
                elecciones.sumar_votos(partido, estado, num_votos);
            } else if (comando == "ganador_en") {
                string estado;
                cin >> estado;
                string ganador  = elecciones.ganador_en(estado);
                cout << "Ganador en " << estado << ": " << ganador << "\n";
            } else if (comando == "resultados") {
                for (const auto &par : elecciones.resultados()) {
                    cout << par.first << " " << par.second << "\n";
                }
            }
        } catch (std::exception &e) {
            cout << e.what() << "\n";
        }
        cin >> comando;
    }

    cout << "---\n";
    return true;
}

int main() {
#ifndef DOMJUDGE
    ifstream in("datos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); 
#endif

    while(resuelveCaso()) { }

#ifndef DOMJUDGE
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif
    return 0;
}
