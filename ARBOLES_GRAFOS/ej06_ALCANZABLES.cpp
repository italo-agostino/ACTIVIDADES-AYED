#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <set>
using namespace std;

class RedDeSensores {
private:
    map<string, vector<string>> grafo;

public:
    /*
    Implementaciones hechas por mi
    "agregarConexion", "estanConectados", "alcanzablesDesde", "dfs"
    */
    // Agrega una conexión bidireccional entre dos módulos
    void agregarConexion(const string& a, const string& b) {
        if(a==b) return;
        for(string x:grafo[a]){
            if(x==b) return;
        }
        grafo[a].push_back(b);
        grafo[b].push_back(a);
    }

    // Devuelve true si existe conexión directa entre a y b
    bool estanConectados(const string& a, const string& b) {
        if(a==b) return true;
        for(string x:grafo[a]){
            if(x==b) return true;
        }
        return false;
    }

    // Devuelve cuántos módulos son alcanzables desde el módulo de inicio (incluido), usando DFS
    int alcanzablesDesde(const string& inicio) {
        set<string> visitados;
        dfs(inicio, visitados);
        return visitados.size();
    }

private:
    void dfs(const string& actual, set<string>& visitados) {
        visitados.insert(actual);
        
        for(string x:grafo[actual]){
            if(visitados.count(x)==1) continue;
            dfs(x, visitados);
        }
    }
};