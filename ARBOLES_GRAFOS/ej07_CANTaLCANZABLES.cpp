#include <iostream>
#include <vector>

class RedDeSensores {
public:
    /*
    Implementaciones hechas por mi
    "agregarConexion"
    "imprimirConexion"
    "imprimirAlcanzables"
    "dfs"
    */
    RedDeSensores(int cantidadModulos) {
        cantidad=cantidadModulos;
        adyacencias.resize(cantidadModulos);
    }

    void agregarConexion(int a, int b) {
        adyacencias[a].push_back(b);
        adyacencias[b].push_back(a);
    }

    void imprimirConexion(int a, int b) {
        int cant=0;
        for(int x:adyacencias[a]){
            if(x==b) cant++;
        }
        std::cout << "Conexion directa (" << a<<" - "<<b<<"): " <<cant<<std::endl;
        // Conexion directa (<a> - <b>): <cantidad>
    }

    void imprimirAlcanzables(int desde) {
        std::vector<bool> visitados(cantidad,false);
        dfs(visitados, desde);
        int cant=0;
        for (bool x: visitados){
            if(x) cant++;
        }
        std::cout<<"Modulos alcanzables desde "<<desde<<": "<<cant<<std::endl;
        // Implementar
        // Salida esperada Modulos alcanzables desde <desde>: <cantidad>
    }

private:
    int cantidad;
    std::vector<std::vector<int>> adyacencias;
    
    void dfs(std::vector<bool>& visitados, int desde){
        visitados[desde] = true;
        for (int x:adyacencias[desde]){
            if(visitados[x]==true) continue;
            dfs(visitados, x);
        }
    }
    
};