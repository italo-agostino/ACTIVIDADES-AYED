#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <queue>

// Clase para representar el grafo de ciudades
class GrafoCiudades {
public:
    std::map<std::string, int> ciudad_a_id; // Mapea nombres de ciudades a IDs numéricos
    std::vector<std::string> id_a_ciudad;   // Mapea IDs numéricos a nombres de ciudades
    std::vector<std::vector<int>> adj;      // Lista de adyacencia

    GrafoCiudades() {}

    /*
    Implementaciones hechas por mi
    "agregarCiudad", "agregarCarretera", "obtenerCaminoMasCorto"
    */
    void agregarCiudad(const std::string& ciudad) {
        if(ciudad_a_id.count(ciudad)!=0) return;
        int id=id_a_ciudad.size();
        ciudad_a_id[ciudad]=id;
        id_a_ciudad.push_back(ciudad);
        adj.push_back({});
    }

    // Agrega una carretera (arista) no dirigida entre dos ciudades
    void agregarCarretera(const std::string& ciudad1, const std::string& ciudad2) {
        agregarCiudad(ciudad1);
        agregarCiudad(ciudad2);
        auto it1=ciudad_a_id.find(ciudad1);
        auto it2=ciudad_a_id.find(ciudad2);
        adj[it1->second].push_back(it2->second);
        adj[it2->second].push_back(it1->second);
    }

    // Encuentra el camino más corto (en cantidad de saltos) usando BFS
    // Devuelve la cantidad de saltos. Si no hay conexión, devuelve -1.

    int obtenerCaminoMasCorto(const std::string& ciudadA, const std::string& ciudadB) {
        auto itA=ciudad_a_id.find(ciudadA);
        auto itB=ciudad_a_id.find(ciudadB);
        if(itA==ciudad_a_id.end()||itB==ciudad_a_id.end()) return -1;
        if(itA==itB) return 0;

        std::vector<int> dist(adj.size(), -1);
        std::queue<int> cola;
        cola.push(itA->second);
        dist[itA->second]=0;

        while(!cola.empty()){
            int actual=cola.front();
            cola.pop();
            for(int vecino:adj[actual]){
                if(dist[vecino]!=-1) continue;
                dist[vecino]=dist[actual]+1;
                if(vecino==itB->second) return dist[vecino];
                cola.push(vecino);
            }

        }
        return -1;
    }
};