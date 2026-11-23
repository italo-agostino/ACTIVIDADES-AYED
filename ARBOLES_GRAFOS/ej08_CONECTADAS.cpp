#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <queue> // Para BFS

// Clase para representar el grafo
class GrafoCiudades {
public:
    std::map<std::string, int> ciudad_a_id; // Mapea nombres de ciudades a IDs numéricos
    std::vector<std::string> id_a_ciudad;   // Mapea IDs numéricos a nombres de ciudades
    std::vector<std::vector<int>> adj;      // Lista de adyacencia
    /*
    Implementaciones hechas por mi:
    "agregarCiudad"
    "agregarCarretera"
    "estanConectadas"
    */
    GrafoCiudades() {}

    // Agrega una ciudad al grafo
    void agregarCiudad(const std::string& ciudad) {
        if(ciudad_a_id.count(ciudad)!=0) return;
        int id=id_a_ciudad.size();
        ciudad_a_id[ciudad]=id;
        id_a_ciudad.push_back(ciudad);
        adj.push_back({});
    }

    // Agrega una carretera (arista) entre dos ciudades
    void agregarCarretera(const std::string& ciudad1, const std::string& ciudad2){
        agregarCiudad(ciudad1);
        agregarCiudad(ciudad2);
        auto it1=ciudad_a_id.find(ciudad1);
        auto it2=ciudad_a_id.find(ciudad2);
        int id1=it1->second;
        int id2=it2->second;
        adj[id1].push_back(id2);
        adj[id2].push_back(id1);
    }

    // Verifica si dos ciudades están conectadas usando BFS
    bool estanConectadas(const std::string& ciudadA, const std::string& ciudadB) {
        auto itA=ciudad_a_id.find(ciudadA);
        auto itB=ciudad_a_id.find(ciudadB);
        if(itA==ciudad_a_id.end()||itB==ciudad_a_id.end()) return false;
        if(itA==itB) return true;
        
        vector<bool> visitados(id_a_ciudad.size(), false);
        queue<int> cola;
        cola.push(itA->second);
        visitados[itA->second]=true;
        
        while(!cola.empty()){
            int actual=cola.front();
            cola.pop();
            for(int x:adj[actual]){
                if(visitados[x]==true) continue;
                if(x==itB->second) return true;
                visitados[x]=true;
                cola.push(x);
            }
        }
        
        return false; // No se encontró un camino
    }
};