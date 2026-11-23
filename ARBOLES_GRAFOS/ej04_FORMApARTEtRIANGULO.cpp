#include <iostream>
#include <vector>

using namespace std;

class Grafo {
private:
    int V;                          // Número de vértices
    vector<vector<int>> matrizAdj;  // Matriz de adyacencia (1 si hay arista, 0 si no)

public:
    Grafo(int vertices) {
        V = vertices;
        matrizAdj.assign(vertices, vector<int>(vertices, 0));
    }

    void agregarArista(int u, int v) {
        matrizAdj[u][v] = 1; // Grafo DIRIGIDO (u apunta a v)
    }

    // Función miembro a probar
    bool formaParteDeTriangulo(int u);
};

// Implementación de la solución
bool Grafo::formaParteDeTriangulo(int u) {
    if (u<0||u>=V) return false;
    for(int v=0; v<V; v++){
        if(v==u) continue;
        for(int w=0; w<V; w++){
            if(w==u||w==v) continue;
            if(matrizAdj[u][v]==1&&matrizAdj[v][w]==1&&matrizAdj[w][u]==1) return true;
        }
    }
    return false;
}