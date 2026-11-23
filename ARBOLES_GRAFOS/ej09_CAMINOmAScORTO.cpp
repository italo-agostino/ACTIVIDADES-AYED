#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <queue>    // Para BFS

// Clase para representar el grafo de ciudades
class GrafoCiudades {
public:
    std::map<std::string, int> ciudad_a_id; // Mapea nombres de ciudades a IDs numéricos
    std::vector<std::string> id_a_ciudad;   // Mapea IDs numéricos a nombres de ciudades
    std::vector<std::vector<int>> adj;      // Lista de adyacencia

    GrafoCiudades() {}
    /*
    Implementaciones hechas por mi:
    "agregarCiudad", "agregarCarretera", "obtenerCaminoMasCorto"
    */
    // Agrega una ciudad al grafo
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
        int id1 = it1->second;
        int id2 = it2->second;
        adj[id1].push_back(id2);
        adj[id2].push_back(id1);
    }
    // Encuentra el camino más corto (en cantidad de saltos) usando BFS
    // Devuelve la cantidad de saltos. Si no hay conexión, devuelve -1.
    int obtenerCaminoMasCorto(const std::string& ciudadA, const std::string& ciudadB) {
        auto ita = ciudad_a_id.find(ciudadA);
        auto itb = ciudad_a_id.find(ciudadB);
        if(ita==ciudad_a_id.end()||itb==ciudad_a_id.end()) return -1;
        if(ita==itb) return 0;
       
        int ida = ita->second;
        int idb = itb->second;
       
        std::vector<int> dist(id_a_ciudad.size(),-1);
        std::queue<int> cola;
        dist[ida]=0;
        cola.push(ida);
       
        while(!cola.empty()){
            int actual=cola.front();
            cola.pop();
            for(int x:adj[actual]){
                if(dist[x]!=-1) continue;
                dist[x]=dist[actual]+1;
                if(x==idb) return dist[x];
                cola.push(x);
            }
        }
       return -1;
    }
};